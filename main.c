#include <stdio.h>

#include "util.h"
#include "absyn.h"
#include "errormsg.h"
#include "semant.h"
#include "printtree.h"
#include "assem.h"
#include "canon.h"
#include "printgraph.h"
#include "assem.h"
#include "codegen.h"

extern int yyparse(void);
extern Temp_map f_map;

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
    T_stmList stmList;
    AS_instrList iList;

    stmList = C_linearize(body);
    stmList = C_traceSchedule(C_basicBlocks(stmList));
//    printStmList(stdout, stmList);
    print_graph_Stm_List(out, stmList);

    iList  = F_codegen(frame, stmList);

    fprintf(stdout, "BEGIN %s\n", Temp_labelstring(frame->name));
    AS_printInstrList (stdout, iList, Temp_layerMap(f_map,Temp_name()));
    fprintf(stdout, "END %s\n\n", Temp_labelstring(frame->name));
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

    fragList = SEM_transProg(root);

//    print_graph_frag_exp(graph_out, fragList);
    doProc(graph_out, fragList->head->u.proc.frame, fragList->head->u.proc.body);

    return 0;
}
