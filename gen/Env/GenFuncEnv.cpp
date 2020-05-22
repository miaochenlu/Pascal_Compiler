//
// Created by lianjiayi on 20-5-22.
//

#include "GenFuncEnv.h"

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
        std::map<char,int>::iterator fun = it.find(name);
        if(fun != it.end())
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
