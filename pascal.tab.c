
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
#define	BEGINN	266
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
#define	PREC_SHIFT_ROUT_PROC	316
#define	PREC_SHIFT_ROUT_FUNC	317

#line 1 "pascal.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "absyn.h"
#include "util.h"
#include "symbol.h"

void yyerror(const char *s);
int yylex();

extern A_program root;
extern int line_no;



#line 20 "pascal.y"
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



#define	YYFINAL		333
#define	YYFLAG		-32768
#define	YYNTBASE	64

#define YYTRANSLATE(x) ((unsigned)(x) <= 317 ? yytranslate[x] : 119)

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
    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     4,     7,    11,    14,    17,    19,    22,    25,    31,
    32,    35,    36,    42,    47,    52,    56,    59,    61,    63,
    65,    67,    69,    72,    73,    76,    78,    83,    88,    90,
    92,    94,    96,    98,   102,   106,   111,   117,   121,   125,
   130,   136,   140,   147,   153,   157,   160,   162,   167,   171,
   173,   176,   177,   180,   182,   187,   192,   196,   199,   202,
   204,   206,   207,   212,   217,   222,   226,   229,   235,   240,
   245,   250,   254,   257,   261,   262,   266,   268,   272,   277,
   281,   285,   289,   293,   296,   298,   300,   304,   308,   309,
   313,   315,   317,   319,   321,   323,   325,   327,   329,   331,
   333,   337,   344,   350,   354,   361,   367,   369,   374,   376,
   381,   386,   392,   395,   396,   401,   406,   415,   424,   426,
   428,   434,   437,   439,   444,   449,   454,   459,   464,   469,
   472,   476,   478,   482,   486,   490,   494,   498,   502,   504,
   508,   512,   516,   518,   522,   526,   530,   534,   536,   538,
   543,   545,   550,   552,   556,   559,   562,   567,   571,   575
};

static const short yyrhs[] = {    65,
    66,    30,     0,    65,    66,     0,     8,     3,    32,     0,
     8,     3,     0,     8,    32,     0,     8,     0,    68,    96,
     0,    68,    96,     0,    69,    70,    73,    83,    86,     0,
     0,     9,    71,     0,     0,    71,     3,    42,    72,    32,
     0,     3,    42,    72,    32,     0,     3,    39,    72,    32,
     0,     3,    42,    32,     0,     3,    32,     0,     4,     0,
     5,     0,     6,     0,     7,     0,    60,     0,    17,    74,
     0,     0,    74,    75,     0,    75,     0,     3,    42,    76,
    32,     0,     3,    39,    76,    32,     0,    77,     0,    78,
     0,    79,     0,    57,     0,     3,     0,    37,    82,    38,
     0,    72,    31,    72,     0,    49,    72,    31,    72,     0,
    49,    72,    31,    49,    72,     0,     3,    31,     3,     0,
    72,    30,    72,     0,    49,    72,    30,    72,     0,    49,
    72,    30,    49,    72,     0,     3,    30,     3,     0,    10,
    35,    77,    36,    28,    76,     0,    10,    35,    77,    36,
    76,     0,    11,    80,    13,     0,    80,    81,     0,    81,
     0,    82,    33,    76,    32,     0,    82,    34,     3,     0,
     3,     0,    14,    84,     0,     0,    84,    85,     0,    85,
     0,    82,    33,    76,    32,     0,    82,    32,    76,    32,
     0,    82,    76,    32,     0,    86,    87,     0,    86,    89,
     0,    87,     0,    89,     0,     0,    88,    32,    67,    32,
     0,    88,    34,    67,    32,     0,    88,    33,    67,    32,
     0,    88,    67,    32,     0,    88,    67,     0,    15,     3,
    91,    33,    77,     0,    90,    32,    67,    32,     0,    90,
    34,    67,    32,     0,    90,    33,    67,    32,     0,    16,
     3,    91,     0,    16,    91,     0,    37,    92,    38,     0,
     0,    92,    32,    93,     0,    93,     0,    92,    33,    93,
     0,    90,    34,    67,    32,     0,    94,    33,    77,     0,
    95,    33,    77,     0,    94,    32,    77,     0,    95,    32,
    77,     0,    14,    82,     0,    82,     0,    97,     0,    12,
    98,    13,     0,    98,    99,    32,     0,     0,     4,    33,
   100,     0,   100,     0,   101,     0,   102,     0,    97,     0,
   103,     0,   105,     0,   106,     0,   107,     0,   109,     0,
   112,     0,     3,    39,   114,     0,     3,    35,   114,    36,
    39,   114,     0,     3,    30,     3,    39,   114,     0,     3,
    42,   114,     0,     3,    35,   114,    36,    42,   114,     0,
     3,    30,     3,    42,   114,     0,     3,     0,     3,    37,
   118,    38,     0,    59,     0,    59,    37,   113,    38,     0,
    18,    37,   117,    38,     0,    19,   114,    20,    99,   104,
     0,    21,    99,     0,     0,    22,    98,    23,   114,     0,
    24,   114,    25,    99,     0,    26,     3,    39,   114,   108,
   114,    25,    99,     0,    26,     3,    42,   114,   108,   114,
    25,    99,     0,    55,     0,    56,     0,    27,   114,    28,
   110,    13,     0,   110,   111,     0,   111,     0,    72,    33,
    99,    32,     0,     3,    33,    99,    32,     0,    72,    34,
    99,    32,     0,     3,    34,    99,    32,     0,    72,    32,
    99,    32,     0,     3,    32,    99,    32,     0,    29,     4,
     0,   113,    34,   114,     0,   114,     0,   114,    44,   115,
     0,   114,    45,   115,     0,   114,    46,   115,     0,   114,
    47,   115,     0,   114,    42,   115,     0,   114,    43,   115,
     0,   115,     0,   115,    48,   116,     0,   115,    49,   116,
     0,   115,    50,   116,     0,   116,     0,   116,    51,   117,
     0,   116,    52,   117,     0,   116,    53,   117,     0,   116,
    54,   117,     0,   117,     0,     3,     0,     3,    37,   118,
    38,     0,    58,     0,    58,    37,   118,    38,     0,    72,
     0,    37,   114,    38,     0,    40,   117,     0,    49,   117,
     0,     3,    35,   114,    36,     0,     3,    30,     3,     0,
   118,    34,   114,     0,   114,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   195,   199,   207,   210,   214,   218,   225,   230,   235,   240,
   245,   248,   253,   256,   259,   263,   267,   274,   277,   280,
   283,   286,   291,   294,   299,   302,   307,   310,   317,   320,
   323,   328,   331,   334,   337,   340,   350,   362,   365,   370,
   382,   396,   403,   406,   413,   418,   421,   426,   431,   434,
   439,   442,   447,   450,   455,   458,   463,   470,   473,   476,
   479,   482,   487,   490,   495,   500,   505,   512,   517,   520,
   525,   532,   535,   544,   547,   552,   555,   558,   563,   571,
   574,   577,   582,   589,   594,   599,   604,   609,   612,   617,
   620,   625,   628,   631,   634,   637,   640,   643,   646,   649,
   654,   657,   660,   663,   668,   673,   680,   683,   686,   689,
   692,   697,   702,   704,   710,   715,   720,   723,   730,   733,
   738,   743,   746,   751,   754,   757,   762,   767,   772,   779,
   784,   787,   792,   795,   798,   801,   804,   807,   810,   815,
   818,   821,   824,   829,   832,   835,   838,   841,   846,   849,
   852,   855,   858,   861,   864,   867,   870,   873,   878,   881
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","ID","INTEGER",
"REAL","CHAR","STRING","PROGRAM","CONST","ARRAY","RECORD","BEGINN","END","VAR",
"FUNCTION","PROCEDURE","TYPE","READ","IF","THEN","ELSE","REPEAT","UNTIL","WHILE",
"DO","FOR","CASE","OF","GOTO","DOT","DOTDOT","SEMI","COLON","COMMA","LB","RB",
"LP","RP","ASSIGN","NOT","NEG","EQUAL","UNEQUAL","GE","GT","LE","LT","PLUS",
"MINUS","OR","MUL","DIV","MOD","AND","TO","DOWNTO","SYS_TYPE","SYS_FUNCT","SYS_PROC",
"SYS_CON","LOWER_THAN_ELSE","PREC_SHIFT_ROUT_PROC","PREC_SHIFT_ROUT_FUNC","program",
"program_head","routine","sub_routine","routine_head","label_part","const_part",
"const_expr_list","const_value","type_part","type_decl_list","type_definition",
"type_decl","simple_type_decl","array_type_decl","record_type_decl","field_decl_list",
"field_decl","name_list","var_part","var_decl_list","var_decl","routine_part",
"function_decl","function_head","procedure_decl","procedure_head","parameters",
"para_decl_list","para_type_list","var_para_list","val_para_list","routine_body",
"compound_stmt","stmt_list","stmt","non_label_stmt","assign_stmt","proc_stmt",
"if_stmt","else_clause","repeat_stmt","while_stmt","for_stmt","direction","case_stmt",
"case_expr_list","case_expr","goto_stmt","expression_list","expression","expr",
"term","factor","args_list", NULL
};
#endif

static const short yyr1[] = {     0,
    64,    64,    65,    65,    65,    65,    66,    67,    68,    69,
    70,    70,    71,    71,    71,    71,    71,    72,    72,    72,
    72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
    76,    77,    77,    77,    77,    77,    77,    77,    77,    77,
    77,    77,    78,    78,    79,    80,    80,    81,    82,    82,
    83,    83,    84,    84,    85,    85,    85,    86,    86,    86,
    86,    86,    87,    87,    87,    87,    87,    88,    89,    89,
    89,    90,    90,    91,    91,    92,    92,    92,    92,    93,
    93,    93,    93,    94,    95,    96,    97,    98,    98,    99,
    99,   100,   100,   100,   100,   100,   100,   100,   100,   100,
   101,   101,   101,   101,   101,   101,   102,   102,   102,   102,
   102,   103,   104,   104,   105,   106,   107,   107,   108,   108,
   109,   110,   110,   111,   111,   111,   111,   111,   111,   112,
   113,   113,   114,   114,   114,   114,   114,   114,   114,   115,
   115,   115,   115,   116,   116,   116,   116,   116,   117,   117,
   117,   117,   117,   117,   117,   117,   117,   117,   118,   118
};

static const short yyr2[] = {     0,
     3,     2,     3,     2,     2,     1,     2,     2,     5,     0,
     2,     0,     5,     4,     4,     3,     2,     1,     1,     1,
     1,     1,     2,     0,     2,     1,     4,     4,     1,     1,
     1,     1,     1,     3,     3,     4,     5,     3,     3,     4,
     5,     3,     6,     5,     3,     2,     1,     4,     3,     1,
     2,     0,     2,     1,     4,     4,     3,     2,     2,     1,
     1,     0,     4,     4,     4,     3,     2,     5,     4,     4,
     4,     3,     2,     3,     0,     3,     1,     3,     4,     3,
     3,     3,     3,     2,     1,     1,     3,     3,     0,     3,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     3,     6,     5,     3,     6,     5,     1,     4,     1,     4,
     4,     5,     2,     0,     4,     4,     8,     8,     1,     1,
     5,     2,     1,     4,     4,     4,     4,     4,     4,     2,
     3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
     3,     3,     1,     3,     3,     3,     3,     1,     1,     4,
     1,     4,     1,     3,     2,     2,     4,     3,     3,     1
};

static const short yydefact[] = {     0,
     6,    10,     4,     5,     2,     0,    12,     3,     1,    89,
     7,    86,     0,    24,     0,     0,    11,     0,    52,   107,
     0,    87,     0,     0,    89,     0,     0,     0,     0,   109,
    94,     0,    91,    92,    93,    95,    96,    97,    98,    99,
   100,    17,     0,     0,     0,     0,    23,    26,     0,    62,
     0,     0,     0,     0,     0,     0,     0,   149,    18,    19,
    20,    21,     0,     0,     0,   151,    22,   153,     0,   139,
   143,   148,     0,     0,     0,     0,   130,     0,    88,     0,
    16,     0,     0,     0,     0,    25,    50,     0,    51,    54,
     0,    75,     9,    60,    10,    61,     0,     0,     0,   160,
     0,   101,   104,    90,     0,     0,     0,     0,     0,   155,
   156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   132,    15,    14,     0,    33,     0,     0,     0,
     0,    32,     0,     0,    29,    30,    31,     0,     0,     0,
     0,     0,    53,    75,    75,     0,    73,    58,    59,    10,
    10,    10,    67,     0,    10,    10,    10,     0,     0,     0,
     0,   108,   111,   158,     0,     0,   154,     0,   114,   137,
   138,   133,   134,   135,   136,   140,   141,   142,   144,   145,
   146,   147,   115,   116,     0,     0,     0,     0,     0,   123,
     0,   110,    13,     0,     0,     0,     0,    47,     0,     0,
     0,     0,     0,    28,    27,     0,     0,    49,    57,     0,
    72,     0,    85,     0,     0,    77,     0,     0,     0,     0,
     0,    66,     8,     0,     0,     0,   103,   106,     0,     0,
   159,   157,   150,   152,     0,   112,   119,   120,     0,     0,
     0,     0,     0,     0,     0,     0,   121,   122,   131,    42,
    38,     0,    45,    46,     0,    34,     0,     0,    39,    35,
    56,    55,     0,    84,    10,     0,     0,    74,     0,     0,
     0,     0,    63,    65,    64,    69,    71,    70,   102,   105,
   113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    40,     0,    36,    68,     0,    76,    78,    82,
    80,    83,    81,     0,     0,   129,   125,   127,   128,   124,
   126,     0,    44,    48,    41,    37,    79,   117,   118,    43,
     0,     0,     0
};

static const short yydefgoto[] = {   331,
     2,     5,   163,   164,     7,    14,    17,    68,    19,    47,
    48,   144,   145,   146,   147,   207,   208,   223,    50,    89,
    90,    93,    94,    95,    96,    97,   157,   225,   226,   227,
   228,    11,    31,    15,    32,    33,    34,    35,    36,   246,
    37,    38,    39,   249,    40,   199,   200,    41,   132,   100,
    70,    71,    72,   101
};

static const short yypact[] = {    -1,
     5,-32768,   -19,-32768,    35,    14,    38,-32768,-32768,-32768,
-32768,-32768,    67,    61,   268,    40,    86,   131,   127,   270,
    78,-32768,   115,   209,-32768,   209,   151,   209,   160,   129,
-32768,   143,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   133,    69,   150,   119,   131,-32768,   183,    93,
   200,   209,   209,   209,   209,   344,   209,    34,-32768,-32768,
-32768,-32768,   209,   209,   209,   182,-32768,-32768,   290,   -16,
   175,-32768,   299,   332,   120,   367,-32768,   209,-32768,   213,
-32768,   228,   133,   184,   184,-32768,-32768,   116,   183,-32768,
   265,     2,    93,-32768,    20,-32768,    63,   178,   379,   407,
    46,   407,   407,-32768,   232,   282,   209,   209,   401,-32768,
-32768,   209,   326,   209,   209,   209,   209,   209,   209,   209,
   209,   209,   209,   209,   209,   209,   209,   326,   209,   209,
    56,    49,   407,-32768,-32768,   261,    87,   266,   183,   183,
   133,-32768,   177,   272,-32768,-32768,-32768,   274,   184,   184,
   288,   283,-32768,   287,   287,    32,-32768,-32768,-32768,-32768,
-32768,-32768,   310,    14,-32768,-32768,-32768,   209,   209,   193,
   209,-32768,-32768,-32768,   391,    52,-32768,    90,   322,   -16,
   -16,   -16,   -16,   -16,   -16,   175,   175,   175,-32768,-32768,
-32768,-32768,   407,-32768,   154,   154,   222,   250,    17,-32768,
   209,-32768,-32768,   343,   346,   259,    25,-32768,   214,    97,
   220,   133,   133,-32768,-32768,   319,   327,-32768,-32768,   321,
-32768,   183,   330,   331,    18,-32768,   241,   256,   328,   329,
   335,-32768,-32768,   337,   349,   350,   407,   407,   209,   209,
   407,-32768,-32768,-32768,   326,-32768,-32768,-32768,   209,   209,
   326,   326,   326,   326,   326,   326,-32768,-32768,   407,-32768,
-32768,   348,-32768,-32768,   184,-32768,   108,   271,-32768,-32768,
-32768,-32768,   259,   330,-32768,    11,    11,-32768,   259,   259,
   259,   259,-32768,-32768,-32768,-32768,-32768,-32768,   407,   407,
-32768,   347,   355,   351,   354,   356,   364,   372,   373,   174,
   374,   133,-32768,   133,-32768,-32768,   375,-32768,-32768,-32768,
-32768,-32768,-32768,   326,   326,-32768,-32768,-32768,-32768,-32768,
-32768,   184,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   387,   408,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,  -150,   414,-32768,-32768,-32768,   -43,-32768,-32768,
   370,   -82,  -188,-32768,-32768,-32768,   211,   -40,-32768,-32768,
   339,-32768,   336,-32768,   338,   263,   144,-32768,    37,-32768,
-32768,   276,    -4,   395,  -109,   376,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   234,-32768,-32768,   242,-32768,-32768,     3,
   341,   219,   -21,    43
};


#define	YYLAST		460


static const short yytable[] = {    80,
    82,    12,   148,   179,   155,   152,     1,     3,    88,   229,
   230,   231,     8,    87,   234,   235,   236,   262,   194,   197,
    59,    60,    61,    62,   222,    10,    69,    87,    74,   257,
    76,   120,   121,   122,    87,   105,     4,   263,   156,   136,
   143,   143,   110,   111,   143,   222,    13,    92,    88,   276,
   277,   160,   161,   162,    99,   278,   102,   103,   197,    59,
    60,    61,    62,   106,     9,   109,   216,   217,   107,    16,
   108,    42,    59,    60,    61,    62,    67,    18,    43,   171,
   133,    44,   201,   172,   306,   171,   202,   198,    45,   243,
   310,   311,   312,   313,   165,   166,   167,   211,   209,   210,
    81,   189,   190,   191,   192,   143,   143,    91,    92,   175,
    56,    59,    60,    61,    62,    67,   204,   205,   137,    59,
    60,    61,    62,   171,   307,   138,   139,   244,    67,   193,
   151,   195,   196,    46,   266,   291,    59,    60,    61,    62,
    49,   294,   295,   296,   297,   298,   299,   149,   150,   151,
   176,    57,   140,    75,   178,   198,   302,    84,   129,    12,
    85,   130,   143,    77,   141,    78,   209,    67,   269,   270,
   237,   238,   142,   241,    79,    67,   137,    59,    60,    61,
    62,   274,   301,   138,   139,    87,   137,    59,    60,    61,
    62,    83,    67,   138,   139,   114,   115,   116,   117,   118,
   119,   322,    98,   259,   328,   329,   212,   213,   247,   248,
   140,    58,    59,    60,    61,    62,   168,   323,   112,   169,
   140,   143,   141,   303,   305,   123,   124,   125,   126,   143,
   142,   239,   141,    67,   240,   143,   143,   143,   143,   330,
   142,   289,   290,    67,   134,    63,   265,   151,    64,   267,
   268,   292,   293,   251,   252,   253,   143,    65,   325,   135,
   326,   137,    59,    60,    61,    62,    66,   154,    67,   173,
    20,    21,   279,   280,    59,    60,    61,    62,   143,    10,
    22,   254,   255,   256,   174,    23,    24,   281,   282,    25,
   218,    26,   203,    27,    28,   140,    29,   220,   221,    51,
   206,    20,    21,   214,    52,   215,    53,   141,    54,   113,
    10,    55,   308,   309,   219,   142,    23,    24,    67,   304,
    25,   127,    26,   156,    27,    28,    30,    29,    20,    21,
    67,   114,   115,   116,   117,   118,   119,    10,   186,   187,
   188,   232,   245,    23,    24,   260,    20,    25,   261,    26,
   271,    27,    28,   273,    29,    10,   128,    30,   272,   283,
   284,    23,    24,   151,   275,    25,   285,    26,   286,    27,
    28,   314,    29,   114,   115,   116,   117,   118,   119,   315,
   287,   288,   316,   300,    30,   317,   332,   318,   114,   115,
   116,   117,   118,   119,   131,   319,   114,   115,   116,   117,
   118,   119,    30,   320,   321,   324,   327,   333,   114,   115,
   116,   117,   118,   119,   170,     6,    86,   264,   224,    73,
   114,   115,   116,   117,   118,   119,   242,   153,   158,   250,
   159,   104,   114,   115,   116,   117,   118,   119,   177,   233,
   258,     0,   114,   115,   116,   117,   118,   119,   114,   115,
   116,   117,   118,   119,   180,   181,   182,   183,   184,   185
};

static const short yycheck[] = {    43,
    44,     6,    85,   113,     3,    88,     8,     3,    49,   160,
   161,   162,    32,     3,   165,   166,   167,   206,   128,     3,
     4,     5,     6,     7,    14,    12,    24,     3,    26,    13,
    28,    48,    49,    50,     3,    57,    32,    13,    37,    83,
    84,    85,    64,    65,    88,    14,     9,    16,    89,    32,
    33,    32,    33,    34,    52,    38,    54,    55,     3,     4,
     5,     6,     7,    30,    30,    63,   149,   150,    35,     3,
    37,    32,     4,     5,     6,     7,    60,    17,    39,    34,
    78,    42,    34,    38,   273,    34,    38,   131,     3,    38,
   279,   280,   281,   282,    32,    33,    34,   141,   139,   140,
    32,   123,   124,   125,   126,   149,   150,    15,    16,   107,
    33,     4,     5,     6,     7,    60,    30,    31,     3,     4,
     5,     6,     7,    34,   275,    10,    11,    38,    60,   127,
    34,   129,   130,     3,    38,   245,     4,     5,     6,     7,
    14,   251,   252,   253,   254,   255,   256,    32,    33,    34,
   108,    37,    37,     3,   112,   199,    49,    39,    39,   164,
    42,    42,   206,     4,    49,    37,   207,    60,   212,   213,
   168,   169,    57,   171,    32,    60,     3,     4,     5,     6,
     7,   222,   265,    10,    11,     3,     3,     4,     5,     6,
     7,    42,    60,    10,    11,    42,    43,    44,    45,    46,
    47,    28,     3,   201,   314,   315,    30,    31,    55,    56,
    37,     3,     4,     5,     6,     7,    39,   300,    37,    42,
    37,   265,    49,   267,   268,    51,    52,    53,    54,   273,
    57,    39,    49,    60,    42,   279,   280,   281,   282,   322,
    57,   239,   240,    60,    32,    37,    33,    34,    40,    30,
    31,   249,   250,    32,    33,    34,   300,    49,   302,    32,
   304,     3,     4,     5,     6,     7,    58,     3,    60,    38,
     3,     4,    32,    33,     4,     5,     6,     7,   322,    12,
    13,    32,    33,    34,     3,    18,    19,    32,    33,    22,
     3,    24,    32,    26,    27,    37,    29,   154,   155,    30,
    35,     3,     4,    32,    35,    32,    37,    49,    39,    20,
    12,    42,   276,   277,    32,    57,    18,    19,    60,    49,
    22,    23,    24,    37,    26,    27,    59,    29,     3,     4,
    60,    42,    43,    44,    45,    46,    47,    12,   120,   121,
   122,    32,    21,    18,    19,     3,     3,    22,     3,    24,
    32,    26,    27,    33,    29,    12,    25,    59,    32,    32,
    32,    18,    19,    34,    34,    22,    32,    24,    32,    26,
    27,    25,    29,    42,    43,    44,    45,    46,    47,    25,
    32,    32,    32,    36,    59,    32,     0,    32,    42,    43,
    44,    45,    46,    47,    28,    32,    42,    43,    44,    45,
    46,    47,    59,    32,    32,    32,    32,     0,    42,    43,
    44,    45,    46,    47,    36,     2,    47,   207,   156,    25,
    42,    43,    44,    45,    46,    47,    36,    89,    93,   196,
    93,    56,    42,    43,    44,    45,    46,    47,    38,   164,
   199,    -1,    42,    43,    44,    45,    46,    47,    42,    43,
    44,    45,    46,    47,   114,   115,   116,   117,   118,   119
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
#line 195 "pascal.y"
{
    yyval.program = A_Program(line_no, yyvsp[-2].program_head, yyvsp[-1].routine);
    root = yyval.program;
;
    break;}
case 2:
#line 199 "pascal.y"
{
    yyval.program = A_Program(line_no, yyvsp[-1].program_head, yyvsp[0].routine);
    root = yyval.program;
    /* 程序结尾少. */
    printf("[syntax error] line: %d, expect a \'.\' at the end of the program.\n", line_no);
;
    break;}
case 3:
#line 207 "pascal.y"
{
    yyval.program_head = A_ProgramHead(line_no, yyvsp[-1].sval);
;
    break;}
case 4:
#line 210 "pascal.y"
{
    yyval.program_head = A_ProgramHead(line_no, yyvsp[0].sval);
    /* 结尾少SEMI */
    printf("[syntax error] line: %d, expect a SEMI(\';\') at the end of the program head.\n", line_no);
;
    break;}
case 5:
#line 214 "pascal.y"
{
    yyval.program_head = A_ProgramHead(line_no, "unnamed");
    /* PROGRAM没ID */
    printf("[syntax error] line: %d, expect a program ID between PROGRAM and \';\'.\n", line_no);
;
    break;}
case 6:
#line 218 "pascal.y"
{
    yyval.program_head = A_ProgramHead(line_no, "unnamed");
    /* both above */
    printf("[syntax error] line: %d, expect a program ID and a SEMI(\';\') behind PROGRAM.\n", line_no);
;
    break;}
case 7:
#line 225 "pascal.y"
{
    yyval.routine = A_Routine(line_no, yyvsp[-1].routine_head, yyvsp[0].routine_body);
;
    break;}
case 8:
#line 230 "pascal.y"
{
    yyval.sub_routine = A_SubRoutine(line_no, yyvsp[-1].routine_head, yyvsp[0].routine_body);
;
    break;}
case 9:
#line 235 "pascal.y"
{
    yyval.routine_head = A_RoutineHead(line_no, yyvsp[-4].label_part, yyvsp[-3].const_part, yyvsp[-2].type_part, yyvsp[-1].var_part, yyvsp[0].routine_part);
;
    break;}
case 10:
#line 240 "pascal.y"
{
    yyval.label_part = A_LabelPart(line_no);
;
    break;}
case 11:
#line 245 "pascal.y"
{
    yyval.const_part = A_ConstPart(line_no, yyvsp[0].const_expr_list);
;
    break;}
case 12:
#line 248 "pascal.y"
{
    yyval.const_part = A_ConstPart(line_no, NULL);
;
    break;}
case 13:
#line 253 "pascal.y"
{
    yyval.const_expr_list = A_ConstExprListSeq(line_no, yyvsp[-4].const_expr_list, S_Symbol(yyvsp[-3].sval), yyvsp[-1].const_value);
;
    break;}
case 14:
#line 256 "pascal.y"
{
    yyval.const_expr_list = A_ConstExprList(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].const_value);
;
    break;}
case 15:
#line 259 "pascal.y"
{
    yyval.const_expr_list = A_ConstExprList(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].const_value);
    /* EQUAL写成ASSIGN */
    printf("[syntax error] line: %d, the ASSIGN(\':=\') should be EQUAL(\'=\').\n", line_no);
;
    break;}
case 16:
#line 263 "pascal.y"
{
    yyval.const_expr_list = A_ConstExprList(line_no, S_Symbol(yyvsp[-2].sval), A_ConstValueInteger(line_no, 0));
    /* 忘记写右值 */
    printf("[syntax error] line: %d, expect a const value between EQUAL(\'=\') and SEMI(\';\')\n", line_no);
;
    break;}
case 17:
#line 267 "pascal.y"
{
    yyval.const_expr_list = A_ConstExprList(line_no, S_Symbol(yyvsp[-1].sval), A_ConstValueInteger(line_no, 0));
    /* CONST量没赋初值 */
    printf("[syntax error] line: %d, expect initial assignment for the const value.\n", line_no);
;
    break;}
case 18:
#line 274 "pascal.y"
{
    yyval.const_value = A_ConstValueInteger(line_no, yyvsp[0].ival);
;
    break;}
case 19:
#line 277 "pascal.y"
{
    yyval.const_value = A_ConstValueReal(line_no, yyvsp[0].dval);
;
    break;}
case 20:
#line 280 "pascal.y"
{
    yyval.const_value = A_ConstValueChar(line_no, yyvsp[0].sval);
;
    break;}
case 21:
#line 283 "pascal.y"
{
    yyval.const_value = A_ConstValueString(line_no, yyvsp[0].sval);
;
    break;}
case 22:
#line 286 "pascal.y"
{
    yyval.const_value = A_ConstValueSysCon(line_no, yyvsp[0].sys_con);
;
    break;}
case 23:
#line 291 "pascal.y"
{
    yyval.type_part = A_TypePart(line_no, yyvsp[0].type_decl_list);
;
    break;}
case 24:
#line 294 "pascal.y"
{
    yyval.type_part = A_TypePart(line_no, NULL);
;
    break;}
case 25:
#line 299 "pascal.y"
{
    yyval.type_decl_list = A_TypeDeclListSeq(line_no, yyvsp[-1].type_decl_list, yyvsp[0].type_definition);
;
    break;}
case 26:
#line 302 "pascal.y"
{
    yyval.type_decl_list = A_TypeDeclList(line_no, yyvsp[0].type_definition);
;
    break;}
case 27:
#line 307 "pascal.y"
{
    yyval.type_definition = A_TypeDefinition(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].type_decl);
;
    break;}
case 28:
#line 310 "pascal.y"
{
    yyval.type_definition = A_TypeDefinition(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].type_decl);
    /* EQUAL写成ASSIGN */
    printf("[syntax error] line: %d, the ASSIGN(\':=\') should be EQUAL(\'=\').\n", line_no);
;
    break;}
case 29:
#line 317 "pascal.y"
{
    yyval.type_decl = A_TypeDeclSimple(line_no, yyvsp[0].simple_type_decl);
;
    break;}
case 30:
#line 320 "pascal.y"
{
    yyval.type_decl = A_TypeDeclArray(line_no, yyvsp[0].array_type_decl);
;
    break;}
case 31:
#line 323 "pascal.y"
{
    yyval.type_decl = A_TypeDeclRecord(line_no, yyvsp[0].record_type_decl);
;
    break;}
case 32:
#line 328 "pascal.y"
{
    yyval.simple_type_decl = A_SimpleTypeDeclSysType(line_no, yyvsp[0].sys_type);
;
    break;}
case 33:
#line 331 "pascal.y"
{
    yyval.simple_type_decl = A_SimpleTypeDeclId(line_no, S_Symbol(yyvsp[0].sval));
;
    break;}
case 34:
#line 334 "pascal.y"
{
    yyval.simple_type_decl = A_SimpleTypeDeclNameList(line_no, yyvsp[-1].name_list);
;
    break;}
case 35:
#line 337 "pascal.y"
{
    yyval.simple_type_decl = A_SimpleTypeDeclRangeConst(line_no, yyvsp[-2].const_value, yyvsp[0].const_value);
;
    break;}
case 36:
#line 340 "pascal.y"
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
case 37:
#line 350 "pascal.y"
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
case 38:
#line 362 "pascal.y"
{
    yyval.simple_type_decl = A_SimpleTypeDeclRangeId(line_no, S_Symbol(yyvsp[-2].sval), S_Symbol(yyvsp[0].sval));
;
    break;}
case 39:
#line 365 "pascal.y"
{
    yyval.simple_type_decl = A_SimpleTypeDeclRangeConst(line_no, yyvsp[-2].const_value, yyvsp[0].const_value);
    /* ..写错成. */
    printf("[syntax error] line: %d, DOT(\'.\') should be DOTDOT(\'..\').\n", line_no);
;
    break;}
case 40:
#line 370 "pascal.y"
{
    A_const_value from = NULL;
    if (yyvsp[-2].const_value->kind == INTEGER) {
        from = A_ConstValueInteger(line_no, -(yyvsp[-2].const_value->u.intt));
    }
    else if (yyvsp[-2].const_value->kind == REAL) {
        from = A_ConstValueReal(line_no, -(yyvsp[-2].const_value->u.real));
    }
    yyval.simple_type_decl = A_SimpleTypeDeclRangeConst(line_no, from, yyvsp[0].const_value);
    /* ..写错成. */
    printf("[syntax error] line: %d, DOT(\'.\') should be DOTDOT(\'..\').\n", line_no);
;
    break;}
case 41:
#line 382 "pascal.y"
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
    /* ..写错成. */
    printf("[syntax error] line: %d, DOT(\'.\') should be DOTDOT(\'..\').\n", line_no);
;
    break;}
case 42:
#line 396 "pascal.y"
{
    yyval.simple_type_decl = A_SimpleTypeDeclRangeId(line_no, S_Symbol(yyvsp[-2].sval), S_Symbol(yyvsp[0].sval));
    /* ..写错成. */
    printf("[syntax error] line: %d, DOT(\'.\') should be DOTDOT(\'..\').\n", line_no);
;
    break;}
case 43:
#line 403 "pascal.y"
{
    yyval.array_type_decl = A_ArrayTypeDecl(line_no, yyvsp[-3].simple_type_decl, yyvsp[0].type_decl);
;
    break;}
case 44:
#line 406 "pascal.y"
{
    yyval.array_type_decl = A_ArrayTypeDecl(line_no, yyvsp[-2].simple_type_decl, yyvsp[0].type_decl);
    /* 缺少OF */
    printf("[syntax error] line: %d, expect OF between RB(\')\') and type declaration.\n", line_no);
;
    break;}
case 45:
#line 413 "pascal.y"
{
    yyval.record_type_decl = A_RecordTypeDecl(line_no, yyvsp[-1].field_decl_list);
;
    break;}
case 46:
#line 418 "pascal.y"
{
    yyval.field_decl_list = A_FieldDeclListSeq(line_no, yyvsp[-1].field_decl_list, yyvsp[0].field_decl);
;
    break;}
case 47:
#line 421 "pascal.y"
{
    yyval.field_decl_list = A_FieldDeclList(line_no, yyvsp[0].field_decl);
;
    break;}
case 48:
#line 426 "pascal.y"
{
    yyval.field_decl = A_FieldDecl(line_no, yyvsp[-3].name_list, yyvsp[-1].type_decl);
;
    break;}
case 49:
#line 431 "pascal.y"
{
    yyval.name_list = A_NameListSeq(line_no, yyvsp[-2].name_list, S_Symbol(yyvsp[0].sval));
;
    break;}
case 50:
#line 434 "pascal.y"
{
    yyval.name_list = A_NameList(line_no, S_Symbol(yyvsp[0].sval));
;
    break;}
case 51:
#line 439 "pascal.y"
{
    yyval.var_part = A_VarPart(line_no, yyvsp[0].var_decl_list);
;
    break;}
case 52:
#line 442 "pascal.y"
{
    yyval.var_part = A_VarPart(line_no, NULL);
;
    break;}
case 53:
#line 447 "pascal.y"
{
    yyval.var_decl_list = A_VarDeclListSeq(line_no, yyvsp[-1].var_decl_list, yyvsp[0].var_decl);
;
    break;}
case 54:
#line 450 "pascal.y"
{
    yyval.var_decl_list = A_VarDeclList(line_no, yyvsp[0].var_decl);
;
    break;}
case 55:
#line 455 "pascal.y"
{
    yyval.var_decl = A_VarDecl(line_no, yyvsp[-3].name_list, yyvsp[-1].type_decl);
;
    break;}
case 56:
#line 458 "pascal.y"
{
    yyval.var_decl = A_VarDecl(line_no, yyvsp[-3].name_list, yyvsp[-1].type_decl);
    /* COLON写错成SEMI */
    printf("[syntax error] line: %d, SEMI(\';\') should be COLON(\':\').\n", line_no);
;
    break;}
case 57:
#line 463 "pascal.y"
{
    yyval.var_decl = A_VarDecl(line_no, yyvsp[-2].name_list, yyvsp[-1].type_decl);
    /* 少COLON */
    printf("[syntax error] line: %d, expect SEMI(\';\') between name list and type declaration.\n", line_no);
;
    break;}
case 58:
#line 470 "pascal.y"
{
    yyval.routine_part = A_RoutinePartSeqWithFunctionDecl(line_no, yyvsp[-1].routine_part, yyvsp[0].function_decl);
;
    break;}
case 59:
#line 473 "pascal.y"
{
    yyval.routine_part = A_RoutinePartSeqWithProcedureDecl(line_no, yyvsp[-1].routine_part, yyvsp[0].procedure_decl);
;
    break;}
case 60:
#line 476 "pascal.y"
{
    yyval.routine_part = A_RoutinePartWithFunctionDecl(line_no, yyvsp[0].function_decl);
;
    break;}
case 61:
#line 479 "pascal.y"
{
    yyval.routine_part = A_RoutinePartWithProcedureDecl(line_no, yyvsp[0].procedure_decl);
;
    break;}
case 62:
#line 482 "pascal.y"
{
    yyval.routine_part = NULL;
;
    break;}
case 63:
#line 487 "pascal.y"
{
    yyval.function_decl = A_FunctionDecl(line_no, yyvsp[-3].function_head, yyvsp[-1].sub_routine);
;
    break;}
case 64:
#line 490 "pascal.y"
{
    yyval.function_decl = A_FunctionDecl(line_no, yyvsp[-3].function_head, yyvsp[-1].sub_routine);
    /* SEMI写错成COMMA */
    printf("[syntax error] line: %d, COMMA(\',\') should be SEMI(\';\').\n", line_no);
;
    break;}
case 65:
#line 495 "pascal.y"
{
    yyval.function_decl = A_FunctionDecl(line_no, yyvsp[-3].function_head, yyvsp[-1].sub_routine);
    /* SEMI写错成COLON */
    printf("[syntax error] line: %d, COLON(\':\') should be SEMI(\';\').\n", line_no);
;
    break;}
case 66:
#line 500 "pascal.y"
{
    yyval.function_decl = A_FunctionDecl(line_no, yyvsp[-2].function_head, yyvsp[-1].sub_routine);
    /* 少SEMI 1 */
    printf("[syntax error] line: %d, expect SEMI(\';\') between function head and subroutine.\n", line_no);
;
    break;}
case 67:
#line 505 "pascal.y"
{
    yyval.function_decl = A_FunctionDecl(line_no, yyvsp[-1].function_head, yyvsp[0].sub_routine);
    /* 少SEMI 2 */
    printf("[syntax error] line: %d, expect SEMI(\';\') at the end of function declaration.\n", line_no);
;
    break;}
case 68:
#line 512 "pascal.y"
{
    yyval.function_head = A_FunctionHead(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-2].parameters, yyvsp[0].simple_type_decl);
;
    break;}
case 69:
#line 517 "pascal.y"
{
    yyval.procedure_decl = A_ProcedureDecl(line_no, yyvsp[-3].procedure_head, yyvsp[-1].sub_routine);
;
    break;}
case 70:
#line 520 "pascal.y"
{
    yyval.procedure_decl = A_ProcedureDecl(line_no, yyvsp[-3].procedure_head, yyvsp[-1].sub_routine);
    /* SEMI写错成COMMA */
    printf("[syntax error] line: %d, COMMA(\',\') should be SEMI(\';\').\n", line_no);
;
    break;}
case 71:
#line 525 "pascal.y"
{
    yyval.procedure_decl = A_ProcedureDecl(line_no, yyvsp[-3].procedure_head, yyvsp[-1].sub_routine);
    /* SEMI写错成COLON */
    printf("[syntax error] line: %d, COLON(\':\') should be SEMI(\';\').\n", line_no);
;
    break;}
case 72:
#line 532 "pascal.y"
{
    yyval.procedure_head = A_ProcedureHead(line_no, S_Symbol(yyvsp[-1].sval), yyvsp[0].parameters);
;
    break;}
case 73:
#line 535 "pascal.y"
{
    char id[40] = { 0 };
    sprintf(id, "unnamed_procedure_at_line_%d\0", line_no);
    yyval.procedure_head = A_ProcedureHead(line_no, S_Symbol(id), yyvsp[0].parameters);
    /* PROCEDURE少ID */
    printf("[syntax error] line: %d, expect procedure ID between PROCEDURE and parameters.\n", line_no);
;
    break;}
case 74:
#line 544 "pascal.y"
{
    yyval.parameters = A_Parameters(line_no, yyvsp[-1].para_decl_list);
;
    break;}
case 75:
#line 547 "pascal.y"
{
    yyval.parameters = NULL;
;
    break;}
case 76:
#line 552 "pascal.y"
{
    yyval.para_decl_list = A_ParaDeclListSeq(line_no, yyvsp[-2].para_decl_list, yyvsp[0].para_type_list);
;
    break;}
case 77:
#line 555 "pascal.y"
{
    yyval.para_decl_list = A_ParaDeclList(line_no, yyvsp[0].para_type_list);
;
    break;}
case 78:
#line 558 "pascal.y"
{
    yyval.para_decl_list = A_ParaDeclListSeq(line_no, yyvsp[-2].para_decl_list, yyvsp[0].para_type_list);
    /* SEMI写错成COLON */
    printf("[syntax error] line: %d, COLON(\':\') should be SEMI(\';\').\n", line_no);
;
    break;}
case 79:
#line 563 "pascal.y"
{
    yyval.para_decl_list = A_ParaDeclListSeq(line_no, yyvsp[-3].procedure_head, yyvsp[-1].sub_routine);
    /* SEMI写错成COLON */
    printf("[syntax error] line: %d, COMMA(\',\') should be SEMI(\';\').\n", line_no);
;
    break;}
case 80:
#line 571 "pascal.y"
{
    yyval.para_type_list = A_ParaTypeListVar(line_no, yyvsp[-2].var_para_list, yyvsp[0].simple_type_decl);
;
    break;}
case 81:
#line 574 "pascal.y"
{
    yyval.para_type_list = A_ParaTypeListVal(line_no, yyvsp[-2].val_para_list, yyvsp[0].simple_type_decl);
;
    break;}
case 82:
#line 577 "pascal.y"
{
    yyval.para_type_list = A_ParaTypeListVar(line_no, yyvsp[-2].var_para_list, yyvsp[0].simple_type_decl);
    /* COLON写错成SEMI */
    printf("[syntax error] line: %d, SEMI(\';\') should be COLON(\':\').\n", line_no);
;
    break;}
case 83:
#line 582 "pascal.y"
{
    yyval.para_type_list = A_ParaTypeListVal(line_no, yyvsp[-2].val_para_list, yyvsp[0].simple_type_decl);
    /* COLON写错成SEMI */
    printf("[syntax error] line: %d, SEMI(\';\') should be COLON(\':\').\n", line_no);
;
    break;}
case 84:
#line 589 "pascal.y"
{
    yyval.var_para_list = A_VarParaList(line_no, yyvsp[0].name_list);
;
    break;}
case 85:
#line 594 "pascal.y"
{
    yyval.val_para_list = A_ValParaList(line_no, yyvsp[0].name_list);
;
    break;}
case 86:
#line 599 "pascal.y"
{
    yyval.routine_body = A_RoutineBody(line_no, yyvsp[0].compound_stmt);
;
    break;}
case 87:
#line 604 "pascal.y"
{
    yyval.compound_stmt = A_CompoundStmt(line_no, yyvsp[-1].stmt_list);
;
    break;}
case 88:
#line 609 "pascal.y"
{
    yyval.stmt_list = A_StmtList(line_no, yyvsp[-2].stmt_list, yyvsp[-1].stmt);
;
    break;}
case 89:
#line 612 "pascal.y"
{
    yyval.stmt_list = NULL;
;
    break;}
case 90:
#line 617 "pascal.y"
{
    yyval.stmt = A_StmtLabel(line_no, yyvsp[-2].ival, yyvsp[0].non_label_stmt);
;
    break;}
case 91:
#line 620 "pascal.y"
{
    yyval.stmt = A_StmtNonLabel(line_no, yyvsp[0].non_label_stmt);
;
    break;}
case 92:
#line 625 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtAssign(line_no, yyvsp[0].assign_stmt);
;
    break;}
case 93:
#line 628 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtProc(line_no, yyvsp[0].proc_stmt);
;
    break;}
case 94:
#line 631 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtCompound(line_no, yyvsp[0].compound_stmt);
;
    break;}
case 95:
#line 634 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtIf(line_no, yyvsp[0].if_stmt);
;
    break;}
case 96:
#line 637 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtRepeat(line_no, yyvsp[0].repeat_stmt);
;
    break;}
case 97:
#line 640 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtWhile(line_no, yyvsp[0].while_stmt);
;
    break;}
case 98:
#line 643 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtFor(line_no, yyvsp[0].for_stmt);
;
    break;}
case 99:
#line 646 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtCase(line_no, yyvsp[0].case_stmt);
;
    break;}
case 100:
#line 649 "pascal.y"
{
    yyval.non_label_stmt = A_NonLabelStmtGoto(line_no, yyvsp[0].goto_stmt);
;
    break;}
case 101:
#line 654 "pascal.y"
{
    yyval.assign_stmt = A_AssignStmtSimple(line_no, S_Symbol(yyvsp[-2].sval), yyvsp[0].expression);
;
    break;}
case 102:
#line 657 "pascal.y"
{
    yyval.assign_stmt = A_AssignStmtArray(line_no, S_Symbol(yyvsp[-5].sval), yyvsp[-3].expression, yyvsp[0].expression);
;
    break;}
case 103:
#line 660 "pascal.y"
{
    yyval.assign_stmt = A_AssignStmtRecord(line_no, S_Symbol(yyvsp[-4].sval), S_Symbol(yyvsp[-2].sval), yyvsp[0].expression);
;
    break;}
case 104:
#line 663 "pascal.y"
{
    yyval.assign_stmt = A_AssignStmtSimple(line_no, S_Symbol(yyvsp[-2].sval), yyvsp[0].expression);
    /* ASSIGN写错成EQUAL */
    printf("[syntax error] line: %d, EQUAL(\'=\') should be ASSIGN(\':=\').\n", line_no);
;
    break;}
case 105:
#line 668 "pascal.y"
{
    yyval.assign_stmt = A_AssignStmtArray(line_no, S_Symbol(yyvsp[-5].sval), yyvsp[-3].expression, yyvsp[0].expression);
    /* ASSIGN写错成EQUAL */
    printf("[syntax error] line: %d, EQUAL(\'=\') should be ASSIGN(\':=\').\n", line_no);
;
    break;}
case 106:
#line 673 "pascal.y"
{
    yyval.assign_stmt = A_AssignStmtRecord(line_no, S_Symbol(yyvsp[-4].sval), S_Symbol(yyvsp[-2].sval), yyvsp[0].expression);
    /* ASSIGN写错成EQUAL */
    printf("[syntax error] line: %d, EQUAL(\'=\') should be ASSIGN(\':=\').\n", line_no);
;
    break;}
case 107:
#line 680 "pascal.y"
{
    yyval.proc_stmt = A_ProcStmtID(line_no, S_Symbol(yyvsp[0].sval));
;
    break;}
case 108:
#line 683 "pascal.y"
{
    yyval.proc_stmt = A_ProcStmtIDWithArgs(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].args_list);
;
    break;}
case 109:
#line 686 "pascal.y"
{
    yyval.proc_stmt = A_ProcStmtSysProc(line_no, yyvsp[0].sys_proc);
;
    break;}
case 110:
#line 689 "pascal.y"
{
    yyval.proc_stmt = A_ProcStmtSysProcWithArgs(line_no, yyvsp[-3].sys_proc, yyvsp[-1].expression_list);
;
    break;}
case 111:
#line 692 "pascal.y"
{
    yyval.proc_stmt = A_ProcStmtRead(line_no, yyvsp[-1].factor);
;
    break;}
case 112:
#line 697 "pascal.y"
{
    yyval.if_stmt = A_IfStmt(line_no, yyvsp[-3].expression, yyvsp[-1].stmt, yyvsp[0].else_clause);
;
    break;}
case 113:
#line 702 "pascal.y"
{
    yyval.else_clause = A_ElseClause(line_no, yyvsp[0].stmt);
;
    break;}
case 114:
#line 704 "pascal.y"
{
    yyval.else_clause = A_ElseClause(line_no, NULL);
;
    break;}
case 115:
#line 710 "pascal.y"
{
    yyval.repeat_stmt = A_RepeatStmt(line_no, yyvsp[-2].stmt_list, yyvsp[0].expression);
;
    break;}
case 116:
#line 715 "pascal.y"
{
    yyval.while_stmt = A_WhileStmt(line_no, yyvsp[-2].expression, yyvsp[0].stmt);
;
    break;}
case 117:
#line 720 "pascal.y"
{
    yyval.for_stmt = A_ForStmt(line_no, S_Symbol(yyvsp[-6].sval), yyvsp[-4].expression, yyvsp[-3].direction, yyvsp[-2].expression, yyvsp[0].stmt);
;
    break;}
case 118:
#line 723 "pascal.y"
{
    yyval.for_stmt = A_ForStmt(line_no, S_Symbol(yyvsp[-6].sval), yyvsp[-4].expression, yyvsp[-3].direction, yyvsp[-2].expression, yyvsp[0].stmt);
    /* ASSIGN写错成EQUAL */
    printf("[syntax error] line: %d, EQUAL(\'=\') should be ASSIGN(\':=\').\n", line_no);
;
    break;}
case 119:
#line 730 "pascal.y"
{
    yyval.direction = DIRECTION_TO;
;
    break;}
case 120:
#line 733 "pascal.y"
{
    yyval.direction = DIRECTION_DOWNTO;
;
    break;}
case 121:
#line 738 "pascal.y"
{
    yyval.case_stmt = A_CaseStmt(line_no, yyvsp[-3].expression, yyvsp[-1].case_expr_list);
;
    break;}
case 122:
#line 743 "pascal.y"
{
    yyval.case_expr_list = A_CaseExprListSeq(line_no, yyvsp[-1].case_expr_list, yyvsp[0].case_expr);
;
    break;}
case 123:
#line 746 "pascal.y"
{
    yyval.case_expr_list = A_CaseExprList(line_no, yyvsp[0].case_expr);
;
    break;}
case 124:
#line 751 "pascal.y"
{
    yyval.case_expr = A_CaseExprConst(line_no, yyvsp[-3].const_value, yyvsp[-1].stmt);
;
    break;}
case 125:
#line 754 "pascal.y"
{
    yyval.case_expr = A_CaseExprNonConst(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].stmt);
;
    break;}
case 126:
#line 757 "pascal.y"
{
    yyval.case_expr = A_CaseExprConst(line_no, yyvsp[-3].const_value, yyvsp[-1].stmt);
    /* COLON写错成COMMA */
    printf("[syntax error] line: %d, COMMA(\',\') should be COLON(\':\').\n", line_no);
;
    break;}
case 127:
#line 762 "pascal.y"
{
    yyval.case_expr = A_CaseExprNonConst(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].stmt);
    /* COLON写错成COMMA */
    printf("[syntax error] line: %d, COMMA(\',\') should be COLON(\':\').\n", line_no);
;
    break;}
case 128:
#line 767 "pascal.y"
{
    yyval.case_expr = A_CaseExprConst(line_no, yyvsp[-3].const_value, yyvsp[-1].stmt);
    /* COLON写错成SEMI */
    printf("[syntax error] line: %d, SEMI(\';\') should be COLON(\':\').\n", line_no);
;
    break;}
case 129:
#line 772 "pascal.y"
{
    yyval.case_expr = A_CaseExprNonConst(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].stmt);
    /* COLON写错成SEMI */
    printf("[syntax error] line: %d, SEMI(\';\') should be COLON(\':\').\n", line_no);
;
    break;}
case 130:
#line 779 "pascal.y"
{
    yyval.goto_stmt = A_GotoStmt(line_no, yyvsp[0].ival);
;
    break;}
case 131:
#line 784 "pascal.y"
{
    yyval.expression_list = A_ExpressionListSeq(line_no, yyvsp[-2].expression_list, yyvsp[0].expression);
;
    break;}
case 132:
#line 787 "pascal.y"
{
    yyval.expression_list = A_ExpressionList(line_no, yyvsp[0].expression);
;
    break;}
case 133:
#line 792 "pascal.y"
{
    yyval.expression = A_ExpressionBin(line_no, yyvsp[-2].expression, OP_GE, yyvsp[0].expr);
;
    break;}
case 134:
#line 795 "pascal.y"
{
    yyval.expression = A_ExpressionBin(line_no, yyvsp[-2].expression, OP_GT, yyvsp[0].expr);
;
    break;}
case 135:
#line 798 "pascal.y"
{
    yyval.expression = A_ExpressionBin(line_no, yyvsp[-2].expression, OP_LE, yyvsp[0].expr);
;
    break;}
case 136:
#line 801 "pascal.y"
{
    yyval.expression = A_ExpressionBin(line_no, yyvsp[-2].expression, OP_LT, yyvsp[0].expr);
;
    break;}
case 137:
#line 804 "pascal.y"
{
    yyval.expression = A_ExpressionBin(line_no, yyvsp[-2].expression, OP_EQUAL, yyvsp[0].expr);
;
    break;}
case 138:
#line 807 "pascal.y"
{
    yyval.expression = A_ExpressionBin(line_no, yyvsp[-2].expression, OP_UNEQUAL, yyvsp[0].expr);
;
    break;}
case 139:
#line 810 "pascal.y"
{
    yyval.expression = A_ExpressionUn(line_no, yyvsp[0].expr);
;
    break;}
case 140:
#line 815 "pascal.y"
{
    yyval.expr = A_ExprBin(line_no, yyvsp[-2].expr, OP_PLUS, yyvsp[0].term);
;
    break;}
case 141:
#line 818 "pascal.y"
{
    yyval.expr = A_ExprBin(line_no, yyvsp[-2].expr, OP_MINUS, yyvsp[0].term);
;
    break;}
case 142:
#line 821 "pascal.y"
{
    yyval.expr = A_ExprBin(line_no, yyvsp[-2].expr, OP_OR, yyvsp[0].term);
;
    break;}
case 143:
#line 824 "pascal.y"
{
    yyval.expr = A_ExprUn(line_no, yyvsp[0].term);
;
    break;}
case 144:
#line 829 "pascal.y"
{
    yyval.term = A_TermBin(line_no, yyvsp[-2].term, OP_MUL, yyvsp[0].factor);
;
    break;}
case 145:
#line 832 "pascal.y"
{
    yyval.term = A_TermBin(line_no, yyvsp[-2].term, OP_DIV, yyvsp[0].factor);
;
    break;}
case 146:
#line 835 "pascal.y"
{
    yyval.term = A_TermBin(line_no, yyvsp[-2].term, OP_MOD, yyvsp[0].factor);
;
    break;}
case 147:
#line 838 "pascal.y"
{
    yyval.term = A_TermBin(line_no, yyvsp[-2].term, OP_AND, yyvsp[0].factor);
;
    break;}
case 148:
#line 841 "pascal.y"
{
    yyval.term = A_TermUn(line_no, yyvsp[0].factor);
;
    break;}
case 149:
#line 846 "pascal.y"
{
    yyval.factor = A_FactorId(line_no, S_Symbol(yyvsp[0].sval));
;
    break;}
case 150:
#line 849 "pascal.y"
{
    yyval.factor = A_FactorIdWithArgs(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].args_list);
;
    break;}
case 151:
#line 852 "pascal.y"
{
    yyval.factor = A_FactorSysFunct(line_no, yyvsp[0].sys_funct);
;
    break;}
case 152:
#line 855 "pascal.y"
{
    yyval.factor = A_FactorSysFunctWithArgs(line_no, yyvsp[-3].sys_funct, yyvsp[-1].args_list);
;
    break;}
case 153:
#line 858 "pascal.y"
{
    yyval.factor = A_FactorConst(line_no, yyvsp[0].const_value);
;
    break;}
case 154:
#line 861 "pascal.y"
{
    yyval.factor = A_FactorInBrackets(line_no, yyvsp[-1].expression);
;
    break;}
case 155:
#line 864 "pascal.y"
{
    yyval.factor = A_FactorUnOp(line_no, OP_NOT, yyvsp[0].factor);
;
    break;}
case 156:
#line 867 "pascal.y"
{
    yyval.factor = A_FactorUnOp(line_no, OP_NEG, yyvsp[0].factor);
;
    break;}
case 157:
#line 870 "pascal.y"
{
    yyval.factor = A_FactorArrayVar(line_no, S_Symbol(yyvsp[-3].sval), yyvsp[-1].expression);
;
    break;}
case 158:
#line 873 "pascal.y"
{
    yyval.factor = A_FactorRecordVar(line_no, S_Symbol(yyvsp[-2].sval), S_Symbol(yyvsp[0].sval));
;
    break;}
case 159:
#line 878 "pascal.y"
{
    yyval.args_list = A_ArgsListSeq(line_no, yyvsp[-2].args_list, yyvsp[0].expression);
;
    break;}
case 160:
#line 881 "pascal.y"
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
#line 887 "pascal.y"

   
void yyerror(const char *s)
{
	printf("yyerror: %s | line: %d.\n", s, line_no);					//out error information
}