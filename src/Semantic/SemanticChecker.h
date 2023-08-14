#ifndef MXCOMPILER_2023_SEMANTICCHECKER_H
#define MXCOMPILER_2023_SEMANTICCHECKER_H
#include "ASTBaseVisitor.h"
#include "Scope.h"

class SemanticChecker : public ASTBaseVisitor{
private:
    GlobalScope *globalScope = nullptr;
    Scope *scope = nullptr;
    int depth = 0;
    ASTFunctionNode *curFunc = nullptr;
public:
    explicit SemanticChecker(GlobalScope *globalScope_) : globalScope(globalScope_), scope(globalScope_) {}
    virtual void visitProgramNode(ASTProgramNode *node) override;
    virtual void visitClassNode(ASTClassNode *node) override;
    virtual void visitFunctionNode(ASTFunctionNode *node) override;
    virtual void visitTypeNode(ASTTypeNode *node) override;
    virtual void visitSuiteNode(ASTSuiteNode *node) override;
//    virtual void visitStmtNode(ASTStmtNode *node) override;
    virtual void visitExprStmtNode(ASTExprStmtNode *node) override;
//    virtual void visitExprNode(ASTExprNode *node) override;
    virtual void visitFuncExprNode(ASTFuncExprNode *node) override;
    virtual void visitArrayExprNode(ASTArrayExprNode *node) override;
    virtual void visitMemberExprNode(ASTMemberExprNode *node) override;
    virtual void visitSingleExprNode(ASTSingleExprNode *node) override;
    virtual void visitNewExprNode(ASTNewExprNode *node) override;
    virtual void visitBinaryExprNode(ASTBinaryExprNode *node) override;
    virtual void visitTernaryExprNode(ASTTernaryExprNode *node) override;
    virtual void visitAssignExprNode(ASTAssignExprNode *node) override;
    virtual void visitLiterExprNode(ASTLiterExprNode *node) override;
    virtual void visitIdExprNode(ASTIdExprNode *node) override;
    virtual void visitBranchStmtNode(ASTBranchStmtNode *node) override;
//    virtual void visitLoopStmtNode(ASTLoopStmtNode *node) override;
    virtual void visitWhileStmtNode(ASTWhileStmtNode *node) override;
    virtual void visitForStmtNode(ASTForStmtNode *node) override;
//    virtual void visitFlowStmtNode(ASTFlowStmtNode *node) override;
    virtual void visitContinueStmtNode(ASTContinueStmtNode *node) override;
    virtual void visitBreakStmtNode(ASTBreakStmtNode *node) override;
    virtual void visitReturnStmtNode(ASTReturnStmtNode *node) override;
    virtual void visitVarStmtNode(ASTVarStmtNode *node) override;
    virtual void visitNewTypeNode(ASTNewTypeNode *node) override;
};


#endif //MXCOMPILER_2023_SEMANTICCHECKER_H
