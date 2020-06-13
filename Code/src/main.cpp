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

enum class Target {
    LLVM,
    ASM,
    OBJ,
    OUT,
    FALSE,
};

Target targetType;
string outname;
string inputname;

bool arg(int argc, char**argv) {
    targetType = Target::FALSE;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0) {
            if (targetType == Target::FALSE) targetType = Target ::LLVM;
            else return false;
        }
        else if (strcmp(argv[i], "-s") == 0) {
            if (targetType == Target::FALSE) targetType = Target ::ASM;
            else return false;
        }
        else if (strcmp(argv[i], "-c") == 0) {
            if (targetType == Target::FALSE) targetType = Target ::OBJ;
            else return false;
        }
        else if (strcmp(argv[i], "-o") == 0) {
            if (i+1 >= argc) return false;
            else if (outname.empty()) outname = argv[i+1], i++;
            else return false;
        }
        else if(inputname.empty()) inputname = argv[i];
        else return false;

    }
    if (inputname.empty()) return false;
    if (outname.empty()) outname = "out";
    if (targetType == Target::FALSE) targetType = Target ::OUT;

    return true;
}

void printUse() {
    printf("Pascal_Compiler [-l/-s/-c] [-o outfile] sourcefile\n");
    printf("    [-l/-s/-c] : file type\n");
    printf("        -l : llvm IR code\n");
    printf("        -s : assembly language\n");
    printf("        -c : native object file\n");
    printf("    [-o outfile] : Rename output file\n");
}

void outasm() {
    string temp =outname + ".ll";
    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "fail to fork another process, errno: " << errno << std::endl;
        return;
    } else if (pid == 0) {
        execlp("llc", "llc", "-relocation-model=pic", "-filetype=asm", temp.c_str(), "-o", outname.c_str(), NULL);
        std::cerr << "fail to execute llc, errno: " << errno << std::endl;
        exit(1);
    }
    else {
        int stat;
        wait(&stat);
        if (WEXITSTATUS(stat)) {
            std::cerr << "llc child process execution failure" << std::endl;
            remove(temp.c_str());
            return;
        }
    }
    remove(temp.c_str());

}
void outobj() {
    string temp =outname + ".ll";
    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "fail to fork another process, errno: " << errno << std::endl;
        return;
    } else if (pid == 0) {
        execlp("llc", "llc", "-relocation-model=pic", "-filetype=obj", temp.c_str(), "-o", outname.c_str(), NULL);
        std::cerr << "fail to execute llc, errno: " << errno << std::endl;
        exit(1);
    }
    else {
        int stat;
        wait(&stat);
        if (WEXITSTATUS(stat)) {
            std::cerr << "llc child process execution failure" << std::endl;
            remove(temp.c_str());
            return;
        }
    }
    remove(temp.c_str());
}

void outout() {
    string temp = outname+".ll";
    string temps = outname + ".s";

    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "fail to fork another process, errno: " << errno << std::endl;
        return ;
    } else if (pid == 0) {
        execlp("llc", "llc", "-relocation-model=pic", temp.c_str(), "-o", temps.c_str(), NULL);
        std::cerr << "fail to execute llc, errno: " << errno << std::endl;
        exit(1);
    } else {
        int stat;
        wait(&stat);
        if (WEXITSTATUS(stat)) {
            std::cerr << "llc child process execution failure" << std::endl;
            remove(temp.c_str());
            return;
        }
    }

    pid = fork();
    if (pid < 0) {
        std::cerr << "fail to fork another process, errno: " << errno << std::endl;
        return ;
    } else if (pid == 0) {
        execlp("gcc", "gcc", "-o", outname.c_str(), temps.c_str(), "-lm", NULL);
        std::cerr << "fail to execute gcc, errno: " << errno << std::endl;
        exit(1);
    } else {
        int stat;
        wait(&stat);
        if (WEXITSTATUS(stat)) {
            std::cerr << "llc child process execution failure" << std::endl;
            remove(temp.c_str());
            remove(temps.c_str());
            return;
        }
    }
    remove(temp.c_str());
    remove(temps.c_str());
}

int main(int argc, char** argv) {
    if (!arg(argc, argv)) {
        printUse();
        return 0;
    }
    yyin = fopen(inputname.c_str(), "r");
    if (yyin == NULL) {
        printf("File does not exists.\n");
        exit(0);
    }

    cout << "---------------------------------------------------------------------------" <<endl;
    cout << "Scanning and Parsering" <<endl;
    cout << "---------------------------------------------------------------------------" <<endl;
	ast::BasicAstNode* tree = parse();
    ast::astTraversal(tree, 0);

    cout << "---------------------------------------------------------------------------" <<endl;
    cout << "Syntax Analyse" <<endl;
    cout << "---------------------------------------------------------------------------" <<endl;
    buildSymTable(tree);
    typeCheck(tree);
    ((ast::Program*)tree)->codeGen();

    cout << "---------------------------------------------------------------------------" <<endl;
    cout << "Code Generation" <<endl;
    cout << "---------------------------------------------------------------------------" <<endl;

    string outputllvm = outname+ ".ll";
    std::error_code error;
    llvm::raw_fd_ostream out(outputllvm, error, llvm::sys::fs::F_None);
    llvmModule.print(out, nullptr);
    if(targetType == Target::LLVM) {
        rename(outputllvm.c_str(), outname.c_str());
        return 0;
    } else if(targetType == Target::ASM) {
        outasm();
    }
    else if(targetType == Target::OBJ) {
        outobj();
    }
    else outout();

	return 0;
}
