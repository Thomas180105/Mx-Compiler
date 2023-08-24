#ifndef MXCOMPILER_2023_IRBASEVISITOR_H
#define MXCOMPILER_2023_IRBASEVISITOR_H

class IRNode{
public:
    IRNode() = default;
    virtual ~IRNode() = default;
    virtual void accept(class IRBaseVisitor* visitor) = 0;
    virtual std::string to_string() = 0;
    virtual void print() = 0;
};

class IRProgramNode;//
class IRFunctionNode;//
class IRGlobalVarStmtNode;//
class IRSuiteNode;//
class IRTypeNode;//
class IRVarNode;//
class IRGlobalVarNode;//
class IRLiteralNode;
class IRStringNode;
class IRCallStmtNode;
class IRAllocaStmtNode;//
class IRStoreStmtNode;//
class IRBrStmtNode;//
class IRBrCondStmtNode;//
class IRRetStmtNode;//
class IRLoadStmtNode;//
class IRTruncateStmtNode;//
class IRPhiStmtNode;//
class IRIcmpStmtNode;//
class IRZeroExtendStmtNode;//
class IRBinaryStmtNode;//
class IRGetElementPtrStmtNode;//

class IRBaseVisitor{
public:
    virtual void visit(IRNode* node) {node->accept(this);}
    virtual void visitProgram(IRProgramNode* node) {}
    virtual void visitFunction(IRFunctionNode* node) {}
    virtual void visitGlobalVarStmt(IRGlobalVarStmtNode* node) {}
    virtual void visitSuite(IRSuiteNode* node) {}
    virtual void visitType(IRTypeNode* node) {}
    virtual void visitVar(IRVarNode* node) {}
    virtual void visitGlobalVar(IRGlobalVarNode* node) {}
    virtual void visitLiteral(IRLiteralNode* node) {}
    virtual void visitString(IRStringNode* node) {}
    virtual void visitCallStmt(IRCallStmtNode* node) {}
    virtual void visitAllocaStmt(IRAllocaStmtNode* node) {}
    virtual void visitStoreStmt(IRStoreStmtNode* node) {}
    virtual void visitBrStmt(IRBrStmtNode* node) {}
    virtual void visitBrCondStmt(IRBrCondStmtNode* node) {}
    virtual void visitRetStmt(IRRetStmtNode* node) {}
    virtual void visitLoadStmt(IRLoadStmtNode* node) {}
    virtual void visitTruncateStmt(IRTruncateStmtNode* node) {}
    virtual void visitPhiStmt(IRPhiStmtNode* node) {}
    virtual void visitIcmpStmt(IRIcmpStmtNode* node) {}
    virtual void visitZeroExtendStmt(IRZeroExtendStmtNode* node) {}
    virtual void visitBinaryStmt(IRBinaryStmtNode* node) {}
    virtual void visitGetElementPtrStmt(IRGetElementPtrStmtNode* node) {}
};


#endif //MXCOMPILER_2023_IRBASEVISITOR_H
