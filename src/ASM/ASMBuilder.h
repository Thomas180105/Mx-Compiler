#ifndef MXCOMPILER_2023_ASMBUILDER_H
#define MXCOMPILER_2023_ASMBUILDER_H

#include <set>
#include <map>
#include <string>
#include <iostream>
#include "IRBaseVisitor.h"
#include "ASMNode.h"
using std::set;
using std::map;
using std::string;

class ASMBuilder : public IRBaseVisitor{
private:
    ASMBlockNode *currentBlock = nullptr;
    IRFunctionNode *currentFunction = nullptr;
    ASMProgramNode *program;
    set<ASMVarNode*> valueSet;
    map<string, int> counter;
    map<string, ASMVarNode*> varMap;

private:
    void print() { std::cout << program->to_string(); }

public:
    ASMBuilder()
    {
        program = new ASMProgramNode();
    }
    ~ASMBuilder()
    {
        delete program;
        for (auto v : valueSet) delete v;
    }
    virtual void visitProgram(IRProgramNode* node);
    virtual void visitFunction(IRFunctionNode* node);
    virtual void visitGlobalVarStmt(IRGlobalVarStmtNode* node);
    virtual void visitSuite(IRSuiteNode* node);
    virtual void visitType(IRTypeNode* node);
    virtual void visitVar(IRVarNode* node);
    virtual void visitGlobalVar(IRGlobalVarNode* node);
    virtual void visitLiteral(IRLiteralNode* node);
    virtual void visitString(IRStringNode* node);
    virtual void visitCallStmt(IRCallStmtNode* node);
    virtual void visitAllocaStmt(IRAllocaStmtNode* node);
    virtual void visitStoreStmt(IRStoreStmtNode* node);
    virtual void visitBrStmt(IRBrStmtNode* node);
    virtual void visitBrCondStmt(IRBrCondStmtNode* node);
    virtual void visitRetStmt(IRRetStmtNode* node);
    virtual void visitLoadStmt(IRLoadStmtNode* node);
    virtual void visitTruncateStmt(IRTruncateStmtNode* node);
    virtual void visitPhiStmt(IRPhiStmtNode* node);
    virtual void visitIcmpStmt(IRIcmpStmtNode* node);
    virtual void visitZeroExtendStmt(IRZeroExtendStmtNode* node);
    virtual void visitBinaryStmt(IRBinaryStmtNode* node);
    virtual void visitGetElementPtrStmt(IRGetElementPtrStmtNode* node);
};


#endif //MXCOMPILER_2023_ASMBUILDER_H
