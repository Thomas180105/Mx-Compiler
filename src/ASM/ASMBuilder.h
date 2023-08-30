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
    RegisterManager regPool;
    ASMSuiteNode *currentBlock = nullptr;
    IRFunctionNode *currentFunction = nullptr;
    ASMProgramNode *program;
    set<ASMVarNode*> valueSet;
    map<string, int> counter;
    map<string, ASMVarNode*> varMap;
    int currentSize = 0;
    map<string, vector<ASMLaCmdNode*>> str2la;

private:
    void IRUpdReg(IRTypeNode *IRValue, Register *reg);//use IRNode to update Register
    ASMVarNode *IR2ASM(IRVarNode *IRValue);//from IRNode to ASMNode, if ASMNode not exist, create a new one
    ASMLocalVarNode* registerLocalVar(IRVarNode* var, bool flag);//With presence check, create a new ASMNode from a IRNode
    void ASMVarUpdReg(ASMVarNode *ASMValue, Register *reg);//use ASMNode(not ptr type) to update Register
    void ASMPtrUpdReg(ASMVarNode *ASMValue, Register *reg);//use ASMNode(ptr type) to update Register
    void storeVar(ASMVarNode *var, Register *reg);//store Register to ASMNode(not ptr type)
    void storePtr(ASMVarNode *var, Register *reg);//store Register to ASMNode(ptr type)
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
    void print() { std::cout << program->to_string(); }
    virtual void visitProgram(IRProgramNode* node)override;
    virtual void visitFunction(IRFunctionNode* node)override;
    virtual void visitGlobalVarStmt(IRGlobalVarStmtNode* node)override;
    virtual void visitSuite(IRSuiteNode* node)override;
    virtual void visitType(IRTypeNode* node)override;
    virtual void visitVar(IRVarNode* node)override;
    virtual void visitGlobalVar(IRGlobalVarNode* node)override;
    virtual void visitLiteral(IRLiteralNode* node)override;
    virtual void visitString(IRStringNode* node)override;
    virtual void visitCallStmt(IRCallStmtNode* node)override;
    virtual void visitAllocaStmt(IRAllocaStmtNode* node)override;
    virtual void visitStoreStmt(IRStoreStmtNode* node)override;
    virtual void visitBrStmt(IRBrStmtNode* node)override;
    virtual void visitBrCondStmt(IRBrCondStmtNode* node)override;
    virtual void visitRetStmt(IRRetStmtNode* node)override;
    virtual void visitLoadStmt(IRLoadStmtNode* node)override;
    virtual void visitTruncateStmt(IRTruncateStmtNode* node)override;
    virtual void visitPhiStmt(IRPhiStmtNode* node)override;
    virtual void visitIcmpStmt(IRIcmpStmtNode* node)override;
    virtual void visitZeroExtendStmt(IRZeroExtendStmtNode* node)override;
    virtual void visitBinaryStmt(IRBinaryStmtNode* node)override;
    virtual void visitGetElementPtrStmt(IRGetElementPtrStmtNode* node)override;
};


#endif //MXCOMPILER_2023_ASMBUILDER_H
