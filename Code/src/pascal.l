%{
#include "ast/ast.h"
#include "parser.hpp"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include <memory>
extern YYSTYPE yylval;
void yyerror(string msg, ...);
int lineno = 1;
void setUpperCase(char* s) {
    int i = 0;
    while(s[i] != 0) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = 'A' - 'a' + s[i];
        }
        i++;
    }
}

void dealwithString(char* s) {
    int i = 1;
    for(; i < strlen(s) - 1; i++) {
        s[i - 1] = s[i];
    }
    s[i - 1] = 0;
}
int termin = 0;
%}
%option yylineno caseless

digit       [0-9]
number      {digit}+
whitespace  [\t ]+


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
"<>"            {return UNEQUAL;}
">="            {return GE;}
">"             {return GT;}
"<="            {return LE;}
"<"             {return LT;}
"+"             {return PLUS;}
"-"             {return MINUS;}
"*"             {return MUL;}
"/"             {return DIV;}
"DIV"           {return DIV;}
"%"             {return MOD;}
"MOD"           {return MOD;}
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
"BEGIN"         {return BEG;}
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
"FALSE"         {yylval.astbool = false; return BOOLEAN;}
"TRUE"          {yylval.astbool = true; return BOOLEAN;}
"MAXINT"        {return SYS_CON;}
"ABS"           {yylval.astSYSFUNCT = ast::SYSFUNCT::ABS; return SYS_FUNCT;}
"CHR"           {yylval.astSYSFUNCT = ast::SYSFUNCT::CHR; return SYS_FUNCT;}
"ODD"           {yylval.astSYSFUNCT = ast::SYSFUNCT::ODD; return SYS_FUNCT;}
"ORD"           {yylval.astSYSFUNCT = ast::SYSFUNCT::ORD; return SYS_FUNCT;}
"PRED"          {yylval.astSYSFUNCT = ast::SYSFUNCT::PRED; return SYS_FUNCT;}
"SQR"           {yylval.astSYSFUNCT = ast::SYSFUNCT::SQR; return SYS_FUNCT;}
"SQRT"          {yylval.astSYSFUNCT = ast::SYSFUNCT::SQRT; return SYS_FUNCT;}
"SUCC"          {yylval.astSYSFUNCT = ast::SYSFUNCT::SUCC; return SYS_FUNCT;}

"WRITE"         {yylval.astSYSPROC = ast::SYSPROC::WRITE; return SYS_PROC;}
"WRITELN"       {yylval.astSYSPROC = ast::SYSPROC::WRITELN; return SYS_PROC;}
"BOOLEAN"       {yylval.astTypeKind = ast::TypeKind::BOOLEANtype; return SYS_TYPE; }
"CHAR"          {yylval.astTypeKind = ast::TypeKind::CHARtype; return SYS_TYPE; }
"INTEGER"       {yylval.astTypeKind = ast::TypeKind::INTtype; return SYS_TYPE; }
"REAL"          {yylval.astTypeKind = ast::TypeKind::REALtype; return SYS_TYPE; }
"STRING"        {yylval.astTypeKind = ast::TypeKind::STRINGtype; return SYS_TYPE; }

{number} {yylval.astint = atoi(yytext); return INTEGER;}
\'.\'    {yylval.astchar = yytext[1]; return CHAR;}
'([^']|'')+'  {dealwithString(yytext); yylval.aststring = strdup(yytext); return STRING;}
[0-9]+"."[0-9]+  {yylval.astreal = atof(yytext); return REAL;}
[a-zA-Z_]([_a-zA-Z0-9])*     {setUpperCase(yytext); yylval.aststring = strdup(yytext); return ID;}
\n      {lineno++;}
{whitespace}    {}
"{"             {
                    char c;
                    do {
                        c = yyinput();
                        if (c == '\n') lineno++;
                        if (termin == 1) { cout << "ERROR: Line " << lineno << ": comment doesn't end" << endl; break;}
                    } while (c != '}' && c != EOF);
                }

.               { cout << "ERROR: Line " << lineno << ": Invalid character: " <<  yytext << endl;}


%%

int yywrap() {
        termin = 1;
		return 1;
}
