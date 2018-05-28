//
// Created by DavidWangjp on 2018/5/17.
//

#ifndef PASCALCOMPLIER_TYPES_H
#define PASCALCOMPLIER_TYPES_H

#include <crtdbg.h>
#include "absyn.h"
#include "symbol.h"

typedef struct Ty_ty_ *Ty_ty;
typedef struct Ty_tyList_ *Ty_tyList;
typedef struct Ty_const_ *Ty_const;
typedef struct Ty_range_ *Ty_range;
typedef struct Ty_field_ *Ty_field;
typedef struct Ty_fieldList_ *Ty_fieldList;

/*
 * Save for enum
 */
typedef struct Ty_name_ *Ty_name;
typedef struct Ty_nameList_ *Ty_nameList;


enum TY_CONST
{
    TY_CONST_INT, TY_CONST_REAL, TY_CONST_CHAR, TY_CONST_STRING, TY_CONST_BOOL
};

struct Ty_const_
{
    enum TY_CONST kind;
    union
    {
        int intt;
        char *charr;
        double real;
        bool booll;
        char *string;
    } u;

};

struct Ty_ty_
{
    enum
    {
        Ty_int, Ty_real, Ty_bool, Ty_char, Ty_subrange, Ty_record,
        Ty_array, Ty_const, Ty_name, Ty_void, Ty_math, Ty_write
    } kind;
    union
    {
        Ty_range range;
        enum TY_CONST constt;
        Ty_fieldList record;
        struct
        {
//            Ty_ty range;
            Ty_ty ty;
            int leftBound, rightBound;
        } array;
        struct
        {
            S_symbol sym;
            Ty_ty ty;
        } name;
    } u;
};

struct Ty_tyList_
{
    Ty_ty head;
    Ty_tyList tail;
};

struct Ty_range_
{
    enum
    {
        Ty_const, Ty_name
    } kind;
    union
    {
        struct
        {
            Ty_const left_bound, right_bound;
        } constt;
        struct
        {
            S_symbol left_bound, right_bound;
        } name;
    } u;
};

struct Ty_field_
{
    S_symbol name;
    Ty_ty ty;
};

struct Ty_fieldList_
{
    Ty_field head;
    Ty_fieldList tail;
};

struct Ty_name_
{
    S_symbol name;
};

struct Ty_nameList_
{
    Ty_name head;
    Ty_nameList tail;
};




Ty_ty Ty_Int(void);

Ty_ty Ty_Real(void);

Ty_ty Ty_Bool(void);

Ty_ty Ty_Char(void);

Ty_ty Ty_Void(void);

Ty_ty Ty_Const_Int(void);

Ty_ty Ty_Const_Char(void);

Ty_ty Ty_Const_Bool(void);

Ty_ty Ty_Const_Real(void);

Ty_ty Ty_Const_String(void);

Ty_ty Ty_Math(void);

Ty_ty Ty_Write(void);

Ty_const Ty_Const(A_const_value const_value);

Ty_ty Ty_Const_Range(Ty_const left_bound, Ty_const right_bound);

Ty_ty Ty_Name_Range(S_symbol left_bound, S_symbol right_bound);

/*
 * Omit enum for now
 */
// Ty_ty Ty_Enum();

Ty_ty Ty_Record(Ty_fieldList fields);

//Ty_ty Ty_Array(Ty_ty range, Ty_ty ty);
Ty_ty Ty_Array(Ty_ty ty, int leftBound, int rightBound);

Ty_ty Ty_Name(S_symbol sym, Ty_ty ty);

Ty_tyList Ty_TyList(Ty_ty head, Ty_tyList tail);

Ty_field Ty_Field(S_symbol name, Ty_ty ty);

Ty_fieldList Ty_FieldList(Ty_field head, Ty_fieldList tail);


#endif //PASCALCOMPLIER_TYPES_H
