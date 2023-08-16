#include "ASTBuilder.h"
#include "ASTNode.h"
#include "Exception.h"
#define Info

using std::any_cast;

std::any ASTBuilder::visitProgram(MxParser::ProgramContext *ctx)
{
#ifdef Info
    std::cerr<<"visitProgram\n";
#endif
    auto node = new ASTProgramNode;
    auto defVec = ctx->declaration();
    for (auto u : defVec)
    {
        auto res = visit(u->children[0]);
        if (!res.has_value()) continue;
        if (auto Var = any_cast<ASTStmtNode*>(&res)) node->children.push_back(*Var);
        else if (auto Func = any_cast<ASTFunctionNode*>(&res)) node->children.push_back(*Func);
        else if (auto Class = any_cast<ASTClassNode*>(&res)) node->children.push_back(*Class);
        else throw std::runtime_error("program unknown node type, in ASTBuilder");
    }
//    return node;
    return static_cast<ASTNode *>(node);
}

//functionDeclaration: typename identifier '(' functionDeclList? ')' body=suiteStatement;
std::any ASTBuilder::visitFunctionDeclaration(MxParser::FunctionDeclarationContext *ctx)
{
#ifdef Info
    std::cerr<<"visitFunctionDeclaration\n";
#endif
    auto node = new ASTFunctionNode;
    node->name = ctx->identifier()->Identifier()->getText();
    node->returnType = any_cast<ASTTypeNode *>(visit(ctx->typename_()));
    if (auto paras = ctx->functionDeclList())
    {
        auto tmp = visit(paras);
        node->paras = *any_cast<vector<pair<ASTTypeNode*, string>>>(&tmp);
    }
    node->block = dynamic_cast<ASTSuiteNode *>(any_cast<ASTStmtNode*>((visit(ctx->body))));
    return node;
}

//直接把functionDeclPair的信息处理完毕了，就不用重载对于functionDeclPair的visit了
std::any ASTBuilder::visitFunctionDeclList(MxParser::FunctionDeclListContext *ctx)
{
#ifdef Info
    std::cerr<<"visitFunctionDeclList\n";
#endif
    vector<pair<ASTTypeNode*, string>> list;
    for (auto defPair : ctx->functionDeclPair())
    {
        auto type = any_cast<ASTTypeNode*>(visit(defPair->typename_()));
        list.emplace_back(type, defPair->identifier()->Identifier()->getText());
    }
    return list;
}

std::any ASTBuilder::visitClassDeclaration(MxParser::ClassDeclarationContext *ctx)
{
#ifdef Info
    std::cerr<<"visitClassDeclaration\n";
#endif
    auto node = new ASTClassNode;
    node->name = ctx->identifier()->Identifier()->getText();
    auto components = ctx->classComponents();
    for (auto com : components)
    {
        auto res = visit(com->children[0]);
        if (!res.has_value()) continue;
        if (auto Var = any_cast<ASTStmtNode*>(&res)) node->variables.push_back(dynamic_cast<ASTVarStmtNode*>(*Var));
        if (auto Cons = any_cast<ASTConstructNode*>(&res)) node->constructors.push_back(*Cons);
        if (auto Func = any_cast<ASTFunctionNode*>(&res)) node->functions.push_back(*Func);
    }
    return node;
}

std::any ASTBuilder::visitConstructorDeclaration(MxParser::ConstructorDeclarationContext *ctx)
{
#ifdef Info
    std::cerr<<"visitConstructorDeclaration\n";
#endif
    auto node = new ASTConstructNode;
    node->name = ctx->identifier()->Identifier()->getText();
    node->block = dynamic_cast<ASTSuiteNode*>(any_cast<ASTStmtNode*>(visit(ctx->body)));
    return node;
}

//std::any ASTBuilder::visitSuiteStatement(MxParser::SuiteStatementContext *ctx)
//{
//#ifdef Info
//    std::cerr<<"visitSuiteStatement\n";
//#endif
//    auto node = new ASTSuiteNode;
////    std::cerr<<"visitSuite begin" << std::endl;
//    for (auto stmt : ctx->statement())
//    {
////        std::cerr<<"a Suite id here" << std::endl;
//        auto res = any_cast<ASTStmtNode*>(visit(stmt));
//        node->stmts.push_back(res);
//    }
////    std::cerr<<"###"<<node<<std::endl;
//    return static_cast<ASTStmtNode*>(node);
//}

std::any ASTBuilder::visitWrapper(MxParser::WrapperContext *ctx)
{
#ifdef Info
    std::cerr<<"visitWrapper\n";
#endif
    //有{}的情形
    if (ctx->suiteStatement())
    {
        auto tmp = visit(ctx->suiteStatement());
        if (auto res = *any_cast<ASTStmtNode*>(&tmp)) return res;
    }
    //无{}情形
    auto node = new ASTSuiteNode;
    auto tmp = visit(ctx->statement());
    if (auto res = *any_cast<ASTStmtNode*>(&tmp)) node->stmts.push_back(res);
    return static_cast<ASTStmtNode*>(node);
}


std::any ASTBuilder::visitVariableDeclaration(MxParser::VariableDeclarationContext *ctx)
{
#ifdef Info
    std::cerr<<"visitVariableDeclaration\n";
#endif
    auto node = new ASTVarStmtNode;
    node->type = any_cast<ASTTypeNode*>(visit(ctx->typename_()));
    for (auto defPair : ctx->initDeclarator())
    {
        if (auto expr = defPair->expression())
        {
            node->vars.emplace_back(defPair->identifier()->Identifier()->getText(), any_cast<ASTExprNode*>(visit(expr)));
        }
        else
        {
            node->vars.emplace_back(defPair->identifier()->Identifier()->getText(), nullptr);
        }
    }
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitExpresionStatement(MxParser::ExpresionStatementContext *ctx)
{
#ifdef Info
    std::cerr<<"visitExpresionStatement\n";
#endif
    auto node = new ASTExprStmtNode;
    if (ctx->expression())
    {
        auto res = visit(ctx->expression());
        node->expr = any_cast<ASTExprNode*>(res);
    }
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitBranchStatement(MxParser::BranchStatementContext *ctx)
{
#ifdef Info
    std::cerr<<"visitBranchStatement\n";
#endif
    auto node = new ASTBranchStmtNode;
    node->conditions.push_back(any_cast<ASTExprNode*>(visit(ctx->expression())));
    for (auto wra : ctx->wrapper())
    {
        node->blocks.push_back(dynamic_cast<ASTSuiteNode*>(any_cast<ASTStmtNode*>(visit(wra))));
    }
    return static_cast<ASTStmtNode*>(node);
}

//START HERE
std::any ASTBuilder::visitWhileLoop(MxParser::WhileLoopContext *ctx)
{
#ifdef Info
    std::cerr<<"visitWhileLoop\n";
#endif
    auto node = new ASTWhileStmtNode;
//    std::cerr<<"visitWhileLoop 1.00"<<std::endl;
    node->cond = any_cast<ASTExprNode*>(visit(ctx->expression()));
//    std::cerr<<"visitWhileLoop 2.00"<<std::endl;
    node->block = dynamic_cast<ASTSuiteNode*>(any_cast<ASTStmtNode*>(visit(ctx->wrapper())));
//    std::cerr<<"visitWhileLoop 3.00"<<std::endl;
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitNormalForLoop(MxParser::NormalForLoopContext *ctx)
{
#ifdef Info
    std::cerr<<"visitNormalForLoop\n";
#endif
    auto node = new ASTForStmtNode;
    if (auto cur = ctx->init)
    {
        auto res = visit(cur);
        if (res.has_value()) node->init = any_cast<ASTStmtNode*>(res);
    }
    if (auto cur = ctx->condition)
    {
        auto res = visit(cur);
        if (res.has_value()) node->cond = any_cast<ASTExprNode*>(res);
    }
    if (auto cur = ctx->step)
    {
        auto res = visit(cur);
        if (res.has_value()) node->step = any_cast<ASTExprNode*>(res);
    }
    auto res = visit(ctx->body);
//    std::cerr<<"(((****************"<<any_cast<ASTStmtNode *>(res)<<std::endl;
    node->block = dynamic_cast<ASTSuiteNode *>(any_cast<ASTStmtNode *>(res));
//    std::cerr<<"(((&&&&&&&&&&&&&&&&&&&&&&"<<node->block<<std::endl;
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitExprForLoop(MxParser::ExprForLoopContext *ctx)
{
#ifdef Info
    std::cerr<<"visitExprForLoop\n";
#endif
    auto node = new ASTForStmtNode;
    if (auto cur = ctx->init)
    {
        auto res = visit(cur);
        if (res.has_value()) node->init = any_cast<ASTStmtNode*>(res);
    }
    if (auto cur = ctx->condition)
    {
        auto res = visit(cur);
        if (res.has_value()) node->cond = any_cast<ASTExprNode*>(res);
    }
    if (auto cur = ctx->step)
    {
        auto res = visit(cur);
        if (res.has_value()) node->step = any_cast<ASTExprNode*>(res);
    }
    auto res = visit(ctx->body);
//    std::cerr<<"****************"<<any_cast<ASTStmtNode *>(res)<<std::endl;
    node->block = dynamic_cast<ASTSuiteNode *>(any_cast<ASTStmtNode *>(res));
//    std::cerr<<"&&&&&&&&&&&&&&&&&&&&&&"<<node->block<<std::endl;
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitReturnStmt(MxParser::ReturnStmtContext *ctx)
{
#ifdef Info
    std::cerr<<"visitReturnStmt\n";
#endif
    auto node = new ASTReturnStmtNode;
    if (ctx->returnStatement()->expression()) node->expr = any_cast<ASTExprNode*>(visit(ctx->returnStatement()->expression()));
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitBreakStmt(MxParser::BreakStmtContext *ctx)
{
#ifdef Info
    std::cerr<<"visitBreakStmt\n";
#endif
    auto node = new ASTBreakStmtNode;
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitContinueStmt(MxParser::ContinueStmtContext *ctx)
{
#ifdef Info
    std::cerr<<"visitContinueStmt\n";
#endif
    auto node = new ASTContinueStmtNode;
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitSuiteStatement(MxParser::SuiteStatementContext *ctx)
{
#ifdef Info
    std::cerr<<"visitSuiteStatement\n";
#endif
    auto node = new ASTSuiteNode;
//    std::cerr<<"visitSuite begin" << std::endl;
    for (auto stmt : ctx->statement())
    {
        auto res = any_cast<ASTStmtNode*>(visit(stmt));
        node->stmts.push_back(res);
    }
//    std::cerr<<"###"<<node<<std::endl;
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitArrayType(MxParser::ArrayTypeContext *ctx)
{
#ifdef Info
    std::cerr<<"visitArrayType\n";
#endif
    auto node = any_cast<ASTTypeNode *>(visit(ctx->typename_()));
    ++node->dim;
    return node;
}

std::any ASTBuilder::visitBuiltInType(MxParser::BuiltInTypeContext *ctx)
{
#ifdef Info
    std::cerr<<"visitBuiltInType\n";
#endif
    auto node = new ASTTypeNode;
    node->name = ctx->builtInTypename()->getText();
    return node;
}

std::any ASTBuilder::visitClassType(MxParser::ClassTypeContext *ctx)
{
#ifdef Info
    std::cerr<<"visitClassType\n";
#endif
    auto node = new ASTTypeNode;
    node->name = ctx->identifier()->Identifier()->getText();
    return node;
}

std::any ASTBuilder::visitLiteralExpression(MxParser::LiteralExpressionContext *ctx)
{
#ifdef Info
    std::cerr<<"visitLiteralExpression\n";
#endif
    auto node = new ASTLiterExprNode;
    node->value = ctx->getText();
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitNewClassArray(MxParser::NewClassArrayContext *ctx)
{
#ifdef Info
    std::cerr<<"visitNewClassArray\n";
#endif
    auto node = new ASTNewTypeNode;
    node->name = ctx->identifier()->Identifier()->getText();
    if (ctx->flag) throw syntax_error("ASTNewTypeNode error");
    for (auto i : ctx->newArrayExpr()) node->size.push_back(any_cast<ASTExprNode*>(visit(i)));
    node->dim = ctx->newArrayExpr().size() + ctx->newArrayEmpty().size();
    return node;
}

std::any ASTBuilder::visitNewBuildInArray(MxParser::NewBuildInArrayContext *ctx)
{
#ifdef Info
    std::cerr<<"visitNewBuildInArray\n";
#endif
    auto node = new ASTNewTypeNode;
    node->name = ctx->builtInTypename()->getText();
    if (ctx->flag) throw syntax_error("ASTNewTypeNode error");
    for (auto i : ctx->newArrayExpr()) node->size.push_back(any_cast<ASTExprNode*>(visit(i)));
    node->dim = ctx->newArrayExpr().size() + ctx->newArrayEmpty().size();
    return node;
}

std::any ASTBuilder::visitNewClass(MxParser::NewClassContext *ctx)
{
#ifdef Info
    std::cerr<<"visitNewClass\n";
#endif
    auto node = new ASTNewTypeNode;
    node->name = ctx->identifier()->Identifier()->getText();
    node->dim = 0;
    return node;
//    return static_cast<ASTNewTypeNode*>(node);
}

std::any ASTBuilder::visitNewArrayExpr(MxParser::NewArrayExprContext *ctx)
{
#ifdef Info
    std::cerr<<"visitNewArrayExpr\n";
#endif
    return visit(ctx->expression());
}

std::any ASTBuilder::visitNewExpr(MxParser::NewExprContext *ctx)
{
#ifdef Info
    std::cerr<<"visitNewExpr\n";
#endif
    return visit(ctx->newExpression());
}

std::any ASTBuilder::visitMemberExpr(MxParser::MemberExprContext *ctx)
{
#ifdef Info
    std::cerr<<"visitMemberExpr\n";
#endif
    auto node = new ASTMemberExprNode;
    node->object = any_cast<ASTExprNode*>(visit(ctx->expression()));
    node->member = ctx->identifier()->Identifier()->getText();
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitBinaryExpr(MxParser::BinaryExprContext *ctx)
{
#ifdef Info
    std::cerr<<"visitBinaryExpr\n";
#endif
    auto node = new ASTBinaryExprNode;
    node->op = ctx->op->getText();
    node->lhs = any_cast<ASTExprNode*>(visit(ctx->lhs));
    node->rhs = any_cast<ASTExprNode*>(visit(ctx->rhs));
    return static_cast<ASTExprNode*>(node);
}
//lhs=expression op=('++' | '--')                                  # PostfixOpExpr
std::any ASTBuilder::visitPostfixOpExpr(MxParser::PostfixOpExprContext *ctx)
{
#ifdef Info
    std::cerr<<"visitPostfixOpExpr\n";
#endif
    auto node = new ASTSingleExprNode;
    node->right = true;
    node->op = ctx->op->getText();
    node->expr = any_cast<ASTExprNode*>(visit(ctx->lhs));
    return static_cast<ASTExprNode*>(node);
}
//<assoc=right>  op=('++' | '--') rhs=expression                   # PrefixOpExpr
std::any ASTBuilder::visitPrefixOpExpr(MxParser::PrefixOpExprContext *ctx)
{
#ifdef Info
    std::cerr<<"visitPrefixOpExpr\n";
#endif
    auto node = new ASTSingleExprNode;
    node->right = false;
    node->op = ctx->op->getText();
    node->expr = any_cast<ASTExprNode*>(visit(ctx->rhs));
    return static_cast<ASTExprNode*>(node);
}
//    | <assoc=right>  op=('!' | '~' | '+' | '-')                rhs=expression # UnaryExpr
std::any ASTBuilder::visitUnaryExpr(MxParser::UnaryExprContext *ctx)
{
#ifdef Info
    std::cerr<<"visitUnaryExpr\n";
#endif
    auto node = new ASTSingleExprNode;
    node->right = false;
    node->op = ctx->op->getText();
    node->expr = any_cast<ASTExprNode*>(visit(ctx->rhs));
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitAssignExpr(MxParser::AssignExprContext *ctx)
{
#ifdef Info
    std::cerr<<"visitAssignExpr\n";
#endif
    auto node = new ASTAssignExprNode;
    node->lhs = any_cast<ASTExprNode*>(visit(ctx->expression()[0]));
    node->rhs = any_cast<ASTExprNode*>(visit(ctx->expression()[1]));
//    std::cerr<<"hsthsyhsthsth" << std::endl;
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitArrayExpr(MxParser::ArrayExprContext *ctx)
{
#ifdef Info
    std::cerr<<"visitArrayExpr\n";
#endif
    auto node = new ASTArrayExprNode;
    node->array = any_cast<ASTExprNode*>(visit(ctx->expression()[0]));
    node->index = any_cast<ASTExprNode*>(visit(ctx->expression()[1]));
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitIdentifierExpr(MxParser::IdentifierExprContext *ctx)
{
#ifdef Info
    std::cerr<<"visitIdentifierExpr\n";
#endif
    auto node = new ASTIdExprNode;
    node->name = ctx->getText();
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitLiteralExpr(MxParser::LiteralExprContext *ctx)
{
#ifdef Info
    std::cerr<<"visitLiteralExpr\n";
#endif
    return visit(ctx->literalExpression());
}

std::any ASTBuilder::visitFunctionCall(MxParser::FunctionCallContext *ctx)
{
#ifdef Info
    std::cerr<<"visitFunctionCall\n";
#endif
    auto node = new ASTFuncExprNode;
    node->func = any_cast<ASTExprNode*>(visit(ctx->expression()));
    if (ctx->functionCallList())
    {
        for (auto expr : ctx->functionCallList()->expression())
        {
            node->args.push_back(any_cast<ASTExprNode*>(visit(expr)));
        }
    }
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitParenExpr(MxParser::ParenExprContext *ctx)
{
#ifdef Info
    std::cerr<<"visitParenExpr\n";
#endif
    return visit(ctx->expression());
}

std::any ASTBuilder::visitTernaryExpr(MxParser::TernaryExprContext *ctx)
{
#ifdef Info
    std::cerr<<"visitTernaryExpr\n";
#endif
    auto node = new ASTTernaryExprNode;
    node->cond = any_cast<ASTExprNode*>(visit(ctx->expression()[0]));
    node->True = any_cast<ASTExprNode*>(visit(ctx->expression()[1]));
    node->False = any_cast<ASTExprNode*>(visit(ctx->expression()[2]));
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitNewExpression(MxParser::NewExpressionContext *ctx)
{
#ifdef Info
    std::cerr<<"visitNewExpression\n";
#endif
    auto node = new ASTNewExprNode;
    node->newType = any_cast<ASTNewTypeNode*>(visit(ctx->newTypename()));
    return static_cast<ASTExprNode*>(node);
}














