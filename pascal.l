%{
#include "global.h"
#include "y.tab.h"
/* lexeme of identifier or reserved word */
/**注意这里STRING还没有实现**/
int lineno = 0;
extern YYSTYPE yylval;
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
"<>"            {return UNEQUAL;}
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
"FALSE"         {yylval.astbool = true; return BOOLEAN;}
"TRUE"          {yylval.astbool = false; return BOOLEAN;}
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

{SIGN}?{number} {yylval.astint = atoi(yytext); return INTEGER;}
{SIGN}?(({number}\.{number})|({number}\.{number}e{SIGN}?{number})|({number}e{SIGN}?{number})) {yylval.astreal = atof(yytext); return REAL;}
\'.\'           {yylval.astchar = yytext[0] ;return CHAR;}
{identifier}    {yylval.aststring = strdup(yytext); return ID;}
{newline}       {lineno++;}
{whitespace}    {/* skip whitespace */}
"{"             { 
                    char c;
                    do { 
                        c = yyinput();
                        if (c == EOF) break;
                        if (c == '\n') lineno++;
                    } while (c != '}');
                }
.               { printf("ERROR: Invalid character\n");} 

%%

// TokenType getToken(void)
// { 
//     static int firstTime = TRUE;
//     TokenType currentToken;
//     if(firstTime) { 
//         firstTime = FALSE;
//         lineno++;
//         yyin = source;
//         yyout = listing;
//     }
//     currentToken = yylex();
//     strncpy(tokenString,yytext,MAXTOKENLEN);
//     if(TraceScan) {
//         fprintf(listing,"\t%d: ",lineno);
//         printToken(currentToken,tokenString);
//     }
//     return currentToken;
// }