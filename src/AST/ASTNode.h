#ifndef MXCOMPILER_2023_ASTNODE_H
#define MXCOMPILER_2023_ASTNODE_H
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include "ASTBaseVisitor.h"
#include "Scope.h"
#include "Type.h"
using std::string;
using std::vector;
using std::pair;

class ASTTypeNode: public ASTNode {
public:
    string name;
    int dim = 0; //必须要初始化！！！

    ~ASTTypeNode() override = default;
    std::string NodeType() override { return "ASTTypeNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitTypeNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTStmtNode: public ASTNode {
public:
    virtual ~ASTStmtNode() override = default;
    std::string NodeType() override { return "ASTStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitStmtNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTSuiteNode: public ASTStmtNode {
public:
    vector<ASTStmtNode*> stmts;

    ~ASTSuiteNode() override {
        for (auto s: stmts) delete s;
    }
    std::string NodeType() override { return "ASTSuiteNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitSuiteNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTExprNode: public ASTNode {
public:
    Type type;
    virtual ~ASTExprNode() override = default;
    std::string NodeType() override { return "ASTExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitExprNode(this); }
    // void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTExprStmtNode: public ASTStmtNode {
public:
    ASTExprNode *expr = nullptr;

    ~ASTExprStmtNode() override {
        delete expr;
    }
    std::string NodeType() override { return "ASTExprStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitExprStmtNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTLiterExprNode: public ASTExprNode {
public:
    string value;

    ~ASTLiterExprNode() override = default;
    std::string NodeType() override { return "ASTLiterExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitLiterExprNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTIdExprNode: public ASTExprNode {
public:
    string name;
    string uniqueName;

    ~ASTIdExprNode() override = default;
    std::string NodeType() override { return "ASTIdExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitIdExprNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTFuncExprNode: public ASTExprNode {
public:
    ASTExprNode* func = nullptr;
    vector<ASTExprNode*> args;

    ~ASTFuncExprNode() override {
        delete func;
        for (auto a: args) delete a;
    }
    std::string NodeType() override { return "ASTFuncExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitFuncExprNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTArrayExprNode: public ASTExprNode {
public:
    ASTExprNode *array = nullptr, *index = nullptr;

    ~ASTArrayExprNode() override {
        delete array;
        delete index;
    }
    std::string NodeType() override { return "ASTArrayExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitArrayExprNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTMemberExprNode: public ASTExprNode {
public:
    ASTExprNode* object = nullptr;
    std::string member;

    ~ASTMemberExprNode() override {
        delete object;
    }
    std::string NodeType() override { return "ASTMemberExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitMemberExprNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTSingleExprNode: public ASTExprNode {
public:
    ASTExprNode* expr = nullptr;
    string op;
    bool right;

    ~ASTSingleExprNode() override {
        delete expr;
    }
    std::string NodeType() override { return "ASTSingleExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitSingleExprNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTNewTypeNode: public ASTNode {
public:
    string name;
    vector<ASTExprNode*> size;
    int dim = 0;

    ~ASTNewTypeNode() {
        for (auto s:size) delete s;
    }
    std::string NodeType() override { return "ASTNewTypeNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitNewTypeNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTNewExprNode: public ASTExprNode {
public:
    ASTNewTypeNode* newType = nullptr;

    ~ASTNewExprNode() override {
        delete newType;
    }
    std::string NodeType() override { return "ASTNewExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitNewExprNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTBinaryExprNode: public ASTExprNode {
public:
    ASTExprNode *lhs = nullptr, *rhs = nullptr;
    string op;

    ~ASTBinaryExprNode() {
        delete lhs;
        delete rhs;
    }
    std::string NodeType() override { return "ASTBinaryExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitBinaryExprNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTTernaryExprNode: public ASTExprNode {
public:
    ASTExprNode *cond = nullptr;
    ASTExprNode *True = nullptr;
    ASTExprNode *False = nullptr;

    ~ASTTernaryExprNode() override{
        delete cond;
        delete True;
        delete False;
    }
    std::string NodeType() override { return "ASTTernaryExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitTernaryExprNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTAssignExprNode: public ASTExprNode {
public:
    ASTExprNode *lhs = nullptr, *rhs = nullptr;

    ~ASTAssignExprNode() {
        delete lhs;
        delete rhs;
    }
    std::string NodeType() override { return "ASTAssignExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitAssignExprNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTBranchStmtNode: public ASTStmtNode {
public:
    //though the g4 not requiring vec to store info, but use vec here in order to deal with a further stronger g4 that enable if elif elif elif else
    vector<ASTExprNode*> conditions;
    vector<ASTSuiteNode*> blocks;

    ~ASTBranchStmtNode() {
        for(auto c: conditions) delete c;
        for(auto b: blocks) delete b;
    }
    std::string NodeType() override { return "ASTBranchStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitBranchStmtNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTLoopStmtNode: public ASTStmtNode{
public:
    ~ASTLoopStmtNode() override = default;
    std::string NodeType() override { return "ASTLoopStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitLoopStmtNode(this); }
};

class ASTWhileStmtNode: public ASTLoopStmtNode {
public:
    ASTExprNode* cond = nullptr;
    ASTSuiteNode* block = nullptr;

    ~ASTWhileStmtNode() {
        delete cond;
        delete block;
    }
    std::string NodeType() override { return "ASTWhileStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitWhileStmtNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTForStmtNode: public ASTLoopStmtNode {
public:
    ASTStmtNode* init = nullptr;
    ASTExprNode *cond = nullptr, *step = nullptr;
    ASTSuiteNode* block = nullptr;

    ~ASTForStmtNode() {
        delete init;
        delete cond;
        delete step;
        delete block;
    }
    std::string NodeType() override { return "ASTForStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitForStmtNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTFlowStmtNode: public ASTStmtNode {
public:
    ~ASTFlowStmtNode() override = default;
    std::string NodeType() override { return "ASTFlowStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitFlowStmtNode(this); }
    // void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTContinueStmtNode: public ASTFlowStmtNode {
public:
    ~ASTContinueStmtNode() override = default;
    std::string NodeType() override { return "ASTContinueStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitContinueStmtNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTBreakStmtNode: public ASTFlowStmtNode {
public:
    ~ASTBreakStmtNode() override = default;
    std::string NodeType() override { return "ASTBreakStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitBreakStmtNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTReturnStmtNode: public ASTFlowStmtNode {
public:
    ASTExprNode* expr = nullptr;

    ~ASTReturnStmtNode() {
        delete expr;
    }
    std::string NodeType() override { return "ASTReturnStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitReturnStmtNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTVarStmtNode: public ASTStmtNode {
public:
    ASTTypeNode *type = nullptr;
    vector<pair<string, ASTExprNode*>> vars;
    vector<pair<string, ASTExprNode*>> uniqueNameVars;

    ~ASTVarStmtNode() override {
        delete type;
        for (auto v: vars) delete v.second;
    }
    std::string NodeType() override { return "ASTVarStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitVarStmtNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTFunctionNode: public ASTNode {
public:
    Type type;
    string name;
    // save the detail of 'functionDeclList' directly
    vector<pair<ASTTypeNode*, string>> paras;
    vector<pair<ASTTypeNode*, string>> uniqueNameParas;
    ASTSuiteNode* block = nullptr;
    ASTTypeNode* returnType = nullptr;

    ~ASTFunctionNode() override {
        for (auto p: paras) delete p.first;
        delete block;
        delete returnType;
    }
    std::string NodeType() override { return "ASTFunctionNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitFunctionNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTConstructNode: public ASTFunctionNode{
public:
    ~ASTConstructNode() override = default;
    std::string NodeType() override { return "ASTConstructNode"; }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTClassNode: public ASTNode {
public:
    string name;
    // save the detail of 'classComponents' directly
    vector<ASTVarStmtNode*> variables;
    vector<ASTConstructNode*> constructors;
    vector<ASTFunctionNode*> functions;
    Scope *scope = nullptr;
    ~ASTClassNode() override {
        for (auto v: variables) delete v;
        for (auto c: constructors) delete c;
        for (auto f: functions) delete f;
    }
    std::string NodeType() override { return "ASTClassNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitClassNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};

class ASTProgramNode: public ASTNode {
public:
    vector<ASTNode*> children; // save varDef | funcDef | classDef Node

    ASTProgramNode() = default;
    ~ASTProgramNode() override {
        for (auto child: children) delete child;
    }
    std::string NodeType() override { return "ASTProgramNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitProgramNode(this); }
    void print() override { std::cerr << "Unimplemented!\n"; }
};
#endif //MXCOMPILER_2023_ASTNODE_H
