
// Generated from MxLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  MxLexer : public antlr4::Lexer {
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

  explicit MxLexer(antlr4::CharStream *input);

  ~MxLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

