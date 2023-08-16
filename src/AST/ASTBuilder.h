#ifndef MXCOMPILER_2023_ASTBUILDER_H
#define MXCOMPILER_2023_ASTBUILDER_H
#include "MxParserBaseVisitor.h"

//有些函数没有被重载：没有额外信息或者信息处理很简单（叶节点），直接父亲结点帮忙把事情做了
//可能需要再检查的未重载函数：visitIdentifier
class ASTBuilder : public MxParserBaseVisitor {
    virtual std::any visitProgram(MxParser::ProgramContext *ctx) override;
    virtual std::any visitFunctionDeclaration(MxParser::FunctionDeclarationContext *ctx) override;
    virtual std::any visitFunctionDeclList(MxParser::FunctionDeclListContext *ctx) override;
//    virtual std::any visitFunctionDeclPair(MxParser::FunctionDeclPairContext *ctx) override;
//    virtual std::any visitFunctionCallList(MxParser::FunctionCallListContext *ctx) override;
    virtual std::any visitClassDeclaration(MxParser::ClassDeclarationContext *ctx) override;
    virtual std::any visitConstructorDeclaration(MxParser::ConstructorDeclarationContext *ctx) override;
    virtual std::any visitWrapper(MxParser::WrapperContext *ctx) override;
//    virtual std::any visitStatement(MxParser::StatementContext *ctx) override;
    virtual std::any visitVariableDeclaration(MxParser::VariableDeclarationContext *ctx) override;
//    virtual std::any visitInitDeclarator(MxParser::InitDeclaratorContext *ctx) override;
    virtual std::any visitExpresionStatement(MxParser::ExpresionStatementContext *ctx) override;
    virtual std::any visitBranchStatement(MxParser::BranchStatementContext *ctx) override;
    virtual std::any visitWhileLoop(MxParser::WhileLoopContext *ctx) override;
    virtual std::any visitNormalForLoop(MxParser::NormalForLoopContext *ctx) override;
    virtual std::any visitExprForLoop(MxParser::ExprForLoopContext *ctx) override;
    virtual std::any visitReturnStmt(MxParser::ReturnStmtContext *ctx) override;
    virtual std::any visitBreakStmt(MxParser::BreakStmtContext *ctx) override;
    virtual std::any visitContinueStmt(MxParser::ContinueStmtContext *ctx) override;
//    virtual std::any visitReturnStatement(MxParser::ReturnStatementContext *ctx) override;
//    virtual std::any visitBreakStatement(MxParser::BreakStatementContext *ctx) override;
//    virtual std::any visitContinueStatement(MxParser::ContinueStatementContext *ctx) override;
    virtual std::any visitSuiteStatement(MxParser::SuiteStatementContext *ctx) override;
//    virtual std::any visitEmptyStatement(MxParser::EmptyStatementContext *ctx) override;
    virtual std::any visitArrayType(MxParser::ArrayTypeContext *ctx) override;
    virtual std::any visitBuiltInType(MxParser::BuiltInTypeContext *ctx) override;
    virtual std::any visitClassType(MxParser::ClassTypeContext *ctx) override;
    virtual std::any visitLiteralExpression(MxParser::LiteralExpressionContext *ctx) override;
    virtual std::any visitNewClassArray(MxParser::NewClassArrayContext *ctx) override;
    virtual std::any visitNewBuildInArray(MxParser::NewBuildInArrayContext *ctx) override;
    virtual std::any visitNewClass(MxParser::NewClassContext *ctx) override;
    virtual std::any visitNewArrayExpr(MxParser::NewArrayExprContext *ctx) override;
//    virtual std::any visitNewArrayEmpty(MxParser::NewArrayEmptyContext *ctx) override;
//    virtual std::any visitIdentifier(MxParser::IdentifierContext *ctx) override;
    virtual std::any visitNewExpr(MxParser::NewExprContext *ctx) override;
    virtual std::any visitMemberExpr(MxParser::MemberExprContext *ctx) override;
    virtual std::any visitBinaryExpr(MxParser::BinaryExprContext *ctx) override;
    virtual std::any visitPostfixOpExpr(MxParser::PostfixOpExprContext *ctx) override;
    virtual std::any visitUnaryExpr(MxParser::UnaryExprContext *ctx) override;
    virtual std::any visitAssignExpr(MxParser::AssignExprContext *ctx) override;
    virtual std::any visitPrefixOpExpr(MxParser::PrefixOpExprContext *ctx) override;
    virtual std::any visitArrayExpr(MxParser::ArrayExprContext *ctx) override;
    virtual std::any visitIdentifierExpr(MxParser::IdentifierExprContext *ctx) override;
    virtual std::any visitLiteralExpr(MxParser::LiteralExprContext *ctx) override;
    virtual std::any visitFunctionCall(MxParser::FunctionCallContext *ctx) override;
    virtual std::any visitParenExpr(MxParser::ParenExprContext *ctx) override;
    virtual std::any visitTernaryExpr(MxParser::TernaryExprContext *ctx) override;
    virtual std::any visitNewExpression(MxParser::NewExpressionContext *ctx) override;
};

#endif //MXCOMPILER_2023_ASTBUILDER_H
