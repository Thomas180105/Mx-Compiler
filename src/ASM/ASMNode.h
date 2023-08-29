#ifndef MXCOMPILER_2023_ASMNODE_H
#define MXCOMPILER_2023_ASMNODE_H
#include <string>
#include <vector>
#include "Register.h"
using std::string;
using std::vector;

class ASMNode {
public:
    ASMNode() = default;
    virtual ~ASMNode() = default;
    virtual std::string to_string() = 0;
};

class ASMCommandNode : public ASMNode {};

class ASMVarNode: public ASMNode {
public:
    std::string name;
    bool is_ptr = false;

    explicit ASMVarNode(std::string name_, bool p_): name(name_), is_ptr(p_) {}
};

class ASMGlobalVarNode: public ASMVarNode {
public:
    explicit ASMGlobalVarNode(std::string name_, bool p_): ASMVarNode(name_, p_) {}
    std::string to_string() override;
};

class ASMBlockNode : public ASMNode {
public:
    string label;
    vector<ASMNode *> cmds;

    ASMBlockNode() = default;
    explicit ASMBlockNode(string label_) : label(label_) {}
    ~ASMBlockNode() override {for (auto c : cmds) delete c;}
    std::string to_string() override;
};

class ASMGlobalVarStmtNode : public ASMNode {
public:
    string name, val;
    bool is_string = false;

    explicit ASMGlobalVarStmtNode(string name_, string val_, bool is_string_ = false) : name(name_), val(val_), is_string(is_string_) {}
    std::string to_string() override;
};

class ASMFunctionNode : public ASMNode {
public:
    vector<ASMBlockNode *> blocks;

    ASMFunctionNode() = default;
    ~ASMFunctionNode() override {for (auto b : blocks) delete b;}
    std::string to_string() override;
};

class ASMDataSectionNode : public ASMNode {
public:
    vector<ASMGlobalVarStmtNode *> globalVarStmts;
    ~ASMDataSectionNode() override {for (auto g : globalVarStmts) delete g;}
    std::string to_string() override;
};

class ASMTextSectionNode : public ASMNode {
public:
    vector<ASMFunctionNode *> functions;
    ~ASMTextSectionNode() override {for (auto f : functions) delete f;}
    std::string to_string() override;
};

class ASMProgramNode : public ASMNode {
public:
    ASMDataSectionNode *dataSection = nullptr;
    ASMTextSectionNode *textSection = nullptr;

    ASMProgramNode() = default;
    explicit ASMProgramNode(ASMDataSectionNode *data_, ASMTextSectionNode *text_) : dataSection(data_), textSection(text_) {}
    ~ASMProgramNode() override {delete dataSection; delete textSection;}
    std::string to_string() override;
};


#endif //MXCOMPILER_2023_ASMNODE_H
