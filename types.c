//
// Created by DavidWangjp on 2018/5/17.
//

#include "util.h"
#include "symbol.h"
#include "types.h"


#define MAXINT 2147483647


static struct Ty_ty_ tyint = {Ty_ty_::Ty_int};

Ty_ty Ty_Int(void)
{
    return &tyint;
}

static struct Ty_ty_ tyreal = {Ty_ty_::Ty_real};

Ty_ty Ty_Real(void)
{
    return &tyreal;
}

static struct Ty_ty_ tybool = {Ty_ty_::Ty_bool};

Ty_ty Ty_Bool(void)
{
    return &tybool;
}

static struct Ty_ty_ tychar = {Ty_ty_::Ty_char};

Ty_ty Ty_Char(void)
{
    return &tychar;
}

static struct Ty_ty_ tyvoid = {Ty_ty_::Ty_void};

Ty_ty Ty_Void(void)
{
    return &tyvoid;
}

static struct Ty_ty_ tyconstint = {
        .kind=Ty_ty_::Ty_const,
        .u.constt=TY_CONST_INT};

Ty_ty Ty_Const_Int(void)
{
    return &tyconstint;
}

static struct Ty_ty_ tyconstreal = {
        .kind=Ty_ty_::Ty_const,
        .u.constt=TY_CONST_REAL};

Ty_ty Ty_Const_Real(void)
{
    return &tyconstreal;
}

static struct Ty_ty_ tyconstchar = {
        .kind=Ty_ty_::Ty_const,
        .u.constt=TY_CONST_CHAR};

Ty_ty Ty_Const_Char(void)
{
    return &tyconstchar;
}

static struct Ty_ty_ tyconstbool = {
        .kind=Ty_ty_::Ty_const,
        .u.constt=TY_CONST_BOOL};

Ty_ty Ty_Const_Bool(void)
{
    return &tyconstbool;
}

static struct Ty_ty_ tyconststring = {
        .kind=Ty_ty_::Ty_const,
        .u.constt=TY_CONST_STRING};

Ty_ty Ty_Const_String(void)
{
    return &tyconststring;
}

Ty_const Ty_Const(A_const_value const_value)
{
    Ty_const p = checked_malloc(sizeof(*p));
    switch (const_value->kind)
    {
        case A_const_value_::CONST_INTEGER:
        {
            p->kind = TY_CONST_INT;
            p->u.intt = const_value->u.intt;
            break;
        }
        case A_const_value_::CONST_REAL:
        {
            p->kind = TY_CONST_REAL;
            p->u.real = const_value->u.real;
            break;
        }
        case A_const_value_::CONST_CHAR:
        {
            p->kind = TY_CONST_CHAR;
            p->u.charr = const_value->u.charr;
            break;
        }
        case A_const_value_::CONST_STRING:
        {
            p->kind = TY_CONST_STRING;
            p->u.string = const_value->u.string;
            break;
        }
        case A_const_value_::CONST_SYS_CON:
        {
            switch (const_value->u.sys_con)
            {
                case SYS_CON_FALSE:
                {
                    p->kind = TY_CONST_BOOL;
                    p->u.booll = FALSE;
                    break;
                }
                case SYS_CON_TRUE:
                {
                    p->kind = TY_CONST_BOOL;
                    p->u.booll = TRUE;
                    break;
                }
                case SYS_CON_MAXINT:
                {
                    p->kind = TY_CONST_INT;
                    p->u.intt = MAXINT;
                    break;
                }
            }
            break;
        }
    }
    return p;
}

Ty_ty Ty_Const_Range(Ty_const left_bound, Ty_const right_bound)
{
    Ty_ty p = checked_malloc(sizeof(*p));
    p->kind = Ty_ty_::Ty_subrange;
    p->u.range->kind = Ty_range_::Ty_const;
    p->u.range->u.constt.left_bound = left_bound;
    p->u.range->u.constt.right_bound = right_bound;
    return p;
}

Ty_ty Ty_Name_Range(S_symbol left_bound, S_symbol right_bound)
{
    Ty_ty p = checked_malloc(sizeof(*p));
    p->kind = Ty_ty_::Ty_subrange;
    p->u.range->kind = Ty_range_::Ty_name;
    p->u.range->u.name.left_bound = left_bound;
    p->u.range->u.name.right_bound = right_bound;
    return p;
}

static struct Ty_ty_ tymath = {Ty_ty_::Ty_math};

Ty_ty Ty_Math(void)
{
    return &tymath;
}

static struct Ty_ty_ tywrite = {Ty_ty_::Ty_write};

Ty_ty Ty_Math(void)
{
    return &tywrite;
}

Ty_ty Ty_Record(Ty_fieldList fields)
{
    Ty_ty p = checked_malloc(sizeof(*p));
    p->kind = Ty_ty_::Ty_record;
    p->u.record = fields;
    return p;
}

//Ty_ty Ty_Array(Ty_ty range, Ty_ty ty)
//{
//    Ty_ty p = checked_malloc(sizeof(*p));
//    p->kind = Ty_ty_::Ty_array;
//    p->u.array.range = range;
//    p->u.array.ty = ty;
//}

Ty_ty Ty_Array(Ty_ty ty, int leftBound, int rightBound)
{
    Ty_ty p = checked_malloc(sizeof(*p));
    p->kind = Ty_ty_::Ty_array;
    p->u.array.ty = ty;
    p->u.array.leftBound = leftBound;
    p->u.array.rightBound = rightBound;
    return p;
}

Ty_ty Ty_Name(S_symbol sym, Ty_ty ty)
{
    Ty_ty p = checked_malloc(sizeof(*p));
    p->kind = Ty_ty_::Ty_name;
    p->u.name.sym = sym;
    p->u.name.ty = ty;
    return p;
}

Ty_tyList Ty_TyList(Ty_ty head, Ty_tyList tail)
{
    Ty_tyList p = checked_malloc(sizeof(*p));
    p->head = head;
    p->tail = tail;
    return p;
}

Ty_field Ty_Field(S_symbol name, Ty_ty ty)
{
    Ty_field p = checked_malloc(sizeof(*p));
    p->ty = ty;
    p->name = name;
    return p;
}

Ty_fieldList Ty_FieldList(Ty_field head, Ty_fieldList tail)
{
    Ty_fieldList p = checked_malloc(sizeof(*p));
    p->head = head;
    p->tail = tail;
    return p;
}

