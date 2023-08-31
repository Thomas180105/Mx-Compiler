#include "ASMNode.h"

string ASMImmRegCmdNode::to_string()
{
    return op + " " + dest->name + ", " + src->name + ", " + std::to_string(imm);
}

string ASMRegRegCmdNode::to_string()
{
    return op + " " + dest->name + ", " + src1->name + ", " + src2->name;
}

string ASMLoadCmdNode::to_string()
{
    return op + " " + dest->name + ", " + std::to_string(offset) + "(" + src->name + ")";
}

string ASMStoreCmdNode::to_string()
{
    return op + " " + src->name + ", " + std::to_string(offset) + "(" + dest->name + ")";
}

string ASMBrCondStmtNode::to_string()
{
    return op + " " + src1->name + ", " + src2->name + ", " + label;
}

string ASMJumpCmdNode::to_string()
{
    return "j " + label;
}

string ASMLaCmdNode::to_string()
{
    return "la " + dest->name + ", " + name;
}

string ASMRetCmdNode::to_string()
{
    return "ret";
}

string ASMCallCmdNode::to_string()
{
    return "call " + name;
}

string ASMLocalVarNode::to_string()
{
    return name;
}

std::string ASMGlobalVarNode::to_string()
{
    return name;
}

std::string ASMSuiteNode::to_string()
{
    string res;
    if (label == "main") res += ".globl main\n";
    res += label + ":\n";
    for (auto c : cmds) res += "   " + c->to_string() + '\n';
    res += '\n';
    return res;
}

std::string ASMGlobalVarStmtNode::to_string()
{
    string res;
    res += name + ": .";
    if (!is_string) res += "word " + val;
    else
    {
        if (val.empty()) res += "zero 1";
        else
        {
            res += "asciz \"";
            for (auto c : val)
            {
                if (c == '\n') res += "\\n";
                else if (c == '\"') res += "\\\"";
                else if (c == '\\') res += "\\\\";
                else res += c;
            }
            res += "\"";
        }
    }
    return res;
}

std::string ASMFunctionNode::to_string()
{
    string res;
    for (auto b : blocks) res += b->to_string();
    return res;
}

std::string ASMDataSectionNode::to_string()
{
    string res;
    res += ".data\n";
    for (auto g : globalVarStmts) res += g->to_string() + '\n';
    return res;
}

std::string ASMTextSectionNode::to_string()
{
    string res;
    res += ".text\n";
    for (auto f : functions) res += f->to_string() + '\n';
    return res;
}

std::string ASMProgramNode::to_string()
{
    string res;
    if (dataSection) res += dataSection->to_string() + '\n';
    if (textSection) res += textSection->to_string() + '\n';
    return res;
}
