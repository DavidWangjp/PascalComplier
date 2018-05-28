//
// Created by Sr on 2018/5/28.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "absyn.h"
#include "errormsg.h"
#include "semant.h"
#include "printtree.h"
#include "pascal.tab.c"

extern A_program root;

A_program parse(string file_name){
    EM_reset(file_name);
    if(yyparse() == 0)
        return root;
    else
        printf("syntax error!\n");
    return 0;
}

int main(int argc, string *argv)
{
    string file_name = argv[0];
    FILE *out = stdout;
    struct expty result_expty;

    parse(file_name);

    if(root == NULL)
        return 1;
//    打印抽象语法树
//    pr_program(root, 0);

    result_expty = SEM_transProg(root);

    print_Tr_exp(out, result_expty.exp);

    getchar();
    return 0;
}