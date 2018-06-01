%{

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

%}

%union
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

%token  <sval> ID

%token  <ival> INTEGER
%token  <dval> REAL
%token  <sval> CHAR
%token  <sval> STRING

%token  PROGRAM
%token  CONST
%token  ARRAY  RECORD
%token  BEGINN  END
%token  VAR  FUNCTION  PROCEDURE
%token  TYPE  READ 
%token  IF  THEN  ELSE
%token  REPEAT  UNTIL  WHILE  DO  FOR
%token  CASE  OF  GOTO
%token  DOT  DOTDOT  SEMI  COLON  COMMA
%token  LB  RB  LP  RP
%token  ASSIGN

%token  <un_op> NOT NEG
%token  <rel_op> EQUAL  UNEQUAL  GE  GT  LE  LT
%token  <plus_op> PLUS  MINUS  OR
%token  <mul_op> MUL  DIV  MOD  AND

%token  <direction> TO  DOWNTO

%token  <sys_type> SYS_TYPE
%token  <sys_funct> SYS_FUNCT
%token  <sys_proc> SYS_PROC
%token  <sys_con> SYS_CON

%type   <program> program
%type   <program_head> program_head
%type   <routine> routine
%type   <routine_head> routine_head
%type   <routine_body> routine_body
%type   <sub_routine> sub_routine
%type   <label_part> label_part
%type   <const_part> const_part
%type   <type_part> type_part
%type   <var_part> var_part
%type   <routine_part> routine_part
%type   <const_expr_list> const_expr_list
%type   <const_value> const_value
%type   <type_decl_list> type_decl_list
%type   <type_definition> type_definition
%type   <type_decl> type_decl
%type   <simple_type_decl> simple_type_decl
%type   <array_type_decl> array_type_decl
%type   <record_type_decl> record_type_decl
%type   <name_list> name_list
%type   <field_decl_list> field_decl_list
%type   <field_decl> field_decl
%type   <var_decl_list> var_decl_list
%type   <var_decl> var_decl
%type   <function_decl> function_decl
%type   <procedure_decl> procedure_decl
%type   <function_head> function_head
%type   <procedure_head> procedure_head
%type   <parameters> parameters
%type   <para_decl_list> para_decl_list
%type   <para_type_list> para_type_list
%type   <var_para_list> var_para_list
%type   <val_para_list> val_para_list
%type   <compound_stmt> compound_stmt
%type   <stmt_list> stmt_list
%type   <stmt> stmt
%type   <non_label_stmt> non_label_stmt
%type   <assign_stmt> assign_stmt
%type   <proc_stmt> proc_stmt
%type   <if_stmt> if_stmt
%type   <repeat_stmt> repeat_stmt
%type   <while_stmt> while_stmt
%type   <for_stmt> for_stmt
%type   <case_stmt> case_stmt
%type   <goto_stmt> goto_stmt
%type   <expression> expression
%type   <args_list> args_list
%type   <expression_list> expression_list
%type   <else_clause> else_clause
%type   <direction> direction
%type   <case_expr_list> case_expr_list
%type   <case_expr> case_expr
%type   <expr> expr
%type   <term> term
%type   <factor> factor

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%nonassoc PREC_SHIFT_ROUT_PROC
%nonassoc PREC_SHIFT_ROUT_FUNC

%%

program :           program_head  routine  DOT {
    $$ = A_Program(line_no, $1, $2);
    root = $$;
}
;

program_head :      PROGRAM  ID  SEMI {
    $$ = A_ProgramHead(line_no, $2);
}
;

routine :           routine_head  routine_body {
    $$ = A_Routine(line_no, $1, $2);
}
;

sub_routine :       routine_head  routine_body {
    $$ = A_SubRoutine(line_no, $1, $2);
}
;

routine_head :      label_part  const_part  type_part  var_part  routine_part {
    $$ = A_RoutineHead(line_no, $1, $2, $3, $4, $5);
}
;

label_part :    {
    $$ = A_LabelPart(line_no);
}
;

const_part :        CONST  const_expr_list {
    $$ = A_ConstPart(line_no, $2);
}
            |   {
    $$ = A_ConstPart(line_no, NULL);
 }
;

const_expr_list :   const_expr_list  ID  EQUAL  const_value  SEMI {
    // $$ = A_ConstExprListSeq(line_no, $1, $2, $4);
    $$ = A_ConstExprListSeq(line_no, $1, S_Symbol($2), $4);
}
                |   ID  EQUAL  const_value  SEMI {
    $$ = A_ConstExprList(line_no, S_Symbol($1), $3);
}
;

const_value :       INTEGER {
    $$ = A_ConstValueInteger(line_no, $1);
}
                |   REAL {
    $$ = A_ConstValueReal(line_no, $1);
}
                |   CHAR {
    $$ = A_ConstValueChar(line_no, $1);
}
                |   STRING {
    $$ = A_ConstValueString(line_no, $1);
}
                |   SYS_CON {
    $$ = A_ConstValueSysCon(line_no, $1);
}
;

type_part :         TYPE type_decl_list {
    $$ = A_TypePart(line_no, $2);
}
                |   {
    $$ = A_TypePart(line_no, NULL);
}
;

type_decl_list :    type_decl_list  type_definition {
    $$ = A_TypeDeclListSeq(line_no, $1, $2);
}
                |   type_definition {
    $$ = A_TypeDeclList(line_no, $1);
}
;

type_definition :   ID  EQUAL  type_decl  SEMI {
    // $$ = A_TypeDefinition(line_no, $1, $3);
    $$ = A_TypeDefinition(line_no, S_Symbol($1), $3);
}
;

type_decl :         simple_type_decl {
    $$ = A_TypeDeclSimple(line_no, $1);
}
                |   array_type_decl {
    $$ = A_TypeDeclArray(line_no, $1);
}
                |   record_type_decl {
    $$ = A_TypeDeclRecord(line_no, $1);
}
;

simple_type_decl :  SYS_TYPE {
    $$ = A_SimpleTypeDeclSysType(line_no, $1);
}
                |   ID {
    // $$ = A_SimpleTypeDeclId(line_no, $1);
    $$ = A_SimpleTypeDeclId(line_no, S_Symbol($1));
}
                |   LP  name_list  RP {
    $$ = A_SimpleTypeDeclNameList(line_no, $2);
}
                |   const_value  DOTDOT  const_value {
    $$ = A_SimpleTypeDeclRangeConst(line_no, $1, $3);
}
                |   MINUS  const_value  DOTDOT  const_value {
    A_const_value from = NULL;
    if ($2->kind == INTEGER) {
        from = A_ConstValueInteger(line_no, -($2->u.intt));
    }
    else if ($2->kind == REAL) {
        from = A_ConstValueReal(line_no, -($2->u.real));
    }
    $$ = A_SimpleTypeDeclRangeConst(line_no, from, $4);
}
                |   MINUS  const_value  DOTDOT  MINUS  const_value {
    A_const_value from = NULL, to = NULL;
    if ($2->kind == INTEGER) {
        from = A_ConstValueInteger(line_no, -($2->u.intt));
        to = A_ConstValueInteger(line_no, -($2->u.intt));
    }
    else if ($2->kind == REAL) {
        from = A_ConstValueReal(line_no, -($5->u.real));
        to = A_ConstValueReal(line_no, -($5->u.real));
    }
    $$ = A_SimpleTypeDeclRangeConst(line_no, from, to);
}
                |   ID  DOTDOT  ID {
    //  $$ = A_SimpleTypeDeclIdRangeId(line_no, $1, $3);
    $$ = A_SimpleTypeDeclRangeId(line_no, S_Symbol($1), S_Symbol($3));
}
;

array_type_decl :   ARRAY  LB  simple_type_decl  RB  OF  type_decl {
    $$ = A_ArrayTypeDecl(line_no, $3, $6);
}
;

record_type_decl :  RECORD  field_decl_list  END {
    $$ = A_RecordTypeDecl(line_no, $2);
}
;

field_decl_list :   field_decl_list  field_decl {
    $$ = A_FieldDeclListSeq(line_no, $1, $2);
}
                |   field_decl {
    $$ = A_FieldDeclList(line_no, $1);
}
;

field_decl :        name_list  COLON  type_decl  SEMI {
    $$ = A_FieldDecl(line_no, $1, $3);
}
;

name_list :         name_list  COMMA  ID {
    // $$ = A_NameListSeq(line_no, $1, $3);
    $$ = A_NameListSeq(line_no, $1, S_Symbol($3));
}
                |   ID {
    // $$ = A_NameList(line_no, $1);
    $$ = A_NameList(line_no, S_Symbol($1));
}
;

var_part :          VAR  var_decl_list {
    $$ = A_VarPart(line_no, $2);
}
                |   {
    $$ = A_VarPart(line_no, NULL);
}
;

var_decl_list :     var_decl_list  var_decl {
    $$ = A_VarDeclListSeq(line_no, $1, $2);
}
                |   var_decl {
    $$ = A_VarDeclList(line_no, $1);
}
;

var_decl :          name_list  COLON  type_decl  SEMI {
    $$ = A_VarDecl(line_no, $1, $3);
}
;

routine_part :      routine_part  function_decl {
    $$ = A_RoutinePartSeqWithFunctionDecl(line_no, $1, $2);
}
                |   routine_part  procedure_decl {
    $$ = A_RoutinePartSeqWithProcedureDecl(line_no, $1, $2);
}
                |   function_decl {
    $$ = A_RoutinePartWithFunctionDecl(line_no, $1);
}
                |   procedure_decl {
    $$ = A_RoutinePartWithProcedureDecl(line_no, $1);
}
                |   {
    $$ = NULL;
}
;

function_decl :     function_head  SEMI  sub_routine  SEMI {
    $$ = A_FunctionDecl(line_no, $1, $3);
}
;

function_head :     FUNCTION  ID  parameters  COLON  simple_type_decl {
    $$ = A_FunctionHead(line_no, S_Symbol($2), $3, $5);
}
;

procedure_decl :    procedure_head  SEMI  sub_routine  SEMI {
    $$ = A_ProcedureDecl(line_no, $1, $3);
}
;

procedure_head :    PROCEDURE ID parameters {
    //$$ = A_ProcedureHead(line_no, $2, $3);
    $$ = A_ProcedureHead(line_no, S_Symbol($2), $3);
}
;

parameters :        LP  para_decl_list  RP {
    $$ = A_Parameters(line_no, $2);
}
                |   {
    $$ = NULL;
}
;

para_decl_list :    para_decl_list  SEMI  para_type_list {
    $$ = A_ParaDeclListSeq(line_no, $1, $3);
}
                |   para_type_list {
    $$ = A_ParaDeclList(line_no, $1);
}
;


para_type_list :    var_para_list  COLON  simple_type_decl {
    $$ = A_ParaTypeListVar(line_no, $1, $3);
}
                |   val_para_list  COLON  simple_type_decl {
    $$ = A_ParaTypeListVal(line_no, $1, $3);
}
;

var_para_list :     VAR  name_list {
    $$ = A_VarParaList(line_no, $2);
}
;

val_para_list :     name_list {
    $$ = A_ValParaList(line_no, $1);
}
;

routine_body :      compound_stmt {
    $$ = A_RoutineBody(line_no, $1);
}
;

compound_stmt :     BEGINN  stmt_list  END {
    $$ = A_CompoundStmt(line_no, $2);
}
;

stmt_list :         stmt_list  stmt  SEMI {
    $$ = A_StmtList(line_no, $1, $2);
}
                |   {
    $$ = NULL;
}
;

stmt :              INTEGER  COLON  non_label_stmt {
    $$ = A_StmtLabel(line_no, $1, $3);
}
                |   non_label_stmt {
    $$ = A_StmtNonLabel(line_no, $1);
}
;

non_label_stmt :    assign_stmt {
    $$ = A_NonLabelStmtAssign(line_no, $1);
}
                |   proc_stmt {
    $$ = A_NonLabelStmtProc(line_no, $1);
}
                |   compound_stmt {
    $$ = A_NonLabelStmtCompound(line_no, $1);
}
                |   if_stmt {
    $$ = A_NonLabelStmtIf(line_no, $1);
}
                |   repeat_stmt {
    $$ = A_NonLabelStmtRepeat(line_no, $1);
}
                |   while_stmt {
    $$ = A_NonLabelStmtWhile(line_no, $1);
}
                |   for_stmt {
    $$ = A_NonLabelStmtFor(line_no, $1);
}
                |   case_stmt {
    $$ = A_NonLabelStmtCase(line_no, $1);
}
                |   goto_stmt {
    $$ = A_NonLabelStmtGoto(line_no, $1);
}
;

assign_stmt :       ID  ASSIGN  expression {
    //$$ = A_AssignStmtSimple(line_no, $1, $3);
    $$ = A_AssignStmtSimple(line_no, S_Symbol($1), $3);
}
                |   ID  LB  expression  RB  ASSIGN  expression {
    //$$ = A_AssignStmtArray(line_no, $1, $3, $6);
    $$ = A_AssignStmtArray(line_no, S_Symbol($1), $3, $6);
}
                |   ID  DOT  ID  ASSIGN  expression {
    //$$ = A_AssignStmtRecord(line_no, $1, $3, $5);
    $$ = A_AssignStmtRecord(line_no, S_Symbol($1), S_Symbol($3), $5);
}
;

proc_stmt :         ID {
    // $$ = A_ProcStmtID(line_no, $1);
    $$ = A_ProcStmtID(line_no, S_Symbol($1));
}
                |   ID  LP  args_list  RP {
    $$ = A_ProcStmtIDWithArgs(line_no, S_Symbol($1), $3);
}
                |   SYS_PROC {
    $$ = A_ProcStmtSysProc(line_no, $1);
}
                |   SYS_PROC  LP  expression_list  RP {
    $$ = A_ProcStmtSysProcWithArgs(line_no, $1, $3);
}
                |   READ  LP  factor  RP {
    $$ = A_ProcStmtRead(line_no, $3);
}
;

if_stmt :           IF  expression  THEN  stmt  else_clause {
    $$ = A_IfStmt(line_no, $2, $4, $5);
}
;

else_clause :       ELSE stmt {
    $$ = A_ElseClause(line_no, $2);
}               |   %prec LOWER_THAN_ELSE {
    $$ = A_ElseClause(line_no, NULL);
}
;


repeat_stmt :       REPEAT  stmt_list  UNTIL  expression {
    $$ = A_RepeatStmt(line_no, $2, $4);
}
;

while_stmt :        WHILE  expression  DO stmt {
    $$ = A_WhileStmt(line_no, $2, $4);
}
;

for_stmt :          FOR  ID  ASSIGN  expression  direction  expression  DO stmt {
    $$ = A_ForStmt(line_no, S_Symbol($2), $4, $5, $6, $8);
}
;

direction :         TO {
    $$ = DIRECTION_TO;
}
                |   DOWNTO {
    $$ = DIRECTION_DOWNTO;
}
;

case_stmt :         CASE  expression  OF  case_expr_list  END {
    $$ = A_CaseStmt(line_no, $2, $4);
}
;

case_expr_list :    case_expr_list  case_expr {
    $$ = A_CaseExprListSeq(line_no, $1, $2);
}
                |   case_expr {
    $$ = A_CaseExprList(line_no, $1);
}
;

case_expr :         const_value  COLON  stmt  SEMI {
    $$ = A_CaseExprConst(line_no, $1, $3);
}
                |   ID  COLON  stmt  SEMI {
    //$$ = A_CaseExprNonConst(line_no, $1, $3);
    $$ = A_CaseExprNonConst(line_no, S_Symbol($1), $3);
}
;

goto_stmt :         GOTO  INTEGER {
    $$ = A_GotoStmt(line_no, $2);
}
;

expression_list :   expression_list  COMMA  expression {
    $$ = A_ExpressionListSeq(line_no, $1, $3);
}
                |   expression {
    $$ = A_ExpressionList(line_no, $1);
}
;

expression :        expression  GE  expr {
    $$ = A_ExpressionBin(line_no, $1, OP_GE, $3);
}
                |   expression  GT  expr {
    $$ = A_ExpressionBin(line_no, $1, OP_GT, $3);
}
                |   expression  LE  expr {
    $$ = A_ExpressionBin(line_no, $1, OP_LE, $3);
}
                |   expression  LT  expr {
    $$ = A_ExpressionBin(line_no, $1, OP_LT, $3);
}
                |   expression  EQUAL  expr {
    $$ = A_ExpressionBin(line_no, $1, OP_EQUAL, $3);
}
                |   expression  UNEQUAL  expr {
    $$ = A_ExpressionBin(line_no, $1, OP_UNEQUAL, $3);
}
                |   expr {
    $$ = A_ExpressionUn(line_no, $1);
}
;

expr :              expr  PLUS  term {
    $$ = A_ExprBin(line_no, $1, OP_PLUS, $3);
}
                |   expr  MINUS  term {
    $$ = A_ExprBin(line_no, $1, OP_MINUS, $3);
}
                |   expr  OR  term {
    $$ = A_ExprBin(line_no, $1, OP_OR, $3);
}
                |   term {
    $$ = A_ExprUn(line_no, $1);
}
;

term :              term  MUL  factor {
    $$ = A_TermBin(line_no, $1, OP_MUL, $3);
}
                |   term  DIV  factor {
    $$ = A_TermBin(line_no, $1, OP_DIV, $3);
}
                |   term  MOD  factor {
    $$ = A_TermBin(line_no, $1, OP_MOD, $3);
}
                |   term  AND  factor {
    $$ = A_TermBin(line_no, $1, OP_AND, $3);
}
                |   factor {
    $$ = A_TermUn(line_no, $1);
}
;

factor :            ID {
    $$ = A_FactorId(line_no, S_Symbol($1));
}
                |   ID  LP  args_list  RP {
    $$ = A_FactorIdWithArgs(line_no, S_Symbol($1), $3);
}
                |   SYS_FUNCT {
    $$ = A_FactorSysFunct(line_no, $1);
}
                |   SYS_FUNCT  LP  args_list  RP {
    $$ = A_FactorSysFunctWithArgs(line_no, $1, $3);
}
                |   const_value {
    $$ = A_FactorConst(line_no, $1);
}
                |   LP  expression  RP {
    $$ = A_FactorInBrackets(line_no, $2);
}
                |   NOT  factor {
    $$ = A_FactorUnOp(line_no, OP_NOT, $2);
}
                |   MINUS  factor {
    $$ = A_FactorUnOp(line_no, OP_NEG, $2);
}
                |   ID  LB  expression  RB {
    $$ = A_FactorArrayVar(line_no, S_Symbol($1), $3);
}
                |   ID  DOT  ID {
    $$ = A_FactorRecordVar(line_no, S_Symbol($1), S_Symbol($3));
}
;

args_list :         args_list  COMMA  expression {
    $$ = A_ArgsListSeq(line_no, $1, $3);
}
                |   expression {
    $$ = A_ArgsList(line_no, $1);
}
;


%%
   
void yyerror(const char *s)
{
	printf("yyerror: %s | line: %d.\n", s, line_no);					//out error information
}