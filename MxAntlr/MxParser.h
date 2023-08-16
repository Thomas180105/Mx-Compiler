
// Generated from MxParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  MxParser : public antlr4::Parser {
public:
  enum {
    Whitespace = 1, Newline = 2, BlockComment = 3, LineComment = 4, OpAdd = 5, 
    OPSub = 6, OPMul = 7, OpDiv = 8, OpMod = 9, Greater = 10, Less = 11, 
    GreaterEqual = 12, LessEqual = 13, NotEqual = 14, Equal = 15, LogicAnd = 16, 
    LogicOr = 17, LogicNot = 18, RightShift = 19, LeftShift = 20, BitAnd = 21, 
    BitOr = 22, BitXor = 23, BitNegation = 24, OpAssign = 25, OpIncrement = 26, 
    OpDecrement = 27, OpMemberAccess = 28, OpenParen = 29, CloseParen = 30, 
    OpenBracket = 31, CloseBracket = 32, OpenBrace = 33, CloseBrace = 34, 
    SemiColon = 35, Comma = 36, QuestionMark = 37, Colon = 38, Void = 39, 
    Bool = 40, Int = 41, String = 42, New = 43, Class = 44, Null = 45, True = 46, 
    False = 47, This = 48, If = 49, Else = 50, For = 51, While = 52, Break = 53, 
    Continue = 54, Return = 55, Identifier = 56, StringLiteral = 57, LogicalLiteral = 58, 
    IntegerLiteral = 59
  };

  enum {
    RuleProgram = 0, RuleDeclaration = 1, RuleFunctionDeclaration = 2, RuleFunctionDeclList = 3, 
    RuleFunctionDeclPair = 4, RuleFunctionCallList = 5, RuleClassDeclaration = 6, 
    RuleClassComponents = 7, RuleConstructorDeclaration = 8, RuleWrapper = 9, 
    RuleSuiteStatement = 10, RuleStatement = 11, RuleVariableDeclaration = 12, 
    RuleInitDeclarator = 13, RuleExpresionStatement = 14, RuleBranchStatement = 15, 
    RuleLoopStatement = 16, RuleControlFlowStatement = 17, RuleReturnStatement = 18, 
    RuleBreakStatement = 19, RuleContinueStatement = 20, RuleEmptyStatement = 21, 
    RuleLogicalLiteral = 22, RuleLiteralExpression = 23, RuleTypename = 24, 
    RuleNewTypename = 25, RuleNewArrayExpr = 26, RuleNewArrayEmpty = 27, 
    RuleIdentifier = 28, RuleExpression = 29, RuleNewExpression = 30, RuleBuiltInTypename = 31
  };

  explicit MxParser(antlr4::TokenStream *input);

  MxParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~MxParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class DeclarationContext;
  class FunctionDeclarationContext;
  class FunctionDeclListContext;
  class FunctionDeclPairContext;
  class FunctionCallListContext;
  class ClassDeclarationContext;
  class ClassComponentsContext;
  class ConstructorDeclarationContext;
  class WrapperContext;
  class SuiteStatementContext;
  class StatementContext;
  class VariableDeclarationContext;
  class InitDeclaratorContext;
  class ExpresionStatementContext;
  class BranchStatementContext;
  class LoopStatementContext;
  class ControlFlowStatementContext;
  class ReturnStatementContext;
  class BreakStatementContext;
  class ContinueStatementContext;
  class EmptyStatementContext;
  class LogicalLiteralContext;
  class LiteralExpressionContext;
  class TypenameContext;
  class NewTypenameContext;
  class NewArrayExprContext;
  class NewArrayEmptyContext;
  class IdentifierContext;
  class ExpressionContext;
  class NewExpressionContext;
  class BuiltInTypenameContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDeclarationContext *variableDeclaration();
    FunctionDeclarationContext *functionDeclaration();
    ClassDeclarationContext *classDeclaration();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  FunctionDeclarationContext : public antlr4::ParserRuleContext {
  public:
    MxParser::SuiteStatementContext *body = nullptr;
    FunctionDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypenameContext *typename_();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *OpenParen();
    antlr4::tree::TerminalNode *CloseParen();
    SuiteStatementContext *suiteStatement();
    FunctionDeclListContext *functionDeclList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDeclarationContext* functionDeclaration();

  class  FunctionDeclListContext : public antlr4::ParserRuleContext {
  public:
    FunctionDeclListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FunctionDeclPairContext *> functionDeclPair();
    FunctionDeclPairContext* functionDeclPair(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDeclListContext* functionDeclList();

  class  FunctionDeclPairContext : public antlr4::ParserRuleContext {
  public:
    FunctionDeclPairContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypenameContext *typename_();
    IdentifierContext *identifier();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDeclPairContext* functionDeclPair();

  class  FunctionCallListContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionCallListContext* functionCallList();

  class  ClassDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ClassDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Class();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *OpenBrace();
    antlr4::tree::TerminalNode *CloseBrace();
    antlr4::tree::TerminalNode *SemiColon();
    std::vector<ClassComponentsContext *> classComponents();
    ClassComponentsContext* classComponents(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassDeclarationContext* classDeclaration();

  class  ClassComponentsContext : public antlr4::ParserRuleContext {
  public:
    ClassComponentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDeclarationContext *variableDeclaration();
    FunctionDeclarationContext *functionDeclaration();
    ConstructorDeclarationContext *constructorDeclaration();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassComponentsContext* classComponents();

  class  ConstructorDeclarationContext : public antlr4::ParserRuleContext {
  public:
    MxParser::SuiteStatementContext *body = nullptr;
    ConstructorDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *OpenParen();
    antlr4::tree::TerminalNode *CloseParen();
    SuiteStatementContext *suiteStatement();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstructorDeclarationContext* constructorDeclaration();

  class  WrapperContext : public antlr4::ParserRuleContext {
  public:
    WrapperContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SuiteStatementContext *suiteStatement();
    StatementContext *statement();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WrapperContext* wrapper();

  class  SuiteStatementContext : public antlr4::ParserRuleContext {
  public:
    SuiteStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OpenBrace();
    antlr4::tree::TerminalNode *CloseBrace();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SuiteStatementContext* suiteStatement();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDeclarationContext *variableDeclaration();
    ExpresionStatementContext *expresionStatement();
    BranchStatementContext *branchStatement();
    LoopStatementContext *loopStatement();
    ControlFlowStatementContext *controlFlowStatement();
    SuiteStatementContext *suiteStatement();
    EmptyStatementContext *emptyStatement();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  VariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypenameContext *typename_();
    std::vector<InitDeclaratorContext *> initDeclarator();
    InitDeclaratorContext* initDeclarator(size_t i);
    antlr4::tree::TerminalNode *SemiColon();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclarationContext* variableDeclaration();

  class  InitDeclaratorContext : public antlr4::ParserRuleContext {
  public:
    MxParser::ExpressionContext *initialValue = nullptr;
    InitDeclaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *OpAssign();
    ExpressionContext *expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitDeclaratorContext* initDeclarator();

  class  ExpresionStatementContext : public antlr4::ParserRuleContext {
  public:
    ExpresionStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SemiColon();
    ExpressionContext *expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpresionStatementContext* expresionStatement();

  class  BranchStatementContext : public antlr4::ParserRuleContext {
  public:
    MxParser::ExpressionContext *condition = nullptr;
    MxParser::WrapperContext *ifWrapper = nullptr;
    MxParser::WrapperContext *elseWrapper = nullptr;
    BranchStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *If();
    antlr4::tree::TerminalNode *OpenParen();
    antlr4::tree::TerminalNode *CloseParen();
    ExpressionContext *expression();
    std::vector<WrapperContext *> wrapper();
    WrapperContext* wrapper(size_t i);
    antlr4::tree::TerminalNode *Else();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BranchStatementContext* branchStatement();

  class  LoopStatementContext : public antlr4::ParserRuleContext {
  public:
    LoopStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LoopStatementContext() = default;
    void copyFrom(LoopStatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NormalForLoopContext : public LoopStatementContext {
  public:
    NormalForLoopContext(LoopStatementContext *ctx);

    MxParser::VariableDeclarationContext *init = nullptr;
    MxParser::ExpressionContext *condition = nullptr;
    MxParser::ExpressionContext *step = nullptr;
    MxParser::WrapperContext *body = nullptr;
    antlr4::tree::TerminalNode *For();
    antlr4::tree::TerminalNode *OpenParen();
    antlr4::tree::TerminalNode *SemiColon();
    antlr4::tree::TerminalNode *CloseParen();
    VariableDeclarationContext *variableDeclaration();
    WrapperContext *wrapper();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprForLoopContext : public LoopStatementContext {
  public:
    ExprForLoopContext(LoopStatementContext *ctx);

    MxParser::ExpresionStatementContext *init = nullptr;
    MxParser::ExpressionContext *condition = nullptr;
    MxParser::ExpressionContext *step = nullptr;
    MxParser::WrapperContext *body = nullptr;
    antlr4::tree::TerminalNode *For();
    antlr4::tree::TerminalNode *OpenParen();
    antlr4::tree::TerminalNode *SemiColon();
    antlr4::tree::TerminalNode *CloseParen();
    ExpresionStatementContext *expresionStatement();
    WrapperContext *wrapper();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WhileLoopContext : public LoopStatementContext {
  public:
    WhileLoopContext(LoopStatementContext *ctx);

    MxParser::ExpressionContext *conditon = nullptr;
    MxParser::WrapperContext *body = nullptr;
    antlr4::tree::TerminalNode *While();
    antlr4::tree::TerminalNode *OpenParen();
    antlr4::tree::TerminalNode *CloseParen();
    ExpressionContext *expression();
    WrapperContext *wrapper();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LoopStatementContext* loopStatement();

  class  ControlFlowStatementContext : public antlr4::ParserRuleContext {
  public:
    ControlFlowStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ControlFlowStatementContext() = default;
    void copyFrom(ControlFlowStatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ContinueStmtContext : public ControlFlowStatementContext {
  public:
    ContinueStmtContext(ControlFlowStatementContext *ctx);

    ContinueStatementContext *continueStatement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BreakStmtContext : public ControlFlowStatementContext {
  public:
    BreakStmtContext(ControlFlowStatementContext *ctx);

    BreakStatementContext *breakStatement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReturnStmtContext : public ControlFlowStatementContext {
  public:
    ReturnStmtContext(ControlFlowStatementContext *ctx);

    ReturnStatementContext *returnStatement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ControlFlowStatementContext* controlFlowStatement();

  class  ReturnStatementContext : public antlr4::ParserRuleContext {
  public:
    ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Return();
    antlr4::tree::TerminalNode *SemiColon();
    ExpressionContext *expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnStatementContext* returnStatement();

  class  BreakStatementContext : public antlr4::ParserRuleContext {
  public:
    BreakStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Break();
    antlr4::tree::TerminalNode *SemiColon();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BreakStatementContext* breakStatement();

  class  ContinueStatementContext : public antlr4::ParserRuleContext {
  public:
    ContinueStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Continue();
    antlr4::tree::TerminalNode *SemiColon();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ContinueStatementContext* continueStatement();

  class  EmptyStatementContext : public antlr4::ParserRuleContext {
  public:
    EmptyStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SemiColon();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EmptyStatementContext* emptyStatement();

  class  LogicalLiteralContext : public antlr4::ParserRuleContext {
  public:
    LogicalLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *True();
    antlr4::tree::TerminalNode *False();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicalLiteralContext* logicalLiteral();

  class  LiteralExpressionContext : public antlr4::ParserRuleContext {
  public:
    LiteralExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *StringLiteral();
    LogicalLiteralContext *logicalLiteral();
    antlr4::tree::TerminalNode *IntegerLiteral();
    antlr4::tree::TerminalNode *Null();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralExpressionContext* literalExpression();

  class  TypenameContext : public antlr4::ParserRuleContext {
  public:
    TypenameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypenameContext() = default;
    void copyFrom(TypenameContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ArrayTypeContext : public TypenameContext {
  public:
    ArrayTypeContext(TypenameContext *ctx);

    TypenameContext *typename_();
    antlr4::tree::TerminalNode *OpenBracket();
    antlr4::tree::TerminalNode *CloseBracket();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BuiltInTypeContext : public TypenameContext {
  public:
    BuiltInTypeContext(TypenameContext *ctx);

    BuiltInTypenameContext *builtInTypename();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ClassTypeContext : public TypenameContext {
  public:
    ClassTypeContext(TypenameContext *ctx);

    IdentifierContext *identifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypenameContext* typename_();
  TypenameContext* typename_(int precedence);
  class  NewTypenameContext : public antlr4::ParserRuleContext {
  public:
    NewTypenameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    NewTypenameContext() = default;
    void copyFrom(NewTypenameContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NewBuildInArrayContext : public NewTypenameContext {
  public:
    NewBuildInArrayContext(NewTypenameContext *ctx);

    MxParser::NewArrayExprContext *flag = nullptr;
    BuiltInTypenameContext *builtInTypename();
    std::vector<NewArrayExprContext *> newArrayExpr();
    NewArrayExprContext* newArrayExpr(size_t i);
    std::vector<NewArrayEmptyContext *> newArrayEmpty();
    NewArrayEmptyContext* newArrayEmpty(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NewClassContext : public NewTypenameContext {
  public:
    NewClassContext(NewTypenameContext *ctx);

    IdentifierContext *identifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NewClassArrayContext : public NewTypenameContext {
  public:
    NewClassArrayContext(NewTypenameContext *ctx);

    MxParser::NewArrayExprContext *flag = nullptr;
    IdentifierContext *identifier();
    std::vector<NewArrayExprContext *> newArrayExpr();
    NewArrayExprContext* newArrayExpr(size_t i);
    std::vector<NewArrayEmptyContext *> newArrayEmpty();
    NewArrayEmptyContext* newArrayEmpty(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  NewTypenameContext* newTypename();

  class  NewArrayExprContext : public antlr4::ParserRuleContext {
  public:
    NewArrayExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OpenBracket();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CloseBracket();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewArrayExprContext* newArrayExpr();

  class  NewArrayEmptyContext : public antlr4::ParserRuleContext {
  public:
    NewArrayEmptyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OpenBracket();
    antlr4::tree::TerminalNode *CloseBracket();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewArrayEmptyContext* newArrayEmpty();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NewExprContext : public ExpressionContext {
  public:
    NewExprContext(ExpressionContext *ctx);

    NewExpressionContext *newExpression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinaryExprContext : public ExpressionContext {
  public:
    BinaryExprContext(ExpressionContext *ctx);

    MxParser::ExpressionContext *lhs = nullptr;
    antlr4::Token *op = nullptr;
    MxParser::ExpressionContext *rhs = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *OPMul();
    antlr4::tree::TerminalNode *OpDiv();
    antlr4::tree::TerminalNode *OpMod();
    antlr4::tree::TerminalNode *OpAdd();
    antlr4::tree::TerminalNode *OPSub();
    antlr4::tree::TerminalNode *LeftShift();
    antlr4::tree::TerminalNode *RightShift();
    antlr4::tree::TerminalNode *Less();
    antlr4::tree::TerminalNode *Greater();
    antlr4::tree::TerminalNode *LessEqual();
    antlr4::tree::TerminalNode *GreaterEqual();
    antlr4::tree::TerminalNode *NotEqual();
    antlr4::tree::TerminalNode *Equal();
    antlr4::tree::TerminalNode *BitAnd();
    antlr4::tree::TerminalNode *BitXor();
    antlr4::tree::TerminalNode *BitOr();
    antlr4::tree::TerminalNode *LogicAnd();
    antlr4::tree::TerminalNode *LogicOr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PostfixOpExprContext : public ExpressionContext {
  public:
    PostfixOpExprContext(ExpressionContext *ctx);

    MxParser::ExpressionContext *lhs = nullptr;
    antlr4::Token *op = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *OpIncrement();
    antlr4::tree::TerminalNode *OpDecrement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryExprContext : public ExpressionContext {
  public:
    UnaryExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    MxParser::ExpressionContext *rhs = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *LogicNot();
    antlr4::tree::TerminalNode *BitNegation();
    antlr4::tree::TerminalNode *OpAdd();
    antlr4::tree::TerminalNode *OPSub();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignExprContext : public ExpressionContext {
  public:
    AssignExprContext(ExpressionContext *ctx);

    MxParser::ExpressionContext *lhs = nullptr;
    MxParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *OpAssign();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrefixOpExprContext : public ExpressionContext {
  public:
    PrefixOpExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    MxParser::ExpressionContext *rhs = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *OpIncrement();
    antlr4::tree::TerminalNode *OpDecrement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayExprContext : public ExpressionContext {
  public:
    ArrayExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *OpenBracket();
    antlr4::tree::TerminalNode *CloseBracket();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MemberExprContext : public ExpressionContext {
  public:
    MemberExprContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *OpMemberAccess();
    IdentifierContext *identifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdentifierExprContext : public ExpressionContext {
  public:
    IdentifierExprContext(ExpressionContext *ctx);

    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *This();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LiteralExprContext : public ExpressionContext {
  public:
    LiteralExprContext(ExpressionContext *ctx);

    LiteralExpressionContext *literalExpression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionCallContext : public ExpressionContext {
  public:
    FunctionCallContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *OpenParen();
    antlr4::tree::TerminalNode *CloseParen();
    FunctionCallListContext *functionCallList();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenExprContext : public ExpressionContext {
  public:
    ParenExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *OpenParen();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CloseParen();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TernaryExprContext : public ExpressionContext {
  public:
    TernaryExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *QuestionMark();
    antlr4::tree::TerminalNode *Colon();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  NewExpressionContext : public antlr4::ParserRuleContext {
  public:
    NewExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *New();
    NewTypenameContext *newTypename();
    antlr4::tree::TerminalNode *OpenParen();
    antlr4::tree::TerminalNode *CloseParen();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewExpressionContext* newExpression();

  class  BuiltInTypenameContext : public antlr4::ParserRuleContext {
  public:
    BuiltInTypenameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Void();
    antlr4::tree::TerminalNode *Bool();
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *String();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BuiltInTypenameContext* builtInTypename();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool typenameSempred(TypenameContext *_localctx, size_t predicateIndex);
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

