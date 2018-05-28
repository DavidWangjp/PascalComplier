//
// Created by DavidWangjp on 2018/5/19.
//

#ifndef PASCALCOMPLIER_SEMANT_H
#define PASCALCOMPLIER_SEMANT_H


#include "types.h"
#include "translate.h"
#include "absyn.h"


struct expty
{
    Tr_exp exp;
    Ty_ty ty;
};


struct expty expTy(Tr_exp exp, Ty_ty ty)
{
    struct expty e;
    e.exp = exp;
    e.ty = ty;
}

struct expty SEM_transProg(A_program a);


#endif //PASCALCOMPLIER_SEMANT_H
