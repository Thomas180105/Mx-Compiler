#include "ASTNode.h"
#include "ASTBuilder.h"
#include "MxErrorListener.h"
#include "Scope.h"
#include "SymbolCollector.h"
#include "SemanticChecker.h"
#include "MxLexer.h"
using std::cerr;

ASTNode* getAST(std::istream &in = std::cin) {
    std::cerr << "in getAST, stop1" << std::endl;
    antlr4::ANTLRInputStream input(in);
    MxErrorListener errorListener;

    std::cerr << "in getAST, stop2" << std::endl;
    MxLexer lexer(&input);
    std::cerr << "in getAST, stop2.1" << std::endl;
    lexer.removeErrorListeners();
    std::cerr << "in getAST, stop2.2" << std::endl;
    lexer.addErrorListener(&errorListener);
    std::cerr << "in getAST, stop2.3" << std::endl;
    antlr4::CommonTokenStream tokens(&lexer);
    std::cerr << "in getAST, stop2.4" << std::endl;
    MxParser parser(&tokens);
    std::cerr << "in getAST, stop2.5" << std::endl;
    parser.removeErrorListeners();
    std::cerr << "in getAST, stop2.6" << std::endl;
    parser.addErrorListener(&errorListener);

    std::cerr << "in getAST, stop3" << std::endl;

    auto tree = parser.program();

    std::cerr << "in getAST, stop4" << std::endl;
    ASTBuilder builder;
    auto visit_result = builder.visit(tree);
    std::cerr << "in getAST, stop5" << std::endl;
    if (!visit_result.has_value())
    {
        throw std::runtime_error("AST build failed");
    }
    return std::any_cast<ASTNode *>(visit_result);
}

void printFileContext(std::fstream &in)
{
    std::cerr << "file output begin" << std::endl;
    if (!in) {
        std::cerr << "无法打开文件" << std::endl;
    }

    std::string line;
    while (std::getline(in, line)) {
        std::cerr << line << std::endl;
    }
//    in.close();
    in.seekg(0);
    std::cerr << "file output end" << std::endl;
}
int main(int argc, char const *argv[]) {
    std::cerr << "stop1" << std::endl;
    vector<string> files;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') files.push_back(argv[i]);
    }
    std::cerr << "stop2" << std::endl;
    try {
        AST ast;
        std::cerr << "stop2.1" << std::endl;
        if (files.empty())
        {
            std::cerr << "stop2.2" << std::endl;
            ast.root = getAST();
            std::cerr << "stop2.3" << std::endl;
        }
        else
        {
            std::cerr << "stop2.4" << std::endl;
            std::ifstream in(files[0]);
//            std::fstream in(files[0]);
//            printFileContext(in);
            if (in.good())
                std::cerr << "stop2.5" << std::endl;
            ast.root = getAST(in);
            std::cerr << "stop2.6" << std::endl;
            in.close();
            std::cerr << "stop2.7" << std::endl;
        }
        std::cerr << "stop3" << std::endl;
        GlobalScope globalscope(nullptr);

        ClassScanner classsanner(&globalscope);
        classsanner.builtInInit();
        classsanner.visit(ast.root);

        std::cerr << "stop4" << std::endl;

        FunctionScanner functionscanner(&globalscope);
        functionscanner.builtInInit();
        functionscanner.visit(ast.root);

        std::cerr << "stop5" << std::endl;

        SemanticChecker semanticchecker(&globalscope);
        semanticchecker.visit(ast.root);

        std::cerr << "stop6" << std::endl;

        for (int i = 1; i < argc; ++i) {
            if (std::string(argv[i]) == "-fsyntax-only") return 0;
        }

        std::cerr << "stop7" << std::endl;
    }
    catch (std::exception &err) {
        std::cerr << "got here!" << std::endl;
        cerr << err.what() << '\n';
        return 1;
    }
    return 0;
}