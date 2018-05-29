
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
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



/* Line 189 of yacc.c  */
#line 92 "pascal.tab.c"

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
     LOWER_THAN_ELSE = 316
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 20 "pascal.y"

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



/* Line 214 of yacc.c  */
#line 270 "pascal.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 282 "pascal.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   338

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNRULES -- Number of states.  */
#define YYNSTATES  261

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    14,    17,    23,    24,    27,
      28,    34,    39,    41,    43,    45,    47,    49,    52,    53,
      56,    58,    63,    65,    67,    69,    71,    73,    77,    81,
      86,    92,    96,   103,   107,   110,   112,   117,   121,   123,
     126,   127,   130,   132,   137,   140,   143,   145,   147,   148,
     153,   159,   164,   168,   172,   173,   177,   179,   183,   187,
     190,   192,   194,   198,   202,   203,   207,   209,   211,   213,
     215,   217,   219,   221,   223,   225,   227,   231,   238,   244,
     246,   251,   253,   258,   263,   269,   272,   273,   278,   283,
     292,   294,   296,   302,   305,   307,   312,   317,   320,   324,
     326,   330,   334,   338,   342,   346,   350,   352,   356,   360,
     364,   366,   370,   374,   378,   382,   384,   386,   391,   393,
     398,   400,   404,   407,   410,   415,   419,   423
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    64,    65,    30,    -1,     8,     3,    32,
      -1,    67,    95,    -1,    67,    95,    -1,    68,    69,    72,
      82,    85,    -1,    -1,     9,    70,    -1,    -1,    70,     3,
      42,    71,    32,    -1,     3,    42,    71,    32,    -1,     4,
      -1,     5,    -1,     6,    -1,     7,    -1,    60,    -1,    17,
      73,    -1,    -1,    73,    74,    -1,    74,    -1,     3,    42,
      75,    32,    -1,    76,    -1,    77,    -1,    78,    -1,    57,
      -1,     3,    -1,    37,    81,    38,    -1,    71,    31,    71,
      -1,    49,    71,    31,    71,    -1,    49,    71,    31,    49,
      71,    -1,     3,    31,     3,    -1,    10,    35,    76,    36,
      28,    75,    -1,    11,    79,    13,    -1,    79,    80,    -1,
      80,    -1,    81,    33,    75,    32,    -1,    81,    34,     3,
      -1,     3,    -1,    14,    83,    -1,    -1,    83,    84,    -1,
      84,    -1,    81,    33,    75,    32,    -1,    85,    86,    -1,
      85,    88,    -1,    86,    -1,    88,    -1,    -1,    87,    32,
      66,    32,    -1,    15,     3,    90,    33,    76,    -1,    89,
      32,    66,    32,    -1,    16,     3,    90,    -1,    37,    91,
      38,    -1,    -1,    91,    32,    92,    -1,    92,    -1,    93,
      33,    76,    -1,    94,    33,    76,    -1,    14,    81,    -1,
      81,    -1,    96,    -1,    12,    97,    13,    -1,    97,    98,
      32,    -1,    -1,     4,    33,    99,    -1,    99,    -1,   100,
      -1,   101,    -1,    96,    -1,   102,    -1,   104,    -1,   105,
      -1,   106,    -1,   108,    -1,   111,    -1,     3,    39,   113,
      -1,     3,    35,   113,    36,    39,   113,    -1,     3,    30,
       3,    39,   113,    -1,     3,    -1,     3,    37,   117,    38,
      -1,    59,    -1,    59,    37,   112,    38,    -1,    18,    37,
     116,    38,    -1,    19,   113,    20,    98,   103,    -1,    21,
      98,    -1,    -1,    22,    97,    23,   113,    -1,    24,   113,
      25,    98,    -1,    26,     3,    39,   113,   107,   113,    25,
      98,    -1,    55,    -1,    56,    -1,    27,   113,    28,   109,
      13,    -1,   109,   110,    -1,   110,    -1,    71,    33,    98,
      32,    -1,     3,    33,    98,    32,    -1,    29,     4,    -1,
     112,    34,   113,    -1,   113,    -1,   113,    44,   114,    -1,
     113,    45,   114,    -1,   113,    46,   114,    -1,   113,    47,
     114,    -1,   113,    42,   114,    -1,   113,    43,   114,    -1,
     114,    -1,   114,    48,   115,    -1,   114,    49,   115,    -1,
     114,    50,   115,    -1,   115,    -1,   115,    51,   116,    -1,
     115,    52,   116,    -1,   115,    53,   116,    -1,   115,    54,
     116,    -1,   116,    -1,     3,    -1,     3,    37,   117,    38,
      -1,    58,    -1,    58,    37,   117,    38,    -1,    71,    -1,
      37,   113,    38,    -1,    40,   116,    -1,    49,   116,    -1,
       3,    35,   113,    36,    -1,     3,    30,     3,    -1,   117,
      34,   113,    -1,   113,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   192,   192,   198,   203,   208,   213,   218,   223,   226,
     231,   235,   240,   243,   246,   249,   252,   257,   260,   265,
     268,   273,   279,   282,   285,   290,   293,   297,   300,   303,
     313,   325,   331,   336,   341,   344,   349,   354,   358,   364,
     367,   372,   375,   380,   385,   388,   391,   394,   397,   402,
     407,   412,   417,   423,   426,   431,   434,   440,   443,   448,
     453,   458,   463,   468,   471,   476,   479,   484,   487,   490,
     493,   496,   499,   502,   505,   508,   513,   517,   521,   527,
     531,   534,   537,   540,   545,   550,   552,   558,   563,   568,
     573,   576,   581,   586,   589,   594,   597,   603,   608,   611,
     616,   619,   622,   625,   628,   631,   634,   639,   642,   645,
     648,   653,   656,   659,   662,   665,   670,   674,   678,   681,
     684,   687,   690,   693,   696,   700,   706,   709
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
  "SYS_CON", "LOWER_THAN_ELSE", "$accept", "program", "program_head",
  "routine", "sub_routine", "routine_head", "label_part", "const_part",
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
     315,   316
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    65,    66,    67,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    74,    75,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    77,    78,    79,    79,    80,    81,    81,    82,
      82,    83,    83,    84,    85,    85,    85,    85,    85,    86,
      87,    88,    89,    90,    90,    91,    91,    92,    92,    93,
      94,    95,    96,    97,    97,    98,    98,    99,    99,    99,
      99,    99,    99,    99,    99,    99,   100,   100,   100,   101,
     101,   101,   101,   101,   102,   103,   103,   104,   105,   106,
     107,   107,   108,   109,   109,   110,   110,   111,   112,   112,
     113,   113,   113,   113,   113,   113,   113,   114,   114,   114,
     114,   115,   115,   115,   115,   115,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   117,   117
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     5,     0,     2,     0,
       5,     4,     1,     1,     1,     1,     1,     2,     0,     2,
       1,     4,     1,     1,     1,     1,     1,     3,     3,     4,
       5,     3,     6,     3,     2,     1,     4,     3,     1,     2,
       0,     2,     1,     4,     2,     2,     1,     1,     0,     4,
       5,     4,     3,     3,     0,     3,     1,     3,     3,     2,
       1,     1,     3,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     6,     5,     1,
       4,     1,     4,     4,     5,     2,     0,     4,     4,     8,
       1,     1,     5,     2,     1,     4,     4,     2,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     1,     4,     1,     4,
       1,     3,     2,     2,     4,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     9,     3,
       2,    64,     4,    61,     0,    18,     0,     0,     8,     0,
      40,    79,     0,    62,     0,     0,    64,     0,     0,     0,
       0,    81,    69,     0,    66,    67,    68,    70,    71,    72,
      73,    74,    75,     0,     0,     0,    17,    20,     0,    48,
       0,     0,     0,     0,     0,     0,   116,    12,    13,    14,
      15,     0,     0,     0,   118,    16,   120,     0,   106,   110,
     115,     0,     0,     0,     0,    97,     0,    63,     0,     0,
       0,    19,    38,     0,    39,    42,     0,     0,     6,    46,
       0,    47,     0,     0,     0,   127,     0,    76,    65,     0,
       0,     0,     0,     0,   122,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,    11,     0,    26,
       0,     0,     0,     0,    25,     0,     0,    22,    23,    24,
       0,     0,    41,    54,    54,    44,    45,     7,     7,     0,
       0,     0,    80,    83,   125,     0,     0,   121,     0,    86,
     104,   105,   100,   101,   102,   103,   107,   108,   109,   111,
     112,   113,   114,    87,    88,     0,     0,     0,     0,    94,
       0,    82,    10,     0,     0,     0,    35,     0,     0,     0,
       0,    21,     0,    37,     0,     0,    52,     0,     0,     0,
      78,     0,   126,   124,   117,   119,     0,    84,    90,    91,
       0,     0,     0,    92,    93,    98,    31,     0,    33,    34,
       0,    27,     0,    28,    43,     0,    60,     0,    56,     0,
       0,     0,    49,     5,    51,    77,    85,     0,     0,     0,
       0,     0,     0,    29,    59,     0,    53,     0,     0,    50,
       0,    96,    95,     0,    36,    30,    55,    57,    58,    89,
      32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,   197,   198,     8,    15,    18,    66,
      20,    46,    47,   136,   137,   138,   139,   185,   186,    83,
      49,    84,    85,    88,    89,    90,    91,    92,   195,   227,
     228,   229,   230,    12,    32,    16,    33,    34,    35,    36,
      37,   207,    38,    39,    40,   210,    41,   178,   179,    42,
     125,    95,    68,    69,    70,    96
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -173
static const yytype_int16 yypact[] =
{
       5,    52,    27,  -173,    25,  -173,    32,    54,    60,  -173,
    -173,  -173,  -173,  -173,    79,    72,   171,    57,   111,   124,
     122,    15,   109,  -173,   107,    28,  -173,    28,   146,    28,
     152,   121,  -173,   130,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,    99,   123,   131,   124,  -173,   161,    31,
     173,    28,    28,    28,   241,    28,    21,  -173,  -173,  -173,
    -173,    28,    28,    28,   143,  -173,  -173,   192,    74,   162,
    -173,   199,   125,   142,    87,  -173,    28,  -173,   150,    99,
     106,  -173,  -173,    86,   161,  -173,   182,   183,    31,  -173,
     159,  -173,   169,   155,   252,   281,    10,   281,  -173,   168,
     205,    28,    28,   275,  -173,  -173,    28,   228,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,   228,    28,    19,    26,   281,  -173,   177,   188,
     185,   161,   161,    99,  -173,   193,   195,  -173,  -173,  -173,
     106,   226,  -173,   196,   196,  -173,  -173,  -173,  -173,    28,
     202,    28,  -173,  -173,  -173,   265,    29,  -173,    46,   222,
      74,    74,    74,    74,    74,    74,   162,   162,   162,  -173,
    -173,  -173,  -173,   281,  -173,   237,   209,   212,    36,  -173,
      28,  -173,  -173,   245,    88,    16,  -173,   127,    49,   218,
      99,  -173,   219,  -173,     7,   229,  -173,   232,    54,   234,
     281,    28,   281,  -173,  -173,  -173,   228,  -173,  -173,  -173,
      28,   228,   228,  -173,  -173,   281,  -173,   225,  -173,  -173,
     106,  -173,   147,  -173,  -173,   161,   235,   -18,  -173,   238,
     239,    88,  -173,  -173,  -173,   281,  -173,   231,   253,   254,
     261,   258,    99,  -173,   235,     7,  -173,    88,    88,  -173,
     228,  -173,  -173,   106,  -173,  -173,  -173,  -173,  -173,  -173,
    -173
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,  -173,  -173,   154,   288,  -173,  -173,  -173,   -43,
    -173,  -173,   257,  -135,  -172,  -173,  -173,  -173,   119,  -124,
    -173,  -173,   230,  -173,   217,  -173,   227,  -173,   172,  -173,
      61,  -173,  -173,   137,    -6,   310,  -104,   283,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,   160,  -173,
    -173,   -23,   221,    24,   -46,   -91
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      78,    13,    67,   159,    72,   192,    74,   187,   188,    99,
      82,   156,   217,     1,   245,   158,   104,   105,   174,    82,
     246,   225,   176,    57,    58,    59,    60,     5,    94,   218,
      97,    56,    57,    58,    59,    60,   128,   135,   103,   176,
      57,    58,    59,    60,   151,    50,    86,    87,   152,   213,
      51,   100,    52,   126,    53,     4,   101,     9,   102,   249,
     180,   187,    10,   151,   181,    61,    11,   204,    62,    14,
     226,   169,   170,   171,   172,   257,   258,    63,   155,    65,
     151,   177,    17,   141,   205,   241,    64,   221,    65,    19,
     189,   129,    57,    58,    59,    60,    65,   135,   173,    43,
     175,   244,   236,    57,    58,    59,    60,   238,   239,   129,
      57,    58,    59,    60,    44,   124,   130,   131,   260,   140,
     141,   226,   114,   115,   116,   132,   200,    45,   202,   108,
     109,   110,   111,   112,   113,   177,    48,   133,   166,   167,
     168,   135,    54,   132,    55,   134,   259,   223,    65,    73,
     122,    57,    58,    59,    60,   133,    75,   215,    76,    65,
     220,   141,    77,   134,    82,    79,    65,   108,   109,   110,
     111,   112,   113,    80,    21,    22,    93,   135,   235,   243,
     106,   123,   127,    11,    23,   143,   144,   237,   135,    24,
      25,   147,    13,    26,   149,    27,   242,    28,    29,   255,
      30,   148,    21,    22,   135,   135,   153,    65,   154,   182,
     135,    11,   107,   117,   118,   119,   120,    24,    25,   183,
     184,    26,   121,    27,   190,    28,    29,   191,    30,   193,
      31,    21,    22,   194,   108,   109,   110,   111,   112,   113,
      11,   201,   211,   206,    21,   212,    24,    25,   216,   222,
      26,   224,    27,    11,    28,    29,   250,    30,    31,    24,
      25,   240,   231,    26,   232,    27,   234,    28,    29,   141,
      30,   247,   248,   108,   109,   110,   111,   112,   113,   108,
     109,   110,   111,   112,   113,   251,   252,    31,   150,   253,
     254,     7,   208,   209,   108,   109,   110,   111,   112,   113,
      31,   203,   199,    81,   219,   145,   256,   108,   109,   110,
     111,   112,   113,   157,   142,   146,   196,   108,   109,   110,
     111,   112,   113,   108,   109,   110,   111,   112,   113,   160,
     161,   162,   163,   164,   165,   233,    71,    98,   214
};

static const yytype_uint8 yycheck[] =
{
      43,     7,    25,   107,    27,   140,    29,   131,   132,    55,
       3,   102,   184,     8,    32,   106,    62,    63,   122,     3,
      38,    14,     3,     4,     5,     6,     7,     0,    51,    13,
      53,     3,     4,     5,     6,     7,    79,    80,    61,     3,
       4,     5,     6,     7,    34,    30,    15,    16,    38,    13,
      35,    30,    37,    76,    39,     3,    35,    32,    37,   231,
      34,   185,    30,    34,    38,    37,    12,    38,    40,     9,
     194,   117,   118,   119,   120,   247,   248,    49,   101,    60,
      34,   124,     3,    34,    38,   220,    58,    38,    60,    17,
     133,     3,     4,     5,     6,     7,    60,   140,   121,    42,
     123,   225,   206,     4,     5,     6,     7,   211,   212,     3,
       4,     5,     6,     7,     3,    28,    10,    11,   253,    33,
      34,   245,    48,    49,    50,    37,   149,     3,   151,    42,
      43,    44,    45,    46,    47,   178,    14,    49,   114,   115,
     116,   184,    33,    37,    37,    57,   250,   190,    60,     3,
      25,     4,     5,     6,     7,    49,     4,   180,    37,    60,
      33,    34,    32,    57,     3,    42,    60,    42,    43,    44,
      45,    46,    47,    42,     3,     4,     3,   220,   201,   222,
      37,    39,    32,    12,    13,     3,     3,   210,   231,    18,
      19,    32,   198,    22,    39,    24,    49,    26,    27,   242,
      29,    32,     3,     4,   247,   248,    38,    60,     3,    32,
     253,    12,    20,    51,    52,    53,    54,    18,    19,    31,
      35,    22,    23,    24,    31,    26,    27,    32,    29,     3,
      59,     3,     4,    37,    42,    43,    44,    45,    46,    47,
      12,    39,    33,    21,     3,    33,    18,    19,     3,    31,
      22,    32,    24,    12,    26,    27,    25,    29,    59,    18,
      19,    36,    33,    22,    32,    24,    32,    26,    27,    34,
      29,    33,    33,    42,    43,    44,    45,    46,    47,    42,
      43,    44,    45,    46,    47,    32,    32,    59,    36,    28,
      32,     3,    55,    56,    42,    43,    44,    45,    46,    47,
      59,    36,   148,    46,   185,    88,   245,    42,    43,    44,
      45,    46,    47,    38,    84,    88,   144,    42,    43,    44,
      45,    46,    47,    42,    43,    44,    45,    46,    47,   108,
     109,   110,   111,   112,   113,   198,    26,    54,   178
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    63,    64,     3,     0,    65,    67,    68,    32,
      30,    12,    95,    96,     9,    69,    97,     3,    70,    17,
      72,     3,     4,    13,    18,    19,    22,    24,    26,    27,
      29,    59,    96,    98,    99,   100,   101,   102,   104,   105,
     106,   108,   111,    42,     3,     3,    73,    74,    14,    82,
      30,    35,    37,    39,    33,    37,     3,     4,     5,     6,
       7,    37,    40,    49,    58,    60,    71,   113,   114,   115,
     116,    97,   113,     3,   113,     4,    37,    32,    71,    42,
      42,    74,     3,    81,    83,    84,    15,    16,    85,    86,
      87,    88,    89,     3,   113,   113,   117,   113,    99,   116,
      30,    35,    37,   113,   116,   116,    37,    20,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    23,    25,    39,    28,   112,   113,    32,    71,     3,
      10,    11,    37,    49,    57,    71,    75,    76,    77,    78,
      33,    34,    84,     3,     3,    86,    88,    32,    32,    39,
      36,    34,    38,    38,     3,   113,   117,    38,   117,    98,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   116,
     116,   116,   116,   113,    98,   113,     3,    71,   109,   110,
      34,    38,    32,    31,    35,    79,    80,    81,    81,    71,
      31,    32,    75,     3,    37,    90,    90,    66,    67,    66,
     113,    39,   113,    36,    38,    38,    21,   103,    55,    56,
     107,    33,    33,    13,   110,   113,     3,    76,    13,    80,
      33,    38,    31,    71,    32,    14,    81,    91,    92,    93,
      94,    33,    32,    95,    32,   113,    98,   113,    98,    98,
      36,    75,    49,    71,    81,    32,    38,    33,    33,    76,
      25,    32,    32,    28,    32,    71,    92,    76,    76,    98,
      75
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 192 "pascal.y"
    {
    (yyval.program) = A_Program(line_no, (yyvsp[(1) - (3)].program_head), (yyvsp[(2) - (3)].routine));
    root = (yyval.program);
;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 198 "pascal.y"
    {
    (yyval.program_head) = A_ProgramHead(line_no, (yyvsp[(2) - (3)].sval));
;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 203 "pascal.y"
    {
    (yyval.routine) = A_Routine(line_no, (yyvsp[(1) - (2)].routine_head), (yyvsp[(2) - (2)].routine_body));
;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 208 "pascal.y"
    {
    (yyval.sub_routine) = A_SubRoutine(line_no, (yyvsp[(1) - (2)].routine_head), (yyvsp[(2) - (2)].routine_body));
;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 213 "pascal.y"
    {
    (yyval.routine_head) = A_RoutineHead(line_no, (yyvsp[(1) - (5)].label_part), (yyvsp[(2) - (5)].const_part), (yyvsp[(3) - (5)].type_part), (yyvsp[(4) - (5)].var_part), (yyvsp[(5) - (5)].routine_part));
;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 218 "pascal.y"
    {
    (yyval.label_part) = A_LabelPart(line_no);
;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 223 "pascal.y"
    {
    (yyval.const_part) = A_ConstPart(line_no, (yyvsp[(2) - (2)].const_expr_list));
;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 226 "pascal.y"
    {
    (yyval.const_part) = A_ConstPart(line_no, NULL);
 ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 231 "pascal.y"
    {
    // $$ = A_ConstExprListSeq(line_no, $1, $2, $4);
    (yyval.const_expr_list) = A_ConstExprListSeq(line_no, (yyvsp[(1) - (5)].const_expr_list), S_Symbol((yyvsp[(2) - (5)].sval)), (yyvsp[(4) - (5)].const_value));
;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 235 "pascal.y"
    {
    (yyval.const_expr_list) = A_ConstExprList(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].const_value));
;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 240 "pascal.y"
    {
    (yyval.const_value) = A_ConstValueInteger(line_no, (yyvsp[(1) - (1)].ival));
;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 243 "pascal.y"
    {
    (yyval.const_value) = A_ConstValueReal(line_no, (yyvsp[(1) - (1)].dval));
;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 246 "pascal.y"
    {
    (yyval.const_value) = A_ConstValueChar(line_no, (yyvsp[(1) - (1)].sval));
;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 249 "pascal.y"
    {
    (yyval.const_value) = A_ConstValueString(line_no, (yyvsp[(1) - (1)].sval));
;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 252 "pascal.y"
    {
    (yyval.const_value) = A_ConstValueSysCon(line_no, (yyvsp[(1) - (1)].sys_con));
;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 257 "pascal.y"
    {
    (yyval.type_part) = A_TypePart(line_no, (yyvsp[(2) - (2)].type_decl_list));
;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 260 "pascal.y"
    {
    (yyval.type_part) = A_TypePart(line_no, NULL);
;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 265 "pascal.y"
    {
    (yyval.type_decl_list) = A_TypeDeclListSeq(line_no, (yyvsp[(1) - (2)].type_decl_list), (yyvsp[(2) - (2)].type_definition));
;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 268 "pascal.y"
    {
    (yyval.type_decl_list) = A_TypeDeclList(line_no, (yyvsp[(1) - (1)].type_definition));
;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 273 "pascal.y"
    {
    // $$ = A_TypeDefinition(line_no, $1, $3);
    (yyval.type_definition) = A_TypeDefinition(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].type_decl));
;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 279 "pascal.y"
    {
    (yyval.type_decl) = A_TypeDeclSimple(line_no, (yyvsp[(1) - (1)].simple_type_decl));
;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 282 "pascal.y"
    {
    (yyval.type_decl) = A_TypeDeclArray(line_no, (yyvsp[(1) - (1)].array_type_decl));
;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 285 "pascal.y"
    {
    (yyval.type_decl) = A_TypeDeclRecord(line_no, (yyvsp[(1) - (1)].record_type_decl));
;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 290 "pascal.y"
    {
    (yyval.simple_type_decl) = A_SimpleTypeDeclSysType(line_no, (yyvsp[(1) - (1)].sys_type));
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 293 "pascal.y"
    {
    // $$ = A_SimpleTypeDeclId(line_no, $1);
    (yyval.simple_type_decl) = A_SimpleTypeDeclId(line_no, S_Symbol((yyvsp[(1) - (1)].sval)));
;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 297 "pascal.y"
    {
    (yyval.simple_type_decl) = A_SimpleTypeDeclNameList(line_no, (yyvsp[(2) - (3)].name_list));
;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 300 "pascal.y"
    {
    (yyval.simple_type_decl) = A_SimpleTypeDeclRangeConst(line_no, (yyvsp[(1) - (3)].const_value), (yyvsp[(3) - (3)].const_value));
;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 303 "pascal.y"
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

  case 30:

/* Line 1455 of yacc.c  */
#line 313 "pascal.y"
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

  case 31:

/* Line 1455 of yacc.c  */
#line 325 "pascal.y"
    {
    //  $$ = A_SimpleTypeDeclIdRangeId(line_no, $1, $3);
    (yyval.simple_type_decl) = A_SimpleTypeDeclRangeId(line_no, S_Symbol((yyvsp[(1) - (3)].sval)), S_Symbol((yyvsp[(3) - (3)].sval)));
;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 331 "pascal.y"
    {
    (yyval.array_type_decl) = A_ArrayTypeDecl(line_no, (yyvsp[(3) - (6)].simple_type_decl), (yyvsp[(6) - (6)].type_decl));
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 336 "pascal.y"
    {
    (yyval.record_type_decl) = A_RecordTypeDecl(line_no, (yyvsp[(2) - (3)].field_decl_list));
;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 341 "pascal.y"
    {
    (yyval.field_decl_list) = A_FieldDeclListSeq(line_no, (yyvsp[(1) - (2)].field_decl_list), (yyvsp[(2) - (2)].field_decl));
;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 344 "pascal.y"
    {
    (yyval.field_decl_list) = A_FieldDeclList(line_no, (yyvsp[(1) - (1)].field_decl));
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 349 "pascal.y"
    {
    (yyval.field_decl) = A_FieldDecl(line_no, (yyvsp[(1) - (4)].name_list), (yyvsp[(3) - (4)].type_decl));
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 354 "pascal.y"
    {
    // $$ = A_NameListSeq(line_no, $1, $3);
    (yyval.name_list) = A_NameListSeq(line_no, (yyvsp[(1) - (3)].name_list), S_Symbol((yyvsp[(3) - (3)].sval)));
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 358 "pascal.y"
    {
    // $$ = A_NameList(line_no, $1);
    (yyval.name_list) = A_NameList(line_no, S_Symbol((yyvsp[(1) - (1)].sval)));
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 364 "pascal.y"
    {
    (yyval.var_part) = A_VarPart(line_no, (yyvsp[(2) - (2)].var_decl_list));
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 367 "pascal.y"
    {
    (yyval.var_part) = A_VarPart(line_no, NULL);
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 372 "pascal.y"
    {
    (yyval.var_decl_list) = A_VarDeclListSeq(line_no, (yyvsp[(1) - (2)].var_decl_list), (yyvsp[(2) - (2)].var_decl));
;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 375 "pascal.y"
    {
    (yyval.var_decl_list) = A_VarDeclList(line_no, (yyvsp[(1) - (1)].var_decl));
;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 380 "pascal.y"
    {
    (yyval.var_decl) = A_VarDecl(line_no, (yyvsp[(1) - (4)].name_list), (yyvsp[(3) - (4)].type_decl));
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 385 "pascal.y"
    {
    (yyval.routine_part) = A_RoutinePartSeqWithFunctionDecl(line_no, (yyvsp[(1) - (2)].routine_part), (yyvsp[(2) - (2)].function_decl));
;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 388 "pascal.y"
    {
    (yyval.routine_part) = A_RoutinePartSeqWithProcedureDecl(line_no, (yyvsp[(1) - (2)].routine_part), (yyvsp[(2) - (2)].procedure_decl));
;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 391 "pascal.y"
    {
    (yyval.routine_part) = A_RoutinePartWithFunctionDecl(line_no, (yyvsp[(1) - (1)].function_decl));
;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 394 "pascal.y"
    {
    (yyval.routine_part) = A_RoutinePartWithProcedureDecl(line_no, (yyvsp[(1) - (1)].procedure_decl));
;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 397 "pascal.y"
    {
    (yyval.routine_part) = NULL;
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 402 "pascal.y"
    {
    (yyval.function_decl) = A_FunctionDecl(line_no, (yyvsp[(1) - (4)].function_head), (yyvsp[(3) - (4)].sub_routine));
;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 407 "pascal.y"
    {
    (yyval.function_head) = A_FunctionHead(line_no, S_Symbol((yyvsp[(2) - (5)].sval)), (yyvsp[(3) - (5)].parameters), (yyvsp[(5) - (5)].simple_type_decl));
;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 412 "pascal.y"
    {
    (yyval.procedure_decl) = A_ProcedureDecl(line_no, (yyvsp[(1) - (4)].procedure_head), (yyvsp[(3) - (4)].sub_routine));
;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 417 "pascal.y"
    {
    //$$ = A_ProcedureHead(line_no, $2, $3);
    (yyval.procedure_head) = A_ProcedureHead(line_no, S_Symbol((yyvsp[(2) - (3)].sval)), (yyvsp[(3) - (3)].parameters));
;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 423 "pascal.y"
    {
    (yyval.parameters) = A_Parameters(line_no, (yyvsp[(2) - (3)].para_decl_list));
;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 426 "pascal.y"
    {
    (yyval.parameters) = NULL;
;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 431 "pascal.y"
    {
    (yyval.para_decl_list) = A_ParaDeclListSeq(line_no, (yyvsp[(1) - (3)].para_decl_list), (yyvsp[(3) - (3)].para_type_list));
;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 434 "pascal.y"
    {
    (yyval.para_decl_list) = A_ParaDeclList(line_no, (yyvsp[(1) - (1)].para_type_list));
;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 440 "pascal.y"
    {
    (yyval.para_type_list) = A_ParaTypeListVar(line_no, (yyvsp[(1) - (3)].var_para_list), (yyvsp[(3) - (3)].simple_type_decl));
;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 443 "pascal.y"
    {
    (yyval.para_type_list) = A_ParaTypeListVal(line_no, (yyvsp[(1) - (3)].val_para_list), (yyvsp[(3) - (3)].simple_type_decl));
;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 448 "pascal.y"
    {
    (yyval.var_para_list) = A_VarParaList(line_no, (yyvsp[(2) - (2)].name_list));
;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 453 "pascal.y"
    {
    (yyval.val_para_list) = A_ValParaList(line_no, (yyvsp[(1) - (1)].name_list));
;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 458 "pascal.y"
    {
    (yyval.routine_body) = A_RoutineBody(line_no, (yyvsp[(1) - (1)].compound_stmt));
;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 463 "pascal.y"
    {
    (yyval.compound_stmt) = A_CompoundStmt(line_no, (yyvsp[(2) - (3)].stmt_list));
;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 468 "pascal.y"
    {
    (yyval.stmt_list) = A_StmtList(line_no, (yyvsp[(1) - (3)].stmt_list), (yyvsp[(2) - (3)].stmt));
;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 471 "pascal.y"
    {
    (yyval.stmt_list) = NULL;
;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 476 "pascal.y"
    {
    (yyval.stmt) = A_StmtLabel(line_no, (yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].non_label_stmt));
;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 479 "pascal.y"
    {
    (yyval.stmt) = A_StmtNonLabel(line_no, (yyvsp[(1) - (1)].non_label_stmt));
;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 484 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtAssign(line_no, (yyvsp[(1) - (1)].assign_stmt));
;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 487 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtProc(line_no, (yyvsp[(1) - (1)].proc_stmt));
;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 490 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtCompound(line_no, (yyvsp[(1) - (1)].compound_stmt));
;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 493 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtIf(line_no, (yyvsp[(1) - (1)].if_stmt));
;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 496 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtRepeat(line_no, (yyvsp[(1) - (1)].repeat_stmt));
;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 499 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtWhile(line_no, (yyvsp[(1) - (1)].while_stmt));
;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 502 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtFor(line_no, (yyvsp[(1) - (1)].for_stmt));
;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 505 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtCase(line_no, (yyvsp[(1) - (1)].case_stmt));
;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 508 "pascal.y"
    {
    (yyval.non_label_stmt) = A_NonLabelStmtGoto(line_no, (yyvsp[(1) - (1)].goto_stmt));
;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 513 "pascal.y"
    {
    //$$ = A_AssignStmtSimple(line_no, $1, $3);
    (yyval.assign_stmt) = A_AssignStmtSimple(line_no, S_Symbol((yyvsp[(1) - (3)].sval)), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 517 "pascal.y"
    {
    //$$ = A_AssignStmtArray(line_no, $1, $3, $6);
    (yyval.assign_stmt) = A_AssignStmtArray(line_no, S_Symbol((yyvsp[(1) - (6)].sval)), (yyvsp[(3) - (6)].expression), (yyvsp[(6) - (6)].expression));
;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 521 "pascal.y"
    {
    //$$ = A_AssignStmtRecord(line_no, $1, $3, $5);
    (yyval.assign_stmt) = A_AssignStmtRecord(line_no, S_Symbol((yyvsp[(1) - (5)].sval)), S_Symbol((yyvsp[(3) - (5)].sval)), (yyvsp[(5) - (5)].expression));
;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 527 "pascal.y"
    {
    // $$ = A_ProcStmtID(line_no, $1);
    (yyval.proc_stmt) = A_ProcStmtID(line_no, S_Symbol((yyvsp[(1) - (1)].sval)));
;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 531 "pascal.y"
    {
    (yyval.proc_stmt) = A_ProcStmtIDWithArgs(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].args_list));
;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 534 "pascal.y"
    {
    (yyval.proc_stmt) = A_ProcStmtSysProc(line_no, (yyvsp[(1) - (1)].sys_proc));
;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 537 "pascal.y"
    {
    (yyval.proc_stmt) = A_ProcStmtSysProcWithArgs(line_no, (yyvsp[(1) - (4)].sys_proc), (yyvsp[(3) - (4)].expression_list));
;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 540 "pascal.y"
    {
    (yyval.proc_stmt) = A_ProcStmtRead(line_no, (yyvsp[(3) - (4)].factor));
;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 545 "pascal.y"
    {
    (yyval.if_stmt) = A_IfStmt(line_no, (yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].stmt), (yyvsp[(5) - (5)].else_clause));
;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 550 "pascal.y"
    {
    (yyval.else_clause) = A_ElseClause(line_no, (yyvsp[(2) - (2)].stmt));
;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 552 "pascal.y"
    {
    (yyval.else_clause) = A_ElseClause(line_no, NULL);
;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 558 "pascal.y"
    {
    (yyval.repeat_stmt) = A_RepeatStmt(line_no, (yyvsp[(2) - (4)].stmt_list), (yyvsp[(4) - (4)].expression));
;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 563 "pascal.y"
    {
    (yyval.while_stmt) = A_WhileStmt(line_no, (yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].stmt));
;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 568 "pascal.y"
    {
    (yyval.for_stmt) = A_ForStmt(line_no, S_Symbol((yyvsp[(2) - (8)].sval)), (yyvsp[(4) - (8)].expression), (yyvsp[(5) - (8)].direction), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].stmt));
;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 573 "pascal.y"
    {
    (yyval.direction) = (yyvsp[(1) - (1)].direction);
;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 576 "pascal.y"
    {
    (yyval.direction) = (yyvsp[(1) - (1)].direction);
;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 581 "pascal.y"
    {
    (yyval.case_stmt) = A_CaseStmt(line_no, (yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].case_expr_list));
;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 586 "pascal.y"
    {
    (yyval.case_expr_list) = A_CaseExprListSeq(line_no, (yyvsp[(1) - (2)].case_expr_list), (yyvsp[(2) - (2)].case_expr));
;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 589 "pascal.y"
    {
    (yyval.case_expr_list) = A_CaseExprList(line_no, (yyvsp[(1) - (1)].case_expr));
;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 594 "pascal.y"
    {
    (yyval.case_expr) = A_CaseExprConst(line_no, (yyvsp[(1) - (4)].const_value), (yyvsp[(3) - (4)].stmt));
;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 597 "pascal.y"
    {
    //$$ = A_CaseExprNonConst(line_no, $1, $3);
    (yyval.case_expr) = A_CaseExprNonConst(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].stmt));
;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 603 "pascal.y"
    {
    (yyval.goto_stmt) = A_GotoStmt(line_no, (yyvsp[(2) - (2)].ival));
;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 608 "pascal.y"
    {
    (yyval.expression_list) = A_ExpressionListSeq(line_no, (yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 611 "pascal.y"
    {
    (yyval.expression_list) = A_ExpressionList(line_no, (yyvsp[(1) - (1)].expression));
;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 616 "pascal.y"
    {
    (yyval.expression) = A_ExpressionBin(line_no, (yyvsp[(1) - (3)].expression), OP_GE, (yyvsp[(3) - (3)].expr));
;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 619 "pascal.y"
    {
    (yyval.expression) = A_ExpressionBin(line_no, (yyvsp[(1) - (3)].expression), OP_GT, (yyvsp[(3) - (3)].expr));
;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 622 "pascal.y"
    {
    (yyval.expression) = A_ExpressionBin(line_no, (yyvsp[(1) - (3)].expression), OP_LE, (yyvsp[(3) - (3)].expr));
;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 625 "pascal.y"
    {
    (yyval.expression) = A_ExpressionBin(line_no, (yyvsp[(1) - (3)].expression), OP_LT, (yyvsp[(3) - (3)].expr));
;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 628 "pascal.y"
    {
    (yyval.expression) = A_ExpressionBin(line_no, (yyvsp[(1) - (3)].expression), OP_EQUAL, (yyvsp[(3) - (3)].expr));
;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 631 "pascal.y"
    {
    (yyval.expression) = A_ExpressionBin(line_no, (yyvsp[(1) - (3)].expression), OP_UNEQUAL, (yyvsp[(3) - (3)].expr));
;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 634 "pascal.y"
    {
    (yyval.expression) = A_ExpressionUn(line_no, (yyvsp[(1) - (1)].expr));
;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 639 "pascal.y"
    {
    (yyval.expr) = A_ExprBin(line_no, (yyvsp[(1) - (3)].expr), OP_PLUS, (yyvsp[(3) - (3)].term));
;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 642 "pascal.y"
    {
    (yyval.expr) = A_ExprBin(line_no, (yyvsp[(1) - (3)].expr), OP_MINUS, (yyvsp[(3) - (3)].term));
;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 645 "pascal.y"
    {
    (yyval.expr) = A_ExprBin(line_no, (yyvsp[(1) - (3)].expr), OP_OR, (yyvsp[(3) - (3)].term));
;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 648 "pascal.y"
    {
    (yyval.expr) = A_ExprUn(line_no, (yyvsp[(1) - (1)].term));
;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 653 "pascal.y"
    {
    (yyval.term) = A_TermBin(line_no, (yyvsp[(1) - (3)].term), OP_MUL, (yyvsp[(3) - (3)].factor));
;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 656 "pascal.y"
    {
    (yyval.term) = A_TermBin(line_no, (yyvsp[(1) - (3)].term), OP_DIV, (yyvsp[(3) - (3)].factor));
;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 659 "pascal.y"
    {
    (yyval.term) = A_TermBin(line_no, (yyvsp[(1) - (3)].term), OP_MOD, (yyvsp[(3) - (3)].factor));
;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 662 "pascal.y"
    {
    (yyval.term) = A_TermBin(line_no, (yyvsp[(1) - (3)].term), OP_AND, (yyvsp[(3) - (3)].factor));
;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 665 "pascal.y"
    {
    (yyval.term) = A_TermUn(line_no, (yyvsp[(1) - (1)].factor));
;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 670 "pascal.y"
    {
    //$$ = A_FactorId(line_no, $1);
    (yyval.factor) = A_FactorId(line_no, S_Symbol((yyvsp[(1) - (1)].sval)));
;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 674 "pascal.y"
    {
    //$$ = A_FactorIdWithArgs(line_no, $1, $3);
    (yyval.factor) = A_FactorIdWithArgs(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].args_list));
;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 678 "pascal.y"
    {
    (yyval.factor) = A_FactorSysFunct(line_no, (yyvsp[(1) - (1)].sys_funct));
;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 681 "pascal.y"
    {
    (yyval.factor) = A_FactorSysFunctWithArgs(line_no, (yyvsp[(1) - (4)].sys_funct), (yyvsp[(3) - (4)].args_list));
;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 684 "pascal.y"
    {
    (yyval.factor) = A_FactorConst(line_no, (yyvsp[(1) - (1)].const_value));
;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 687 "pascal.y"
    {
    (yyval.factor) = A_FactorInBrackets(line_no, (yyvsp[(2) - (3)].expression));
;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 690 "pascal.y"
    {
    (yyval.factor) = A_FactorUnOp(line_no, OP_NOT, (yyvsp[(2) - (2)].factor));
;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 693 "pascal.y"
    {
    (yyval.factor) = A_FactorUnOp(line_no, OP_NEG, (yyvsp[(2) - (2)].factor));
;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 696 "pascal.y"
    {
    //$$ = A_FactorArrayVar(line_no, $1, $3);
    (yyval.factor) = A_FactorArrayVar(line_no, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].expression));
;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 700 "pascal.y"
    {
    //$$ = A_FactorRecordVar(line_no, $1, $3);
    (yyval.factor) = A_FactorRecordVar(line_no, S_Symbol((yyvsp[(1) - (3)].sval)), S_Symbol((yyvsp[(3) - (3)].sval)));
;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 706 "pascal.y"
    {
    (yyval.args_list) = A_ArgsListSeq(line_no, (yyvsp[(1) - (3)].args_list), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 709 "pascal.y"
    {
    (yyval.args_list) = A_ArgsList(line_no, (yyvsp[(1) - (1)].expression));
;}
    break;



/* Line 1455 of yacc.c  */
#line 2900 "pascal.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 715 "pascal.y"

   
void yyerror(const char *s)
{
	printf("%s | line: %d.\n", s, line_no);					//out error information
}
