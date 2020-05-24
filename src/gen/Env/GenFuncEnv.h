//
// Created by lianjiayi on 20-5-22.
//

#ifndef PASCAL_COMPILER_GENFUNCENV_H
#define PASCAL_COMPILER_GENFUNCENV_H

#include <llvm/IR/Function.h>

#include <string>
#include <vector>
#include <map>

class GenFuncEnv
{
public:
    void popLayer();
    void pushLayer();
    llvm::Function* getFunc(std::string name);
    bool setFunc(std::string name, llvm::Function *func);

private:
    std::vector <std::map<std::string, llvm::Function*>> funcStack;
};



#endif //PASCAL_COMPILER_GENFUNCENV_H
