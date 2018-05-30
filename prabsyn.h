#ifndef _PRABSYN_H_
#define _PRABSYN_H_

#include <stdio.h>

#include "absyn.h"


void pr_program(A_program t, int layer);
void pr_program_head(A_program_head t, int layer);
void pr_routine(A_routine t, int layer);
void pr_routine_head(A_routine_head t, int layer);
void pr_routine_body(A_routine_body t, int layer);

void pr_label_part(A_label_part t, int layer);
void pr_const_part(A_const_part t, int layer);
void pr_type_part(A_type_part t, int layer);
void pr_var_part(A_var_part t, int layer);
void pr_routine_part(A_routine_part t, int layer);

void pr_const_expr_list(A_const_expr_list t, int layer);
void pr_const_value(A_const_value t, int layer);

void pr_type_decl_list(A_type_decl_list t, int layer);
void pr_type_definition(A_type_definition t, int layer);
void pr_type_decl(A_type_decl t, int layer);
void pr_simple_type_decl(A_simple_type_decl t, int layer);
void pr_array_type_decl(A_array_type_decl t, int layer);
void pr_record_type_decl(A_record_type_decl t, int layer);
void pr_field_decl_list(A_field_decl_list t, int layer);
void pr_field_decl(A_field_decl t, int layer);
void pr_name_list(A_name_list t, int layer);
void pr_var_decl_list(A_var_decl_list t, int layer);
void pr_var_decl(A_var_decl t, int layer);

void pr_function_decl(A_function_decl t, int layer);
void pr_procedure_decl(A_procedure_decl t, int layer);
void pr_function_head(A_function_head t, int layer);
void pr_procedure_head(A_procedure_head t, int layer);
void pr_parameters(A_parameters t, int layer);
void pr_para_decl_list(A_para_decl_list t, int layer);
void pr_para_type_list(A_para_type_list t, int layer);
void pr_var_para_list(A_var_para_list t, int layer);
void pr_val_para_list(A_val_para_list t, int layer);

void pr_compound_stmt(A_compound_stmt t, int layer);
void pr_stmt_list(A_stmt_list t, int layer);
void pr_stmt(A_stmt t, int layer);
void pr_non_label_stmt(A_non_label_stmt t, int layer);

void pr_assign_stmt(A_assign_stmt t, int layer);
void pr_proc_stmt(A_proc_stmt t, int layer);
void pr_if_stmt(A_if_stmt t, int layer);
void pr_repeat_stmt(A_repeat_stmt t, int layer);
void pr_while_stmt(A_while_stmt t, int layer);
void pr_for_stmt(A_for_stmt t, int layer);
void pr_case_stmt(A_case_stmt t, int layer);
void pr_goto_stmt(A_goto_stmt t, int layer);

void pr_else_clause(A_else_clause t, int layer);
void pr_case_expr_list(A_case_expr_list t, int layer);
void pr_case_expr(A_case_expr t, int layer);
void pr_expression_list(A_expression_list t, int layer);
void pr_expression(A_expression t, int layer);
void pr_expr(A_expr t, int layer);
void pr_term(A_term t, int layer);
void pr_factor(A_factor t, int layer);
void pr_args_list(A_args_list t, int layer);


#endif // prabsyn.h