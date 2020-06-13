//
// Created by lianjiayi on 20-5-25.
//

#ifndef PASCAL_COMPILER_GENLLVMTYPE_H
#define PASCAL_COMPILER_GENLLVMTYPE_H

#include <llvm/IR/Value.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>

namespace ast {

/****************** type ************************/
    class BasicType;
    class SimpleType;
    class CharType;
    class IntegerType;
    class RealType;
    class StringType;
    class BooleanType;
    class RangeType;
    class VoidType;
    class UserDefType;
    class ArrayType;
    class RecordType;
}

namespace gen
{
    llvm::Type* getLLVMType(ast::BasicType *type);
    llvm::Type* getLLVMArray(ast::ArrayType* type);
    llvm::Type* getLLVMRecord(ast::RecordType* type);
}




#endif //PASCAL_COMPILER_GENLLVMTYPE_H
