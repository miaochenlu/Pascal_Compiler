//
// Created by lianjiayi on 20-5-22.
//

#include "GenValueEnv.h"

void GenValueEnv::popLayer()
{
    if(valStack.empty())
        valStack.pop_back();
}

void GenValueEnv::pushLayer()
{
    valStack.emplace_back();
}

llvm::Value* GenValueEnv::getValue(std::string name)
{
    for(auto it = valStack.rbegin(); it != valStack.rend(); it++)
    {
        std::map<std::string, llvm::Value*>::iterator val = (*it).find(name);
        if(val != (*it).end())
            return val->second;
    }
    //throw: cannot find
}

bool GenValueEnv::setValue(std::string name, llvm::Value *value)
{
    if(valStack.back().find(name) == valStack.back().end()) {
        (valStack.back())[name] = value;
        return true;
    }
    else return false;
}

bool GenValueEnv::isGlobal() {
    return valStack.size() == 1;
}
