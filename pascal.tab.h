/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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

/* Tokens.  */
#include "absyn.h"
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "pascal.y"
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
/* Line 1529 of yacc.c.  */
#line 250 "pascal.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

