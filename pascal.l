%{

#include "pascal.tab.h"

/* C Declarations: */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "absyn.h"
#include "util.h"

#ifdef __cplusplus
static int yyinput (void );
#else
static int input (void );
#endif

/* These variables and functions refers to 
 * Modern Compiler Implementation in C
 */
int charPos=1;
//int EM_tokPos = 0;
extern int EM_tokPos;

int line_no = 1;

int yywrap(void)
{
    charPos = 1;
    printf("token finish ( line: %d ).\n", line_no);
    return 1;
}

void commentError()
{
    fprintf (stderr, "unexpected EOF inside comment at line %d\n",line_no);
    exit (1);
}

void adjust(void)
{
    EM_tokPos = charPos;
    charPos += yyleng;
}

%}

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
NQUOTE [^']

%%


{A}{N}{D} { adjust(); return AND; }
{A}{R}{R}{A}{Y} { adjust(); return ARRAY; }
{B}{E}{G}{I}{N} { adjust(); return BEGINN; }
{C}{A}{S}{E} { adjust(); return CASE; }
{C}{O}{N}{S}{T} { adjust(); return CONST; }
{D}{O} { adjust(); return DO; }
{D}{O}{W}{N}{T}{O} { adjust(); return DOWNTO; }
{E}{L}{S}{E} { adjust(); return ELSE; }
{E}{N}{D} { adjust(); return END; }
{F}{O}{R} { adjust(); return FOR; }
{F}{U}{N}{C}{T}{I}{O}{N} { adjust(); return FUNCTION; }
{G}{O}{T}{O} { adjust(); return GOTO; }
{I}{F} { adjust(); return IF; }
{M}{O}{D} { adjust(); return MOD; }
{N}{O}{T} { adjust(); return NOT; }
{O}{F} { adjust(); return OF; }
{O}{R} { adjust(); return OR; }
{P}{R}{O}{C}{E}{D}{U}{R}{E} { adjust(); return PROCEDURE; }
{P}{R}{O}{G}{R}{A}{M} { adjust(); return PROGRAM; }
{R}{E}{A}{D} { adjust(); return READ; }
{R}{E}{C}{O}{R}{D} { adjust(); return RECORD; }
{R}{E}{P}{E}{A}{T} { adjust(); return REPEAT; }
{T}{H}{E}{N} { adjust(); return THEN; }
{T}{O} { adjust(); return TO; }
{T}{Y}{P}{E} { adjust(); return TYPE; }
{U}{N}{T}{I}{L} { adjust(); return UNTIL; }
{V}{A}{R} { adjust(); return VAR; }
{W}{H}{I}{L}{E} { adjust(); return WHILE; }

{T}{R}{U}{E} {
    adjust();
    yylval.sys_con = SYS_CON_TRUE;
    return SYS_CON;
}

{F}{A}{L}{S}{E} {
    adjust();
    yylval.sys_con = SYS_CON_FALSE;
    return SYS_CON;
}

{M}{A}{X}{I}{N}{T} {
    adjust();
    yylval.sys_con = SYS_CON_MAXINT;
    return SYS_CON;
}

{W}{R}{I}{T}{E} {
    adjust();
    yylval.sys_proc = SYS_PROC_WRITE;
    return SYS_PROC;
}

{W}{R}{I}{T}{E}{L}{N} {
    adjust();
    yylval.sys_proc = SYS_PROC_WRITELN;
    return SYS_PROC;
}

{I}{N}{T}{E}{G}{E}{R} {
    adjust();
    yylval.sys_type = T_INTEGER;
    return SYS_TYPE;
}

{R}{E}{A}{L} {
    adjust();
    yylval.sys_type = T_REAL;
    return SYS_TYPE;
}

{C}{H}{A}{R} {
    adjust();
    yylval.sys_type = T_CHAR;
    return SYS_TYPE;
}

{B}{O}{O}{L}{E}{A}{N} {
    adjust();
    yylval.sys_type = T_BOOLEAN;
    return SYS_TYPE;
}

{A}{B}{S} {
    adjust();
    yylval.sys_funct = SYS_FUNCT_ABS;
    return SYS_FUNCT;
}

{C}{H}{R} {
    adjust();
    yylval.sys_funct = SYS_FUNCT_CHR;
    return SYS_FUNCT;
}

{O}{D}{D} {
    adjust();
    yylval.sys_funct = SYS_FUNCT_ODD;
    return SYS_FUNCT;
}

{O}{R}{D} {
    adjust();
    yylval.sys_funct = SYS_FUNCT_ORD;
    return SYS_FUNCT;
}

{P}{R}{E}{D} {
    adjust();
    yylval.sys_funct = SYS_FUNCT_PRED;
    return SYS_FUNCT;
}

{S}{Q}{R} {
    adjust();
    yylval.sys_funct = SYS_FUNCT_SQR;
    return SYS_FUNCT;
}

{S}{Q}{R}{T} {
    adjust();
    yylval.sys_funct = SYS_FUNCT_SQRT;
    return SYS_FUNCT;
}

{S}{U}{C}{C} {
    adjust();
    yylval.sys_funct = SYS_FUNCT_SUCC;
    return SYS_FUNCT;
}

[a-zA-Z]([a-zA-Z0-9_])* {
    adjust();
	yylval.sval = String(yytext);
    return ID;
}


'({NQUOTE}|'')({NQUOTE}|'')+' {
    adjust();
    yylval.sval = yytext;
    return STRING;
}

'({NQUOTE}|'')' {
    adjust();
    yylval.sval = yytext;
    return CHAR;
}

[0-9]+ {
    adjust();
    yylval.ival = atoi(yytext);
    return INTEGER;
}

[0-9]+"\."[0-9]+ {
    adjust();
    yylval.dval = atof(yytext);
    return REAL;
}


":=" { adjust(); return ASSIGN; }
":" { adjust(); return COLON; }
"," { adjust(); return COMMA; }
"." { adjust(); return DOT; }
".." { adjust(); return DOTDOT; }
"=" { adjust(); return EQUAL; }
">=" { adjust(); return GE; }
">" { adjust(); return GT; }
"[" { adjust(); return LB; }
"<=" { adjust(); return LE; }
"(" { adjust(); return LP; }
"<" { adjust(); return LT; }
"-" { adjust(); return MINUS; }
"<>" { adjust(); return UNEQUAL; }
"+" { adjust(); return PLUS; }
"]" { adjust(); return RB; }
")" { adjust(); return RP; }
";" { adjust(); return SEMI; }
"/" { adjust(); return DIV; }
"*" { adjust(); return MUL; }
"%" { adjust(); return MOD; }

"{" {
    adjust();
    register int c;
    while ((c = input()))
    {
        adjust();
        if (c == '}')
            break;
        else if (c == '\n')
            line_no++;
        else if (c == -1)
            commentError();
    }
}

"(*" {
    adjust();
    register int c;
    while ((c = input()))
    {
        adjust();
        if (c=='*')
        {
            if ((c = input()) == ')')
                break;
            else
                unput (c);
        }
        else if (c == '\n')
            line_no++;
        else if(c == -1)
            commentError();
    }
}

[\t\f] {}

"\n" { line_no++; }

"\r" {}

" " {}

. {
    fprintf(stderr, "'%c' (0%o): illegal character at line %d\n",
            yytext[0], yytext[0], line_no);
}
 
%%