#include <stdio.h>

#include "util.h"
#include "absyn.h"
#include "errormsg.h"
#include "semant.h"
#include "printtree.h"
#include "assem.h"
#include "canon.h"
#include "printgraph.h"

extern int yyparse(void);

A_program root;

A_program parse(string file_name)
{
    EM_reset(file_name);
    if (yyparse() == 0)
        return root;
    else
        printf("syntax error!\n");
    return 0;
}

/* print the assembly language instructions to filename.s */
static void doProc(FILE *out, F_frame frame, T_stm body)
{
    AS_proc proc;
    T_stmList stmList;
    AS_instrList iList;

    stmList = C_linearize(body);
    stmList = C_traceSchedule(C_basicBlocks(stmList));
    printStmList(stdout, stmList);
//  iList = F_codegen(frame, stmList); /* 9 */
//
//  fprintf(out, "BEGIN %s\n", Temp_labelstring(F_name(frame)));
//  AS_printInstrList(out, iList,
//                    Temp_layerMap(F_tempMap, Temp_name()));
//  fprintf(out, "END %s\n\n", Temp_labelstring(F_name(frame)));
}

int main(int argc, string *argv)
{
    root = NULL;
    string file_name = argv[1];
    FILE *tree_out = stdout;
    FILE *graph_out;
    graph_out = fopen("graph.dot", "w+");
    F_fragList fragList;

    parse(file_name);

//    if (root != NULL)
//    {
//        pr_program(root, 0);
//        return 1;
//    }

    //打印抽象语法树
//     pr_program(root, 0);


    fragList = SEM_transProg(root);

    print_frag_exp(tree_out, fragList);

//    doProc(tree_out, fragList->head->u.proc.frame, fragList->head->u.proc.body);
    print_graph_frag_exp(graph_out, fragList);

    return 0;
}
