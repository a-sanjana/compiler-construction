/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AND = 258,                     /* AND  */
    ARRAY = 259,                   /* ARRAY  */
    ASSIGNMENT = 260,              /* ASSIGNMENT  */
    CASE = 261,                    /* CASE  */
    CHARACTER_STRING = 262,        /* CHARACTER_STRING  */
    COLON = 263,                   /* COLON  */
    COMMA = 264,                   /* COMMA  */
    CONST = 265,                   /* CONST  */
    DIGSEQ = 266,                  /* DIGSEQ  */
    DIV = 267,                     /* DIV  */
    DO = 268,                      /* DO  */
    DOT = 269,                     /* DOT  */
    DOTDOT = 270,                  /* DOTDOT  */
    DOWNTO = 271,                  /* DOWNTO  */
    ELSE = 272,                    /* ELSE  */
    END = 273,                     /* END  */
    EQUAL = 274,                   /* EQUAL  */
    EXTERNAL = 275,                /* EXTERNAL  */
    FOR = 276,                     /* FOR  */
    FORWARD = 277,                 /* FORWARD  */
    FUNCTION = 278,                /* FUNCTION  */
    GE = 279,                      /* GE  */
    GOTO = 280,                    /* GOTO  */
    GT = 281,                      /* GT  */
    IDENTIFIER = 282,              /* IDENTIFIER  */
    IF = 283,                      /* IF  */
    IN = 284,                      /* IN  */
    LABEL = 285,                   /* LABEL  */
    LBRAC = 286,                   /* LBRAC  */
    LE = 287,                      /* LE  */
    LPAREN = 288,                  /* LPAREN  */
    LT = 289,                      /* LT  */
    MINUS = 290,                   /* MINUS  */
    MOD = 291,                     /* MOD  */
    NIL = 292,                     /* NIL  */
    NOT = 293,                     /* NOT  */
    NOTEQUAL = 294,                /* NOTEQUAL  */
    OF = 295,                      /* OF  */
    OR = 296,                      /* OR  */
    OTHERWISE = 297,               /* OTHERWISE  */
    PACKED = 298,                  /* PACKED  */
    PBEGIN = 299,                  /* PBEGIN  */
    PFILE = 300,                   /* PFILE  */
    PLUS = 301,                    /* PLUS  */
    PROCEDURE = 302,               /* PROCEDURE  */
    PROGRAM = 303,                 /* PROGRAM  */
    RBRAC = 304,                   /* RBRAC  */
    REALNUMBER = 305,              /* REALNUMBER  */
    RECORD = 306,                  /* RECORD  */
    REPEAT = 307,                  /* REPEAT  */
    RPAREN = 308,                  /* RPAREN  */
    SEMICOLON = 309,               /* SEMICOLON  */
    SET = 310,                     /* SET  */
    SLASH = 311,                   /* SLASH  */
    STAR = 312,                    /* STAR  */
    STARSTAR = 313,                /* STARSTAR  */
    THEN = 314,                    /* THEN  */
    TO = 315,                      /* TO  */
    TYPE = 316,                    /* TYPE  */
    UNTIL = 317,                   /* UNTIL  */
    UPARROW = 318,                 /* UPARROW  */
    VAR = 319,                     /* VAR  */
    WHILE = 320,                   /* WHILE  */
    WITH = 321,                    /* WITH  */
    READ = 322,                    /* READ  */
    WRITE = 323,                   /* WRITE  */
    BOOLEAN = 324,                 /* BOOLEAN  */
    CHAR = 325,                    /* CHAR  */
    REAL = 326,                    /* REAL  */
    INTEGER = 327,                 /* INTEGER  */
    ERROR = 328                    /* ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define AND 258
#define ARRAY 259
#define ASSIGNMENT 260
#define CASE 261
#define CHARACTER_STRING 262
#define COLON 263
#define COMMA 264
#define CONST 265
#define DIGSEQ 266
#define DIV 267
#define DO 268
#define DOT 269
#define DOTDOT 270
#define DOWNTO 271
#define ELSE 272
#define END 273
#define EQUAL 274
#define EXTERNAL 275
#define FOR 276
#define FORWARD 277
#define FUNCTION 278
#define GE 279
#define GOTO 280
#define GT 281
#define IDENTIFIER 282
#define IF 283
#define IN 284
#define LABEL 285
#define LBRAC 286
#define LE 287
#define LPAREN 288
#define LT 289
#define MINUS 290
#define MOD 291
#define NIL 292
#define NOT 293
#define NOTEQUAL 294
#define OF 295
#define OR 296
#define OTHERWISE 297
#define PACKED 298
#define PBEGIN 299
#define PFILE 300
#define PLUS 301
#define PROCEDURE 302
#define PROGRAM 303
#define RBRAC 304
#define REALNUMBER 305
#define RECORD 306
#define REPEAT 307
#define RPAREN 308
#define SEMICOLON 309
#define SET 310
#define SLASH 311
#define STAR 312
#define STARSTAR 313
#define THEN 314
#define TO 315
#define TYPE 316
#define UNTIL 317
#define UPARROW 318
#define VAR 319
#define WHILE 320
#define WITH 321
#define READ 322
#define WRITE 323
#define BOOLEAN 324
#define CHAR 325
#define REAL 326
#define INTEGER 327
#define ERROR 328

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "remove_extra.y"

    struct Node* node;
    double number;
    char* string;

#line 219 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
