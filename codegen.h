//
// Created by Sr on 2018/6/12.
//

#ifndef PASCALCOMPLIER_CODEGEN_H
#define PASCALCOMPLIER_CODEGEN_H

#include "assem.h"
#include "frame.h"
#include "tree.h"

AS_instrList F_codegen(F_frame f, T_stmList stmList);

#endif //PASCALCOMPLIER_CODEGEN_H
