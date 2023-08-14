#ifndef MXCOMPILER_2023_ASTBASEVISITOR_H
#define MXCOMPILER_2023_ASTBASEVISITOR_H
#include "Scope.h"
class ASTBaseVisitor;

class ASTNode {
public:
    ASTNode() = default;
    virtual ~ASTNode() = default;
    virtual std::string NodeType() { return "ASTNode"; }
    virtual void accept(ASTBaseVisitor *visitor) {}
    virtual void print() {};
};

class AST {
public:
    ASTNode *root = nullptr;
    AST() = default;
    ~AST() { delete root; }
};

class ASTProgramNode;
class ASTClassNode;
class ASTConstructNode;
class ASTFunctionNode;
class ASTTypeNode;
class ASTSuiteNode;
class ASTStmtNode;
class ASTExprStmtNode;
class ASTExprNode;
class ASTFuncExprNode;
class ASTArrayExprNode;
class ASTMemberExprNode;
class ASTSingleExprNode;
class ASTNewExprNode;
class ASTBinaryExprNode;
class ASTTernaryExprNode;
class ASTAssignExprNode;
class ASTLiterExprNode;
class ASTIdExprNode;
class ASTBranchStmtNode;
class ASTLoopStmtNode;
class ASTWhileStmtNode;
class ASTForStmtNode;
class ASTFlowStmtNode;
class ASTContinueStmtNode;
class ASTBreakStmtNode;
class ASTReturnStmtNode;
class ASTVarStmtNode;
class ASTNewTypeNode;


class ASTBaseVisitor {
public:
    ASTBaseVisitor() = default;
    virtual ~ASTBaseVisitor() = default;
    virtual void visit(ASTNode *node) { node->accept(this); }
    virtual void visitProgramNode(ASTProgramNode *node) {}
    virtual void visitClassNode(ASTClassNode *node) {}
    virtual void visitFunctionNode(ASTFunctionNode *node) {}
    virtual void visitTypeNode(ASTTypeNode *node) {}
    virtual void visitSuiteNode(ASTSuiteNode *node) {}
    virtual void visitStmtNode(ASTStmtNode *node) {}
    virtual void visitExprStmtNode(ASTExprStmtNode *node) {}
    virtual void visitExprNode(ASTExprNode *node) {}
    virtual void visitFuncExprNode(ASTFuncExprNode *node) {}
    virtual void visitArrayExprNode(ASTArrayExprNode *node) {}
    virtual void visitMemberExprNode(ASTMemberExprNode *node) {}
    virtual void visitSingleExprNode(ASTSingleExprNode *node) {}
    virtual void visitNewExprNode(ASTNewExprNode *node) {}
    virtual void visitBinaryExprNode(ASTBinaryExprNode *node) {}
    virtual void visitTernaryExprNode(ASTTernaryExprNode *node) {}
    virtual void visitAssignExprNode(ASTAssignExprNode *node) {}
    virtual void visitLiterExprNode(ASTLiterExprNode *node) {}
    virtual void visitIdExprNode(ASTIdExprNode *node) {}
    virtual void visitBranchStmtNode(ASTBranchStmtNode *node) {}
    virtual void visitLoopStmtNode(ASTLoopStmtNode *node) {}
    virtual void visitWhileStmtNode(ASTWhileStmtNode *node) {}
    virtual void visitForStmtNode(ASTForStmtNode *node) {}
    virtual void visitFlowStmtNode(ASTFlowStmtNode *node) {}
    virtual void visitContinueStmtNode(ASTContinueStmtNode *node) {}
    virtual void visitBreakStmtNode(ASTBreakStmtNode *node) {}
    virtual void visitReturnStmtNode(ASTReturnStmtNode *node) {}
    virtual void visitVarStmtNode(ASTVarStmtNode *node) {}
    virtual void visitNewTypeNode(ASTNewTypeNode *node) {}
};


#endif //MXCOMPILER_2023_ASTBASEVISITOR_H
