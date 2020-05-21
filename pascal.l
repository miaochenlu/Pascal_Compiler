%{
#include "global.h"

/* lexeme of identifier or reserved word */
/**注意这里STRING还没有实现**/

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
"FALSE"         {yylval->build<bool>(true); return BOOLEAN;}
"TRUE"          {yylval->build<bool>(flase); return BOOLEAN;}
"MAXINT"        {return SYS_CON;}
"ABS"           {yylval->build<ast::SYS_FUNCT>(ast::SYS_FUNCT::ABS); return SYS_FUNCT;}
"CHR"           {yylval->build<ast::SYS_FUNCT>(ast::SYS_FUNCT::CHR); return SYS_FUNCT;}
"ODD"           {yylval->build<ast::SYS_FUNCT>(ast::SYS_FUNCT::ODD); return SYS_FUNCT;}
"ORD"           {yylval->build<ast::SYS_FUNCT>(ast::SYS_FUNCT::ORD); return SYS_FUNCT;}
"PRED"          {yylval->build<ast::SYS_FUNCT>(ast::SYS_FUNCT::PRED); return SYS_FUNCT;}
"SQR"           {yylval->build<ast::SYS_FUNCT>(ast::SYS_FUNCT::SQR); return SYS_FUNCT;}
"SQRT"          {yylval->build<ast::SYS_FUNCT>(ast::SYS_FUNCT::SQRT); return SYS_FUNCT;}
"SUCC"          {yylval->build<ast::SYS_FUNCT>(ast::SYS_FUNCT::SUCC); return SYS_FUNCT;}

"WRITE"         {yylval->build<ast::SYS_PROC>(ast::SYS_PROC::WRITE); return SYS_PROC;}
"WRITELN"       {yylval->build<ast::SYS_PROC>(ast::SYS_PROC::WRITELN); return SYS_PROC;}
"BOOLEAN"       {yylval->build<ast::TypeKind>(ast::TypeKind::BOOLEAN); return SYS_TYPE; }
"CHAR"          {yylval->build<ast::TypeKind>(ast::TypeKind::CHAR); return SYS_TYPE; }
"INTEGER"       {yylval->build<ast::TypeKind>(ast::TypeKind::INTEGER); return SYS_TYPE; }
"REAL"          {yylval->build<ast::TypeKind>(ast::TypeKind::REAL); return SYS_TYPE; }

{SIGN}?{number} {yylval->build<int>(stoi(yytext)); return INTEGER;}
{SIGN}?(({number}\.{number})|({number}\.{number}e{SIGN}?{number})|({number}e{SIGN}?{number})) {yylval->build<double>(std::stod(yytext)); return REAL;}
\'.\'           {return CHAR;}
{identifier}    {yylval->build<string>(string(yytext)); return ID;}
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