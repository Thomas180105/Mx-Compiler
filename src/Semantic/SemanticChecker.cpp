#include "ASTNode.h"
#include "SemanticChecker.h"

#define INFO
void SemanticChecker::visitProgramNode(ASTProgramNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 1"<<std::endl;
#endif
    for (auto u : node->children) u->accept(this);
    //回溯的时候进行检查
    auto checkFunc = globalScope->tellFuncType("main");
    if (checkFunc.returnType != Type("int", 0, false)) throw semantic_error("main() doesn't return int");
    if (!checkFunc.paras.empty()) throw semantic_error("unexpected main() paras");
}

void SemanticChecker::visitClassNode(ASTClassNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 2"<<std::endl;
#endif
    auto returnScope = scope;
    scope = node->scope;
    for (auto cons : node->constructors) cons->accept(this);
    for (auto func : node->functions) func->accept(this);
    scope = returnScope;
}

void SemanticChecker::visitFunctionNode(ASTFunctionNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 3"<<std::endl;
#endif
    auto returnScope = scope;
    scope = new Scope(scope);
    try{
        curFunc = node;
        for (auto p : node->paras)
        {
            p.first->accept(this);
            scope->addVar(p.second, Type(p.first->name, p.first->dim, false));
        }
        for (auto stmt : node->block->stmts) stmt->accept(this);
        std::cerr<<"%%%%%%"<<node->returnType<<std::endl;
//注意构造函数的情况，比如class-13中的t = new B();
//        node->returnType->accept(this);
//        node->type = Type(node->returnType->name, node->returnType->dim, true);
        if (node->returnType)
        {
            node->returnType->accept(this);
            node->type = Type(node->returnType->name, node->returnType->dim, true);
        }
        else node->type = Type("void", 0, true);
    }
    catch(semantic_error &err){
        delete scope;
        scope = returnScope;
        curFunc = nullptr;
        throw err;
    }
    //赋值node中的unique命名
    node->uniqueNameParas = node->paras;
    for (auto i : node->uniqueNameParas) i.second = scope->tellVarUnique(i.second);
    delete scope;
    scope = returnScope;
    curFunc = nullptr;
}

void SemanticChecker::visitTypeNode(ASTTypeNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 4"<<std::endl;
#endif
    if (!globalScope->isClassExisted(node->name)) throw semantic_error(" undefined type " + node->name + " occur");
}

void SemanticChecker::visitSuiteNode(ASTSuiteNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 5"<<std::endl;
#endif
    auto returnScope = scope;
    scope = new Scope(scope);
    try{
        for (auto stmt : node->stmts) stmt->accept(this);
    }
    catch(semantic_error &err){
        delete scope;
        scope = returnScope;
        curFunc = nullptr;
        throw err;
    }
    delete scope;
    scope = returnScope;
}

void SemanticChecker::visitExprStmtNode(ASTExprStmtNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 6"<<std::endl;
#endif
    //in case that exprStmt is empty
    if (node->expr) node->expr->accept(this);
}
//凡是继承自ASTExprNode都需要记录下type的信息
void SemanticChecker::visitFuncExprNode(ASTFuncExprNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 7"<<std::endl;
#endif
    node->func->accept(this);
    FuncType funcType;
    auto function = dynamic_cast<ASTIdExprNode*>(node->func);
    if (function) funcType = scope->tellFuncType(function->name);
    else//memberFunction
    {
        auto classMember = dynamic_cast<ASTMemberExprNode*>(node->func);
        if (classMember == nullptr) throw semantic_error("functionCall semantic_error");
        if (!classMember->object->type.dim)
        {
            string className = classMember->object->type.name;
            auto classScope = globalScope->getClassType(className)->scope;
            funcType = classScope->tellFuncType(classMember->member);
        }
        else //int type[]::size()
        {
            if (classMember->member != "size") throw semantic_error("non-buildIn functionCall to array is not allowed");
            funcType = globalScope->tellFuncType("__size__");//to fix the bug of builtIn_3
        }
    }

    if (funcType.paras.size() != node->args.size()) throw semantic_error("functionCall args count error");
    for (int i = 0, s = funcType.paras.size(); i < s; ++i)
    {
        node->args[i]->accept(this);
        if (!funcType.paras[i].assignable(node->args[i]->type)) throw semantic_error("functionCall args not assignable to para");
    }
    node->type = funcType.returnType;
    node->type.isConst = true;
}

void SemanticChecker::visitArrayExprNode(ASTArrayExprNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 8"<<std::endl;
#endif
    node->array->accept(this);
    if (!node->array->type.dim) throw semantic_error("arrayType doesn't have []");
    node->index->accept(this);
//    if(node->index->type.name != "int")  throw semantic_error("array index isn't 'int");
    if(!node->index->type.is_int())  throw semantic_error("array index isn't 'int");
    node->type = node->array->type;
    --node->type.dim;
}

void SemanticChecker::visitMemberExprNode(ASTMemberExprNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 9"<<std::endl;
#endif
    node->object->accept(this);
    //builtIn-functions need SPJ
    auto objType = node->object->type;
    auto memberName = node->member;
    if(objType.is_builtIn())
    {
        bool flag = (memberName == "length" || memberName == "substring" || memberName == "parseInt" || memberName == "ord");
        if (objType.is_string() && flag)
        {
            node->type = globalScope->getClassType("string")->scope->tellVarType(memberName);
            return;
        }
        else throw semantic_error("unexpected member of builtInClass");
    }
    if (objType.dim)
    {
        if (memberName == "size")
        {
//            node->type = globalScope->tellFuncType("string").returnType;//slower than directly assign
            node->type = Type("int", 0, true);
            return;
        }
        else throw semantic_error("unexpected member of arrayClass");
    }
    //normal case. notice the node->type might be nullptr
    auto classType = globalScope->getClassType(objType.name);
    if (classType->scope->isVarExisted(memberName)) node->type = classType->scope->tellVarType(memberName);
}

void SemanticChecker::visitSingleExprNode(ASTSingleExprNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 10"<<std::endl;
#endif
    node->expr->accept(this);
    node->type = node->expr->type;

    if (node->op == "++" || node->op == "--")
    {
        if (!node->type.is_int()) throw semantic_error("++/-- meet with non-int var");
        if (node->type.isConst) throw semantic_error("++/-- meet with const var");
        if (node->right) node->type.isConst = true; //注意顺序！不可以出现在上一个if判断之前
    }
    else if (node->op == "-")
    {
        node->type.isConst = true;
        if (!node->type.is_int()) throw semantic_error("- meet with non-int var");
    }
    else if (node->op == "~")
    {
        node->type.isConst = true;
        if (!node->type.is_int()) throw semantic_error("~ meet with non-int var");
    }
    else if (node->op == "!")
    {
        node->type.isConst = true;
        if (!node->type.is_bool()) throw semantic_error("! meet with non-bool var");
    }
    else throw semantic_error("unexpected unary operator, the op is " + node->op);
}

void SemanticChecker::visitNewExprNode(ASTNewExprNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 11"<<std::endl;
#endif
    node->newType->accept(this);
    if (!globalScope->isClassExisted(node->newType->name)) throw semantic_error("undefined type in newExpr, the type is " + node->newType->name);
    if (node->type.is_void()) throw semantic_error("newType could not be void");
    node->type = Type(node->newType->name, node->newType->dim, false);
}

void SemanticChecker::visitBinaryExprNode(ASTBinaryExprNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 12"<<std::endl;
#endif
    node->lhs->accept(this);
    node->rhs->accept(this);
    auto lType = node->lhs->type;
    auto rType = node->rhs->type;

    if (lType.is_int() || lType.is_bool() || rType.is_int() || rType.is_bool())
    {
        if (lType != rType) throw semantic_error("binaryExpr(</>) opponents type not match");
    }
    if (node->op == ">" || node->op == ">=" || node->op == "<" || node->op == "<=")
    {
        if (!lType.is_builtIn() || !rType.is_builtIn()) throw semantic_error("Comparison operator apply to non-builtInType");
        if (lType.is_bool() || lType.is_void() || rType.is_bool() || rType.is_void()) throw semantic_error("Comparison operator apply to bool/void");
        if (lType != rType) throw semantic_error("binaryExpr(comp) opponents type not match");
        node->type = Type("bool", 0, true);
    }
    else if (node->op == "==" || node->op == "!=")
    {
        if ((lType != rType) && lType.is_builtIn() && rType.is_builtIn())
            throw semantic_error("binaryExpr(!=/==) opponents type not match(1)");
        if ((lType != rType) && (!lType.is_builtIn() || !rType.is_builtIn()) && !lType.is_null() && !rType.is_null())
            throw semantic_error("binaryExpr(!=/==) opponents type not match(2)");
        node->type = Type("bool", 0, true);
    }
    else
    {
        if (!lType.is_builtIn() || !rType.is_builtIn()) throw semantic_error("binaryExpr(others) opponents type not match");
        if (lType.is_bool() || rType.is_bool())
        {
            if (lType != rType) throw semantic_error("bool shouldn't applied to non-bool");
            if (node->op != "&&" && node->op != "||")
            {
//                std::cerr<<"^^^"<<node->op<<std::endl;
                throw semantic_error("bool shouldn't applied to non-(&& or ||)");
            }
        }
        if (lType.is_string() || rType.is_string())
        {
            if (lType != rType) throw semantic_error("string shouldn't applied to non-string");
            if (node->op != "+") throw semantic_error("string shouldn't applied to non(+)");
        }
        node->type = lType;
        node->type.isConst = true;
    }
}

void SemanticChecker::visitTernaryExprNode(ASTTernaryExprNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 13"<<std::endl;
#endif
    node->cond->accept(this);
    if (!node->cond->type.is_bool()) throw semantic_error("condition in ternaryExpr is non-bool");
    node->True->accept(this);
    node->False->accept(this);

    auto tType = node->True->type;
    auto fType = node->False->type;
    Type commonType;
    if (tType == fType || tType.convertible(fType)) commonType = tType; //A.convertible(B)表征B是否可以转为A
    else if (fType.convertible(tType)) commonType = fType;
    else throw semantic_error("fail to reach a commonType for ternaryExpr to return");
    node->type = commonType;
}

void SemanticChecker::visitAssignExprNode(ASTAssignExprNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 14"<<std::endl;
#endif
    node->lhs->accept(this);
    node->rhs->accept(this);
    if (!node->lhs->type.assignable(node->rhs->type)) throw semantic_error("type mismatch in assignment");
    node->type = node->lhs->type;
}

//StringLiteral
//| logicalLiteral //实验中发现直接写为('true' | 'false')也可以
//| IntegerLiteral
//| This
//| Null
void SemanticChecker::visitLiterExprNode(ASTLiterExprNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 15"<<std::endl;
#endif
    if (node->value[0] == '\"') node->type = Type("string", 0, true);
    else if (node->value == "true" || node->value == "false") node->type = Type("bool", 0, true);
    else if (std::isdigit(node->value[0])) node->type = Type("int", 0, true);
    else if (node->value == "this") node->type = Type("this", 0, true);
    else if (node->value == "null") node->type = Type("null", 0, true);
    else throw semantic_error("unexpected literalType, the typeName is " + node->value);
}

void SemanticChecker::visitIdExprNode(ASTIdExprNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 16"<<std::endl;
#endif
    node->type = scope->tellVarType(node->name);
    node->uniqueName = scope->tellVarUnique(node->name);
}

void SemanticChecker::visitBranchStmtNode(ASTBranchStmtNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 17"<<std::endl;
#endif
    for (auto cons : node->conditions)
    {
        cons->accept(this);
        if (!cons->type.is_bool()) throw semantic_error("non-bool returnType for branchStmt is undefined");
    }
    for (auto block : node->blocks) block->accept(this);
}

void SemanticChecker::visitWhileStmtNode(ASTWhileStmtNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 18"<<std::endl;
#endif
    auto returnScope = scope;
    scope = new Scope(scope);
    try{
        node->cond->accept(this);
        if (!node->cond->type.is_bool())  throw semantic_error("non-bool conditionType occur in whileStmt");
        ++depth;
        for (auto stmt : node->block->stmts) stmt->accept(this);
        --depth;
    }
    catch (semantic_error &err) {
        delete scope;
        scope = returnScope;
        throw err;
    }
    delete scope;
    scope = returnScope;
}

void SemanticChecker::visitForStmtNode(ASTForStmtNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 19"<<std::endl;
#endif
    auto returnScope = scope;
    scope = new Scope(scope);
    try{
        if (node->init) node->init->accept(this);
        if (node->cond)
        {
            node->cond->accept(this);
            if (!node->cond->type.is_bool()) throw semantic_error("non-bool conditionType occur in forStmt");
        }
        if (node->step) node->step->accept(this);
        ++depth;
        std::cerr<<"%%%"<<node->block<<std::endl;
        for (auto stmt : node->block->stmts) stmt->accept(this);
        --depth;
    }
    catch (semantic_error &err) {
        delete scope;
        scope = returnScope;
        throw err;
    }
    delete scope;
    scope = returnScope;
}

void SemanticChecker::visitContinueStmtNode(ASTContinueStmtNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 20"<<std::endl;
#endif
    if (!depth) throw semantic_error("continueStmt appears outside the loop");
}

void SemanticChecker::visitBreakStmtNode(ASTBreakStmtNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 21"<<std::endl;
#endif
    if (!depth) throw semantic_error("continueStmt appears outside the loop");
}
void SemanticChecker::visitReturnStmtNode(ASTReturnStmtNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 22"<<std::endl;
#endif
    if (!curFunc) throw semantic_error("returnSmt appears outside of Func");
    if (!curFunc->returnType && node->expr) throw semantic_error("non-empty returnType appears in voidType func");
    if(curFunc->returnType)
    {
        if (node->expr)
        {
            node->expr->accept(this);
            Type tmp(curFunc->returnType->name, curFunc->returnType->dim, false);
            if (!tmp.assignable(node->expr->type)) throw semantic_error("return type mismatch(1) in returnStmt");
        }
        else
        {
            if (curFunc->returnType->name != "void") throw semantic_error("return type mismatch(2) in returnStmt");
        }
    }
}

void SemanticChecker::visitVarStmtNode(ASTVarStmtNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 23"<<std::endl;
#endif
    node->type->accept(this);
    auto curType = Type(node->type->name, node->type->dim, false);
    for (auto varPair : node->vars)
    {
        if (varPair.second)
        {
            varPair.second->accept(this);
            if (!curType.assignable(varPair.second->type)) throw semantic_error("type mismatch appears in varStmt");
        }
        scope->addVar(varPair.first, curType);
    }
    node->uniqueNameVars = node->vars;
    for (auto i : node->uniqueNameVars) i.first = scope->tellVarUnique(i.first);
}

void SemanticChecker::visitNewTypeNode(ASTNewTypeNode *node)
{
#ifdef INFO
    std::cerr<<"[semantic] 24"<<std::endl;
#endif
    for (auto expr : node->size)
    {
        expr->accept(this);
        if (!expr->type.is_int()) throw semantic_error("non-int array size appears in newType");
    }
}
