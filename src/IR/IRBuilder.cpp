#include "IRBuilder.h"
#include "IRType.h"
#include "IRNode.h"
#include "ASTNode.h"
//#define info

static IRIntType boolType(32);
static IRIntType int32Type(32);
static IRIntType int8Type(8);
static IRIntType int1Type(1);
static IRPtrType ptrType;
static IRStringType strType;
static IRVoidType voidType;
static IRVarNode thisNode(&ptrType, "this", true);

static IRLiteralNode nullNode(&ptrType, 0);
static IRLiteralNode intZeroNode(&int32Type, 0);
static IRLiteralNode intOneNode(&int32Type, 1);
static IRLiteralNode intMinusOneNode(&int32Type, -1);
static IRLiteralNode boolFalseNode(&int1Type, 0);
static IRLiteralNode boolTrueNode(&int1Type, 1);

void printAst2Value(ASTNode* p1, IRTypeNode* p2, int line)
{
    if(!p2) std::cerr<<"about ast2value : "<<p1<<" -> "<<p2<<" at line "<<line<<std::endl;
}

void IRBuilder::InitBuiltInFunc()
{
    //void print(string str);
    auto print = new IRFunctionNode(&voidType, "print");
    print->args.emplace_back(&strType, "str");
    program->functions.push_back(print);

    //void println(string str)
    auto println = new IRFunctionNode(&voidType, "println");
    println->args.emplace_back(&strType, "str");
    program->functions.push_back(println);

    //void printInt(i32 n)
    auto printInt = new IRFunctionNode(&voidType, "printInt");
    printInt->args.emplace_back(&int32Type, "n");
    program->functions.push_back(printInt);

    //void printlnInt(i32 n)
    auto printlnInt = new IRFunctionNode(&voidType, "printlnInt");
    printlnInt->args.emplace_back(&int32Type, "n");
    program->functions.push_back(printlnInt);

    //ptr getString()
    auto getString = new IRFunctionNode(&ptrType, "getString");
    program->functions.push_back(getString);

    //i32 getInt()
    auto getInt = new IRFunctionNode(&int32Type, "getInt");
    program->functions.push_back(getInt);

    //str toString(i32 n)
    auto toString = new IRFunctionNode(&strType, "toString");
    toString->args.emplace_back(&int32Type, "n");
    program->functions.push_back(toString);

    //i32 array.size(ptr array)
    auto arraySize = new IRFunctionNode(&int32Type, "array.size");
    arraySize->args.emplace_back(&ptrType, "array");
    program->functions.push_back(arraySize);

    //i32 string.length(str str)
    auto stringLength = new IRFunctionNode(&int32Type, "string.length");
    stringLength->args.emplace_back(&strType, "str");
    program->functions.push_back(stringLength);

    //str string.substring(str str, i32 left, i32 right)
    auto stringSubstring = new IRFunctionNode(&strType, "string.substring");
    stringSubstring->args.emplace_back(&strType, "str");
    stringSubstring->args.emplace_back(&int32Type, "left");
    stringSubstring->args.emplace_back(&int32Type, "right");
    program->functions.push_back(stringSubstring);

    //void string.parseInt(str str)
    auto stringParseInt = new IRFunctionNode(&voidType, "string.parseInt");
    stringParseInt->args.emplace_back(&strType, "str");
    program->functions.push_back(stringParseInt);

    //i32 string.ord(str str, i32 pos)
    auto stringOrd = new IRFunctionNode(&int32Type, "string.ord");
    stringOrd->args.emplace_back(&strType, "str");
    stringOrd->args.emplace_back(&int32Type, "pos");
    program->functions.push_back(stringOrd);

    //str string.add(str str1, str str2)
    auto stringAdd = new IRFunctionNode(&strType, "string.add");
    stringAdd->args.emplace_back(&strType, "str1");
    stringAdd->args.emplace_back(&strType, "str2");
    program->functions.push_back(stringAdd);

    //i1 string.equal(str str1, str str2)
    auto stringEqual = new IRFunctionNode(&int1Type, "string.equal");
    stringEqual->args.emplace_back(&strType, "str1");
    stringEqual->args.emplace_back(&strType, "str2");
    program->functions.push_back(stringEqual);

    //i1 string.notEqual(str str1, str str2)
    auto stringNotEqual = new IRFunctionNode(&int1Type, "string.notEqual");
    stringNotEqual->args.emplace_back(&strType, "str1");
    stringNotEqual->args.emplace_back(&strType, "str2");
    program->functions.push_back(stringNotEqual);

    //i1 string.less(str str1, str str2)
    auto stringLess = new IRFunctionNode(&int1Type, "string.less");
    stringLess->args.emplace_back(&strType, "str1");
    stringLess->args.emplace_back(&strType, "str2");
    program->functions.push_back(stringLess);

    //i1 string.greater(str str1, str str2)
    auto stringGreater = new IRFunctionNode(&int1Type, "string.greater");
    stringGreater->args.emplace_back(&strType, "str1");
    stringGreater->args.emplace_back(&strType, "str2");
    program->functions.push_back(stringGreater);

    //i1 string.lessEqual(str str1, str str2)
    auto stringLessEqual = new IRFunctionNode(&int1Type, "string.lessOrEqual");
    stringLessEqual->args.emplace_back(&strType, "str1");
    stringLessEqual->args.emplace_back(&strType, "str2");
    program->functions.push_back(stringLessEqual);

    //i1 string.greaterEqual(str str1, str str2)
    auto stringGreaterEqual = new IRFunctionNode(&int1Type, "string.greaterOrEqual");
    stringGreaterEqual->args.emplace_back(&strType, "str1");
    stringGreaterEqual->args.emplace_back(&strType, "str2");
    program->functions.push_back(stringGreaterEqual);

    //ptr malloc(i32 size)
    auto malloc = new IRFunctionNode(&ptrType, "malloc");
    malloc->args.emplace_back(&int32Type, "size");
    program->functions.push_back(malloc);

    //ptr __newPtrArray(i32 size)
    auto newPtrArray = new IRFunctionNode(&ptrType, "__newPtrArray");
    newPtrArray->args.emplace_back(&int32Type, "size");
    program->functions.push_back(newPtrArray);

    //ptr __newIntArray(i32 size)
    auto newIntArray = new IRFunctionNode(&ptrType, "__newIntArray");
    newIntArray->args.emplace_back(&int32Type, "size");
    program->functions.push_back(newIntArray);

    //ptr __newBoolArray(i32 size)
    auto newBoolArray = new IRFunctionNode(&ptrType, "__newBoolArray");
    newBoolArray->args.emplace_back(&int32Type, "size");
    program->functions.push_back(newBoolArray);
}

void IRBuilder::InitGlobalVar()
{
    if (varToInit.empty()) return;
    auto init = new IRFunctionNode(&voidType, "__.initGlobalVar");
    program->functions.push_back(init);
    init->blocks.push_back(new IRSuiteNode("entry"));
    currentFunction = init;
    currentBlock = init->blocks.front();
    for (auto u : varToInit)
    {
        visit(u.second);
        currentBlock->stmts.push_back(new IRStoreStmtNode(setVariable(turnIRType(&(u.second->type)), ast2value[u.second]), u.first));
    }
    currentBlock->stmts.push_back(new IRRetStmtNode(nullptr));
    currentFunction = nullptr;
}


//将值从指针中取出来，需要先指定指的类型。如果指针本身是常量，那么就不需要额外的工作
IRTypeNode *IRBuilder::setVariable(IRType *type, IRTypeNode *value)
{
    if (auto var = dynamic_cast<IRVarNode*>(value))
    {
        if (var->isConst) return value;
        auto tmp = new IRVarNode(type, "__var.tmp" + std::to_string(counter["var.tmp"]++), true);
        valueSet.insert(tmp);
        currentBlock->stmts.push_back(new IRLoadStmtNode(tmp, var));
        return tmp;
    }
    return value;
}

//对于cond做常量化处理，同时如果cond不是i1类型的话，将进行截断处理
void IRBuilder::setCondition(IRTypeNode *cond, IRSuiteNode *trueBlock, IRSuiteNode *falseBlock)
{
    auto condVar = setVariable(&int32Type, cond);
    IRTypeNode *condNode = nullptr;
    if (condVar->type->to_string() == "i1") condNode = condVar;
    else
    {
        condNode = new IRVarNode(&int1Type, "__cond.tmp" + std::to_string(counter["cond.tmp"]++), true);
        valueSet.insert(condNode);
        currentBlock->stmts.push_back(new IRTruncateStmtNode(dynamic_cast<IRVarNode*>(condNode), condVar));
    }
    currentBlock->stmts.push_back(new IRBrCondStmtNode(condNode, trueBlock->label, falseBlock->label));
}

IRTypeNode *IRBuilder::defaultValue(IRType *type)
{
    if (type == &int32Type) return &intZeroNode;
    if (type == &boolType) return &boolFalseNode;
    if (type == &strType) return strMap[""];
    return &nullNode;
}

void IRBuilder::initGlobalStr()
{
    string tmpStr = "_string" + std::to_string(counter["string"]++);
    auto varNode = new IRGlobalVarNode(&ptrType, tmpStr, true);
    valueSet.insert(varNode);
    strMap[""] = varNode;

    auto tmpIRType = new IRArrayType(1, &int8Type);
    auto strNode = new IRStringNode(tmpIRType, "");
    valueSet.insert(strNode);
    program->globalVarStmts.push_back(new IRGlobalVarStmtNode(strNode, varNode));
}

IRType *IRBuilder::turnIRType(Type *type)
{
    if (type->dim) return &ptrType;
    if (type->name == "void") return &voidType;
    if (type->name == "int") return &int32Type;
    if (type->name == "bool") return &boolType;
    if (type->name == "string") return &strType;
    return &ptrType;
}

IRType *IRBuilder::turnIRType(ASTTypeNode *typeNode)
{
    if (!typeNode) return &voidType;//一般来说typeNode为nullptr意味着这是类的构造函数
    if (typeNode->dim) return &ptrType;
    if (typeNode->name == "void") return &voidType;
    if (typeNode->name == "int") return &int32Type;
    if (typeNode->name == "bool") return &boolType;
    if (typeNode->name == "string") return &strType;
    return &ptrType;
}

void IRBuilder::registerFunction(ASTFunctionNode *node)
{
    auto func = new IRFunctionNode(turnIRType(&(node->type)));
    if (currentClass)
    {
        func->name = currentClass->name + "." + node->name;
        func->args.emplace_back(&ptrType, "this");//显式地加入this指针
        memberFuncSet.insert(func->name);
    }
    else func->name = node->name;
    for (auto arg : node->paras) func->args.emplace_back(turnIRType(arg.first), arg.second);

    program->functions.push_back(func);
    func2func[node] = func;
}

void IRBuilder::registerClass(ASTClassNode *node)
{
    auto classType = new IRClassType(node->name);
    int cnt = 0;
    for (auto varList : node->variables)
    {
        auto type = turnIRType(varList->type);
        for (const auto& i : varList->vars)
        {
            classType->members.push_back(type);
            memberIndex[node->name + "." + i.first] = cnt++;//i.first is the var name(string)
        }
    }
    str2clsType[node->name] = classType;
    currentClass = classType;
    for (auto func : node->functions) registerFunction(func);
    for (auto cons : node->constructors) registerFunction(cons);
    currentClass = nullptr;
}

void IRBuilder::visitProgramNode(ASTProgramNode *node)
{
    InitBuiltInFunc();
    initGlobalStr();
    for (auto c : node->children)
    {
        if (auto var = dynamic_cast<ASTVarStmtNode*>(c)) visit(var);
        else if (auto func = dynamic_cast<ASTFunctionNode*>(c)) registerFunction(func);
        else if (auto classDef = dynamic_cast<ASTClassNode*>(c)) registerClass(classDef);
    }
    InitGlobalVar();
    for (auto c : node->children)
    {
        if (auto func = dynamic_cast<ASTFunctionNode*>(c)) visit(func);
        else if (auto classDef = dynamic_cast<ASTClassNode*>(c)) visit(classDef);
    }
}

void IRBuilder::visitFunctionNode(ASTFunctionNode *node)
{
    auto func = func2func[node];
    func->blocks.push_back(new IRSuiteNode("entry"));
    currentFunction = func;
    currentBlock = func->blocks.front();
    if (node->name == "main" && !varToInit.empty())
    {
        auto initCall = new IRCallStmtNode(nullptr, "__.initGlobalVar");
        currentBlock->stmts.push_back(initCall);
    }

    for (int i = 0, s = node->paras.size(); i < s; ++i)
    {
        //vector<pair<ASTTypeNode*, string>> paras;
        auto varIRType = turnIRType(node->paras[i].first);
        auto ptrVarNode = new IRVarNode(&ptrType, node->uniqueNameParas[i].second, false);//这里传的是指针，所以非const
        auto constVarNode = new IRVarNode(varIRType, node->paras[i].second, true);//只支持一次赋值
        valueSet.insert(ptrVarNode), valueSet.insert(constVarNode);
        currentBlock->stmts.push_back(new IRAllocaStmtNode(ptrVarNode, varIRType));
        currentBlock->stmts.push_back(new IRStoreStmtNode(constVarNode, ptrVarNode));
        varMap[node->uniqueNameParas[i].second] = ptrVarNode;
#ifdef info
        std::cerr<<"about varMap1 : "<<node->uniqueNameParas[i].second<<" -> "<<ptrVarNode<<std::endl;
#endif
    }

    IRVarNode *retVar = nullptr;
    if (func->retType->to_string() != "void")
    {
        retVar = new IRVarNode(&ptrType, "__function.return" + std::to_string(counter["func.return"]++), false);
        valueSet.insert(retVar);
        currentBlock->stmts.push_back(new IRAllocaStmtNode(retVar, func->retType));
    }
    auto retBlock = new IRSuiteNode("__return_block" + std::to_string(counter["return_block"]++));
    returnBlock = retBlock;
    returnVar = retVar;
    visit(node->block);

    //对于func->blocks中的每一个block添加跳转returnBlock的语句
    for (auto &IRBlock : func->blocks)
    {
        if (IRBlock->stmts.empty())
        {
            IRBlock->stmts.push_back(new IRBrStmtNode(retBlock->label));
            continue;
        }
        bool flag1 = dynamic_cast<IRBrStmtNode*>(IRBlock->stmts.back());
        bool flag2 = dynamic_cast<IRBrCondStmtNode*>(IRBlock->stmts.back());
        if (!flag1 && !flag2) IRBlock->stmts.push_back(new IRBrStmtNode(retBlock->label));
    }

    currentBlock = retBlock;//开始处理retBlock的部分
    if (func->retType->to_string() == "void") currentBlock->stmts.push_back(new IRRetStmtNode(nullptr));
    else
    {
        //类似如下这种，先load再ret
        //%b.val.2 = load i32, ptr %b
        //ret i32 %b.val.2
        auto tmp = new IRVarNode(func->retType, "__function.return.tmp" + std::to_string(counter["func.return.tmp"]++), true);
        valueSet.insert(tmp);
        retBlock->stmts.push_back(new IRLoadStmtNode(tmp, retVar));
        retBlock->stmts.push_back(new IRRetStmtNode(tmp));
    }
    func->blocks.push_back(retBlock);
    currentFunction = nullptr;
    currentBlock = nullptr;
}

void IRBuilder::visitSuiteNode(ASTSuiteNode *node)
{
    for (auto s : node->stmts) visit(s);
}

void IRBuilder::visitClassNode(ASTClassNode *node)
{
    auto cls = str2clsType[node->name];
    currentClass = cls;
    for (auto func : node->functions) visit(func);
    for (auto cons : node->constructors) visit(cons);
    currentClass = nullptr;
}

void IRBuilder::visitVarStmtNode(ASTVarStmtNode *node)
{
    auto varIRType = turnIRType(node->type);
    if (!currentFunction)
    {
        for (auto v : node->uniqueNameVars)
        {
            auto varNode = new IRGlobalVarNode(&ptrType, v.first, false);
            valueSet.insert(varNode);
            auto varStmt = new IRGlobalVarStmtNode(defaultValue(varIRType), varNode);//先丢一个默认值
            if (v.second)
            {
                if (auto expr = dynamic_cast<ASTLiterExprNode*>(v.second))
                {
                    visit(expr);
                    varStmt->value = ast2value[expr];
                }
                else varToInit.emplace_back(varNode, v.second);//不是常量，需要记录下来等后续处理
            }
            program->globalVarStmts.push_back(varStmt);
            varMap[v.first] = varNode;
#ifdef info
            std::cerr<<"about varMap2 : "<<v.first<<" -> "<<varNode<<std::endl;
#endif
        }
    }
    else
    {
        for (auto v : node->uniqueNameVars)
        {
            auto var = new IRVarNode(&ptrType, v.first, false);
            valueSet.insert(var);
            currentBlock->stmts.push_back(new IRAllocaStmtNode(var, varIRType));
            if (v.second)
            {
                visit(v.second);
                auto constVar = setVariable(varIRType, ast2value[v.second]);
                currentBlock->stmts.push_back(new IRStoreStmtNode(constVar, var));
            }
            else if (varIRType->to_string() == "ptr")
            {
                currentBlock->stmts.push_back(new IRStoreStmtNode(&nullNode, var));
            }
            varMap[v.first] = var;
#ifdef info
            std::cerr<<"about varMap3 : "<<v.first<<" -> "<<var<<std::endl;
#endif
        }
    }
}

void IRBuilder::visitContinueStmtNode(ASTContinueStmtNode *node)
{
    //nextBlock在while与for中被维护
    currentBlock->stmts.push_back(new IRBrStmtNode(nextBlock->label));
}

void IRBuilder::visitReturnStmtNode(ASTReturnStmtNode *node)
{
    //ASTExprNode* expr = nullptr;
    if (!node->expr) currentBlock->stmts.push_back(new IRBrStmtNode(returnBlock->label));//currentBlock->stmts.push_back(new IRRetStmtNode(nullptr));
    else
    {
        visit(node->expr);
        auto ret = setVariable(turnIRType(&(node->expr->type)), ast2value[node->expr]);
        //先给returnVar赋值，然后告诉程序去跳转到returnBlock
        currentBlock->stmts.push_back(new IRStoreStmtNode(ret, returnVar));
        currentBlock->stmts.push_back(new IRBrStmtNode(returnBlock->label));
    }
}

void IRBuilder::visitWhileStmtNode(ASTWhileStmtNode *node)
{
    auto cond = new IRSuiteNode("__while.cond" + std::to_string(counter["while.cond"]++));
    currentFunction->blocks.push_back(cond);

    auto body = new IRSuiteNode("__while.body" + std::to_string(counter["while.body"]++));
    currentFunction->blocks.push_back(body);

    auto end = new IRSuiteNode("__while.end" + std::to_string(counter["while.end"]++));
    currentFunction->blocks.push_back(end);

    currentBlock->stmts.push_back(new IRBrStmtNode(cond->label));
    currentBlock = cond;
    if (!node->cond) cond->stmts.push_back(new IRBrStmtNode(body->label));
    else
    {
        visit(node->cond);
        setCondition(ast2value[node->cond], body, end);
    }

    currentBlock = body;
    auto nextBlockCopy = nextBlock, endBlockCopy = endBlock;
    nextBlock = cond, endBlock = end;
    visit(node->block);
    currentBlock->stmts.push_back(new IRBrStmtNode(cond->label));
    nextBlock = nextBlockCopy, endBlock = endBlockCopy;
    currentBlock = end;
}

void IRBuilder::visitBreakStmtNode(ASTBreakStmtNode *node)
{
    //三步走：先添加一个跳转语句，然后新建一个block并将其实质性地加入到当前Func，最后将currentBlock指向新建的block
    currentBlock->stmts.push_back(new IRBrStmtNode(endBlock->label));
    auto block = new IRSuiteNode("__break_block" + std::to_string(counter["break"]++));
    currentFunction->blocks.push_back(block);
    currentBlock = block;
}

void IRBuilder::visitForStmtNode(ASTForStmtNode *node)
{
    //this 4 auto were surprisingly formed by GitHub Copilot
    auto cond = new IRSuiteNode("__for.cond" + std::to_string(counter["for.cond"]++));
    currentFunction->blocks.push_back(cond);

    auto body = new IRSuiteNode("__for.body" + std::to_string(counter["for.body"]++));
    currentFunction->blocks.push_back(body);

    auto step = new IRSuiteNode("__for.step" + std::to_string(counter["for.step"]++));
    currentFunction->blocks.push_back(step);

    auto end = new IRSuiteNode("__for.end" + std::to_string(counter["for.end"]++));
    currentFunction->blocks.push_back(end);

    if (node->init) visit(node->init);
    currentBlock->stmts.push_back(new IRBrStmtNode(cond->label));
    currentBlock = cond;

    if (!node->cond) cond->stmts.push_back(new IRBrStmtNode(body->label));
    else
    {
        visit(node->cond);
        auto condVar = setVariable(turnIRType(&(node->cond->type)), ast2value[node->cond]);//auto condVar = setVariable(&int1Type, ast2value[node->cond]);
        setCondition(condVar, body, end);
    }

    currentBlock = body;
    auto nextBlockCopy = nextBlock, endBlockCopy = endBlock;
    nextBlock = step, endBlock = end;
    visit(node->block);
    currentBlock->stmts.push_back(new IRBrStmtNode(step->label));
    nextBlock = nextBlockCopy, endBlock = endBlockCopy;

    currentBlock = step;
    if (node->step) visit(node->step);
    currentBlock->stmts.push_back(new IRBrStmtNode(cond->label));
    currentBlock = end;
}
void IRBuilder::visitBranchStmtNode(ASTBranchStmtNode *node)
{
    int blockSum = node->blocks.size();
    int condSum = node->conditions.size();
    bool isFull = (blockSum == condSum);
    auto ifEndBlock = new IRSuiteNode("__if.end" + std::to_string(counter["if.end"]++));
    for (int i = 0; i < blockSum; ++i)
    {
        if (i < condSum)
        {
            auto trueBlock = new IRSuiteNode("__if.true" + std::to_string(counter["if.true"]++));
            currentFunction->blocks.push_back(trueBlock);
            IRSuiteNode *falseBlock = nullptr;
            //判定为假，进下一个判定语句，若无下一个判定语句，则进ifEndBlock
            if (i == blockSum - 1 && isFull) falseBlock = ifEndBlock;
            else
            {
                falseBlock = new IRSuiteNode("__if.false" + std::to_string(counter["if.false"]++));
                currentFunction->blocks.push_back(falseBlock);
            }

            visit(node->conditions[i]);
            setCondition(ast2value[node->conditions[i]], trueBlock, falseBlock);

            //开始处理trueBlock的部分
            currentBlock = trueBlock;
            visit(node->blocks[i]);
            currentBlock->stmts.push_back(new IRBrStmtNode(ifEndBlock->label));
            currentBlock = falseBlock;
        }
        else//这是最后一个else语句
        {
            visit(node->blocks[i]);
            currentBlock->stmts.push_back(new IRBrStmtNode(ifEndBlock->label));
        }
    }
    currentFunction->blocks.push_back(ifEndBlock);
    currentBlock = ifEndBlock;
}

void IRBuilder::visitTernaryExprNode(ASTTernaryExprNode *node)
{
    auto type = turnIRType(&(node->type));
    bool nonVoid = (type->to_string() != "void");
    auto trueBlock = new IRSuiteNode("__ternary.true" + std::to_string(counter["ternary.true"]++));
    currentFunction->blocks.push_back(trueBlock);
    auto falseBlock = new IRSuiteNode("__ternary.false" + std::to_string(counter["ternary.false"]++));
    currentFunction->blocks.push_back(falseBlock);
    auto ternaryEndBlock = new IRSuiteNode("__ternary.end" + std::to_string(counter["ternary.end"]++));
    currentFunction->blocks.push_back(ternaryEndBlock);

    IRVarNode *res = nullptr;
    if (nonVoid)
    {
        res = new IRVarNode(&ptrType, "__ternary.res" + std::to_string(counter["ternary.res"]++), false);
        valueSet.insert(res);
        currentBlock->stmts.push_back(new IRAllocaStmtNode(res, type));
    }

    //cond
    visit(node->cond);
    setCondition(ast2value[node->cond], trueBlock, falseBlock);

    //trueBlock
    currentBlock = trueBlock;
    visit(node->True);
    if (nonVoid)
    {
        auto trueConstVar = setVariable(type, ast2value[node->True]);
        currentBlock->stmts.push_back(new IRStoreStmtNode(trueConstVar, res));
    }
    currentBlock->stmts.push_back(new IRBrStmtNode(ternaryEndBlock->label));

    //falseBlock
    currentBlock = falseBlock;
    visit(node->False);
    if (nonVoid)
    {
        auto falseConstVar = setVariable(type, ast2value[node->False]);
        currentBlock->stmts.push_back(new IRStoreStmtNode(falseConstVar, res));
    }
    currentBlock->stmts.push_back(new IRBrStmtNode(ternaryEndBlock->label));

    //endBlock
    currentBlock = ternaryEndBlock;
    ast2value[node] = res;//write the res of the calculation
#ifdef info
    printAst2Value(node, res, 1);
#endif
}

void IRBuilder::visitAssignExprNode(ASTAssignExprNode *node)
{
    auto IRType = turnIRType(&(node->type));
    visit(node->lhs);
    visit(node->rhs);
    auto lhsNode = dynamic_cast<IRVarNode*>(ast2value[node->lhs]);
    auto rhsNode = setVariable(IRType, ast2value[node->rhs]);
    currentBlock->stmts.push_back(new IRStoreStmtNode(rhsNode, lhsNode));
#ifdef info
//    std::cerr<<"detail-1-pointer8 "<<node->lhs<<std::endl;
//    std::cerr<<"detail-2-pointer8 "<<ast2value[node->lhs]<<std::endl;
//    std::cerr<<"pointer8 "<<lhsNode<<std::endl;
#endif
}


void IRBuilder::visitBinaryExprNode(ASTBinaryExprNode *node)
{
    auto IRType = turnIRType(&(node->type));
    IRVarNode *res = new IRVarNode(IRType, "__binary.tmp" + std::to_string(counter["binary.tmp"]++), true);
    valueSet.insert(res);
    //先判断类型，如果是字符串，则需要调用内置函数进行处理
    if (node->type.is_string())
    {
        visit(node->lhs), visit(node->rhs);
        auto lhsNode = setVariable(turnIRType(&(node->lhs->type)), ast2value[node->lhs]);
        auto rhsNode = setVariable(turnIRType(&(node->rhs->type)), ast2value[node->rhs]);
        auto callNode = new IRCallStmtNode(res, strOp[node->op]);
        callNode->args.push_back(lhsNode), callNode->args.push_back(rhsNode);
        currentBlock->stmts.push_back(callNode);
    }
    else if (node->op == "&&" || node->op == "||")
    {
        visit(node->lhs);
        auto lhs = ast2value[node->lhs];
        auto nextExprBlock = new IRSuiteNode("__logic" + std::to_string(counter["logic"]++));
        auto logicEndBlock = new IRSuiteNode("__logic.end" + std::to_string(counter["logic.end"]++));
        if (node->op == "||") setCondition(lhs, logicEndBlock, nextExprBlock);
        else setCondition(lhs, nextExprBlock, logicEndBlock);
        currentFunction->blocks.push_back(nextExprBlock);
        currentFunction->blocks.push_back(logicEndBlock);

        auto tmp = new IRPhiStmtNode(res);
        tmp->pairs.emplace_back(setVariable(turnIRType(&(node->lhs->type)), lhs), currentBlock->label);

        currentBlock = nextExprBlock;
        visit(node->rhs);
        auto rhs = ast2value[node->rhs];
        tmp->pairs.emplace_back(setVariable(turnIRType(&(node->rhs->type)), rhs), currentBlock->label);
        currentBlock->stmts.push_back(new IRBrStmtNode(logicEndBlock->label));

        currentBlock = logicEndBlock;
        logicEndBlock->stmts.push_back(tmp);
        ast2value[node] = res;
#ifdef info
        printAst2Value(node, res, 2);
#endif
    }
    else
    {
        visit(node->lhs), visit(node->rhs);
        auto lhs = setVariable(turnIRType(&(node->lhs->type)), ast2value[node->lhs]);
        auto rhs = setVariable(turnIRType(&(node->rhs->type)), ast2value[node->rhs]);
        auto opIR = op[node->op];
        if (opIR.find("icmp") != std::string::npos)//为大小比较，需要特殊处理
        {
//            std::cerr<<"&*^%$#"<<node->type.name<<'\n';
            auto tmp = new IRVarNode(&int1Type, "__binary.tmp" + std::to_string(counter["binary.tmp"]++), true);
            valueSet.insert(tmp);
            currentBlock->stmts.push_back(new IRIcmpStmtNode(opIR, lhs, rhs, tmp));
            currentBlock->stmts.push_back(new IRZeroExtendStmtNode(res, tmp));
        }
        else
        {
            currentBlock->stmts.push_back(new IRBinaryStmtNode(opIR, lhs, rhs, res));
#ifdef info
//            std::cerr<<"binaryExpr debug0 -detail=1 : "<<node->rhs<<std::endl;
//            std::cerr<<"binaryExpr debug0 -detail=2 : "<<ast2value[node->rhs]<<std::endl;
//            std::cerr<<"binaryExpr debug0 : "<<rhs<<std::endl;
#endif
        }
    }
    ast2value[node] = res;
#ifdef info
    printAst2Value(node, res, 3);
#endif
}

void IRBuilder::visitMemberExprNode(ASTMemberExprNode *node)
{
    //ASTExprNode* object = nullptr; std::string member;
    auto tmp = new IRVarNode(&ptrType, "__member.tmp" + std::to_string(counter["member.tmp"]++), false);
    valueSet.insert(tmp);
    auto IRtype = turnIRType(&(node->type));
    visit(node->object);
    if (memberIndex.count(node->object->type.name + '.' + node->member))//在registerClass中被登记过
    {
        auto objectPtr = setVariable(&ptrType, ast2value[node->object]);
        auto eleIndex = new IRLiteralNode(&int32Type, memberIndex[node->object->type.name + '.' + node->member]);
        valueSet.insert(eleIndex);
        currentBlock->stmts.push_back(new IRGetElementPtrStmtNode(tmp, dynamic_cast<IRVarNode*>(objectPtr), eleIndex, turnIRType(&(node->type))));
        ast2value[node] = tmp;
#ifdef info
        printAst2Value(node, tmp, 4);
#endif
    }
    else//成员方法的调用
    {
        if (node->object->type.dim) memberFuncMap[node] = "array.size";
        else memberFuncMap[node] = node->object->type.name + '.' + node->member;
        auto text = setVariable(&ptrType, ast2value[node->object]);
        ast2value[node] = text;
#ifdef info
        printAst2Value(node, text, 5);
#endif
    }
}

void IRBuilder::visitSingleExprNode(ASTSingleExprNode *node)
{
    auto IRType = turnIRType(&(node->type));
    visit(node->expr);
    auto exprRes = setVariable(turnIRType(&(node->expr->type)), ast2value[node->expr]);

    auto res = new IRVarNode(IRType, "__single.res" + std::to_string(counter["single.res"]++), true);
    valueSet.insert(res);

    if (node->op == "-")
    {
        currentBlock->stmts.push_back(new IRBinaryStmtNode("sub", &intZeroNode, exprRes, res));
#ifdef info
        std::cerr<<"binaryExpr debug1 : "<<exprRes<<std::endl;
#endif
    }
    else if (node->op == "~") currentBlock->stmts.push_back(new IRBinaryStmtNode("xor", exprRes, &intMinusOneNode, res));
    else if (node->op == "!")
    {
        auto tmp1 = new IRVarNode(&int1Type, "__single.not.tmp" + std::to_string(counter["single.not.tmp"]++), true);
        auto tmp2 = new IRVarNode(&int1Type, "__single.not.tmp" + std::to_string(counter["single.not.tmp"]++), true);
        valueSet.insert(tmp1), valueSet.insert(tmp2);
        currentBlock->stmts.push_back(new IRTruncateStmtNode(tmp1, exprRes));//先截断
        currentBlock->stmts.push_back(new IRBinaryStmtNode("xor", tmp1, &boolTrueNode, tmp2));//逻辑取反
        currentBlock->stmts.push_back(new IRZeroExtendStmtNode(res, tmp2));//零拓展
    }
    else if (node->op == "++")
    {
        currentBlock->stmts.push_back(new IRBinaryStmtNode("add", exprRes, &intOneNode, res));
        currentBlock->stmts.push_back(new IRStoreStmtNode(res, dynamic_cast<IRVarNode*>(ast2value[node->expr])));
#ifdef info
//        std::cerr<<"detail-1-pointer9  "<<node->expr<<std::endl;
//        std::cerr<<"detail-2-pointer9  "<<ast2value[node->expr]<<std::endl;
//        std::cerr<<"pointer9  "<<dynamic_cast<IRVarNode*>(ast2value[node->expr])<<std::endl;
#endif
    }
    else if (node->op == "--")
    {
        currentBlock->stmts.push_back(new IRBinaryStmtNode("sub", exprRes, &intOneNode, res));
        currentBlock->stmts.push_back(new IRStoreStmtNode(res, dynamic_cast<IRVarNode*>(ast2value[node->expr])));
    }
    if (node->right)
    {
        ast2value[node] = exprRes;
#ifdef info
        printAst2Value(node, exprRes, 6);
#endif
    }
    else
    {
        ast2value[node] = res;
#ifdef info
        printAst2Value(node, res, 7);
#endif
    }
}

void IRBuilder::visitLiterExprNode(ASTLiterExprNode *node)
{
    if (node->type.is_bool())
    {
        int val = (node->value == "true" ? 1 : 0);
        auto res = new IRLiteralNode(&boolType, val);
        valueSet.insert(res);
        ast2value[node] = res;
#ifdef info
        printAst2Value(node, res, 8);
#endif
    }
    else if (node->type.is_int())
    {
        auto res = new IRLiteralNode(&int32Type, std::stoi(node->value));
        valueSet.insert(res);
        ast2value[node] = res;
#ifdef info
        printAst2Value(node, res, 9);
#endif
    }
    else if (node->type.is_null())
    {
        ast2value[node] = &nullNode;
#ifdef info
        printAst2Value(node, &nullNode, 10);
#endif
    }
    else if (node->type.is_string())
    {
        auto str = node->value.substr(1, node->value.size() - 2);
        if (strMap.count(str))//如果已经存在，就直接维护一下ast2value就可以直接返回了
        {
            ast2value[node] = strMap[str];
#ifdef info
            printAst2Value(node, strMap[str], 11);
#endif
            return;
        }
        string res;
        for (int i = 0, s = str.size(); i < s; ++i)
        {
            if (str[i] != '\\') res += str[i];
            else
            {
                if (str[++i] == 'n') res += '\n';
                else if (str[i] == '"') res += '\"';
                else if (str[i] == '\\') res += '\\';
            }
        }
        auto type = new IRArrayType(res.size() + 1, &int8Type);
        auto globalVar = new IRGlobalVarNode(&ptrType, "__string" + std::to_string(counter["string"]++), true);
        auto strNode = new IRStringNode(type, res);
        valueSet.insert(globalVar), valueSet.insert(strNode);
        program->globalVarStmts.push_back(new IRGlobalVarStmtNode(strNode, globalVar));
        strMap[str] = globalVar;
        ast2value[node] = globalVar;
#ifdef info
        printAst2Value(node, globalVar, 12);
#endif
    }
}

void IRBuilder::visitArrayExprNode(ASTArrayExprNode *node)
{
    //ASTExprNode *array = nullptr, *index = nullptr;
    auto IRType = turnIRType(&(node->type));
    visit(node->array);
    auto arrayVar = setVariable(&ptrType, ast2value[node->array]);
    visit(node->index);
    auto indexVar = setVariable(&int32Type, ast2value[node->index]);
    auto res = new IRVarNode(&ptrType, "__array.res" + std::to_string(counter["array.tmp"]++), false);
    valueSet.insert(res);
    currentBlock->stmts.push_back(new IRGetElementPtrStmtNode(res, dynamic_cast<IRVarNode*>(arrayVar), indexVar, IRType));
    ast2value[node] = res;
#ifdef info
    printAst2Value(node, res, 13);
#endif
}

void IRBuilder::visitIdExprNode(ASTIdExprNode *node)
{
    if (node->name == "this")
    {
        ast2value[node] = &thisNode;
#ifdef info
        printAst2Value(node, &thisNode, 14);
#endif
    }
    else if (!currentClass || !memberIndex.count(currentClass->name + '.' + node->name))
    {
        //不是类的成员，或者虽然在类中，但是没有相关的memberIndex信息(对应着函数的传参)
        ast2value[node] = varMap[node->uniqueName];
#ifdef info
        printAst2Value(node, varMap[node->uniqueName], 15);
        std::cerr<<"in line 15, the varMap: "<<node->uniqueName<<" -> "<<varMap[node->uniqueName]<<std::endl;
#endif
    }
    else//类的成员
    {
        auto index = new IRLiteralNode(&int32Type, memberIndex[currentClass->name + '.' + node->name]);
        auto res = new IRVarNode(&ptrType, "__member.tmp" + std::to_string(counter["member.tmp"]++), false);
        valueSet.insert(index), valueSet.insert(res);
        currentBlock->stmts.push_back(new IRGetElementPtrStmtNode(res, &thisNode, index, turnIRType(&(node->type))));
        ast2value[node] = res;
#ifdef info
        printAst2Value(node, res, 16);
#endif
    }
}

void IRBuilder::visitExprStmtNode(ASTExprStmtNode *node)
{
    if (node->expr) visit(node->expr);
}

void IRBuilder::visitFuncExprNode(ASTFuncExprNode *node)
{
    //ASTExprNode* func = nullptr;  vector<ASTExprNode*> args;
    auto IRType = turnIRType(&(node->type));
    IRVarNode *res = nullptr;

    if (IRType->to_string() != "void")
    {
        res = new IRVarNode(IRType, "__call.tmp" + std::to_string(counter["call.tmp"]++), true);
        valueSet.insert(res);
    }

    IRCallStmtNode *callNode = nullptr;
    if (auto func = dynamic_cast<ASTIdExprNode*>(node->func))
    {
        //类成员函数调用
        if (currentClass && memberFuncSet.contains(currentClass->name + '.' + func->name))
        {
            callNode = new IRCallStmtNode(res, currentClass->name + '.' + func->name);
            auto thisVar = new IRVarNode(&ptrType, "this", true);
            valueSet.insert(thisVar);
            callNode->args.push_back(thisVar);
        }
        //普通函数调用
        else callNode = new IRCallStmtNode(res, func->name);
    }
    else
    {
        auto memFunc = dynamic_cast<ASTMemberExprNode*>(node->func);
        visit(node->func);
        callNode = new IRCallStmtNode(res, memberFuncMap[memFunc]);
        callNode->args.push_back(setVariable(&ptrType, ast2value[memFunc]));
    }

    for (auto arg : node->args)
    {
        visit(arg);
        callNode->args.push_back(setVariable(turnIRType(&(arg->type)), ast2value[arg]));
    }
    currentBlock->stmts.push_back(callNode);
    ast2value[node] = res;
#ifdef info
    printAst2Value(node, res, 17);
#endif
}

void IRBuilder::visitNewExprNode(ASTNewExprNode *node)
{
    if (node->newType->size.empty())
    {
        //simple situation ptr var = new type []
//        auto newType = turnIRType(&(node->type));
        auto newType = str2clsType[node->newType->name];//info are prepared in registerClass
        auto res = new IRVarNode(&ptrType, "__new.res" + std::to_string(counter["new.res"]++), true);//pointer is const
        auto sizeNode = new IRLiteralNode(&int32Type, newType->size());
        auto callNode = new IRCallStmtNode(res, "malloc");
        valueSet.insert(res), valueSet.insert(sizeNode);
        //start to prepare the args
        callNode->args.push_back(sizeNode);
        currentBlock->stmts.push_back(callNode);

        auto consFuncStr = node->newType->name + '.' + node->newType->name;
        if (memberFuncSet.contains(consFuncStr))
        {
            //call the constructor
            auto consNode = new IRCallStmtNode(nullptr, consFuncStr);
            consNode->args.push_back(res);
            currentBlock->stmts.push_back(consNode);
        }
        ast2value[node] = res;
#ifdef info
        printAst2Value(node, res, 18);
#endif
    }
    else
    {
        //more complex situation, like ptr var = new int [5][] or ptr var = new int [5][6]
        auto text = mallocArray(node->newType, 0);
        ast2value[node] = text;//递归函数
#ifdef info
        printAst2Value(node, text, 19);
#endif
    }
}

//currentBlock->stmts.push_back(new IRGetElementPtrStmtNode(index, resPtr, i, &ptrType));
//currentBlock->stmts.push_back(new IRStoreStmtNode(sonPtr, index));
//TODO:double check needed
IRVarNode *IRBuilder::mallocArray(ASTNewTypeNode *node, int index)
{
    visit(node->size[index]);
    auto sizeNode = setVariable(&int32Type, ast2value[node->size[index]]);
    if (index == node->size.size() - 1)
    {
        //递归出口
        auto resPtr = new IRVarNode(&ptrType, "__new.res" + std::to_string(counter["new.res"]++), true);
        valueSet.insert(resPtr);

        IRCallStmtNode *callNode = nullptr;
        if (node->size.size() < node->dim) callNode = new IRCallStmtNode(resPtr, "__newPtrArray");
        else if (node->name == "bool") callNode = new IRCallStmtNode(resPtr, "__newBoolArray");
        else if (node->name == "int") callNode = new IRCallStmtNode(resPtr, "__newIntArray");
        else /*the str case*/ callNode = new IRCallStmtNode(resPtr, "__newPtrArray");
        callNode->args.push_back(sizeNode);

        currentBlock->stmts.push_back(callNode);
        return resPtr;
    }
    else
    {
        auto resPtr = new IRVarNode(&ptrType, "__new.res" + std::to_string(counter["new.res"]++), true);
        valueSet.insert(resPtr);
        auto callNode = new IRCallStmtNode(resPtr, "__newPtrArray");
        callNode->args.push_back(sizeNode);
        currentBlock->stmts.push_back(callNode);

        auto workBlock = new IRSuiteNode("__new.array" + std::to_string(counter["new.array"]++));
        auto workEnd = new IRSuiteNode("__new.array.end" + std::to_string(counter["new.array.end"]++));
        currentFunction->blocks.push_back(workBlock);
        currentBlock->stmts.push_back(new IRBrStmtNode(workBlock->label));
        string fromLabel = currentBlock->label;
        currentBlock = workBlock;

        auto i = new IRVarNode(&int32Type, "__new.tmp.i" + std::to_string(counter["new.tmp.i"]++), true);
        valueSet.insert(i);
        auto phiNode = new IRPhiStmtNode(i);
        currentBlock->stmts.push_back(phiNode);
        phiNode->pairs.emplace_back(&intZeroNode, fromLabel);
        auto next = new IRVarNode(&int32Type, "__new.tmp.next" + std::to_string(counter["new.tmp.next"]++), true);
        valueSet.insert(next);
        auto addStmt = new IRBinaryStmtNode(op["+"], &intOneNode, i, next);
        currentBlock->stmts.push_back(addStmt);

        auto sonPtr = mallocArray(node, index + 1);//递归此处发生
        auto index = new IRVarNode(&ptrType, "__new.tmp.ind" + std::to_string(counter["new.tmp.ind"]++), true);
        valueSet.insert(index);
        currentBlock->stmts.push_back(new IRGetElementPtrStmtNode(index, resPtr, i, &ptrType));
        currentBlock->stmts.push_back(new IRStoreStmtNode(sonPtr, index, true));

        phiNode->pairs.emplace_back(next, currentBlock->label);
        auto comp = new IRVarNode(&int1Type, "__new.tmp.comp" + std::to_string(counter["new.tmp.comp"]++), true);
        valueSet.insert(comp);
        currentBlock->stmts.push_back(new IRIcmpStmtNode("icmp slt", next, sizeNode, comp));//op["<"]
        currentBlock->stmts.push_back(new IRBrCondStmtNode(comp, workBlock->label, workEnd->label));

        currentBlock = workEnd;
        currentFunction->blocks.push_back(workEnd);
        return resPtr;
    }
}




























