//
// Created by DavidWangjp on 2018/6/1.
//

#include <stdio.h>
#include "escape.h"
#include "table.h"

static bool escape = TRUE;

void traverse(S_table escenv, S_table venv, A_routine_head head, A_routine_body body);

void traverseStmt(S_table escenv, S_table venv, A_stmt stmt);

void traverseExpression(S_table escenv, S_table venv, A_expression expression);

void traverseStmts(S_table escenv, S_table venv, A_stmt_list stmts);

void traverseExpr(S_table escenv, S_table venv, A_expr expr);

void traverseTerm(S_table escenv, S_table venv, A_term term);

void traverseFactor(S_table escenv, S_table venv, A_factor factor);

S_table ESC_findEscape(A_routine_head head, A_routine_body body)
{
    S_table venv = S_empty();
    S_table esvenv = S_empty();
    S_beginScope(venv);
    traverse(esvenv, venv, head, body);
    S_endScope(venv);
    return esvenv;
}

void traverse(S_table escenv, S_table venv, A_routine_head head, A_routine_body body)
{
    for (A_routine_part l = head->routine_part; l; l = l->routine_part)
    {
        switch (l->kind)
        {
            case routine_part_function:
            {

                S_table escape_paras = NULL;
                int pos = 0;
                bool flag = FALSE;
                for (A_para_decl_list pl = l->u.function_decl->function_head->parameters->para_decl_list; pl; pl = pl->para_decl_list)
                {
                    switch (pl->para_type_list->kind)
                    {
                        case para_type_list_var:
                        {
                            if (!flag)
                            {
                                flag = TRUE;
                                escape_paras = S_empty();
                            }
                            char label[10];
                            sprintf(label, "%d", pos);
                            S_enter(escape_paras, S_Symbol(label), &escape);
                            pos++;
                            break;
                        }
                        case para_type_list_val:
                        {
                            for (A_name_list nl = pl->para_type_list->u.val_para_list.val_para_list->name_list; nl; nl = nl->name_list)
                            {
                                pos++;
                            }
                            break;
                        }
                    }
                }
                if (flag)
                    S_enter(venv, l->u.function_decl->function_head->id, escape_paras);
                break;
            }
            case routine_part_procedure:
            {
                S_table escape_paras = NULL;
                int pos = 0;
                bool flag = FALSE;
                for (A_para_decl_list pl = l->u.function_decl->function_head->parameters->para_decl_list; pl; pl = pl->para_decl_list)
                {
                    switch (pl->para_type_list->kind)
                    {
                        case para_type_list_var:
                        {
                            if (!flag)
                            {
                                flag = TRUE;
                                escape_paras = S_empty();
                            }
                            for (A_name_list nl = pl->para_type_list->u.var_para_list.var_para_list->name_list; nl; nl = nl->name_list)
                            {
                                char label[10];
                                sprintf(label, "%d", pos);
                                S_enter(escape_paras, S_Symbol(label), &escape);
                                pos++;
                            }
                            break;
                        }
                        case para_type_list_val:
                        {
                            for (A_name_list nl = pl->para_type_list->u.val_para_list.val_para_list->name_list; nl; nl = nl->name_list)
                            {
                                pos++;
                            }
                            break;
                        }
                    }
                }
                if (flag)
                    S_enter(venv, l->u.function_decl->function_head->id, escape_paras);
                break;
            }
        }
    }
    traverseStmts(escenv, venv, body->compound_stmt->stmt_list);
    for (A_routine_part l = head->routine_part; l; l = l->routine_part)
    {
        S_beginScope(venv);
        switch (l->kind)
        {

            case routine_part_function:
            {
                traverse(escenv, venv, l->u.function_decl->sub_routine->routine_head,
                         l->u.function_decl->sub_routine->routine_body);
                break;
            }
            case routine_part_procedure:
            {
                traverse(escenv, venv, l->u.procedure_decl->sub_routine->routine_head,
                         l->u.procedure_decl->sub_routine->routine_body);
                break;
            }
        }
    }
}

void traverseStmts(S_table escenv, S_table venv, A_stmt_list stmts)
{
    for (A_stmt_list l = stmts; l; l = l->stmt_list)
    {
        traverseStmt(escenv, venv, l->stmt);
    }
}

void traverseStmt(S_table escenv, S_table venv, A_stmt stmt)
{
    switch (stmt->non_label_stmt->kind)
    {

        case non_label_stmt_assign:
        {
            switch (stmt->non_label_stmt->u.assign_stmt->kind)
            {

                case assign_stmt_simple:
                {
                    traverseExpression(escenv, venv,
                                       stmt->non_label_stmt->u.assign_stmt->u.simple_var_assign_stmt.right_expression);
                    break;
                }
                case assign_stmt_record:
                {
                    traverseExpression(escenv, venv,
                                       stmt->non_label_stmt->u.assign_stmt->u.record_var_assign_stmt.right_expression);

                    break;
                }
                case assign_stmt_array:
                {
                    traverseExpression(escenv, venv,
                                       stmt->non_label_stmt->u.assign_stmt->u.array_var_assign_stmt.right_expression);

                    break;
                }
            }
            break;
        }
        case non_label_stmt_proc:
        {
            switch (stmt->non_label_stmt->u.proc_stmt->kind)
            {

                case proc_stmt_id:
                    break;
                case proc_stmt_id_with_args:
                {
                    S_table escape_paras = (S_table) S_look(venv, stmt->non_label_stmt->u.proc_stmt->u.id_with_args.id);
                    if (escape_paras)
                    {
                        int pos = 0;
                        for (A_args_list l = stmt->non_label_stmt->u.proc_stmt->u.id_with_args.args_list; l; l = l->args_list)
                        {
                            if (l->expression->is_bin_op == NONBINOP &&
                                l->expression->u.expr->is_bin_op == NONBINOP &&
                                l->expression->u.expr->u.term->is_bin_op == NONBINOP &&
                                l->expression->u.expr->u.term->u.factor->kind == factor_id)
                            {
                                char label[10];
                                sprintf(label, "%d", pos);
                                void *find = S_look(escape_paras, S_Symbol(label));
                                if (find)
                                    S_enter(escenv, l->expression->u.expr->u.term->u.factor->u.id, &escape);
                                pos++;
                            }
                            else
                            {
                                traverseExpression(escenv, venv, l->expression);
                                pos++;
                            }
                        }
                    }

                    break;
                }
                case proc_stmt_sys_proc:
                    break;
                case proc_stmt_sys_proc_with_args:
                    break;
                case proc_stmt_read:
                    break;
            }
            break;
        }
        case non_label_stmt_compound:
        {
            traverseStmts(escenv, venv, stmt->non_label_stmt->u.compound_stmt->stmt_list);
            break;
        }
        case non_label_stmt_if:
        {
            traverseExpression(escenv, venv, stmt->non_label_stmt->u.if_stmt->test);
            traverseStmt(escenv, venv, stmt->non_label_stmt->u.if_stmt->body);
            if (stmt->non_label_stmt->u.if_stmt->else_clause)
                traverseStmt(escenv, venv, stmt->non_label_stmt->u.if_stmt->else_clause->body);

            break;
        }
        case non_label_stmt_repeat:
        {
            traverseStmts(escenv, venv, stmt->non_label_stmt->u.repeat_stmt->body);
            traverseExpression(escenv, venv, stmt->non_label_stmt->u.repeat_stmt->until);
            break;
        }
        case non_label_stmt_while:
        {
            traverseExpression(escenv, venv, stmt->non_label_stmt->u.while_stmt->test);
            traverseStmt(escenv, venv, stmt->non_label_stmt->u.while_stmt->body);
            break;
        }
        case non_label_stmt_for:
        {
            traverseExpression(escenv, venv, stmt->non_label_stmt->u.for_stmt->hi);
            traverseExpression(escenv, venv, stmt->non_label_stmt->u.for_stmt->lo);
            traverseStmt(escenv, venv, stmt->non_label_stmt->u.for_stmt->body);
            break;
        }
        case non_label_stmt_case:
        {
            traverseExpression(escenv, venv, stmt->non_label_stmt->u.case_stmt->expression);
            for (A_case_expr_list l = stmt->non_label_stmt->u.case_stmt->case_expr_list; l; l = l->case_expr_list)
            {
                switch (l->case_expr->kind)
                {

                    case case_expr_const_value:
                    {
                        traverseStmt(escenv, venv, l->case_expr->u.const_value.body);
                        break;
                    }
                    case case_expr_non_const_value:
                    {
                        traverseStmt(escenv, venv, l->case_expr->u.non_const_value.body);
                        break;
                    }
                }
            }
            break;
        }
        case non_label_stmt_goto:
        {
            break;
        }
    }
}

void traverseExpression(S_table escenv, S_table venv, A_expression expression)
{
    switch (expression->is_bin_op)
    {

        case NONBINOP:
        {
            traverseExpr(escenv, venv, expression->u.expr);
            break;
        }
        case BINOP:
        {
            traverseExpression(escenv, venv, expression->u.bin_op.left_expression);
            traverseExpr(escenv, venv, expression->u.bin_op.right_expr);
            break;
        }
    }

}

void traverseExpr(S_table escenv, S_table venv, A_expr expr)
{
    switch (expr->is_bin_op)
    {

        case NONBINOP:
        {
            traverseTerm(escenv, venv, expr->u.term);
            break;
        }
        case BINOP:
        {
            traverseExpr(escenv, venv, expr->u.bin_op.left_expr);
            traverseTerm(escenv, venv, expr->u.bin_op.right_term);
            break;
        }
    }
}

void traverseTerm(S_table escenv, S_table venv, A_term term)
{
    switch (term->is_bin_op)
    {

        case NONBINOP:
        {
            traverseFactor(escenv, venv, term->u.factor);
            break;
        }
        case BINOP:
        {
            traverseTerm(escenv, venv, term->u.bin_op.left_term);
            traverseFactor(escenv, venv, term->u.bin_op.right_factor);
            break;
        }
    }
}

void traverseFactor(S_table escenv, S_table venv, A_factor factor)
{
    switch (factor->kind)
    {

        case factor_id:
            break;
        case factor_id_with_args:
        {
            S_table escape_paras = (S_table) S_look(venv, factor->u.id_with_args.id);
            if (escape_paras)
            {
                int pos = 0;
                for (A_args_list l = factor->u.id_with_args.args_list; l; l = l->args_list)
                {
                    if (l->expression->is_bin_op == NONBINOP &&
                        l->expression->u.expr->is_bin_op == NONBINOP &&
                        l->expression->u.expr->u.term->is_bin_op == NONBINOP &&
                        l->expression->u.expr->u.term->u.factor->kind == factor_id)
                    {
                        char label[10];
                        sprintf(label, "%d", pos);
                        void *find = S_look(escape_paras, S_Symbol(label));
                        if (find)
                            S_enter(escenv, l->expression->u.expr->u.term->u.factor->u.id, &escape);
                        pos++;
                    }
                    else
                    {
                        traverseExpression(escenv, venv, l->expression);
                        pos++;
                    }
                }
            }
            break;
        }
        case factor_sys_funct:
            break;
        case factor_sys_funct_with_args:
            break;
        case factor_const_value:
            break;
        case factor_in_brackets:
            break;
        case factor_un_op:
            break;
        case factor_array_var:
            break;
        case factor_record_var:
            break;
    }
}


