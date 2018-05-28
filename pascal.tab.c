
/*  A Bison parser, made from pascal.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

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

#line 1 "pascal.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "absyn.h"
#include "util.h"
#include "symbol.h"

void yyerror(const char *s);
extern int yylex(void);
extern int line_no;


#line 17 "pascal.y"
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
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		261
#define	YYFLAG		-32768
#define	YYNTBASE	62

#define YYTRANSLATE(x) ((unsigned)(x) <= 315 ? yytranslate[x] : 117)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     4,     8,    11,    14,    20,    21,    24,    25,    31,
    36,    38,    40,    42,    44,    46,    49,    50,    53,    55,
    60,    62,    64,    66,    68,    70,    74,    78,    83,    89,
    93,   100,   104,   107,   109,   114,   118,   120,   123,   124,
   127,   129,   134,   137,   140,   142,   144,   145,   150,   156,
   161,   165,   169,   170,   174,   176,   180,   184,   187,   189,
   191,   195,   199,   200,   204,   206,   208,   210,   212,   214,
   216,   218,   220,   222,   224,   228,   235,   241,   243,   248,
   250,   255,   260,   266,   269,   270,   275,   280,   289,   291,
   293,   299,   302,   304,   309,   314,   317,   321,   323,   327,
   331,   335,   339,   343,   347,   349,   353,   357,   361,   363,
   367,   371,   375,   379,   381,   383,   388,   390,   395,   397,
   401,   404,   407,   412,   416,   420
};

static const short yyrhs[] = {    63,
    64,    30,     0,     8,     3,    32,     0,    66,    94,     0,
    66,    94,     0,    67,    68,    71,    81,    84,     0,     0,
     9,    69,     0,     0,    69,     3,    42,    70,    32,     0,
     3,    42,    70,    32,     0,     4,     0,     5,     0,     6,
     0,     7,     0,    60,     0,    17,    72,     0,     0,    72,
    73,     0,    73,     0,     3,    42,    74,    32,     0,    75,
     0,    76,     0,    77,     0,    57,     0,     3,     0,    37,
    80,    38,     0,    70,    31,    70,     0,    49,    70,    31,
    70,     0,    49,    70,    31,    49,    70,     0,     3,    31,
     3,     0,    10,    35,    75,    36,    28,    74,     0,    11,
    78,    13,     0,    78,    79,     0,    79,     0,    80,    33,
    74,    32,     0,    80,    34,     3,     0,     3,     0,    14,
    82,     0,     0,    82,    83,     0,    83,     0,    80,    33,
    74,    32,     0,    84,    85,     0,    84,    87,     0,    85,
     0,    87,     0,     0,    86,    32,    65,    32,     0,    15,
     3,    89,    33,    75,     0,    88,    32,    65,    32,     0,
    16,     3,    89,     0,    37,    90,    38,     0,     0,    90,
    32,    91,     0,    91,     0,    92,    33,    75,     0,    93,
    33,    75,     0,    14,    80,     0,    80,     0,    95,     0,
    12,    96,    13,     0,    96,    97,    32,     0,     0,     4,
    33,    98,     0,    98,     0,    99,     0,   100,     0,    95,
     0,   101,     0,   103,     0,   104,     0,   105,     0,   107,
     0,   110,     0,     3,    39,   112,     0,     3,    35,   112,
    36,    39,   112,     0,     3,    30,     3,    39,   112,     0,
     3,     0,     3,    37,   116,    38,     0,    59,     0,    59,
    37,   111,    38,     0,    18,    37,   115,    38,     0,    19,
   112,    20,    97,   102,     0,    21,    97,     0,     0,    22,
    96,    23,   112,     0,    24,   112,    25,    97,     0,    26,
     3,    39,   112,   106,   112,    25,    97,     0,    55,     0,
    56,     0,    27,   112,    28,   108,    13,     0,   108,   109,
     0,   109,     0,    70,    33,    97,    32,     0,     3,    33,
    97,    32,     0,    29,     4,     0,   111,    34,   112,     0,
   112,     0,   112,    44,   113,     0,   112,    45,   113,     0,
   112,    46,   113,     0,   112,    47,   113,     0,   112,    42,
   113,     0,   112,    43,   113,     0,   113,     0,   113,    48,
   114,     0,   113,    49,   114,     0,   113,    50,   114,     0,
   114,     0,   114,    51,   115,     0,   114,    52,   115,     0,
   114,    53,   115,     0,   114,    54,   115,     0,   115,     0,
     3,     0,     3,    37,   116,    38,     0,    58,     0,    58,
    37,   116,    38,     0,    70,     0,    37,   112,    38,     0,
    40,   115,     0,    49,   115,     0,     3,    35,   112,    36,
     0,     3,    30,     3,     0,   116,    34,   112,     0,   112,
     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   190,   195,   200,   205,   210,   215,   220,   223,   228,   232,
   237,   240,   243,   246,   249,   254,   257,   262,   265,   270,
   276,   279,   282,   287,   290,   294,   297,   300,   310,   322,
   328,   333,   338,   341,   346,   351,   355,   361,   364,   369,
   372,   377,   382,   385,   388,   391,   394,   399,   404,   409,
   414,   420,   423,   428,   431,   437,   440,   445,   450,   455,
   460,   465,   468,   473,   476,   481,   484,   487,   490,   493,
   496,   499,   502,   505,   510,   514,   518,   524,   528,   531,
   534,   537,   542,   547,   549,   555,   560,   565,   570,   573,
   578,   583,   586,   591,   594,   600,   605,   608,   613,   616,
   619,   622,   625,   628,   631,   636,   639,   642,   645,   650,
   653,   656,   659,   662,   667,   671,   675,   678,   681,   684,
   687,   690,   693,   697,   703,   706
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","ID","INTEGER",
"REAL","CHAR","STRING","PROGRAM","CONST","ARRAY","RECORD","BEGIN","END","VAR",
"FUNCTION","PROCEDURE","TYPE","READ","IF","THEN","ELSE","REPEAT","UNTIL","WHILE",
"DO","FOR","CASE","OF","GOTO","DOT","DOTDOT","SEMI","COLON","COMMA","LB","RB",
"LP","RP","ASSIGN","NOT","NEG","EQUAL","UNEQUAL","GE","GT","LE","LT","PLUS",
"MINUS","OR","MUL","DIV","MOD","AND","TO","DOWNTO","SYS_TYPE","SYS_FUNCT","SYS_PROC",
"SYS_CON","LOWER_THAN_ELSE","program","program_head","routine","sub_routine",
"routine_head","label_part","const_part","const_expr_list","const_value","type_part",
"type_decl_list","type_definition","type_decl","simple_type_decl","array_type_decl",
"record_type_decl","field_decl_list","field_decl","name_list","var_part","var_decl_list",
"var_decl","routine_part","function_decl","function_head","procedure_decl","procedure_head",
"parameters","para_decl_list","para_type_list","var_para_list","val_para_list",
"routine_body","compound_stmt","stmt_list","stmt","non_label_stmt","assign_stmt",
"proc_stmt","if_stmt","else_clause","repeat_stmt","while_stmt","for_stmt","direction",
"case_stmt","case_expr_list","case_expr","goto_stmt","expression_list","expression",
"expr","term","factor","args_list", NULL
};
#endif

static const short yyr1[] = {     0,
    62,    63,    64,    65,    66,    67,    68,    68,    69,    69,
    70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
    74,    74,    74,    75,    75,    75,    75,    75,    75,    75,
    76,    77,    78,    78,    79,    80,    80,    81,    81,    82,
    82,    83,    84,    84,    84,    84,    84,    85,    86,    87,
    88,    89,    89,    90,    90,    91,    91,    92,    93,    94,
    95,    96,    96,    97,    97,    98,    98,    98,    98,    98,
    98,    98,    98,    98,    99,    99,    99,   100,   100,   100,
   100,   100,   101,   102,   102,   103,   104,   105,   106,   106,
   107,   108,   108,   109,   109,   110,   111,   111,   112,   112,
   112,   112,   112,   112,   112,   113,   113,   113,   113,   114,
   114,   114,   114,   114,   115,   115,   115,   115,   115,   115,
   115,   115,   115,   115,   116,   116
};

static const short yyr2[] = {     0,
     3,     3,     2,     2,     5,     0,     2,     0,     5,     4,
     1,     1,     1,     1,     1,     2,     0,     2,     1,     4,
     1,     1,     1,     1,     1,     3,     3,     4,     5,     3,
     6,     3,     2,     1,     4,     3,     1,     2,     0,     2,
     1,     4,     2,     2,     1,     1,     0,     4,     5,     4,
     3,     3,     0,     3,     1,     3,     3,     2,     1,     1,
     3,     3,     0,     3,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     3,     6,     5,     1,     4,     1,
     4,     4,     5,     2,     0,     4,     4,     8,     1,     1,
     5,     2,     1,     4,     4,     2,     3,     1,     3,     3,
     3,     3,     3,     3,     1,     3,     3,     3,     1,     3,
     3,     3,     3,     1,     1,     4,     1,     4,     1,     3,
     2,     2,     4,     3,     3,     1
};

static const short yydefact[] = {     0,
     0,     6,     0,     0,     0,     8,     2,     1,    63,     3,
    60,     0,    17,     0,     0,     7,     0,    39,    78,     0,
    61,     0,     0,    63,     0,     0,     0,     0,    80,    68,
     0,    65,    66,    67,    69,    70,    71,    72,    73,    74,
     0,     0,     0,    16,    19,     0,    47,     0,     0,     0,
     0,     0,     0,   115,    11,    12,    13,    14,     0,     0,
     0,   117,    15,   119,     0,   105,   109,   114,     0,     0,
     0,     0,    96,     0,    62,     0,     0,     0,    18,    37,
     0,    38,    41,     0,     0,     5,    45,     0,    46,     0,
     0,     0,   126,     0,    75,    64,     0,     0,     0,     0,
     0,   121,   122,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    98,    10,     0,    25,     0,     0,     0,
     0,    24,     0,     0,    21,    22,    23,     0,     0,    40,
    53,    53,    43,    44,     6,     6,     0,     0,     0,    79,
    82,   124,     0,     0,   120,     0,    85,   103,   104,    99,
   100,   101,   102,   106,   107,   108,   110,   111,   112,   113,
    86,    87,     0,     0,     0,     0,    93,     0,    81,     9,
     0,     0,     0,    34,     0,     0,     0,     0,    20,     0,
    36,     0,     0,    51,     0,     0,     0,    77,     0,   125,
   123,   116,   118,     0,    83,    89,    90,     0,     0,     0,
    91,    92,    97,    30,     0,    32,    33,     0,    26,     0,
    27,    42,     0,    59,     0,    55,     0,     0,     0,    48,
     4,    50,    76,    84,     0,     0,     0,     0,     0,     0,
    28,    58,     0,    52,     0,     0,    49,     0,    95,    94,
     0,    35,    29,    54,    56,    57,    88,    31,     0,     0,
     0
};

static const short yydefgoto[] = {   259,
     2,     4,   195,   196,     6,    13,    16,    64,    18,    44,
    45,   134,   135,   136,   137,   183,   184,    81,    47,    82,
    83,    86,    87,    88,    89,    90,   193,   225,   226,   227,
   228,    10,    30,    14,    31,    32,    33,    34,    35,   205,
    36,    37,    38,   208,    39,   176,   177,    40,   123,    93,
    66,    67,    68,    94
};

static const short yypact[] = {     5,
    24,-32768,    23,    27,    57,    78,-32768,-32768,-32768,-32768,
-32768,    96,    72,   171,    85,   111,   133,   124,    15,   107,
-32768,   102,    28,-32768,    28,   139,    28,   140,   112,-32768,
   126,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    99,   114,   122,   133,-32768,   170,    31,   173,    28,    28,
    28,   241,    28,    21,-32768,-32768,-32768,-32768,    28,    28,
    28,   128,-32768,-32768,   192,    74,   162,-32768,   199,   125,
   141,    87,-32768,    28,-32768,   149,    99,   106,-32768,-32768,
    49,   170,-32768,   179,   182,    31,-32768,   154,-32768,   159,
   155,   252,   281,   -23,   281,-32768,   163,   203,    28,    28,
   275,-32768,-32768,    28,   228,    28,    28,    28,    28,    28,
    28,    28,    28,    28,    28,    28,    28,    28,    28,   228,
    28,    19,    10,   281,-32768,   176,   178,   184,   170,   170,
    99,-32768,   189,   195,-32768,-32768,-32768,   106,   221,-32768,
   196,   196,-32768,-32768,-32768,-32768,    28,   190,    28,-32768,
-32768,-32768,   265,    26,-32768,    29,   220,    74,    74,    74,
    74,    74,    74,   162,   162,   162,-32768,-32768,-32768,-32768,
   281,-32768,   237,   209,   210,    36,-32768,    28,-32768,-32768,
   242,    88,    16,-32768,    86,    46,   217,    99,-32768,   219,
-32768,     7,   216,-32768,   229,    57,   230,   281,    28,   281,
-32768,-32768,-32768,   228,-32768,-32768,-32768,    28,   228,   228,
-32768,-32768,   281,-32768,   233,-32768,-32768,   106,-32768,   147,
-32768,-32768,   170,   232,   -18,-32768,   238,   239,    88,-32768,
-32768,-32768,   281,-32768,   231,   253,   254,   236,   257,    99,
-32768,   232,     7,-32768,    88,    88,-32768,   228,-32768,-32768,
   106,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   290,   291,
-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,   156,   301,-32768,-32768,-32768,   -41,-32768,-32768,
   260,  -133,  -170,-32768,-32768,-32768,   123,  -122,-32768,-32768,
   234,-32768,   249,-32768,   250,-32768,   172,-32768,    62,-32768,
-32768,   119,    -4,   313,  -102,   286,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   164,-32768,-32768,   -21,
   223,    48,   -44,   -38
};


#define	YYLAST		340


static const short yytable[] = {    76,
    11,    65,   157,    70,   190,    72,   185,   186,    97,    80,
   149,   215,     1,   243,   150,   102,   103,   172,    80,   244,
   223,   174,    55,    56,    57,    58,     3,    92,   216,    95,
    54,    55,    56,    57,    58,   126,   133,   101,   174,    55,
    56,    57,    58,   178,    48,    84,    85,   179,   211,    49,
    98,    50,   124,    51,     7,    99,     8,   100,   247,   149,
   185,   154,   149,   202,    59,   156,   203,    60,     9,   224,
   167,   168,   169,   170,   255,   256,    61,   153,    63,   139,
   175,   138,   139,   219,   239,    62,    12,    63,    17,   187,
   127,    55,    56,    57,    58,    63,   133,   171,    15,   173,
   242,   234,    55,    56,    57,    58,   236,   237,   127,    55,
    56,    57,    58,    42,   122,   128,   129,   258,   218,   139,
   224,   112,   113,   114,   130,   198,    41,   200,   106,   107,
   108,   109,   110,   111,   175,    43,   131,    46,    53,    52,
   133,    71,   130,    73,   132,   257,   221,    63,    74,   120,
    55,    56,    57,    58,   131,    77,   213,    75,    63,   164,
   165,   166,   132,    78,   104,    63,   106,   107,   108,   109,
   110,   111,    80,    19,    20,    91,   133,   233,   241,   121,
   125,   141,     9,    21,   142,   145,   235,   133,    22,    23,
   146,    11,    24,   147,    25,   240,    26,    27,   253,    28,
   151,    19,    20,   133,   133,   152,    63,   180,   181,   133,
     9,   105,   115,   116,   117,   118,    22,    23,   182,   188,
    24,   119,    25,   191,    26,    27,   189,    28,   199,    29,
    19,    20,   192,   106,   107,   108,   109,   110,   111,     9,
   204,   209,   210,    19,   214,    22,    23,   220,   229,    24,
   222,    25,     9,    26,    27,   248,    28,    29,    22,    23,
   230,   232,    24,   251,    25,   139,    26,    27,   238,    28,
   245,   246,   106,   107,   108,   109,   110,   111,   106,   107,
   108,   109,   110,   111,   249,   250,    29,   148,   252,   260,
   261,   206,   207,   106,   107,   108,   109,   110,   111,    29,
   201,   197,     5,    79,   254,   217,   106,   107,   108,   109,
   110,   111,   155,   194,   231,   140,   106,   107,   108,   109,
   110,   111,   106,   107,   108,   109,   110,   111,   158,   159,
   160,   161,   162,   163,   143,   144,    69,    96,     0,   212
};

static const short yycheck[] = {    41,
     5,    23,   105,    25,   138,    27,   129,   130,    53,     3,
    34,   182,     8,    32,    38,    60,    61,   120,     3,    38,
    14,     3,     4,     5,     6,     7,     3,    49,    13,    51,
     3,     4,     5,     6,     7,    77,    78,    59,     3,     4,
     5,     6,     7,    34,    30,    15,    16,    38,    13,    35,
    30,    37,    74,    39,    32,    35,    30,    37,   229,    34,
   183,   100,    34,    38,    37,   104,    38,    40,    12,   192,
   115,   116,   117,   118,   245,   246,    49,    99,    60,    34,
   122,    33,    34,    38,   218,    58,     9,    60,    17,   131,
     3,     4,     5,     6,     7,    60,   138,   119,     3,   121,
   223,   204,     4,     5,     6,     7,   209,   210,     3,     4,
     5,     6,     7,     3,    28,    10,    11,   251,    33,    34,
   243,    48,    49,    50,    37,   147,    42,   149,    42,    43,
    44,    45,    46,    47,   176,     3,    49,    14,    37,    33,
   182,     3,    37,     4,    57,   248,   188,    60,    37,    25,
     4,     5,     6,     7,    49,    42,   178,    32,    60,   112,
   113,   114,    57,    42,    37,    60,    42,    43,    44,    45,
    46,    47,     3,     3,     4,     3,   218,   199,   220,    39,
    32,     3,    12,    13,     3,    32,   208,   229,    18,    19,
    32,   196,    22,    39,    24,    49,    26,    27,   240,    29,
    38,     3,     4,   245,   246,     3,    60,    32,    31,   251,
    12,    20,    51,    52,    53,    54,    18,    19,    35,    31,
    22,    23,    24,     3,    26,    27,    32,    29,    39,    59,
     3,     4,    37,    42,    43,    44,    45,    46,    47,    12,
    21,    33,    33,     3,     3,    18,    19,    31,    33,    22,
    32,    24,    12,    26,    27,    25,    29,    59,    18,    19,
    32,    32,    22,    28,    24,    34,    26,    27,    36,    29,
    33,    33,    42,    43,    44,    45,    46,    47,    42,    43,
    44,    45,    46,    47,    32,    32,    59,    36,    32,     0,
     0,    55,    56,    42,    43,    44,    45,    46,    47,    59,
    36,   146,     2,    44,   243,   183,    42,    43,    44,    45,
    46,    47,    38,   142,   196,    82,    42,    43,    44,    45,
    46,    47,    42,    43,    44,    45,    46,    47,   106,   107,
   108,   109,   110,   111,    86,    86,    24,    52,    -1,   176
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */


#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc)
#include <alloca.h>
#else /* not sparc */
#if (defined (MSDOS) || defined(WIN32)) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#define YYLEX		yylex(&yylval, &yylloc)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_bcopy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif


#line 169 "bison.simple"
int
yyparse()
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
#ifdef YYLSP_NEEDED
		 &yyls1, size * sizeof (*yylsp),
#endif
		 &yystacksize);

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 190 "pascal.y"
{
    yyval.program = A_Program(line_no, yyvsp[-2].program_head, yyvsp[-1].routine);
;
    break;}
case 2:
#line 195 "pascal.y"
{
    yyval.program_head = A_ProgramHead(line_no, yyvsp[-1].sval);
;
    break;}
case 3:
#line 200 "pascal.y"
{
    yyval.routine = A_Routine(line_no, yyvsp[-1].routine_head, yyvsp[0].routine_body);
;
    break;}
case 4:
#line 205 "pascal.y"
{
    yyval.sub_routine = A_SubRoutine(line_no, yyvsp[-1].routine_head, yyvsp[0].routine_body);
;
    break;}
case 5:
#line 210 "pascal.y"
{
    yyval.routine_head = A_RoutineHead(line_no, yyvsp[-4].label_part, yyvsp[-3].const_part, yyvsp[-2].type_part, yyvsp[-1].var_part, yyvsp[0].routine_part);
;
    break;}
case 6:
#line 215 "pascal.y"
{
    yyval.label_part = A_LabelPart(line_no);
;
    break;}
case 7:
#line 220 "pascal.y"
{
    yyval.const_part = A_ConstPart(line_no, yyvsp[0].const_expr_list);
;
    break;}
case 8:
#line 223 "pascal.y"
{
    yyval.const_part = A_ConstPart(line_no, NULL);
 ;
    break;}
case 9:
#line 228 "pascal.y"
{
    // $$ = A_ConstExprListSeq(line_no, $1, $2, $4);
    yyval.const_expr_list = A_ConstExprListSeq(line_no, yyvsp[-4].const_expr_list, S_Symbol(yyvsp[-3].sval), yyvsp[-1].const_value);
;
    break;}
case 10:
#line 232 "pascal.y"
{
    yyval.const_expr_list = A_ConstExprList(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].const_value);
;
    break;}
case 11:
#line 237 "pascal.y"
{
    yyval.const_value = A_ConstValueInteger(line_no, yyvsp[0].ival);
;
    break;}
case 12:
#line 240 "pascal.y"
{
    yyval.const_value = A_ConstValueReal(line_no, yyvsp[0].dval);
;
    break;}
case 13:
#line 243 "pascal.y"
{
    yyval.const_value = A_ConstValueChar(line_no, yyvsp[0].sval);
;
    break;}
case 14:
#line 246 "pascal.y"
{
    yyval.const_value = A_ConstValueString(line_no, yyvsp[0].sval);
;
    break;}
case 15:
#line 249 "pascal.y"
{
    yyval.const_value = A_ConstValueSysCon(line_no, yyvsp[0].sys_con);
;
    break;}
case 16:
#line 254 "pascal.y"
{
    yyval.type_part = A_TypePart(line_no, yyvsp[0].type_decl_list);
;
    break;}
case 17:
#line 257 "pascal.y"
{
    yyval.type_part = A_TypePart(line_no, NULL);
;
    break;}
case 18:
#line 262 "pascal.y"
{
    yyval.type_decl_list = A_TypeDeclListSeq(line_no, yyvsp[-1].type_decl_list, yyvsp[0].type_definition);
;
    break;}
case 19:
#line 265 "pascal.y"
{
    yyval.type_decl_list = A_TypeDeclList(line_no, yyvsp[0].type_definition);
;
    break;}
case 20:
#line 270 "pascal.y"
{
    // $$ = A_TypeDefinition(line_no, $1, $3);
    yyval.type_definition = A_TypeDefinition(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].type_decl);
;
    break;}
case 21:
#line 276 "pascal.y"
{
    yyval.type_decl = A_TypeDeclSimple(line_no, yyvsp[0].simple_type_decl);
;
    break;}
case 22:
#line 279 "pascal.y"
{
    yyval.type_decl = A_TypeDeclArray(line_no, yyvsp[0].array_type_decl);
;
    break;}
case 23:
#line 282 "pascal.y"
{                    
    yyval.type_decl = A_TypeDeclRecord(line_no, yyvsp[0].record_type_decl);
;
    break;}
case 24:
#line 287 "pascal.y"
{
    yyval.simple_type_decl = A_SimpleTypeDeclSysType(line_no, yyvsp[0].sys_type);
;
    break;}
case 25:
#line 290 "pascal.y"
{
    // $$ = A_SimpleTypeDeclId(line_no, $1);
    yyval.simple_type_decl = A_SimpleTypeDeclId(line_no, S_Symbol(yyvsp[0].sval));
;
    break;}
case 26:
#line 294 "pascal.y"
{
    yyval.simple_type_decl = A_SimpleTypeDeclNameList(line_no, yyvsp[-1].name_list);
;
    break;}
case 27:
#line 297 "pascal.y"
{
    yyval.simple_type_decl = A_SimpleTypeDeclRangeConst(line_no, yyvsp[-2].const_value, yyvsp[0].const_value);
;
    break;}
case 28:
#line 300 "pascal.y"
{
    A_const_value from = NULL;
    if (yyvsp[-2].const_value->kind == INTEGER) {
        from = A_ConstValueInteger(line_no, -(yyvsp[-2].const_value->u.intt));
    }
    else if (yyvsp[-2].const_value->kind == REAL) {
        from = A_ConstValueReal(line_no, -(yyvsp[-2].const_value->u.real));
    }
    yyval.simple_type_decl = A_SimpleTypeDeclRangeConst(line_no, from, yyvsp[0].const_value);
;
    break;}
case 29:
#line 310 "pascal.y"
{
    A_const_value from = NULL, to = NULL;
    if (yyvsp[-3].const_value->kind == INTEGER) {
        from = A_ConstValueInteger(line_no, -(yyvsp[-3].const_value->u.intt));
        to = A_ConstValueInteger(line_no, -(yyvsp[-3].const_value->u.intt));
    }
    else if (yyvsp[-3].const_value->kind == REAL) {
        from = A_ConstValueReal(line_no, -(yyvsp[0].const_value->u.real));
        to = A_ConstValueReal(line_no, -(yyvsp[0].const_value->u.real));
    }
    yyval.simple_type_decl = A_SimpleTypeDeclRangeConst(line_no, from, to);
;
    break;}
case 30:
#line 322 "pascal.y"
{
    //  $$ = A_SimpleTypeDeclIdRangeId(line_no, $1, $3);
    yyval.simple_type_decl = A_SimpleTypeDeclRangeId(line_no, S_Symbol(yyvsp[-2].sval), S_Symbol(yyvsp[0].sval));
;
    break;}
case 31:
#line 328 "pascal.y"
{
    yyval.array_type_decl = A_ArrayTypeDecl(line_no, yyvsp[-3].simple_type_decl, yyvsp[0].type_decl);
;
    break;}
case 32:
#line 333 "pascal.y"
{
    yyval.record_type_decl = A_RecordTypeDecl(line_no, yyvsp[-1].field_decl_list);
;
    break;}
case 33:
#line 338 "pascal.y"
{
    yyval.field_decl_list = A_FieldDeclListSeq(line_no, yyvsp[-1].field_decl_list, yyvsp[0].field_decl);
;
    break;}
case 34:
#line 341 "pascal.y"
{
    yyval.field_decl_list = A_FieldDeclList(line_no, yyvsp[0].field_decl);
;
    break;}
case 35:
#line 346 "pascal.y"
{
    yyval.field_decl = A_FieldDecl(line_no, yyvsp[-3].name_list, yyvsp[-1].type_decl);
;
    break;}
case 36:
#line 351 "pascal.y"
{
    // $$ = A_NameListSeq(line_no, $1, $3);
    yyval.name_list = A_NameListSeq(line_no, yyvsp[-2].name_list, S_Symbol(yyvsp[0].sval));
;
    break;}
case 37:
#line 355 "pascal.y"
{
    // $$ = A_NameList(line_no, $1);
    yyval.name_list = A_NameList(line_no, S_Symbol(yyvsp[0].sval));
;
    break;}
case 38:
#line 361 "pascal.y"
{
    yyval.var_part = A_VarPart(line_no, yyvsp[0].var_decl_list);
;
    break;}
case 39:
#line 364 "pascal.y"
{
    yyval.var_part = A_VarPart(line_no, NULL);
;
    break;}
case 40:
#line 369 "pascal.y"
{
    yyval.var_decl_list = A_VarDeclListSeq(line_no, yyvsp[-1].var_decl_list, yyvsp[0].var_decl);
;
    break;}
case 41:
#line 372 "pascal.y"
{
    yyval.var_decl_list = A_VarDeclList(line_no, yyvsp[0].var_decl);
;
    break;}
case 42:
#line 377 "pascal.y"
{
    yyval.var_decl = A_VarDecl(line_no, yyvsp[-3].name_list, yyvsp[-1].type_decl);
;
    break;}
case 43:
#line 382 "pascal.y"
{
    yyval.routine_part = A_RoutinePartSeqWithFunctionDecl(line_no, yyvsp[-1].routine_part, yyvsp[0].function_decl);
;
    break;}
case 44:
#line 385 "pascal.y"
{
    yyval.routine_part = A_RoutinePartSeqWithProcedureDecl(line_no, yyvsp[-1].routine_part, yyvsp[0].procedure_decl);
;
    break;}
case 45:
#line 388 "pascal.y"
{
    yyval.routine_part = A_RoutinePartWithFunctionDecl(line_no, yyvsp[0].function_decl);
;
    break;}
case 46:
#line 391 "pascal.y"
{
    yyval.routine_part = A_RoutinePartWithProcedureDecl(line_no, yyvsp[0].procedure_decl);
;
    break;}
case 47:
#line 394 "pascal.y"
{
    yyval.routine_part = NULL;
;
    break;}
case 48:
#line 399 "pascal.y"
{
    yyval.function_decl = A_FunctionDecl(line_no, yyvsp[-3].function_head, yyvsp[-1].sub_routine);
;
    break;}
case 49:
#line 404 "pascal.y"
{
    yyval.function_head = A_FunctionHead(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-2].parameters, yyvsp[0].simple_type_decl);
;
    break;}
case 50:
#line 409 "pascal.y"
{
    yyval.procedure_decl = A_ProcedureDecl(line_no, yyvsp[-3].procedure_head, yyvsp[-1].sub_routine);
;
    break;}
case 51:
#line 414 "pascal.y"
{
    //$$ = A_ProcedureHead(line_no, $2, $3);
    yyval.procedure_head = A_ProcedureHead(line_no, S_Symbol(yyvsp[-1].sval), yyvsp[0].parameters);
;
    break;}
case 52:
#line 420 "pascal.y"
{
    yyval.parameters = A_Parameters(line_no, yyvsp[-1].para_decl_list);
;
    break;}
case 53:
#line 423 "pascal.y"
{
    yyval.parameters = NULL;
;
    break;}
case 54:
#line 428 "pascal.y"
{
    yyval.para_decl_list = A_ParaDeclListSeq(line_no, yyvsp[-2].para_decl_list, yyvsp[0].para_type_list);
;
    break;}
case 55:
#line 431 "pascal.y"
{
    yyval.para_decl_list = A_ParaDeclList(line_no, yyvsp[0].para_type_list);
;
    break;}
case 56:
#line 437 "pascal.y"
{
    yyval.para_type_list = A_ParaTypeListVar(line_no, yyvsp[-2].var_para_list, yyvsp[0].simple_type_decl);
;
    break;}
case 57:
#line 440 "pascal.y"
{
    yyval.para_type_list = A_ParaTypeListVal(line_no, yyvsp[-2].val_para_list, yyvsp[0].simple_type_decl);
;
    break;}
case 58:
#line 445 "pascal.y"
{
    yyval.var_para_list = A_VarParaList(line_no, yyvsp[0].name_list);
;
    break;}
case 59:
#line 450 "pascal.y"
{
    yyval.val_para_list = A_ValParaList(line_no, yyvsp[0].name_list);
;
    break;}
case 60:
#line 455 "pascal.y"
{
    yyval.routine_body = A_RoutineBody(line_no, yyvsp[0].compound_stmt);
;
    break;}
case 61:
#line 460 "pascal.y"
{
    yyval.compound_stmt = A_CompoundStmt(line_no, yyvsp[-1].stmt_list);
;
    break;}
case 62:
#line 465 "pascal.y"
{
    yyval.stmt_list = A_StmtList(line_no, yyvsp[-2].stmt_list, yyvsp[-1].stmt);
;
    break;}
case 63:
#line 468 "pascal.y"
{
    yyval.stmt_list = NULL;
;
    break;}
case 64:
#line 473 "pascal.y"
{
    yyval.stmt = A_StmtLabel(line_no, yyvsp[-2].ival, yyvsp[0].non_label_stmt);
;
    break;}
case 65:
#line 476 "pascal.y"
{
    yyval.stmt = A_StmtNonLabel(line_no, yyvsp[0].non_label_stmt);
;
    break;}
case 66:
#line 481 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtAssign(line_no, yyvsp[0].assign_stmt);
;
    break;}
case 67:
#line 484 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtProc(line_no, yyvsp[0].proc_stmt);
;
    break;}
case 68:
#line 487 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtCompound(line_no, yyvsp[0].compound_stmt);
;
    break;}
case 69:
#line 490 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtIf(line_no, yyvsp[0].if_stmt);
;
    break;}
case 70:
#line 493 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtRepeat(line_no, yyvsp[0].repeat_stmt);
;
    break;}
case 71:
#line 496 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtWhile(line_no, yyvsp[0].while_stmt);
;
    break;}
case 72:
#line 499 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtFor(line_no, yyvsp[0].for_stmt);
;
    break;}
case 73:
#line 502 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtCase(line_no, yyvsp[0].case_stmt);
;
    break;}
case 74:
#line 505 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtGoto(line_no, yyvsp[0].goto_stmt);
;
    break;}
case 75:
#line 510 "pascal.y"
{
    //$$ = A_AssignStmtSimple(line_no, $1, $3);
    yyval.assign_stmt = A_AssignStmtSimple(line_no, S_Symbol(yyvsp[-2].sval), yyvsp[0].expression);
;
    break;}
case 76:
#line 514 "pascal.y"
{
    //$$ = A_AssignStmtArray(line_no, $1, $3, $6);
    yyval.assign_stmt = A_AssignStmtArray(line_no, S_Symbol(yyvsp[-5].sval), yyvsp[-3].expression, yyvsp[0].expression);
;
    break;}
case 77:
#line 518 "pascal.y"
{
    //$$ = A_AssignStmtRecord(line_no, $1, $3, $5);
    yyval.assign_stmt = A_AssignStmtRecord(line_no, S_Symbol(yyvsp[-4].sval), S_Symbol(yyvsp[-2].sval), yyvsp[0].expression);
;
    break;}
case 78:
#line 524 "pascal.y"
{
    // $$ = A_ProcStmtID(line_no, $1);
    yyval.proc_stmt = A_ProcStmtID(line_no, S_Symbol(yyvsp[0].sval));
;
    break;}
case 79:
#line 528 "pascal.y"
{
    yyval.proc_stmt = A_ProcStmtIDWithArgs(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].args_list);
;
    break;}
case 80:
#line 531 "pascal.y"
{
    yyval.proc_stmt = A_ProcStmtSysProc(line_no, yyvsp[0].sys_proc);
;
    break;}
case 81:
#line 534 "pascal.y"
{
    yyval.proc_stmt = A_ProcStmtSysProcWithArgs(line_no, yyvsp[-3].sys_proc, yyvsp[-1].expression_list);
;
    break;}
case 82:
#line 537 "pascal.y"
{
    yyval.proc_stmt = A_ProcStmtRead(line_no, yyvsp[-1].factor);
;
    break;}
case 83:
#line 542 "pascal.y"
{
    yyval.if_stmt = A_IfStmt(line_no, yyvsp[-3].expression, yyvsp[-1].stmt, yyvsp[0].else_clause);
;
    break;}
case 84:
#line 547 "pascal.y"
{
    yyval.else_clause = A_ElseClause(line_no, yyvsp[0].stmt);
;
    break;}
case 85:
#line 549 "pascal.y"
{
    yyval.else_clause = A_ElseClause(line_no, NULL);
;
    break;}
case 86:
#line 555 "pascal.y"
{
    yyval.repeat_stmt = A_RepeatStmt(line_no, yyvsp[-2].stmt_list, yyvsp[0].expression);
;
    break;}
case 87:
#line 560 "pascal.y"
{
    yyval.while_stmt = A_WhileStmt(line_no, yyvsp[-2].expression, yyvsp[0].stmt);
;
    break;}
case 88:
#line 565 "pascal.y"
{
    yyval.for_stmt = A_ForStmt(line_no, S_Symbol(yyvsp[-6].sval), yyvsp[-4].expression, yyvsp[-3].direction, yyvsp[-2].expression, yyvsp[0].stmt);
;
    break;}
case 89:
#line 570 "pascal.y"
{
    yyval.direction = yyvsp[0].direction;
;
    break;}
case 90:
#line 573 "pascal.y"
{
    yyval.direction = yyvsp[0].direction;
;
    break;}
case 91:
#line 578 "pascal.y"
{
    yyval.case_stmt = A_CaseStmt(line_no, yyvsp[-3].expression, yyvsp[-1].case_expr_list);
;
    break;}
case 92:
#line 583 "pascal.y"
{
    yyval.case_expr_list = A_CaseExprListSeq(line_no, yyvsp[-1].case_expr_list, yyvsp[0].case_expr);
;
    break;}
case 93:
#line 586 "pascal.y"
{
    yyval.case_expr_list = A_CaseExprList(line_no, yyvsp[0].case_expr);
;
    break;}
case 94:
#line 591 "pascal.y"
{
    yyval.case_expr = A_CaseExprConst(line_no, yyvsp[-3].const_value, yyvsp[-1].stmt);
;
    break;}
case 95:
#line 594 "pascal.y"
{
    //$$ = A_CaseExprNonConst(line_no, $1, $3);
    yyval.case_expr = A_CaseExprNonConst(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].stmt);
;
    break;}
case 96:
#line 600 "pascal.y"
{
    yyval.goto_stmt = A_GotoStmt(line_no, yyvsp[0].ival);
;
    break;}
case 97:
#line 605 "pascal.y"
{
    yyval.expression_list = A_ExpressionListSeq(line_no, yyvsp[-2].expression_list, yyvsp[0].expression);
;
    break;}
case 98:
#line 608 "pascal.y"
{
    yyval.expression_list = A_ExpressionList(line_no, yyvsp[0].expression);
;
    break;}
case 99:
#line 613 "pascal.y"
{
    yyval.expression = A_ExpressionBin(line_no, yyvsp[-2].expression, GE, yyvsp[0].expr);
;
    break;}
case 100:
#line 616 "pascal.y"
{
    yyval.expression = A_ExpressionBin(line_no, yyvsp[-2].expression, GT, yyvsp[0].expr);
;
    break;}
case 101:
#line 619 "pascal.y"
{
    yyval.expression = A_ExpressionBin(line_no, yyvsp[-2].expression, LE, yyvsp[0].expr);
;
    break;}
case 102:
#line 622 "pascal.y"
{
    yyval.expression = A_ExpressionBin(line_no, yyvsp[-2].expression, LT, yyvsp[0].expr);
;
    break;}
case 103:
#line 625 "pascal.y"
{
    yyval.expression = A_ExpressionBin(line_no, yyvsp[-2].expression, EQUAL, yyvsp[0].expr);
;
    break;}
case 104:
#line 628 "pascal.y"
{
    yyval.expression = A_ExpressionBin(line_no, yyvsp[-2].expression, UNEQUAL, yyvsp[0].expr);
;
    break;}
case 105:
#line 631 "pascal.y"
{
    yyval.expression = A_ExpressionUn(line_no, yyvsp[0].expr);
;
    break;}
case 106:
#line 636 "pascal.y"
{
    yyval.expr = A_ExprBin(line_no, yyvsp[-2].expr, PLUS, yyvsp[0].term);
;
    break;}
case 107:
#line 639 "pascal.y"
{
    yyval.expr = A_ExprBin(line_no, yyvsp[-2].expr, MINUS, yyvsp[0].term);
;
    break;}
case 108:
#line 642 "pascal.y"
{
    yyval.expr = A_ExprBin(line_no, yyvsp[-2].expr, OR, yyvsp[0].term);
;
    break;}
case 109:
#line 645 "pascal.y"
{
    yyval.expr = A_ExprUn(line_no, yyvsp[0].term);
;
    break;}
case 110:
#line 650 "pascal.y"
{
    yyval.term = A_TermBin(line_no, yyvsp[-2].term, MUL, yyvsp[0].factor);
;
    break;}
case 111:
#line 653 "pascal.y"
{
    yyval.term = A_TermBin(line_no, yyvsp[-2].term, DIV, yyvsp[0].factor);
;
    break;}
case 112:
#line 656 "pascal.y"
{
    yyval.term = A_TermBin(line_no, yyvsp[-2].term, MOD, yyvsp[0].factor);
;
    break;}
case 113:
#line 659 "pascal.y"
{
    yyval.term = A_TermBin(line_no, yyvsp[-2].term, AND, yyvsp[0].factor);
;
    break;}
case 114:
#line 662 "pascal.y"
{
    yyval.term = A_TermUn(line_no, yyvsp[0].factor);
;
    break;}
case 115:
#line 667 "pascal.y"
{
    //$$ = A_FactorId(line_no, $1);
    yyval.factor = A_FactorId(line_no, S_Symbol(yyvsp[0].sval));
;
    break;}
case 116:
#line 671 "pascal.y"
{
    //$$ = A_FactorIdWithArgs(line_no, $1, $3);
    yyval.factor = A_FactorIdWithArgs(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].args_list);
;
    break;}
case 117:
#line 675 "pascal.y"
{
    yyval.factor = A_FactorSysFunct(line_no, yyvsp[0].sys_funct);
;
    break;}
case 118:
#line 678 "pascal.y"
{
    yyval.factor = A_FactorSysFunctWithArgs(line_no, yyvsp[-3].sys_funct, yyvsp[-1].args_list);
;
    break;}
case 119:
#line 681 "pascal.y"
{
    yyval.factor = A_FactorConst(line_no, yyvsp[0].const_value);
;
    break;}
case 120:
#line 684 "pascal.y"
{
    yyval.factor = A_FactorInBrackets(line_no, yyvsp[-1].expression);
;
    break;}
case 121:
#line 687 "pascal.y"
{
    yyval.factor = A_FactorUnOp(line_no, NOT, yyvsp[0].factor);
;
    break;}
case 122:
#line 690 "pascal.y"
{
    yyval.factor = A_FactorUnOp(line_no, NEG, yyvsp[0].factor);
;
    break;}
case 123:
#line 693 "pascal.y"
{
    //$$ = A_FactorArrayVar(line_no, $1, $3);
    yyval.factor = A_FactorArrayVar(line_no, S_Symbol(yyvsp[-3].sval), S_Symbol(yyvsp[-1].expression));
;
    break;}
case 124:
#line 697 "pascal.y"
{
    //$$ = A_FactorRecordVar(line_no, $1, $3);
    yyval.factor = A_FactorRecordVar(line_no, S_Symbol(yyvsp[-2].sval), S_Symbol(yyvsp[0].sval));
;
    break;}
case 125:
#line 703 "pascal.y"
{
    yyval.args_list = A_ArgsListSeq(line_no, yyvsp[-2].args_list, yyvsp[0].expression);
;
    break;}
case 126:
#line 706 "pascal.y"
{
    yyval.args_list = A_ArgsList(line_no, yyvsp[0].expression);
;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 442 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  for (x = 0; x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = 0; x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 712 "pascal.y"

   
void yyerror(const char *s)
{
	printf("%s | line: %d.\n", s, line_no);					//out error information
}