//
// Created by Sr on 2018/5/31.
//

#ifndef PASCALCOMPLIER_PRINTGRAPH_H
#define PASCALCOMPLIER_PRINTGRAPH_H


#include "translate.h"

void print_graph_Tr_exp (FILE *out, Tr_exp exp);

void print_graph_frag_exp (FILE *out, F_fragList list);

void print_graph_Stm_List(FILE *out, T_stmList stmList);

#endif //PASCALCOMPLIER_PRINTGRAPH_H
