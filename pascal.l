%{

#include <stdio.h>
#include "y.tab.h"

#define SYNTAX_ERROR 1
#define NO_SYNTAX_ERROR 0
#define LEXICAL_ERROR 1
#define NO_LEXICAL_ERROR 0
#define PARSER_ERROR 1
#define NO_PARSER_ERROR 0
#define SEMANTIC_ERROR 1
#define NO_SEMANTIC_ERROR 0

#define IS_DOT DOT
#define IS_LBRAC LBRAC
#define IS_GE GE
#define IS_GT GT
#define IS_LE LE
#define IS_LT LT
#define IS_DOTDOT DOTDOT
#define IS_MINUS MINUS
#define IS_NOTEQUAL NOTEQUAL
#define IS_PLUS PLUS
#define IS_LPAREN LPAREN
#define IS_RBRAC RBRAC
#define IS_REALNUMBER REALNUMBER
#define IS_RPAREN RPAREN
#define IS_SEMICOLON SEMICOLON
#define IS_SLASH SLASH
#define IS_STAR STAR
#define IS_MOD MOD
#define IS_STARSTAR STARSTAR

%}

NQUOTE [^']

%%

[oO][rR]   return(OR);
[fF][iI][Ll][eE]   return(PFILE);
[Ww][rR][iI][Tt][eE] return (WRITE);
[Dd][oO][Ww][Nn][tT][oO]  return(DOWNTO);
[tT][oO]  return(TO);
[fF][oO][rR]   return(FOR);
[iI][Ff]    return(IF);
[iI][nN]    return(IN);
[Aa][Rr][rR][Aa][Yy]   return(ARRAY);
[Ww][Hh][iI][Ll][eE]   return(WHILE);
[eE][lL][sS][eE]   return(ELSE);
[iI][Nn][Tt][eE][Gg][eE][rR] return (INTEGER);
[cC][hH][Aa][Rr] return (CHAR);
[Bb][eE][Gg][iI][Nn]   return(PBEGIN);
[Uu][Nn][tT][iI][Ll]   return(UNTIL);
[tT][Hh][eE][nN]   return(THEN);
[Bb][oO][Oo][lL][eE][Aa][Nn] return (BOOLEAN);
[Pp][Rr][oO][Gg][rR][Aa][Mm]  return(PROGRAM);
[Nn][oO][tT]   return(NOT);
[Tt][Yy][Pp][eE]   return(TYPE);
[eE][Nn][Dd]   return(END);
[Dd][oO]    return(DO);
[Vv][Aa][rR]   return(VAR);
[Oo][fF]    return(OF);
[Rr][eE][Aa][Ll] return(REAL);
[rR][eE][Aa][Dd] return(READ);
[Ww][iI][Tt][Hh]   return(WITH);
[Aa][Nn][Dd]   return(AND);

[a-zA-Z]([a-zA-Z0-9_])*   { yylval.string = strdup(yytext); return IDENTIFIER; }

":="    return(ASSIGNMENT);
\"([^\"]|\"\")*\"   { yylval.string = strdup(yytext); return CHARACTER_STRING;}
":"    return(COLON);
","    return(COMMA);
"//".* ;
[0-9]+    {yylval.number = atoi(yytext);return DIGSEQ;}
"."    return(DOT);
".."    return(DOTDOT);
"="    return(EQUAL);
">="    return(GE);
">"    return(GT);
"["    return(LBRAC);
"<="    return(LE);
"("    return(LPAREN);
"<"    return(LT);
"-"    return(MINUS);
"<>"    return(NOTEQUAL);
"+"    return(PLUS);
"]"    return(RBRAC);
[0-9]+"."[0-9]+   {
    yylval.number = atof(yytext); // Store the string value of the real number
    return REALNUMBER; // Return the token type
};
")"    return(RPAREN);
";"    return(SEMICOLON);
"/"    return(SLASH);
"*"    return(STAR);
"%"    return(MOD);
"**"    return(STARSTAR);
"->"   |
"^"    return(UPARROW);

[ \t\f\n.]    ;

. return (ERROR);

%%

int yywrap ()
{
 return (1);
}