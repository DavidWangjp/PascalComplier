/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     INTEGER = 259,
     REAL = 260,
     CHAR = 261,
     STRING = 262,
     PROGRAM = 263,
     CONST = 264,
     ARRAY = 265,
     RECORD = 266,
     BEGINN = 267,
     END = 268,
     VAR = 269,
     FUNCTION = 270,
     PROCEDURE = 271,
     TYPE = 272,
     READ = 273,
     IF = 274,
     THEN = 275,
     ELSE = 276,
     REPEAT = 277,
     UNTIL = 278,
     WHILE = 279,
     DO = 280,
     FOR = 281,
     CASE = 282,
     OF = 283,
     GOTO = 284,
     DOT = 285,
     DOTDOT = 286,
     SEMI = 287,
     COLON = 288,
     COMMA = 289,
     LB = 290,
     RB = 291,
     LP = 292,
     RP = 293,
     ASSIGN = 294,
     NOT = 295,
     NEG = 296,
     EQUAL = 297,
     UNEQUAL = 298,
     GE = 299,
     GT = 300,
     LE = 301,
     LT = 302,
     PLUS = 303,
     MINUS = 304,
     OR = 305,
     MUL = 306,
     DIV = 307,
     MOD = 308,
     AND = 309,
     TO = 310,
     DOWNTO = 311,
     SYS_TYPE = 312,
     SYS_FUNCT = 313,
     SYS_PROC = 314,
     SYS_CON = 315,
     LOWER_THAN_ELSE = 316,
     PREC_SHIFT_ROUT_PROC = 317,
     PREC_SHIFT_ROUT_FUNC = 318
   };
#endif
/* Tokens.  */
#define ID 258
#define INTEGER 259
#define REAL 260
#define CHAR 261
#define STRING 262
#define PROGRAM 263
#define CONST 264
#define ARRAY 265
#define RECORD 266
#define BEGINN 267
#define END 268
#define VAR 269
#define FUNCTION 270
#define PROCEDURE 271
#define TYPE 272
#define READ 273
#define IF 274
#define THEN 275
#define ELSE 276
#define REPEAT 277
#define UNTIL 278
#define WHILE 279
#define DO 280
#define FOR 281
#define CASE 282
#define OF 283
#define GOTO 284
#define DOT 285
#define DOTDOT 286
#define SEMI 287
#define COLON 288
#define COMMA 289
#define LB 290
#define RB 291
#define LP 292
#define RP 293
#define ASSIGN 294
#define NOT 295
#define NEG 296
#define EQUAL 297
#define UNEQUAL 298
#define GE 299
#define GT 300
#define LE 301
#define LT 302
#define PLUS 303
#define MINUS 304
#define OR 305
#define MUL 306
#define DIV 307
#define MOD 308
#define AND 309
#define TO 310
#define DOWNTO 311
#define SYS_TYPE 312
#define SYS_FUNCT 313
#define SYS_PROC 314
#define SYS_CON 315
#define LOWER_THAN_ELSE 316
#define PREC_SHIFT_ROUT_PROC 317
#define PREC_SHIFT_ROUT_FUNC 318




/* Copy the first part of user declarations.  */
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




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "pascal.y"
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
}
/* Line 193 of yacc.c.  */
#line 320 "pascal.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 333 "pascal.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   460

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  161
/* YYNRULES -- Number of states.  */
#define YYNSTATES  333

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    10,    14,    17,    20,    22,    25,
      28,    34,    35,    38,    39,    45,    50,    55,    59,    62,
      64,    66,    68,    70,    72,    75,    76,    79,    81,    86,
      91,    93,    95,    97,    99,   101,   105,   109,   114,   120,
     124,   128,   133,   139,   143,   150,   156,   160,   163,   165,
     170,   174,   176,   179,   180,   183,   185,   190,   195,   199,
     202,   205,   207,   209,   210,   215,   220,   225,   229,   232,
     238,   243,   248,   253,   257,   260,   264,   265,   269,   271,
     275,   280,   284,   288,   292,   296,   299,   301,   303,   307,
     311,   312,   316,   318,   320,   322,   324,   326,   328,   330,
     332,   334,   336,   340,   347,   353,   357,   364,   370,   372,
     377,   379,   384,   389,   395,   398,   399,   404,   409,   418,
     427,   429,   431,   437,   440,   442,   447,   452,   457,   462,
     467,   472,   475,   479,   481,   485,   489,   493,   497,   501,
     505,   507,   511,   515,   519,   521,   525,   529,   533,   537,
     539,   541,   546,   548,   553,   555,   559,   562,   565,   570,
     574,   578
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      65,     0,    -1,    66,    67,    30,    -1,    66,    67,    -1,
       8,     3,    32,    -1,     8,     3,    -1,     8,    32,    -1,
       8,    -1,    69,    97,    -1,    69,    97,    -1,    70,    71,
      74,    84,    87,    -1,    -1,     9,    72,    -1,    -1,    72,
       3,    42,    73,    32,    -1,     3,    42,    73,    32,    -1,
       3,    39,    73,    32,    -1,     3,    42,    32,    -1,     3,
      32,    -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,
      60,    -1,    17,    75,    -1,    -1,    75,    76,    -1,    76,
      -1,     3,    42,    77,    32,    -1,     3,    39,    77,    32,
      -1,    78,    -1,    79,    -1,    80,    -1,    57,    -1,     3,
      -1,    37,    83,    38,    -1,    73,    31,    73,    -1,    49,
      73,    31,    73,    -1,    49,    73,    31,    49,    73,    -1,
       3,    31,     3,    -1,    73,    30,    73,    -1,    49,    73,
      30,    73,    -1,    49,    73,    30,    49,    73,    -1,     3,
      30,     3,    -1,    10,    35,    78,    36,    28,    77,    -1,
      10,    35,    78,    36,    77,    -1,    11,    81,    13,    -1,
      81,    82,    -1,    82,    -1,    83,    33,    77,    32,    -1,
      83,    34,     3,    -1,     3,    -1,    14,    85,    -1,    -1,
      85,    86,    -1,    86,    -1,    83,    33,    77,    32,    -1,
      83,    32,    77,    32,    -1,    83,    77,    32,    -1,    87,
      88,    -1,    87,    90,    -1,    88,    -1,    90,    -1,    -1,
      89,    32,    68,    32,    -1,    89,    34,    68,    32,    -1,
      89,    33,    68,    32,    -1,    89,    68,    32,    -1,    89,
      68,    -1,    15,     3,    92,    33,    78,    -1,    91,    32,
      68,    32,    -1,    91,    34,    68,    32,    -1,    91,    33,
      68,    32,    -1,    16,     3,    92,    -1,    16,    92,    -1,
      37,    93,    38,    -1,    -1,    93,    32,    94,    -1,    94,
      -1,    93,    33,    94,    -1,    91,    34,    68,    32,    -1,
      95,    33,    78,    -1,    96,    33,    78,    -1,    95,    32,
      78,    -1,    96,    32,    78,    -1,    14,    83,    -1,    83,
      -1,    98,    -1,    12,    99,    13,    -1,    99,   100,    32,
      -1,    -1,     4,    33,   101,    -1,   101,    -1,   102,    -1,
     103,    -1,    98,    -1,   104,    -1,   106,    -1,   107,    -1,
     108,    -1,   110,    -1,   113,    -1,     3,    39,   115,    -1,
       3,    35,   115,    36,    39,   115,    -1,     3,    30,     3,
      39,   115,    -1,     3,    42,   115,    -1,     3,    35,   115,
      36,    42,   115,    -1,     3,    30,     3,    42,   115,    -1,
       3,    -1,     3,    37,   119,    38,    -1,    59,    -1,    59,
      37,   114,    38,    -1,    18,    37,   118,    38,    -1,    19,
     115,    20,   100,   105,    -1,    21,   100,    -1,    -1,    22,
      99,    23,   115,    -1,    24,   115,    25,   100,    -1,    26,
       3,    39,   115,   109,   115,    25,   100,    -1,    26,     3,
      42,   115,   109,   115,    25,   100,    -1,    55,    -1,    56,
      -1,    27,   115,    28,   111,    13,    -1,   111,   112,    -1,
     112,    -1,    73,    33,   100,    32,    -1,     3,    33,   100,
      32,    -1,    73,    34,   100,    32,    -1,     3,    34,   100,
      32,    -1,    73,    32,   100,    32,    -1,     3,    32,   100,
      32,    -1,    29,     4,    -1,   114,    34,   115,    -1,   115,
      -1,   115,    44,   116,    -1,   115,    45,   116,    -1,   115,
      46,   116,    -1,   115,    47,   116,    -1,   115,    42,   116,
      -1,   115,    43,   116,    -1,   116,    -1,   116,    48,   117,
      -1,   116,    49,   117,    -1,   116,    50,   117,    -1,   117,
      -1,   117,    51,   118,    -1,   117,    52,   118,    -1,   117,
      53,   118,    -1,   117,    54,   118,    -1,   118,    -1,     3,
      -1,     3,    37,   119,    38,    -1,    58,    -1,    58,    37,
     119,    38,    -1,    73,    -1,    37,   115,    38,    -1,    40,
     118,    -1,    49,   118,    -1,     3,    35,   115,    36,    -1,
       3,    30,     3,    -1,   119,    34,   115,    -1,   115,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   195,   195,   199,   207,   210,   214,   218,   225,   230,
     235,   240,   245,   248,   253,   256,   259,   263,   267,   274,
     277,   280,   283,   286,   291,   294,   299,   302,   307,   310,
     317,   320,   323,   328,   331,   334,   337,   340,   350,   362,
     365,   370,   382,   396,   403,   406,   413,   418,   421,   426,
     431,   434,   439,   442,   447,   450,   455,   458,   463,   470,
     473,   476,   479,   482,   487,   490,   495,   500,   505,   512,
     517,   520,   525,   532,   535,   544,   547,   552,   555,   558,
     563,   571,   574,   577,   582,   589,   594,   599,   604,   609,
     612,   617,   620,   625,   628,   631,   634,   637,   640,   643,
     646,   649,   654,   657,   660,   663,   668,   673,   680,   683,
     686,   689,   692,   697,   702,   704,   710,   715,   720,   723,
     730,   733,   738,   743,   746,   751,   754,   757,   762,   767,
     772,   779,   784,   787,   792,   795,   798,   801,   804,   807,
     810,   815,   818,   821,   824,   829,   832,   835,   838,   841,
     846,   849,   852,   855,   858,   861,   864,   867,   870,   873,
     878,   881
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTEGER", "REAL", "CHAR",
  "STRING", "PROGRAM", "CONST", "ARRAY", "RECORD", "BEGINN", "END", "VAR",
  "FUNCTION", "PROCEDURE", "TYPE", "READ", "IF", "THEN", "ELSE", "REPEAT",
  "UNTIL", "WHILE", "DO", "FOR", "CASE", "OF", "GOTO", "DOT", "DOTDOT",
  "SEMI", "COLON", "COMMA", "LB", "RB", "LP", "RP", "ASSIGN", "NOT", "NEG",
  "EQUAL", "UNEQUAL", "GE", "GT", "LE", "LT", "PLUS", "MINUS", "OR", "MUL",
  "DIV", "MOD", "AND", "TO", "DOWNTO", "SYS_TYPE", "SYS_FUNCT", "SYS_PROC",
  "SYS_CON", "LOWER_THAN_ELSE", "PREC_SHIFT_ROUT_PROC",
  "PREC_SHIFT_ROUT_FUNC", "$accept", "program", "program_head", "routine",
  "sub_routine", "routine_head", "label_part", "const_part",
  "const_expr_list", "const_value", "type_part", "type_decl_list",
  "type_definition", "type_decl", "simple_type_decl", "array_type_decl",
  "record_type_decl", "field_decl_list", "field_decl", "name_list",
  "var_part", "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "routine_body", "compound_stmt", "stmt_list", "stmt", "non_label_stmt",
  "assign_stmt", "proc_stmt", "if_stmt", "else_clause", "repeat_stmt",
  "while_stmt", "for_stmt", "direction", "case_stmt", "case_expr_list",
  "case_expr", "goto_stmt", "expression_list", "expression", "expr",
  "term", "factor", "args_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    65,    66,    66,    66,    66,    67,    68,
      69,    70,    71,    71,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    79,    79,    80,    81,    81,    82,
      83,    83,    84,    84,    85,    85,    86,    86,    86,    87,
      87,    87,    87,    87,    88,    88,    88,    88,    88,    89,
      90,    90,    90,    91,    91,    92,    92,    93,    93,    93,
      93,    94,    94,    94,    94,    95,    96,    97,    98,    99,
      99,   100,   100,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   102,   102,   102,   102,   103,   103,
     103,   103,   103,   104,   105,   105,   106,   107,   108,   108,
     109,   109,   110,   111,   111,   112,   112,   112,   112,   112,
     112,   113,   114,   114,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   116,   116,   117,   117,   117,   117,   117,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     119,   119
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     3,     2,     2,     1,     2,     2,
       5,     0,     2,     0,     5,     4,     4,     3,     2,     1,
       1,     1,     1,     1,     2,     0,     2,     1,     4,     4,
       1,     1,     1,     1,     1,     3,     3,     4,     5,     3,
       3,     4,     5,     3,     6,     5,     3,     2,     1,     4,
       3,     1,     2,     0,     2,     1,     4,     4,     3,     2,
       2,     1,     1,     0,     4,     4,     4,     3,     2,     5,
       4,     4,     4,     3,     2,     3,     0,     3,     1,     3,
       4,     3,     3,     3,     3,     2,     1,     1,     3,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     6,     5,     3,     6,     5,     1,     4,
       1,     4,     4,     5,     2,     0,     4,     4,     8,     8,
       1,     1,     5,     2,     1,     4,     4,     4,     4,     4,
       4,     2,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       1,     4,     1,     4,     1,     3,     2,     2,     4,     3,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     0,    11,     5,     6,     1,     3,     0,    13,
       4,     2,    90,     8,    87,     0,    25,     0,     0,    12,
       0,    53,   108,     0,    88,     0,     0,    90,     0,     0,
       0,     0,   110,    95,     0,    92,    93,    94,    96,    97,
      98,    99,   100,   101,    18,     0,     0,     0,     0,    24,
      27,     0,    63,     0,     0,     0,     0,     0,     0,     0,
     150,    19,    20,    21,    22,     0,     0,     0,   152,    23,
     154,     0,   140,   144,   149,     0,     0,     0,     0,   131,
       0,    89,     0,    17,     0,     0,     0,     0,    26,    51,
       0,    52,    55,     0,    76,    10,    61,    11,    62,     0,
       0,     0,   161,     0,   102,   105,    91,     0,     0,     0,
       0,     0,   156,   157,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,    16,    15,     0,    34,
       0,     0,     0,     0,    33,     0,     0,    30,    31,    32,
       0,     0,     0,     0,     0,    54,    76,    76,     0,    74,
      59,    60,    11,    11,    11,    68,     0,    11,    11,    11,
       0,     0,     0,     0,   109,   112,   159,     0,     0,   155,
       0,   115,   138,   139,   134,   135,   136,   137,   141,   142,
     143,   145,   146,   147,   148,   116,   117,     0,     0,     0,
       0,     0,   124,     0,   111,    14,     0,     0,     0,     0,
      48,     0,     0,     0,     0,     0,    29,    28,     0,     0,
      50,    58,     0,    73,     0,    86,     0,     0,    78,     0,
       0,     0,     0,     0,    67,     9,     0,     0,     0,   104,
     107,     0,     0,   160,   158,   151,   153,     0,   113,   120,
     121,     0,     0,     0,     0,     0,     0,     0,     0,   122,
     123,   132,    43,    39,     0,    46,    47,     0,    35,     0,
       0,    40,    36,    57,    56,     0,    85,    11,     0,     0,
      75,     0,     0,     0,     0,    64,    66,    65,    70,    72,
      71,   103,   106,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,    37,    69,     0,
      77,    79,    83,    81,    84,    82,     0,     0,   130,   126,
     128,   129,   125,   127,     0,    45,    49,    42,    38,    80,
     118,   119,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,   165,   166,     9,    16,    19,    70,
      21,    49,    50,   146,   147,   148,   149,   209,   210,   225,
      52,    91,    92,    95,    96,    97,    98,    99,   159,   227,
     228,   229,   230,    13,    33,    17,    34,    35,    36,    37,
      38,   248,    39,    40,    41,   251,    42,   201,   202,    43,
     134,   102,    72,    73,    74,   103
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -191
static const yytype_int16 yypact[] =
{
      -1,     5,    13,  -191,    15,  -191,  -191,    -4,    53,    80,
    -191,  -191,  -191,  -191,  -191,    67,    94,   268,    40,    75,
     131,   127,   270,   121,  -191,   115,   209,  -191,   209,   161,
     209,   162,   138,  -191,   160,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,   133,    69,   144,   119,   131,
    -191,   200,    93,   216,   209,   209,   209,   209,   344,   209,
      34,  -191,  -191,  -191,  -191,   209,   209,   209,   208,  -191,
    -191,   290,   -16,   175,  -191,   299,   332,   120,   367,  -191,
     209,  -191,   228,  -191,   236,   133,   184,   184,  -191,  -191,
     116,   200,  -191,   267,     2,    93,  -191,    20,  -191,    63,
     178,   379,   407,    46,   407,   407,  -191,   247,   288,   209,
     209,   401,  -191,  -191,   209,   326,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     326,   209,   209,    56,    49,   407,  -191,  -191,   261,    87,
     266,   200,   200,   133,  -191,   177,   272,  -191,  -191,  -191,
     274,   184,   184,   321,   309,  -191,   305,   305,    32,  -191,
    -191,  -191,  -191,  -191,  -191,   311,    53,  -191,  -191,  -191,
     209,   209,   193,   209,  -191,  -191,  -191,   391,    52,  -191,
      90,   325,   -16,   -16,   -16,   -16,   -16,   -16,   175,   175,
     175,  -191,  -191,  -191,  -191,   407,  -191,   154,   154,   222,
     250,    17,  -191,   209,  -191,  -191,   346,   348,   259,    25,
    -191,   214,    97,   220,   133,   133,  -191,  -191,   322,   327,
    -191,  -191,   328,  -191,   200,   330,   331,    18,  -191,   241,
     256,   335,   337,   349,  -191,  -191,   350,   351,   352,   407,
     407,   209,   209,   407,  -191,  -191,  -191,   326,  -191,  -191,
    -191,   209,   209,   326,   326,   326,   326,   326,   326,  -191,
    -191,   407,  -191,  -191,   324,  -191,  -191,   184,  -191,   108,
     271,  -191,  -191,  -191,  -191,   259,   330,  -191,    11,    11,
    -191,   259,   259,   259,   259,  -191,  -191,  -191,  -191,  -191,
    -191,   407,   407,  -191,   347,   355,   354,   356,   364,   372,
     373,   374,   174,   375,   133,  -191,   133,  -191,  -191,   376,
    -191,  -191,  -191,  -191,  -191,  -191,   326,   326,  -191,  -191,
    -191,  -191,  -191,  -191,   184,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,  -191
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -191,  -191,  -191,  -191,  -152,   384,  -191,  -191,  -191,   -45,
    -191,  -191,   368,   -84,  -190,  -191,  -191,  -191,   207,   -42,
    -191,  -191,   329,  -191,   323,  -191,   333,   273,   142,  -191,
      61,  -191,  -191,   253,    -6,   402,  -111,   382,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,   232,  -191,  -191,   231,  -191,
    -191,     1,   339,   191,   -23,    41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      82,    84,    14,   150,   181,   157,   154,     1,     4,    90,
     231,   232,   233,     6,    89,   236,   237,   238,   264,   196,
     199,    61,    62,    63,    64,   224,    11,    71,    89,    76,
     259,    78,   122,   123,   124,    89,   107,     5,   265,   158,
     138,   145,   145,   112,   113,   145,   224,    10,    94,    90,
     278,   279,   162,   163,   164,   101,   280,   104,   105,   199,
      61,    62,    63,    64,   108,    12,   111,   218,   219,   109,
      18,   110,    44,    61,    62,    63,    64,    69,    47,    45,
     173,   135,    46,   203,   174,   308,   173,   204,   200,    15,
     245,   312,   313,   314,   315,   167,   168,   169,   213,   211,
     212,    83,   191,   192,   193,   194,   145,   145,    93,    94,
     177,    20,    61,    62,    63,    64,    69,   206,   207,   139,
      61,    62,    63,    64,   173,   309,   140,   141,   246,    69,
     195,   153,   197,   198,    48,   268,   293,    61,    62,    63,
      64,    51,   296,   297,   298,   299,   300,   301,   151,   152,
     153,   178,    59,   142,    58,   180,   200,   304,    86,   131,
      14,    87,   132,   145,    77,   143,    79,   211,    69,   271,
     272,   239,   240,   144,   243,    80,    69,   139,    61,    62,
      63,    64,   276,   303,   140,   141,    85,   139,    61,    62,
      63,    64,    81,    69,   140,   141,   116,   117,   118,   119,
     120,   121,   324,    89,   261,   330,   331,   214,   215,   249,
     250,   142,    60,    61,    62,    63,    64,   170,   325,   100,
     171,   142,   145,   143,   305,   307,   125,   126,   127,   128,
     145,   144,   241,   143,    69,   242,   145,   145,   145,   145,
     332,   144,   291,   292,    69,   114,    65,   267,   153,    66,
     269,   270,   294,   295,   253,   254,   255,   145,    67,   327,
     136,   328,   139,    61,    62,    63,    64,    68,   137,    69,
     156,    22,    23,   281,   282,    61,    62,    63,    64,   145,
      12,    24,   256,   257,   258,   175,    25,    26,   283,   284,
      27,   176,    28,   205,    29,    30,   142,    31,   222,   223,
      53,   208,    22,    23,   216,    54,   217,    55,   143,    56,
     115,    12,    57,   188,   189,   190,   144,    25,    26,    69,
     306,    27,   129,    28,   220,    29,    30,    32,    31,    22,
      23,    69,   116,   117,   118,   119,   120,   121,    12,   310,
     311,   221,   158,   234,    25,    26,   247,    22,    27,   262,
      28,   263,    29,    30,   273,    31,    12,   130,    32,   274,
     302,   275,    25,    26,   153,   277,    27,   285,    28,   286,
      29,    30,   316,    31,   116,   117,   118,   119,   120,   121,
     317,   287,   288,   289,   290,    32,   318,     8,   319,   116,
     117,   118,   119,   120,   121,   133,   320,   116,   117,   118,
     119,   120,   121,    32,   321,   322,   323,   326,   329,   116,
     117,   118,   119,   120,   121,   172,   266,    88,   160,   235,
     155,   116,   117,   118,   119,   120,   121,   244,   161,    75,
     252,   226,   260,   116,   117,   118,   119,   120,   121,   179,
     106,     0,     0,   116,   117,   118,   119,   120,   121,   116,
     117,   118,   119,   120,   121,   182,   183,   184,   185,   186,
     187
};

static const yytype_int16 yycheck[] =
{
      45,    46,     8,    87,   115,     3,    90,     8,     3,    51,
     162,   163,   164,     0,     3,   167,   168,   169,   208,   130,
       3,     4,     5,     6,     7,    14,    30,    26,     3,    28,
      13,    30,    48,    49,    50,     3,    59,    32,    13,    37,
      85,    86,    87,    66,    67,    90,    14,    32,    16,    91,
      32,    33,    32,    33,    34,    54,    38,    56,    57,     3,
       4,     5,     6,     7,    30,    12,    65,   151,   152,    35,
       3,    37,    32,     4,     5,     6,     7,    60,     3,    39,
      34,    80,    42,    34,    38,   275,    34,    38,   133,     9,
      38,   281,   282,   283,   284,    32,    33,    34,   143,   141,
     142,    32,   125,   126,   127,   128,   151,   152,    15,    16,
     109,    17,     4,     5,     6,     7,    60,    30,    31,     3,
       4,     5,     6,     7,    34,   277,    10,    11,    38,    60,
     129,    34,   131,   132,     3,    38,   247,     4,     5,     6,
       7,    14,   253,   254,   255,   256,   257,   258,    32,    33,
      34,   110,    37,    37,    33,   114,   201,    49,    39,    39,
     166,    42,    42,   208,     3,    49,     4,   209,    60,   214,
     215,   170,   171,    57,   173,    37,    60,     3,     4,     5,
       6,     7,   224,   267,    10,    11,    42,     3,     4,     5,
       6,     7,    32,    60,    10,    11,    42,    43,    44,    45,
      46,    47,    28,     3,   203,   316,   317,    30,    31,    55,
      56,    37,     3,     4,     5,     6,     7,    39,   302,     3,
      42,    37,   267,    49,   269,   270,    51,    52,    53,    54,
     275,    57,    39,    49,    60,    42,   281,   282,   283,   284,
     324,    57,   241,   242,    60,    37,    37,    33,    34,    40,
      30,    31,   251,   252,    32,    33,    34,   302,    49,   304,
      32,   306,     3,     4,     5,     6,     7,    58,    32,    60,
       3,     3,     4,    32,    33,     4,     5,     6,     7,   324,
      12,    13,    32,    33,    34,    38,    18,    19,    32,    33,
      22,     3,    24,    32,    26,    27,    37,    29,   156,   157,
      30,    35,     3,     4,    32,    35,    32,    37,    49,    39,
      20,    12,    42,   122,   123,   124,    57,    18,    19,    60,
      49,    22,    23,    24,     3,    26,    27,    59,    29,     3,
       4,    60,    42,    43,    44,    45,    46,    47,    12,   278,
     279,    32,    37,    32,    18,    19,    21,     3,    22,     3,
      24,     3,    26,    27,    32,    29,    12,    25,    59,    32,
      36,    33,    18,    19,    34,    34,    22,    32,    24,    32,
      26,    27,    25,    29,    42,    43,    44,    45,    46,    47,
      25,    32,    32,    32,    32,    59,    32,     3,    32,    42,
      43,    44,    45,    46,    47,    28,    32,    42,    43,    44,
      45,    46,    47,    59,    32,    32,    32,    32,    32,    42,
      43,    44,    45,    46,    47,    36,   209,    49,    95,   166,
      91,    42,    43,    44,    45,    46,    47,    36,    95,    27,
     198,   158,   201,    42,    43,    44,    45,    46,    47,    38,
      58,    -1,    -1,    42,    43,    44,    45,    46,    47,    42,
      43,    44,    45,    46,    47,   116,   117,   118,   119,   120,
     121
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    65,    66,     3,    32,     0,    67,    69,    70,
      32,    30,    12,    97,    98,     9,    71,    99,     3,    72,
      17,    74,     3,     4,    13,    18,    19,    22,    24,    26,
      27,    29,    59,    98,   100,   101,   102,   103,   104,   106,
     107,   108,   110,   113,    32,    39,    42,     3,     3,    75,
      76,    14,    84,    30,    35,    37,    39,    42,    33,    37,
       3,     4,     5,     6,     7,    37,    40,    49,    58,    60,
      73,   115,   116,   117,   118,    99,   115,     3,   115,     4,
      37,    32,    73,    32,    73,    42,    39,    42,    76,     3,
      83,    85,    86,    15,    16,    87,    88,    89,    90,    91,
       3,   115,   115,   119,   115,   115,   101,   118,    30,    35,
      37,   115,   118,   118,    37,    20,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    23,
      25,    39,    42,    28,   114,   115,    32,    32,    73,     3,
      10,    11,    37,    49,    57,    73,    77,    78,    79,    80,
      77,    32,    33,    34,    77,    86,     3,     3,    37,    92,
      88,    90,    32,    33,    34,    68,    69,    32,    33,    34,
      39,    42,    36,    34,    38,    38,     3,   115,   119,    38,
     119,   100,   116,   116,   116,   116,   116,   116,   117,   117,
     117,   118,   118,   118,   118,   115,   100,   115,   115,     3,
      73,   111,   112,    34,    38,    32,    30,    31,    35,    81,
      82,    83,    83,    73,    30,    31,    32,    32,    77,    77,
       3,    32,    92,    92,    14,    83,    91,    93,    94,    95,
      96,    68,    68,    68,    32,    97,    68,    68,    68,   115,
     115,    39,    42,   115,    36,    38,    38,    21,   105,    55,
      56,   109,   109,    32,    33,    34,    32,    33,    34,    13,
     112,   115,     3,     3,    78,    13,    82,    33,    38,    30,
      31,    73,    73,    32,    32,    33,    83,    34,    32,    33,
      38,    32,    33,    32,    33,    32,    32,    32,    32,    32,
      32,   115,   115,   100,   115,   115,   100,   100,   100,   100,
     100,   100,    36,    77,    49,    73,    49,    73,    78,    68,
      94,    94,    78,    78,    78,    78,    25,    25,    32,    32,
      32,    32,    32,    32,    28,    77,    32,    73,    73,    32,
     100,   100,    77
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 195 "pascal.y"
    {
    (yyval.program) = A_Program(line_no, (yyvsp[(1) - (3)].program_head), (yyvsp[(2) - (3)].routine));
    root = (yyval.program);
;}
    break;

  case 3:
#line 199 "pascal.y"
    {
    (yyval.program) = A_Program(line_no, (yyvsp[(1) - (2)].program_head), (yyvsp[(2) - (2)].routine));
    root = (yyval.program);
    /* 程序结尾少. */
    printf("[syntax error] line: %d, expect a \'.\' at the end of the program.\n", line_no);
;}
    break;

  case 4:
#line 207 "pascal.y"
    {
    (yyval.program_head) = A_ProgramHead(line_no, (yyvsp[(2) - (3)].sval));
;}
    break;

  case 5:
#line 210 "pascal.y"
    {
    (yyval.program_head) = A_ProgramHead(line_no, (yyvsp[(2) - (2)].sval));
    /* 结尾少SEMI */
    printf("[syntax error] line: %d, expect a SEMI(\';\') at the end of the program head.\n", line_no);
;}
    break;

  case 6:
#line 214 "pascal.y"
    {
    (yyval.program_head) = A_ProgramHead(line_no, "unnamed");
    /* PROGRAM没ID */
    printf("[syntax error] line: %d, expect a program ID between PROGRAM and \';\'.\n", line_no);
;}
    break;

  case 7:
#line 218 "pascal.y"
    {
    (yyval.program_head) = A_ProgramHead(line_no, "unnamed");
    /* both above */
    printf("[syntax error] line: %d, expect a program ID and a SEMI(\';\') behind PROGRAM.\n", line_no);
;}
    break;

  case 8:
#line 225 "pascal.y"
    {
    (yyval.routine) = A_Routine(line_no, (yyvsp[(1) - (2)].routine_head), (yyvsp[(2) - (2)].routine_body));
;}
    break;

  case 9:
#line 230 "pascal.y"
    {
    (yyval.sub_routine) = A_SubRoutine(line_no, (yyvsp[(1) - (2)].routine_head), (yyvsp[(2) - (2)].routine_body));
;}
    break;

  case 10:
#line 235 "pascal.y"
    {
    (yyval.routine_head) = A_RoutineHead(line_no, (yyvsp[(1) - (5)].label_part), (yyvsp[(2) - (5)].const_part), (yyvsp[(3) - (5)].type_part), (yyvsp[(4) - (5)].var_part), (yyvsp[(5) - (5)].routine_part));
;}
    break;

  case 11:
#line 240 "pascal.y"
    {
    (yyval.label_part) = A_LabelPart(line_no);
;}
    break;

  case 12:
#line 245 "pascal.y"
    {
    (yyval.const_part) = A_ConstPart(line_no, (yyvsp[(2) - (2)].const_expr_list));
;}
    break;

  case 13:
#line 248 "pascal.y"
    {
    (yyval.const_part) = A_ConstPart(line_no, NULL);
;}
    break;

  case 14:
#line 253 "pascal.y"
    {
    (yyval.const_expr_list) = A_ConstExprListSeq(line_no, (yyvsp[(1) - (5)].const_expr_list), S_Symbol((yyvsp[(2) - (5)].sval)), (yyvsp[(4) - (5)].const_value));
;}
    break;

  case 15:
#line 256 "pascal.y"
    {
    (yyval.const_expr_list) = A_ConstExprList(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].const_value));
;}
    break;

  case 16:
#line 259 "pascal.y"
    {
    (yyval.const_expr_list) = A_ConstExprList(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].const_value));
    /* EQUAL写成ASSIGN */
    printf("[syntax error] line: %d, the ASSIGN(\':=\') should be EQUAL(\'=\').\n", line_no);
;}
    break;

  case 17:
#line 263 "pascal.y"
    {
    (yyval.const_expr_list) = A_ConstExprList(line_no, S_Symbol((yyvsp[(1) - (3)].sval)), A_ConstValueInteger(line_no, 0));
    /* 忘记写右值 */
    printf("[syntax error] line: %d, expect a const value between EQUAL(\'=\') and SEMI(\';\')\n", line_no);
;}
    break;

  case 18:
#line 267 "pascal.y"
    {
    (yyval.const_expr_list) = A_ConstExprList(line_no, S_Symbol((yyvsp[(1) - (2)].sval)), A_ConstValueInteger(line_no, 0));
    /* CONST量没赋初值 */
    printf("[syntax error] line: %d, expect initial assignment for the const value.\n", line_no);
;}
    break;

  case 19:
#line 274 "pascal.y"
    {
    (yyval.const_value) = A_ConstValueInteger(line_no, (yyvsp[(1) - (1)].ival));
;}
    break;

  case 20:
#line 277 "pascal.y"
    {
    (yyval.const_value) = A_ConstValueReal(line_no, (yyvsp[(1) - (1)].dval));
;}
    break;

  case 21:
#line 280 "pascal.y"
    {
    (yyval.const_value) = A_ConstValueChar(line_no, (yyvsp[(1) - (1)].sval));
;}
    break;

  case 22:
#line 283 "pascal.y"
    {
    (yyval.const_value) = A_ConstValueString(line_no, (yyvsp[(1) - (1)].sval));
;}
    break;

  case 23:
#line 286 "pascal.y"
    {
    (yyval.const_value) = A_ConstValueSysCon(line_no, (yyvsp[(1) - (1)].sys_con));
;}
    break;

  case 24:
#line 291 "pascal.y"
    {
    (yyval.type_part) = A_TypePart(line_no, (yyvsp[(2) - (2)].type_decl_list));
;}
    break;

  case 25:
#line 294 "pascal.y"
    {
    (yyval.type_part) = A_TypePart(line_no, NULL);
;}
    break;

  case 26:
#line 299 "pascal.y"
    {
    (yyval.type_decl_list) = A_TypeDeclListSeq(line_no, (yyvsp[(1) - (2)].type_decl_list), (yyvsp[(2) - (2)].type_definition));
;}
    break;

  case 27:
#line 302 "pascal.y"
    {
    (yyval.type_decl_list) = A_TypeDeclList(line_no, (yyvsp[(1) - (1)].type_definition));
;}
    break;

  case 28:
#line 307 "pascal.y"
    {
    (yyval.type_definition) = A_TypeDefinition(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].type_decl));
;}
    break;

  case 29:
#line 310 "pascal.y"
    {
    (yyval.type_definition) = A_TypeDefinition(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].type_decl));
    /* EQUAL写成ASSIGN */
    printf("[syntax error] line: %d, the ASSIGN(\':=\') should be EQUAL(\'=\').\n", line_no);
;}
    break;

  case 30:
#line 317 "pascal.y"
    {
    (yyval.type_decl) = A_TypeDeclSimple(line_no, (yyvsp[(1) - (1)].simple_type_decl));
;}
    break;

  case 31:
#line 320 "pascal.y"
    {
    (yyval.type_decl) = A_TypeDeclArray(line_no, (yyvsp[(1) - (1)].array_type_decl));
;}
    break;

  case 32:
#line 323 "pascal.y"
    {
    (yyval.type_decl) = A_TypeDeclRecord(line_no, (yyvsp[(1) - (1)].record_type_decl));
;}
    break;

  case 33:
#line 328 "pascal.y"
    {
    (yyval.simple_type_decl) = A_SimpleTypeDeclSysType(line_no, (yyvsp[(1) - (1)].sys_type));
;}
    break;

  case 34:
#line 331 "pascal.y"
    {
    (yyval.simple_type_decl) = A_SimpleTypeDeclId(line_no, S_Symbol((yyvsp[(1) - (1)].sval)));
;}
    break;

  case 35:
#line 334 "pascal.y"
    {
    (yyval.simple_type_decl) = A_SimpleTypeDeclNameList(line_no, (yyvsp[(2) - (3)].name_list));
;}
    break;

  case 36:
#line 337 "pascal.y"
    {
    (yyval.simple_type_decl) = A_SimpleTypeDeclRangeConst(line_no, (yyvsp[(1) - (3)].const_value), (yyvsp[(3) - (3)].const_value));
;}
    break;

  case 37:
#line 340 "pascal.y"
    {
    A_const_value from = NULL;
    if ((yyvsp[(2) - (4)].const_value)->kind == INTEGER) {
        from = A_ConstValueInteger(line_no, -((yyvsp[(2) - (4)].const_value)->u.intt));
    }
    else if ((yyvsp[(2) - (4)].const_value)->kind == REAL) {
        from = A_ConstValueReal(line_no, -((yyvsp[(2) - (4)].const_value)->u.real));
    }
    (yyval.simple_type_decl) = A_SimpleTypeDeclRangeConst(line_no, from, (yyvsp[(4) - (4)].const_value));
;}
    break;

  case 38:
#line 350 "pascal.y"
    {
    A_const_value from = NULL, to = NULL;
    if ((yyvsp[(2) - (5)].const_value)->kind == INTEGER) {
        from = A_ConstValueInteger(line_no, -((yyvsp[(2) - (5)].const_value)->u.intt));
        to = A_ConstValueInteger(line_no, -((yyvsp[(2) - (5)].const_value)->u.intt));
    }
    else if ((yyvsp[(2) - (5)].const_value)->kind == REAL) {
        from = A_ConstValueReal(line_no, -((yyvsp[(5) - (5)].const_value)->u.real));
        to = A_ConstValueReal(line_no, -((yyvsp[(5) - (5)].const_value)->u.real));
    }
    (yyval.simple_type_decl) = A_SimpleTypeDeclRangeConst(line_no, from, to);
;}
    break;

  case 39:
#line 362 "pascal.y"
    {
    (yyval.simple_type_decl) = A_SimpleTypeDeclRangeId(line_no, S_Symbol((yyvsp[(1) - (3)].sval)), S_Symbol((yyvsp[(3) - (3)].sval)));
;}
    break;

  case 40:
#line 365 "pascal.y"
    {
    (yyval.simple_type_decl) = A_SimpleTypeDeclRangeConst(line_no, (yyvsp[(1) - (3)].const_value), (yyvsp[(3) - (3)].const_value));
    /* ..写错成. */
    printf("[syntax error] line: %d, DOT(\'.\') should be DOTDOT(\'..\').\n", line_no);
;}
    break;

  case 41:
#line 370 "pascal.y"
    {
    A_const_value from = NULL;
    if ((yyvsp[(2) - (4)].const_value)->kind == INTEGER) {
        from = A_ConstValueInteger(line_no, -((yyvsp[(2) - (4)].const_value)->u.intt));
    }
    else if ((yyvsp[(2) - (4)].const_value)->kind == REAL) {
        from = A_ConstValueReal(line_no, -((yyvsp[(2) - (4)].const_value)->u.real));
    }
    (yyval.simple_type_decl) = A_SimpleTypeDeclRangeConst(line_no, from, (yyvsp[(4) - (4)].const_value));
    /* ..写错成. */
    printf("[syntax error] line: %d, DOT(\'.\') should be DOTDOT(\'..\').\n", line_no);
;}
    break;

  case 42:
#line 382 "pascal.y"
    {
    A_const_value from = NULL, to = NULL;
    if ((yyvsp[(2) - (5)].const_value)->kind == INTEGER) {
        from = A_ConstValueInteger(line_no, -((yyvsp[(2) - (5)].const_value)->u.intt));
        to = A_ConstValueInteger(line_no, -((yyvsp[(2) - (5)].const_value)->u.intt));
    }
    else if ((yyvsp[(2) - (5)].const_value)->kind == REAL) {
        from = A_ConstValueReal(line_no, -((yyvsp[(5) - (5)].const_value)->u.real));
        to = A_ConstValueReal(line_no, -((yyvsp[(5) - (5)].const_value)->u.real));
    }
    (yyval.simple_type_decl) = A_SimpleTypeDeclRangeConst(line_no, from, to);
    /* ..写错成. */
    printf("[syntax error] line: %d, DOT(\'.\') should be DOTDOT(\'..\').\n", line_no);
;}
    break;

  case 43:
#line 396 "pascal.y"
    {
    (yyval.simple_type_decl) = A_SimpleTypeDeclRangeId(line_no, S_Symbol((yyvsp[(1) - (3)].sval)), S_Symbol((yyvsp[(3) - (3)].sval)));
    /* ..写错成. */
    printf("[syntax error] line: %d, DOT(\'.\') should be DOTDOT(\'..\').\n", line_no);
;}
    break;

  case 44:
#line 403 "pascal.y"
    {
    (yyval.array_type_decl) = A_ArrayTypeDecl(line_no, (yyvsp[(3) - (6)].simple_type_decl), (yyvsp[(6) - (6)].type_decl));
;}
    break;

  case 45:
#line 406 "pascal.y"
    {
    (yyval.array_type_decl) = A_ArrayTypeDecl(line_no, (yyvsp[(3) - (5)].simple_type_decl), (yyvsp[(5) - (5)].type_decl));
    /* 缺少OF */
    printf("[syntax error] line: %d, expect OF between RB(\')\') and type declaration.\n", line_no);
;}
    break;

  case 46:
#line 413 "pascal.y"
    {
    (yyval.record_type_decl) = A_RecordTypeDecl(line_no, (yyvsp[(2) - (3)].field_decl_list));
;}
    break;

  case 47:
#line 418 "pascal.y"
    {
    (yyval.field_decl_list) = A_FieldDeclListSeq(line_no, (yyvsp[(1) - (2)].field_decl_list), (yyvsp[(2) - (2)].field_decl));
;}
    break;

  case 48:
#line 421 "pascal.y"
    {
    (yyval.field_decl_list) = A_FieldDeclList(line_no, (yyvsp[(1) - (1)].field_decl));
;}
    break;

  case 49:
#line 426 "pascal.y"
    {
    (yyval.field_decl) = A_FieldDecl(line_no, (yyvsp[(1) - (4)].name_list), (yyvsp[(3) - (4)].type_decl));
;}
    break;

  case 50:
#line 431 "pascal.y"
    {
    (yyval.name_list) = A_NameListSeq(line_no, (yyvsp[(1) - (3)].name_list), S_Symbol((yyvsp[(3) - (3)].sval)));
;}
    break;

  case 51:
#line 434 "pascal.y"
    {
    (yyval.name_list) = A_NameList(line_no, S_Symbol((yyvsp[(1) - (1)].sval)));
;}
    break;

  case 52:
#line 439 "pascal.y"
    {
    (yyval.var_part) = A_VarPart(line_no, (yyvsp[(2) - (2)].var_decl_list));
;}
    break;

  case 53:
#line 442 "pascal.y"
    {
    (yyval.var_part) = A_VarPart(line_no, NULL);
;}
    break;

  case 54:
#line 447 "pascal.y"
    {
    (yyval.var_decl_list) = A_VarDeclListSeq(line_no, (yyvsp[(1) - (2)].var_decl_list), (yyvsp[(2) - (2)].var_decl));
;}
    break;

  case 55:
#line 450 "pascal.y"
    {
    (yyval.var_decl_list) = A_VarDeclList(line_no, (yyvsp[(1) - (1)].var_decl));
;}
    break;

  case 56:
#line 455 "pascal.y"
    {
    (yyval.var_decl) = A_VarDecl(line_no, (yyvsp[(1) - (4)].name_list), (yyvsp[(3) - (4)].type_decl));
;}
    break;

  case 57:
#line 458 "pascal.y"
    {
    (yyval.var_decl) = A_VarDecl(line_no, (yyvsp[(1) - (4)].name_list), (yyvsp[(3) - (4)].type_decl));
    /* COLON写错成SEMI */
    printf("[syntax error] line: %d, SEMI(\';\') should be COLON(\':\').\n", line_no);
;}
    break;

  case 58:
#line 463 "pascal.y"
    {
    (yyval.var_decl) = A_VarDecl(line_no, (yyvsp[(1) - (3)].name_list), (yyvsp[(2) - (3)].type_decl));
    /* 少COLON */
    printf("[syntax error] line: %d, expect SEMI(\';\') between name list and type declaration.\n", line_no);
;}
    break;

  case 59:
#line 470 "pascal.y"
    {
    (yyval.routine_part) = A_RoutinePartSeqWithFunctionDecl(line_no, (yyvsp[(1) - (2)].routine_part), (yyvsp[(2) - (2)].function_decl));
;}
    break;

  case 60:
#line 473 "pascal.y"
    {
    (yyval.routine_part) = A_RoutinePartSeqWithProcedureDecl(line_no, (yyvsp[(1) - (2)].routine_part), (yyvsp[(2) - (2)].procedure_decl));
;}
    break;

  case 61:
#line 476 "pascal.y"
    {
    (yyval.routine_part) = A_RoutinePartWithFunctionDecl(line_no, (yyvsp[(1) - (1)].function_decl));
;}
    break;

  case 62:
#line 479 "pascal.y"
    {
    (yyval.routine_part) = A_RoutinePartWithProcedureDecl(line_no, (yyvsp[(1) - (1)].procedure_decl));
;}
    break;

  case 63:
#line 482 "pascal.y"
    {
    (yyval.routine_part) = NULL;
;}
    break;

  case 64:
#line 487 "pascal.y"
    {
    (yyval.function_decl) = A_FunctionDecl(line_no, (yyvsp[(1) - (4)].function_head), (yyvsp[(3) - (4)].sub_routine));
;}
    break;

  case 65:
#line 490 "pascal.y"
    {
    (yyval.function_decl) = A_FunctionDecl(line_no, (yyvsp[(1) - (4)].function_head), (yyvsp[(3) - (4)].sub_routine));
    /* SEMI写错成COMMA */
    printf("[syntax error] line: %d, COMMA(\',\') should be SEMI(\';\').\n", line_no);
;}
    break;

  case 66:
#line 495 "pascal.y"
    {
    (yyval.function_decl) = A_FunctionDecl(line_no, (yyvsp[(1) - (4)].function_head), (yyvsp[(3) - (4)].sub_routine));
    /* SEMI写错成COLON */
    printf("[syntax error] line: %d, COLON(\':\') should be SEMI(\';\').\n", line_no);
;}
    break;

  case 67:
#line 500 "pascal.y"
    {
    (yyval.function_decl) = A_FunctionDecl(line_no, (yyvsp[(1) - (3)].function_head), (yyvsp[(2) - (3)].sub_routine));
    /* 少SEMI 1 */
    printf("[syntax error] line: %d, expect SEMI(\';\') between function head and subroutine.\n", line_no);
;}
    break;

  case 68:
#line 505 "pascal.y"
    {
    (yyval.function_decl) = A_FunctionDecl(line_no, (yyvsp[(1) - (2)].function_head), (yyvsp[(2) - (2)].sub_routine));
    /* 少SEMI 2 */
    printf("[syntax error] line: %d, expect SEMI(\';\') at the end of function declaration.\n", line_no);
;}
    break;

  case 69:
#line 512 "pascal.y"
    {
    (yyval.function_head) = A_FunctionHead(line_no, S_Symbol((yyvsp[(2) - (5)].sval)), (yyvsp[(3) - (5)].parameters), (yyvsp[(5) - (5)].simple_type_decl));
;}
    break;

  case 70:
#line 517 "pascal.y"
    {
    (yyval.procedure_decl) = A_ProcedureDecl(line_no, (yyvsp[(1) - (4)].procedure_head), (yyvsp[(3) - (4)].sub_routine));
;}
    break;

  case 71:
#line 520 "pascal.y"
    {
    (yyval.procedure_decl) = A_ProcedureDecl(line_no, (yyvsp[(1) - (4)].procedure_head), (yyvsp[(3) - (4)].sub_routine));
    /* SEMI写错成COMMA */
    printf("[syntax error] line: %d, COMMA(\',\') should be SEMI(\';\').\n", line_no);
;}
    break;

  case 72:
#line 525 "pascal.y"
    {
    (yyval.procedure_decl) = A_ProcedureDecl(line_no, (yyvsp[(1) - (4)].procedure_head), (yyvsp[(3) - (4)].sub_routine));
    /* SEMI写错成COLON */
    printf("[syntax error] line: %d, COLON(\':\') should be SEMI(\';\').\n", line_no);
;}
    break;

  case 73:
#line 532 "pascal.y"
    {
    (yyval.procedure_head) = A_ProcedureHead(line_no, S_Symbol((yyvsp[(2) - (3)].sval)), (yyvsp[(3) - (3)].parameters));
;}
    break;

  case 74:
#line 535 "pascal.y"
    {
    char id[40] = { 0 };
    sprintf(id, "unnamed_procedure_at_line_%d\0", line_no);
    (yyval.procedure_head) = A_ProcedureHead(line_no, S_Symbol(id), (yyvsp[(2) - (2)].parameters));
    /* PROCEDURE少ID */
    printf("[syntax error] line: %d, expect procedure ID between PROCEDURE and parameters.\n", line_no);
;}
    break;

  case 75:
#line 544 "pascal.y"
    {
    (yyval.parameters) = A_Parameters(line_no, (yyvsp[(2) - (3)].para_decl_list));
;}
    break;

  case 76:
#line 547 "pascal.y"
    {
    (yyval.parameters) = NULL;
;}
    break;

  case 77:
#line 552 "pascal.y"
    {
    (yyval.para_decl_list) = A_ParaDeclListSeq(line_no, (yyvsp[(1) - (3)].para_decl_list), (yyvsp[(3) - (3)].para_type_list));
;}
    break;

  case 78:
#line 555 "pascal.y"
    {
    (yyval.para_decl_list) = A_ParaDeclList(line_no, (yyvsp[(1) - (1)].para_type_list));
;}
    break;

  case 79:
#line 558 "pascal.y"
    {
    (yyval.para_decl_list) = A_ParaDeclListSeq(line_no, (yyvsp[(1) - (3)].para_decl_list), (yyvsp[(3) - (3)].para_type_list));
    /* SEMI写错成COLON */
    printf("[syntax error] line: %d, COLON(\':\') should be SEMI(\';\').\n", line_no);
;}
    break;

  case 80:
#line 563 "pascal.y"
    {
    (yyval.para_decl_list) = A_ParaDeclListSeq(line_no, (yyvsp[(1) - (4)].procedure_head), (yyvsp[(3) - (4)].sub_routine));
    /* SEMI写错成COLON */
    printf("[syntax error] line: %d, COMMA(\',\') should be SEMI(\';\').\n", line_no);
;}
    break;

  case 81:
#line 571 "pascal.y"
    {
    (yyval.para_type_list) = A_ParaTypeListVar(line_no, (yyvsp[(1) - (3)].var_para_list), (yyvsp[(3) - (3)].simple_type_decl));
;}
    break;

  case 82:
#line 574 "pascal.y"
    {
    (yyval.para_type_list) = A_ParaTypeListVal(line_no, (yyvsp[(1) - (3)].val_para_list), (yyvsp[(3) - (3)].simple_type_decl));
;}
    break;

  case 83:
#line 577 "pascal.y"
    {
    (yyval.para_type_list) = A_ParaTypeListVar(line_no, (yyvsp[(1) - (3)].var_para_list), (yyvsp[(3) - (3)].simple_type_decl));
    /* COLON写错成SEMI */
    printf("[syntax error] line: %d, SEMI(\';\') should be COLON(\':\').\n", line_no);
;}
    break;

  case 84:
#line 582 "pascal.y"
    {
    (yyval.para_type_list) = A_ParaTypeListVal(line_no, (yyvsp[(1) - (3)].val_para_list), (yyvsp[(3) - (3)].simple_type_decl));
    /* COLON写错成SEMI */
    printf("[syntax error] line: %d, SEMI(\';\') should be COLON(\':\').\n", line_no);
;}
    break;

  case 85:
#line 589 "pascal.y"
    {
    (yyval.var_para_list) = A_VarParaList(line_no, (yyvsp[(2) - (2)].name_list));
;}
    break;

  case 86:
#line 594 "pascal.y"
    {
    (yyval.val_para_list) = A_ValParaList(line_no, (yyvsp[(1) - (1)].name_list));
;}
    break;

  case 87:
#line 599 "pascal.y"
    {
    (yyval.routine_body) = A_RoutineBody(line_no, (yyvsp[(1) - (1)].compound_stmt));
;}
    break;

  case 88:
#line 604 "pascal.y"
    {
    (yyval.compound_stmt) = A_CompoundStmt(line_no, (yyvsp[(2) - (3)].stmt_list));
;}
    break;

  case 89:
#line 609 "pascal.y"
    {
    (yyval.stmt_list) = A_StmtList(line_no, (yyvsp[(1) - (3)].stmt_list), (yyvsp[(2) - (3)].stmt));
;}
    break;

  case 90:
#line 612 "pascal.y"
    {
    (yyval.stmt_list) = NULL;
;}
    break;

  case 91:
#line 617 "pascal.y"
    {
    (yyval.stmt) = A_StmtLabel(line_no, (yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].non_label_stmt));
;}
    break;

  case 92:
#line 620 "pascal.y"
    {
    (yyval.stmt) = A_StmtNonLabel(line_no, (yyvsp[(1) - (1)].non_label_stmt));
;}
    break;

  case 93:
#line 625 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtAssign(line_no, (yyvsp[(1) - (1)].assign_stmt));
;}
    break;

  case 94:
#line 628 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtProc(line_no, (yyvsp[(1) - (1)].proc_stmt));
;}
    break;

  case 95:
#line 631 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtCompound(line_no, (yyvsp[(1) - (1)].compound_stmt));
;}
    break;

  case 96:
#line 634 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtIf(line_no, (yyvsp[(1) - (1)].if_stmt));
;}
    break;

  case 97:
#line 637 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtRepeat(line_no, (yyvsp[(1) - (1)].repeat_stmt));
;}
    break;

  case 98:
#line 640 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtWhile(line_no, (yyvsp[(1) - (1)].while_stmt));
;}
    break;

  case 99:
#line 643 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtFor(line_no, (yyvsp[(1) - (1)].for_stmt));
;}
    break;

  case 100:
#line 646 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtCase(line_no, (yyvsp[(1) - (1)].case_stmt));
;}
    break;

  case 101:
#line 649 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtGoto(line_no, (yyvsp[(1) - (1)].goto_stmt));
;}
    break;

  case 102:
#line 654 "pascal.y"
    {
    (yyval.assign_stmt) = A_AssignStmtSimple(line_no, S_Symbol((yyvsp[(1) - (3)].sval)), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 103:
#line 657 "pascal.y"
    {
    (yyval.assign_stmt) = A_AssignStmtArray(line_no, S_Symbol((yyvsp[(1) - (6)].sval)), (yyvsp[(3) - (6)].expression), (yyvsp[(6) - (6)].expression));
;}
    break;

  case 104:
#line 660 "pascal.y"
    {
    (yyval.assign_stmt) = A_AssignStmtRecord(line_no, S_Symbol((yyvsp[(1) - (5)].sval)), S_Symbol((yyvsp[(3) - (5)].sval)), (yyvsp[(5) - (5)].expression));
;}
    break;

  case 105:
#line 663 "pascal.y"
    {
    (yyval.assign_stmt) = A_AssignStmtSimple(line_no, S_Symbol((yyvsp[(1) - (3)].sval)), (yyvsp[(3) - (3)].expression));
    /* ASSIGN写错成EQUAL */
    printf("[syntax error] line: %d, EQUAL(\'=\') should be ASSIGN(\':=\').\n", line_no);
;}
    break;

  case 106:
#line 668 "pascal.y"
    {
    (yyval.assign_stmt) = A_AssignStmtArray(line_no, S_Symbol((yyvsp[(1) - (6)].sval)), (yyvsp[(3) - (6)].expression), (yyvsp[(6) - (6)].expression));
    /* ASSIGN写错成EQUAL */
    printf("[syntax error] line: %d, EQUAL(\'=\') should be ASSIGN(\':=\').\n", line_no);
;}
    break;

  case 107:
#line 673 "pascal.y"
    {
    (yyval.assign_stmt) = A_AssignStmtRecord(line_no, S_Symbol((yyvsp[(1) - (5)].sval)), S_Symbol((yyvsp[(3) - (5)].sval)), (yyvsp[(5) - (5)].expression));
    /* ASSIGN写错成EQUAL */
    printf("[syntax error] line: %d, EQUAL(\'=\') should be ASSIGN(\':=\').\n", line_no);
;}
    break;

  case 108:
#line 680 "pascal.y"
    {
    (yyval.proc_stmt) = A_ProcStmtID(line_no, S_Symbol((yyvsp[(1) - (1)].sval)));
;}
    break;

  case 109:
#line 683 "pascal.y"
    {
    (yyval.proc_stmt) = A_ProcStmtIDWithArgs(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].args_list));
;}
    break;

  case 110:
#line 686 "pascal.y"
    {
    (yyval.proc_stmt) = A_ProcStmtSysProc(line_no, (yyvsp[(1) - (1)].sys_proc));
;}
    break;

  case 111:
#line 689 "pascal.y"
    {
    (yyval.proc_stmt) = A_ProcStmtSysProcWithArgs(line_no, (yyvsp[(1) - (4)].sys_proc), (yyvsp[(3) - (4)].expression_list));
;}
    break;

  case 112:
#line 692 "pascal.y"
    {
    (yyval.proc_stmt) = A_ProcStmtRead(line_no, (yyvsp[(3) - (4)].factor));
;}
    break;

  case 113:
#line 697 "pascal.y"
    {
    (yyval.if_stmt) = A_IfStmt(line_no, (yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].stmt), (yyvsp[(5) - (5)].else_clause));
;}
    break;

  case 114:
#line 702 "pascal.y"
    {
    (yyval.else_clause) = A_ElseClause(line_no, (yyvsp[(2) - (2)].stmt));
;}
    break;

  case 115:
#line 704 "pascal.y"
    {
    (yyval.else_clause) = A_ElseClause(line_no, NULL);
;}
    break;

  case 116:
#line 710 "pascal.y"
    {
    (yyval.repeat_stmt) = A_RepeatStmt(line_no, (yyvsp[(2) - (4)].stmt_list), (yyvsp[(4) - (4)].expression));
;}
    break;

  case 117:
#line 715 "pascal.y"
    {
    (yyval.while_stmt) = A_WhileStmt(line_no, (yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].stmt));
;}
    break;

  case 118:
#line 720 "pascal.y"
    {
    (yyval.for_stmt) = A_ForStmt(line_no, S_Symbol((yyvsp[(2) - (8)].sval)), (yyvsp[(4) - (8)].expression), (yyvsp[(5) - (8)].direction), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].stmt));
;}
    break;

  case 119:
#line 723 "pascal.y"
    {
    (yyval.for_stmt) = A_ForStmt(line_no, S_Symbol((yyvsp[(2) - (8)].sval)), (yyvsp[(4) - (8)].expression), (yyvsp[(5) - (8)].direction), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].stmt));
    /* ASSIGN写错成EQUAL */
    printf("[syntax error] line: %d, EQUAL(\'=\') should be ASSIGN(\':=\').\n", line_no);
;}
    break;

  case 120:
#line 730 "pascal.y"
    {
    (yyval.direction) = DIRECTION_TO;
;}
    break;

  case 121:
#line 733 "pascal.y"
    {
    (yyval.direction) = DIRECTION_DOWNTO;
;}
    break;

  case 122:
#line 738 "pascal.y"
    {
    (yyval.case_stmt) = A_CaseStmt(line_no, (yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].case_expr_list));
;}
    break;

  case 123:
#line 743 "pascal.y"
    {
    (yyval.case_expr_list) = A_CaseExprListSeq(line_no, (yyvsp[(1) - (2)].case_expr_list), (yyvsp[(2) - (2)].case_expr));
;}
    break;

  case 124:
#line 746 "pascal.y"
    {
    (yyval.case_expr_list) = A_CaseExprList(line_no, (yyvsp[(1) - (1)].case_expr));
;}
    break;

  case 125:
#line 751 "pascal.y"
    {
    (yyval.case_expr) = A_CaseExprConst(line_no, (yyvsp[(1) - (4)].const_value), (yyvsp[(3) - (4)].stmt));
;}
    break;

  case 126:
#line 754 "pascal.y"
    {
    (yyval.case_expr) = A_CaseExprNonConst(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].stmt));
;}
    break;

  case 127:
#line 757 "pascal.y"
    {
    (yyval.case_expr) = A_CaseExprConst(line_no, (yyvsp[(1) - (4)].const_value), (yyvsp[(3) - (4)].stmt));
    /* COLON写错成COMMA */
    printf("[syntax error] line: %d, COMMA(\',\') should be COLON(\':\').\n", line_no);
;}
    break;

  case 128:
#line 762 "pascal.y"
    {
    (yyval.case_expr) = A_CaseExprNonConst(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].stmt));
    /* COLON写错成COMMA */
    printf("[syntax error] line: %d, COMMA(\',\') should be COLON(\':\').\n", line_no);
;}
    break;

  case 129:
#line 767 "pascal.y"
    {
    (yyval.case_expr) = A_CaseExprConst(line_no, (yyvsp[(1) - (4)].const_value), (yyvsp[(3) - (4)].stmt));
    /* COLON写错成SEMI */
    printf("[syntax error] line: %d, SEMI(\';\') should be COLON(\':\').\n", line_no);
;}
    break;

  case 130:
#line 772 "pascal.y"
    {
    (yyval.case_expr) = A_CaseExprNonConst(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].stmt));
    /* COLON写错成SEMI */
    printf("[syntax error] line: %d, SEMI(\';\') should be COLON(\':\').\n", line_no);
;}
    break;

  case 131:
#line 779 "pascal.y"
    {
    (yyval.goto_stmt) = A_GotoStmt(line_no, (yyvsp[(2) - (2)].ival));
;}
    break;

  case 132:
#line 784 "pascal.y"
    {
    (yyval.expression_list) = A_ExpressionListSeq(line_no, (yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 133:
#line 787 "pascal.y"
    {
    (yyval.expression_list) = A_ExpressionList(line_no, (yyvsp[(1) - (1)].expression));
;}
    break;

  case 134:
#line 792 "pascal.y"
    {
    (yyval.expression) = A_ExpressionBin(line_no, (yyvsp[(1) - (3)].expression), OP_GE, (yyvsp[(3) - (3)].expr));
;}
    break;

  case 135:
#line 795 "pascal.y"
    {
    (yyval.expression) = A_ExpressionBin(line_no, (yyvsp[(1) - (3)].expression), OP_GT, (yyvsp[(3) - (3)].expr));
;}
    break;

  case 136:
#line 798 "pascal.y"
    {
    (yyval.expression) = A_ExpressionBin(line_no, (yyvsp[(1) - (3)].expression), OP_LE, (yyvsp[(3) - (3)].expr));
;}
    break;

  case 137:
#line 801 "pascal.y"
    {
    (yyval.expression) = A_ExpressionBin(line_no, (yyvsp[(1) - (3)].expression), OP_LT, (yyvsp[(3) - (3)].expr));
;}
    break;

  case 138:
#line 804 "pascal.y"
    {
    (yyval.expression) = A_ExpressionBin(line_no, (yyvsp[(1) - (3)].expression), OP_EQUAL, (yyvsp[(3) - (3)].expr));
;}
    break;

  case 139:
#line 807 "pascal.y"
    {
    (yyval.expression) = A_ExpressionBin(line_no, (yyvsp[(1) - (3)].expression), OP_UNEQUAL, (yyvsp[(3) - (3)].expr));
;}
    break;

  case 140:
#line 810 "pascal.y"
    {
    (yyval.expression) = A_ExpressionUn(line_no, (yyvsp[(1) - (1)].expr));
;}
    break;

  case 141:
#line 815 "pascal.y"
    {
    (yyval.expr) = A_ExprBin(line_no, (yyvsp[(1) - (3)].expr), OP_PLUS, (yyvsp[(3) - (3)].term));
;}
    break;

  case 142:
#line 818 "pascal.y"
    {
    (yyval.expr) = A_ExprBin(line_no, (yyvsp[(1) - (3)].expr), OP_MINUS, (yyvsp[(3) - (3)].term));
;}
    break;

  case 143:
#line 821 "pascal.y"
    {
    (yyval.expr) = A_ExprBin(line_no, (yyvsp[(1) - (3)].expr), OP_OR, (yyvsp[(3) - (3)].term));
;}
    break;

  case 144:
#line 824 "pascal.y"
    {
    (yyval.expr) = A_ExprUn(line_no, (yyvsp[(1) - (1)].term));
;}
    break;

  case 145:
#line 829 "pascal.y"
    {
    (yyval.term) = A_TermBin(line_no, (yyvsp[(1) - (3)].term), OP_MUL, (yyvsp[(3) - (3)].factor));
;}
    break;

  case 146:
#line 832 "pascal.y"
    {
    (yyval.term) = A_TermBin(line_no, (yyvsp[(1) - (3)].term), OP_DIV, (yyvsp[(3) - (3)].factor));
;}
    break;

  case 147:
#line 835 "pascal.y"
    {
    (yyval.term) = A_TermBin(line_no, (yyvsp[(1) - (3)].term), OP_MOD, (yyvsp[(3) - (3)].factor));
;}
    break;

  case 148:
#line 838 "pascal.y"
    {
    (yyval.term) = A_TermBin(line_no, (yyvsp[(1) - (3)].term), OP_AND, (yyvsp[(3) - (3)].factor));
;}
    break;

  case 149:
#line 841 "pascal.y"
    {
    (yyval.term) = A_TermUn(line_no, (yyvsp[(1) - (1)].factor));
;}
    break;

  case 150:
#line 846 "pascal.y"
    {
    (yyval.factor) = A_FactorId(line_no, S_Symbol((yyvsp[(1) - (1)].sval)));
;}
    break;

  case 151:
#line 849 "pascal.y"
    {
    (yyval.factor) = A_FactorIdWithArgs(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].args_list));
;}
    break;

  case 152:
#line 852 "pascal.y"
    {
    (yyval.factor) = A_FactorSysFunct(line_no, (yyvsp[(1) - (1)].sys_funct));
;}
    break;

  case 153:
#line 855 "pascal.y"
    {
    (yyval.factor) = A_FactorSysFunctWithArgs(line_no, (yyvsp[(1) - (4)].sys_funct), (yyvsp[(3) - (4)].args_list));
;}
    break;

  case 154:
#line 858 "pascal.y"
    {
    (yyval.factor) = A_FactorConst(line_no, (yyvsp[(1) - (1)].const_value));
;}
    break;

  case 155:
#line 861 "pascal.y"
    {
    (yyval.factor) = A_FactorInBrackets(line_no, (yyvsp[(2) - (3)].expression));
;}
    break;

  case 156:
#line 864 "pascal.y"
    {
    (yyval.factor) = A_FactorUnOp(line_no, OP_NOT, (yyvsp[(2) - (2)].factor));
;}
    break;

  case 157:
#line 867 "pascal.y"
    {
    (yyval.factor) = A_FactorUnOp(line_no, OP_NEG, (yyvsp[(2) - (2)].factor));
;}
    break;

  case 158:
#line 870 "pascal.y"
    {
    (yyval.factor) = A_FactorArrayVar(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].expression));
;}
    break;

  case 159:
#line 873 "pascal.y"
    {
    (yyval.factor) = A_FactorRecordVar(line_no, S_Symbol((yyvsp[(1) - (3)].sval)), S_Symbol((yyvsp[(3) - (3)].sval)));
;}
    break;

  case 160:
#line 878 "pascal.y"
    {
    (yyval.args_list) = A_ArgsListSeq(line_no, (yyvsp[(1) - (3)].args_list), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 161:
#line 881 "pascal.y"
    {
    (yyval.args_list) = A_ArgsList(line_no, (yyvsp[(1) - (1)].expression));
;}
    break;


/* Line 1267 of yacc.c.  */
#line 3089 "pascal.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 887 "pascal.y"

   
void yyerror(const char *s)
{
	printf("yyerror: %s | line: %d.\n", s, line_no);					//out error information
}
