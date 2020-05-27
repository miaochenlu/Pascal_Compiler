//
// Created by lianjiayi on 20-5-25.
//

#include "GenLLVMConstant.h"
#include "ast/ast.h"
#include "gen/GenEnv.h"

namespace gen
{

    llvm::Value*getLLVMConstant(ast::BasicConst* node)
    {
        switch (node->type) {
            case ast::TypeKind::BOOLEANtype:
                return getLLVMConstBOOL(((ast::BooleanNode *)node)->boolVal);
            case ast::TypeKind::INTtype:
                return getLLVMConstINT(((ast::IntegerNode *)node)->integerVal);
            case ast::TypeKind::REALtype:
                return getLLVMConstREAL(((ast::RealNode *)node)->realVal);
            case ast::TypeKind::CHARtype:
                return getLLVMConstCHAR(((ast::CharNode *)node)->charVal);
            case ast::TypeKind::STRINGtype:
                return getLLVMConstSTRING(((ast::StringNode *)node)->stringVal);
            default:
                return nullptr;
        }
    }

    llvm::Constant*getLLVMConstINT(int value) {
        return llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvmContext), (uint64_t) value, true);
    }

    llvm::Constant*getLLVMConstBOOL(bool value) {
        return llvm::ConstantInt::get(llvm::Type::getInt1Ty(llvmContext), (uint64_t) value, true);
    }

    llvm::Constant*getLLVMConstREAL(double value) {
        return llvm::ConstantFP::get(llvm::Type::getDoubleTy(llvmContext), value);
    }

    llvm::Constant*getLLVMConstCHAR(char value) {
        return llvm::ConstantInt::get(llvm::Type::getInt8Ty(llvmContext), (uint64_t) value, true);
    }

    llvm::Value*getLLVMConstSTRING(std::string value) {
        while(value.length() < 254) value+=" " ;
        if(value.length()>254) value=value.substr(0,253);
        return irBuilder.CreateLoad(irBuilder.CreateGlobalString(value));
    }
}
