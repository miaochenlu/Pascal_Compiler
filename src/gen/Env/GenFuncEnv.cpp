//
// Created by lianjiayi on 20-5-22.
//

#include <gen/GenEnv.h>
#include "GenFuncEnv.h"

void GenFuncEnv::setABS(){
    std::vector<llvm::Type*> argType = {llvm::Type::getInt32Ty(llvmContext)};
    llvm::FunctionType *funcType = llvm::FunctionType::get(llvm::Type::getInt32Ty(llvmContext), argType, false);
    llvm::Function *func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "abs", &llvmModule);
    func->setCallingConv(llvm::CallingConv::C);
    (funcStack.back())["ABS"] = func;
}

void GenFuncEnv::setSQRT(){
    std::vector<llvm::Type*> argType = {llvm::Type::getDoubleTy(llvmContext)};
    llvm::FunctionType *funcType = llvm::FunctionType::get(llvm::Type::getDoubleTy(llvmContext), argType, false);
    llvm::Function *func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "sqrt", &llvmModule);
    func->setCallingConv(llvm::CallingConv::C);
    (funcStack.back())["SQRT"] = func;
}

void GenFuncEnv::setWRITE() {
    std::vector<llvm::Type *> argType = {llvm::Type::getInt8PtrTy(llvmContext)};
    llvm::FunctionType *funcType = llvm::FunctionType::get(llvm::Type::getInt32Ty(llvmContext), argType, false);
    llvm::Function *func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "printf", &llvmModule);
    func->setCallingConv(llvm::CallingConv::C);
    (funcStack.back())["WRITE"] = func;
}



void GenFuncEnv::setSysCall() {
    setABS();
    setWRITE();
    setSQRT();


}

void GenFuncEnv::popLayer()
{
    if(funcStack.empty())
        funcStack.pop_back();
}

void GenFuncEnv::pushLayer()
{
    funcStack.emplace_back();
}

llvm::Function* GenFuncEnv::getFunc(std::string name)
{
    for(auto it = funcStack.rbegin(); it != funcStack.rend(); it++)
    {
        std::map<std::string, llvm::Function*>::iterator fun = (*it).find(name);
        if(fun != (*it).end())
            return fun->second;
    }
    //throw: cannot find
}

bool GenFuncEnv::setFunc(std::string name, llvm::Function *func)
{
    if (funcStack.back().find(name) == funcStack.back().end()) {
        (funcStack.back())[name] = func;
        return true;
    } else return false;
}
