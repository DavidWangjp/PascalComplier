/* function prototype from printtree.c */
#ifndef PASCALCOMPLIER_PRINTTREE_H
#define PASCALCOMPLIER_PRINTTREE_H

#include "translate.h"
void printStmList (FILE *out, T_stmList stmList) ;

void print_Tr_exp (FILE *out, Tr_exp exp) ;

void print_frag_exp (FILE *out, F_fragList list) ;

#endif