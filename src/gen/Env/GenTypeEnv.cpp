//
// Created by lianjiayi on 20-5-25.
//

#include "GenTypeEnv.h"

void GenTypeEnv::popLayer()
{
    if(typeStack.empty())
        typeStack.pop_back();
}

void GenTypeEnv::pushLayer()
{
    typeStack.emplace_back();
}

llvm::Type* GenTypeEnv::getType(std::string name)
{
    for(auto it = typeStack.rbegin(); it != typeStack.rend(); it++)
    {
        std::map<std::string, llvm::Type*>::iterator type = (*it).find(name);
        if(type != (*it).end())
            return type->second;
    }
    //throw: cannot find
}

bool GenTypeEnv::setType(std::string name, llvm::Type *type)
{
    if (typeStack.back().find(name) == typeStack.back().end()) {
        (typeStack.back())[name] = type;
        return true;
    } else return false;
}
