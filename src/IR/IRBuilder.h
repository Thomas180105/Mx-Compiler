#ifndef MXCOMPILER_2023_IRBUILDER_H
#define MXCOMPILER_2023_IRBUILDER_H
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "ASTBaseVisitor.h"
#include "Type.h"
#include "IRNode.h"
#include "ASTNode.h"

using std::map;
using std::set;
using std::vector;
using std::pair;

class IRBuilder : public ASTBaseVisitor {
private:
    IRProgramNode *program;
    map<std::string, std::string> op, strOp;
    set<IRTypeNode *> valueSet;
    map<string, IRGlobalVarNode*> strMap;
    map<string, int> counter;//相当于多个int类型变量
    set<string> memberFuncSet;
    map<string, int> memberIndex;
    map<string, IRClassType*> str2clsType;
    map<ASTFunctionNode*, IRFunctionNode*> func2func;
    vector<pair<IRVarNode*, ASTExprNode*>> varToInit;
    IRClassType *currentClass = nullptr;
    IRFunctionNode* currentFunction = nullptr;
    IRSuiteNode *currentBlock = nullptr;
    IRSuiteNode *nextBlock = nullptr;
    IRSuiteNode *endBlock = nullptr;
    IRSuiteNode *returnBlock = nullptr;
    IRVarNode *returnVar = nullptr;
    map<string, IRVarNode*> varMap;
    map<ASTNode*, IRTypeNode*> ast2value;
    map<ASTMemberExprNode*, string> memberFuncMap;
    IRVarNode *mallocArray(ASTNewTypeNode *node, int index);

private:
    //tool functions
    void InitBuiltInFunc();
    void initGlobalStr();
    void InitGlobalVar();
    IRType *turnIRType(Type *type);
    IRType *turnIRType(ASTTypeNode *typeNode);
    IRTypeNode *defaultValue(IRType *type);
    void registerFunction(ASTFunctionNode *node);
    void registerClass(ASTClassNode *node);
    IRTypeNode* setVariable(IRType* type, IRTypeNode* value);
    void setCondition(IRTypeNode* cond, IRSuiteNode* trueBlock, IRSuiteNode* falseBlock);
public:
    IRBuilder()
    {
        //TODO: check if this is correct
        op["+"] = "add", op["-"] = "sub", op["*"] = "mul", op["/"] = "sdiv", op["%"] = "srem";
        op["<"] = "icmp slt", op["<="] = "icmp sle", op[">"] = "icmp sgt", op[">="] = "icmp sge", op["=="] = "icmp eq", op["!="] = "icmp ne";//add prefix "icmp" in order to arrange them more easily
        op["<<"] = "shl", op[">>"] = "ashr", op["&"] = "and", op["|"] = "or", op["^"] = "xor";
        strOp["+"] = "string.add", strOp["<"] = "string.lt", strOp["<="] = "string.le", strOp[">"] = "string.gt", strOp[">="] = "string.ge", strOp["=="] = "string.eq", strOp["!="] = "string.ne";

        program = new IRProgramNode();
    };
    ~IRBuilder()
    {
        delete program;
        for (auto v : valueSet) delete v;
    }
    IRProgramNode *root() {return program;}
    void print() {program->print();}
    void visitProgramNode(ASTProgramNode *node) override;
    void visitClassNode(ASTClassNode *node) override;
    void visitFunctionNode(ASTFunctionNode *node) override;
//    void visitTypeNode(ASTTypeNode *node) override;
    void visitSuiteNode(ASTSuiteNode *node) override;
//    void visitStmtNode(ASTStmtNode *node) override;
    void visitExprStmtNode(ASTExprStmtNode *node) override;
//    void visitExprNode(ASTExprNode *node) override;
    void visitFuncExprNode(ASTFuncExprNode *node) override;
    void visitArrayExprNode(ASTArrayExprNode *node) override;
    void visitMemberExprNode(ASTMemberExprNode *node) override;
    void visitSingleExprNode(ASTSingleExprNode *node) override;
    void visitNewExprNode(ASTNewExprNode *node) override;
    void visitBinaryExprNode(ASTBinaryExprNode *node) override;
    void visitTernaryExprNode(ASTTernaryExprNode *node) override;
    void visitAssignExprNode(ASTAssignExprNode *node) override;
    void visitLiterExprNode(ASTLiterExprNode *node) override;
    void visitIdExprNode(ASTIdExprNode *node) override;
    void visitBranchStmtNode(ASTBranchStmtNode *node) override;
//    void visitLoopStmtNode(ASTLoopStmtNode *node) override;
    void visitWhileStmtNode(ASTWhileStmtNode *node) override;
    void visitForStmtNode(ASTForStmtNode *node) override;
//    void visitFlowStmtNode(ASTFlowStmtNode *node) override;
    void visitContinueStmtNode(ASTContinueStmtNode *node) override;
    void visitBreakStmtNode(ASTBreakStmtNode *node) override;
    void visitReturnStmtNode(ASTReturnStmtNode *node) override;
    void visitVarStmtNode(ASTVarStmtNode *node) override;
//    void visitNewTypeNode(ASTNewTypeNode *node) override;
};
#endif //MXCOMPILER_2023_IRBUILDER_H
