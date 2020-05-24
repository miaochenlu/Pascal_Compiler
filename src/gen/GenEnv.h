//
// Created by lianjiayi on 20-5-22.
//

#ifndef PASCAL_COMPILER_GENENV_H
#define PASCAL_COMPILER_GENENV_H
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include "Env/GenFuncEnv.h"
#include "Env/GenValueEnv.h"

class GenEnv
{
public:
    GenFuncEnv funcEnv;
    GenValueEnv valueEnv;
};

extern llvm::LLVMContext llvmContext;
extern llvm::Module llvmModule;
extern llvm::IRBuilder<> irBuilder;


#endif //PASCAL_COMPILER_GENENV_H
