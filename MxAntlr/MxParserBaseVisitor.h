
// Generated from MxParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MxParserVisitor.h"


/**
 * This class provides an empty implementation of MxParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MxParserBaseVisitor : public MxParserVisitor {
public:

  virtual std::any visitProgram(MxParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration(MxParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDeclaration(MxParser::FunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDeclList(MxParser::FunctionDeclListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDeclPair(MxParser::FunctionDeclPairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCallList(MxParser::FunctionCallListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassDeclaration(MxParser::ClassDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassComponents(MxParser::ClassComponentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstructorDeclaration(MxParser::ConstructorDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWrapper(MxParser::WrapperContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSuiteStatement(MxParser::SuiteStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(MxParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclaration(MxParser::VariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitDeclarator(MxParser::InitDeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpresionStatement(MxParser::ExpresionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBranchStatement(MxParser::BranchStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileLoop(MxParser::WhileLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNormalForLoop(MxParser::NormalForLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprForLoop(MxParser::ExprForLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(MxParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStmt(MxParser::BreakStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStmt(MxParser::ContinueStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(MxParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStatement(MxParser::BreakStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStatement(MxParser::ContinueStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmptyStatement(MxParser::EmptyStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalLiteral(MxParser::LogicalLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteralExpression(MxParser::LiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayType(MxParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBuiltInType(MxParser::BuiltInTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassType(MxParser::ClassTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewClassArray(MxParser::NewClassArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewBuildInArray(MxParser::NewBuildInArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewClass(MxParser::NewClassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewArrayExpr(MxParser::NewArrayExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewArrayEmpty(MxParser::NewArrayEmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier(MxParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewExpr(MxParser::NewExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryExpr(MxParser::BinaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPostfixOpExpr(MxParser::PostfixOpExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpr(MxParser::UnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignExpr(MxParser::AssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrefixOpExpr(MxParser::PrefixOpExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayExpr(MxParser::ArrayExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberExpr(MxParser::MemberExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifierExpr(MxParser::IdentifierExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteralExpr(MxParser::LiteralExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCall(MxParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenExpr(MxParser::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTernaryExpr(MxParser::TernaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewExpression(MxParser::NewExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBuiltInTypename(MxParser::BuiltInTypenameContext *ctx) override {
    return visitChildren(ctx);
  }


};

