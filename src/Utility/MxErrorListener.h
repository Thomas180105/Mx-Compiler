#ifndef MXCOMPILER_2023_MXERRORLISTENER_H
#define MXCOMPILER_2023_MXERRORLISTENER_H
//自定义错误处理方式
class MxErrorListener : public antlr4::BaseErrorListener {
    void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line, size_t charPositionInLine,
                     const std::string &msg, std::exception_ptr e) override {
        throw syntax_error{"Error: " + msg};
    }
};
#endif //MXCOMPILER_2023_MXERRORLISTENER_H
