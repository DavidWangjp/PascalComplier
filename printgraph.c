//
// Created by Sr on 2018/5/31.
//

#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "temp.h"
#include "tree.h"
#include "printgraph.h"

static int print_index = 0;

static void pr_graph_tree_stm(FILE *out, T_exp exp, int n);

static char bin_oper[][12] = {
        "PLUS", "MINUS", "TIMES", "DIVIDE",
        "AND", "OR", "LSHIFT", "RSHIFT", "ARSHIFT", "XOR"};

static char rel_oper[][12] = {
        "EQ", "NE", "LT", "GT", "LE", "GE", "ULT", "ULE", "UGT", "UGE"};

static void pr_graph_stm(FILE *out, T_stm stm, int n)
{
    switch (stm->kind)
    {
        case T_SEQ:
            fprintf(out, "node%d[label=\"SEQ\"];\n", n);
            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            pr_graph_stm(out, stm->u.SEQ.left, print_index);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            pr_graph_stm(out, stm->u.SEQ.right, print_index);
            break;
        case T_LABEL:
            fprintf(out, "node%d[label=\"LABEL\"];\n", n);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            fprintf(out, "node%d[label=\"%s\"];\n", print_index, S_name(stm->u.LABEL));
            break;
        case T_JUMP:
            fprintf(out, "node%d[label=\"JUMP\"];\n", n);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            pr_graph_tree_stm(out, stm->u.JUMP.exp, print_index);
            break;
        case T_CJUMP:
            fprintf(out, "node%d[label=\"CJUMP\"];\n", n);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            fprintf(out, "node%d[label=\"%s\"];\n", print_index, rel_oper[stm->u.CJUMP.op]);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            pr_graph_tree_stm(out, stm->u.CJUMP.left, print_index);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            pr_graph_tree_stm(out, stm->u.CJUMP.right, print_index);

            print_index++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            fprintf(out, "node%d[label=\"%s\"];\n", print_index, S_name(stm->u.CJUMP.true_label));

            print_index++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            fprintf(out, "node%d[label=\"%s\"];\n", print_index, S_name(stm->u.CJUMP.false_label));
            break;
        case T_MOVE:
            fprintf(out, "node%d[label=\"MOVE\"];\n", n);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            pr_graph_tree_stm(out, stm->u.MOVE.dst, print_index);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            pr_graph_tree_stm(out, stm->u.MOVE.src, print_index);
            break;
        case T_EXP:
            fprintf(out, "node%d[label=\"EXP\"];\n", n);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            pr_graph_tree_stm(out, stm->u.EXP, print_index);
            break;
        case T_RETURN:
            fprintf(out, "node%d[label=\"RETUEN\"];\n", n);
            break;
    }
}

static void pr_graph_tree_stm(FILE *out, T_exp exp, int n)
{
    switch (exp->kind)
    {
        case T_BINOP:
            fprintf(out, "node%d[label=\"BINOP\"];\n", n);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            fprintf(out, "node%d[label=\"%s\"];\n", print_index, bin_oper[exp->u.BINOP.op]);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            pr_graph_tree_stm(out, exp->u.BINOP.left, print_index);


            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            pr_graph_tree_stm(out, exp->u.BINOP.right, print_index);
            break;
        case T_MEM:
            fprintf(out, "node%d[label=\"MEM\"];\n", n);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            pr_graph_tree_stm(out, exp->u.MEM.exp, print_index);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            fprintf(out, "node%d[label=\"%d\"];\n", print_index, exp->u.MEM.size);
            break;
        case T_TEMP:
            fprintf(out, "node%d[label=\"TEMP\"];\n", n);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            fprintf(out, "node%d[label=\"%s\"];\n", print_index, Temp_look(Temp_name(), exp->u.TEMP));
            break;
        case T_ESEQ:
            fprintf(out, "node%d[label=\"ESEQ\"];\n", n);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            pr_graph_stm(out, exp->u.ESEQ.stm, print_index);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            pr_graph_tree_stm(out, exp->u.ESEQ.exp, print_index);
            break;
        case T_NAME:
            fprintf(out, "node%d[label=\"NAME\"];\n", n);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            fprintf(out, "node%d[label=\"%s\"];\n", print_index, S_name(exp->u.NAME));
            break;
        case T_CONST:
            fprintf(out, "node%d[label=\"CONST\"];\n", n);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            fprintf(out, "node%d[label=\"%d\"];\n", print_index, exp->u.CONST);
            break;
        case T_CALL:
        {
            T_expList args = exp->u.CALL.args;
            fprintf(out, "node%d[label=\"CALL\"];\n", n);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            pr_graph_tree_stm(out, exp->u.CALL.fun, print_index);

            for (; args; args = args->tail)
            {
                print_index ++;
                fprintf(out, "node%d->node%d;\n", n, print_index);
                pr_graph_tree_stm(out, args->head, print_index);
            }
            break;
        }
        case T_DOUBLE:
            fprintf(out, "node%d[label=\"DOUBLE\"];\n", n);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            fprintf(out, "node%d[label=\"%f\"];\n", print_index, exp->u.DOUBLE);
            break;
        case T_CHAR_:
            fprintf(out, "node%d[label=\"CHAR\"];\n", n);

            print_index ++;
            fprintf(out, "node%d->node%d;\n", n, print_index);
            fprintf(out, "node%d[label=\"%d\"];\n", print_index, exp->u.CHAR);
            break;
    } /* end of switch */
}


void print_graph_Tr_exp(FILE *out, Tr_exp exp)
{
    T_stm node = exp->u.nx;
    fprintf(out, "digraph g {\n");
    pr_graph_stm(out, node, 0);
    fprintf(out, "}\n");
}

void print_graph_Stm_List(FILE *out, T_stmList stmList)
{
    fprintf(out, "digraph g {\n");
    for (; stmList; stmList = stmList->tail)
    {
        print_index ++;
        pr_graph_stm(out, stmList->head, print_index);
    }
    fprintf(out, "}\n");
}


void print_graph_frag_exp (FILE *out, F_fragList list)
{
    fprintf(out, "digraph g {\n");
    for(; list; list=list->tail)
    {
        F_frag frag = list->head;
        if(frag->kind == F_procFrag){
            print_index ++;
            pr_graph_stm(out, frag->u.proc.body, print_index);
        }
    }
    fprintf(out, "}\n");
}