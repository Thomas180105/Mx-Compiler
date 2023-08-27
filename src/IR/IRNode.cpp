#include "IRNode.h"

string IRProgramNode::to_string()
{
    string res;
    for (auto g : globalVarStmts) res += g->to_string() + '\n';
    res += '\n';
    for (auto f : functions) res += f->to_string() + '\n';
    return res;
}

//have '\n' in the end
string IRFunctionNode::to_string()
{
    string res;
    res += (blocks.empty() ? "declare " : "define ");
    res += retType->to_string() + " @" + name + '(';
    int s = args.size();
    for (int i = 0; i < s - 1; ++i) res += args[i].first->to_string() + " %" + args[i].second + ", ";
    if (s) res += args[s - 1].first->to_string() + " %" + args[s - 1].second;
    res += ")\n";
    if (blocks.empty()) return res;
    res += "{\n";
    for (auto b : blocks) res += b->to_string() + '\n';
    res += "}\n";
    return res;
}

//no '\n' in the end
string IRGlobalVarStmtNode::to_string()
{
    return var->to_string() + " = global " + value->type->to_string() + " " + value->to_string();
}

string IRVarNode::to_string()
{
    return "%" + name;
}

string IRGlobalVarNode::to_string()
{
    return "@" + name;
}

string IRLiteralNode::to_string()
{
    if (type->to_string() == "i1") return (value ? "true" : "false");
    else if (type->to_string() == "i32") return std::to_string(value);
    else if (type->to_string() == "ptr") return "null";
    return "";//exception
}

string IRStringNode::to_string()
{
    //"hello!\n\\\""  转化为  c"hello!\0A\\\22\00"
    string res = "c\"";
    for (auto c : str)
    {
        if (c == '\n') res += "\\0A";
        else if (c == '\\') res += "\\\\";
        else if (c == '\"') res += "\\22";
        else res += c;
    }
    res += "\\00\"";//C风格字符串以'\00'结尾
    return res;
}

string IRSuiteNode::to_string()
{
    string res = label + ":\n";
    for (auto s : stmts) res += "   " + s->to_string() + '\n';
    return res;
}

string IRCallStmtNode::to_string()
{
    //%result = call i32 @foo1(i32 %arg1)
    string str;
    if (res) str += res->to_string() + " = ";\
    string resType = res ? res->type->to_string() : "void";
    str += "call " + resType + " @" + funcName + '(';
    int s = args.size();
    for (int i = 0; i < s - 1; ++i) str += args[i]->type->to_string() + " " + args[i]->to_string() + ", ";
    if (s) str += args[s - 1]->type->to_string() + " " + args[s - 1]->to_string();
    str += ')';
    return str;
}

string IRAllocaStmtNode::to_string()
{
    //%a = alloca i32
    return var->to_string() + " = alloca " + type->to_string();
}

string IRStoreStmtNode::to_string()
{
    //store i32 %0, ptr @i
    return "store " + value->type->to_string() + " " + value->to_string() + ", " + pointer->type->to_string() + " " + pointer->to_string();
}

string IRBrStmtNode::to_string()
{
    //br label %condition_end_0
    return "br label %" + destinationLabel;
}

string IRBrCondStmtNode::to_string()
{
    //br i1 %a.val.1, label %true_0, label %false_
    return "br i1 " + condition->to_string() + ", label %" + trueLabel + ", label %" + falseLabel;
}

string IRRetStmtNode::to_string()
{
    //ret i32 %a
    return "ret " + (var ? var->type->to_string() + " " + var->to_string() : "void");
}

string IRLoadStmtNode::to_string()
{
    //%b.val.2 = load i32, ptr %b
    return var->to_string() + " = load " + var->type->to_string() + ", " + pointer->type->to_string() + " " + pointer->to_string();
}

string IRTruncateStmtNode::to_string()
{
    return var->to_string() + " = trunc " + value->type->to_string() + " " + value->to_string() + " to " + var->type->to_string();
}

string IRPhiStmtNode::to_string()
{
    //%tmp.0 = phi i32 [ %add1, %if.end ], [ 0, %entry ]
    string res =  var->to_string() + " = phi " + var->type->to_string() + " ";
    int s = pairs.size();
    for (int i = 0; i < s - 1; ++i) res += "[ " + pairs[i].first->to_string() + ", %" + pairs[i].second + " ], ";
    if (s) res += "[ " + pairs[s - 1].first->to_string() + ", %" + pairs[s - 1].second + " ]";
    return res;
}

string IRIcmpStmtNode::to_string()
{
    //%cmp = icmp eq ptr %a, null
    return var->to_string() + " = " + op + " " + lhs->type->to_string() + " " + lhs->to_string() + ", " + rhs->to_string();
}

string IRBinaryStmtNode::to_string()
{
    return var->to_string() + " = " + op + " " + lhs->type->to_string() + " " + lhs->to_string() + ", " + rhs->to_string();
}

string IRZeroExtendStmtNode::to_string()
{
    return var->to_string() + " = zext " + value->type->to_string() + " " + value->to_string() + " to " + var->type->to_string();
}

std::string IRGetElementPtrStmtNode::to_string()
{
    //%t1 = getelementptr %struct.ST, ptr %s, i32 1
    return var->to_string() + " = getelementptr " + type->to_string() + ", ptr" + ptr->to_string() + ", i32" + index->to_string();
}
