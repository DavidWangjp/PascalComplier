#ifndef _TRANSLATE_H_
#define _TRANSLATE_H_

#include "temp.h"
#include "tree.h"
#include "frame.h"
#include "absyn.h"

typedef struct Tr_exp_ *Tr_exp;
typedef struct Tr_expList_ *Tr_expList;
typedef struct Tr_stm_ *Tr_stm;
typedef struct Tr_level_ *Tr_level;
typedef struct Tr_access_ *Tr_access;
typedef struct Tr_accessList_ *Tr_accessList;
typedef struct patchList_ *patchList;

struct patchList_
{
    Temp_label *head;
    patchList tail;
};

struct Cx
{
    patchList trues;
    patchList falses;
    T_stm stm;
};

struct Tr_exp_
{
    enum
    {
        Tr_ex, Tr_nx, Tr_cx
    } kind;
    union
    {
        T_exp ex;
        T_stm nx;
        struct Cx cx;
    } u;
};

struct Tr_expList_
{
    Tr_exp head;
    Tr_expList tail;
};

struct Tr_level_
{
    Tr_level parent;
    F_frame frame;
};

struct Tr_access_
{
    Tr_level level;
    F_access access;
};

struct Tr_accessList_
{
    Tr_access head;
    Tr_accessList tail;
};

//将label加入list中
static patchList PatchList(Temp_label *head, patchList tail);

//填充标号
void doPatch(patchList tList, Temp_label label);

//合并patchlist
patchList joinPatch(patchList first, patchList second);

//合并Tr_accesslist
Tr_accessList Tr_AccessList(Tr_access head, Tr_accessList tail);

//最外层的level
Tr_level Tr_outermost(void);

//在调用函数的时候定义一个新的level
Tr_level Tr_NewLevel(Tr_level parent, Temp_label name, U_boolList formals);

//返回当前变量的所有堆栈里的所有变量
Tr_accessList Tr_formals(Tr_level level);

//定义一个新的变量
Tr_access Tr_AllocLocal(Tr_level level, bool escape, int size);

//创建新的基础Ex Nx Cx中间树
Tr_exp Tr_Ex(T_exp ex);

Tr_exp Tr_Nx(T_stm nx);

Tr_exp Tr_Cx(patchList trues, patchList falses, T_stm stm);

//类型转换
static T_exp unEx(Tr_exp e);

static T_stm unNx(Tr_exp e);

static struct Cx unCx(Tr_exp e);

//简单变量
Tr_exp Tr_SimpleVar(Tr_access acc, Tr_level level);

//数组下标变量 传递数组变量基地址 下标 下标可以是一个表达式 访问内存的大小
Tr_exp Tr_SubscriptVar(Tr_exp base, Tr_exp e, int size);

//record变量 传递简单变量基地值 成员偏移量 访问内存的大小
Tr_exp Tr_RecordVar(Tr_exp base, int offset, int size);

//算数操作 进行+ - | 操作
Tr_exp Tr_PlusArithExp(A_plus_op op, Tr_exp left, Tr_exp right);

//算数操作 进行* / % & 操作
Tr_exp Tr_MulArithExp(A_mul_op op, Tr_exp left, Tr_exp right);

//表达式
Tr_exp Tr_IntExp(int i);

Tr_exp Tr_BoolExp(bool i);

Tr_exp Tr_RealExp(double i);

Tr_exp Tr_CharExp(char i);


//传递字符串和数组 数组元素个数 依次的值 每个成员的所占内存
Tr_exp Tr_ArrayExp(Tr_exp n, Tr_expList es, int size);

//传递record 对象总大小 每个成员的值 成员值所占的内存
Tr_exp Tr_RecordExp(int n, Tr_expList es, U_byteList bytes);

//if e1 then e2 else e3    case语句在sement改成if
Tr_exp Tr_IfExp(Tr_exp e1, Tr_exp e2, Tr_exp e3);

//while cond body done done是一个label  for语句在semant改成while
Tr_exp Tr_WhileExp(Tr_exp cond, Tr_exp body, Tr_exp done);

//函数调用
Tr_exp Tr_CallExp(Temp_label label, Tr_level def_l, Tr_level call_l, Tr_expList paras);

//赋值
Tr_exp Tr_AssignExp(Tr_exp left, Tr_exp right);

//GOTO
Tr_exp Tr_GotoExp(Tr_exp done);

//比较
Tr_exp Tr_RelExp(A_rel_op op, Tr_exp left, Tr_exp right);

Tr_expList Tr_ExpList(Tr_exp head, Tr_expList tail);

Tr_exp Tr_SeqExp(Tr_exp left, Tr_exp right);

Tr_exp Tr_LabelExp(Temp_label label);

Tr_exp Tr_NullExp(void);

Tr_exp Tr_MinusExp(Tr_exp e);

Tr_exp Tr_RtnAddress(void);

Tr_access Tr_RtnValue(int size);

#endif