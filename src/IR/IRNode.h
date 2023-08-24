#ifndef MXCOMPILER_2023_IRNODE_H
#define MXCOMPILER_2023_IRNODE_H
#include <string>
#include <vector>
#include <iostream>
#include "IRType.h"
#include "IRBaseVisitor.h"
using std::string;
using std::vector;
using std::pair;

//The member functions of each node are generated with the help of GitHub Copilot.
class IRProgramNode : public IRNode {
public:
    vector<IRGlobalVarStmtNode *> globalVarStmts;
    vector<IRFunctionNode *> functions;

    ~IRProgramNode() override
    {
        for (auto &g: globalVarStmts) delete g;
        for (auto &f: functions) delete f;
    }

    void accept(IRBaseVisitor *visitor) override { visitor->visitProgram(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRFunctionNode : public IRNode {
public:
    string name;
    IRType *retType;
    vector<pair<IRType *, string>> args;
    vector<IRSuiteNode *> blocks;

    explicit IRFunctionNode(IRType *retType_, string name_) : retType(retType_), name(name_) {}
    explicit IRFunctionNode(IRType *retType_) : retType(retType_) {}
    ~IRFunctionNode() override
    {
        for (auto &b: blocks) delete b;
    }
    void accept(IRBaseVisitor *visitor) override { visitor->visitFunction(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRStmtNode : public IRNode{};

class IRGlobalVarStmtNode : public IRStmtNode{
public:
    IRTypeNode *value = nullptr;//值
    IRGlobalVarNode *var = nullptr;//变量

    explicit IRGlobalVarStmtNode(IRTypeNode *value_, IRGlobalVarNode *var_) : value(value_), var(var_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitGlobalVarStmt(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRTypeNode : public IRNode {
public:
    IRType *type = nullptr;

    explicit IRTypeNode(IRType *type_) : type(type_) {}
    virtual void accept(IRBaseVisitor *visitor) override { visitor->visitType(this); }
    virtual string to_string() override;
    virtual void print() override { std::cout << to_string(); }
};

class IRVarNode : public IRTypeNode {
public:
    string name;
    bool isConst = false;

    explicit IRVarNode(IRType * type_, string name_, bool isConst_) : IRTypeNode(type_), name(name_), isConst(isConst_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitVar(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRGlobalVarNode : public IRVarNode {
public:
    explicit IRGlobalVarNode(IRType *type_, string name_, bool isConst_) : IRVarNode(type_, name_, isConst_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitGlobalVar(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRLiteralNode : public IRTypeNode {
public:
    int value;

    explicit IRLiteralNode(IRType *type_, int value_) : IRTypeNode(type_), value(value_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitLiteral(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRStringNode : public IRTypeNode {
public:
    string str;

    explicit IRStringNode(IRType *type_, string str_) : IRTypeNode(type_), str(str_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitString(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

//注意，对标AST中的ASTSuiteNode
class IRSuiteNode : public IRNode {
public:
    string label;
    vector<IRStmtNode*> stmts;

    explicit IRSuiteNode(string label_) : label(label_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitSuite(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRCallStmtNode : public IRStmtNode {
public:
    IRVarNode *res;
    string funcName;
    vector<IRTypeNode *> args;

    explicit IRCallStmtNode(IRVarNode *res_, string funcName_) : res(res_), funcName(funcName_), args() {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitCallStmt(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRAllocaStmtNode : public IRStmtNode{
public:
    IRVarNode *var = nullptr;//关于指针变量的信息
    IRType *type = nullptr;//关于指针指向内容的类型
    //顺序与IR语句相一致，如 %b = alloca i32
    explicit IRAllocaStmtNode(IRVarNode *var_, IRType *type_) : var(var_), type(type_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitAllocaStmt(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRStoreStmtNode : public IRStmtNode{
public:
    IRTypeNode *value = nullptr;//值
    IRVarNode *pointer = nullptr;//变量
    //顺序与IR语句相一致，如：store i32 1, ptr %b
    explicit IRStoreStmtNode(IRTypeNode *value_, IRVarNode *pointer_) : value(value_), pointer(pointer_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitStoreStmt(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRBrStmtNode : public IRStmtNode{
public:
    string destinationLabel;

    explicit IRBrStmtNode(string destinationLabel_) : destinationLabel(destinationLabel_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitBrStmt(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRBrCondStmtNode : public IRStmtNode{
public:
    IRTypeNode *condition = nullptr;
    string trueLabel;
    string falseLabel;

    explicit IRBrCondStmtNode(IRTypeNode *condition_, string trueLabel_, string falseLabel_) : condition(condition_), trueLabel(trueLabel_), falseLabel(falseLabel_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitBrCondStmt(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRRetStmtNode : public IRStmtNode{
public:
    IRVarNode *var = nullptr;

    explicit IRRetStmtNode(IRVarNode *var_) : var(var_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitRetStmt(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRLoadStmtNode : public IRStmtNode{
public:
    //%b.val.2 = load i32, ptr %b
    IRVarNode *var = nullptr;//左侧
    IRVarNode *pointer = nullptr;//右侧

    explicit IRLoadStmtNode(IRVarNode *var_, IRVarNode *pointer_) : var(var_), pointer(pointer_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitLoadStmt(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRTruncateStmtNode : public IRStmtNode{
public:
    IRVarNode *var = nullptr;//左侧
    IRTypeNode *value = nullptr;//右侧

    explicit IRTruncateStmtNode(IRVarNode *var_, IRTypeNode *value_) : var(var_), value(value_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitTruncateStmt(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRPhiStmtNode : public IRStmtNode{
public:
    IRVarNode *var = nullptr;
    vector<pair<IRTypeNode *, string>> pairs;

    explicit IRPhiStmtNode(IRVarNode *var_) :var(var_) {}
    void accept(IRBaseVisitor *visitor) override {visitor->visitPhiStmt((this));}
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRIcmpStmtNode : public IRStmtNode{
public:
    string op;
    IRTypeNode *lhs = nullptr;
    IRTypeNode *rhs = nullptr;
    IRVarNode *var = nullptr;

    explicit IRIcmpStmtNode(string op_, IRTypeNode *lhs_, IRTypeNode *rhs_, IRVarNode *var_) : op(op_), lhs(lhs_), rhs(rhs_), var(var_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitIcmpStmt(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRBinaryStmtNode : public IRStmtNode{
public:
    string op;
    IRTypeNode *lhs = nullptr;
    IRTypeNode *rhs = nullptr;
    IRVarNode *var = nullptr;

    explicit IRBinaryStmtNode(string op_, IRTypeNode *lhs_, IRTypeNode *rhs_, IRVarNode *var_) : op(op_), lhs(lhs_), rhs(rhs_), var(var_) {}
    void accept(IRBaseVisitor *visitor) override { visitor->visitBinaryStmt(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

class IRZeroExtendStmtNode : public IRStmtNode {
public:
    IRVarNode* var = nullptr;
    IRTypeNode* value = nullptr;

    explicit IRZeroExtendStmtNode(IRVarNode* var_, IRTypeNode* value_) : var(var_), value(value_) {}
    void accept(IRBaseVisitor* visitor) override { visitor->visitZeroExtendStmt(this); }
    string to_string() override;
    void print() override { std::cout << to_string(); }
};

//totally formed by GitHub Copilot, magic it is
class IRGetElementPtrStmtNode : public IRStmtNode {
//%b.val.2 = getelementptr i32, ptr %b, i32 1
//<result> = getelementptr <ty>, ptr <ptrval>{, <ty> <idx>}*
public:
    IRVarNode *var = nullptr, *ptr = nullptr;
    IRTypeNode* index = nullptr;
    IRType* type;

    explicit IRGetElementPtrStmtNode(IRVarNode* var_, IRVarNode* ptr_, IRTypeNode* index_, IRType* type_):
            var(var_), ptr(ptr_), index(index_), type(type_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor){ visitor->visitGetElementPtrStmt(this); }
};
#endif //MXCOMPILER_2023_IRNODE_H
