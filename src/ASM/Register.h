#ifndef MXCOMPILER_2023_REGISTER_H
#define MXCOMPILER_2023_REGISTER_H
//mostly formed with the help of GitHub Copilot

#include <string>
#include <map>
using std::string;
using std::map;

class Register {
public:
    string name;
    int value{};
    Register() = default;
    string to_string() { return name; }
};

class PhysicalRegister : public Register {};

class VirtualRegister : public Register {};

class RegisterManager{
private:
    PhysicalRegister x[32];
    map<string, PhysicalRegister*> name2reg;

public:
    RegisterManager()
    {
        x[0].name = "zero", x[1].name = "ra", x[2].name = "sp", x[3].name = "gp", x[4].name = "tp";
        x[5].name = "t0", x[6].name = "t1", x[7].name = "t2", x[8].name = "s0", x[9].name = "s1";
        for (int i = 10; i <= 17; ++i) x[i].name = "a" + std::to_string(i - 10);
        for (int i = 18; i <= 27; ++i) x[i].name = "s" + std::to_string(i - 18 + 2);
        for (int i = 28; i <= 31; ++i) x[i].name = "t" + std::to_string(i - 28 + 3);
        for (int i = 0; i < 32; ++i) name2reg[x[i].name] = &x[i];
        for (int i = 0; i < 32; ++i) name2reg["x" + std::to_string(i)] = &x[i];
    }
    Register* getRegPtr(const string &name) {return name2reg[name];}
};

#endif //MXCOMPILER_2023_REGISTER_H
