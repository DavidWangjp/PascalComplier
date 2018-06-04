#ifndef _FRAME_H_
#define _FRAME_H_

#include "util.h"
#include "symbol.h"
#include "temp.h"
#include "tree.h"

#define F_wordSize 4

typedef struct F_frame_ *F_frame;
typedef struct F_access_ *F_access;

typedef struct F_access_List_ *F_access_List;
struct F_access_List_
{
    F_access head;
    F_access_List tail;
};

struct F_frame_
{
    Temp_label name;
    F_access_List paras;
    int offset;
};

struct F_access_
{
    enum
    {
        inFrame, inReg
    } kind;
    union
    {
        int offset;
        Temp_temp reg;
    } u;
    int size;//访问内存的大小
};

//传入名字 参数逃逸情况 参数的大小(byte) 所有变量的大小都要提供（不论是否存在寄存器中）
F_frame F_newFrame(Temp_label name, U_boolList formals, U_byteList bytes);

T_exp F_externalCall(string s, T_expList args);

Temp_label F_name(F_frame F);

F_access_List F_formals(F_frame f);

F_access F_allocLocal(F_frame f, bool escape, int size);

static F_access InFrame(int offset, int size);

static F_access InReg(Temp_temp reg);

Temp_temp F_FP(void);
Temp_temp F_RA(void);
Temp_temp F_RV(void);

T_exp F_Exp(F_access acc, T_exp framePtr);

#endif