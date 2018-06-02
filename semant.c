//
// Created by DavidWangjp on 2018/5/19.
//

/*
 * 所有变量作为逃逸变量处理，所有常量是非逃逸变量
 * 忽略枚举和子界类型
 * 字符串类型常量没有处理
 */

#include "semant.h"
#include "env.h"
#include "errormsg.h"
#include "escape.h"
#include "absyn.h"


struct expty expTy(Tr_exp exp, Ty_ty ty)
{
    struct expty e;
    e.exp = exp;
    e.ty = ty;
    return e;
}

typedef struct A_var_ *A_var;

struct A_var_
{
    A_pos pos;
    enum
    {
        A_SIMPLE, A_ARRAY, A_RECORD
    } kind;
    union
    {
        S_symbol simple;
        struct
        {
            S_symbol array;
            A_expression subscript;
        } array;
        struct
        {
            S_symbol record;
            S_symbol field;
        } record;
    } u;
};

A_var A_Simple(A_pos pos, S_symbol s)
{
    A_var simple = checked_malloc(sizeof(*simple));
    simple->pos = pos;
    simple->kind = A_SIMPLE;
    simple->u.simple = s;
    return simple;
}

A_var A_Array(A_pos pos, S_symbol s, A_expression a)
{
    A_var array = checked_malloc(sizeof(*array));
    array->pos = pos;
    array->kind = A_ARRAY;
    array->u.array.array = s;
    array->u.array.subscript = a;
    return array;
}

A_var A_Record(A_pos pos, S_symbol s, S_symbol f)
{
    A_var record = checked_malloc(sizeof(*record));
    record->pos = pos;
    record->kind = A_RECORD;
    record->u.record.record = s;
    record->u.record.field = f;
    return record;
}

struct expty transProgram(S_table venv, S_table tenv, A_program a);

struct expty transRoutine(S_table venv, S_table tenv, A_routine a);

void transRoutineHead(S_table escenv, S_table venv, S_table tenv, A_routine_head a, Tr_level level);

struct expty transRoutineBody(Tr_level level, S_table venv, S_table tenv, A_routine_body a);

Ty_ty transTy(Tr_level level, S_table venv, S_table tenv, A_type_decl a);

void transConstDec(Tr_level level, S_table venv, A_const_part a);

void transTypeDec(Tr_level level, S_table venv, S_table tenv, A_type_part a);

void transVarDec(S_table escenv, S_table venv, S_table tenv, A_var_part a, Tr_level level);

void transRoutineDec(Tr_level level, S_table venv, S_table tenv, A_routine_part a);

struct expty transStm(Tr_level level, S_table venv, S_table tenv, A_stmt a);

struct expty transStms(Tr_level level, S_table venv, S_table tenv, A_stmt_list stmts);

struct expty transVar(Tr_level level, S_table venv, S_table tenv, A_var a);

struct expty transConst(A_const_value a);

struct expty transExp(Tr_level level, S_table venv, S_table tenv, A_expression a);


/***************************** Implementations start *****************************/

Ty_ty actual_ty(Ty_ty ty)
{
    if (ty->kind == Ty_name_ty)
        return actual_ty(ty->u.name.ty);
    else
        return ty;
}

int typeSize(Ty_ty ty)
{
    switch (actual_ty(ty)->kind)
    {
        case Ty_int:
            return INT_SIZE;
        case Ty_real:
            return REAL_SIZE;
        case Ty_bool:
            return BOOL_SIZE;
        case Ty_char:
            return CHAR_SIZE;
        case Ty_subrange:
            break;
        case Ty_record:
        {
            int size = 0;
            for (Ty_fieldList l = ty->u.record; l; l = l->tail)
                size += typeSize(actual_ty(l->head->ty));
            return size;
        }
        case Ty_array:
        {
            return typeSize(ty->u.array.ty) * (ty->u.array.rightBound - ty->u.array.leftBound);
        }
        case Ty_const_ty:
        {
            switch (ty->u.constt)
            {
                case TY_CONST_INT:
                    return INT_SIZE;
                case TY_CONST_REAL:
                    return REAL_SIZE;
                case TY_CONST_CHAR:
                    return CHAR_SIZE;
                case TY_CONST_STRING:
                {
                    //todo: convert to array
                }
                case TY_CONST_BOOL:
                {
                    return BOOL_SIZE;
                }
            }
        }
        case Ty_name_ty:
        {
            return 0;
        }
        case Ty_void:
        {
            return 0;
        }
        case Ty_math:
            break;
        case Ty_write:
            break;
    }
    return 0;
}

bool typeMatch(Ty_ty ty1, Ty_ty ty2)
{
    ty1 = actual_ty(ty1);
    ty2 = actual_ty(ty2);
    switch (ty1->kind)
    {
        case Ty_int:
        case Ty_real:
        case Ty_bool:
        case Ty_char:
        case Ty_const_ty:
        {
            if (ty2->kind == Ty_int ||
                ty2->kind == Ty_real ||
                ty2->kind == Ty_bool ||
                ty2->kind == Ty_char ||
                ty2->kind == Ty_math ||
                ty2->kind == Ty_const_ty
                    )
                return TRUE;
            else
                return FALSE;
        }
        case Ty_subrange:
            break;
        case Ty_record:
        {
            if (ty2->kind == Ty_record)
                return TRUE;
            else
                return FALSE;
        }
        case Ty_array:
        {
            if (ty2->kind == Ty_array)
                return TRUE;
            else
                return FALSE;
        }
        case Ty_name_ty:
            break;
        case Ty_void:
        {
            return FALSE;
        }
        case Ty_math:
        {
            if (ty2->kind == Ty_int ||
                ty2->kind == Ty_real ||
                ty2->kind == Ty_math)
                return TRUE;
            else if (ty2->kind == Ty_const_ty)
            {
                if (ty2->u.constt == TY_CONST_INT || ty2->u.constt == TY_CONST_REAL)
                    return TRUE;
                else
                    return FALSE;
            }
            else
                return FALSE;
        }
        case Ty_write:
        {
            switch (ty2->kind)
            {
                case Ty_int:
                case Ty_real:
                case Ty_bool:
                case Ty_const_ty:
                    return TRUE;

                default:
                    return FALSE;
            }
        }
    }
    return FALSE;
}

struct expty SEM_transProg(A_program a)
{
    struct expty exp;
    S_table type_base_env = E_base_tenv();
    S_table value_base_env = E_base_venv();
    exp = transProgram(value_base_env, type_base_env, a);
    return exp;
}


struct expty transProgram(S_table venv, S_table tenv, A_program a)
{
    return transRoutine(venv, tenv, a->routine);
};


struct expty transRoutine(S_table venv, S_table tenv, A_routine a)
{
    S_beginScope(venv);
    S_beginScope(tenv);
    S_table escenv = ESC_findEscape(a->routine_head, a->routine_body);
    transRoutineHead(escenv, venv, tenv, a->routine_head, Tr_outermost());
    struct expty exp = transRoutineBody(Tr_outermost(), venv, tenv, a->routine_body);
    S_endScope(tenv);
    S_endScope(venv);
    return exp;
}


void transRoutineHead(S_table escenv, S_table venv, S_table tenv, A_routine_head a, Tr_level level)
{
    transConstDec(level, venv, a->const_part);
    transTypeDec(level, venv, tenv, a->type_part);
    transVarDec(escenv, venv, tenv, a->var_part, level);
    transRoutineDec(level, venv, tenv, a->routine_part);
}

/*
 * Declarations start.
 */

/*
 * reverse the list of const  declaration,
 * since that the grammar is left recursive.
 */
A_const_expr_list reverse_const_dec_list(A_const_expr_list list)
{
    if (list == NULL || list->const_expr_list == NULL)
        return list;
    else
    {
        A_const_expr_list new = reverse_const_dec_list(list->const_expr_list);
        list->const_expr_list->const_expr_list = list;
        list->const_expr_list = NULL;
        return new;
    }
}

struct expty transConst(A_const_value a)
{
    switch (a->kind)
    {
        case CONST_INTEGER:
            return expTy(Tr_IntExp(a->u.intt), Ty_Const_Int());
        case CONST_REAL:
            return expTy(Tr_RealExp(a->u.real), Ty_Const_Real());
        case CONST_CHAR:
            return expTy(Tr_CharExp(a->u.charr[0]), Ty_Const_Char());
        case CONST_STRING:
            // todo: convert to array
            return expTy(NULL, Ty_Const_String());
        case CONST_SYS_CON:
        {
            switch (a->u.sys_con)
            {
                case SYS_CON_FALSE:
                    return expTy(Tr_BoolExp(FALSE), Ty_Const_Bool());
                case SYS_CON_TRUE:
                    return expTy(Tr_BoolExp(TRUE), Ty_Const_Bool());
                case SYS_CON_MAXINT:
                    return expTy(Tr_IntExp(MAXINT), Ty_Const_Int());
            }
        }
    }
}

void transConstDec(Tr_level level, S_table venv, A_const_part a)
{
    for (A_const_expr_list l = reverse_const_dec_list(a->const_expr_list); l; l = l->const_expr_list)
    {
        struct expty value = transConst(l->const_value);
        Tr_access local = Tr_AllocLocal(level, FALSE, typeSize(value.ty));
        S_enter(venv, l->id, E_VarEntry(local, value.ty));
    }
}

/*
 * reverse the list of type declaration,
 * since that the grammar is left recursive.
 */
A_type_decl_list reverse_type_dec_list(A_type_decl_list list)
{
    if (list == NULL || list->type_decl_list == NULL)
        return list;
    else
    {
        A_type_decl_list new = reverse_type_dec_list(list->type_decl_list);
        list->type_decl_list->type_decl_list = list;
        list->type_decl_list = NULL;
        return new;
    }
}

Ty_fieldList makeFieldList(Tr_level level, S_table venv, S_table tenv, A_field_decl_list list)
{
    Ty_fieldList fieldList = NULL;
    for (A_field_decl_list l = list; l; l = l->field_decl_list)
    {
        for (A_name_list name = l->field_decl->name_list; name; name = name->name_list)
        {
            fieldList = Ty_FieldList(
                    Ty_Field(name->id, transTy(level, venv, tenv, l->field_decl->type_decl)),
                    fieldList);
        }
    }
    return fieldList;
}

Ty_ty transTy(Tr_level level, S_table venv, S_table tenv, A_type_decl a)
{
    switch (a->kind)
    {
        case type_decl_simple:
        {
            switch (a->u.simple_type_decl->kind)
            {
                case simple_type_decl_sys_type:
                {
                    switch (a->u.simple_type_decl->u.sys_type)
                    {
                        case T_BOOLEAN:
                            return Ty_Bool();
                        case T_CHAR:
                            return Ty_Char();
                        case T_INTEGER:
                            return Ty_Int();
                        case T_REAL:
                            return Ty_Real();
                    }
                }
                case simple_type_decl_id:
                {
                    Ty_ty ty = S_look(tenv, a->u.simple_type_decl->u.id);
                    if (ty)
                        return ty;
                    else
                    {
                        EM_error(a->pos, "Undefined type: %s",
                                 S_name(a->u.simple_type_decl->u.id));
                        return Ty_Int();
                    }

                }
                    /*
                     * Temporarily omit.
                     */
                case simple_type_decl_name_list:
                {
                    break;
                }
                case simple_type_decl_range_const_to_const:
                {
                    break;
                }
                case simple_type_decl_range_id_to_id:
                {
                    break;
                }
            }
        }
        case type_decl_record:
        {
            return Ty_Record(makeFieldList(level, venv, tenv, a->u.record_type_decl->field_decl_list));
        }
        case type_decl_array:
        {
            switch (a->u.array_type_decl->simple_type_decl->kind)
            {

                case simple_type_decl_range_const_to_const:
                {
//                    Ty_ty range = Ty_Const_Range(
//                            Ty_Const(a->u.array_type_decl->simple_type_decl->u.const_range.from),
//                            Ty_Const(a->u.array_type_decl->simple_type_decl->u.const_range.to)
//                    );

//                    return Ty_Array(range, transTy(tenv, a->u.array_type_decl->type_decl));
                    A_const_value leftBound = a->u.array_type_decl->simple_type_decl->u.const_range.from;
                    A_const_value rightBound = a->u.array_type_decl->simple_type_decl->u.const_range.to;
                    if (leftBound->kind == CONST_INTEGER &&
                        rightBound->kind == CONST_INTEGER)
                    {
                        return Ty_Array(transTy(level, venv, tenv, a->u.array_type_decl->type_decl), leftBound->u.intt,
                                        rightBound->u.intt);

                    }
                    else
                    {
                        EM_error(leftBound->pos, "Bound of array must be integer.\n");
                        return Ty_Void();
                    }

                }
                case simple_type_decl_range_id_to_id:
                {
//                    Ty_ty range = Ty_Name_Range(
//                            a->u.array_type_decl->simple_type_decl->u.id_range.from,
//                            a->u.array_type_decl->simple_type_decl->u.id_range.to
//                    );

//                    return Ty_Array(range, transTy(tenv, a->u.array_type_decl->type_decl));

                    struct expty leftBound = transVar(level, venv, tenv,
                                                      A_Simple(a->u.array_type_decl->pos,
                                                               a->u.array_type_decl->simple_type_decl->u.id_range.from));
                    struct expty rightBound = transVar(level, venv, tenv,
                                                       A_Simple(a->u.array_type_decl->pos,
                                                                a->u.array_type_decl->simple_type_decl->u.id_range.to));

                    if (leftBound.ty->kind == Ty_const_ty &&
                        rightBound.ty->kind == Ty_const_ty &&
                        leftBound.ty->u.constt == TY_CONST_INT &&
                        rightBound.ty->u.constt == TY_CONST_INT)
                    {
                        return Ty_Array(transTy(level, venv, tenv, a->u.array_type_decl->type_decl),
                                        leftBound.exp->u.ex->u.CONST, rightBound.exp->u.ex->u.CONST);
                    }
                    else
                    {
                        EM_error(a->u.array_type_decl->simple_type_decl->pos, "Bound of array must be integer.\n");
                        return Ty_Void();
                    }
                }
                    /*
                     * Temporarily omit.
                     */
                case simple_type_decl_sys_type:
                    break;
                case simple_type_decl_id:
                    break;
                case simple_type_decl_name_list:
                    break;

            }
        }
    }
    return Ty_Int();
}

void transTypeDec(Tr_level level, S_table venv, S_table tenv, A_type_part a)
{
    /*
     * 不支持不同类型之间的超前引用
     * 只支持同一类型的递归定义
     */
    for (A_type_decl_list l = reverse_type_dec_list(a->type_decl_list); l; l = l->type_decl_list)
    {
        if (l->type_definition->type_decl->kind == type_decl_record)
        {
            S_enter(tenv, l->type_definition->id, Ty_Name(l->type_definition->id, NULL));
            Ty_ty declaration = transTy(level, venv, tenv, l->type_definition->type_decl);
            Ty_ty type = (Ty_ty) S_look(tenv, l->type_definition->id);
            type->u.name.ty = declaration;
        }
        else
            S_enter(tenv, l->type_definition->id, transTy(level, venv, tenv, l->type_definition->type_decl));

    }
}

void transVarDec(S_table escenv, S_table venv, S_table tenv, A_var_part a, Tr_level level)
{
    for (A_var_decl_list l = a->var_decl_list; l; l = l->var_decl_list)
    {
        for (A_name_list name = l->var_decl->name_list; name; name = name->name_list)
        {
            if (S_look(venv, name->id))
                EM_error(l->var_decl->pos, "Variable redefine\n");
            Ty_ty ty = transTy(level, venv, tenv, l->var_decl->type_decl);
            Tr_access local;

            if (S_look(escenv, name->id))
                local = Tr_AllocLocal(level, TRUE, typeSize(actual_ty(ty)));
            else
                local = Tr_AllocLocal(level, FALSE, typeSize(actual_ty(ty)));

            S_enter(venv, name->id, E_VarEntry(local, ty));
        }
    }
}

/*
 * reverse the list of routine declaration,
 * since that the grammar is left recursive.
 */
A_routine_part reverse_routine_dec_list(A_routine_part list)
{
    if (list == NULL || list->routine_part == NULL)
        return list;
    else
    {
        A_routine_part new = reverse_routine_dec_list(list->routine_part);
        list->routine_part->routine_part = list;
        list->routine_part = NULL;
        return new;
    }
}

A_para_decl_list reverse_para_dec_list(A_para_decl_list list)
{
    if (list == NULL || list->para_decl_list == NULL)
        return list;
    else
    {
        A_para_decl_list new = reverse_para_dec_list(list->para_decl_list);
        list->para_decl_list->para_decl_list = list;
        list->para_decl_list = NULL;
        return new;
    }
}

Ty_tyList makeFormalTyList(Tr_level level, S_table venv, S_table tenv, A_para_decl_list a)
{
    Ty_tyList tyList = NULL;
    for (A_para_decl_list l = a; l; l = l->para_decl_list)
    {
        /*
         * convert simple_type_decl to A_type_decl
         */
        A_type_decl ty = checked_malloc(sizeof(*ty));
        ty->kind = type_decl_simple;
        ty->u.simple_type_decl = l->para_type_list->u.var_para_list.simple_type_decl;

        switch (l->para_type_list->kind)
        {
            case para_type_list_var:
            {
                for (A_name_list para = l->para_type_list->u.var_para_list.var_para_list->name_list;
                     para; para = para->name_list)
                {
                    tyList = Ty_TyList(transTy(level, venv, tenv, ty), tyList);
                }
                break;
            }
            case para_type_list_val:
            {
                for (A_name_list para = l->para_type_list->u.val_para_list.val_para_list->name_list;
                     para; para = para->name_list)
                {
                    tyList = Ty_TyList(transTy(level, venv, tenv, ty), tyList);
                }
                break;
            }
        }
    }
    return tyList;
}

U_boolList makeFormalEscapeList(A_para_decl_list a)
{
    U_boolList list = NULL;
    for (A_para_decl_list l = a; l; l = l->para_decl_list)
        list = U_BoolList(TRUE, list);
    return list;
}

void transRoutineDec(Tr_level level, S_table venv, S_table tenv, A_routine_part a)
{
    for (A_routine_part l = reverse_routine_dec_list(a); l; l = l->routine_part)
    {
        switch (l->kind)
        {
            case routine_part_function:
            {
                A_type_decl ty = checked_malloc(sizeof(*ty));
                ty->kind = type_decl_simple;
                ty->u.simple_type_decl = a->u.function_decl->function_head->simple_type_decl;
                Ty_ty resultTy = transTy(level, venv, tenv, ty);
                Ty_tyList formalTys = makeFormalTyList(level, venv, tenv,
                                                       l->u.function_decl->function_head->parameters->para_decl_list);
                Temp_label label = Temp_namedlabel(S_name(l->u.function_decl->function_head->id));
                if (S_look(venv, l->u.function_decl->function_head->id))
                    EM_error(l->u.function_decl->function_head->pos, "Function redefine\n");
                S_enter(venv, l->u.function_decl->function_head->id, E_FunEntry(level, label, formalTys, resultTy));
                break;
            }
            case routine_part_procedure:
            {
                Ty_ty resultTy = Ty_Void();
                Ty_tyList formalTys = makeFormalTyList(level, venv, tenv,
                                                       l->u.procedure_decl->procedure_head->parameters->para_decl_list);
                Temp_label label = Temp_namedlabel(S_name(l->u.procedure_decl->procedure_head->id));
                if (S_look(venv, l->u.procedure_decl->procedure_head->id))
                    EM_error(l->u.procedure_decl->procedure_head->pos, "Procedure redefine\n");
                S_enter(venv, l->u.procedure_decl->procedure_head->id, E_FunEntry(level, label, formalTys, resultTy));
                break;
            }
        }
    }
    for (A_routine_part l = a; l; l = l->routine_part)
    {
        switch (l->kind)
        {
            case routine_part_function:
            {
                E_enventry fun = (E_enventry) S_look(venv, l->u.procedure_decl->procedure_head->id);
                Ty_tyList formalTys = fun->u.fun.formals;
                Temp_label label = fun->u.fun.label;

                U_boolList formalEscapes = makeFormalEscapeList(
                        l->u.function_decl->function_head->parameters->para_decl_list);

                Tr_level newLevel = Tr_NewLevel(level, label, formalEscapes);
                S_beginScope(tenv);
                S_beginScope(venv);
                {
                    A_para_decl_list declList;
                    Ty_tyList tyList;
                    for (declList =
                                 reverse_para_dec_list(
                                         l->u.function_decl->function_head->parameters->para_decl_list),
                                 tyList = formalTys;
                         declList;
                         declList = declList->para_decl_list, tyList = tyList->tail)
                    {
                        switch (declList->para_type_list->kind)
                        {
                            case para_type_list_var:
                            {
                                for (A_name_list nameList =
                                        declList->para_type_list->u.var_para_list.var_para_list->name_list;
                                     nameList; nameList = nameList->name_list)
                                {
                                    Tr_access local = Tr_AllocLocal(newLevel, TRUE, typeSize(tyList->head));
                                    S_enter(venv, nameList->id, E_VarEntry(local, tyList->head));
                                }
                                break;
                            }
                            case para_type_list_val:
                            {
                                for (A_name_list nameList =
                                        declList->para_type_list->u.var_para_list.var_para_list->name_list;
                                     nameList; nameList = nameList->name_list)
                                {
                                    Tr_access local = Tr_AllocLocal(newLevel, TRUE, typeSize(tyList->head));
                                    S_enter(venv, nameList->id, E_VarEntry(local, tyList->head));
                                }
                                break;
                            }
                        }
                    }
                    S_table escenv = ESC_findEscape(l->u.function_decl->sub_routine->routine_head,
                                                    l->u.function_decl->sub_routine->routine_body);
                    transRoutineHead(escenv, venv, tenv, l->u.function_decl->sub_routine->routine_head, newLevel);
                }
                transRoutineBody(level, venv, tenv, l->u.function_decl->sub_routine->routine_body);
                S_endScope(venv);
                S_endScope(tenv);
                break;
            }
            case routine_part_procedure:
            {
                E_enventry fun = (E_enventry) S_look(venv, l->u.procedure_decl->procedure_head->id);
                Ty_tyList formalTys = fun->u.fun.formals;
                Temp_label label = fun->u.fun.label;

                U_boolList formalEscapes = makeFormalEscapeList(
                        l->u.procedure_decl->procedure_head->parameters->para_decl_list);

                Tr_level newLevel = Tr_NewLevel(level, label, formalEscapes);
                S_beginScope(tenv);
                S_beginScope(venv);
                {
                    A_para_decl_list declList;
                    Ty_tyList tyList;
                    for (declList =
                                 reverse_para_dec_list(
                                         l->u.procedure_decl->procedure_head->parameters->para_decl_list),
                                 tyList = formalTys;
                         declList;
                         declList = declList->para_decl_list, tyList = tyList->tail)
                    {
                        switch (declList->para_type_list->kind)
                        {
                            case para_type_list_var:
                            {
                                for (A_name_list nameList =
                                        declList->para_type_list->u.var_para_list.var_para_list->name_list;
                                     nameList; nameList = nameList->name_list)
                                {
                                    Tr_access local = Tr_AllocLocal(newLevel, TRUE, typeSize(tyList->head));
                                    S_enter(venv, nameList->id, E_VarEntry(local, tyList->head));
                                }
                                break;
                            }
                            case para_type_list_val:
                            {
                                for (A_name_list nameList =
                                        declList->para_type_list->u.val_para_list.val_para_list->name_list;
                                     nameList; nameList = nameList->name_list)
                                {
                                    Tr_access local = Tr_AllocLocal(newLevel, TRUE, typeSize(tyList->head));
                                    S_enter(venv, nameList->id, E_VarEntry(local, tyList->head));
                                }
                                break;
                            }
                        }
                    }
                    S_table escenv = ESC_findEscape(l->u.procedure_decl->sub_routine->routine_head,
                                                    l->u.procedure_decl->sub_routine->routine_body);
                    transRoutineHead(escenv, venv, tenv, l->u.procedure_decl->sub_routine->routine_head, newLevel);
                }
                transRoutineBody(level, venv, tenv, l->u.procedure_decl->sub_routine->routine_body);
                S_endScope(venv);
                S_endScope(tenv);
                break;
            }
        }

    }
}

/*
 * Declarations end.
 */


/*
 * Statements start;
 */
A_stmt_list reverse_stmt_list(A_stmt_list list)
{
    if (list == NULL || list->stmt_list == NULL)
        return list;
    else
    {
        A_stmt_list new = reverse_stmt_list(list->stmt_list);
        list->stmt_list->stmt_list = list;
        list->stmt_list = NULL;
        return new;
    }

}

Ty_tyList reverse_type_list(Ty_tyList list)
{
    if (list == NULL || list->tail == NULL)
        return list;
    else
    {
        Ty_tyList new = reverse_type_list(list->tail);
        list->tail->tail = list;
        list->tail = NULL;
        return new;
    }

}

Tr_expList makeArgsList(Tr_level level, S_table venv, S_table tenv, A_args_list a, E_enventry fun)
{
    Tr_expList expList = NULL;
    A_args_list l;
    Ty_tyList t;
    for (l = a, t = reverse_type_list(fun->u.fun.formals); l && t; l = l->args_list, t = t->tail)
    {
        struct expty arg = transExp(level, venv, tenv, l->expression);
        if (!typeMatch(t->head, arg.ty))
        {
            EM_error(l->pos, "Argument type does not match declaration.\n");
            return NULL;
        }
        expList = Tr_ExpList(arg.exp, expList);
    }
    if (l || t)
    {
        EM_error(a->pos, "Arguments num does not match.\n");
        return NULL;
    }

    return expList;
}

struct expty transRoutineBody(Tr_level level, S_table venv, S_table tenv, A_routine_body a)
{
    return transStms(level, venv, tenv, reverse_stmt_list(a->compound_stmt->stmt_list));
}

/*
 * convert case statement to if statement.
 */
Tr_exp convertCaseStm(Tr_level level, S_table venv, S_table tenv, A_case_expr_list a, A_expression c)
{
    if (!a)
        return NULL;

    Tr_exp cond = NULL, body = NULL;
    switch (a->case_expr->kind)
    {

        case case_expr_const_value:
        {
            cond = Tr_RelExp(OP_EQUAL,
                             transExp(level, venv, tenv, c).exp,
                             transConst(a->case_expr->u.const_value.const_value).exp);

            body = transStm(level, venv, tenv, a->case_expr->u.const_value.body).exp;
            break;
        }
        case case_expr_non_const_value:
        {
            cond = Tr_RelExp(OP_EQUAL, transExp(level, venv, tenv, c).exp,
                             transVar(level, venv, tenv,
                                      A_Simple(a->case_expr->pos,
                                               a->case_expr->u.non_const_value.id)).exp);

            body = transStm(level, venv, tenv, a->case_expr->u.non_const_value.body).exp;
        }
    }

    return Tr_IfExp(cond, body, convertCaseStm(level, venv, tenv, a->case_expr_list, c));

}

struct expty transStm(Tr_level level, S_table venv, S_table tenv, A_stmt a)
{
    switch (a->non_label_stmt->kind)
    {
        case non_label_stmt_assign:
        {
            struct expty left, right;
            switch (a->non_label_stmt->u.assign_stmt->kind)
            {
                case assign_stmt_simple:
                {
                    left = transVar(level, venv, tenv,
                                    A_Simple(a->non_label_stmt->u.assign_stmt->pos,
                                             a->non_label_stmt->u.assign_stmt->u.simple_var_assign_stmt.id));
                    right = transExp(level, venv, tenv,
                                     a->non_label_stmt->u.assign_stmt->u.simple_var_assign_stmt.right_expression);
                    break;
                }
                case assign_stmt_record:
                {
                    left = transVar(level, venv, tenv,
                                    A_Record(a->non_label_stmt->u.assign_stmt->pos,
                                             a->non_label_stmt->u.assign_stmt->u.record_var_assign_stmt.id,
                                             a->non_label_stmt->u.assign_stmt->u.record_var_assign_stmt.field_id));
                    right = transExp(level, venv, tenv,
                                     a->non_label_stmt->u.assign_stmt->u.record_var_assign_stmt.right_expression);
                    break;
                }
                case assign_stmt_array:
                {
                    left = transVar(level, venv, tenv,
                                    A_Array(a->non_label_stmt->u.assign_stmt->pos,
                                            a->non_label_stmt->u.assign_stmt->u.array_var_assign_stmt.id,
                                            a->non_label_stmt->u.assign_stmt->u.array_var_assign_stmt.subscript_expression));
                    right = transExp(level, venv, tenv,
                                     a->non_label_stmt->u.assign_stmt->u.array_var_assign_stmt.right_expression);
                    break;
                }
            }


            if (left.ty->kind == Ty_const_ty)
            {
                EM_error(a->pos, "Const value cannot be assigned.\n");
                return expTy(NULL, Ty_Void());
            }

            if (typeMatch(left.ty, right.ty))
            {
                return expTy(Tr_AssignExp(left.exp, right.exp), Ty_Void());
            }
            else
            {
                EM_error(a->pos, "Assign statement type dose not match.\n");
                return expTy(NULL, Ty_Void());
            }
        }
        case non_label_stmt_proc:
        {
            switch (a->non_label_stmt->u.proc_stmt->kind)
            {
                case proc_stmt_id:
                    break;
                case proc_stmt_id_with_args:
                {
                    E_enventry fun = (E_enventry) S_look(venv, a->non_label_stmt->u.proc_stmt->u.id_with_args.id);
                    if (fun && fun->kind == E_funEntry)
                    {
                        Tr_expList argList = makeArgsList(level, venv, tenv,
                                                          a->non_label_stmt->u.proc_stmt->u.id_with_args.args_list,
                                                          fun);
                        return expTy(Tr_CallExp(fun->u.fun.label, fun->u.fun.level, level, argList), fun->u.fun.result);
                    }
                    else
                    {
                        EM_error(a->pos, "Function is not declared.\n");
                        return expTy(NULL, Ty_Int());
                    }
                }
                case proc_stmt_sys_proc:
                    break;
                case proc_stmt_sys_proc_with_args:
                {
                    E_enventry fun = (E_enventry) S_look(venv, a->non_label_stmt->u.proc_stmt->u.id_with_args.id);
                    if (fun && fun->kind == E_funEntry)
                    {
                        Tr_expList argList = makeArgsList(level, venv, tenv,
                                                          a->non_label_stmt->u.proc_stmt->u.id_with_args.args_list,
                                                          fun);
                        return expTy(Tr_CallExp(fun->u.fun.label, fun->u.fun.level, level, argList), fun->u.fun.result);
                    }
                    else
                    {
                        EM_error(a->pos, "Function is not declared.\n");
                        return expTy(NULL, Ty_Int());
                    }
                }
                case proc_stmt_read:
                    break;
            }
        }
        case non_label_stmt_compound:
        {
            return transStms(level, venv, tenv, a->non_label_stmt->u.compound_stmt->stmt_list);
        }
        case non_label_stmt_if:
        {
            struct expty cond, e1, e2;
            cond = transExp(level, venv, tenv, a->non_label_stmt->u.if_stmt->test);
            e1 = transStm(level, venv, tenv, a->non_label_stmt->u.if_stmt->body);
            if (a->non_label_stmt->u.if_stmt->else_clause)
                e2 = transStm(level, venv, tenv, a->non_label_stmt->u.if_stmt->else_clause->body);
            return expTy(Tr_IfExp(cond.exp, e1.exp, e2.exp), Ty_Void());
        }
        case non_label_stmt_repeat:
        {
            struct expty cond = transExp(level, venv, tenv, a->non_label_stmt->u.repeat_stmt->until);
            struct expty body = transStms(level, venv, tenv, a->non_label_stmt->u.repeat_stmt->body);
            Tr_exp label = Tr_LabelExp(Temp_newlabel());
            return expTy(Tr_SeqExp(Tr_SeqExp(body.exp,
                                             Tr_WhileExp(cond.exp, body.exp, label)),
                                   label),
                         Ty_Void());
        }
        case non_label_stmt_while:
        {
            struct expty cond = transExp(level, venv, tenv, a->non_label_stmt->u.while_stmt->test);
            struct expty body = transStm(level, venv, tenv, a->non_label_stmt->u.while_stmt->body);
            Tr_exp label = Tr_LabelExp(Temp_newlabel());
            return expTy(Tr_SeqExp(Tr_WhileExp(cond.exp, body.exp, label), label), Ty_Void());
        }
        case non_label_stmt_for:
        {
            struct expty loopVar = transVar(level, venv, tenv,
                                            A_Simple(a->non_label_stmt->u.for_stmt->pos,
                                                     a->non_label_stmt->u.for_stmt->loop_var));
            struct expty low = transExp(level, venv, tenv, a->non_label_stmt->u.for_stmt->lo);
            struct expty high = transExp(level, venv, tenv, a->non_label_stmt->u.for_stmt->hi);

            Tr_exp loopVarInit = NULL, cond = NULL, body = NULL;
            switch (a->non_label_stmt->u.for_stmt->direction)
            {
                case DIRECTION_TO:
                {
                    loopVarInit = Tr_AssignExp(loopVar.exp, low.exp);
                    cond = Tr_RelExp(OP_LT, loopVar.exp, high.exp);
                    body = Tr_SeqExp(transStm(level, venv, tenv, a->non_label_stmt->u.for_stmt->body).exp,
                                     Tr_AssignExp(loopVar.exp,
                                                  Tr_PlusArithExp(OP_PLUS, loopVar.exp, Tr_IntExp(1))));

                    break;
                }
                case DIRECTION_DOWNTO:
                {
                    loopVarInit = Tr_AssignExp(loopVar.exp, high.exp);
                    cond = Tr_RelExp(OP_GT, loopVar.exp, low.exp);
                    body = Tr_SeqExp(transStm(level, venv, tenv, a->non_label_stmt->u.for_stmt->body).exp,
                                     Tr_AssignExp(loopVar.exp,
                                                  Tr_PlusArithExp(OP_MINUS, loopVar.exp, Tr_IntExp(1))));

                    break;
                }
            }
            Tr_exp label = Tr_LabelExp(Temp_newlabel());
            return expTy(Tr_SeqExp(Tr_SeqExp(loopVarInit,
                                             Tr_WhileExp(cond, body, label)),
                                   label),
                         Ty_Void());

        }
        case non_label_stmt_case:
        {
            return expTy(convertCaseStm(level, venv, tenv, a->non_label_stmt->u.case_stmt->case_expr_list,
                                        a->non_label_stmt->u.case_stmt->expression),
                         Ty_Void());
        }
        case non_label_stmt_goto:
        {
            char label[10];
            sprintf(label, "%d", a->non_label_stmt->u.goto_stmt->label);
            return expTy(Tr_GotoExp(Tr_LabelExp(Temp_namedlabel(label))), Ty_Void());
        }
    }
    return expTy(NULL, Ty_Void());
}

struct expty transStms(Tr_level level, S_table venv, S_table tenv, A_stmt_list stmts)
{
    struct expty exp;
    if (stmts->stmt->is_label == LABEL)
    {
        char label[10];
        sprintf(label, "%d", stmts->stmt->label);
        exp = expTy(Tr_SeqExp(Tr_LabelExp(Temp_namedlabel(label)), transStm(level, venv, tenv, stmts->stmt).exp),
                    Ty_Void());
    }
    else
        exp = transStm(level, venv, tenv, stmts->stmt);

    if (stmts->stmt_list)
        return expTy(Tr_SeqExp(exp.exp, transStms(level, venv, tenv, stmts->stmt_list).exp), Ty_Void());
    else
        return exp;
}

struct expty transVar(Tr_level level, S_table venv, S_table tenv, A_var a)
{
    switch (a->kind)
    {
        case A_SIMPLE:
        {
            E_enventry varEntry = (E_enventry) S_look(venv, a->u.simple);
            if (!varEntry)
            {
                EM_error(a->pos, "Variable is not declared: %s.\n", S_name(a->u.simple));
                return expTy(NULL, Ty_Int());
            }
            if (varEntry->kind == E_varEntry &&
                (varEntry->u.var.ty->kind == Ty_int ||
                 varEntry->u.var.ty->kind == Ty_char ||
                 varEntry->u.var.ty->kind == Ty_real ||
                 varEntry->u.var.ty->kind == Ty_bool ||
                 varEntry->u.var.ty->kind == Ty_const_ty))
            {
                return expTy(Tr_SimpleVar(varEntry->u.var.access, level), actual_ty(varEntry->u.var.ty));
            }
            else
            {
                EM_error(a->pos, "Simple type expected: %s.\n", S_name(a->u.simple));
                return expTy(NULL, Ty_Int());
            }
        }
        case A_ARRAY:
        {
            E_enventry varEntry = (E_enventry) S_look(venv, a->u.array.array);
            if (!varEntry)
            {
                EM_error(a->pos, "Variable is not declared: %s.\n", S_name(a->u.array.array));
                return expTy(NULL, Ty_Int());
            }

            if (varEntry->kind == E_varEntry &&
                varEntry->u.var.ty->kind == Ty_array)
            {
                struct expty subscript = transExp(level, venv, tenv, a->u.array.subscript);
                if (subscript.ty->kind == Ty_int ||
                    (subscript.ty->kind == Ty_const_ty && subscript.ty->u.constt == TY_CONST_INT))
                {
                    return expTy(Tr_SubscriptVar(Tr_SimpleVar(varEntry->u.var.access, level),
                                                 subscript.exp, typeSize(varEntry->u.var.ty->u.array.ty)),
                                 actual_ty(varEntry->u.var.ty->u.array.ty));
                }
                else
                {
                    EM_error(a->pos, "Index must be integer.\n", S_name(a->u.array.array));
                    return expTy(NULL, Ty_Int());
                }
            }
            else
            {
                EM_error(a->pos, "Array type expected: %s.\n", S_name(a->u.array.array));
                return expTy(NULL, Ty_Int());
            }

        }
        case A_RECORD:
        {
            E_enventry varEntry = (E_enventry) S_look(venv, a->u.record.record);
            if (!varEntry)
            {
                EM_error(a->pos, "Variable is not declared: %s.\n", S_name(a->u.array.array));
                return expTy(NULL, Ty_Int());
            }
            int offset = 0;
            if (varEntry->kind == E_varEntry &&
                actual_ty(varEntry->u.var.ty)->kind == Ty_record)
            {
                for (Ty_fieldList field = actual_ty(varEntry->u.var.ty)->u.record; field; field = field->tail)
                {
                    int size = typeSize(field->head->ty);
                    if (field->head->name == a->u.record.field)
                    {
                        return expTy(Tr_RecordVar(Tr_SimpleVar(varEntry->u.var.access, level),
                                                  offset, size),
                                     actual_ty(field->head->ty));
                    }
                    offset += size;
                }
                EM_error(a->pos, "Field does no exist: %s.\n", S_name(a->u.record.field));
                return expTy(NULL, Ty_Int());
            }
            else
            {
                EM_error(a->pos, "Record type expected: %s.\n", S_name(a->u.record.record));
                return expTy(NULL, Ty_Int());
            }
        }
    }
}

struct expty transFactor(Tr_level level, S_table venv, S_table tenv, A_factor a)
{
    switch (a->kind)
    {
        case factor_id:
        {
            return transVar(level, venv, tenv, A_Simple(a->pos, a->u.id));
        }
        case factor_id_with_args:
        {
            E_enventry fun = (E_enventry) S_look(venv, a->u.id_with_args.id);
            if (fun && fun->kind == E_funEntry)
            {
                Tr_expList argList = makeArgsList(level, venv, tenv, a->u.id_with_args.args_list, fun);
                return expTy(Tr_CallExp(fun->u.fun.label, fun->u.fun.level, level, argList),
                             actual_ty(fun->u.fun.result));
            }
            else
            {
                EM_error(a->pos, "Function is not declared.\n");
                return expTy(NULL, Ty_Int());
            }
        }
        case factor_sys_funct:
            break;
        case factor_sys_funct_with_args:
            break;
        case factor_const_value:
        {
            return transConst(a->u.const_value);
        }
        case factor_in_brackets:
        {
            return transExp(level, venv, tenv, a->u.expression);
        }
        case factor_un_op:
            break;
        case factor_array_var:
        {
            return transVar(level, venv, tenv, A_Array(a->pos, a->u.array_var.id, a->u.array_var.subscript_expression));
        }
        case factor_record_var:
        {
            return transVar(level, venv, tenv, A_Record(a->pos, a->u.record_var.id, a->u.record_var.field_id));
        }
    }
    return expTy(NULL, Ty_Int());
}

struct expty transTerm(Tr_level level, S_table venv, S_table tenv, A_term a)
{

    struct expty left, right;
    switch (a->is_bin_op)
    {
        case NONBINOP:
        {
            right = transFactor(level, venv, tenv, a->u.factor);
            return right;
        }
        case BINOP:
        {
            left = transTerm(level, venv, tenv, a->u.bin_op.left_term);
            right = transFactor(level, venv, tenv, a->u.bin_op.right_factor);
            if (typeMatch(left.ty, right.ty))
                return expTy(Tr_MulArithExp(a->u.bin_op.mul_op, left.exp, right.exp),
                             left.ty);
            else
            {
                EM_error(a->pos, "Expression type dose not match.\n");
                return expTy(NULL, Ty_Int());
            }
        }
    }
}

struct expty transExpr(Tr_level level, S_table venv, S_table tenv, A_expr a)
{
    struct expty left, right;
    switch (a->is_bin_op)
    {
        case NONBINOP:
        {
            right = transTerm(level, venv, tenv, a->u.term);
            return right;
        }
        case BINOP:
        {
            left = transExpr(level, venv, tenv, a->u.bin_op.left_expr);
            right = transTerm(level, venv, tenv, a->u.bin_op.right_term);
            if (typeMatch(left.ty, right.ty))
                return expTy(Tr_PlusArithExp(a->u.bin_op.plus_op, left.exp, right.exp),
                             left.ty);
            else
            {
                EM_error(a->pos, "Expression type dose not match.\n");
                return expTy(NULL, Ty_Int());
            }

        }
    }
}

struct expty transExp(Tr_level level, S_table venv, S_table tenv, A_expression a)
{
    struct expty left, right;
    switch (a->is_bin_op)
    {
        case NONBINOP:
        {
            right = transExpr(level, venv, tenv, a->u.expr);
            return expTy(right.exp, right.ty);
        }

        case BINOP:
        {
            left = transExp(level, venv, tenv, a->u.bin_op.left_expression);
            right = transExpr(level, venv, tenv, a->u.bin_op.right_expr);
            if (typeMatch(left.ty, right.ty))
            {
                return expTy(Tr_RelExp(a->u.bin_op.rel_op, left.exp, right.exp),
                             Ty_Bool());
            }
            else
            {
                EM_error(a->pos, "Expression type dose not match.\n");
                return expTy(NULL, Ty_Int());
            }
        }
    }
}
