//
// Created by lianjiayi on 20-5-25.
//

#ifndef PASCAL_COMPILER_GENTYPEENV_H
#define PASCAL_COMPILER_GENTYPEENV_H

#include <llvm/IR/Type.h>

#include <string>
#include <vector>
#include <map>

class GenTypeEnv {
public:
    void popLayer();
    void pushLayer();
    llvm::Type * getType(std::string name);
    bool setType(std::string name, llvm::Type *type);

private:
    std::vector <std::map<std::string, llvm::Type*>> typeStack;


};


#endif //PASCAL_COMPILER_GENTYPEENV_H
