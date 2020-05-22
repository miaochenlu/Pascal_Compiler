//
// Created by lianjiayi on 20-5-22.
//

#ifndef PASCAL_COMPILER_GENVALUEENV_H
#define PASCAL_COMPILER_GENVALUEENV_H

#include <llvm/IR/Value.h>
#include <string>
#include <vector>
#include <map>

class GenValueEnv
{
public:
    void popLayer();
    void pushLayer();
    llvm::Value* getValue(std::string name);
    bool setValue(std::string name, llvm::Value *value);

private:
    std::vector <std::map<std::string, llvm::Value*>> valStack;
};


#endif //PASCAL_COMPILER_GENVALUEENV_H
