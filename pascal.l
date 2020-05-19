%{
#include "globals.h"
#include "util.h"
#include "scan.h"
/* lexeme of identifier or reserved word */
/**注意这里STRING还没有实现**/
char tokenString[MAXTOKENLEN+1];
%}

digit       [0-9]
number      {digit}+
SIGN        "+"|"-"
letter      [a-zA-Z]
identifier  {letter}+
newline     \n
whitespace  [\t]+


%%
"."             {return DOT;}
".."            {return DOTDOT;}
";"             {return SEMI;}
","             {return COMMA;}
":"             {return COLON;}
"("             {return LP;}
")"             {return RP;}
"["             {return LB;}
"]"             {return RB;}
"="             {return EQUAL;}
"<>"            {reutrn UNEQUAL;}
">="            {return GE;}
">"             {return GT;}
"<="            {return LE;}
"<"             {return LT;}
"+"             {return PLUS;}
"-"             {return MINUS;}
"*"             {return MUL;}
"/" | "div"     {return DIV;}
"OR"            {return OR;}
"AND"           {return AND;}
"NOT"           {return NOT;}
"ARRAY"         {return ARRAY;}
"PROGRAM"       {return PROGRAM;}
"PROCEDURE"     {return PROCEDURE;}
"FUNCTION"      {return FUNCTION;}
"CONST"         {return CONST;}
"TYPE"          {return TYPE;}
"OF"            {return OF;}
"RECORD"        {return RECORD;}
"BEGIN"         {return BEGIN;}
"END"           {return END;}
"VAR"           {return VAR;}
":="            {return ASSIGN;}
"IF"            {return IF;}
"THEN"          {return THEN;}
"ELSE"          {return ELSE;}
"REPEAT"        {return REPEAT;}
"UNTIL"         {return UNTIL;}
"WHILE"         {return WHILE;}
"DO"            {return DO;}
"FOR"           {return FOR;}
"TO"            {return TO;}
"DOWNTO"        {return DOWNTO;}
"CASE"          {return CASE;}
"GOTO"          {return GOTO;}
"READ"          {return READ;}
"FALSE" | "TRUE" | "MAXINT"                                         {return SYS_CON;}
"ABS" | "CHR" | "ODD" | "ORD" | "PRED" | "SQR" | "SQRT" | "SUCC"    {return SYS_FUNCT;}
"WRITE" | "WRITELN"                                                 {return SYS_PROC;}
"BOOLEAN" | "CHAR" | "INTEGER" | "REAL"                             {return SYS_TYPE}

{SIGN}?{number} {return INTEGER;}
{SIGN}?(({number}\.{number})|({number}\.{number}e{SIGN}?{number})|({number}e{SIGN}?{number})) {return REAL;}
\'.\'           {return CHAR;}
{identifier}    {return ID;}
                {return NAME;}
{newline}       {lineno++;}
{whitespace}    {/* skip whitespace */}
"{"             { 
                    char c;
                    do { 
                        c = input();
                        if (c == EOF) break;
                        if (c == '\n') lineno++;
                    } while (c != '}');
                }
.               {return ERROR;}

%%

TokenType getToken(void)
{ 
    static int firstTime = TRUE;
    TokenType currentToken;
    if(firstTime) { 
        firstTime = FALSE;
        lineno++;
        yyin = source;
        yyout = listing;
    }
    currentToken = yylex();
    strncpy(tokenString,yytext,MAXTOKENLEN);
    if(TraceScan) {
        fprintf(listing,"\t%d: ",lineno);
        printToken(currentToken,tokenString);
    }
    return currentToken;
}