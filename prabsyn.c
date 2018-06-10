#include "prabsyn.h"

void pr_program(A_program t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("program: %d\n", t->pos);
    pr_program_head(t->program_head, layer + 1);
    pr_routine(t->routine, layer + 1);
}

void pr_program_head(A_program_head t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("program head: %d\n", t->pos);
    for (i = 0; i < layer + 1; i++)
        printf("  ");
    printf("id: %s\n", t->id);
}

void pr_routine(A_routine t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("routine: %d\n", t->pos);
    pr_routine_head(t->routine_head, layer + 1);
    pr_routine_body(t->routine_body, layer + 1);
}

void pr_sub_routine(A_sub_routine t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("sub_routine: %d\n", t->pos);
    pr_routine_head(t->routine_head, layer + 1);
    pr_routine_body(t->routine_body, layer + 1);
}

void pr_routine_head(A_routine_head t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("routine_head: %d\n", t->pos);
    if (t->label_part)
        pr_label_part(t->label_part, layer + 1);
    if (t->const_part)
        pr_const_part(t->const_part, layer + 1);
    if (t->type_part)
        pr_type_part(t->type_part, layer + 1);
    if (t->var_part)
        pr_var_part(t->var_part, layer + 1);
    if (t->routine_part)
        pr_routine_part(t->routine_part, layer + 1);
}

void pr_routine_body(A_routine_body t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("routine_body: %d\n", t->pos);
    pr_compound_stmt(t->compound_stmt, layer + 1);
}


void pr_label_part(A_label_part t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("label_part: %d\n", t->pos);
}

void pr_const_part(A_const_part t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("const_part: %d\n", t->pos);
    if (t->const_expr_list)
        pr_const_expr_list(t->const_expr_list, layer + 1);
}

void pr_type_part(A_type_part t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("type_part: %d\n", t->pos);
    if (t->type_decl_list)
        pr_type_decl_list(t->type_decl_list, layer + 1);
}

void pr_var_part(A_var_part t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("var_part: %d\n", t->pos);
    if (t->var_decl_list)
        pr_var_decl_list(t->var_decl_list, layer + 1);
}

void pr_routine_part(A_routine_part t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("routine_part: %d\n", t->pos);
    if (t->is_seq == SEQ)
        pr_routine_part(t->routine_part, layer + 1);
    if (t->kind == routine_part_function && t->u.function_decl)
        pr_function_decl(t->u.function_decl, layer + 1);
    if (t->kind == routine_part_procedure && t->u.procedure_decl)
        pr_procedure_decl(t->u.procedure_decl, layer + 1);

}

void pr_const_expr_list(A_const_expr_list t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("const_expr_list: %d\n", t->pos);
    if (t->is_seq == SEQ)
        pr_const_expr_list(t->const_expr_list, layer + 1);
    for (i = 0; i < layer + 1; i++)
        printf("  ");
    printf("id: %s\n", S_name(t->id));
    pr_const_value(t->const_value, layer + 1);
}

void pr_const_value(A_const_value t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("const_value: %d, ", t->pos);
    switch (t->kind)
    {
        case CONST_INTEGER:
        {
            printf("%d", t->u.intt);
            break;
        }
        case CONST_REAL:
        {
            printf("%lf", t->u.real);
            break;
        }
        case CONST_CHAR:
        {
            printf("%s", t->u.charr);
            break;
        }
        case CONST_STRING:
        {
            printf("%s", t->u.string);
            break;
        }
        case CONST_SYS_CON:
        {
            switch (t->u.sys_con)
            {
                case SYS_CON_FALSE:
                {
                    printf("FALSE");
                    break;
                }
                case SYS_CON_TRUE:
                {
                    printf("TRUE");
                    break;
                }
                case SYS_CON_MAXINT:
                {
                    printf("MAXINT");
                    break;
                }
            }
            break;
        }
    }
    printf("\n");
}

void pr_type_decl_list(A_type_decl_list t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("type_decl_list: %d\n", t->pos);
    if (t->is_seq == SEQ)
        pr_type_decl_list(t->type_decl_list, layer + 1);
    pr_type_definition(t->type_definition, layer + 1);
}

void pr_type_definition(A_type_definition t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("type_definition: %d\n", t->pos);
    for (i = 0; i < layer + 1; i++)
        printf("  ");
    printf("id: %s\n", S_name(t->id));
    pr_type_decl(t->type_decl, layer + 1);
}

void pr_type_decl(A_type_decl t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("type_decl: %d\n", t->pos);
    switch (t->kind)
    {
        case type_decl_simple:
        {
            pr_simple_type_decl(t->u.simple_type_decl, layer + 1);
            break;
        }
        case type_decl_record:
        {
            pr_record_type_decl(t->u.record_type_decl, layer + 1);
            break;
        }
        case type_decl_array:
        {
            pr_array_type_decl(t->u.array_type_decl, layer + 1);
            break;
        }
    }
}

void pr_simple_type_decl(A_simple_type_decl t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("simple_type_decl: %d\n", t->pos);
    switch (t->kind)
    {
        case simple_type_decl_sys_type:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("sys_type: ");
            switch (t->u.sys_type)
            {
                case T_BOOLEAN:
                {
                    printf("BOOLEAN");
                    break;
                }
                case T_CHAR:
                {
                    printf("CHAR");
                    break;
                }
                case T_INTEGER:
                {
                    printf("INTEGER");
                    break;
                }
                case T_REAL:
                {
                    printf("REAL");
                    break;
                }
            }
            printf("\n");
            break;
        }
        case simple_type_decl_id:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("id: ");
            printf("%s\n", S_name(t->u.id));
            break;
        }
        case simple_type_decl_name_list:
        {
            pr_name_list(t->u.name_list, layer + 1);
            break;
        }
        case simple_type_decl_range_const_to_const:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("range_const_to_const:\n");
            for (i = 0; i < layer + 2; i++)
                printf("  ");
            printf("from: ");
            pr_const_value(t->u.const_range.from, 0);
            for (i = 0; i < layer + 2; i++)
                printf("  ");
            printf("to: ");
            pr_const_value(t->u.const_range.to, 0);
            break;
        }
        case simple_type_decl_range_id_to_id:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("range_id_to_id:\n");
            for (i = 0; i < layer + 2; i++)
                printf("  ");
            printf("from: %s\n", S_name(t->u.id_range.from));
            for (i = 0; i < layer + 2; i++)
                printf("  ");
            printf("to: %s\n", S_name(t->u.id_range.to));
            break;
        }
    }
}

void pr_array_type_decl(A_array_type_decl t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("array_type_decl: %d\n", t->pos);
    pr_simple_type_decl(t->simple_type_decl, layer + 1);
    pr_type_decl(t->type_decl, layer + 1);
}

void pr_record_type_decl(A_record_type_decl t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("record_type_decl: %d\n", t->pos);
    pr_field_decl_list(t->field_decl_list, layer + 1);
}

void pr_field_decl_list(A_field_decl_list t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("field_decl_list: %d\n", t->pos);
    if (t->is_seq == SEQ)
        pr_field_decl_list(t->field_decl_list, layer + 1);
    pr_field_decl(t->field_decl, layer + 1);
}

void pr_field_decl(A_field_decl t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("field_decl: %d\n", t->pos);
    pr_name_list(t->name_list, layer + 1);
    pr_type_decl(t->type_decl, layer + 1);
}

void pr_name_list(A_name_list t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("name_list: %d\n", t->pos);
    if (t->is_seq == SEQ)
        pr_name_list(t->name_list, layer + 1);
    for (i = 0; i < layer + 1; i++)
        printf("  ");
    printf("id: %s\n", S_name(t->id));
}

void pr_var_decl_list(A_var_decl_list t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("var_decl_list: %d\n", t->pos);
    if (t->is_seq == SEQ)
        pr_var_decl_list(t->var_decl_list, layer + 1);
    if (t->var_decl)
        pr_var_decl(t->var_decl, layer + 1);
}

void pr_var_decl(A_var_decl t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("var_decl: %d\n", t->pos);
    pr_name_list(t->name_list, layer + 1);
    pr_type_decl(t->type_decl, layer + 1);
}

void pr_function_decl(A_function_decl t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("function_decl: %d\n", t->pos);
    pr_function_head(t->function_head, layer + 1);
    pr_sub_routine(t->sub_routine, layer + 1);
}

void pr_procedure_decl(A_procedure_decl t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("procedure_decl: %d\n", t->pos);
    pr_procedure_head(t->procedure_head, layer + 1);
    pr_sub_routine(t->sub_routine, layer + 1);
}

void pr_function_head(A_function_head t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("function_head: %d\n", t->pos);
    for (i = 0; i < layer + 1; i++)
        printf("  ");
    printf("id: %s\n", S_name(t->id));
    pr_parameters(t->parameters, layer + 1);
    pr_simple_type_decl(t->simple_type_decl, layer + 1);
}

void pr_procedure_head(A_procedure_head t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("procedure_head: %d\n", t->pos);
    for (i = 0; i < layer + 1; i++)
        printf("  ");
    printf("id: %s\n", S_name(t->id));
    pr_parameters(t->parameters, layer + 1);
}

void pr_parameters(A_parameters t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("parameters: %d\n", t->pos);
    pr_para_decl_list(t->para_decl_list, layer + 1);
}

void pr_para_decl_list(A_para_decl_list t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("para_decl_list: %d\n", t->pos);
    if (t->is_seq == SEQ)
        pr_para_decl_list(t->para_decl_list, layer + 1);
    pr_para_type_list(t->para_type_list, layer + 1);
}

void pr_para_type_list(A_para_type_list t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("para_type_list: %d\n", t->pos);
    switch (t->kind)
    {
        case para_type_list_var:
        {
            pr_var_para_list(t->u.var_para_list.var_para_list, layer + 1);
            pr_simple_type_decl(t->u.var_para_list.simple_type_decl, layer + 1);
            break;
        }
        case para_type_list_val:
        {
            pr_val_para_list(t->u.val_para_list.val_para_list, layer + 1);
            pr_simple_type_decl(t->u.val_para_list.simple_type_decl, layer + 1);
            break;
        }
    }
}

void pr_var_para_list(A_var_para_list t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("var_para_list: %d\n", t->pos);
    pr_name_list(t->name_list, layer + 1);
}

void pr_val_para_list(A_val_para_list t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("val_para_list: %d\n", t->pos);
    pr_name_list(t->name_list, layer + 1);
}

void pr_compound_stmt(A_compound_stmt t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("compound_stmt: %d\n", t->pos);
    if (t->stmt_list)
        pr_stmt_list(t->stmt_list, layer + 1);
}

void pr_stmt_list(A_stmt_list t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("stmt_list: %d\n", t->pos);
    if (t->stmt_list)
        pr_stmt_list(t->stmt_list, layer + 1);
    pr_stmt(t->stmt, layer + 1);
}

void pr_stmt(A_stmt t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("stmt: %d\n", t->pos);
    if (t->is_label == LABEL)
    {
        for (i = 0; i < layer + 1; i++)
            printf("  ");
        printf("label: %d\n", t->label);
    }
    pr_non_label_stmt(t->non_label_stmt, layer + 1);
}

void pr_non_label_stmt(A_non_label_stmt t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("non_label_stmt: %d\n", t->pos);
    switch (t->kind)
    {
        case non_label_stmt_assign:
        {
            pr_assign_stmt(t->u.assign_stmt, layer + 1);
            break;
        }
        case non_label_stmt_proc:
        {
            pr_proc_stmt(t->u.proc_stmt, layer + 1);
            break;
        }
        case non_label_stmt_compound:
        {
            pr_compound_stmt(t->u.compound_stmt, layer + 1);
            break;
        }
        case non_label_stmt_if:
        {
            pr_if_stmt(t->u.if_stmt, layer + 1);
            break;
        }
        case non_label_stmt_repeat:
        {
            pr_repeat_stmt(t->u.repeat_stmt, layer + 1);
            break;
        }
        case non_label_stmt_while:
        {
            pr_while_stmt(t->u.while_stmt, layer + 1);
            break;
        }
        case non_label_stmt_for:
        {
            pr_for_stmt(t->u.for_stmt, layer + 1);
            break;
        }
        case non_label_stmt_case:
        {
            pr_case_stmt(t->u.case_stmt, layer + 1);
            break;
        }
        case non_label_stmt_goto:
        {
            pr_goto_stmt(t->u.goto_stmt, layer + 1);
            break;
        }
    }
}

void pr_assign_stmt(A_assign_stmt t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("assign_stmt: %d\n", t->pos);
    switch (t->kind)
    {
        case assign_stmt_simple:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("id: %s\n", S_name(t->u.simple_var_assign_stmt.id));
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("right value:\n");
            pr_expression(t->u.simple_var_assign_stmt.right_expression, layer + 2);
            break;
        }
        case assign_stmt_record:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("id.field_id: %s.%s\n",
                   S_name(t->u.record_var_assign_stmt.id), S_name(t->u.record_var_assign_stmt.field_id));
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("right value:\n");
            pr_expression(t->u.record_var_assign_stmt.right_expression, layer + 2);
            break;
        }
        case assign_stmt_array:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("id: %s\n", S_name(t->u.array_var_assign_stmt.id));
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("subscript:\n");
            pr_expression(t->u.array_var_assign_stmt.subscript_expression, layer + 2);
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("right value:\n");
            pr_expression(t->u.array_var_assign_stmt.right_expression, layer + 2);
            break;
        }
    }
}

void pr_proc_stmt(A_proc_stmt t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("proc_stmt: %d\n", t->pos);
    switch (t->kind)
    {
        case proc_stmt_id:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("id: %s\n", S_name(t->u.id));
            break;
        }
        case proc_stmt_id_with_args:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("id: %s\n", S_name(t->u.id_with_args.id));
            pr_args_list(t->u.id_with_args.args_list, layer + 1);
            break;
        }
        case proc_stmt_sys_proc:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("sys_proc: ");
            switch (t->u.sys_proc)
            {
                case SYS_PROC_WRITE:
                {
                    printf("write\n");
                    break;
                }
                case SYS_PROC_WRITELN:
                {
                    printf("writeln\n");
                    break;
                }
            }
            break;
        }
        case proc_stmt_sys_proc_with_args:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("sys_proc: ");
            switch (t->u.sys_proc_with_args.sys_proc)
            {
                case SYS_PROC_WRITE:
                {
                    printf("write\n");
                    break;
                }
                case SYS_PROC_WRITELN:
                {
                    printf("writeln\n");
                    break;
                }
            }
            pr_expression_list(t->u.sys_proc_with_args.expression_list, layer + 1);
            break;
        }
        case proc_stmt_read:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("read: \n");
            pr_factor(t->u.factor, layer + 1);
            break;
        }
    }
}

void pr_if_stmt(A_if_stmt t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("if_stmt: %d\n", t->pos);
    pr_expression(t->test, layer + 1);
    pr_stmt(t->body, layer + 1);
    if (t->else_clause)
        pr_else_clause(t->else_clause, layer + 1);
}

void pr_repeat_stmt(A_repeat_stmt t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("repeat_stmt: %d\n", t->pos);
    pr_stmt_list(t->body, layer + 1);
    pr_expression(t->until, layer + 1);
}

void pr_while_stmt(A_while_stmt t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("while_stmt: %d\n", t->pos);
    pr_expression(t->test, layer + 1);
    pr_stmt(t->body, layer + 1);
}

void pr_for_stmt(A_for_stmt t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("for_stmt: %d\n", t->pos);
    for (i = 0; i < layer + 1; i++)
        printf("  ");
    printf("loop_var: %s\n", S_name(t->loop_var));
    pr_expression(t->lo, layer + 1);
    for (i = 0; i < layer + 1; i++)
        printf("  ");
    printf("direction: ");
    switch (t->direction)
    {
        case DIRECTION_DOWNTO:
        {
            printf("downto\n");
            break;
        }
        case DIRECTION_TO:
        {
            printf("to\n");
            break;
        }
    }
    pr_expression(t->hi, layer + 1);
}

void pr_case_stmt(A_case_stmt t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("case_stmt: %d\n", t->pos);
    pr_expression(t->expression, layer + 1);
    pr_case_expr_list(t->case_expr_list, layer + 1);
}

void pr_goto_stmt(A_goto_stmt t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("goto_stmt: %d\n", t->pos);
    for (i = 0; i < layer + 1; i++)
        printf("  ");
    printf("label: %d\n", t->label);
}

void pr_else_clause(A_else_clause t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("else_clause: %d\n", t->pos);
    pr_stmt(t->body, layer + 1);
}

void pr_case_expr_list(A_case_expr_list t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("case_expr_list: %d\n", t->pos);
    if (t->is_seq == SEQ)
        pr_case_expr_list(t->case_expr_list, layer + 1);
    pr_case_expr(t->case_expr, layer + 1);
}

void pr_case_expr(A_case_expr t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("case_expr: %d\n", t->pos);
    switch (t->kind)
    {
        case case_expr_const_value:
        {
            pr_const_value(t->u.const_value.const_value, layer + 1);
            pr_stmt(t->u.const_value.body, layer + 1);
            break;
        }
        case case_expr_non_const_value:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("id: %s\n", S_name(t->u.non_const_value.id));
            pr_stmt(t->u.non_const_value.body, layer + 1);
            break;
        }
    }
}

void pr_expression_list(A_expression_list t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("expression_list: %d\n", t->pos);
    if (t->is_seq == SEQ)
        pr_expression_list(t->expression_list, layer + 1);
    pr_expression(t->expression, layer + 1);
}

void pr_expression(A_expression t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("expression: %d\n", t->pos);
    if (t->is_bin_op == BINOP)
    {
        pr_expression(t->u.bin_op.left_expression, layer + 1);
        for (i = 0; i < layer + 1; i++)
            printf("  ");
        printf("rel_op: ");
        switch (t->u.bin_op.rel_op)
        {
            case OP_GE:
            {
                printf("GE\n");
                break;
            }
            case OP_GT:
            {
                printf("GT\n");
                break;
            }
            case OP_LE:
            {
                printf("LE\n");
                break;
            }
            case OP_LT:
            {
                printf("LT\n");
                break;
            }
            case OP_EQUAL:
            {
                printf("EQUAL\n");
                break;
            }
            case OP_UNEQUAL:
            {
                printf("UNEQUAL\n");
                break;
            }
        }
        pr_expr(t->u.bin_op.right_expr, layer + 1);
    }
    else
    {
        pr_expr(t->u.expr, layer + 1);
    }
}

void pr_expr(A_expr t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("expr: %d\n", t->pos);
    if (t->is_bin_op == BINOP)
    {
        pr_expr(t->u.bin_op.left_expr, layer + 1);
        for (i = 0; i < layer + 1; i++)
            printf("  ");
        printf("plus_op: ");
        switch (t->u.bin_op.plus_op)
        {
            case OP_PLUS:
            {
                printf("PLUS");
                break;
            }
            case OP_MINUS:
            {
                printf("MINUS");
                break;
            }
            case OP_OR:
            {
                printf("OR");
                break;
            }
        }
        printf("\n");
        pr_term(t->u.bin_op.right_term, layer + 1);
    }
    else
    {
        pr_term(t->u.term, layer + 1);
    }
}

void pr_term(A_term t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("term: %d\n", t->pos);
    if (t->is_bin_op == BINOP)
    {
        pr_term(t->u.bin_op.left_term, layer + 1);
        for (i = 0; i < layer + 1; i++)
            printf("  ");
        printf("mul_op: ");
        switch (t->u.bin_op.mul_op)
        {
            case OP_MUL:
            {
                printf("MUL\n");
                break;
            }
            case OP_DIV:
            {
                printf("DIV\n");
                break;
            }
            case OP_MOD:
            {
                printf("MOD\n");
                break;
            }
            case OP_AND:
            {
                printf("AND\n");
                break;
            }
        }
        pr_factor(t->u.bin_op.right_factor, layer + 1);
    }
    else
    {
        pr_factor(t->u.factor, layer + 1);
    }
}

void pr_factor(A_factor t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("factor: %d\n", t->pos);
    switch (t->kind)
    {
        case factor_id:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("id: %s\n", S_name(t->u.id));
            break;
        }
        case factor_id_with_args:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("id: %s\n", S_name(t->u.id_with_args.id));
            pr_args_list(t->u.id_with_args.args_list, layer + 1);
            break;
        }
        case factor_sys_funct:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("sys_funct: ");
            switch (t->u.sys_funct)
            {
                case SYS_FUNCT_ABS:
                {
                    printf("abs\n");
                    break;
                }
                case SYS_FUNCT_CHR:
                {
                    printf("chr\n");
                    break;
                }
                case SYS_FUNCT_ODD:
                {
                    printf("odd\n");
                    break;
                }
                case SYS_FUNCT_ORD:
                {
                    printf("ord\n");
                    break;
                }
                case SYS_FUNCT_PRED:
                {
                    printf("pred\n");
                    break;
                }
                case SYS_FUNCT_SQR:
                {
                    printf("sqr\n");
                    break;
                }
                case SYS_FUNCT_SQRT:
                {
                    printf("sqrt\n");
                    break;
                }
                case SYS_FUNCT_SUCC:
                {
                    printf("succ\n");
                    break;
                }
            }
            break;
        }
        case factor_sys_funct_with_args:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("sys_funct_with_args: ");
            switch (t->u.sys_funct_with_args.sys_funct)
            {
                case SYS_FUNCT_ABS:
                {
                    printf("abs\n");
                    break;
                }
                case SYS_FUNCT_CHR:
                {
                    printf("chr\n");
                    break;
                }
                case SYS_FUNCT_ODD:
                {
                    printf("odd\n");
                    break;
                }
                case SYS_FUNCT_ORD:
                {
                    printf("ord\n");
                    break;
                }
                case SYS_FUNCT_PRED:
                {
                    printf("pred\n");
                    break;
                }
                case SYS_FUNCT_SQR:
                {
                    printf("sqr\n");
                    break;
                }
                case SYS_FUNCT_SQRT:
                {
                    printf("sqrt\n");
                    break;
                }
                case SYS_FUNCT_SUCC:
                {
                    printf("succ\n");
                    break;
                }
            }
            pr_args_list(t->u.sys_funct_with_args.args_list, layer + 1);
            break;
        }
        case factor_const_value:
        {
            pr_const_value(t->u.const_value, layer + 1);
            break;
        }
        case factor_in_brackets:
        {
            pr_expression(t->u.expression, layer + 1);
            break;
        }
        case factor_un_op:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("un_op: ");
            switch (t->u.un_op.un_op)
            {
                case OP_NOT:
                {
                    printf("NOT\n");
                    break;
                }
                case OP_NEG:
                {
                    printf("NEG\n");
                    break;
                }
            }
            pr_factor(t->u.un_op.factor, layer + 1);
            break;
        }
        case factor_record_var:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("id.field_id: %s.%s\n", S_name(t->u.record_var.id), S_name(t->u.record_var.field_id));
            break;
        }
        case factor_array_var:
        {
            for (i = 0; i < layer + 1; i++)
                printf("  ");
            printf("id: %s\n", S_name(t->u.array_var.id));
            pr_expression(t->u.array_var.subscript_expression, layer + 1);
            break;
        }
    }
}

void pr_args_list(A_args_list t, int layer)
{
    if (t == NULL)
        return;
    int i;
    for (i = 0; i < layer; i++)
        printf("  ");
    printf("args_list: %d\n", t->pos);
    if (t->is_seq == SEQ)
        pr_args_list(t->args_list, layer + 1);
    pr_expression(t->expression, layer + 1);
}