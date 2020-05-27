//
// Created by lianjiayi on 20-5-25.
//

#ifndef PASCAL_COMPILER_GENLLVMCONSTANT_H
#define PASCAL_COMPILER_GENLLVMCONSTANT_H
#include <llvm/IR/Value.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>

namespace ast
{
    /****************** const ***********************/
    class BasicConst;
    class IntegerNode;
    class RealNode;
    class CharNode;
    class StringNode;
    class BooleanNode;
    class MaxIntNode;
}

namespace gen
{
    llvm::Value *getLLVMConstant(ast::BasicConst* node);
    llvm::Constant *getLLVMConstINT(int value);
    llvm::Constant *getLLVMConstBOOL(bool value);
    llvm::Constant *getLLVMConstREAL(double value);
    llvm::Constant *getLLVMConstCHAR(char value);
    //llvm::Value *getLLVMConstARRAY(int value);
    llvm::Value *getLLVMConstSTRING(std::string value);
    //llvm::Value *getLLVMConstRECORD(int value);

}



#endif //PASCAL_COMPILER_GENLLVMCONSTANT_H
