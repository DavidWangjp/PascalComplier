#include <stdio.h>

#include "util.h"
#include "absyn.h"
#include "errormsg.h"
#include "semant.h"
#include "printtree.h"
#include "printgraph.h"
#include "prabsyn.h"

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
     pr_program(root, 0);


    fragList = SEM_transProg(root);

    print_frag_exp(tree_out, fragList);

    print_graph_frag_exp(graph_out, fragList);

    return 0;
}
