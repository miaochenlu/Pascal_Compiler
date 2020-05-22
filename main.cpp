#include <iostream>
#include "ast/ast.h"
#include "parser.hpp"

using namespace std;

extern int yyparse();
extern ast::BasicAstNode* parse(void);
extern FILE * yyin;


int main(int argc, char** argv) {
    yyin = fopen("test/demo1.pascal", "r");
    if (yyin == NULL) {
        printf("File does not exists.\n");
        exit(0);
    }
	ast::BasicAstNode* tree = parse();
    ast::astTraversal(tree, 0);
	return 0;
}
