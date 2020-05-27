#include <iostream>
#include <llvm/Support/FileSystem.h>
#include "ast/ast.h"
#include "parser.hpp"
#include "gen/GenEnv.h"

using namespace std;


extern int yyparse();
extern ast::BasicAstNode* parse(void);
extern FILE * yyin;


int main(int argc, char** argv) {
    //yyin = fopen(argv[1], "r");
    yyin = fopen("../../test/stmtTest.pascal", "r");
    if (yyin == NULL) {
        printf("File does not exists.\n");
        exit(0);
    }
	ast::BasicAstNode* tree = parse();
    ast::astTraversal(tree, 0);
    ((ast::Program*)tree)->codeGen();
    std::string output = "../../test/stmtTset";
    output = output.append(".ll");
    std::error_code error;
    llvm::raw_fd_ostream out(output, error, llvm::sys::fs::F_None);
    llvmModule.print(out, nullptr);

	return 0;
}
