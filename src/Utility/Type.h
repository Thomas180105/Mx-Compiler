#ifndef MXCOMPILER_2023_TYPE_H
#define MXCOMPILER_2023_TYPE_H
#include <vector>
#include <string>
using std::vector;
using std::string;

class TypeName{
public:
    string name;
    TypeName() = default;
    TypeName(const string &n) : name(n) {}
};

class Type : public TypeName{
public:
    int dim = 0;//dimension
    bool isConst = false;
public:
    Type() = default;
    Type(const string &name_) : TypeName(name_) {}
    Type(const string &name_, const int &dim_, bool isConst_) : TypeName(name_), dim(dim_), isConst(isConst_) {}
    Type &operator=(const Type &rhs)
    {
        if (this == &rhs) return *this;
        name = rhs.name, dim = rhs.dim, isConst = rhs.isConst;
        return *this;
    }
    bool operator==(const Type &rhs) const {return name == rhs.name && dim == rhs.dim;}
    bool operator!=(const Type &rhs) const {return !(*this == rhs);}
    [[nodiscard]] bool is_void()   const { return dim == 0 &&  name == "void"; }
    [[nodiscard]] bool is_bool()   const { return dim == 0 &&  name == "bool"; }
    [[nodiscard]] bool is_int() const {return dim == 0 && name == "int";}
    [[nodiscard]] bool is_string() const { return dim == 0 &&  name == "string"; }
    [[nodiscard]] bool is_null()   const { return dim == 0 &&  name == "null"; }
    [[nodiscard]] bool is_builtIn()  const { return dim == 0 && (name == "void" || name == "bool" || name == "int" || name == "string"); }
    void setConst() {isConst = true;}
    [[nodiscard]] bool is_const()  const { return isConst; }
    [[nodiscard]] bool assignable(const Type &rhs) const {return !isConst && convertible(rhs);}
    [[nodiscard]] bool convertible(const Type &rhs) const
    {
        if (rhs.is_null()) return dim > 0 || !is_builtIn();
        return name == rhs.name && dim == rhs.dim;
    }
};

class Scope;

class ClassType : public Type{
public:
    Scope *scope = nullptr;
    ClassType() = default;
    ClassType(const string &name_) : Type(name) {}
};

class FuncType : public Type{
public:
    vector<Type> paras;
    Type returnType;
    FuncType() = default;
    FuncType(const string & name) : Type(name) {}
};


#endif //MXCOMPILER_2023_TYPE_H
