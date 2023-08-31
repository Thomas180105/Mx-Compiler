#ifndef MXCOMPILER_2023_SCOPE_H
#define MXCOMPILER_2023_SCOPE_H
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include "Type.h"
#include "Exception.h"
using std::map;
using std::set;
using std::vector;
using std::string;

class Scope {
private:
    map<string, Type> vars;
    map<string, FuncType> funcs;
    set<string> unique;
    Scope *parent = nullptr;
    int childCnt = 0;
public:
    string scopeName;

    explicit Scope(Scope *parent_) : parent(parent_)
    {
        if (parent)
        {
            ++parent->childCnt;
            //选择一些高级语言不可使用的名称作为 identifier。这在内建函数和类的成员方法中非常常见
            scopeName = parent->scopeName + "." + std::to_string(parent->childCnt);
        }
    }

    bool isVarExisted(string name) { return vars.count(name); }

    void addVar(string name, Type type)
    {
        if (isVarExisted(name)) throw semantic_error("[scope]variable redefine, the varName is " + name);
        if (type.name == "void") throw semantic_error("[scope]variable type error(unexpected void), the varName is " + name);
        vars.emplace(name, type); //better than "vars[name] = type;"
        unique.insert(name);
    }

    Type tellVarType(const string &name)
    {
        for (Scope *p = this; p; p = p->parent) if (p->vars.count(name)) return p->vars[name];
        throw semantic_error("[scope]variable not found, the varName is :" + name);
    }

    string tellVarUnique(const string name)
    {
        for (Scope *p = this; p; p = p->parent) if (p->unique.find(name) != p->unique.end()) return name + p->scopeName;
        throw semantic_error("[scope]variable not found, the varName is :" + name);
    };

    void addFunc(FuncType func)
    {
        if (funcs.count(func.name)) throw semantic_error("[scope]function redefine, the funcName is " + func.name);
        funcs.emplace(func.name, func);
        vars.emplace(func.name, func.returnType);
        unique.insert(func.name);
    }

    FuncType tellFuncType(const string &name)
    {
        for (Scope *p = this; p; p = p->parent) if (p->funcs.count(name)) return p->funcs[name];
        throw semantic_error("[scope]function not found, the funcName is :" + name);
    }
};

class GlobalScope : public Scope{
private:
    map<string, ClassType*> types;
public:
    GlobalScope() = default;
    GlobalScope(Scope *parent) : Scope(parent) {}
    ~GlobalScope() {for (const auto& t : types) {delete t.second->scope; delete t.second;}}
    bool isClassExisted(const string &name) { return types.count(name); }
    TypeName* addClass(const string &name)
    {
        if (isClassExisted(name)) throw semantic_error("[scope]class redefine, the className is " + name);
        auto type = new ClassType(name);
        types.emplace(name, type);
//        std::cerr<<"in addClass() : "<<name<<'\n';
        return type;
    }
    ClassType* getClassType(const string &name)
    {
        if (!isClassExisted(name)) throw semantic_error("[scope]class not found, the className is " + name);
        return types[name];
    }
    void setName(string name) { scopeName = name; }
};

#endif //MXCOMPILER_2023_SCOPE_H
