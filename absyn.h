#ifndef _ABSYN_H_
#define _ABSYN_H_

#include "util.h"
#include "symbol.h"


typedef enum
{
    NONLABEL, LABEL
} A_is_label;

typedef enum
{
    NONSEQ, SEQ
} A_is_seq;

typedef enum
{
    NONBINOP, BINOP
} A_is_bin_op;

typedef int A_pos;

typedef struct A_program_ *A_program;
typedef struct A_program_head_ *A_program_head;
typedef struct A_routine_ *A_routine;
typedef struct A_sub_routine_ *A_sub_routine;
typedef struct A_routine_head_ *A_routine_head;
typedef struct A_routine_body_ *A_routine_body;
typedef struct A_label_part_ *A_label_part;
typedef struct A_const_part_ *A_const_part;
typedef struct A_type_part_ *A_type_part;
typedef struct A_var_part_ *A_var_part;
typedef struct A_routine_part_ *A_routine_part;
typedef struct A_routine_part_prime_ *A_routine_part_prime;

typedef struct A_const_expr_list_ *A_const_expr_list;
typedef struct A_const_value_ *A_const_value;

typedef struct A_type_decl_list_ *A_type_decl_list;
typedef struct A_type_definition_ *A_type_definition;
typedef struct A_type_decl_ *A_type_decl;
typedef struct A_simple_type_decl_ *A_simple_type_decl;
typedef struct A_array_type_decl_ *A_array_type_decl;
typedef struct A_record_type_decl_ *A_record_type_decl;
typedef struct A_field_decl_list_ *A_field_decl_list;
typedef struct A_field_decl_ *A_field_decl;
typedef struct A_name_list_ *A_name_list;
typedef struct A_var_decl_list_ *A_var_decl_list;
typedef struct A_var_decl_ *A_var_decl;

typedef struct A_function_decl_ *A_function_decl;
typedef struct A_procedure_decl_ *A_procedure_decl;
typedef struct A_function_head_ *A_function_head;
typedef struct A_procedure_head_ *A_procedure_head;
typedef struct A_parameters_ *A_parameters;
typedef struct A_para_decl_list_ *A_para_decl_list;
typedef struct A_para_type_list_ *A_para_type_list;
typedef struct A_var_para_list_ *A_var_para_list;
typedef struct A_val_para_list_ *A_val_para_list;

typedef struct A_compound_stmt_ *A_compound_stmt;
typedef struct A_stmt_list_ *A_stmt_list;
typedef struct A_stmt_ *A_stmt;
typedef struct A_non_label_stmt_ *A_non_label_stmt;

typedef struct A_assign_stmt_ *A_assign_stmt;
typedef struct A_proc_stmt_ *A_proc_stmt;
typedef struct A_if_stmt_ *A_if_stmt;
typedef struct A_repeat_stmt_ *A_repeat_stmt;
typedef struct A_while_stmt_ *A_while_stmt;
typedef struct A_for_stmt_ *A_for_stmt;
typedef struct A_case_stmt_ *A_case_stmt;
typedef struct A_goto_stmt_ *A_goto_stmt;

typedef struct A_else_clause_ *A_else_clause;
typedef struct A_case_expr_list_ *A_case_expr_list;
typedef struct A_case_expr_ *A_case_expr;
typedef struct A_expression_list_ *A_expression_list;
typedef struct A_expression_ *A_expression;
typedef struct A_expr_ *A_expr;
typedef struct A_term_ *A_term;
typedef struct A_factor_ *A_factor;
typedef struct A_args_list_ *A_args_list;

/* Unary operators */
typedef enum
{
    OP_NOT, OP_NEG
} A_un_op;

/* Binary opertors */
typedef enum
{
    OP_GE, OP_GT, OP_LE, OP_LT, OP_EQUAL, OP_UNEQUAL
} A_rel_op;

typedef enum
{
    OP_PLUS, OP_MINUS, OP_OR
} A_plus_op;

typedef enum
{
    OP_MUL, OP_DIV, OP_MOD, OP_AND
} A_mul_op;

/* Directions */
typedef enum
{
    DIRECTION_TO, DIRECTION_DOWNTO
} A_direction;

/* TOKENS */
typedef enum
{
    SYS_CON_FALSE, SYS_CON_TRUE, SYS_CON_MAXINT
} A_SYS_CON;

typedef enum
{
    SYS_FUNCT_ABS,
    SYS_FUNCT_CHR,
    SYS_FUNCT_ODD,
    SYS_FUNCT_ORD,
    SYS_FUNCT_PRED,
    SYS_FUNCT_SQR,
    SYS_FUNCT_SQRT,
    SYS_FUNCT_SUCC
} A_SYS_FUNCT;

typedef enum
{
    SYS_PROC_WRITE, SYS_PROC_WRITELN
} A_SYS_PROC;

typedef enum
{
    T_BOOLEAN, T_CHAR, T_INTEGER, T_REAL
} A_SYS_TYPE;

/* nodes */
struct A_program_
{
    A_pos pos;
    A_program_head program_head;
    A_routine routine;
};

struct A_program_head_
{
    A_pos pos;
    char *id;
};

struct A_routine_
{
    A_pos pos;
    A_routine_head routine_head;
    A_routine_body routine_body;
};

struct A_sub_routine_
{
    A_pos pos;
    A_routine_head routine_head;
    A_routine_body routine_body;
};

struct A_routine_head_
{
    A_pos pos;
    A_label_part label_part;
    A_const_part const_part;
    A_type_part type_part;
    A_var_part var_part;
    A_routine_part routine_part;
};

struct A_label_part_
{
    A_pos pos;
};

struct A_const_part_
{
    A_pos pos;
    A_const_expr_list const_expr_list;
};

struct A_const_expr_list_
{
    A_pos pos;
    A_is_seq is_seq;
    A_const_expr_list const_expr_list;
//    char *id;
    S_symbol id;
    A_const_value const_value;
};

struct A_const_value_
{
    A_pos pos;
    enum
    {
        CONST_INTEGER, CONST_REAL, CONST_CHAR, CONST_STRING, CONST_SYS_CON
    } kind;
    union
    {
        int intt;
        double real;
        char *charr;
        char *string;
        A_SYS_CON sys_con;
    } u;
};

struct A_type_part_
{
    A_pos pos;
    A_type_decl_list type_decl_list;
};

struct A_type_decl_list_
{
    A_pos pos;
    A_is_seq is_seq;
    A_type_decl_list type_decl_list;
    A_type_definition type_definition;
};

struct A_type_definition_
{
    A_pos pos;
//    char *id;
    S_symbol id;
    A_type_decl type_decl;
};

struct A_type_decl_
{
    A_pos pos;
    enum
    {
        type_decl_simple,
        type_decl_record,
        type_decl_array
    } kind;
    union
    {
        A_simple_type_decl simple_type_decl;
        A_record_type_decl record_type_decl;
        A_array_type_decl array_type_decl;
    } u;
};

struct A_simple_type_decl_
{
    A_pos pos;
    enum
    {
        simple_type_decl_sys_type,
        simple_type_decl_id,
        simple_type_decl_name_list,
        simple_type_decl_range_const_to_const,
        simple_type_decl_range_id_to_id
    } kind;
    union
    {
        A_SYS_TYPE sys_type;
//        char *id;
        S_symbol id;
        A_name_list name_list;
        struct
        {
            A_const_value from;
            A_const_value to;
        } const_range;
        struct
        {
//            char *from;
//            char *to;
            S_symbol from;
            S_symbol to;
        } id_range;
    } u;
};

struct A_array_type_decl_
{
    A_pos pos;
    A_simple_type_decl simple_type_decl;
    A_type_decl type_decl;
};

struct A_record_type_decl_
{
    A_pos pos;
    A_field_decl_list field_decl_list;
};

struct A_field_decl_list_
{
    A_pos pos;
    A_is_seq is_seq;
    A_field_decl_list field_decl_list;
    A_field_decl field_decl;
};

struct A_field_decl_
{
    A_pos pos;
    A_name_list name_list;
    A_type_decl type_decl;
};

struct A_name_list_
{
    A_pos pos;
    A_is_seq is_seq;
    A_name_list name_list;
//    char *id;
    S_symbol id;
};

struct A_var_part_
{
    A_pos pos;
    A_var_decl_list var_decl_list;
};

struct A_var_decl_list_
{
    A_pos pos;
    A_is_seq is_seq;
    A_var_decl_list var_decl_list;
    A_var_decl var_decl;
};

struct A_var_decl_
{
    A_pos pos;
    A_name_list name_list;
    A_type_decl type_decl;
};

struct A_routine_part_
{
    A_pos pos;
    A_is_seq is_seq;
    enum
    {
        routine_part_function,
        routine_part_procedure,
        //routine_part_empty
    } kind;
    //A_routine_part_prime routine_part_prime;
    union
    {
        A_function_decl function_decl;
        A_procedure_decl procedure_decl;
    } u;
};

struct A_routine_part_prime_ {
    A_pos pos;
    A_is_seq is_seq;
    enum {
        routine_part_prime_function,
        routine_part_prime_procedure,
        routine_part_prime_empty
    } kind;
    A_routine_part_prime routine_part_prime;
    union {
        A_function_decl function_decl;
        A_procedure_decl procedure_decl;
    } u;
};

struct A_function_decl_
{
    A_pos pos;
    A_function_head function_head;
    A_sub_routine sub_routine;
};

struct A_function_head_
{
    A_pos pos;
//    char *id;
    S_symbol id;
    A_parameters parameters;
    A_simple_type_decl simple_type_decl;
};

struct A_procedure_decl_
{
    A_pos pos;
    A_procedure_head procedure_head;
    A_sub_routine sub_routine;
};

struct A_procedure_head_
{
    A_pos pos;
//    char *id;
    S_symbol id;
    A_parameters parameters;
};

struct A_parameters_
{
    A_pos pos;
    A_para_decl_list para_decl_list;
};

struct A_para_decl_list_
{
    A_pos pos;
    A_is_seq is_seq;
    A_para_decl_list para_decl_list;
    A_para_type_list para_type_list;
};

struct A_para_type_list_
{
    A_pos pos;
    enum
    {
        para_type_list_var,
        para_type_list_val
    } kind;
    union
    {
        struct
        {
            A_var_para_list var_para_list;
            A_simple_type_decl simple_type_decl;
        } var_para_list;
        struct
        {
            A_val_para_list val_para_list;
            A_simple_type_decl simple_type_decl;
        } val_para_list;
    } u;
};

struct A_var_para_list_
{
    A_pos pos;
    A_name_list name_list;
};

struct A_val_para_list_
{
    A_pos pos;
    A_name_list name_list;
};

struct A_routine_body_
{
    A_pos pos;
    A_compound_stmt compound_stmt;
};

struct A_compound_stmt_
{
    A_pos pos;
    A_stmt_list stmt_list;
};

struct A_stmt_list_
{
    A_pos pos;
    A_stmt_list stmt_list;
    A_stmt stmt;
};

struct A_stmt_
{
    A_pos pos;
    A_is_label is_label;
    int label;
    A_non_label_stmt non_label_stmt;
};

struct A_non_label_stmt_
{
    A_pos pos;
    enum
    {
        non_label_stmt_assign,
        non_label_stmt_proc,
        non_label_stmt_compound,
        non_label_stmt_if,
        non_label_stmt_repeat,
        non_label_stmt_while,
        non_label_stmt_for,
        non_label_stmt_case,
        non_label_stmt_goto
    } kind;
    union
    {
        A_assign_stmt assign_stmt;
        A_proc_stmt proc_stmt;
        A_compound_stmt compound_stmt;
        A_if_stmt if_stmt;
        A_repeat_stmt repeat_stmt;
        A_while_stmt while_stmt;
        A_for_stmt for_stmt;
        A_case_stmt case_stmt;
        A_goto_stmt goto_stmt;
    } u;
};

struct A_assign_stmt_
{
    A_pos pos;
    enum
    {
        assign_stmt_simple,
        assign_stmt_record,
        assign_stmt_array
    } kind;
    union
    {
        struct
        {
//            char *id;
            S_symbol id;
            A_expression right_expression;
        } simple_var_assign_stmt;
        struct
        {
//            char *id;
//            char *field_id;
            S_symbol id;
            S_symbol field_id;
            A_expression right_expression;
        } record_var_assign_stmt;
        struct
        {
//            char *id;
            S_symbol id;
            A_expression subscript_expression;
            A_expression right_expression;
        } array_var_assign_stmt;
    } u;
};

struct A_proc_stmt_
{
    A_pos pos;
    enum
    {
        proc_stmt_id,
        proc_stmt_id_with_args,
        proc_stmt_sys_proc,
        proc_stmt_sys_proc_with_args,
        proc_stmt_read
    } kind;
    union
    {
//        char *id;
        S_symbol id;
        struct
        {
//            char *id;
            S_symbol id;
            A_args_list args_list;
        } id_with_args;
        A_SYS_PROC sys_proc;
        struct
        {
            A_SYS_PROC sys_proc;
            A_expression_list expression_list;
        } sys_proc_with_args;
        A_factor factor;
    } u;
};

struct A_if_stmt_
{
    A_pos pos;
    A_expression test;
    A_stmt body;
    A_else_clause else_clause;
};

struct A_else_clause_
{
    A_pos pos;
    A_stmt body;
};

struct A_repeat_stmt_
{
    A_pos pos;
    A_stmt_list body;
    A_expression until;
};

struct A_while_stmt_
{
    A_pos pos;
    A_expression test;
    A_stmt body;
};

struct A_for_stmt_
{
    A_pos pos;
//    char *loop_var;
    S_symbol loop_var;
    A_expression lo;
    A_direction direction;
    A_expression hi;
    A_stmt body;
};

struct A_case_stmt_
{
    A_expression expression;
    A_case_expr_list case_expr_list;
};

struct A_case_expr_list_
{
    A_pos pos;
    A_is_seq is_seq;
    A_case_expr_list case_expr_list;
    A_case_expr case_expr;
};

struct A_case_expr_
{
    A_pos pos;
    enum
    {
        case_expr_const_value,
        case_expr_non_const_value
    } kind;
    union
    {
        struct
        {
            A_const_value const_value;
            A_stmt body;
        } const_value;
        struct
        {
//            char *id;
            S_symbol id;
            A_stmt body;
        } non_const_value;
    } u;
};

struct A_goto_stmt_
{
    A_pos pos;
    int label;
};

struct A_expression_list_
{
    A_pos pos;
    A_is_seq is_seq;
    A_expression_list expression_list;
    A_expression expression;
};

struct A_expression_
{
    A_pos pos;
    A_is_bin_op is_bin_op;
    union
    {
        struct
        {
            A_expression left_expression;
            A_rel_op rel_op;
            A_expr right_expr;
        } bin_op;
        A_expr expr;
    } u;
};

struct A_expr_
{
    A_pos pos;
    A_is_bin_op is_bin_op;
    union
    {
        struct
        {
            A_expr left_expr;
            A_plus_op plus_op;
            A_term right_term;
        } bin_op;
        A_term term;
    } u;
};

struct A_term_
{
    A_pos pos;
    A_is_bin_op is_bin_op;
    union
    {
        struct
        {
            A_term left_term;
            A_mul_op mul_op;
            A_factor right_factor;
        } bin_op;
        A_factor factor;
    } u;
};

struct A_factor_
{
    A_pos pos;
    enum factor_kind
    {
        factor_id,
        factor_id_with_args,
        factor_sys_funct,
        factor_sys_funct_with_args,
        factor_const_value,
        factor_in_brackets,
        factor_un_op,
        factor_array_var,
        factor_record_var
    } kind;
    union
    {
//        char *id;
        S_symbol id;
        struct
        {
//            char *id;
            S_symbol id;
            A_args_list args_list;
        } id_with_args;
        A_SYS_FUNCT sys_funct;
        struct
        {
            A_SYS_FUNCT sys_funct;
            A_args_list args_list;
        } sys_funct_with_args;
        A_const_value const_value;
        A_expression expression;
        struct
        {
            A_un_op un_op;
            A_factor factor;
        } un_op;
        struct
        {
//            char *id;
            S_symbol id;
//            char *field_id;
            S_symbol field_id;
        } record_var;
        struct
        {
//            char *id;
            S_symbol id;
            A_expression subscript_expression;
        } array_var;
    } u;
};

struct A_args_list_
{
    A_pos pos;
    A_is_seq is_seq;
    A_args_list args_list;
    A_expression expression;
};

A_program A_Program(A_pos pos, A_program_head program_head, A_routine routine);

A_program_head A_ProgramHead(A_pos, char *id);

A_routine A_Routine(A_pos pos, A_routine_head routine_head, A_routine_body routine_body);

A_sub_routine A_SubRoutine(A_pos pos, A_routine_head routine_head, A_routine_body routine_body);

A_routine_head
A_RoutineHead(A_pos pos, A_label_part label_part, A_const_part const_part, A_type_part type_part, A_var_part var_part,
              A_routine_part routine_part);

A_routine_body A_RoutineBody(A_pos pos, A_compound_stmt compound_stmt);

A_label_part A_LabelPart(A_pos pos);

A_const_part A_ConstPart(A_pos pos, A_const_expr_list const_expr_list);

A_type_part A_TypePart(A_pos pos, A_type_decl_list type_decl_list);

A_var_part A_VarPart(A_pos pos, A_var_decl_list var_decl_list);


A_routine_part A_RoutinePartSeqWithProcedureDecl(A_pos pos, A_routine_part routine_part, A_procedure_decl procedure_decl);

A_routine_part A_RoutinePartSeqWithFunctionDecl(A_pos pos, A_routine_part routine_part, A_function_decl function_decl);

A_routine_part A_RoutinePartWithProcedureDecl(A_pos pos, A_procedure_decl procedure_decl);

A_routine_part A_RoutinePartWithFunctionDecl(A_pos pos, A_function_decl function_decl);


//A_routine_part A_RoutinePartWithFunctionDecl(A_pos pos, A_function_decl function_decl, A_routine_part_prime routine_part_prime);
//A_routine_part A_RoutinePartWithProcedureDecl(A_pos pos, A_procedure_decl procedure_decl, A_routine_part_prime routine_part_prime);
//A_routine_part_prime A_RoutinePartPrimeWithFunctionDecl(A_pos pos, A_function_decl function_decl, A_routine_part_prime routine_part_prime);
//A_routine_part_prime A_RoutinePartPrimeWithProcedureDecl(A_pos pos, A_procedure_decl procedure_decl, A_routine_part_prime routine_part_prime);

A_const_expr_list A_ConstExprListSeq(A_pos pos, A_const_expr_list const_expr_list, S_symbol id, A_const_value const_value);

A_const_expr_list A_ConstExprList(A_pos pos, S_symbol id, A_const_value const_value);

A_const_value A_ConstValueInteger(A_pos pos, int intt);

A_const_value A_ConstValueReal(A_pos pos, double real);

A_const_value A_ConstValueChar(A_pos pos, char *charr);

A_const_value A_ConstValueString(A_pos pos, char *string);

A_const_value A_ConstValueSysCon(A_pos pos, A_SYS_CON sys_con);

A_type_decl_list A_TypeDeclListSeq(A_pos pos, A_type_decl_list type_decl_list, A_type_definition type_definition);

A_type_decl_list A_TypeDeclList(A_pos pos, A_type_definition type_definition);

A_type_definition A_TypeDefinition(A_pos pos, S_symbol id, A_type_decl type_decl);

A_type_decl A_TypeDeclSimple(A_pos pos, A_simple_type_decl simple_type_decl);

A_type_decl A_TypeDeclRecord(A_pos pos, A_record_type_decl record_type_decl);

A_type_decl A_TypeDeclArray(A_pos pos, A_array_type_decl array_type_decl);

A_simple_type_decl A_SimpleTypeDeclSysType(A_pos pos, A_SYS_TYPE sys_type);

A_simple_type_decl A_SimpleTypeDeclId(A_pos pos, S_symbol id);

A_simple_type_decl A_SimpleTypeDeclNameList(A_pos pos, A_name_list name_list);

A_simple_type_decl A_SimpleTypeDeclRangeConst(A_pos pos, A_const_value from, A_const_value to);

A_simple_type_decl A_SimpleTypeDeclRangeId(A_pos pos, S_symbol from, S_symbol to);

A_array_type_decl A_ArrayTypeDecl(A_pos pos, A_simple_type_decl simple_decl, A_type_decl type_decl);

A_record_type_decl A_RecordTypeDecl(A_pos pos, A_field_decl_list field_decl_list);

A_field_decl_list A_FieldDeclListSeq(A_pos, A_field_decl_list field_decl_list, A_field_decl field_decl);

A_field_decl_list A_FieldDeclList(A_pos, A_field_decl field_decl);

A_field_decl A_FieldDecl(A_pos pos, A_name_list name_list, A_type_decl type_decl);

A_name_list A_NameListSeq(A_pos pos, A_name_list name_list, S_symbol id);

A_name_list A_NameList(A_pos pos, S_symbol id);

A_var_decl_list A_VarDeclListSeq(A_pos pos, A_var_decl_list var_decl_list, A_var_decl var_decl);

A_var_decl_list A_VarDeclList(A_pos pos, A_var_decl var_decl);

A_var_decl A_VarDecl(A_pos pos, A_name_list name_list, A_type_decl type_decl);

A_function_decl A_FunctionDecl(A_pos pos, A_function_head function_head, A_sub_routine sub_routine);

A_procedure_decl A_ProcedureDecl(A_pos pos, A_procedure_head procedure_head, A_sub_routine sub_routine);

A_function_head A_FunctionHead(A_pos pos, S_symbol id, A_parameters parameters, A_simple_type_decl simple_type_decl);

A_procedure_head A_ProcedureHead(A_pos pos, S_symbol id, A_parameters parameters);

A_parameters A_Parameters(A_pos pos, A_para_decl_list para_decl_list);

A_para_decl_list A_ParaDeclListSeq(A_pos pos, A_para_decl_list para_decl_list, A_para_type_list para_type_list);

A_para_decl_list A_ParaDeclList(A_pos pos, A_para_type_list para_type_list);

A_para_type_list A_ParaTypeListVar(A_pos pos, A_var_para_list var_para_list, A_simple_type_decl simple_type_decl);

A_para_type_list A_ParaTypeListVal(A_pos pos, A_val_para_list val_para_list, A_simple_type_decl simple_type_decl);

A_var_para_list A_VarParaList(A_pos pos, A_name_list name_list);

A_val_para_list A_ValParaList(A_pos pos, A_name_list name_list);

A_compound_stmt A_CompoundStmt(A_pos pos, A_stmt_list stmt_list);

A_stmt_list A_StmtList(A_pos pos, A_stmt_list stmt_list, A_stmt stmt);

A_stmt A_StmtLabel(A_pos pos, int label, A_non_label_stmt non_label_stmt);

A_stmt A_StmtNonLabel(A_pos pos, A_non_label_stmt non_label_stmt);

A_non_label_stmt A_NonLabelStmtAssign(A_pos pos, A_assign_stmt assign_stmt);

A_non_label_stmt A_NonLabelStmtProc(A_pos pos, A_proc_stmt proc_stmt);

A_non_label_stmt A_NonLabelStmtCompound(A_pos pos, A_compound_stmt compound_stmt);

A_non_label_stmt A_NonLabelStmtIf(A_pos pos, A_if_stmt if_stmt);

A_non_label_stmt A_NonLabelStmtRepeat(A_pos pos, A_repeat_stmt repeat_stmt);

A_non_label_stmt A_NonLabelStmtWhile(A_pos pos, A_while_stmt while_stmt);

A_non_label_stmt A_NonLabelStmtCase(A_pos pos, A_case_stmt case_stmt);

A_non_label_stmt A_NonLabelStmtFor(A_pos pos, A_for_stmt for_stmt);

A_non_label_stmt A_NonLabelStmtGoto(A_pos pos, A_goto_stmt goto_stmt);

A_assign_stmt A_AssignStmtSimple(A_pos pos, S_symbol id, A_expression right_expression);

A_assign_stmt A_AssignStmtRecord(A_pos pos, S_symbol id, S_symbol field_id, A_expression right_expression);

A_assign_stmt A_AssignStmtArray(A_pos pos, S_symbol id, A_expression subscript_expression, A_expression right_expression);

A_proc_stmt A_ProcStmtID(A_pos pos, S_symbol id);

A_proc_stmt A_ProcStmtIDWithArgs(A_pos pos, S_symbol id, A_args_list args_list);

A_proc_stmt A_ProcStmtSysProc(A_pos pos, A_SYS_PROC sys_proc);

A_proc_stmt A_ProcStmtSysProcWithArgs(A_pos pos, A_SYS_PROC sys_proc, A_expression_list expression_list);

A_proc_stmt A_ProcStmtRead(A_pos pos, A_factor);

A_if_stmt A_IfStmt(A_pos pos, A_expression test, A_stmt body, A_else_clause else_clause);

A_repeat_stmt A_RepeatStmt(A_pos pos, A_stmt_list body, A_expression until);

A_while_stmt A_WhileStmt(A_pos pos, A_expression test, A_stmt body);

A_for_stmt A_ForStmt(A_pos pos, S_symbol loop_var, A_expression lo, A_direction direction, A_expression hi, A_stmt body);

A_case_stmt A_CaseStmt(A_pos pos, A_expression expression, A_case_expr_list case_expr_list);

A_goto_stmt A_GotoStmt(A_pos pos, int label);

A_else_clause A_ElseClause(A_pos pos, A_stmt else_body);

A_case_expr_list A_CaseExprListSeq(A_pos pos, A_case_expr_list casde_expr_list, A_case_expr case_expr);

A_case_expr_list A_CaseExprList(A_pos pos, A_case_expr case_expr);

A_case_expr A_CaseExprConst(A_pos pos, A_const_value const_value, A_stmt body);

A_case_expr A_CaseExprNonConst(A_pos pos, S_symbol id, A_stmt body);

A_expression_list A_ExpressionListSeq(A_pos pos, A_expression_list expression_list, A_expression expression);

A_expression_list A_ExpressionList(A_pos pos, A_expression expression);

A_expression A_ExpressionBin(A_pos pos, A_expression left_expression, A_rel_op rel_op, A_expr right_expr);

A_expression A_ExpressionUn(A_pos pos, A_expr expr);

A_expr A_ExprBin(A_pos pos, A_expr left_expr, A_plus_op plus_op, A_term right_term);

A_expr A_ExprUn(A_pos pos, A_term term);

A_term A_TermBin(A_pos pos, A_term left_term, A_mul_op mul_op, A_factor right_factor);

A_term A_TermUn(A_pos pos, A_factor factor);

A_factor A_FactorId(A_pos pos, S_symbol id);

A_factor A_FactorIdWithArgs(A_pos pos, S_symbol id, A_args_list args_list);

A_factor A_FactorSysFunct(A_pos pos, A_SYS_FUNCT sys_funct);

A_factor A_FactorSysFunctWithArgs(A_pos pos, A_SYS_FUNCT sys_funct, A_args_list args_list);

A_factor A_FactorConst(A_pos pos, A_const_value const_value);

A_factor A_FactorInBrackets(A_pos pos, A_expression expression);

A_factor A_FactorUnOp(A_pos pos, A_un_op un_op, A_factor factor);

A_factor A_FactorRecordVar(A_pos pos, S_symbol id, S_symbol field_id);

A_factor A_FactorArrayVar(A_pos pos, S_symbol id, A_expression subscript_expression);

A_args_list A_ArgsListSeq(A_pos pos, A_args_list args_list, A_expression expression);

A_args_list A_ArgsList(A_pos pos, A_expression expression);

#endif // absyn.h
