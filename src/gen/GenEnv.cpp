//
// Created by lianjiayi on 20-5-22.
//

#include "GenEnv.h"

llvm::LLVMContext llvmContext;
llvm::Module llvmModule("Module", llvmContext);
llvm::IRBuilder<> irBuilder(llvmContext);

GenEnv genEnv;