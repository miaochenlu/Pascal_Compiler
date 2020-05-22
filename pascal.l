%{
#include "ast.h"
#include "parser.hpp"

int lineno = 0;
extern YYSTYPE yylval;
extern "C" {
    int yylex(void);
}
void yyerror(string msg, ...);

%}
%option yylineno

digit       [0-9]
number      {digit}+
SIGN        "-"
newline     \n
whitespace  [ \t]+


%%
"."             {cout << yytext << endl; return DOT;}
".."            {cout << yytext << endl; return DOTDOT;}
";"             {cout << yytext << endl; return SEMI;}
","             {cout << yytext << endl; return COMMA;}
":"             {cout << yytext << endl; return COLON;}
"("             {cout << yytext << endl; return LP;}
")"             {cout << yytext << endl; return RP;}
"["             {cout << yytext << endl; return LB;}
"]"             {cout << yytext << endl; return RB;}
"="             {cout << yytext << endl; return EQUAL;}
"<>"            {cout << yytext << endl; return UNEQUAL;}
">="            {cout << yytext << endl; return GE;}
">"             {cout << yytext << endl; return GT;}
"<="            {cout << yytext << endl; return LE;}
"<"             {cout << yytext << endl; return LT;}
"+"             {cout << yytext << endl; return PLUS;}
"-"             {cout << yytext << endl; return MINUS;}
"*"             {cout << yytext << endl; return MUL;}
"/" | "DIV"     {cout << yytext << endl; return DIV;}
"OR"            {cout << yytext << endl; return OR;}
"AND"           {cout << yytext << endl; return AND;}
"NOT"           {cout << yytext << endl; return NOT;}
"ARRAY"         {cout << yytext << endl; return ARRAY;}
"PROGRAM"       {cout << yytext << endl; return PROGRAM;}
"PROCEDURE"     {cout << yytext << endl; return PROCEDURE;}
"FUNCTION"      {cout << yytext << endl; return FUNCTION;}
"CONST"         {cout << yytext << endl; return CONST;}
"TYPE"          {cout << yytext << endl; return TYPE;}
"OF"            {cout << yytext << endl; return OF;}
"RECORD"        {cout << yytext << endl; return RECORD;}
"BEGIN"         {cout << yytext << endl; return BEG;}
"END"           {cout << yytext << endl; return END;}
"VAR"           {cout << yytext << endl; return VAR;}
":="            {cout << yytext << endl; return ASSIGN;}
"IF"            {cout << yytext << endl; return IF;}
"THEN"          {cout << yytext << endl; return THEN;}
"ELSE"          {cout << yytext << endl; return ELSE;}
"REPEAT"        {cout << yytext << endl; return REPEAT;}
"UNTIL"         {cout << yytext << endl; return UNTIL;}
"WHILE"         {cout << yytext << endl; return WHILE;}
"DO"            {cout << yytext << endl; return DO;}
"FOR"           {cout << yytext << endl; return FOR;}
"TO"            {cout << yytext << endl; return TO;}
"DOWNTO"        {cout << yytext << endl; return DOWNTO;}
"CASE"          {cout << yytext << endl; return CASE;}
"GOTO"          {cout << yytext << endl; return GOTO;}
"READ"          {cout << yytext << endl; return READ;}
"FALSE"         {cout << yytext << endl; yylval.astbool = true; return BOOLEAN;}
"TRUE"          {cout << yytext << endl; yylval.astbool = false; return BOOLEAN;}
"MAXINT"        {cout << yytext << endl; return SYS_CON;}
"ABS"           {cout << yytext << endl; yylval.astSYSFUNCT = ast::SYSFUNCT::ABS; return SYS_FUNCT;}
"CHR"           {cout << yytext << endl; yylval.astSYSFUNCT = ast::SYSFUNCT::CHR; return SYS_FUNCT;}
"ODD"           {cout << yytext << endl; yylval.astSYSFUNCT = ast::SYSFUNCT::ODD; return SYS_FUNCT;}
"ORD"           {cout << yytext << endl; yylval.astSYSFUNCT = ast::SYSFUNCT::ORD; return SYS_FUNCT;}
"PRED"          {cout << yytext << endl; yylval.astSYSFUNCT = ast::SYSFUNCT::PRED; return SYS_FUNCT;}
"SQR"           {cout << yytext << endl; yylval.astSYSFUNCT = ast::SYSFUNCT::SQR; return SYS_FUNCT;}
"SQRT"          {cout << yytext << endl; yylval.astSYSFUNCT = ast::SYSFUNCT::SQRT; return SYS_FUNCT;}
"SUCC"          {cout << yytext << endl; yylval.astSYSFUNCT = ast::SYSFUNCT::SUCC; return SYS_FUNCT;}

"WRITE"         {cout << yytext << endl; yylval.astSYSPROC = ast::SYSPROC::WRITE; return SYS_PROC;}
"WRITELN"       {cout << yytext << endl; yylval.astSYSPROC = ast::SYSPROC::WRITELN; return SYS_PROC;}
"BOOLEAN"       {cout << yytext << endl; yylval.astTypeKind = ast::TypeKind::BOOLEANtype; return SYS_TYPE; }
"CHAR"          {cout << yytext << endl; yylval.astTypeKind = ast::TypeKind::CHARtype; return SYS_TYPE; }
"INTEGER"       {cout << yytext << endl; yylval.astTypeKind = ast::TypeKind::INTtype; return SYS_TYPE; }
"REAL"          {cout << yytext << endl; yylval.astTypeKind = ast::TypeKind::REALtype; return SYS_TYPE; }

{SIGN}?{number} {cout << yytext << endl; yylval.astint = atoi(yytext); return INTEGER;}
{SIGN}?(({number}\.{number})|({number}\.{number}e{SIGN}?{number})|({number}e{SIGN}?{number})) {cout << yytext << endl; yylval.astreal = atof(yytext); return REAL;}
\'.\'                       {cout << yytext << endl; yylval.astchar = yytext[0] ;return CHAR;}
[a-zA-Z]([_a-zA-Z0-9])*     {cout << yytext << endl ; yylval.aststring = strdup(yytext); return ID;}
{newline}       {lineno++;}
{whitespace}    {}
"{"             {   cout << yytext << endl;
                    char c;
                    do { 
                        c = yyinput();
                        if (c == EOF) break;
                        if (c == '\n') lineno++;
                    } while (c != '}');
                }
.               { printf("ERROR: Invalid character\n"); cout << yytext << "???" << endl;} 

%%

int yywrap()
{
		return 1;
}

int get_token() {
	int token = yylex();
	// if (TraceScan)
    // printf("%d\n", token);
	return token;
}