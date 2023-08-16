#ifndef MXCOMPILER_2023_SYMBOLCOLLECTOR_H
#define MXCOMPILER_2023_SYMBOLCOLLECTOR_H

#include "ASTBaseVisitor.h"
#include "Scope.h"
#include "Type.h"
#include "ASTNode.h"

//需要跑programNode和classNode
class ClassScanner: public ASTBaseVisitor{
private:
    GlobalScope *globalScope;
public:
    explicit ClassScanner(GlobalScope *globalScope_) : globalScope(globalScope_) {}
    void builtInInit()
    {
        globalScope->addClass("bool"), globalScope->addClass("int"), globalScope->addClass("void"), globalScope->addClass("string");
    }
    virtual void visitProgramNode(ASTProgramNode *node) override
    {
        for (auto u : node->children)
        {
            std::cerr<<"+"<<std::endl;
            u->accept(this);
        }
    }
    virtual void visitClassNode(ASTClassNode *node) override
    {
        if (globalScope->isClassExisted(node->name))
            throw semantic_error("class redefine, the className is " + node->name);
        globalScope->addClass(node->name);
        //原则上if这一行代码可以移除，不过目前这样代码可读性更高
    }
};

class FunctionScanner : public ASTBaseVisitor{
private:
    GlobalScope *globalScope;
    void visitFunc(ASTFunctionNode *node, Scope *scope, bool is_constructor)
    {
        if (!is_constructor && globalScope->isClassExisted(node->name))
            throw semantic_error("Function name conflicts with constructor of an existing class, funcName : " + node->name);
        FuncType cur(node->name);
        for (const auto& p : node->paras) cur.paras.emplace_back(p.first->name, p.first->dim, false);
        //如果是构造函数过来，这里的node->returnType是nullptr，所以需要特判
//        std::cerr<<"++++"<<node->returnType<<std::endl;
        if (!node->returnType) cur.returnType = Type("void", 0, false);
        else cur.returnType = Type(node->returnType->name, node->returnType->dim, false);
        scope->addFunc(cur);
    }
public:
    explicit FunctionScanner(GlobalScope *globalScope_) : globalScope(globalScope_) {}
    void builtInInit()
    {
        FuncType cur;
        cur.name = "print";
        cur.returnType = Type("void", 0, true);
        cur.paras.emplace_back("string", 0, false);
        globalScope->addFunc(cur);
        cur.paras.clear();

        cur.name = "println";
        cur.returnType = Type("void", 0, true);
        cur.paras.emplace_back("string", 0, false);
        globalScope->addFunc(cur);
        cur.paras.clear();

        cur.name = "printInt";
        cur.returnType = Type("void", 0, true);
        cur.paras.emplace_back("int", 0, false);
        globalScope->addFunc(cur);
        cur.paras.clear();

        cur.name = "printlnInt";
        cur.returnType = Type("void", 0, true);
        cur.paras.emplace_back("int", 0, false);
        globalScope->addFunc(cur);
        cur.paras.clear();

        cur.name = "getString";
        cur.returnType = Type("string", 0, true);
        globalScope->addFunc(cur);
        cur.paras.clear();

        cur.name = "getInt";
        cur.returnType = Type("int", 0, true);
        globalScope->addFunc(cur);
        cur.paras.clear();

        cur.name = "toString";
        cur.returnType = Type("string", 0, true);
        cur.paras.emplace_back("int", 0, false);
        globalScope->addFunc(cur);
        cur.paras.clear();

        //int type[]::size()
        cur.name = "__size__";
        cur.returnType = Type("int", 0, true);
        globalScope->addFunc(cur);
        cur.paras.clear();

        auto scope = globalScope->getClassType("string")->scope = new Scope(globalScope);

        cur.name = "length";
        cur.returnType = Type("int", 0, true);
        scope->addFunc(cur);
        cur.paras.clear();

        cur.name = "substring";
        cur.returnType = Type("string", 0, true);
        cur.paras.emplace_back("int", 0, false);
        cur.paras.emplace_back("int", 0, false);
        scope->addFunc(cur);
        cur.paras.clear();

        cur.name = "parseInt";
        cur.returnType = Type("int", 0, true);
        scope->addFunc(cur);
        cur.paras.clear();

        cur.name = "ord";
        cur.returnType = Type("int", 0, true);
        cur.paras.emplace_back("int", 0, false);
        scope->addFunc(cur);
        cur.paras.clear();
    }
    virtual void visitProgramNode(ASTProgramNode *node) override
    {
        for (auto u : node->children) u->accept(this);
    }
//    virtual void visitStmtNode(ASTStmtNode *node) {} //不知为啥没有
    virtual void visitFunctionNode(ASTFunctionNode *node) override
    {
        visitFunc(node, globalScope, false);
    }
    virtual void visitClassNode(ASTClassNode *node) override
    {
        node->scope = new Scope(globalScope);
        globalScope->getClassType(node->name)->scope = node->scope;
        node->scope->addVar("this", Type(node->name, 0, false));
        for (auto varStmt : node->variables)
        {
            if (!varStmt->type) throw semantic_error("class type missed, class name : " + node->name);
            auto curType = Type(varStmt->type->name, varStmt->type->dim, false);
            for (auto obj : varStmt->vars) node->scope->addVar(obj.first, curType);
        }
        for (auto cons : node->constructors)
        {
            if (cons->name != node->name) throw semantic_error("constructor name doesn't match the class, class name : " + node->name);
            visitFunc(cons, node->scope, true);
        }
        for (auto func : node->functions)
        {
            visitFunc(func, node->scope, false);
        }
    }
};
#endif //MXCOMPILER_2023_SYMBOLCOLLECTOR_H
