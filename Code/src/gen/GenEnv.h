//
// Created by lianjiayi on 20-5-22.
//

#ifndef PASCAL_COMPILER_GENENV_H
#define PASCAL_COMPILER_GENENV_H
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include "Env/GenFuncEnv.h"
#include "Env/GenValueEnv.h"
#include "Env/GenTypeEnv.h"
#include "Env/GenLabelEnv.h"

class GenEnv
{
public:
    GenEnv();
    void pushLayer();
    void popLayer();
    bool isGlobal()
    {
        return !((bool)isGlobalFlag);
    }
    GenFuncEnv & getFuncEnv(){
        return funcEnv;
    }
    GenValueEnv & getValueEnv(){
        return valueEnv;
    }
    GenTypeEnv & getTypeEnv(){
        return typeEnv;
    }
    GenLabelEnv & getLabelEnv(){
        return labelEnv;
    }

private:
    GenFuncEnv funcEnv;
    GenTypeEnv typeEnv;
    GenValueEnv valueEnv;
    GenLabelEnv labelEnv;
    int isGlobalFlag;

};

extern llvm::LLVMContext llvmContext;
extern llvm::Module llvmModule;
extern llvm::IRBuilder<> irBuilder;
extern GenEnv genEnv;


#endif //PASCAL_COMPILER_GENENV_H
