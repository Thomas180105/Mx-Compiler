#include "ASTBuilder.h"
#include "ASTNode.h"
#include "Exception.h"

using std::any_cast;

std::any ASTBuilder::visitProgram(MxParser::ProgramContext *ctx)
{
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
    return node;
}

//functionDeclaration: typename identifier '(' functionDeclList? ')' body=suiteStatement;
std::any ASTBuilder::visitFunctionDeclaration(MxParser::FunctionDeclarationContext *ctx)
{
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
    auto node = new ASTConstructNode;
    node->name = ctx->identifier()->Identifier()->getText();
    node->block = dynamic_cast<ASTSuiteNode*>(any_cast<ASTStmtNode*>(visit(ctx->body)));
    return node;
}

std::any ASTBuilder::visitVariableDeclaration(MxParser::VariableDeclarationContext *ctx)
{
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
    auto node = new ASTExprStmtNode;
    auto res = visit(ctx->expression());
    node->expr = any_cast<ASTExprNode*>(res);
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitBranchStatement(MxParser::BranchStatementContext *ctx)
{
    auto node = new ASTBranchStmtNode;
    node->conditions.push_back(any_cast<ASTExprNode*>(visit(ctx->expression())));
    for (auto stmt : ctx->statement())
    {
        node->blocks.push_back(dynamic_cast<ASTSuiteNode*>(any_cast<ASTStmtNode*>(visit(stmt))));
    }
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitWhileLoop(MxParser::WhileLoopContext *ctx)
{
    auto node = new ASTWhileStmtNode;
    node->cond = any_cast<ASTExprNode*>(visit(ctx->expression()));
    node->block = dynamic_cast<ASTSuiteNode*>(any_cast<ASTStmtNode*>(ctx->statement()));
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitNormalForLoop(MxParser::NormalForLoopContext *ctx)
{
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
    node->block = dynamic_cast<ASTSuiteNode *>(any_cast<ASTStmtNode *>(res));
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitExprForLoop(MxParser::ExprForLoopContext *ctx)
{
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
    node->block = dynamic_cast<ASTSuiteNode *>(any_cast<ASTStmtNode *>(res));
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitReturnStmt(MxParser::ReturnStmtContext *ctx)
{
    auto node = new ASTReturnStmtNode;
    if (ctx->returnStatement()->expression()) node->expr = any_cast<ASTExprNode*>(visit(ctx->returnStatement()->expression()));
    return node;
}

std::any ASTBuilder::visitBreakStmt(MxParser::BreakStmtContext *ctx)
{
    auto node = new ASTBreakStmtNode;
    return node;
}

std::any ASTBuilder::visitContinueStmt(MxParser::ContinueStmtContext *ctx)
{
    auto node = new ASTContinueStmtNode;
    return node;
}

std::any ASTBuilder::visitSuiteStatement(MxParser::SuiteStatementContext *ctx)
{
    auto node = new ASTSuiteNode;
    for (auto stmt : ctx->statement())
    {
        auto res = any_cast<ASTStmtNode*>(visit(stmt));
        node->stmts.push_back(res);
    }
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitArrayType(MxParser::ArrayTypeContext *ctx)
{
    auto node = any_cast<ASTTypeNode *>(visit(ctx->typename_()));
    ++node->dim;
    return node;
}

std::any ASTBuilder::visitBuiltInType(MxParser::BuiltInTypeContext *ctx)
{
    auto node = new ASTTypeNode;
    node->name = ctx->builtInTypename()->getText();
    return node;
}

std::any ASTBuilder::visitClassType(MxParser::ClassTypeContext *ctx)
{
    auto node = new ASTTypeNode;
    node->name = ctx->identifier()->Identifier()->getText();
    return node;
}

std::any ASTBuilder::visitLiteralExpression(MxParser::LiteralExpressionContext *ctx)
{
    auto node = new ASTLiterExprNode;
    node->value = ctx->getText();
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitNewClassArray(MxParser::NewClassArrayContext *ctx)
{
    auto node = new ASTNewTypeNode;
    node->name = ctx->identifier()->Identifier()->getText();
    if (ctx->flag) throw syntax_error("ASTNewTypeNode error");
    for (auto i : ctx->newArrayExpr()) node->size.push_back(any_cast<ASTExprNode*>(visit(i)));
    node->dim = ctx->newArrayExpr().size() + ctx->newArrayEmpty().size();
    return node;
}

std::any ASTBuilder::visitNewBuildInArray(MxParser::NewBuildInArrayContext *ctx)
{
    auto node = new ASTNewTypeNode;
    node->name = ctx->builtInTypename()->getText();
    if (ctx->flag) throw syntax_error("ASTNewTypeNode error");
    for (auto i : ctx->newArrayExpr()) node->size.push_back(any_cast<ASTExprNode*>(visit(i)));
    node->dim = ctx->newArrayExpr().size() + ctx->newArrayEmpty().size();
    return node;
}

std::any ASTBuilder::visitNewClass(MxParser::NewClassContext *ctx)
{
    auto node = new ASTNewTypeNode;
    node->name = ctx->identifier()->Identifier()->getText();
    node->dim = 0;
    return node;
//    return static_cast<ASTNewTypeNode*>(node);
}

std::any ASTBuilder::visitNewArrayExpr(MxParser::NewArrayExprContext *ctx)
{
    return visit(ctx->expression());
}

std::any ASTBuilder::visitNewExpr(MxParser::NewExprContext *ctx)
{
    return visit(ctx->newExpression());
}

std::any ASTBuilder::visitMemberExpr(MxParser::MemberExprContext *ctx)
{
    auto node = new ASTMemberExprNode;
    node->object = any_cast<ASTExprNode*>(visit(ctx->expression()));
    node->member = ctx->identifier()->Identifier()->getText();
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitBinaryExpr(MxParser::BinaryExprContext *ctx)
{
    auto node = new ASTBinaryExprNode;
    node->op = ctx->op->getText();
    node->lhs = any_cast<ASTExprNode*>(visit(ctx->lhs));
    node->rhs = any_cast<ASTExprNode*>(visit(ctx->rhs));
    return static_cast<ASTExprNode*>(node);
}
//lhs=expression op=('++' | '--')                                  # PostfixOpExpr
std::any ASTBuilder::visitPostfixOpExpr(MxParser::PostfixOpExprContext *ctx)
{
    auto node = new ASTSingleExprNode;
    node->right = true;
    node->op = ctx->op->getText();
    node->expr = any_cast<ASTExprNode*>(visit(ctx->lhs));
    return static_cast<ASTExprNode*>(node);
}
//<assoc=right>  op=('++' | '--') rhs=expression                   # PrefixOpExpr
std::any ASTBuilder::visitPrefixOpExpr(MxParser::PrefixOpExprContext *ctx)
{
    auto node = new ASTSingleExprNode;
    node->right = false;
    node->op = ctx->op->getText();
    node->expr = any_cast<ASTExprNode*>(visit(ctx->rhs));
    return static_cast<ASTExprNode*>(node);
}
//    | <assoc=right>  op=('!' | '~' | '+' | '-')                rhs=expression # UnaryExpr
std::any ASTBuilder::visitUnaryExpr(MxParser::UnaryExprContext *ctx)
{
    auto node = new ASTSingleExprNode;
    node->right = false;
    node->op = ctx->op->getText();
    node->expr = any_cast<ASTExprNode*>(visit(ctx->rhs));
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitAssignExpr(MxParser::AssignExprContext *ctx)
{
    auto node = new ASTAssignExprNode;
    node->lhs = any_cast<ASTExprNode*>(visit(ctx->expression()[0]));
    node->rhs = any_cast<ASTExprNode*>(visit(ctx->expression()[1]));
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitArrayExpr(MxParser::ArrayExprContext *ctx)
{
    auto node = new ASTArrayExprNode;
    node->array = any_cast<ASTExprNode*>(visit(ctx->expression()[0]));
    node->index = any_cast<ASTExprNode*>(visit(ctx->expression()[1]));
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitIdentifierExpr(MxParser::IdentifierExprContext *ctx)
{
    auto node = new ASTIdExprNode;
    node->name = ctx->getText();
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitLiteralExpr(MxParser::LiteralExprContext *ctx)
{
    return visit(ctx->literalExpression());
}

std::any ASTBuilder::visitFunctionCall(MxParser::FunctionCallContext *ctx)
{
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
    return visit(ctx->expression());
}

std::any ASTBuilder::visitTernaryExpr(MxParser::TernaryExprContext *ctx)
{
    auto node = new ASTTernaryExprNode;
    node->cond = any_cast<ASTExprNode*>(visit(ctx->expression()[0]));
    node->True = any_cast<ASTExprNode*>(visit(ctx->expression()[1]));
    node->False = any_cast<ASTExprNode*>(visit(ctx->expression()[2]));
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitNewExpression(MxParser::NewExpressionContext *ctx)
{
    auto node = new ASTNewExprNode;
    node->newType = any_cast<ASTNewTypeNode*>(visit(ctx->newTypename()));
    return static_cast<ASTExprNode*>(node);
}















