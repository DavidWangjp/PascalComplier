#include <stdio.h>

#include "util.h"
#include "absyn.h"
#include "errormsg.h"
#include "semant.h"
#include "printtree.h"
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
    FILE *out = stdout;
    struct expty result_expty;

    parse(file_name);

//    if (root != NULL)
//    {
//        pr_program(root, 0);
//        return 1;
//    }

     //打印抽象语法树
//     pr_program(root, 0);


    result_expty = SEM_transProg(root);

    print_Tr_exp(out, result_expty.exp);

    getchar();
    return 0;
}
