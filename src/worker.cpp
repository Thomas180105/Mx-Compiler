#include "ASTNode.h"
#include "ASTBuilder.h"
#include "MxErrorListener.h"
#include "Scope.h"
#include "SymbolCollector.h"
#include "SemanticChecker.h"
#include "MxLexer.h"
#include "IRBuilder.h"
#include "ASMBuilder.h"
//#include
using std::cerr;

ASTNode* getAST(std::istream &in = std::cin) {
    antlr4::ANTLRInputStream input(in);
    MxErrorListener errorListener;

    MxLexer lexer(&input);
    lexer.removeErrorListeners();
    lexer.addErrorListener(&errorListener);
    antlr4::CommonTokenStream tokens(&lexer);
    MxParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListener);

    auto tree = parser.program();
    ASTBuilder builder;
    auto visit_result = builder.visit(tree);
    if (!visit_result.has_value())
    {
        throw std::runtime_error("AST build failed");
    }
//    std::cerr << "in getAST, we get a ASTTree, now to return" << std::endl;
//    std::cerr << std::any_cast<ASTProgramNode *>(&visit_result) << '\n';
    return std::any_cast<ASTNode *>(visit_result);
}

int main(int argc, char const *argv[]) {
    vector<string> files;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') files.push_back(argv[i]);
    }
    try {
        AST ast;
        if (files.empty())
        {
            ast.root = getAST();
        }
        else
        {
//            std::cerr << "stop2.4" << std::endl;
            std::ifstream in(files[0]);
            if (in.good())
//                std::cerr << "stop2.5" << std::endl;
            ast.root = getAST(in);
//            std::cerr << "stop2.6" << std::endl;
            in.close();
//            std::cerr << "stop2.7" << std::endl;
        }

//        std::cerr << "in worker.cpp, we get a ASTTree successfully" << std::endl;

//        std::cerr << "stop3" << std::endl;
        GlobalScope globalscope(nullptr);
        globalscope.setName(".0");
        ClassScanner classsanner(&globalscope);
        classsanner.builtInInit();
        classsanner.visit(ast.root);

//        std::cerr << "stop4" << std::endl;

        FunctionScanner functionscanner(&globalscope);
        functionscanner.builtInInit();
//        std::cerr<<"the ast.root is "<<ast.root<<std::endl;
        functionscanner.visit(ast.root);

//        std::cerr << "stop5" << std::endl;

        SemanticChecker semanticchecker(&globalscope);
//        std::cerr << "stop5.5" << std::endl;
        semanticchecker.visit(ast.root);

//        std::cerr << "stop6" << std::endl;

        for (int i = 1; i < argc; ++i) {
            if (std::string(argv[i]) == "-fsyntax-only") return 0;
        }

//        std::cerr << "stop7" << std::endl;

        IRBuilder irbuilder;
//        std::cerr << "get there *1\n";
        irbuilder.visit(ast.root);
//        std::cerr << "get there *2\n";
//        irbuilder.print();

        ASMBuilder asmBuilder;
        asmBuilder.visit(irbuilder.root());
        std::cerr<<"get there *3\n";
        asmBuilder.print();
        std::cerr<<"get there *4\n";
    }
    catch (std::exception &err) {
        std::cerr << "in worker.cpp, an error has been thrown : ";
        cerr << err.what() << '\n';
        return 1;
    }

    return 0;
}