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

class ASMImmRegCmdNode : public ASMCommandNode {
public:
    string op;
    Register *dest = nullptr;
    Register *src = nullptr;
    int imm = 0;
    void setImm(const int imm_) {imm = imm_;}
    explicit ASMImmRegCmdNode(string op_, Register *dest_, Register *src_, int imm_ = 0) : op(op_), dest(dest_), src(src_), imm(imm_) {}
    string to_string() override;
};

class ASMRegRegCmdNode : public ASMCommandNode {
public:
    string op;
    Register *dest = nullptr;
    Register *src1 = nullptr;
    Register *src2 = nullptr;
    explicit ASMRegRegCmdNode(string op_, Register *dest_, Register *src1_, Register *src2_) : op(op_), dest(dest_), src1(src1_), src2(src2_) {}
    string to_string() override;
};
//x[dest] = M[x[src] + offset]
class ASMLoadCmdNode : public ASMCommandNode {
public:
    string op;
    Register *dest = nullptr;
    Register *src = nullptr;
    int offset = 0;
    explicit ASMLoadCmdNode(string op_, Register *dest_, Register *src_, int offset_ = 0) : op(op_), dest(dest_), src(src_), offset(offset_) {}
    string to_string() override;
};
//M[x[dest] + offset] = x[src]
class ASMStoreCmdNode : public ASMCommandNode {
public:
    string op;
    Register *dest = nullptr;
    Register *src = nullptr;
    int offset = 0;
    explicit ASMStoreCmdNode(string op_, Register *dest_, Register *src_, int offset_ = 0) : op(op_), dest(dest_), src(src_), offset(offset_) {}
    string to_string() override;
};

class ASMBrCondStmtNode : public ASMCommandNode
{
    //bne x5，x0，Exit ＃如果 x5！= 0，则跳转到 Exit
public:
    string op;
    Register *src1 = nullptr;
    Register *src2 = nullptr;
    string label;
    explicit ASMBrCondStmtNode(string op_, Register *src1_, Register *src2_, string label_) : op(op_), src1(src1_), src2(src2_), label(label_) {}
    string to_string() override;
};

class ASMJumpCmdNode : public ASMCommandNode {
public:
    // j offset   (将pc设置为当前指加上符号位拓展的offset)
    string label;
    explicit ASMJumpCmdNode(string label_) : label(label_) {}
    string to_string() override;
};

class ASMLaCmdNode : public ASMCommandNode {
    // la rd symbol (将 symbol 的地址加载到 x[rd]中)
public:
    Register *dest = nullptr;
    string name;
    explicit ASMLaCmdNode(Register *dest_, string name_) : dest(dest_), name(name_) {}
    string to_string() override;
};

class ASMRetCmdNode : public ASMCommandNode {
public:
    // ret (从子过程返回。实际被扩展为 jalr x0, 0(x1))
    string to_string() override;
};

class ASMCallCmdNode : public ASMCommandNode {
public:
    // call symbol (调用子过程 symbol)
    string name;
    explicit ASMCallCmdNode(string name_) : name(name_) {}
    string to_string() override;
};

class ASMVarNode: public ASMNode {
public:
    std::string name;
    bool is_ptr = false;

    void setPtrFlag(bool f) {is_ptr = f;}
    explicit ASMVarNode(std::string name_, bool p_): name(name_), is_ptr(p_) {}
};

class ASMLocalVarNode: public ASMVarNode {
public:
    Register *reg = nullptr;
    int offset;//相对于sp
    explicit ASMLocalVarNode(std::string name_, int offset_, bool p_): ASMVarNode(name_, p_), offset(offset_) {}
    string to_string() override;
};

class ASMGlobalVarNode: public ASMVarNode {
public:
    explicit ASMGlobalVarNode(std::string name_, bool p_): ASMVarNode(name_, p_) {}
    std::string to_string() override;
};

class ASMSuiteNode : public ASMNode {
public:
    string label;
    vector<ASMNode *> cmds;

    ASMSuiteNode() = default;
    explicit ASMSuiteNode(string label_) : label(label_) {}
    ~ASMSuiteNode() override {for (auto c : cmds) delete c;}
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
    vector<ASMSuiteNode *> blocks;

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
