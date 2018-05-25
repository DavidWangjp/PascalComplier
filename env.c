//
// Created by DavidWangjp on 2018/5/18.
//

#include "env.h"


/*
 * predefined type
 */
S_table E_base_tenv(void)
{
    S_table type_base_table = S_empty();
    S_enter(type_base_table, S_Symbol("int"), Ty_Int());
    S_enter(type_base_table, S_Symbol("real"), Ty_Real());
    S_enter(type_base_table, S_Symbol("bool"), Ty_Bool());
    S_enter(type_base_table, S_Symbol("char"), Ty_Char());
    return type_base_table;
}

/*
 * predefined value identifier, whether a variable or function
 */
E_enventry E_VarEntry(Tr_access access, Ty_ty ty)
{
    E_enventry p = checked_malloc(sizeof((*p)));
    p->kind = E_enventry_::E_varEntry;
    p->u.var.access = access;
    p->u.var.ty = ty;
    return p;
}

E_enventry E_FunEntry(Tr_level level, Temp_label label, Ty_tyList formals, Ty_ty result)
{
    E_enventry p = checked_malloc(sizeof((*p)));
    p->kind = E_enventry_::E_funEntry;
    p->u.fun.level = level;
    p->u.fun.label = label;
    p->u.fun.formals = formals;
    p->u.fun.result = result;
    return p;
}

S_table E_base_venv(void)
{
    S_table value_base_table = S_empty();

    S_enter(value_base_table, S_Symbol("false"),
            E_VarEntry(Tr_AllocLocal(Tr_outermost(), FALSE, BOOL_SIZE), Ty_Bool()));
    S_enter(value_base_table, S_Symbol("true"),
            E_VarEntry(Tr_AllocLocal(Tr_outermost(), FALSE, BOOL_SIZE) , Ty_Bool()));
    S_enter(value_base_table, S_Symbol("maxint"),
            E_VarEntry(Tr_AllocLocal(Tr_outermost(), FALSE, INT_SIZE), Ty_Int()));

//    S_enter(value_base_table, S_Symbol("writeln"), E_FunEntry(Ty_TyList(Ty_Const_String(), NULL), NULL));
    return value_base_table;
}



