#ifndef MXCOMPILER_2023_IRTYPE_H
#define MXCOMPILER_2023_IRTYPE_H
#include <string>
#include <utility>
#include <vector>
//mostly formed by GitHub copilot
using std::string;
class IRType{
public:
    virtual string to_string() = 0;
    virtual int size() = 0;
    virtual ~IRType() {}
};

class IRIntType : public IRType{
public:
    int bits;
    explicit IRIntType(int bits_) : bits(bits_) {}
    string to_string() override {return "i" + std::to_string(bits);}
    int size() override { return (bits + 7) / 8; }
};

class IRVoidType: public IRType{
public:
    string to_string() override { return "void"; }
    int size() override { return 0; }
};

class IRPtrType: public IRType{
public:
    string to_string() override { return "ptr"; }
    int size() override { return 4; }
};

class IRStringType: public IRPtrType {};

class IRArrayType: public IRType{
public:
    int capacity;
    IRType *type;

    explicit IRArrayType(int capacity_, IRType *type_): capacity(capacity_), type(type_) {}
    string to_string() override {return "[" + std::to_string(capacity) + " x " + type->to_string() + "]";}
    int size() override {return capacity * type->size();}
    ~IRArrayType() override {delete type;}
};

class IRClassType : public IRType{
public:
    string name;
    std::vector<IRType*> members;
    explicit IRClassType(string name_) : name(std::move(name_)), members() {}
    string to_string() override
    {
        return "%class." + name;
    }
    int size() override
    {
        int res = 0;
        for (auto member : members) res += member->size();
        return res;
    }
    //warning : double free or corruption (out) when delete member
    ~IRClassType() override
    {
        for (auto member : members) delete member;
    }
};

//    string to_string() override
//    {
//        string res = "type { ";
//        auto len = members.size();
//        for (int i = 0; i < len - 1; ++i) res += members[i]->to_string() + ", ";
//        res += members[len - 1]->to_string();
//        res += " }";
//        if (size() % 4) res = "<" + res + ">";
//        return res;
//    }

#endif //MXCOMPILER_2023_IRTYPE_H
