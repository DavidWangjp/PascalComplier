typedef union
{
    int ival;
	double dval;
    char* sval;

    A_SYS_FUNCT sys_funct;
    A_SYS_PROC sys_proc;
    A_SYS_TYPE sys_type;
    A_SYS_CON sys_con;

    A_program program;
    A_program_head program_head;
    A_routine routine;
    A_sub_routine sub_routine;
    A_routine_head routine_head;
    A_routine_body routine_body;
    A_label_part label_part;
    A_const_part const_part;
    A_type_part type_part;
    A_var_part var_part;
    A_routine_part routine_part;
    A_routine_part_prime routine_part_prime;

    A_const_expr_list const_expr_list;
    A_const_value const_value;

    A_type_decl_list type_decl_list;
    A_type_definition type_definition;
    A_type_decl type_decl;
    A_simple_type_decl simple_type_decl;
    A_array_type_decl array_type_decl;
    A_record_type_decl record_type_decl;
    A_field_decl_list field_decl_list;
    A_field_decl field_decl;
    A_name_list name_list;
    A_var_decl_list var_decl_list;
    A_var_decl var_decl;

    A_function_decl function_decl;
    A_procedure_decl procedure_decl;
    A_function_head function_head;
    A_procedure_head procedure_head;
    A_parameters parameters;
    A_para_decl_list para_decl_list;
    A_para_type_list para_type_list;
    A_var_para_list var_para_list;
    A_val_para_list val_para_list;

    A_compound_stmt compound_stmt;
    A_stmt_list stmt_list;
    A_stmt stmt;
    A_non_label_stmt non_label_stmt;

    A_assign_stmt assign_stmt;
    A_proc_stmt proc_stmt;
    A_if_stmt if_stmt;
    A_repeat_stmt repeat_stmt;
    A_while_stmt while_stmt;
    A_for_stmt for_stmt;
    A_case_stmt case_stmt;
    A_goto_stmt goto_stmt;

    A_else_clause else_clause;
    A_case_expr_list case_expr_list;
    A_case_expr case_expr;
    A_expression_list expression_list;
    A_expression expression;
    A_expr expr;
    A_term term;
    A_factor factor;
    A_args_list args_list;

    A_un_op un_op;
    A_rel_op rel_op;
    A_plus_op plus_op;
    A_mul_op mul_op;
    A_direction direction;
} YYSTYPE;
#define	ID	257
#define	INTEGER	258
#define	REAL	259
#define	CHAR	260
#define	STRING	261
#define	PROGRAM	262
#define	CONST	263
#define	ARRAY	264
#define	RECORD	265
#define	BEGIN	266
#define	END	267
#define	VAR	268
#define	FUNCTION	269
#define	PROCEDURE	270
#define	TYPE	271
#define	READ	272
#define	IF	273
#define	THEN	274
#define	ELSE	275
#define	REPEAT	276
#define	UNTIL	277
#define	WHILE	278
#define	DO	279
#define	FOR	280
#define	CASE	281
#define	OF	282
#define	GOTO	283
#define	DOT	284
#define	DOTDOT	285
#define	SEMI	286
#define	COLON	287
#define	COMMA	288
#define	LB	289
#define	RB	290
#define	LP	291
#define	RP	292
#define	ASSIGN	293
#define	NOT	294
#define	NEG	295
#define	EQUAL	296
#define	UNEQUAL	297
#define	GE	298
#define	GT	299
#define	LE	300
#define	LT	301
#define	PLUS	302
#define	MINUS	303
#define	OR	304
#define	MUL	305
#define	DIV	306
#define	MOD	307
#define	AND	308
#define	TO	309
#define	DOWNTO	310
#define	SYS_TYPE	311
#define	SYS_FUNCT	312
#define	SYS_PROC	313
#define	SYS_CON	314
#define	LOWER_THAN_ELSE	315


extern YYSTYPE yylval;
