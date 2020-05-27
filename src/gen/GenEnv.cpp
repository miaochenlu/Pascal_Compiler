//
// Created by lianjiayi on 20-5-22.
//

#include "GenEnv.h"

llvm::LLVMContext llvmContext;
llvm::Module llvmModule("Module", llvmContext);
llvm::IRBuilder<> irBuilder(llvmContext);

GenEnv genEnv;

GenEnv::GenEnv() {
    pushLayer();
    funcEnv.setSysCall();
}

void GenEnv::popLayer() {
    funcEnv.popLayer();
    typeEnv.popLayer();
    valueEnv.popLayer();
    labelEnv.popLayer();
}

void GenEnv::pushLayer() {
    funcEnv.pushLayer();
    typeEnv.pushLayer();
    valueEnv.pushLayer();
    labelEnv.pushLayer();
}