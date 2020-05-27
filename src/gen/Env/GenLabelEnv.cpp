//
// Created by lianjiayi on 20-5-25.
//

#include "GenLabelEnv.h"

void GenLabelEnv::popLayer()
{
    if(labelStack.empty())
        labelStack.pop_back();
}

void GenLabelEnv::pushLayer()
{
    labelStack.emplace_back();
}

llvm::BasicBlock* GenLabelEnv::getLabel(int name){
    for(auto it = labelStack.rbegin(); it != labelStack.rend(); it++)
    {
        std::map<int, llvm::BasicBlock*>::iterator label = (*it).find(name);
        if(label != (*it).end())
            return label->second;
    }
    //throw: cannot find
}

bool GenLabelEnv::setLabel(int name, llvm::BasicBlock *label) {
    if (labelStack.back().find(name) == labelStack.back().end()) {
        (labelStack.back())[name] = label;
        return true;
    } else return false;
}
