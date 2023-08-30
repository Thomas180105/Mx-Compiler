#include "ASMBuilder.h"
#include "IRNode.h"
#include "ASMNode.h"

void ASMBuilder::IRUpdReg(IRTypeNode *IRValue, Register *reg)
{
    if (auto tmp1 = dynamic_cast<IRLiteralNode *>(IRValue))
    {
        auto move = new ASMImmRegCmdNode("addi", reg, regPool.getReg("zero"), tmp1->value);
        currentBlock->cmds.push_back(move);
    }
    else if (auto tmp2 = dynamic_cast<IRVarNode *>(IRValue))
    {
        auto var = IR2ASM(tmp2);
        ASMVarUpdReg(var, reg);
    }
}

ASMVarNode *ASMBuilder::IR2ASM(IRVarNode *IRValue)
{
    if (varMap.count(IRValue->name)) return varMap[IRValue->name];
    return registerLocalVar(IRValue, false);
}

ASMLocalVarNode *ASMBuilder::registerLocalVar(IRVarNode *var, bool flag)
{
    if (varMap.count(var->name))
    {
        auto res = dynamic_cast<ASMLocalVarNode *>(varMap[var->name]);
        res->setPtrFlag(flag);
        return res;
    }
    auto res = new ASMLocalVarNode(var->name, currentSize, flag);
    valueSet.insert(res), varMap[var->name] = res;
    currentSize += var->type->size();
    return res;
}


void ASMBuilder::ASMVarUpdReg(ASMVarNode *ASMValue, Register *reg)
{
    if (auto tmp1 = dynamic_cast<ASMLocalVarNode *>(ASMValue))
    {
        auto load = new ASMLoadCmdNode("lw", reg, regPool.getReg("sp"), tmp1->offset);
        currentBlock->cmds.push_back(load);
    }
    else if (auto tmp2 = dynamic_cast<ASMGlobalVarNode *>(ASMValue))
    {
        auto laCmd = new ASMLaCmdNode(reg, tmp2->name);
        currentBlock->cmds.push_back(laCmd);
        if (!ASMValue->is_ptr)//如果不是指针变量，则拿到地址之后需要去相应地址找
        {
            auto move = new ASMLoadCmdNode("lw", reg, reg);
            currentBlock->cmds.push_back(move);
        }
    }
}

void ASMBuilder::ASMPtrUpdReg(ASMVarNode *ASMValue, Register *reg)
{
    if (!ASMValue->is_ptr) return;//TODO: or throw error?
    if (auto tmp1 = dynamic_cast<ASMGlobalVarNode *>(ASMValue))
    {
        auto laCmd = new ASMLaCmdNode(reg, tmp1->name);
        auto load = new ASMLoadCmdNode("lw", reg, reg);
        auto load2 = new ASMLoadCmdNode("lw", reg, reg);
        currentBlock->cmds.push_back(laCmd), currentBlock->cmds.push_back(load), currentBlock->cmds.push_back(load2);
    }
    else if (auto tmp2 = dynamic_cast<ASMLocalVarNode *>(ASMValue))
    {
        auto load = new ASMLoadCmdNode("lw", reg, regPool.getReg("sp"), tmp2->offset);
        auto load2 = new ASMLoadCmdNode("lw", reg, reg);
        currentBlock->cmds.push_back(load), currentBlock->cmds.push_back(load2);
    }
}

void ASMBuilder::storeVar(ASMVarNode *var, Register *reg)//reg写var
{
    if (auto tmp1 = dynamic_cast<ASMLocalVarNode *>(var))
    {
        auto store = new ASMStoreCmdNode("sw", regPool.getReg("sp"), reg, tmp1->offset);
        currentBlock->cmds.push_back(store);
    }
    else if (auto tmp2 = dynamic_cast<ASMGlobalVarNode *>(var))
    {
        auto laCmd = new ASMLaCmdNode(regPool.getReg("s1"), tmp2->name);//将地址放在s1寄存器中
        auto store = new ASMStoreCmdNode("sw", regPool.getReg("s1"), reg);//访问地址为s1寄存器值的内存，将其写为reg
        currentBlock->cmds.push_back(laCmd), currentBlock->cmds.push_back(store);
    }
}

void ASMBuilder::storePtr(ASMVarNode *var, Register *reg)
{
    if (var->is_ptr) return;//TODO: or throw error?
    if (auto tmp1 = dynamic_cast<ASMLocalVarNode *>(var))
    {
        auto load = new ASMLoadCmdNode("lw", regPool.getReg("s1"), regPool.getReg("sp"), tmp1->offset);//把指针存的内容（实际1内容的地址）取出来，暂存s1
        auto store = new ASMStoreCmdNode("sw", regPool.getReg("s1"), reg);//把reg写到这个地址里
        currentBlock->cmds.push_back(load), currentBlock->cmds.push_back(store);
    }
    else if (auto tmp2 = dynamic_cast<ASMGlobalVarNode *>(var))
    {
        auto laCmd = new ASMLaCmdNode(regPool.getReg("s1"), tmp2->name);
        auto load = new ASMLoadCmdNode("lw", regPool.getReg("s1"), regPool.getReg("s1"));
        auto store = new ASMStoreCmdNode("sw", regPool.getReg("s1"), reg);
        currentBlock->cmds.push_back(laCmd), currentBlock->cmds.push_back(load), currentBlock->cmds.push_back(store);
    }
}


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
//        else if (str == "true") str = "1";
//        else if (str == "false") str = "0";
    }
    auto var = new ASMGlobalVarNode(node->var->name, is_string);
    valueSet.insert(var), varMap[node->var->name] = var;
    auto globalVarStmt = new ASMGlobalVarStmtNode(node->var->name, str, is_string);
    program->dataSection->globalVarStmts.push_back(globalVarStmt);
}

void ASMBuilder::visitFunction(IRFunctionNode *node)
{
    //TODO : double check here
    if (node->blocks.empty()) return;//declare
    currentFunction = node;
    program->textSection->functions.push_back(new ASMFunctionNode());
    currentSize = 0;
    for (auto &b : node->blocks) visit(b);
    currentSize = (currentSize + 15) / 16 * 16;
    currentFunction = nullptr;
}

void ASMBuilder::visitSuite(IRSuiteNode *node)
{
    ASMSuiteNode *tmpBlock = nullptr;
    if (node->label != "entry") tmpBlock = new ASMSuiteNode(".L" + node->label);//.L表示本地标签
    else
    {
        tmpBlock = new ASMSuiteNode(currentFunction->name);
        currentBlock = tmpBlock;
        auto add = new ASMImmRegCmdNode("addi", regPool.getReg("sp"), regPool.getReg("sp"), -currentSize);//为函数开辟栈空间
        currentBlock->cmds.push_back(add);
        int stackCnt = 0;
        for (int i = 8, k = currentFunction->args.size(); i < k; ++i)
        {
            auto arg = currentFunction->args[i];
            //在currentSize更新之前进行ASMVar创建
            auto ASMVar = new ASMLocalVarNode(arg.second, currentSize, false);
            currentSize += arg.first->size(); stackCnt += arg.first->size();
            valueSet.insert(ASMVar), varMap[arg.second] = ASMVar;
            auto load = new ASMLoadCmdNode("lw", regPool.getReg("s0"), regPool.getReg("sp"), -stackCnt);
            currentBlock->cmds.push_back(load);
            storeVar(ASMVar, regPool.getReg("s0"));
        }

        for (int i = 0, k = currentFunction->args.size(), s = std::min(8, k); i < s; ++i)
        {
            auto arg = currentFunction->args[i];
            auto ASMVar = new ASMLocalVarNode(arg.second, currentSize, false);
            currentSize += arg.first->size();
            valueSet.insert(ASMVar), varMap[arg.second] = ASMVar;
            storeVar(ASMVar, regPool.getReg("a" + std::to_string(i)));
        }

        auto raVar = new ASMLocalVarNode("..ra" + currentFunction->name, currentSize, false);
        currentSize += 4;
        valueSet.insert(raVar), varMap["..ra" + currentFunction->name] = raVar;
        auto store = new ASMStoreCmdNode("sw", regPool.getReg("sp"), regPool.getReg("ra"), raVar->offset);
        currentBlock->cmds.push_back(store);
    }
    program->textSection->functions.back()->blocks.push_back(tmpBlock);//往时期最进的func中塞tmpBlock
    currentBlock = tmpBlock;
    for (auto &c : node->stmts) visit(c);
}

void ASMBuilder::visitCallStmt(IRCallStmtNode *node)
{
    ASMLocalVarNode *var = nullptr;
    if (node->res) var = registerLocalVar(node->res, node->res->type->to_string() == "ptr");
    int stackCnt = 0;
    for (int i = 8, k = node->args.size(); i < k; ++i)
    {
        auto arg = node->args[i];
        IRUpdReg(arg, regPool.getReg("s0"));
        stackCnt += arg->type->size();
        auto store = new ASMStoreCmdNode("sw", regPool.getReg("sp"), regPool.getReg("s0"), -stackCnt);
        currentBlock->cmds.push_back(store);
    }

    for (int i = 0, k = node->args.size(), s = std::min(8, k); i < s; ++i)
    {
        auto arg = node->args[i];
        IRUpdReg(arg, regPool.getReg("a" + std::to_string(i)));
    }

    auto call = new ASMCallCmdNode(node->funcName);
    currentBlock->cmds.push_back(call);
    if (var) storeVar(var, regPool.getReg("a0"));
}

void ASMBuilder::visitAllocaStmt(IRAllocaStmtNode *node)
{
    registerLocalVar(node->var, false);
}

void ASMBuilder::visitStoreStmt(IRStoreStmtNode *node)
{//node->value是值,node->pointer是被赋值的变量
    //TODO: double think here
    IRUpdReg(node->value, regPool.getReg("s0"));
    auto ASMVar = varMap[node->pointer->name];
    if (ASMVar->is_ptr) storePtr(ASMVar, regPool.getReg("s0"));
    else storeVar(ASMVar, regPool.getReg("s0"));

    if (node->is_ptr) ASMVar->is_ptr = true;
}

void ASMBuilder::visitBrStmt(IRBrStmtNode *node)
{
    auto laCmd = new ASMLaCmdNode(regPool.getReg("t6"), currentBlock->label);
    auto jump = new ASMJumpCmdNode(".L" + node->destinationLabel);
    currentBlock->cmds.push_back(laCmd), currentBlock->cmds.push_back(jump);
}

void ASMBuilder::visitBrCondStmt(IRBrCondStmtNode *node)
{
    auto laCmd = new ASMLaCmdNode(regPool.getReg("t6"), currentBlock->label);
    IRUpdReg(node->condition, regPool.getReg("s0"));
    auto bne = new ASMBrCondStmtNode("bne", regPool.getReg("s0"), regPool.getReg("zero"), ".L" + node->trueLabel);
    auto jump = new ASMJumpCmdNode(".L" + node->falseLabel);
    currentBlock->cmds.push_back(laCmd), currentBlock->cmds.push_back(bne), currentBlock->cmds.push_back(jump);
}

void ASMBuilder::visitRetStmt(IRRetStmtNode *node)
{
    if (node->var) ASMVarUpdReg(varMap[node->var->name], regPool.getReg("a0"));
    auto raVar = dynamic_cast<ASMLocalVarNode *>(varMap["..ra" + currentFunction->name]);
    auto load = new ASMLoadCmdNode("lw", regPool.getReg("ra"), regPool.getReg("sp"), raVar->offset);
    auto addi = new ASMImmRegCmdNode("addi", regPool.getReg("sp"), regPool.getReg("sp"), currentSize);//Freeing space on the function stack frame.
    auto ret = new ASMRetCmdNode();
    currentBlock->cmds.push_back(load), currentBlock->cmds.push_back(addi), currentBlock->cmds.push_back(ret);
}

void ASMBuilder::visitLoadStmt(IRLoadStmtNode *node)
{
    auto var = registerLocalVar(node->var, node->var->type->to_string() == "ptr");//with present check
    auto ptr = varMap[node->pointer->name];
    if (ptr->is_ptr) ASMPtrUpdReg(ptr, regPool.getReg("s0"));
    else ASMVarUpdReg(ptr, regPool.getReg("s0"));
    storePtr(var, regPool.getReg("s0"));
}

void ASMBuilder::visitTruncateStmt(IRTruncateStmtNode *node)
{//node->var,等式左侧  node->value,等式右侧 被类型压缩的值
    IRUpdReg(node->value, regPool.getReg("s0"));
    auto ASMVar = registerLocalVar(node->var, false);
    storePtr(ASMVar, regPool.getReg("s0"));
}

void ASMBuilder::visitPhiStmt(IRPhiStmtNode *node)
{
    auto ASMVar = registerLocalVar(node->var, false);
    auto endBlock = new ASMSuiteNode(".LPhiEnd" + std::to_string(counter["PhiEnd"]++));
    for (auto p : node->pairs)
    {
        auto IRVar = p.first;
        auto label = p.second;
        if (label == "entry") label = currentFunction->name;
        else label = ".L" + label;

        auto tmpBlock = new ASMSuiteNode(".LPhiLoad" + std::to_string(counter["PhiLoad"]++));
        auto laCmd = new ASMLaCmdNode(regPool.getReg("t5"), label);
        currentBlock->cmds.push_back(laCmd);
        str2la[label].push_back(laCmd);

        currentBlock->cmds.push_back(new ASMBrCondStmtNode("beq", regPool.getReg("t5"), regPool.getReg("t6"), tmpBlock->label));
        auto blockCopy = currentBlock;
        currentBlock = tmpBlock;
        IRUpdReg(IRVar, regPool.getReg("s0"));
        currentBlock->cmds.push_back(new ASMJumpCmdNode(endBlock->label));
        program->textSection->functions.back()->blocks.push_back(tmpBlock);
        currentBlock = blockCopy;
    }

    for (auto la : str2la[currentFunction->name])
    {
        la->name = endBlock->label;
        str2la[endBlock->label].push_back(la);
    }
    str2la[currentFunction->name].clear();
    program->textSection->functions.back()->blocks.push_back(endBlock);
    currentBlock = endBlock;
    storeVar(ASMVar, regPool.getReg("s0"));
}

void ASMBuilder::visitIcmpStmt(IRIcmpStmtNode *node)
{
    auto reg0 = regPool.getReg("s0");//指针传递
    auto reg1 = regPool.getReg("s1");
    IRUpdReg(node->lhs, reg0);
    IRUpdReg(node->rhs, reg1);
    if (node->op == "icmp slt") currentBlock->cmds.push_back(new ASMRegRegCmdNode("slt", reg0, reg0, reg1));
    else if (node->op == "icmp sle")
    {
        currentBlock->cmds.push_back(new ASMRegRegCmdNode("slt", reg0, reg1, reg0));
        currentBlock->cmds.push_back(new ASMImmRegCmdNode("xori", reg0, reg0, 1));
    }
    else if (node->op == "icmp sgt") currentBlock->cmds.push_back(new ASMRegRegCmdNode("slt", reg0, reg1, reg0));
    else if (node->op == "icmp sge")
    {
        currentBlock->cmds.push_back(new ASMRegRegCmdNode("slt", reg0, reg1, reg0));
        currentBlock->cmds.push_back(new ASMImmRegCmdNode("xori", reg0, reg0, 1));
    }
    else if (node->op == "icmp eq")
    {
        currentBlock->cmds.push_back(new ASMRegRegCmdNode("xor", reg0, reg0, reg1));
        currentBlock->cmds.push_back(new ASMImmRegCmdNode("sltiu", reg0, reg0, 1));
    }
    else if (node->op == "icmp ne")
    {
        currentBlock->cmds.push_back(new ASMRegRegCmdNode("xor", reg0, reg0, reg1));
        currentBlock->cmds.push_back(new ASMRegRegCmdNode("sltu", reg0, regPool.getReg("zero"), reg0));
    }
    else throw std::runtime_error("unknown icmp op");
    auto res = registerLocalVar(node->var, false);
    storeVar(res, reg0);
}

void ASMBuilder::visitZeroExtendStmt(IRZeroExtendStmtNode *node)
{
    IRUpdReg(node->value, regPool.getReg("s0"));
    auto ASMVar = registerLocalVar(node->var, false);
    storePtr(ASMVar, regPool.getReg("s0"));
}

void ASMBuilder::visitBinaryStmt(IRBinaryStmtNode *node)
{
    auto reg0 = regPool.getReg("s0");
    auto reg1 = regPool.getReg("s1");
    IRUpdReg(node->lhs, reg0);
    IRUpdReg(node->rhs, reg1);
    string op = node->op;
    if (op == "sdiv") op = "div";
    else if (op == "srem") op = "rem";
    else if (op == "shl") op = "sll";
    else if (op == "ashr") op = "sra";

    currentBlock->cmds.push_back(new ASMRegRegCmdNode(op, reg0, reg0, reg1));
    auto res = registerLocalVar(node->var, false);
    storeVar(res, reg0);
}

void ASMBuilder::visitGetElementPtrStmt(IRGetElementPtrStmtNode *node)
{
    auto left = registerLocalVar(node->var, true);
    auto right = varMap[node->ptr->name];
    ASMVarUpdReg(right, regPool.getReg("s0"));
    IRUpdReg(node->index, regPool.getReg("s1"));
    auto size = new ASMImmRegCmdNode("addi", regPool.getReg("t1"), regPool.getReg("zero"), node->var->type->size());
    auto mul = new ASMRegRegCmdNode("mul", regPool.getReg("s1"), regPool.getReg("s1"), regPool.getReg("t1"));
    auto add = new ASMRegRegCmdNode("add", regPool.getReg("s0"), regPool.getReg("s0"), regPool.getReg("s1"));
    storeVar(left, regPool.getReg("s0"));
    currentBlock->cmds.push_back(size), currentBlock->cmds.push_back(mul), currentBlock->cmds.push_back(add);
}


