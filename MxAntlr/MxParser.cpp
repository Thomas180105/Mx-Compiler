
// Generated from MxParser.g4 by ANTLR 4.13.0


#include "MxParserVisitor.h"

#include "MxParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MxParserStaticData final {
  MxParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MxParserStaticData(const MxParserStaticData&) = delete;
  MxParserStaticData(MxParserStaticData&&) = delete;
  MxParserStaticData& operator=(const MxParserStaticData&) = delete;
  MxParserStaticData& operator=(MxParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mxparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
MxParserStaticData *mxparserParserStaticData = nullptr;

void mxparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (mxparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(mxparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MxParserStaticData>(
    std::vector<std::string>{
      "program", "declaration", "functionDeclaration", "functionDeclList", 
      "functionDeclPair", "functionCallList", "classDeclaration", "classComponents", 
      "constructorDeclaration", "wrapper", "suiteStatement", "statement", 
      "variableDeclaration", "initDeclarator", "expresionStatement", "branchStatement", 
      "loopStatement", "controlFlowStatement", "returnStatement", "breakStatement", 
      "continueStatement", "emptyStatement", "logicalLiteral", "literalExpression", 
      "typename", "newTypename", "newArrayExpr", "newArrayEmpty", "identifier", 
      "expression", "newExpression", "builtInTypename"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'+'", "'-'", "'*'", "'/'", "'%'", "'>'", "'<'", 
      "'>='", "'<='", "'!='", "'=='", "'&&'", "'||'", "'!'", "'>>'", "'<<'", 
      "'&'", "'|'", "'^'", "'~'", "'='", "'++'", "'--'", "'.'", "'('", "')'", 
      "'['", "']'", "'{'", "'}'", "';'", "','", "'\\u003F'", "':'", "'void'", 
      "'bool'", "'int'", "'string'", "'new'", "'class'", "'null'", "'true'", 
      "'false'", "'this'", "'if'", "'else'", "'for'", "'while'", "'break'", 
      "'continue'", "'return'"
    },
    std::vector<std::string>{
      "", "Whitespace", "Newline", "BlockComment", "LineComment", "OpAdd", 
      "OPSub", "OPMul", "OpDiv", "OpMod", "Greater", "Less", "GreaterEqual", 
      "LessEqual", "NotEqual", "Equal", "LogicAnd", "LogicOr", "LogicNot", 
      "RightShift", "LeftShift", "BitAnd", "BitOr", "BitXor", "BitNegation", 
      "OpAssign", "OpIncrement", "OpDecrement", "OpMemberAccess", "OpenParen", 
      "CloseParen", "OpenBracket", "CloseBracket", "OpenBrace", "CloseBrace", 
      "SemiColon", "Comma", "QuestionMark", "Colon", "Void", "Bool", "Int", 
      "String", "New", "Class", "Null", "True", "False", "This", "If", "Else", 
      "For", "While", "Break", "Continue", "Return", "Identifier", "StringLiteral", 
      "LogicalLiteral", "IntegerLiteral"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,59,389,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,1,0,5,0,66,8,0,10,0,12,0,69,9,0,1,0,
  	1,0,1,1,1,1,1,1,3,1,76,8,1,1,2,1,2,1,2,1,2,3,2,82,8,2,1,2,1,2,1,2,1,3,
  	1,3,1,3,5,3,90,8,3,10,3,12,3,93,9,3,1,3,1,3,1,4,1,4,1,4,1,5,1,5,1,5,5,
  	5,103,8,5,10,5,12,5,106,9,5,1,5,1,5,1,6,1,6,1,6,1,6,5,6,114,8,6,10,6,
  	12,6,117,9,6,1,6,1,6,1,6,1,7,1,7,1,7,3,7,125,8,7,1,8,1,8,1,8,1,8,1,8,
  	1,9,1,9,3,9,134,8,9,1,10,1,10,5,10,138,8,10,10,10,12,10,141,9,10,1,10,
  	1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,152,8,11,1,12,1,12,1,12,
  	1,12,5,12,158,8,12,10,12,12,12,161,9,12,1,12,1,12,1,12,1,13,1,13,1,13,
  	3,13,169,8,13,1,14,3,14,172,8,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,3,15,183,8,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,
  	16,3,16,195,8,16,1,16,1,16,3,16,199,8,16,1,16,1,16,1,16,1,16,1,16,1,16,
  	1,16,3,16,208,8,16,1,16,1,16,3,16,212,8,16,1,16,1,16,1,16,3,16,217,8,
  	16,1,17,1,17,1,17,3,17,222,8,17,1,18,1,18,3,18,226,8,18,1,18,1,18,1,19,
  	1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,23,1,23,3,23,
  	244,8,23,1,24,1,24,1,24,3,24,249,8,24,1,24,1,24,1,24,5,24,254,8,24,10,
  	24,12,24,257,9,24,1,25,1,25,4,25,261,8,25,11,25,12,25,262,1,25,5,25,266,
  	8,25,10,25,12,25,269,9,25,1,25,5,25,272,8,25,10,25,12,25,275,9,25,1,25,
  	1,25,4,25,279,8,25,11,25,12,25,280,1,25,5,25,284,8,25,10,25,12,25,287,
  	9,25,1,25,5,25,290,8,25,10,25,12,25,293,9,25,1,25,3,25,296,8,25,1,26,
  	1,26,1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,29,
  	1,29,1,29,1,29,1,29,1,29,1,29,1,29,3,29,320,8,29,3,29,322,8,29,1,29,1,
  	29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,
  	29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,
  	29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,3,29,363,8,29,1,29,1,
  	29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,5,29,376,8,29,10,29,12,
  	29,379,9,29,1,30,1,30,1,30,1,30,3,30,385,8,30,1,31,1,31,1,31,0,2,48,58,
  	32,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,
  	48,50,52,54,56,58,60,62,0,8,1,0,46,47,1,0,26,27,3,0,5,6,18,18,24,24,1,
  	0,7,9,1,0,5,6,1,0,19,20,1,0,10,15,1,0,39,42,422,0,67,1,0,0,0,2,75,1,0,
  	0,0,4,77,1,0,0,0,6,91,1,0,0,0,8,96,1,0,0,0,10,104,1,0,0,0,12,109,1,0,
  	0,0,14,124,1,0,0,0,16,126,1,0,0,0,18,133,1,0,0,0,20,135,1,0,0,0,22,151,
  	1,0,0,0,24,153,1,0,0,0,26,165,1,0,0,0,28,171,1,0,0,0,30,175,1,0,0,0,32,
  	216,1,0,0,0,34,221,1,0,0,0,36,223,1,0,0,0,38,229,1,0,0,0,40,232,1,0,0,
  	0,42,235,1,0,0,0,44,237,1,0,0,0,46,243,1,0,0,0,48,248,1,0,0,0,50,295,
  	1,0,0,0,52,297,1,0,0,0,54,301,1,0,0,0,56,304,1,0,0,0,58,321,1,0,0,0,60,
  	380,1,0,0,0,62,386,1,0,0,0,64,66,3,2,1,0,65,64,1,0,0,0,66,69,1,0,0,0,
  	67,65,1,0,0,0,67,68,1,0,0,0,68,70,1,0,0,0,69,67,1,0,0,0,70,71,5,0,0,1,
  	71,1,1,0,0,0,72,76,3,24,12,0,73,76,3,4,2,0,74,76,3,12,6,0,75,72,1,0,0,
  	0,75,73,1,0,0,0,75,74,1,0,0,0,76,3,1,0,0,0,77,78,3,48,24,0,78,79,3,56,
  	28,0,79,81,5,29,0,0,80,82,3,6,3,0,81,80,1,0,0,0,81,82,1,0,0,0,82,83,1,
  	0,0,0,83,84,5,30,0,0,84,85,3,20,10,0,85,5,1,0,0,0,86,87,3,8,4,0,87,88,
  	5,36,0,0,88,90,1,0,0,0,89,86,1,0,0,0,90,93,1,0,0,0,91,89,1,0,0,0,91,92,
  	1,0,0,0,92,94,1,0,0,0,93,91,1,0,0,0,94,95,3,8,4,0,95,7,1,0,0,0,96,97,
  	3,48,24,0,97,98,3,56,28,0,98,9,1,0,0,0,99,100,3,58,29,0,100,101,5,36,
  	0,0,101,103,1,0,0,0,102,99,1,0,0,0,103,106,1,0,0,0,104,102,1,0,0,0,104,
  	105,1,0,0,0,105,107,1,0,0,0,106,104,1,0,0,0,107,108,3,58,29,0,108,11,
  	1,0,0,0,109,110,5,44,0,0,110,111,3,56,28,0,111,115,5,33,0,0,112,114,3,
  	14,7,0,113,112,1,0,0,0,114,117,1,0,0,0,115,113,1,0,0,0,115,116,1,0,0,
  	0,116,118,1,0,0,0,117,115,1,0,0,0,118,119,5,34,0,0,119,120,5,35,0,0,120,
  	13,1,0,0,0,121,125,3,24,12,0,122,125,3,4,2,0,123,125,3,16,8,0,124,121,
  	1,0,0,0,124,122,1,0,0,0,124,123,1,0,0,0,125,15,1,0,0,0,126,127,3,56,28,
  	0,127,128,5,29,0,0,128,129,5,30,0,0,129,130,3,20,10,0,130,17,1,0,0,0,
  	131,134,3,20,10,0,132,134,3,22,11,0,133,131,1,0,0,0,133,132,1,0,0,0,134,
  	19,1,0,0,0,135,139,5,33,0,0,136,138,3,22,11,0,137,136,1,0,0,0,138,141,
  	1,0,0,0,139,137,1,0,0,0,139,140,1,0,0,0,140,142,1,0,0,0,141,139,1,0,0,
  	0,142,143,5,34,0,0,143,21,1,0,0,0,144,152,3,24,12,0,145,152,3,28,14,0,
  	146,152,3,30,15,0,147,152,3,32,16,0,148,152,3,34,17,0,149,152,3,20,10,
  	0,150,152,3,42,21,0,151,144,1,0,0,0,151,145,1,0,0,0,151,146,1,0,0,0,151,
  	147,1,0,0,0,151,148,1,0,0,0,151,149,1,0,0,0,151,150,1,0,0,0,152,23,1,
  	0,0,0,153,159,3,48,24,0,154,155,3,26,13,0,155,156,5,36,0,0,156,158,1,
  	0,0,0,157,154,1,0,0,0,158,161,1,0,0,0,159,157,1,0,0,0,159,160,1,0,0,0,
  	160,162,1,0,0,0,161,159,1,0,0,0,162,163,3,26,13,0,163,164,5,35,0,0,164,
  	25,1,0,0,0,165,168,3,56,28,0,166,167,5,25,0,0,167,169,3,58,29,0,168,166,
  	1,0,0,0,168,169,1,0,0,0,169,27,1,0,0,0,170,172,3,58,29,0,171,170,1,0,
  	0,0,171,172,1,0,0,0,172,173,1,0,0,0,173,174,5,35,0,0,174,29,1,0,0,0,175,
  	176,5,49,0,0,176,177,5,29,0,0,177,178,3,58,29,0,178,179,5,30,0,0,179,
  	182,3,18,9,0,180,181,5,50,0,0,181,183,3,18,9,0,182,180,1,0,0,0,182,183,
  	1,0,0,0,183,31,1,0,0,0,184,185,5,52,0,0,185,186,5,29,0,0,186,187,3,58,
  	29,0,187,188,5,30,0,0,188,189,3,18,9,0,189,217,1,0,0,0,190,191,5,51,0,
  	0,191,192,5,29,0,0,192,194,3,24,12,0,193,195,3,58,29,0,194,193,1,0,0,
  	0,194,195,1,0,0,0,195,196,1,0,0,0,196,198,5,35,0,0,197,199,3,58,29,0,
  	198,197,1,0,0,0,198,199,1,0,0,0,199,200,1,0,0,0,200,201,5,30,0,0,201,
  	202,3,18,9,0,202,217,1,0,0,0,203,204,5,51,0,0,204,205,5,29,0,0,205,207,
  	3,28,14,0,206,208,3,58,29,0,207,206,1,0,0,0,207,208,1,0,0,0,208,209,1,
  	0,0,0,209,211,5,35,0,0,210,212,3,58,29,0,211,210,1,0,0,0,211,212,1,0,
  	0,0,212,213,1,0,0,0,213,214,5,30,0,0,214,215,3,18,9,0,215,217,1,0,0,0,
  	216,184,1,0,0,0,216,190,1,0,0,0,216,203,1,0,0,0,217,33,1,0,0,0,218,222,
  	3,36,18,0,219,222,3,38,19,0,220,222,3,40,20,0,221,218,1,0,0,0,221,219,
  	1,0,0,0,221,220,1,0,0,0,222,35,1,0,0,0,223,225,5,55,0,0,224,226,3,58,
  	29,0,225,224,1,0,0,0,225,226,1,0,0,0,226,227,1,0,0,0,227,228,5,35,0,0,
  	228,37,1,0,0,0,229,230,5,53,0,0,230,231,5,35,0,0,231,39,1,0,0,0,232,233,
  	5,54,0,0,233,234,5,35,0,0,234,41,1,0,0,0,235,236,5,35,0,0,236,43,1,0,
  	0,0,237,238,7,0,0,0,238,45,1,0,0,0,239,244,5,57,0,0,240,244,3,44,22,0,
  	241,244,5,59,0,0,242,244,5,45,0,0,243,239,1,0,0,0,243,240,1,0,0,0,243,
  	241,1,0,0,0,243,242,1,0,0,0,244,47,1,0,0,0,245,246,6,24,-1,0,246,249,
  	3,62,31,0,247,249,3,56,28,0,248,245,1,0,0,0,248,247,1,0,0,0,249,255,1,
  	0,0,0,250,251,10,1,0,0,251,252,5,31,0,0,252,254,5,32,0,0,253,250,1,0,
  	0,0,254,257,1,0,0,0,255,253,1,0,0,0,255,256,1,0,0,0,256,49,1,0,0,0,257,
  	255,1,0,0,0,258,260,3,56,28,0,259,261,3,52,26,0,260,259,1,0,0,0,261,262,
  	1,0,0,0,262,260,1,0,0,0,262,263,1,0,0,0,263,267,1,0,0,0,264,266,3,54,
  	27,0,265,264,1,0,0,0,266,269,1,0,0,0,267,265,1,0,0,0,267,268,1,0,0,0,
  	268,273,1,0,0,0,269,267,1,0,0,0,270,272,3,52,26,0,271,270,1,0,0,0,272,
  	275,1,0,0,0,273,271,1,0,0,0,273,274,1,0,0,0,274,296,1,0,0,0,275,273,1,
  	0,0,0,276,278,3,62,31,0,277,279,3,52,26,0,278,277,1,0,0,0,279,280,1,0,
  	0,0,280,278,1,0,0,0,280,281,1,0,0,0,281,285,1,0,0,0,282,284,3,54,27,0,
  	283,282,1,0,0,0,284,287,1,0,0,0,285,283,1,0,0,0,285,286,1,0,0,0,286,291,
  	1,0,0,0,287,285,1,0,0,0,288,290,3,52,26,0,289,288,1,0,0,0,290,293,1,0,
  	0,0,291,289,1,0,0,0,291,292,1,0,0,0,292,296,1,0,0,0,293,291,1,0,0,0,294,
  	296,3,56,28,0,295,258,1,0,0,0,295,276,1,0,0,0,295,294,1,0,0,0,296,51,
  	1,0,0,0,297,298,5,31,0,0,298,299,3,58,29,0,299,300,5,32,0,0,300,53,1,
  	0,0,0,301,302,5,31,0,0,302,303,5,32,0,0,303,55,1,0,0,0,304,305,5,56,0,
  	0,305,57,1,0,0,0,306,307,6,29,-1,0,307,308,5,29,0,0,308,309,3,58,29,0,
  	309,310,5,30,0,0,310,322,1,0,0,0,311,322,3,60,30,0,312,313,7,1,0,0,313,
  	322,3,58,29,15,314,315,7,2,0,0,315,322,3,58,29,14,316,322,3,46,23,0,317,
  	320,3,56,28,0,318,320,5,48,0,0,319,317,1,0,0,0,319,318,1,0,0,0,320,322,
  	1,0,0,0,321,306,1,0,0,0,321,311,1,0,0,0,321,312,1,0,0,0,321,314,1,0,0,
  	0,321,316,1,0,0,0,321,319,1,0,0,0,322,377,1,0,0,0,323,324,10,13,0,0,324,
  	325,7,3,0,0,325,376,3,58,29,14,326,327,10,12,0,0,327,328,7,4,0,0,328,
  	376,3,58,29,13,329,330,10,11,0,0,330,331,7,5,0,0,331,376,3,58,29,12,332,
  	333,10,10,0,0,333,334,7,6,0,0,334,376,3,58,29,11,335,336,10,9,0,0,336,
  	337,5,21,0,0,337,376,3,58,29,10,338,339,10,8,0,0,339,340,5,23,0,0,340,
  	376,3,58,29,9,341,342,10,7,0,0,342,343,5,22,0,0,343,376,3,58,29,8,344,
  	345,10,6,0,0,345,346,5,16,0,0,346,376,3,58,29,7,347,348,10,5,0,0,348,
  	349,5,17,0,0,349,376,3,58,29,6,350,351,10,4,0,0,351,352,5,37,0,0,352,
  	353,3,58,29,0,353,354,5,38,0,0,354,355,3,58,29,4,355,376,1,0,0,0,356,
  	357,10,3,0,0,357,358,5,25,0,0,358,376,3,58,29,3,359,360,10,20,0,0,360,
  	362,5,29,0,0,361,363,3,10,5,0,362,361,1,0,0,0,362,363,1,0,0,0,363,364,
  	1,0,0,0,364,376,5,30,0,0,365,366,10,19,0,0,366,367,5,28,0,0,367,376,3,
  	56,28,0,368,369,10,18,0,0,369,370,5,31,0,0,370,371,3,58,29,0,371,372,
  	5,32,0,0,372,376,1,0,0,0,373,374,10,16,0,0,374,376,7,1,0,0,375,323,1,
  	0,0,0,375,326,1,0,0,0,375,329,1,0,0,0,375,332,1,0,0,0,375,335,1,0,0,0,
  	375,338,1,0,0,0,375,341,1,0,0,0,375,344,1,0,0,0,375,347,1,0,0,0,375,350,
  	1,0,0,0,375,356,1,0,0,0,375,359,1,0,0,0,375,365,1,0,0,0,375,368,1,0,0,
  	0,375,373,1,0,0,0,376,379,1,0,0,0,377,375,1,0,0,0,377,378,1,0,0,0,378,
  	59,1,0,0,0,379,377,1,0,0,0,380,381,5,43,0,0,381,384,3,50,25,0,382,383,
  	5,29,0,0,383,385,5,30,0,0,384,382,1,0,0,0,384,385,1,0,0,0,385,61,1,0,
  	0,0,386,387,7,7,0,0,387,63,1,0,0,0,37,67,75,81,91,104,115,124,133,139,
  	151,159,168,171,182,194,198,207,211,216,221,225,243,248,255,262,267,273,
  	280,285,291,295,319,321,362,375,377,384
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mxparserParserStaticData = staticData.release();
}

}

MxParser::MxParser(TokenStream *input) : MxParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MxParser::MxParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MxParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *mxparserParserStaticData->atn, mxparserParserStaticData->decisionToDFA, mxparserParserStaticData->sharedContextCache, options);
}

MxParser::~MxParser() {
  delete _interpreter;
}

const atn::ATN& MxParser::getATN() const {
  return *mxparserParserStaticData->atn;
}

std::string MxParser::getGrammarFileName() const {
  return "MxParser.g4";
}

const std::vector<std::string>& MxParser::getRuleNames() const {
  return mxparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& MxParser::getVocabulary() const {
  return mxparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MxParser::getSerializedATN() const {
  return mxparserParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

MxParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ProgramContext::EOF() {
  return getToken(MxParser::EOF, 0);
}

std::vector<MxParser::DeclarationContext *> MxParser::ProgramContext::declaration() {
  return getRuleContexts<MxParser::DeclarationContext>();
}

MxParser::DeclarationContext* MxParser::ProgramContext::declaration(size_t i) {
  return getRuleContext<MxParser::DeclarationContext>(i);
}


size_t MxParser::ProgramContext::getRuleIndex() const {
  return MxParser::RuleProgram;
}


std::any MxParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ProgramContext* MxParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, MxParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 72083432561180672) != 0)) {
      setState(64);
      declaration();
      setState(69);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(70);
    match(MxParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

MxParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::VariableDeclarationContext* MxParser::DeclarationContext::variableDeclaration() {
  return getRuleContext<MxParser::VariableDeclarationContext>(0);
}

MxParser::FunctionDeclarationContext* MxParser::DeclarationContext::functionDeclaration() {
  return getRuleContext<MxParser::FunctionDeclarationContext>(0);
}

MxParser::ClassDeclarationContext* MxParser::DeclarationContext::classDeclaration() {
  return getRuleContext<MxParser::ClassDeclarationContext>(0);
}


size_t MxParser::DeclarationContext::getRuleIndex() const {
  return MxParser::RuleDeclaration;
}


std::any MxParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MxParser::DeclarationContext* MxParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, MxParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(72);
      variableDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(73);
      functionDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(74);
      classDeclaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

MxParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::TypenameContext* MxParser::FunctionDeclarationContext::typename_() {
  return getRuleContext<MxParser::TypenameContext>(0);
}

MxParser::IdentifierContext* MxParser::FunctionDeclarationContext::identifier() {
  return getRuleContext<MxParser::IdentifierContext>(0);
}

tree::TerminalNode* MxParser::FunctionDeclarationContext::OpenParen() {
  return getToken(MxParser::OpenParen, 0);
}

tree::TerminalNode* MxParser::FunctionDeclarationContext::CloseParen() {
  return getToken(MxParser::CloseParen, 0);
}

MxParser::SuiteStatementContext* MxParser::FunctionDeclarationContext::suiteStatement() {
  return getRuleContext<MxParser::SuiteStatementContext>(0);
}

MxParser::FunctionDeclListContext* MxParser::FunctionDeclarationContext::functionDeclList() {
  return getRuleContext<MxParser::FunctionDeclListContext>(0);
}


size_t MxParser::FunctionDeclarationContext::getRuleIndex() const {
  return MxParser::RuleFunctionDeclaration;
}


std::any MxParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MxParser::FunctionDeclarationContext* MxParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, MxParser::RuleFunctionDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    typename_(0);
    setState(78);
    identifier();
    setState(79);
    match(MxParser::OpenParen);
    setState(81);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 72065840375136256) != 0)) {
      setState(80);
      functionDeclList();
    }
    setState(83);
    match(MxParser::CloseParen);
    setState(84);
    antlrcpp::downCast<FunctionDeclarationContext *>(_localctx)->body = suiteStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclListContext ------------------------------------------------------------------

MxParser::FunctionDeclListContext::FunctionDeclListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::FunctionDeclPairContext *> MxParser::FunctionDeclListContext::functionDeclPair() {
  return getRuleContexts<MxParser::FunctionDeclPairContext>();
}

MxParser::FunctionDeclPairContext* MxParser::FunctionDeclListContext::functionDeclPair(size_t i) {
  return getRuleContext<MxParser::FunctionDeclPairContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::FunctionDeclListContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::FunctionDeclListContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
}


size_t MxParser::FunctionDeclListContext::getRuleIndex() const {
  return MxParser::RuleFunctionDeclList;
}


std::any MxParser::FunctionDeclListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclList(this);
  else
    return visitor->visitChildren(this);
}

MxParser::FunctionDeclListContext* MxParser::functionDeclList() {
  FunctionDeclListContext *_localctx = _tracker.createInstance<FunctionDeclListContext>(_ctx, getState());
  enterRule(_localctx, 6, MxParser::RuleFunctionDeclList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(91);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(86);
        functionDeclPair();
        setState(87);
        match(MxParser::Comma); 
      }
      setState(93);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
    setState(94);
    functionDeclPair();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclPairContext ------------------------------------------------------------------

MxParser::FunctionDeclPairContext::FunctionDeclPairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::TypenameContext* MxParser::FunctionDeclPairContext::typename_() {
  return getRuleContext<MxParser::TypenameContext>(0);
}

MxParser::IdentifierContext* MxParser::FunctionDeclPairContext::identifier() {
  return getRuleContext<MxParser::IdentifierContext>(0);
}


size_t MxParser::FunctionDeclPairContext::getRuleIndex() const {
  return MxParser::RuleFunctionDeclPair;
}


std::any MxParser::FunctionDeclPairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclPair(this);
  else
    return visitor->visitChildren(this);
}

MxParser::FunctionDeclPairContext* MxParser::functionDeclPair() {
  FunctionDeclPairContext *_localctx = _tracker.createInstance<FunctionDeclPairContext>(_ctx, getState());
  enterRule(_localctx, 8, MxParser::RuleFunctionDeclPair);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    typename_(0);
    setState(97);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallListContext ------------------------------------------------------------------

MxParser::FunctionCallListContext::FunctionCallListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::ExpressionContext *> MxParser::FunctionCallListContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::FunctionCallListContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::FunctionCallListContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::FunctionCallListContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
}


size_t MxParser::FunctionCallListContext::getRuleIndex() const {
  return MxParser::RuleFunctionCallList;
}


std::any MxParser::FunctionCallListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitFunctionCallList(this);
  else
    return visitor->visitChildren(this);
}

MxParser::FunctionCallListContext* MxParser::functionCallList() {
  FunctionCallListContext *_localctx = _tracker.createInstance<FunctionCallListContext>(_ctx, getState());
  enterRule(_localctx, 10, MxParser::RuleFunctionCallList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(104);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(99);
        expression(0);
        setState(100);
        match(MxParser::Comma); 
      }
      setState(106);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(107);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDeclarationContext ------------------------------------------------------------------

MxParser::ClassDeclarationContext::ClassDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ClassDeclarationContext::Class() {
  return getToken(MxParser::Class, 0);
}

MxParser::IdentifierContext* MxParser::ClassDeclarationContext::identifier() {
  return getRuleContext<MxParser::IdentifierContext>(0);
}

tree::TerminalNode* MxParser::ClassDeclarationContext::OpenBrace() {
  return getToken(MxParser::OpenBrace, 0);
}

tree::TerminalNode* MxParser::ClassDeclarationContext::CloseBrace() {
  return getToken(MxParser::CloseBrace, 0);
}

tree::TerminalNode* MxParser::ClassDeclarationContext::SemiColon() {
  return getToken(MxParser::SemiColon, 0);
}

std::vector<MxParser::ClassComponentsContext *> MxParser::ClassDeclarationContext::classComponents() {
  return getRuleContexts<MxParser::ClassComponentsContext>();
}

MxParser::ClassComponentsContext* MxParser::ClassDeclarationContext::classComponents(size_t i) {
  return getRuleContext<MxParser::ClassComponentsContext>(i);
}


size_t MxParser::ClassDeclarationContext::getRuleIndex() const {
  return MxParser::RuleClassDeclaration;
}


std::any MxParser::ClassDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitClassDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ClassDeclarationContext* MxParser::classDeclaration() {
  ClassDeclarationContext *_localctx = _tracker.createInstance<ClassDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 12, MxParser::RuleClassDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    match(MxParser::Class);
    setState(110);
    identifier();
    setState(111);
    match(MxParser::OpenBrace);
    setState(115);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 72065840375136256) != 0)) {
      setState(112);
      classComponents();
      setState(117);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(118);
    match(MxParser::CloseBrace);
    setState(119);
    match(MxParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassComponentsContext ------------------------------------------------------------------

MxParser::ClassComponentsContext::ClassComponentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::VariableDeclarationContext* MxParser::ClassComponentsContext::variableDeclaration() {
  return getRuleContext<MxParser::VariableDeclarationContext>(0);
}

MxParser::FunctionDeclarationContext* MxParser::ClassComponentsContext::functionDeclaration() {
  return getRuleContext<MxParser::FunctionDeclarationContext>(0);
}

MxParser::ConstructorDeclarationContext* MxParser::ClassComponentsContext::constructorDeclaration() {
  return getRuleContext<MxParser::ConstructorDeclarationContext>(0);
}


size_t MxParser::ClassComponentsContext::getRuleIndex() const {
  return MxParser::RuleClassComponents;
}


std::any MxParser::ClassComponentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitClassComponents(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ClassComponentsContext* MxParser::classComponents() {
  ClassComponentsContext *_localctx = _tracker.createInstance<ClassComponentsContext>(_ctx, getState());
  enterRule(_localctx, 14, MxParser::RuleClassComponents);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(124);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(121);
      variableDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(122);
      functionDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(123);
      constructorDeclaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstructorDeclarationContext ------------------------------------------------------------------

MxParser::ConstructorDeclarationContext::ConstructorDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::IdentifierContext* MxParser::ConstructorDeclarationContext::identifier() {
  return getRuleContext<MxParser::IdentifierContext>(0);
}

tree::TerminalNode* MxParser::ConstructorDeclarationContext::OpenParen() {
  return getToken(MxParser::OpenParen, 0);
}

tree::TerminalNode* MxParser::ConstructorDeclarationContext::CloseParen() {
  return getToken(MxParser::CloseParen, 0);
}

MxParser::SuiteStatementContext* MxParser::ConstructorDeclarationContext::suiteStatement() {
  return getRuleContext<MxParser::SuiteStatementContext>(0);
}


size_t MxParser::ConstructorDeclarationContext::getRuleIndex() const {
  return MxParser::RuleConstructorDeclaration;
}


std::any MxParser::ConstructorDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitConstructorDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ConstructorDeclarationContext* MxParser::constructorDeclaration() {
  ConstructorDeclarationContext *_localctx = _tracker.createInstance<ConstructorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 16, MxParser::RuleConstructorDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    identifier();
    setState(127);
    match(MxParser::OpenParen);
    setState(128);
    match(MxParser::CloseParen);
    setState(129);
    antlrcpp::downCast<ConstructorDeclarationContext *>(_localctx)->body = suiteStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WrapperContext ------------------------------------------------------------------

MxParser::WrapperContext::WrapperContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::SuiteStatementContext* MxParser::WrapperContext::suiteStatement() {
  return getRuleContext<MxParser::SuiteStatementContext>(0);
}

MxParser::StatementContext* MxParser::WrapperContext::statement() {
  return getRuleContext<MxParser::StatementContext>(0);
}


size_t MxParser::WrapperContext::getRuleIndex() const {
  return MxParser::RuleWrapper;
}


std::any MxParser::WrapperContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitWrapper(this);
  else
    return visitor->visitChildren(this);
}

MxParser::WrapperContext* MxParser::wrapper() {
  WrapperContext *_localctx = _tracker.createInstance<WrapperContext>(_ctx, getState());
  enterRule(_localctx, 18, MxParser::RuleWrapper);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(133);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(131);
      suiteStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(132);
      statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuiteStatementContext ------------------------------------------------------------------

MxParser::SuiteStatementContext::SuiteStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::SuiteStatementContext::OpenBrace() {
  return getToken(MxParser::OpenBrace, 0);
}

tree::TerminalNode* MxParser::SuiteStatementContext::CloseBrace() {
  return getToken(MxParser::CloseBrace, 0);
}

std::vector<MxParser::StatementContext *> MxParser::SuiteStatementContext::statement() {
  return getRuleContexts<MxParser::StatementContext>();
}

MxParser::StatementContext* MxParser::SuiteStatementContext::statement(size_t i) {
  return getRuleContext<MxParser::StatementContext>(i);
}


size_t MxParser::SuiteStatementContext::getRuleIndex() const {
  return MxParser::RuleSuiteStatement;
}


std::any MxParser::SuiteStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitSuiteStatement(this);
  else
    return visitor->visitChildren(this);
}

MxParser::SuiteStatementContext* MxParser::suiteStatement() {
  SuiteStatementContext *_localctx = _tracker.createInstance<SuiteStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, MxParser::RuleSuiteStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    match(MxParser::OpenBrace);
    setState(139);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 863547130311344224) != 0)) {
      setState(136);
      statement();
      setState(141);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(142);
    match(MxParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MxParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::VariableDeclarationContext* MxParser::StatementContext::variableDeclaration() {
  return getRuleContext<MxParser::VariableDeclarationContext>(0);
}

MxParser::ExpresionStatementContext* MxParser::StatementContext::expresionStatement() {
  return getRuleContext<MxParser::ExpresionStatementContext>(0);
}

MxParser::BranchStatementContext* MxParser::StatementContext::branchStatement() {
  return getRuleContext<MxParser::BranchStatementContext>(0);
}

MxParser::LoopStatementContext* MxParser::StatementContext::loopStatement() {
  return getRuleContext<MxParser::LoopStatementContext>(0);
}

MxParser::ControlFlowStatementContext* MxParser::StatementContext::controlFlowStatement() {
  return getRuleContext<MxParser::ControlFlowStatementContext>(0);
}

MxParser::SuiteStatementContext* MxParser::StatementContext::suiteStatement() {
  return getRuleContext<MxParser::SuiteStatementContext>(0);
}

MxParser::EmptyStatementContext* MxParser::StatementContext::emptyStatement() {
  return getRuleContext<MxParser::EmptyStatementContext>(0);
}


size_t MxParser::StatementContext::getRuleIndex() const {
  return MxParser::RuleStatement;
}


std::any MxParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

MxParser::StatementContext* MxParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 22, MxParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(151);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(144);
      variableDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(145);
      expresionStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(146);
      branchStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(147);
      loopStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(148);
      controlFlowStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(149);
      suiteStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(150);
      emptyStatement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

MxParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::TypenameContext* MxParser::VariableDeclarationContext::typename_() {
  return getRuleContext<MxParser::TypenameContext>(0);
}

std::vector<MxParser::InitDeclaratorContext *> MxParser::VariableDeclarationContext::initDeclarator() {
  return getRuleContexts<MxParser::InitDeclaratorContext>();
}

MxParser::InitDeclaratorContext* MxParser::VariableDeclarationContext::initDeclarator(size_t i) {
  return getRuleContext<MxParser::InitDeclaratorContext>(i);
}

tree::TerminalNode* MxParser::VariableDeclarationContext::SemiColon() {
  return getToken(MxParser::SemiColon, 0);
}

std::vector<tree::TerminalNode *> MxParser::VariableDeclarationContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::VariableDeclarationContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
}


size_t MxParser::VariableDeclarationContext::getRuleIndex() const {
  return MxParser::RuleVariableDeclaration;
}


std::any MxParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MxParser::VariableDeclarationContext* MxParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 24, MxParser::RuleVariableDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(153);
    typename_(0);
    setState(159);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(154);
        initDeclarator();
        setState(155);
        match(MxParser::Comma); 
      }
      setState(161);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
    setState(162);
    initDeclarator();
    setState(163);
    match(MxParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitDeclaratorContext ------------------------------------------------------------------

MxParser::InitDeclaratorContext::InitDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::IdentifierContext* MxParser::InitDeclaratorContext::identifier() {
  return getRuleContext<MxParser::IdentifierContext>(0);
}

tree::TerminalNode* MxParser::InitDeclaratorContext::OpAssign() {
  return getToken(MxParser::OpAssign, 0);
}

MxParser::ExpressionContext* MxParser::InitDeclaratorContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}


size_t MxParser::InitDeclaratorContext::getRuleIndex() const {
  return MxParser::RuleInitDeclarator;
}


std::any MxParser::InitDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitInitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

MxParser::InitDeclaratorContext* MxParser::initDeclarator() {
  InitDeclaratorContext *_localctx = _tracker.createInstance<InitDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 26, MxParser::RuleInitDeclarator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    identifier();
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MxParser::OpAssign) {
      setState(166);
      match(MxParser::OpAssign);
      setState(167);
      antlrcpp::downCast<InitDeclaratorContext *>(_localctx)->initialValue = expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpresionStatementContext ------------------------------------------------------------------

MxParser::ExpresionStatementContext::ExpresionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ExpresionStatementContext::SemiColon() {
  return getToken(MxParser::SemiColon, 0);
}

MxParser::ExpressionContext* MxParser::ExpresionStatementContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}


size_t MxParser::ExpresionStatementContext::getRuleIndex() const {
  return MxParser::RuleExpresionStatement;
}


std::any MxParser::ExpresionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitExpresionStatement(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ExpresionStatementContext* MxParser::expresionStatement() {
  ExpresionStatementContext *_localctx = _tracker.createInstance<ExpresionStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, MxParser::RuleExpresionStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 793170096846798944) != 0)) {
      setState(170);
      expression(0);
    }
    setState(173);
    match(MxParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BranchStatementContext ------------------------------------------------------------------

MxParser::BranchStatementContext::BranchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::BranchStatementContext::If() {
  return getToken(MxParser::If, 0);
}

tree::TerminalNode* MxParser::BranchStatementContext::OpenParen() {
  return getToken(MxParser::OpenParen, 0);
}

tree::TerminalNode* MxParser::BranchStatementContext::CloseParen() {
  return getToken(MxParser::CloseParen, 0);
}

MxParser::ExpressionContext* MxParser::BranchStatementContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

std::vector<MxParser::WrapperContext *> MxParser::BranchStatementContext::wrapper() {
  return getRuleContexts<MxParser::WrapperContext>();
}

MxParser::WrapperContext* MxParser::BranchStatementContext::wrapper(size_t i) {
  return getRuleContext<MxParser::WrapperContext>(i);
}

tree::TerminalNode* MxParser::BranchStatementContext::Else() {
  return getToken(MxParser::Else, 0);
}


size_t MxParser::BranchStatementContext::getRuleIndex() const {
  return MxParser::RuleBranchStatement;
}


std::any MxParser::BranchStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitBranchStatement(this);
  else
    return visitor->visitChildren(this);
}

MxParser::BranchStatementContext* MxParser::branchStatement() {
  BranchStatementContext *_localctx = _tracker.createInstance<BranchStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, MxParser::RuleBranchStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(MxParser::If);
    setState(176);
    match(MxParser::OpenParen);
    setState(177);
    antlrcpp::downCast<BranchStatementContext *>(_localctx)->condition = expression(0);
    setState(178);
    match(MxParser::CloseParen);
    setState(179);
    antlrcpp::downCast<BranchStatementContext *>(_localctx)->ifWrapper = wrapper();
    setState(182);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(180);
      match(MxParser::Else);
      setState(181);
      antlrcpp::downCast<BranchStatementContext *>(_localctx)->elseWrapper = wrapper();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopStatementContext ------------------------------------------------------------------

MxParser::LoopStatementContext::LoopStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MxParser::LoopStatementContext::getRuleIndex() const {
  return MxParser::RuleLoopStatement;
}

void MxParser::LoopStatementContext::copyFrom(LoopStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NormalForLoopContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::NormalForLoopContext::For() {
  return getToken(MxParser::For, 0);
}

tree::TerminalNode* MxParser::NormalForLoopContext::OpenParen() {
  return getToken(MxParser::OpenParen, 0);
}

tree::TerminalNode* MxParser::NormalForLoopContext::SemiColon() {
  return getToken(MxParser::SemiColon, 0);
}

tree::TerminalNode* MxParser::NormalForLoopContext::CloseParen() {
  return getToken(MxParser::CloseParen, 0);
}

MxParser::VariableDeclarationContext* MxParser::NormalForLoopContext::variableDeclaration() {
  return getRuleContext<MxParser::VariableDeclarationContext>(0);
}

MxParser::WrapperContext* MxParser::NormalForLoopContext::wrapper() {
  return getRuleContext<MxParser::WrapperContext>(0);
}

std::vector<MxParser::ExpressionContext *> MxParser::NormalForLoopContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::NormalForLoopContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

MxParser::NormalForLoopContext::NormalForLoopContext(LoopStatementContext *ctx) { copyFrom(ctx); }


std::any MxParser::NormalForLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNormalForLoop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprForLoopContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::ExprForLoopContext::For() {
  return getToken(MxParser::For, 0);
}

tree::TerminalNode* MxParser::ExprForLoopContext::OpenParen() {
  return getToken(MxParser::OpenParen, 0);
}

tree::TerminalNode* MxParser::ExprForLoopContext::SemiColon() {
  return getToken(MxParser::SemiColon, 0);
}

tree::TerminalNode* MxParser::ExprForLoopContext::CloseParen() {
  return getToken(MxParser::CloseParen, 0);
}

MxParser::ExpresionStatementContext* MxParser::ExprForLoopContext::expresionStatement() {
  return getRuleContext<MxParser::ExpresionStatementContext>(0);
}

MxParser::WrapperContext* MxParser::ExprForLoopContext::wrapper() {
  return getRuleContext<MxParser::WrapperContext>(0);
}

std::vector<MxParser::ExpressionContext *> MxParser::ExprForLoopContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::ExprForLoopContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

MxParser::ExprForLoopContext::ExprForLoopContext(LoopStatementContext *ctx) { copyFrom(ctx); }


std::any MxParser::ExprForLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitExprForLoop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileLoopContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::WhileLoopContext::While() {
  return getToken(MxParser::While, 0);
}

tree::TerminalNode* MxParser::WhileLoopContext::OpenParen() {
  return getToken(MxParser::OpenParen, 0);
}

tree::TerminalNode* MxParser::WhileLoopContext::CloseParen() {
  return getToken(MxParser::CloseParen, 0);
}

MxParser::ExpressionContext* MxParser::WhileLoopContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

MxParser::WrapperContext* MxParser::WhileLoopContext::wrapper() {
  return getRuleContext<MxParser::WrapperContext>(0);
}

MxParser::WhileLoopContext::WhileLoopContext(LoopStatementContext *ctx) { copyFrom(ctx); }


std::any MxParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}
MxParser::LoopStatementContext* MxParser::loopStatement() {
  LoopStatementContext *_localctx = _tracker.createInstance<LoopStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, MxParser::RuleLoopStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(216);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MxParser::WhileLoopContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(184);
      match(MxParser::While);
      setState(185);
      match(MxParser::OpenParen);
      setState(186);
      antlrcpp::downCast<WhileLoopContext *>(_localctx)->conditon = expression(0);
      setState(187);
      match(MxParser::CloseParen);
      setState(188);
      antlrcpp::downCast<WhileLoopContext *>(_localctx)->body = wrapper();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MxParser::NormalForLoopContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(190);
      match(MxParser::For);
      setState(191);
      match(MxParser::OpenParen);
      setState(192);
      antlrcpp::downCast<NormalForLoopContext *>(_localctx)->init = variableDeclaration();
      setState(194);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 793170096846798944) != 0)) {
        setState(193);
        antlrcpp::downCast<NormalForLoopContext *>(_localctx)->condition = expression(0);
      }
      setState(196);
      match(MxParser::SemiColon);
      setState(198);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 793170096846798944) != 0)) {
        setState(197);
        antlrcpp::downCast<NormalForLoopContext *>(_localctx)->step = expression(0);
      }
      setState(200);
      match(MxParser::CloseParen);
      setState(201);
      antlrcpp::downCast<NormalForLoopContext *>(_localctx)->body = wrapper();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MxParser::ExprForLoopContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(203);
      match(MxParser::For);
      setState(204);
      match(MxParser::OpenParen);
      setState(205);
      antlrcpp::downCast<ExprForLoopContext *>(_localctx)->init = expresionStatement();
      setState(207);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 793170096846798944) != 0)) {
        setState(206);
        antlrcpp::downCast<ExprForLoopContext *>(_localctx)->condition = expression(0);
      }
      setState(209);
      match(MxParser::SemiColon);
      setState(211);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 793170096846798944) != 0)) {
        setState(210);
        antlrcpp::downCast<ExprForLoopContext *>(_localctx)->step = expression(0);
      }
      setState(213);
      match(MxParser::CloseParen);
      setState(214);
      antlrcpp::downCast<ExprForLoopContext *>(_localctx)->body = wrapper();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ControlFlowStatementContext ------------------------------------------------------------------

MxParser::ControlFlowStatementContext::ControlFlowStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MxParser::ControlFlowStatementContext::getRuleIndex() const {
  return MxParser::RuleControlFlowStatement;
}

void MxParser::ControlFlowStatementContext::copyFrom(ControlFlowStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ContinueStmtContext ------------------------------------------------------------------

MxParser::ContinueStatementContext* MxParser::ContinueStmtContext::continueStatement() {
  return getRuleContext<MxParser::ContinueStatementContext>(0);
}

MxParser::ContinueStmtContext::ContinueStmtContext(ControlFlowStatementContext *ctx) { copyFrom(ctx); }


std::any MxParser::ContinueStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitContinueStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakStmtContext ------------------------------------------------------------------

MxParser::BreakStatementContext* MxParser::BreakStmtContext::breakStatement() {
  return getRuleContext<MxParser::BreakStatementContext>(0);
}

MxParser::BreakStmtContext::BreakStmtContext(ControlFlowStatementContext *ctx) { copyFrom(ctx); }


std::any MxParser::BreakStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitBreakStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

MxParser::ReturnStatementContext* MxParser::ReturnStmtContext::returnStatement() {
  return getRuleContext<MxParser::ReturnStatementContext>(0);
}

MxParser::ReturnStmtContext::ReturnStmtContext(ControlFlowStatementContext *ctx) { copyFrom(ctx); }


std::any MxParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
MxParser::ControlFlowStatementContext* MxParser::controlFlowStatement() {
  ControlFlowStatementContext *_localctx = _tracker.createInstance<ControlFlowStatementContext>(_ctx, getState());
  enterRule(_localctx, 34, MxParser::RuleControlFlowStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(221);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::Return: {
        _localctx = _tracker.createInstance<MxParser::ReturnStmtContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(218);
        returnStatement();
        break;
      }

      case MxParser::Break: {
        _localctx = _tracker.createInstance<MxParser::BreakStmtContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(219);
        breakStatement();
        break;
      }

      case MxParser::Continue: {
        _localctx = _tracker.createInstance<MxParser::ContinueStmtContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(220);
        continueStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

MxParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ReturnStatementContext::Return() {
  return getToken(MxParser::Return, 0);
}

tree::TerminalNode* MxParser::ReturnStatementContext::SemiColon() {
  return getToken(MxParser::SemiColon, 0);
}

MxParser::ExpressionContext* MxParser::ReturnStatementContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}


size_t MxParser::ReturnStatementContext::getRuleIndex() const {
  return MxParser::RuleReturnStatement;
}


std::any MxParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ReturnStatementContext* MxParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, MxParser::RuleReturnStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    match(MxParser::Return);
    setState(225);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 793170096846798944) != 0)) {
      setState(224);
      expression(0);
    }
    setState(227);
    match(MxParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

MxParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::BreakStatementContext::Break() {
  return getToken(MxParser::Break, 0);
}

tree::TerminalNode* MxParser::BreakStatementContext::SemiColon() {
  return getToken(MxParser::SemiColon, 0);
}


size_t MxParser::BreakStatementContext::getRuleIndex() const {
  return MxParser::RuleBreakStatement;
}


std::any MxParser::BreakStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitBreakStatement(this);
  else
    return visitor->visitChildren(this);
}

MxParser::BreakStatementContext* MxParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, MxParser::RuleBreakStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    match(MxParser::Break);
    setState(230);
    match(MxParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStatementContext ------------------------------------------------------------------

MxParser::ContinueStatementContext::ContinueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ContinueStatementContext::Continue() {
  return getToken(MxParser::Continue, 0);
}

tree::TerminalNode* MxParser::ContinueStatementContext::SemiColon() {
  return getToken(MxParser::SemiColon, 0);
}


size_t MxParser::ContinueStatementContext::getRuleIndex() const {
  return MxParser::RuleContinueStatement;
}


std::any MxParser::ContinueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitContinueStatement(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ContinueStatementContext* MxParser::continueStatement() {
  ContinueStatementContext *_localctx = _tracker.createInstance<ContinueStatementContext>(_ctx, getState());
  enterRule(_localctx, 40, MxParser::RuleContinueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    match(MxParser::Continue);
    setState(233);
    match(MxParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStatementContext ------------------------------------------------------------------

MxParser::EmptyStatementContext::EmptyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::EmptyStatementContext::SemiColon() {
  return getToken(MxParser::SemiColon, 0);
}


size_t MxParser::EmptyStatementContext::getRuleIndex() const {
  return MxParser::RuleEmptyStatement;
}


std::any MxParser::EmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}

MxParser::EmptyStatementContext* MxParser::emptyStatement() {
  EmptyStatementContext *_localctx = _tracker.createInstance<EmptyStatementContext>(_ctx, getState());
  enterRule(_localctx, 42, MxParser::RuleEmptyStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    match(MxParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalLiteralContext ------------------------------------------------------------------

MxParser::LogicalLiteralContext::LogicalLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::LogicalLiteralContext::True() {
  return getToken(MxParser::True, 0);
}

tree::TerminalNode* MxParser::LogicalLiteralContext::False() {
  return getToken(MxParser::False, 0);
}


size_t MxParser::LogicalLiteralContext::getRuleIndex() const {
  return MxParser::RuleLogicalLiteral;
}


std::any MxParser::LogicalLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitLogicalLiteral(this);
  else
    return visitor->visitChildren(this);
}

MxParser::LogicalLiteralContext* MxParser::logicalLiteral() {
  LogicalLiteralContext *_localctx = _tracker.createInstance<LogicalLiteralContext>(_ctx, getState());
  enterRule(_localctx, 44, MxParser::RuleLogicalLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    _la = _input->LA(1);
    if (!(_la == MxParser::True

    || _la == MxParser::False)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralExpressionContext ------------------------------------------------------------------

MxParser::LiteralExpressionContext::LiteralExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::LiteralExpressionContext::StringLiteral() {
  return getToken(MxParser::StringLiteral, 0);
}

MxParser::LogicalLiteralContext* MxParser::LiteralExpressionContext::logicalLiteral() {
  return getRuleContext<MxParser::LogicalLiteralContext>(0);
}

tree::TerminalNode* MxParser::LiteralExpressionContext::IntegerLiteral() {
  return getToken(MxParser::IntegerLiteral, 0);
}

tree::TerminalNode* MxParser::LiteralExpressionContext::Null() {
  return getToken(MxParser::Null, 0);
}


size_t MxParser::LiteralExpressionContext::getRuleIndex() const {
  return MxParser::RuleLiteralExpression;
}


std::any MxParser::LiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}

MxParser::LiteralExpressionContext* MxParser::literalExpression() {
  LiteralExpressionContext *_localctx = _tracker.createInstance<LiteralExpressionContext>(_ctx, getState());
  enterRule(_localctx, 46, MxParser::RuleLiteralExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(243);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::StringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(239);
        match(MxParser::StringLiteral);
        break;
      }

      case MxParser::True:
      case MxParser::False: {
        enterOuterAlt(_localctx, 2);
        setState(240);
        logicalLiteral();
        break;
      }

      case MxParser::IntegerLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(241);
        match(MxParser::IntegerLiteral);
        break;
      }

      case MxParser::Null: {
        enterOuterAlt(_localctx, 4);
        setState(242);
        match(MxParser::Null);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypenameContext ------------------------------------------------------------------

MxParser::TypenameContext::TypenameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MxParser::TypenameContext::getRuleIndex() const {
  return MxParser::RuleTypename;
}

void MxParser::TypenameContext::copyFrom(TypenameContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

MxParser::TypenameContext* MxParser::ArrayTypeContext::typename_() {
  return getRuleContext<MxParser::TypenameContext>(0);
}

tree::TerminalNode* MxParser::ArrayTypeContext::OpenBracket() {
  return getToken(MxParser::OpenBracket, 0);
}

tree::TerminalNode* MxParser::ArrayTypeContext::CloseBracket() {
  return getToken(MxParser::CloseBracket, 0);
}

MxParser::ArrayTypeContext::ArrayTypeContext(TypenameContext *ctx) { copyFrom(ctx); }


std::any MxParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BuiltInTypeContext ------------------------------------------------------------------

MxParser::BuiltInTypenameContext* MxParser::BuiltInTypeContext::builtInTypename() {
  return getRuleContext<MxParser::BuiltInTypenameContext>(0);
}

MxParser::BuiltInTypeContext::BuiltInTypeContext(TypenameContext *ctx) { copyFrom(ctx); }


std::any MxParser::BuiltInTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitBuiltInType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ClassTypeContext ------------------------------------------------------------------

MxParser::IdentifierContext* MxParser::ClassTypeContext::identifier() {
  return getRuleContext<MxParser::IdentifierContext>(0);
}

MxParser::ClassTypeContext::ClassTypeContext(TypenameContext *ctx) { copyFrom(ctx); }


std::any MxParser::ClassTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitClassType(this);
  else
    return visitor->visitChildren(this);
}

MxParser::TypenameContext* MxParser::typename_() {
   return typename_(0);
}

MxParser::TypenameContext* MxParser::typename_(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MxParser::TypenameContext *_localctx = _tracker.createInstance<TypenameContext>(_ctx, parentState);
  MxParser::TypenameContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, MxParser::RuleTypename, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(248);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::Void:
      case MxParser::Bool:
      case MxParser::Int:
      case MxParser::String: {
        _localctx = _tracker.createInstance<BuiltInTypeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(246);
        builtInTypename();
        break;
      }

      case MxParser::Identifier: {
        _localctx = _tracker.createInstance<ClassTypeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(247);
        identifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(255);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ArrayTypeContext>(_tracker.createInstance<TypenameContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleTypename);
        setState(250);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(251);
        match(MxParser::OpenBracket);
        setState(252);
        match(MxParser::CloseBracket); 
      }
      setState(257);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- NewTypenameContext ------------------------------------------------------------------

MxParser::NewTypenameContext::NewTypenameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MxParser::NewTypenameContext::getRuleIndex() const {
  return MxParser::RuleNewTypename;
}

void MxParser::NewTypenameContext::copyFrom(NewTypenameContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NewBuildInArrayContext ------------------------------------------------------------------

MxParser::BuiltInTypenameContext* MxParser::NewBuildInArrayContext::builtInTypename() {
  return getRuleContext<MxParser::BuiltInTypenameContext>(0);
}

std::vector<MxParser::NewArrayExprContext *> MxParser::NewBuildInArrayContext::newArrayExpr() {
  return getRuleContexts<MxParser::NewArrayExprContext>();
}

MxParser::NewArrayExprContext* MxParser::NewBuildInArrayContext::newArrayExpr(size_t i) {
  return getRuleContext<MxParser::NewArrayExprContext>(i);
}

std::vector<MxParser::NewArrayEmptyContext *> MxParser::NewBuildInArrayContext::newArrayEmpty() {
  return getRuleContexts<MxParser::NewArrayEmptyContext>();
}

MxParser::NewArrayEmptyContext* MxParser::NewBuildInArrayContext::newArrayEmpty(size_t i) {
  return getRuleContext<MxParser::NewArrayEmptyContext>(i);
}

MxParser::NewBuildInArrayContext::NewBuildInArrayContext(NewTypenameContext *ctx) { copyFrom(ctx); }


std::any MxParser::NewBuildInArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewBuildInArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NewClassContext ------------------------------------------------------------------

MxParser::IdentifierContext* MxParser::NewClassContext::identifier() {
  return getRuleContext<MxParser::IdentifierContext>(0);
}

MxParser::NewClassContext::NewClassContext(NewTypenameContext *ctx) { copyFrom(ctx); }


std::any MxParser::NewClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewClass(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NewClassArrayContext ------------------------------------------------------------------

MxParser::IdentifierContext* MxParser::NewClassArrayContext::identifier() {
  return getRuleContext<MxParser::IdentifierContext>(0);
}

std::vector<MxParser::NewArrayExprContext *> MxParser::NewClassArrayContext::newArrayExpr() {
  return getRuleContexts<MxParser::NewArrayExprContext>();
}

MxParser::NewArrayExprContext* MxParser::NewClassArrayContext::newArrayExpr(size_t i) {
  return getRuleContext<MxParser::NewArrayExprContext>(i);
}

std::vector<MxParser::NewArrayEmptyContext *> MxParser::NewClassArrayContext::newArrayEmpty() {
  return getRuleContexts<MxParser::NewArrayEmptyContext>();
}

MxParser::NewArrayEmptyContext* MxParser::NewClassArrayContext::newArrayEmpty(size_t i) {
  return getRuleContext<MxParser::NewArrayEmptyContext>(i);
}

MxParser::NewClassArrayContext::NewClassArrayContext(NewTypenameContext *ctx) { copyFrom(ctx); }


std::any MxParser::NewClassArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewClassArray(this);
  else
    return visitor->visitChildren(this);
}
MxParser::NewTypenameContext* MxParser::newTypename() {
  NewTypenameContext *_localctx = _tracker.createInstance<NewTypenameContext>(_ctx, getState());
  enterRule(_localctx, 50, MxParser::RuleNewTypename);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(295);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MxParser::NewClassArrayContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(258);
      identifier();
      setState(260); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(259);
                newArrayExpr();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(262); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(267);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(264);
          newArrayEmpty(); 
        }
        setState(269);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
      }

      setState(273);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(270);
          antlrcpp::downCast<NewClassArrayContext *>(_localctx)->flag = newArrayExpr(); 
        }
        setState(275);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MxParser::NewBuildInArrayContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(276);
      builtInTypename();
      setState(278); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(277);
                newArrayExpr();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(280); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(285);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(282);
          newArrayEmpty(); 
        }
        setState(287);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      }

      setState(291);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(288);
          antlrcpp::downCast<NewBuildInArrayContext *>(_localctx)->flag = newArrayExpr(); 
        }
        setState(293);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      }
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MxParser::NewClassContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(294);
      identifier();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewArrayExprContext ------------------------------------------------------------------

MxParser::NewArrayExprContext::NewArrayExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::NewArrayExprContext::OpenBracket() {
  return getToken(MxParser::OpenBracket, 0);
}

MxParser::ExpressionContext* MxParser::NewArrayExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::NewArrayExprContext::CloseBracket() {
  return getToken(MxParser::CloseBracket, 0);
}


size_t MxParser::NewArrayExprContext::getRuleIndex() const {
  return MxParser::RuleNewArrayExpr;
}


std::any MxParser::NewArrayExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewArrayExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::NewArrayExprContext* MxParser::newArrayExpr() {
  NewArrayExprContext *_localctx = _tracker.createInstance<NewArrayExprContext>(_ctx, getState());
  enterRule(_localctx, 52, MxParser::RuleNewArrayExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(MxParser::OpenBracket);
    setState(298);
    expression(0);
    setState(299);
    match(MxParser::CloseBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewArrayEmptyContext ------------------------------------------------------------------

MxParser::NewArrayEmptyContext::NewArrayEmptyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::NewArrayEmptyContext::OpenBracket() {
  return getToken(MxParser::OpenBracket, 0);
}

tree::TerminalNode* MxParser::NewArrayEmptyContext::CloseBracket() {
  return getToken(MxParser::CloseBracket, 0);
}


size_t MxParser::NewArrayEmptyContext::getRuleIndex() const {
  return MxParser::RuleNewArrayEmpty;
}


std::any MxParser::NewArrayEmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewArrayEmpty(this);
  else
    return visitor->visitChildren(this);
}

MxParser::NewArrayEmptyContext* MxParser::newArrayEmpty() {
  NewArrayEmptyContext *_localctx = _tracker.createInstance<NewArrayEmptyContext>(_ctx, getState());
  enterRule(_localctx, 54, MxParser::RuleNewArrayEmpty);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
    match(MxParser::OpenBracket);
    setState(302);
    match(MxParser::CloseBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

MxParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::IdentifierContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}


size_t MxParser::IdentifierContext::getRuleIndex() const {
  return MxParser::RuleIdentifier;
}


std::any MxParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

MxParser::IdentifierContext* MxParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 56, MxParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    match(MxParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

MxParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MxParser::ExpressionContext::getRuleIndex() const {
  return MxParser::RuleExpression;
}

void MxParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NewExprContext ------------------------------------------------------------------

MxParser::NewExpressionContext* MxParser::NewExprContext::newExpression() {
  return getRuleContext<MxParser::NewExpressionContext>(0);
}

MxParser::NewExprContext::NewExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::NewExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::BinaryExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::BinaryExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::BinaryExprContext::OPMul() {
  return getToken(MxParser::OPMul, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::OpDiv() {
  return getToken(MxParser::OpDiv, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::OpMod() {
  return getToken(MxParser::OpMod, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::OpAdd() {
  return getToken(MxParser::OpAdd, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::OPSub() {
  return getToken(MxParser::OPSub, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::LeftShift() {
  return getToken(MxParser::LeftShift, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::RightShift() {
  return getToken(MxParser::RightShift, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Less() {
  return getToken(MxParser::Less, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Greater() {
  return getToken(MxParser::Greater, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::LessEqual() {
  return getToken(MxParser::LessEqual, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::GreaterEqual() {
  return getToken(MxParser::GreaterEqual, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::NotEqual() {
  return getToken(MxParser::NotEqual, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Equal() {
  return getToken(MxParser::Equal, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::BitAnd() {
  return getToken(MxParser::BitAnd, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::BitXor() {
  return getToken(MxParser::BitXor, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::BitOr() {
  return getToken(MxParser::BitOr, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::LogicAnd() {
  return getToken(MxParser::LogicAnd, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::LogicOr() {
  return getToken(MxParser::LogicOr, 0);
}

MxParser::BinaryExprContext::BinaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::BinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitBinaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PostfixOpExprContext ------------------------------------------------------------------

MxParser::ExpressionContext* MxParser::PostfixOpExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::PostfixOpExprContext::OpIncrement() {
  return getToken(MxParser::OpIncrement, 0);
}

tree::TerminalNode* MxParser::PostfixOpExprContext::OpDecrement() {
  return getToken(MxParser::OpDecrement, 0);
}

MxParser::PostfixOpExprContext::PostfixOpExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::PostfixOpExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitPostfixOpExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryExprContext ------------------------------------------------------------------

MxParser::ExpressionContext* MxParser::UnaryExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::UnaryExprContext::LogicNot() {
  return getToken(MxParser::LogicNot, 0);
}

tree::TerminalNode* MxParser::UnaryExprContext::BitNegation() {
  return getToken(MxParser::BitNegation, 0);
}

tree::TerminalNode* MxParser::UnaryExprContext::OpAdd() {
  return getToken(MxParser::OpAdd, 0);
}

tree::TerminalNode* MxParser::UnaryExprContext::OPSub() {
  return getToken(MxParser::OPSub, 0);
}

MxParser::UnaryExprContext::UnaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignExprContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::AssignExprContext::OpAssign() {
  return getToken(MxParser::OpAssign, 0);
}

std::vector<MxParser::ExpressionContext *> MxParser::AssignExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::AssignExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

MxParser::AssignExprContext::AssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrefixOpExprContext ------------------------------------------------------------------

MxParser::ExpressionContext* MxParser::PrefixOpExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::PrefixOpExprContext::OpIncrement() {
  return getToken(MxParser::OpIncrement, 0);
}

tree::TerminalNode* MxParser::PrefixOpExprContext::OpDecrement() {
  return getToken(MxParser::OpDecrement, 0);
}

MxParser::PrefixOpExprContext::PrefixOpExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::PrefixOpExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitPrefixOpExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::ArrayExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::ArrayExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::ArrayExprContext::OpenBracket() {
  return getToken(MxParser::OpenBracket, 0);
}

tree::TerminalNode* MxParser::ArrayExprContext::CloseBracket() {
  return getToken(MxParser::CloseBracket, 0);
}

MxParser::ArrayExprContext::ArrayExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::ArrayExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitArrayExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberExprContext ------------------------------------------------------------------

MxParser::ExpressionContext* MxParser::MemberExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::MemberExprContext::OpMemberAccess() {
  return getToken(MxParser::OpMemberAccess, 0);
}

MxParser::IdentifierContext* MxParser::MemberExprContext::identifier() {
  return getRuleContext<MxParser::IdentifierContext>(0);
}

MxParser::MemberExprContext::MemberExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::MemberExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitMemberExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierExprContext ------------------------------------------------------------------

MxParser::IdentifierContext* MxParser::IdentifierExprContext::identifier() {
  return getRuleContext<MxParser::IdentifierContext>(0);
}

tree::TerminalNode* MxParser::IdentifierExprContext::This() {
  return getToken(MxParser::This, 0);
}

MxParser::IdentifierExprContext::IdentifierExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::IdentifierExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitIdentifierExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralExprContext ------------------------------------------------------------------

MxParser::LiteralExpressionContext* MxParser::LiteralExprContext::literalExpression() {
  return getRuleContext<MxParser::LiteralExpressionContext>(0);
}

MxParser::LiteralExprContext::LiteralExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::LiteralExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitLiteralExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallContext ------------------------------------------------------------------

MxParser::ExpressionContext* MxParser::FunctionCallContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::FunctionCallContext::OpenParen() {
  return getToken(MxParser::OpenParen, 0);
}

tree::TerminalNode* MxParser::FunctionCallContext::CloseParen() {
  return getToken(MxParser::CloseParen, 0);
}

MxParser::FunctionCallListContext* MxParser::FunctionCallContext::functionCallList() {
  return getRuleContext<MxParser::FunctionCallListContext>(0);
}

MxParser::FunctionCallContext::FunctionCallContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::ParenExprContext::OpenParen() {
  return getToken(MxParser::OpenParen, 0);
}

MxParser::ExpressionContext* MxParser::ParenExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::ParenExprContext::CloseParen() {
  return getToken(MxParser::CloseParen, 0);
}

MxParser::ParenExprContext::ParenExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TernaryExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::TernaryExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::TernaryExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::TernaryExprContext::QuestionMark() {
  return getToken(MxParser::QuestionMark, 0);
}

tree::TerminalNode* MxParser::TernaryExprContext::Colon() {
  return getToken(MxParser::Colon, 0);
}

MxParser::TernaryExprContext::TernaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::TernaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitTernaryExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ExpressionContext* MxParser::expression() {
   return expression(0);
}

MxParser::ExpressionContext* MxParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MxParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  MxParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 58;
  enterRecursionRule(_localctx, 58, MxParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(321);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::OpenParen: {
        _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(307);
        match(MxParser::OpenParen);
        setState(308);
        expression(0);
        setState(309);
        match(MxParser::CloseParen);
        break;
      }

      case MxParser::New: {
        _localctx = _tracker.createInstance<NewExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(311);
        newExpression();
        break;
      }

      case MxParser::OpIncrement:
      case MxParser::OpDecrement: {
        _localctx = _tracker.createInstance<PrefixOpExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(312);
        antlrcpp::downCast<PrefixOpExprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == MxParser::OpIncrement

        || _la == MxParser::OpDecrement)) {
          antlrcpp::downCast<PrefixOpExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(313);
        antlrcpp::downCast<PrefixOpExprContext *>(_localctx)->rhs = expression(15);
        break;
      }

      case MxParser::OpAdd:
      case MxParser::OPSub:
      case MxParser::LogicNot:
      case MxParser::BitNegation: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(314);
        antlrcpp::downCast<UnaryExprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 17039456) != 0))) {
          antlrcpp::downCast<UnaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(315);
        antlrcpp::downCast<UnaryExprContext *>(_localctx)->rhs = expression(14);
        break;
      }

      case MxParser::Null:
      case MxParser::True:
      case MxParser::False:
      case MxParser::StringLiteral:
      case MxParser::IntegerLiteral: {
        _localctx = _tracker.createInstance<LiteralExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(316);
        literalExpression();
        break;
      }

      case MxParser::This:
      case MxParser::Identifier: {
        _localctx = _tracker.createInstance<IdentifierExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(319);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case MxParser::Identifier: {
            setState(317);
            identifier();
            break;
          }

          case MxParser::This: {
            setState(318);
            match(MxParser::This);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(377);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(375);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(323);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(324);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 896) != 0))) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(325);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(14);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(326);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(327);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MxParser::OpAdd

          || _la == MxParser::OPSub)) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(328);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(13);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(329);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(330);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MxParser::RightShift

          || _la == MxParser::LeftShift)) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(331);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(12);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(332);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(333);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 64512) != 0))) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(334);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(11);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(335);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(336);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(MxParser::BitAnd);
          setState(337);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(10);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(338);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(339);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(MxParser::BitXor);
          setState(340);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(9);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(341);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(342);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(MxParser::BitOr);
          setState(343);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(8);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(344);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(345);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(MxParser::LogicAnd);
          setState(346);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(7);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(347);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(348);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(MxParser::LogicOr);
          setState(349);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(6);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<TernaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(350);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(351);
          match(MxParser::QuestionMark);
          setState(352);
          expression(0);
          setState(353);
          match(MxParser::Colon);
          setState(354);
          expression(4);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<AssignExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(356);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(357);
          match(MxParser::OpAssign);
          setState(358);
          antlrcpp::downCast<AssignExprContext *>(_localctx)->rhs = expression(3);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<FunctionCallContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(359);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(360);
          match(MxParser::OpenParen);
          setState(362);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 793170096846798944) != 0)) {
            setState(361);
            functionCallList();
          }
          setState(364);
          match(MxParser::CloseParen);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<MemberExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(365);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(366);
          match(MxParser::OpMemberAccess);
          setState(367);
          identifier();
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<ArrayExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(368);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(369);
          match(MxParser::OpenBracket);
          setState(370);
          expression(0);
          setState(371);
          match(MxParser::CloseBracket);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<PostfixOpExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(373);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(374);
          antlrcpp::downCast<PostfixOpExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MxParser::OpIncrement

          || _la == MxParser::OpDecrement)) {
            antlrcpp::downCast<PostfixOpExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        default:
          break;
        } 
      }
      setState(379);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- NewExpressionContext ------------------------------------------------------------------

MxParser::NewExpressionContext::NewExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::NewExpressionContext::New() {
  return getToken(MxParser::New, 0);
}

MxParser::NewTypenameContext* MxParser::NewExpressionContext::newTypename() {
  return getRuleContext<MxParser::NewTypenameContext>(0);
}

tree::TerminalNode* MxParser::NewExpressionContext::OpenParen() {
  return getToken(MxParser::OpenParen, 0);
}

tree::TerminalNode* MxParser::NewExpressionContext::CloseParen() {
  return getToken(MxParser::CloseParen, 0);
}


size_t MxParser::NewExpressionContext::getRuleIndex() const {
  return MxParser::RuleNewExpression;
}


std::any MxParser::NewExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewExpression(this);
  else
    return visitor->visitChildren(this);
}

MxParser::NewExpressionContext* MxParser::newExpression() {
  NewExpressionContext *_localctx = _tracker.createInstance<NewExpressionContext>(_ctx, getState());
  enterRule(_localctx, 60, MxParser::RuleNewExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(380);
    match(MxParser::New);
    setState(381);
    newTypename();
    setState(384);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(382);
      match(MxParser::OpenParen);
      setState(383);
      match(MxParser::CloseParen);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BuiltInTypenameContext ------------------------------------------------------------------

MxParser::BuiltInTypenameContext::BuiltInTypenameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::BuiltInTypenameContext::Void() {
  return getToken(MxParser::Void, 0);
}

tree::TerminalNode* MxParser::BuiltInTypenameContext::Bool() {
  return getToken(MxParser::Bool, 0);
}

tree::TerminalNode* MxParser::BuiltInTypenameContext::Int() {
  return getToken(MxParser::Int, 0);
}

tree::TerminalNode* MxParser::BuiltInTypenameContext::String() {
  return getToken(MxParser::String, 0);
}


size_t MxParser::BuiltInTypenameContext::getRuleIndex() const {
  return MxParser::RuleBuiltInTypename;
}


std::any MxParser::BuiltInTypenameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitBuiltInTypename(this);
  else
    return visitor->visitChildren(this);
}

MxParser::BuiltInTypenameContext* MxParser::builtInTypename() {
  BuiltInTypenameContext *_localctx = _tracker.createInstance<BuiltInTypenameContext>(_ctx, getState());
  enterRule(_localctx, 62, MxParser::RuleBuiltInTypename);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(386);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8246337208320) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MxParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 24: return typenameSempred(antlrcpp::downCast<TypenameContext *>(context), predicateIndex);
    case 29: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MxParser::typenameSempred(TypenameContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MxParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 13);
    case 2: return precpred(_ctx, 12);
    case 3: return precpred(_ctx, 11);
    case 4: return precpred(_ctx, 10);
    case 5: return precpred(_ctx, 9);
    case 6: return precpred(_ctx, 8);
    case 7: return precpred(_ctx, 7);
    case 8: return precpred(_ctx, 6);
    case 9: return precpred(_ctx, 5);
    case 10: return precpred(_ctx, 4);
    case 11: return precpred(_ctx, 3);
    case 12: return precpred(_ctx, 20);
    case 13: return precpred(_ctx, 19);
    case 14: return precpred(_ctx, 18);
    case 15: return precpred(_ctx, 16);

  default:
    break;
  }
  return true;
}

void MxParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  mxparserParserInitialize();
#else
  ::antlr4::internal::call_once(mxparserParserOnceFlag, mxparserParserInitialize);
#endif
}
