#include "ASMBuilder.h"
#include "IRNode.h"
#include "ASMNode.h"

void ASMBuilder::visitProgram(IRProgramNode *node)
{
    if (!node->globalVarStmts.empty()) program->dataSection = new ASMDataSectionNode();
    if (!node->functions.empty()) program->textSection = new ASMTextSectionNode();
    for (auto g : node->globalVarStmts) visit(g);
    for (auto f : node->functions) visit(f);
}

void ASMBuilder::visitGlobalVarStmt(IRGlobalVarStmtNode *node)
{
    string str;
    auto strIR = dynamic_cast<IRStringNode *>(node->value);
    bool is_string = (strIR != nullptr);
    if (is_string) str = strIR->str;
    else
    {
        str = node->value->to_string();
        //TODO: double check here
        if (str[0] == '@') str = str.substr(1);
        else if (str == "null") str = "0";
        else if (str == "true") str = "1";
        else if (str == "false") str = "0";
    }
    auto var = new ASMGlobalVarNode(node->var->name, is_string);
    valueSet.insert(var), varMap[node->var->name] = var;
    auto globalVarStmt = new ASMGlobalVarStmtNode(node->var->name, str, is_string);
    program->dataSection->globalVarStmts.push_back(globalVarStmt);
}

void ASMBuilder::visitFunction(IRFunctionNode *node)
{
    if (node->blocks.empty()) return;//declare
    currentFunction = node;
    auto function = new ASMFunctionNode();
    program->textSection->functions.push_back(function);
    //TODO: not finished yet
}



