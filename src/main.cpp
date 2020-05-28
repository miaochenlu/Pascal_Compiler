#include <iostream>
#include <llvm/Support/FileSystem.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "ast/ast.h"
#include "parser.hpp"
#include "gen/GenEnv.h"
#include "analyze.h"

using namespace std;


extern int yyparse();
extern ast::BasicAstNode* parse(void);
extern FILE * yyin;


int main(int argc, char** argv) {
    //yyin = fopen(argv[1], "r");
    yyin = fopen("../../test/sysFuncTest.pas", "r");
    if (yyin == NULL) {
        printf("File does not exists.\n");
        exit(0);
    }
	ast::BasicAstNode* tree = parse();
    ast::astTraversal(tree, 0);
    buildSymTable(tree);
    typeCheck(tree);
    cout << "analyse end" <<endl;
    ((ast::Program*)tree)->codeGen();
    std::string output = "../../test/Test";

    output = output.append(".ll");
    std::error_code error;
    llvm::raw_fd_ostream out(output, error, llvm::sys::fs::F_None);
    llvmModule.print(out, nullptr);

    {
        string outname = "../../test/test";
        std::string tmp_file = output + ".s";
        pid_t pid = fork();
        if (pid < 0) {
            std::cerr << "fail to fork another process, errno: " << errno << std::endl;
        } else if (pid == 0) {
            execlp("llc", "llc", "-relocation-model=pic", output.c_str(), "-o", tmp_file.c_str(), NULL);
            std::cerr << "fail to execute llc, errno: " << errno << std::endl;
            exit(1);
        } else {
            int stat;
            wait(&stat);
            if (WEXITSTATUS(stat)) {
                std::cerr << "llc child process execution failure" << std::endl;
                remove(output.c_str());
                remove(tmp_file.c_str());
                cout << "error" << endl;
            }
        }

        pid = fork();
        if (pid < 0) {
            std::cerr << "fail to fork another process, errno: " << errno << std::endl;
        } else if (pid == 0) {
            execlp("gcc", "gcc", "-o", outname.c_str(), tmp_file.c_str(), "-lm", NULL);
            std::cerr << "fail to execute gcc, errno: " << errno << std::endl;
            exit(1);
        } else {
            int stat;
            wait(&stat);
            if (WEXITSTATUS(stat)) {
                std::cerr << "gcc child process execution failure" << std::endl;
                remove(output.c_str());
                remove(tmp_file.c_str());
                remove(outname.c_str());
                cout << "error" << endl;
            }
        }
    }
	return 0;
}
