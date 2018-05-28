#include <stdio.h>

#include "util.h"
#include "absyn.h"

A_program A_Program(A_pos pos, A_program_head program_head, A_routine routine)
{
    A_program p = (A_program) checked_malloc(sizeof(struct A_program_));
    p->pos = pos;
    p->program_head = program_head;
    p->routine = routine;
    return p;
}

A_program_head A_ProgramHead(A_pos pos, char *id)
{
    A_program_head p = (A_program_head) checked_malloc(sizeof(struct A_program_head_));
    p->pos = pos;
    p->id = id;
    return p;
}

A_routine A_Routine(A_pos pos, A_routine_head routine_head, A_routine_body routine_body)
{
    A_routine p = (A_routine) checked_malloc(sizeof(struct A_routine_));
    p->pos = pos;
    p->routine_head = routine_head;
    p->routine_body = routine_body;
    return p;
}

A_sub_routine A_SubRoutine(A_pos pos, A_routine_head routine_head, A_routine_body routine_body)
{
    A_sub_routine p = (A_sub_routine) checked_malloc(sizeof(struct A_sub_routine_));
    p->pos = pos;
    p->routine_head = routine_head;
    p->routine_body = routine_body;
    return p;
}

A_routine_head
A_RoutineHead(A_pos pos, A_label_part label_part, A_const_part const_part, A_type_part type_part, A_var_part var_part,
              A_routine_part routine_part)
{
    A_routine_head p = (A_routine_head) checked_malloc(sizeof(struct A_routine_head_));
    p->pos = pos;
    p->label_part = label_part;
    p->const_part = const_part;
    p->type_part = type_part;
    p->var_part = var_part;
    p->routine_part = routine_part;
    return p;
}

A_routine_body A_RoutineBody(A_pos pos, A_compound_stmt compound_stmt)
{
    A_routine_body p = (A_routine_body) checked_malloc(sizeof(struct A_routine_body_));
    p->pos = pos;
    p->compound_stmt = compound_stmt;
    return p;
}

A_label_part A_LabelPart(A_pos pos)
{
    A_label_part p = (A_label_part) checked_malloc(sizeof(struct A_label_part_));
    p->pos = pos;
    return p;
}

A_const_part A_ConstPart(A_pos pos, A_const_expr_list const_expr_list)
{
    A_const_part p = (A_const_part) checked_malloc(sizeof(struct A_const_part_));
    p->pos = pos;
    p->const_expr_list = const_expr_list;
    return p;
}

A_type_part A_TypePart(A_pos pos, A_type_decl_list type_decl_list)
{
    A_type_part p = (A_type_part) checked_malloc(sizeof(struct A_type_part_));
    p->pos = pos;
    p->type_decl_list = type_decl_list;
    return p;
}

A_var_part A_VarPart(A_pos pos, A_var_decl_list var_decl_list)
{
    A_var_part p = (A_var_part) checked_malloc(sizeof(struct A_var_part_));
    p->pos = pos;
    p->var_decl_list = var_decl_list;
    return p;
}


A_routine_part A_RoutinePartSeqWithProcedureDecl(A_pos pos, A_routine_part routine_part, A_procedure_decl procedure_decl)
{
    A_routine_part p = (A_routine_part) checked_malloc(sizeof(struct A_routine_part_));
    p->pos = pos;
    p->is_seq = SEQ;
    p->routine_part = routine_part;
    p->kind = routine_part_procedure;
    p->u.procedure_decl = procedure_decl;
    return p;
}

A_routine_part A_RoutinePartSeqWithFunctionDecl(A_pos pos, A_routine_part routine_part, A_function_decl function_decl)
{
    A_routine_part p = (A_routine_part) checked_malloc(sizeof(struct A_routine_part_));
    p->pos = pos;
    p->is_seq = SEQ;
    p->routine_part = routine_part;
    p->kind = routine_part_function;
    p->u.function_decl = function_decl;
    return p;
}

A_routine_part A_RoutinePartWithProcedureDecl(A_pos pos, A_procedure_decl procedure_decl)
{
    A_routine_part p = (A_routine_part) checked_malloc(sizeof(struct A_routine_part_));
    p->pos = pos;
    p->is_seq = NONSEQ;
    p->routine_part = NULL;
    p->kind = routine_part_procedure;
    p->u.procedure_decl = procedure_decl;
    return p;
}

A_routine_part A_RoutinePartWithFunctionDecl(A_pos pos, A_function_decl function_decl)
{
    A_routine_part p = (A_routine_part) checked_malloc(sizeof(struct A_routine_part_));
    p->pos = pos;
    p->is_seq = NONSEQ;
    p->routine_part = NULL;
    p->kind = routine_part_function;
    p->u.function_decl = function_decl;
    return p;
}


/*A_routine_part A_RoutinePartWithFunctionDecl(A_pos pos, A_function_decl function_decl, A_routine_part_prime routine_part_prime) {
    A_routine_part p = (A_routine_part) checked_malloc(sizeof(struct A_routine_part_));
    p->pos = pos;
    p->kind = p->routine_part_function;
    p->u.function_decl = function_decl;
    p->routine_part_prime = routine_part_prime;
    return p;
}

A_routine_part A_RoutinePartWithProcedureDecl(A_pos pos, A_procedure_decl procedure_decl, A_routine_part_prime routine_part_prime) {
    A_routine_part p = (A_routine_part) checked_malloc(sizeof(struct A_routine_part_));
    p->pos = pos;
    p->kind = p->routine_part_procedure;
    p->u.procedure_decl = procedure_decl;
    p->routine_part_prime = routine_part_prime;
    return p;
}

A_routine_part_prime A_RoutinePartPrimeWithFunctionDecl(A_pos pos, A_function_decl function_decl, A_routine_part_prime routine_part_prime) {
    A_routine_part_prime p = (A_routine_part_prime) checked_malloc(sizeof(struct A_routine_part_prime_));
    p->pos = pos;
    p->kind = p->routine_part_prime_function;
    p->u.function_decl = function_decl;
    p->routine_part_prime = routine_part_prime;
    return p;
}

A_routine_part_prime A_RoutinePartPrimeWithProcedureDecl(A_pos pos, A_procedure_decl procedure_decl, A_routine_part_prime routine_part_prime) {
    A_routine_part_prime p = (A_routine_part_prime) checked_malloc(sizeof(struct A_routine_part_prime_));
    p->pos = pos;
    p->kind = p->routine_part_prime_procedure;
    p->u.procedure_decl = procedure_decl;
    p->routine_part_prime = routine_part_prime;
    return p;
}*/


//A_const_expr_list A_ConstExprListSeq(A_pos pos, A_const_expr_list const_expr_list, char *id, A_const_value const_value)
A_const_expr_list
A_ConstExprListSeq(A_pos pos, A_const_expr_list const_expr_list, S_symbol id, A_const_value const_value)
{
    A_const_expr_list p = (A_const_expr_list) checked_malloc(sizeof(struct A_const_expr_list_));
    p->pos = pos;
    p->is_seq = SEQ;
    p->const_expr_list = const_expr_list;
    p->id = id;
    p->const_value = const_value;
    return p;
}

// A_const_expr_list A_ConstExprList(A_pos pos, char *id, A_const_value const_value)
A_const_expr_list A_ConstExprList(A_pos pos, S_symbol id, A_const_value const_value)
{
    A_const_expr_list p = (A_const_expr_list) checked_malloc(sizeof(struct A_const_expr_list_));
    p->pos = pos;
    p->is_seq = NONSEQ;
    p->const_expr_list = NULL;
    p->id = id;
    p->const_value = const_value;
    return p;
}

A_const_value A_ConstValueInteger(A_pos pos, int intt)
{
    A_const_value p = (A_const_value) checked_malloc(sizeof(struct A_const_value_));
    p->pos = pos;
    p->kind = CONST_INTEGER;
    p->u.intt = intt;
    return p;
}

A_const_value A_ConstValueReal(A_pos pos, double real)
{
    A_const_value p = (A_const_value) checked_malloc(sizeof(struct A_const_value_));
    p->pos = pos;
    p->kind = CONST_REAL;
    p->u.real = real;
    return p;
}

A_const_value A_ConstValueChar(A_pos pos, char *charr)
{
    A_const_value p = (A_const_value) checked_malloc(sizeof(struct A_const_value_));
    p->pos = pos;
    p->kind = CONST_CHAR;
    p->u.charr = charr;
    return p;
}

A_const_value A_ConstValueString(A_pos pos, char *string)
{
    A_const_value p = (A_const_value) checked_malloc(sizeof(struct A_const_value_));
    p->pos = pos;
    p->kind = CONST_STRING;
    p->u.string = string;
    return p;
}

A_const_value A_ConstValueSysCon(A_pos pos, A_SYS_CON sys_con)
{
    A_const_value p = (A_const_value) checked_malloc(sizeof(struct A_const_value_));
    p->pos = pos;
    p->kind = CONST_SYS_CON;
    p->u.sys_con = sys_con;
    return p;
}

A_type_decl_list A_TypeDeclListSeq(A_pos pos, A_type_decl_list type_decl_list, A_type_definition type_definition)
{
    A_type_decl_list p = (A_type_decl_list) checked_malloc(sizeof(struct A_type_decl_list_));
    p->pos = pos;
    p->is_seq = SEQ;
    p->type_decl_list = type_decl_list;
    p->type_definition = type_definition;
    return p;
}

A_type_decl_list A_TypeDeclList(A_pos pos, A_type_definition type_definition)
{
    A_type_decl_list p = (A_type_decl_list) checked_malloc(sizeof(struct A_type_decl_list_));
    p->pos = pos;
    p->is_seq = NONSEQ;
    p->type_decl_list = NULL;
    p->type_definition = type_definition;
    return p;
}

//A_type_definition A_TypeDefinition(A_pos pos, char *id, A_type_decl type_decl)
A_type_definition A_TypeDefinition(A_pos pos, S_symbol id, A_type_decl type_decl)
{
    A_type_definition p = (A_type_definition) checked_malloc(sizeof(struct A_type_definition_));
    p->pos = pos;
    p->id = id;
    p->type_decl = type_decl;
    return p;
}

A_type_decl A_TypeDeclSimple(A_pos pos, A_simple_type_decl simple_type_decl)
{
    A_type_decl p = (A_type_decl) checked_malloc(sizeof(struct A_type_decl_));
    p->pos = pos;
    p->kind = type_decl_simple;
    p->u.simple_type_decl = simple_type_decl;
    return p;
}

A_type_decl A_TypeDeclRecord(A_pos pos, A_record_type_decl record_type_decl)
{
    A_type_decl p = (A_type_decl) checked_malloc(sizeof(struct A_type_decl_));
    p->pos = pos;
    p->kind = type_decl_record;
    p->u.record_type_decl = record_type_decl;
    return p;
}

A_type_decl A_TypeDeclArray(A_pos pos, A_array_type_decl array_type_decl)
{
    A_type_decl p = (A_type_decl) checked_malloc(sizeof(struct A_type_decl_));
    p->pos = pos;
    p->kind = type_decl_array;
    p->u.array_type_decl = array_type_decl;
    return p;
}

A_simple_type_decl A_SimpleTypeDeclSysType(A_pos pos, A_SYS_TYPE sys_type)
{
    A_simple_type_decl p = (A_simple_type_decl) checked_malloc(sizeof(struct A_simple_type_decl_));
    p->pos = pos;
    p->kind = simple_type_decl_sys_type;
    p->u.sys_type = sys_type;
    return p;
}

//A_simple_type_decl A_SimpleTypeDeclId(A_pos pos, char *id)
A_simple_type_decl A_SimpleTypeDeclId(A_pos pos, S_symbol id)
{
    A_simple_type_decl p = (A_simple_type_decl) checked_malloc(sizeof(struct A_array_type_decl_));
    p->pos = pos;
    p->kind = simple_type_decl_id;
    p->u.id = id;
    return p;
}

A_simple_type_decl A_SimpleTypeDeclNameList(A_pos pos, A_name_list name_list)
{
    A_simple_type_decl p = (A_simple_type_decl) checked_malloc(sizeof(struct A_simple_type_decl_));
    p->pos = pos;
    p->kind = simple_type_decl_name_list;
    p->u.name_list = name_list;
    return p;
}

A_simple_type_decl A_SimpleTypeDeclRangeConst(A_pos pos, A_const_value from, A_const_value to)
{
    A_simple_type_decl p = (A_simple_type_decl) checked_malloc(sizeof(struct A_simple_type_decl_));
    p->pos = pos;
    p->kind = simple_type_decl_range_const_to_const;
    p->u.const_range.from = from;
    p->u.const_range.to = to;
    return p;
}

//A_simple_type_decl A_SimpleTypeDeclRangeId(A_pos pos, char *from, char *to)
A_simple_type_decl A_SimpleTypeDeclRangeId(A_pos pos, S_symbol from, S_symbol to)
{
    A_simple_type_decl p = (A_simple_type_decl) checked_malloc(sizeof(struct A_simple_type_decl_));
    p->pos = pos;
    p->kind = simple_type_decl_range_id_to_id;
    p->u.id_range.from = from;
    p->u.id_range.to = to;
    return p;
}

A_array_type_decl A_ArrayTypeDecl(A_pos pos, A_simple_type_decl simple_type_decl, A_type_decl type_decl)
{
    A_array_type_decl p = (A_array_type_decl) checked_malloc(sizeof(struct A_array_type_decl_));
    p->pos = pos;
    p->simple_type_decl = simple_type_decl;
    p->type_decl = type_decl;
    return p;
}

A_record_type_decl A_RecordTypeDecl(A_pos pos, A_field_decl_list field_decl_list)
{
    A_record_type_decl p = (A_record_type_decl) checked_malloc(sizeof(struct A_record_type_decl_));
    p->pos = pos;
    p->field_decl_list = field_decl_list;
    return p;
}

A_field_decl_list A_FieldDeclListSeq(A_pos pos, A_field_decl_list field_decl_list, A_field_decl field_decl)
{
    A_field_decl_list p = (A_field_decl_list) checked_malloc(sizeof(struct A_field_decl_list_));
    p->pos = pos;
    p->is_seq = SEQ;
    p->field_decl_list = field_decl_list;
    p->field_decl = field_decl;
    return p;
}

A_field_decl_list A_FieldDeclList(A_pos pos, A_field_decl field_decl)
{
    A_field_decl_list p = (A_field_decl_list) checked_malloc(sizeof(struct A_field_decl_list_));
    p->pos = pos;
    p->is_seq = NONSEQ;
    p->field_decl_list = NULL;
    p->field_decl = field_decl;
    return p;
}

A_field_decl A_FieldDecl(A_pos pos, A_name_list name_list, A_type_decl type_decl)
{
    A_field_decl p = (A_field_decl) checked_malloc(sizeof(struct A_field_decl_));
    p->pos = pos;
    p->name_list = name_list;
    p->type_decl = type_decl;
    return p;
}

//A_name_list A_NameListSeq(A_pos pos, A_name_list name_list, char *id)
A_name_list A_NameListSeq(A_pos pos, A_name_list name_list, S_symbol id)
{
    A_name_list p = (A_name_list) checked_malloc(sizeof(struct A_name_list_));
    p->pos = pos;
    p->is_seq = SEQ;
    p->id = id;
    p->name_list = name_list;
    return p;
}

//A_name_list A_NameList(A_pos pos, char *id)
A_name_list A_NameList(A_pos pos, S_symbol id)
{
    A_name_list p = (A_name_list) checked_malloc(sizeof(struct A_name_list_));
    p->pos = pos;
    p->is_seq = NONSEQ;
    p->id = id;
    p->name_list = NULL;
    return p;
}

A_var_decl_list A_VarDeclListSeq(A_pos pos, A_var_decl_list var_decl_list, A_var_decl var_decl)
{
    A_var_decl_list p = (A_var_decl_list) checked_malloc(sizeof(struct A_var_decl_list_));
    p->pos = pos;
    p->is_seq = SEQ;
    p->var_decl_list = var_decl_list;
    p->var_decl = var_decl;
    return p;
}

A_var_decl_list A_VarDeclList(A_pos pos, A_var_decl var_decl)
{
    A_var_decl_list p = (A_var_decl_list) checked_malloc(sizeof(struct A_var_decl_list_));
    p->pos = pos;
    p->is_seq = NONSEQ;
    p->var_decl_list = NULL;
    p->var_decl = var_decl;
    return p;
}

A_var_decl A_VarDecl(A_pos pos, A_name_list name_list, A_type_decl type_decl)
{
    A_var_decl p = (A_var_decl) checked_malloc(sizeof(struct A_var_decl_));
    p->pos = pos;
    p->name_list = name_list;
    p->type_decl = type_decl;
    return p;
}

A_function_decl A_FunctionDecl(A_pos pos, A_function_head function_head, A_sub_routine sub_routine)
{
    A_function_decl p = (A_function_decl) checked_malloc(sizeof(struct A_function_decl_));
    p->pos = pos;
    p->function_head = function_head;
    p->sub_routine = sub_routine;
    return p;
}

A_procedure_decl A_ProcedureDecl(A_pos pos, A_procedure_head procedure_head, A_sub_routine sub_routine)
{
    A_procedure_decl p = (A_procedure_decl) checked_malloc(sizeof(struct A_procedure_decl_));
    p->pos = pos;
    p->procedure_head = procedure_head;
    p->sub_routine = sub_routine;
    return p;
}

//A_function_head A_FunctionHead(A_pos pos, char *id, A_parameters parameters, A_simple_type_decl simple_type_decl)
A_function_head A_FunctionHead(A_pos pos, S_symbol id, A_parameters parameters, A_simple_type_decl simple_type_decl)
{
    A_function_head p = (A_function_head) checked_malloc(sizeof(struct A_function_head_));
    p->pos = pos;
    p->id = id;
    p->parameters = parameters;
    p->simple_type_decl = simple_type_decl;
    return p;
}

//A_procedure_head A_ProcedureHead(A_pos pos, char *id, A_parameters parameters)
A_procedure_head A_ProcedureHead(A_pos pos, S_symbol id, A_parameters parameters)
{
    A_procedure_head p = (A_procedure_head) checked_malloc(sizeof(struct A_procedure_head_));
    p->pos = pos;
    p->id = id;
    p->parameters = parameters;
    return p;
}

A_parameters A_Parameters(A_pos pos, A_para_decl_list para_decl_list)
{
    A_parameters p = (A_parameters) checked_malloc(sizeof(struct A_parameters_));
    p->pos = pos;
    p->para_decl_list = para_decl_list;
    return p;
}

A_para_decl_list A_ParaDeclListSeq(A_pos pos, A_para_decl_list para_decl_list, A_para_type_list para_type_list)
{
    A_para_decl_list p = (A_para_decl_list) checked_malloc(sizeof(struct A_para_decl_list_));
    p->pos = pos;
    p->is_seq = SEQ;
    p->para_decl_list = para_decl_list;
    p->para_type_list = para_type_list;
    return p;
}

A_para_decl_list A_ParaDeclList(A_pos pos, A_para_type_list para_type_list)
{
    A_para_decl_list p = (A_para_decl_list) checked_malloc(sizeof(struct A_para_decl_list_));
    p->pos = pos;
    p->is_seq = NONSEQ;
    p->para_decl_list = NULL;
    p->para_type_list = para_type_list;
    return p;
}

A_para_type_list A_ParaTypeListVar(A_pos pos, A_var_para_list var_para_list, A_simple_type_decl simple_type_decl)
{
    A_para_type_list p = (A_para_type_list) checked_malloc(sizeof(struct A_para_type_list_));
    p->pos = pos;
    p->kind = para_type_list_var;
    p->u.var_para_list.var_para_list = var_para_list;
    p->u.var_para_list.simple_type_decl = simple_type_decl;
    return p;
}

A_para_type_list A_ParaTypeListVal(A_pos pos, A_val_para_list val_para_list, A_simple_type_decl simple_type_decl)
{
    A_para_type_list p = (A_para_type_list) checked_malloc(sizeof(struct A_para_type_list_));
    p->pos = pos;
    p->kind = para_type_list_val;
    p->u.val_para_list.val_para_list = val_para_list;
    p->u.val_para_list.simple_type_decl = simple_type_decl;
    return p;
}

A_var_para_list A_VarParaList(A_pos pos, A_name_list name_list)
{
    A_var_para_list p = (A_var_para_list) checked_malloc(sizeof(struct A_var_para_list_));
    p->pos = pos;
    p->name_list = name_list;
    return p;
}

A_val_para_list A_ValParaList(A_pos pos, A_name_list name_list)
{
    A_val_para_list p = (A_val_para_list) checked_malloc(sizeof(struct A_val_para_list_));
    p->pos = pos;
    p->name_list = name_list;
    return p;
}

A_compound_stmt A_CompoundStmt(A_pos pos, A_stmt_list stmt_list)
{
    A_compound_stmt p = (A_compound_stmt) checked_malloc(sizeof(struct A_compound_stmt_));
    p->pos = pos;
    p->stmt_list = stmt_list;
    return p;
}

A_stmt_list A_StmtList(A_pos pos, A_stmt_list stmt_list, A_stmt stmt)
{
    A_stmt_list p = (A_stmt_list) checked_malloc(sizeof(struct A_stmt_list_));
    p->stmt_list = stmt_list;
    p->stmt = stmt;
    return p;
}

A_stmt A_StmtLabel(A_pos pos, int label, A_non_label_stmt non_label_stmt)
{
    A_stmt p = (A_stmt) checked_malloc(sizeof(struct A_stmt_));
    p->pos = pos;
    p->is_label = LABEL;
    p->label = label;
    p->non_label_stmt = non_label_stmt;
    return p;
}

A_stmt A_StmtNonLabel(A_pos pos, A_non_label_stmt non_label_stmt)
{
    A_stmt p = (A_stmt) checked_malloc(sizeof(struct A_stmt_));
    p->pos = pos;
    p->is_label = NONLABEL;
    p->label = -1;
    p->non_label_stmt = non_label_stmt;
    return p;
}

A_non_label_stmt A_NonLabelStmtAssign(A_pos pos, A_assign_stmt assign_stmt)
{
    A_non_label_stmt p = (A_non_label_stmt) checked_malloc(sizeof(struct A_non_label_stmt_));
    p->pos = pos;
    p->kind = non_label_stmt_assign;
    p->u.assign_stmt = assign_stmt;
    return p;
}

A_non_label_stmt A_NonLabelStmtProc(A_pos pos, A_proc_stmt proc_stmt)
{
    A_non_label_stmt p = (A_non_label_stmt) checked_malloc(sizeof(struct A_non_label_stmt_));
    p->pos = pos;
    p->kind = non_label_stmt_proc;
    p->u.proc_stmt = proc_stmt;
    return p;
}

A_non_label_stmt A_NonLabelStmtCompound(A_pos pos, A_compound_stmt compound_stmt)
{
    A_non_label_stmt p = (A_non_label_stmt) checked_malloc(sizeof(struct A_non_label_stmt_));
    p->pos = pos;
    p->kind = non_label_stmt_compound;
    p->u.compound_stmt = compound_stmt;
    return p;
}

A_non_label_stmt A_NonLabelStmtIf(A_pos pos, A_if_stmt if_stmt)
{
    A_non_label_stmt p = (A_non_label_stmt) checked_malloc(sizeof(struct A_non_label_stmt_));
    p->pos = pos;
    p->kind = non_label_stmt_if;
    p->u.if_stmt = if_stmt;
    return p;
}

A_non_label_stmt A_NonLabelStmtRepeat(A_pos pos, A_repeat_stmt repeat_stmt)
{
    A_non_label_stmt p = (A_non_label_stmt) checked_malloc(sizeof(struct A_non_label_stmt_));
    p->pos = pos;
    p->kind = non_label_stmt_repeat;
    p->u.repeat_stmt = repeat_stmt;
    return p;
}

A_non_label_stmt A_NonLabelStmtWhile(A_pos pos, A_while_stmt while_stmt)
{
    A_non_label_stmt p = (A_non_label_stmt) checked_malloc(sizeof(struct A_non_label_stmt_));
    p->pos = pos;
    p->kind = non_label_stmt_while;
    p->u.while_stmt = while_stmt;
    return p;
}

A_non_label_stmt A_NonLabelStmtCase(A_pos pos, A_case_stmt case_stmt)
{
    A_non_label_stmt p = (A_non_label_stmt) checked_malloc(sizeof(struct A_non_label_stmt_));
    p->pos = pos;
    p->kind = non_label_stmt_case;
    p->u.case_stmt = case_stmt;
    return p;
}

A_non_label_stmt A_NonLabelStmtFor(A_pos pos, A_for_stmt for_stmt)
{
    A_non_label_stmt p = (A_non_label_stmt) checked_malloc(sizeof(struct A_non_label_stmt_));
    p->pos = pos;
    p->kind = non_label_stmt_for;
    p->u.for_stmt = for_stmt;
    return p;
}

A_non_label_stmt A_NonLabelStmtGoto(A_pos pos, A_goto_stmt goto_stmt)
{
    A_non_label_stmt p = (A_non_label_stmt) checked_malloc(sizeof(struct A_non_label_stmt_));
    p->pos = pos;
    p->kind = non_label_stmt_goto;
    p->u.goto_stmt = goto_stmt;
    return p;
}

//A_assign_stmt A_AssignStmtSimple(A_pos pos, char *id, A_expression right_expression)
A_assign_stmt A_AssignStmtSimple(A_pos pos, S_symbol id, A_expression right_expression)
{
    A_assign_stmt p = (A_assign_stmt) checked_malloc(sizeof(struct A_assign_stmt_));
    p->pos = pos;
    p->kind = assign_stmt_simple;
    p->u.simple_var_assign_stmt.id = id;
    p->u.simple_var_assign_stmt.right_expression = right_expression;
    return p;
}

//A_assign_stmt A_AssignStmtRecord(A_pos pos, char *id, char *field_id, A_expression right_expression)
A_assign_stmt A_AssignStmtRecord(A_pos pos, S_symbol id, S_symbol field_id, A_expression right_expression)
{
    A_assign_stmt p = (A_assign_stmt) checked_malloc(sizeof(struct A_assign_stmt_));
    p->pos = pos;
    p->kind = assign_stmt_record;
    p->u.record_var_assign_stmt.id = id;
    p->u.record_var_assign_stmt.field_id = field_id;
    p->u.record_var_assign_stmt.right_expression = right_expression;
    return p;
}

//A_assign_stmt A_AssignStmtArray(A_pos pos, char *id, A_expression subscript_expression, A_expression right_expression)
A_assign_stmt A_AssignStmtArray(A_pos pos, S_symbol id, A_expression subscript_expression, A_expression right_expression)
{
    A_assign_stmt p = (A_assign_stmt) checked_malloc(sizeof(struct A_assign_stmt_));
    p->pos = pos;
    p->kind = assign_stmt_array;
    p->u.array_var_assign_stmt.id = id;
    p->u.array_var_assign_stmt.subscript_expression = subscript_expression;
    p->u.array_var_assign_stmt.right_expression = right_expression;
    return p;
}

//A_proc_stmt A_ProcStmtID(A_pos pos, char *id)
A_proc_stmt A_ProcStmtID(A_pos pos, S_symbol id)
{
    A_proc_stmt p = (A_proc_stmt) checked_malloc(sizeof(struct A_proc_stmt_));
    p->pos = pos;
    p->kind = proc_stmt_id; // id
    p->u.id = id;
    return p;
}

//A_proc_stmt A_ProcStmtIDWithArgs(A_pos pos, char *id, A_args_list args_list)
A_proc_stmt A_ProcStmtIDWithArgs(A_pos pos, S_symbol id, A_args_list args_list)
{
    A_proc_stmt p = (A_proc_stmt) checked_malloc(sizeof(struct A_proc_stmt_));
    p->pos = pos;
    p->kind = proc_stmt_id_with_args; // id with args
    p->u.id_with_args.id = id;
    p->u.id_with_args.args_list = args_list;
    return p;
}

A_proc_stmt A_ProcStmtSysProc(A_pos pos, A_SYS_PROC sys_proc)
{
    A_proc_stmt p = (A_proc_stmt) checked_malloc(sizeof(struct A_proc_stmt_));
    p->pos = pos;
    p->kind = proc_stmt_sys_proc; // sys_proc
    p->u.sys_proc = sys_proc;
    return p;
}

A_proc_stmt A_ProcStmtSysProcWithArgs(A_pos pos, A_SYS_PROC sys_proc, A_expression_list expression_list)
{
    A_proc_stmt p = (A_proc_stmt) checked_malloc(sizeof(struct A_proc_stmt_));
    p->pos = pos;
    p->kind = proc_stmt_sys_proc_with_args; // sys_proc with args
    p->u.sys_proc_with_args.sys_proc = sys_proc;
    p->u.sys_proc_with_args.expression_list = expression_list;
    return p;
}

A_proc_stmt A_ProcStmtRead(A_pos pos, A_factor factor)
{
    A_proc_stmt p = (A_proc_stmt) checked_malloc(sizeof(struct A_proc_stmt_));
    p->pos = pos;
    p->kind = proc_stmt_read; // read
    p->u.factor = factor;
    return p;
}

A_if_stmt A_IfStmt(A_pos pos, A_expression test, A_stmt body, A_else_clause else_clause)
{
    A_if_stmt p = (A_if_stmt) checked_malloc(sizeof(struct A_if_stmt_));
    p->pos = pos;
    p->test = test;
    p->body = body;
    p->else_clause = else_clause;
    return p;
}

A_repeat_stmt A_RepeatStmt(A_pos pos, A_stmt_list body, A_expression until)
{
    A_repeat_stmt p = (A_repeat_stmt) checked_malloc(sizeof(struct A_repeat_stmt_));
    p->pos = pos;
    p->body = body;
    p->until = until;
}

A_while_stmt A_WhileStmt(A_pos pos, A_expression test, A_stmt body)
{
    A_while_stmt p = (A_while_stmt) checked_malloc(sizeof(struct A_while_stmt_));
    p->pos = pos;
    p->test = test;
    p->body = body;
    return p;
}

//A_for_stmt A_ForStmt(A_pos pos, char *loop_var, A_expression lo, A_direction direction, A_expression hi)
A_for_stmt A_ForStmt(A_pos pos, S_symbol loop_var, A_expression lo, A_direction direction, A_expression hi, A_stmt body)
{
    A_for_stmt p = (A_for_stmt) checked_malloc(sizeof(struct A_for_stmt_));
    p->pos = pos;
    p->loop_var = loop_var;
    p->lo = lo;
    p->hi = hi;
    p->direction = direction;
    p->body = body;
    return p;
}

A_case_stmt A_CaseStmt(A_pos pos, A_expression expression, A_case_expr_list case_expr_list)
{
    A_case_stmt p = (A_case_stmt) checked_malloc(sizeof(struct A_case_stmt_));
    p->expression = expression;
    p->case_expr_list = case_expr_list;
    return p;
}

A_goto_stmt A_GotoStmt(A_pos pos, int label)
{
    A_goto_stmt p = (A_goto_stmt) checked_malloc(sizeof(struct A_goto_stmt_));
    p->pos = pos;
    p->label = label;
    return p;
}

A_else_clause A_ElseClause(A_pos pos, A_stmt else_body)
{
    A_else_clause p = (A_else_clause) checked_malloc(sizeof(struct A_else_clause_));
    p->pos = pos;
    p->body = (else_body == NULL) ? NULL : else_body;
    return p;
}

A_case_expr_list A_CaseExprListSeq(A_pos pos, A_case_expr_list case_expr_list, A_case_expr case_expr)
{
    A_case_expr_list p = (A_case_expr_list) checked_malloc(sizeof(struct A_case_expr_list_));
    p->pos = pos;
    p->is_seq = SEQ; // SEQ
    p->case_expr_list = case_expr_list;
    p->case_expr = case_expr;
    return p;
}

A_case_expr_list A_CaseExprList(A_pos pos, A_case_expr case_expr)
{
    A_case_expr_list p = (A_case_expr_list) checked_malloc(sizeof(struct A_case_expr_list_));
    p->pos = pos;
    p->is_seq = NONSEQ; // NONSEQ
    p->case_expr_list = NULL;
    p->case_expr = case_expr;
    return p;
}

A_case_expr A_CaseExprConst(A_pos pos, A_const_value const_value, A_stmt body)
{
    A_case_expr p = (A_case_expr) checked_malloc(sizeof(struct A_case_expr_));
    p->pos = pos;
    p->kind = case_expr_const_value; // const_value
    p->u.const_value.const_value = const_value;
    p->u.const_value.body = body;
    return p;
}

//A_case_expr A_CaseExprNonConst(A_pos pos, char *id, A_stmt body)
A_case_expr A_CaseExprNonConst(A_pos pos, S_symbol id, A_stmt body)
{
    A_case_expr p = (A_case_expr) checked_malloc(sizeof(struct A_case_expr_));
    p->pos = pos;
    p->kind = case_expr_non_const_value; // non_const_value
    p->u.non_const_value.id = id;
    p->u.non_const_value.body = body;
    return p;
}

A_expression_list A_ExpressionListSeq(A_pos pos, A_expression_list expression_list, A_expression expression)
{
    A_expression_list p = (A_expression_list) checked_malloc(sizeof(struct A_expression_list_));
    p->pos = pos;
    p->is_seq = SEQ; // SEQ
    p->expression_list = expression_list;
    p->expression = expression;
    return p;
}

A_expression_list A_ExpressionList(A_pos pos, A_expression expression)
{
    A_expression_list p = (A_expression_list) checked_malloc(sizeof(struct A_expression_list_));
    p->pos = pos;
    p->is_seq = NONSEQ; // NONSEQ
    p->expression_list = NULL;
    p->expression = expression;
    return p;
}

A_expression A_ExpressionBin(A_pos pos, A_expression left_expression, A_rel_op rel_op, A_expr right_expr)
{
    A_expression p = (A_expression) checked_malloc(sizeof(struct A_expression_));
    p->pos = pos;
    p->is_bin_op = BINOP;
    p->u.bin_op.left_expression = left_expression;
    p->u.bin_op.rel_op = rel_op;
    p->u.bin_op.right_expr = right_expr;
    return p;
}

A_expression A_ExpressionUn(A_pos pos, A_expr expr)
{
    A_expression p = (A_expression) checked_malloc(sizeof(struct A_expression_));
    p->pos = pos;
    p->is_bin_op = NONBINOP;
    p->u.expr = expr;
    return p;
}

A_expr A_ExprBin(A_pos pos, A_expr left_expr, A_plus_op plus_op, A_term right_term)
{
    A_expr p = (A_expr) checked_malloc(sizeof(struct A_expr_));
    p->pos = pos;
    p->is_bin_op = BINOP;
    p->u.bin_op.left_expr = left_expr;
    p->u.bin_op.plus_op = plus_op;
    p->u.bin_op.right_term = right_term;
    return p;
}

A_expr A_ExprUn(A_pos pos, A_term term)
{
    A_expr p = (A_expr) checked_malloc(sizeof(struct A_expr_));
    p->pos = pos;
    p->is_bin_op = NONBINOP;
    p->u.term = term;
    return p;
}

A_term A_TermBin(A_pos pos, A_term left_term, A_mul_op mul_op, A_factor right_factor)
{
    A_term p = (A_term) checked_malloc(sizeof(struct A_term_));
    p->pos = pos;
    p->is_bin_op = BINOP;
    p->u.bin_op.mul_op = mul_op;
    p->u.factor = right_factor;
}

A_term A_TermUn(A_pos pos, A_factor factor)
{
    A_term p = (A_term) checked_malloc(sizeof(struct A_term_));
    p->pos = pos;
    p->is_bin_op = NONBINOP;
    p->u.factor = factor;
}

//A_factor A_FactorId(A_pos pos, char *id)
A_factor A_FactorId(A_pos pos, S_symbol id)
{
    A_factor p = (A_factor) checked_malloc(sizeof(struct A_factor_));
    p->pos = pos;
    p->kind = factor_id; // id
    p->u.id = id;
    return p;
}

//A_factor A_FactorIdWithArgs(A_pos pos, char *id, A_args_list args_list)
A_factor A_FactorIdWithArgs(A_pos pos, S_symbol id, A_args_list args_list)
{
    A_factor p = (A_factor) checked_malloc(sizeof(struct A_factor_));
    p->pos = pos;
    p->kind = factor_id_with_args; // id_with_args
    p->u.id_with_args.id = id;
    p->u.id_with_args.args_list = args_list;
    return p;
}

A_factor A_FactorSysFunct(A_pos pos, A_SYS_FUNCT sys_funct)
{
    A_factor p = (A_factor) checked_malloc(sizeof(struct A_factor_));
    p->pos = pos;
    p->kind = factor_sys_funct; // sys_funct
    p->u.sys_funct = sys_funct;
    return p;
}

A_factor A_FactorSysFunctWithArgs(A_pos pos, A_SYS_FUNCT sys_funct, A_args_list args_list)
{
    A_factor p = (A_factor) checked_malloc(sizeof(struct A_factor_));
    p->pos = pos;
    p->kind = factor_sys_funct_with_args; // sys_funct_with_args
    p->u.sys_funct_with_args.sys_funct = sys_funct;
    p->u.sys_funct_with_args.args_list = args_list;
    return p;
}

A_factor A_FactorConst(A_pos pos, A_const_value const_value)
{
    A_factor p = (A_factor) checked_malloc(sizeof(struct A_factor_));
    p->pos = pos;
    p->kind = factor_const_value; // const_value
    p->u.const_value = const_value;
    return p;
}

A_factor A_FactorInBrackets(A_pos pos, A_expression expression)
{
    A_factor p = (A_factor) checked_malloc(sizeof(struct A_factor_));
    p->pos = pos;
    p->kind = factor_in_brackets; // in_brackets_factor
    p->u.expression = expression;
    return p;
}

A_factor A_FactorUnOp(A_pos pos, A_un_op un_op, A_factor factor)
{
    A_factor p = (A_factor) checked_malloc(sizeof(struct A_args_list_));
    p->pos = pos;
    p->kind = factor_un_op; // un_op
    p->u.un_op.un_op = un_op;
    p->u.un_op.factor = factor;
    return p;
}

//A_factor A_FactorRecordVar(A_pos pos, char *id, char *field_id)
A_factor A_FactorRecordVar(A_pos pos, S_symbol id, S_symbol field_id)
{
    A_factor p = (A_factor) checked_malloc(sizeof(struct A_args_list_));
    p->pos = pos;
    p->kind = factor_record_var; // record_var
    p->u.record_var.id = id;
    p->u.record_var.field_id = field_id;
    return p;
}

//A_factor A_FactorArrayVar(A_pos pos, char *id, A_expression subscript_expression)
A_factor A_FactorArrayVar(A_pos pos, S_symbol id, A_expression subscript_expression)
{
    A_factor p = (A_factor) checked_malloc(sizeof(struct A_args_list_));
    p->pos = pos;
    p->kind = factor_array_var; // array_var
    p->u.array_var.id = id;
    p->u.array_var.subscript_expression = subscript_expression;
    return p;
}

A_args_list A_ArgsListSeq(A_pos pos, A_args_list args_list, A_expression expression)
{
    A_args_list p = (A_args_list) checked_malloc(sizeof(struct A_args_list_));
    p->pos = pos;
    p->is_seq = SEQ;
    p->args_list = args_list;
    p->expression = expression;
    return p;
}

A_args_list A_ArgsList(A_pos pos, A_expression expression)
{
    A_args_list p = (A_args_list) checked_malloc(sizeof(struct A_args_list_));
    p->pos = pos;
    p->is_seq = NONSEQ;
    p->args_list = NULL;
    p->expression = expression;
    return p;
}


