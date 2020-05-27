//
// Created by lianjiayi on 20-5-25.
//

#include "GenLLVMType.h"
#include "ast/ast.h"
#include "gen/GenEnv.h"

namespace gen{

    llvm::Type* getLLVMArray(ast::ArrayType *Type)
    {
        int lowb =  ((ast::IntegerNode*)((ast::RangeType*)Type->range)->lowerB)->integerVal;
        int upb =  ((ast::IntegerNode*)((ast::RangeType*)Type->range)->upperB)->integerVal;
        int size = upb-lowb;
        return llvm::ArrayType::get(getLLVMType(Type->elementType), (uint64_t) size);
    }

    llvm::Type* getLLVMRecord(ast::RecordType* type)
    {
        std::vector<llvm::Type*> typeVector;
        for(auto field : *type->fieldList) {
            typeVector.emplace_back(getLLVMType(field->type));
        }
        return llvm::StructType::get(llvmContext,typeVector);
    }

    llvm::Type* getLLVMType(ast::BasicType *type)
    {
        switch(type->type)
        {
            case ast::TypeKind::BOOLEANtype:
                return llvm::Type::getInt1Ty(llvmContext);
            case ast::TypeKind::INTtype:
                return llvm::Type::getInt32Ty(llvmContext);
            case ast::TypeKind::REALtype:
                return llvm::Type::getDoubleTy(llvmContext);
            case ast::TypeKind::VOIDtype:
                return llvm::Type::getVoidTy(llvmContext);
            case ast::TypeKind::CHARtype:
                return llvm::Type::getInt8Ty(llvmContext);
            case ast::TypeKind::ARRAYtype:
                return getLLVMArray((ast::ArrayType*)type);
            case ast::TypeKind::STRINGtype:
                return llvm::ArrayType::get(llvm::Type::getInt8Ty(llvmContext), (uint64_t) 255);
            case ast::TypeKind::RECORDtype:
                return getLLVMRecord((ast::RecordType*) type);
            case ast::TypeKind::USERDEFtype:
                return genEnv.getTypeEnv().getType(((ast::UserDefType*)type)->typeName->name);
            default:
                return llvm::Type::getVoidTy(llvmContext);
        }
    }



}