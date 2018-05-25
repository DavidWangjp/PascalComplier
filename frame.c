#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "symbol.h"
#include "temp.h"
#include "frame.h"

#define MAX_REG 32
#define MAX_ARGS_REG 4

Temp_map f_map = NULL;
Temp_temp fp = NULL;

F_access_List NewAccessList(F_frame f, U_boolList formals, U_byteList bytes)
{
    F_access_List head = NULL;
    F_access_List tail = NULL;
    U_boolList tmp_para = formals;
    U_byteList tmp_byte = bytes;
    int num_reg = 0;
    int index = 0;
    int size = 0;
    while (tmp_para)
    {
        F_access new_ac = NULL;
        //有不同
        if (tmp_para->head == FALSE && num_reg < MAX_ARGS_REG)
        {
            new_ac = InReg(Temp_newtemp());
            num_reg++;
        }
        else
        {
            size = tmp_byte->byte;
            new_ac = InFrame(index * F_wordSize, size);
            index++;
        }
        if (head == NULL)
        {
            head = checked_malloc(sizeof(*head));
            head->head = new_ac;
            head->tail = NULL;
            tail = head;
        }
        else
        {
            F_access_List tmp_ac = checked_malloc(sizeof(*tmp_ac));
            tmp_ac->head = new_ac;
            tmp_ac->tail = NULL;
            tail->tail = tmp_ac;
            tail = tmp_ac;
        }
        tmp_para = tmp_para->tail;
        tmp_byte = tmp_byte->tail;
    }
    return head;
}

F_frame F_newFrame(Temp_label name, U_boolList formals, U_byteList bytes)
{
    F_frame f = checked_malloc(sizeof(*f));
    f->name = name;
    f->paras = NewAccessList(f, formals, bytes);
    f->offset = 0;
    return f;
}

Temp_label F_name(F_frame F)
{
    return F->name;
}

F_access_List F_formals(F_frame f)
{
    return f->paras;
}

F_access F_allocLocal(F_frame f, bool escape, int size)
{
    f->offset++;
    if (escape)
        return InFrame(-F_wordSize * f->offset, size);
    else
        return InReg(Temp_newtemp());
}

static F_access InFrame(int offset, int size)
{
    F_access ac = checked_malloc(sizeof(*ac));
    ac->kind = inFrame;
    ac->u.offset = offset;
    ac->size = size;
    return ac;
}

static F_access InReg(Temp_temp reg)
{
    F_access ac = checked_malloc(sizeof(*ac));
    ac->kind = inReg;
    ac->u.reg = reg;
    return ac;
}

Temp_temp F_FP(void)
{
    if (!fp)
    {
        if (!f_map)
        {
            f_map = Temp_empty();
        }
        fp = Temp_newtemp();
        Temp_enter(f_map, fp, "ebp");
    }
    return fp;
}

T_exp F_Exp(F_access acc, T_exp framePtr)
{
    if (acc->kind == inFrame)
    {
        return T_Mem(T_Binop(T_plus, framePtr, T_Const(acc->u.offset)), acc->size);
    }
    else
    {
        return T_Temp(acc->u.reg);
    }
}

T_exp F_externalCall(string s, T_expList args)
{
    return T_Call(T_Name(Temp_namedlabel(s)), args);
}