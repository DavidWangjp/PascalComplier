//
// Created by Sr on 2018/6/12.
//

#include "codegen.h"
#include "assem.h"
#include "frame.h"
#include "temp.h"
#include "tree.h"

static AS_instrList iList = NULL, last = NULL;
static Temp_temp munchExp(T_exp e);
static void munchStm(T_stm s);
//static Temp_tempList munchArgs(int i, T_expList params);
extern Temp_map f_map;

Temp_tempList L(Temp_temp h, Temp_tempList t){
    return Temp_TempList(h, t);
}

static void emit(AS_instr inst){
    if(last!=NULL)
        last = last->tail = AS_InstrList(inst, NULL);
    else
        last = iList = AS_InstrList(inst, NULL);
}

AS_instrList F_codegen(F_frame f, T_stmList stmList){
    AS_instrList list;
    T_stmList  s1;
    for(s1 = stmList; s1; s1 = s1->tail)
        munchStm(s1->head);
    list = iList;
    iList = last = NULL;
    return list;
}

static void munchStm(T_stm s){
    char assemInst[80];
    char oper[10];
    if(s == NULL)
        return;
    if(s->kind == T_MOVE){
        T_exp dst = s->u.MOVE.dst;
        T_exp src = s->u.MOVE.src;

        if(dst->kind == T_TEMP){
            emit(AS_Move(String("MOVE `d0, `s0\n"), L(munchExp(dst), NULL), L(munchExp(src), NULL)));
        }
        else if(dst->kind == T_MEM){
            if(dst->u.MEM.exp->kind == T_BINOP && dst->u.MEM.exp->u.BINOP.op == T_plus){
                if(dst->u.MEM.exp->u.BINOP.right->kind == T_CONST){
                    sprintf(assemInst, "STORE M[`d0+%d] <- `s0\n", dst->u.MEM.exp->u.BINOP.right->u.CONST);
                    emit(AS_Move(String(assemInst), L(munchExp(dst->u.MEM.exp->u.BINOP.left), NULL), L(munchExp(src), NULL)));
                }
                else if(dst->u.MEM.exp->u.BINOP.left->kind == T_CONST){
                    sprintf(assemInst, "STORE M[`d0+%d] <- `s0\n", dst->u.MEM.exp->u.BINOP.left->u.CONST);
                    emit(AS_Move(String(assemInst), L(munchExp(dst->u.MEM.exp->u.BINOP.right), NULL), L(munchExp(src), NULL)));
                }
                else{
                    sprintf(assemInst, "STORE M[`d0] <- `s0\n");
                    emit(AS_Move(String(assemInst), L(munchExp(dst->u.MEM.exp), NULL), L(munchExp(src), NULL)));
                }
            }
            else if(dst->u.MEM.exp->kind == T_CONST){
                sprintf(assemInst, "STORE M[r0+%d] <- `s0\n", dst->u.MEM.exp->u.CONST);
                emit(AS_Move(String(assemInst), NULL, L(munchExp(src), NULL)));
            }
            else if(src->kind == T_MEM){
                sprintf(assemInst, "MOVEM M[`d0] <- M[`s0]\n");
                emit(AS_Move(String(assemInst), L(munchExp(dst->u.MEM.exp), NULL), L(munchExp(src->u.MEM.exp), NULL)));
            }
            else{
                sprintf(assemInst, "STORE M[`d0] <- `s0\n");
                emit(AS_Move(String(assemInst), L(munchExp(dst->u.MEM.exp), NULL), L(munchExp(src), NULL)));
            }
        }
        else{
            assert(0);
        }
    }
    else if(s->kind == T_JUMP){
        Temp_temp tmp = munchExp(s->u.JUMP.exp);
        emit(AS_Oper(String("JUMP `j0\n"), L(tmp, NULL), NULL, AS_Targets(s->u.JUMP.jumps)));
    }
    else if(s->kind == T_CJUMP){
        Temp_temp left = munchExp(s->u.CJUMP.left);
        Temp_temp right = munchExp(s->u.CJUMP.right);
        if(s->u.CJUMP.op==T_eq)
            sprintf(oper, "EQ");
        else if(s->u.CJUMP.op==T_ne)
            sprintf(oper, "NE");
        else if(s->u.CJUMP.op==T_lt)
            sprintf(oper, "LT");
        else if(s->u.CJUMP.op==T_gt)
            sprintf(oper, "GT");
        else if(s->u.CJUMP.op==T_le)
            sprintf(oper, "LE");
        else if(s->u.CJUMP.op==T_ge)
            sprintf(oper, "GE");
        else
            assert(0);
        sprintf(assemInst, "%s `s0, `s1, `j0\n", oper);
        emit(AS_Oper(String(assemInst), NULL, L(left, L(right, NULL)), AS_Targets(Temp_LabelList(s->u.CJUMP.true_label, NULL))));
    }
    else if(s->kind == T_SEQ){
        munchStm(s->u.SEQ.left);
        munchStm(s->u.SEQ.right);
    }
    else if(s->kind == T_LABEL){
        sprintf(assemInst, "%s:\n", Temp_labelstring(s->u.LABEL));
        emit(AS_Label(String(assemInst), s->u.LABEL));
    }
    else if(s->kind == T_EXP){
        munchExp(s->u.EXP);
    }
    else{
        assert(0);
    }
}

static Temp_temp munchExp(T_exp e){
    Temp_temp r = Temp_newtemp(String(".t"));
    char assemInst[80];
    char oper[10];
    char op[10];
    switch(e->kind){
        case T_TEMP:{
            return e->u.TEMP;
        }
        case T_BINOP:{
            T_exp left = e->u.BINOP.left;
            T_exp right = e->u.BINOP.right;
            if(e->u.BINOP.op == T_plus && (left->kind == T_CONST || right->kind == T_CONST)){
                if(left->kind == T_CONST){
                    sprintf(assemInst, "ADDI `d0 <- `s0 + %d\n", left->u.CONST);
                    emit(AS_Oper(String(assemInst), L(r, NULL), L(munchExp(right), NULL), NULL));
                } else{
                    sprintf(assemInst, "ADDI `d0 <- `s0 + %d\n", right->u.CONST);
                    emit(AS_Oper(String(assemInst), L(r, NULL), L(munchExp(left), NULL), NULL));
                }
            }
            else{
                switch (e->u.BINOP.op){
                    case T_plus:
                        sprintf(oper, "ADD");
                        sprintf(op, "+");
                        break;
                    case T_mul:
                        sprintf(oper, "MUL");
                        sprintf(op, "*");
                        break;
                    case T_minus:
                        sprintf(oper, "SUB");
                        sprintf(op, "-");
                        break;
                    case T_div:
                        sprintf(oper, "DIV");
                        sprintf(op, "/");
                        break;
                }
                sprintf(assemInst, "%s `d0 <- `s0 %s `s1\n", oper, op);
                emit(AS_Oper(String(assemInst), L(r,NULL), L(munchExp(left), L(munchExp(right), NULL)), NULL));
            }
            return r;
        }
        case T_MEM:{
            T_exp mem = e->u.MEM.exp;
            if(mem->kind == T_BINOP && mem->u.BINOP.op == T_plus){
                T_exp left = mem->u.BINOP.left;
                T_exp right = mem->u.BINOP.right;
                if(left->kind == T_CONST){
                    sprintf(assemInst, "LOAD `d0 <- M[`s0+%d]\n", left->u.CONST);
                    emit(AS_Oper(String(assemInst), L(r, NULL), L(munchExp(right), NULL), NULL));
                }
                else if(right->kind == T_CONST){
                    sprintf(assemInst, "LOAD `d0 <- M[`s0+%d]\n", right->u.CONST);
                    emit(AS_Oper(String(assemInst), L(r, NULL), L(munchExp(left), NULL), NULL));
                }
                else{
                    emit(AS_Oper("LOAD `d0 <- M[`s0+0]\n", L(r,NULL), L(munchExp(mem), NULL), NULL));
                }
            }
            else if (mem->kind == T_CONST){
                sprintf(assemInst, "LOAD `d0 <- M[r0+%d]\n", mem->u.CONST);
                emit(AS_Oper(String(assemInst), L(r, NULL), NULL, NULL));
            }
            else{
                emit(AS_Oper("LOAD `d0 <- M[`s0+0]\n", L(r,NULL), L(munchExp(mem), NULL), NULL));
            }
            return r;
        }
        case T_ESEQ:{
            munchStm(e->u.ESEQ.stm);
            return munchExp(e->u.ESEQ.exp);
        }
        case T_NAME:{
            Temp_enter(f_map, r, Temp_labelstring(e->u.NAME));
            return r;
        }
        case T_CONST:{
            sprintf(assemInst, "ADDI `d0 <- r0+%d\n", e->u.CONST);
            emit(AS_Oper(String(assemInst), L(r, NULL), NULL, NULL));
            return r;
        }
//        case T_CALL:{
//            Temp_tempList l = munchArgs(0, e->u.CALL.args);
//            r = munchExp(e->u.CALL.fun);
//#warning 有问题
//            emit(AS_Oper("CALL `s0\n", NULL, L(r, l) ,NULL));
//            return r;
//        }
    }
    printf("munchExp error!\n");
    assert(0);
}