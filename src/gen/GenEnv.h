//
// Created by lianjiayi on 20-5-22.
//

#ifndef PASCAL_COMPILER_GENENV_H
#define PASCAL_COMPILER_GENENV_H

#include "gen/Env/GenFuncEnv.h"
#include "gen/Env/GenValueEnv.h"

class GenEnv
{
public:
    GenFuncEnv funcEnv;
    GenValueEnv valueEnv;
};


#endif //PASCAL_COMPILER_GENENV_H
