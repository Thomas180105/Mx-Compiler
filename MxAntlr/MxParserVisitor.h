
// Generated from MxParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MxParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MxParser.
 */
class  MxParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MxParser.
   */
    virtual std::any visitProgram(MxParser::ProgramContext *context) = 0;

    virtual std::any visitDeclaration(MxParser::DeclarationContext *context) = 0;

    virtual std::any visitFunctionDeclaration(MxParser::FunctionDeclarationContext *context) = 0;

    virtual std::any visitFunctionDeclList(MxParser::FunctionDeclListContext *context) = 0;

    virtual std::any visitFunctionDeclPair(MxParser::FunctionDeclPairContext *context) = 0;

    virtual std::any visitFunctionCallList(MxParser::FunctionCallListContext *context) = 0;

    virtual std::any visitClassDeclaration(MxParser::ClassDeclarationContext *context) = 0;

    virtual std::any visitClassComponents(MxParser::ClassComponentsContext *context) = 0;

    virtual std::any visitConstructorDeclaration(MxParser::ConstructorDeclarationContext *context) = 0;

    virtual std::any visitStatement(MxParser::StatementContext *context) = 0;

    virtual std::any visitVariableDeclaration(MxParser::VariableDeclarationContext *context) = 0;

    virtual std::any visitInitDeclarator(MxParser::InitDeclaratorContext *context) = 0;

    virtual std::any visitExpresionStatement(MxParser::ExpresionStatementContext *context) = 0;

    virtual std::any visitBranchStatement(MxParser::BranchStatementContext *context) = 0;

    virtual std::any visitWhileLoop(MxParser::WhileLoopContext *context) = 0;

    virtual std::any visitNormalForLoop(MxParser::NormalForLoopContext *context) = 0;

    virtual std::any visitExprForLoop(MxParser::ExprForLoopContext *context) = 0;

    virtual std::any visitReturnStmt(MxParser::ReturnStmtContext *context) = 0;

    virtual std::any visitBreakStmt(MxParser::BreakStmtContext *context) = 0;

    virtual std::any visitContinueStmt(MxParser::ContinueStmtContext *context) = 0;

    virtual std::any visitReturnStatement(MxParser::ReturnStatementContext *context) = 0;

    virtual std::any visitBreakStatement(MxParser::BreakStatementContext *context) = 0;

    virtual std::any visitContinueStatement(MxParser::ContinueStatementContext *context) = 0;

    virtual std::any visitSuiteStatement(MxParser::SuiteStatementContext *context) = 0;

    virtual std::any visitEmptyStatement(MxParser::EmptyStatementContext *context) = 0;

    virtual std::any visitLogicalLiteral(MxParser::LogicalLiteralContext *context) = 0;

    virtual std::any visitLiteralExpression(MxParser::LiteralExpressionContext *context) = 0;

    virtual std::any visitArrayType(MxParser::ArrayTypeContext *context) = 0;

    virtual std::any visitBuiltInType(MxParser::BuiltInTypeContext *context) = 0;

    virtual std::any visitClassType(MxParser::ClassTypeContext *context) = 0;

    virtual std::any visitNewClassArray(MxParser::NewClassArrayContext *context) = 0;

    virtual std::any visitNewBuildInArray(MxParser::NewBuildInArrayContext *context) = 0;

    virtual std::any visitNewClass(MxParser::NewClassContext *context) = 0;

    virtual std::any visitNewArrayExpr(MxParser::NewArrayExprContext *context) = 0;

    virtual std::any visitNewArrayEmpty(MxParser::NewArrayEmptyContext *context) = 0;

    virtual std::any visitIdentifier(MxParser::IdentifierContext *context) = 0;

    virtual std::any visitNewExpr(MxParser::NewExprContext *context) = 0;

    virtual std::any visitBinaryExpr(MxParser::BinaryExprContext *context) = 0;

    virtual std::any visitPostfixOpExpr(MxParser::PostfixOpExprContext *context) = 0;

    virtual std::any visitUnaryExpr(MxParser::UnaryExprContext *context) = 0;

    virtual std::any visitAssignExpr(MxParser::AssignExprContext *context) = 0;

    virtual std::any visitPrefixOpExpr(MxParser::PrefixOpExprContext *context) = 0;

    virtual std::any visitArrayExpr(MxParser::ArrayExprContext *context) = 0;

    virtual std::any visitMemberExpr(MxParser::MemberExprContext *context) = 0;

    virtual std::any visitIdentifierExpr(MxParser::IdentifierExprContext *context) = 0;

    virtual std::any visitLiteralExpr(MxParser::LiteralExprContext *context) = 0;

    virtual std::any visitFunctionCall(MxParser::FunctionCallContext *context) = 0;

    virtual std::any visitParenExpr(MxParser::ParenExprContext *context) = 0;

    virtual std::any visitTernaryExpr(MxParser::TernaryExprContext *context) = 0;

    virtual std::any visitNewExpression(MxParser::NewExpressionContext *context) = 0;

    virtual std::any visitBuiltInTypename(MxParser::BuiltInTypenameContext *context) = 0;


};

