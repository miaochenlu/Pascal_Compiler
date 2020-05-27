//
// Created by lianjiayi on 20-5-25.
//

#ifndef PASCAL_COMPILER_GENLABELENV_H
#define PASCAL_COMPILER_GENLABELENV_H


#include <llvm/IR/BasicBlock.h>

#include <string>
#include <vector>
#include <map>

class GenLabelEnv {
public:
    void popLayer();
    void pushLayer();
    llvm::BasicBlock * getLabel(int name);
    bool setLabel(int name, llvm::BasicBlock *label);

private:
    std::vector <std::map<int, llvm::BasicBlock*>> labelStack;


};

#endif //PASCAL_COMPILER_GENLABELENV_H
