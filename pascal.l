%{

/* C Declarations: */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "absyn.h"
#include "util.h"

/* These variables and functions refers to 
 * Modern Compiler Implementation in C
 */
int charPos=1;

// comments depth and strings defines
const int INITIAL_BUF_LEN = 32;
char *str_buf;
unsigned int str_buf_cap;
int commentNesting = 0;

void init_str_buf(void) {
    str_buf = checked_malloc(INITIAL_BUF_LEN);
    str_buf[0] = 0;
    str_buf_cap = INITIAL_BUF_LEN;
}

static void append_char2str_buf(char ch) {
    size_t new_length = strlen(str_buf) + 1;
    if (new_length == str_buf_cap){
        char *temp;
        str_buf_cap *= 2;
        temp = checked_malloc(str_buf_cap);
        memcpy(temp, str_buf, new_length);
        free(str_buf);
        str_buf = temp;
    }
    str_buf[new_length - 1] = ch;
    str_buf[new_length] = 0;
}

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
    return sys_con;
}

{F}{A}{L}{S}{E} {
    adjust();
    yylval.sys_con = SYS_CON_FALSE;
    return sys_con;
}

{M}{A}{X}{I}{N}{T} {
    adjust();
    yylval.sys_con = SYS_CON_MAXINT;
    return sys_con;
}

{W}{R}{I}{T}{E} {
    adjust();
    yylval.sys_proc = WRITE;
    return sys_proc;
}

{W}{R}{I}{T}{E}{L}{N} {
    adjust();
    yylval.sys_proc = WRITELN;
    return sys_proc;
}

{I}{N}{T}{E}{G}{E}{R} {
    adjust();
    yylval.sys_type = T_INTEGER;
    return sys_type;
}

{R}{E}{A}{L} {
    adjust();
    yylval.sys_type = T_REAL;
    return sys_type;
}

{C}{H}{A}{R} {
    adjust();
    yylval.sys_type = T_CHAR;
    return sys_type;
}

{B}{O}{O}{L}{E}{A}{N} {
    adjust();
    yylval.sys_type = T_BOOLEAN;
    return sys_type;
}

{A}{B}{S} {
    adjust();
    yylval.sys_funct = ABS;
    return sys_funct;
}

{C}{H}{R} {
    adjust();
    yylval.sys_funct = CHR;
    return sys_funct;
}

{O}{D}{D} {
    adjust();
    yylval.sys_funct = ODD;
    return sys_funct;
}

{O}{R}{D} {
    adjust();
    yylval.sys_funct = ORD;
    return sys_funct;
}

{P}{R}{E}{D} {
    adjust();
    yylval.sys_funct = PRED;
    return sys_funct;
}

{S}{Q}{R} {
    adjust();
    yylval.sys_funct = SQR;
    return sys_funct;
}

{S}{Q}{R}{T} {
    adjust();
    yylval.sys_funct = SQRT;
    return sys_funct;
}

{S}{U}{C}{C} {
    adjust();
    yylval.sys_funct = SUCC;
    return sys_funct;
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
    while ((c = yyinput()))
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
    while ((c = yyinput()))
    {
        adjust();
        if (c=='*')
        {
            if ((c = yyinput()) == ')')
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

" " {}

. {
    fprintf(stderr, "'%c' (0%o): illegal charcter at line %d\n",
            yytext[0], yytext[0], line_no);
}
 
%%