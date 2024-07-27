/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "remove_extra.y"

#include <stdio.h>
#include "ast.h"
#include "sym.h"
#include "output.h"
extern int line_no;
int syntax_error = 0;
void yyerror(const char *s) {
    syntax_error = 1;
    printf("syntax error\n");
}

int yylex();
Node* ASTROOT;

extern FILE * yyin;


#line 90 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 295 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AND = 3,                        /* AND  */
  YYSYMBOL_ARRAY = 4,                      /* ARRAY  */
  YYSYMBOL_ASSIGNMENT = 5,                 /* ASSIGNMENT  */
  YYSYMBOL_CASE = 6,                       /* CASE  */
  YYSYMBOL_CHARACTER_STRING = 7,           /* CHARACTER_STRING  */
  YYSYMBOL_COLON = 8,                      /* COLON  */
  YYSYMBOL_COMMA = 9,                      /* COMMA  */
  YYSYMBOL_CONST = 10,                     /* CONST  */
  YYSYMBOL_DIGSEQ = 11,                    /* DIGSEQ  */
  YYSYMBOL_DIV = 12,                       /* DIV  */
  YYSYMBOL_DO = 13,                        /* DO  */
  YYSYMBOL_DOT = 14,                       /* DOT  */
  YYSYMBOL_DOTDOT = 15,                    /* DOTDOT  */
  YYSYMBOL_DOWNTO = 16,                    /* DOWNTO  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_END = 18,                       /* END  */
  YYSYMBOL_EQUAL = 19,                     /* EQUAL  */
  YYSYMBOL_EXTERNAL = 20,                  /* EXTERNAL  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_FORWARD = 22,                   /* FORWARD  */
  YYSYMBOL_FUNCTION = 23,                  /* FUNCTION  */
  YYSYMBOL_GE = 24,                        /* GE  */
  YYSYMBOL_GOTO = 25,                      /* GOTO  */
  YYSYMBOL_GT = 26,                        /* GT  */
  YYSYMBOL_IDENTIFIER = 27,                /* IDENTIFIER  */
  YYSYMBOL_IF = 28,                        /* IF  */
  YYSYMBOL_IN = 29,                        /* IN  */
  YYSYMBOL_LABEL = 30,                     /* LABEL  */
  YYSYMBOL_LBRAC = 31,                     /* LBRAC  */
  YYSYMBOL_LE = 32,                        /* LE  */
  YYSYMBOL_LPAREN = 33,                    /* LPAREN  */
  YYSYMBOL_LT = 34,                        /* LT  */
  YYSYMBOL_MINUS = 35,                     /* MINUS  */
  YYSYMBOL_MOD = 36,                       /* MOD  */
  YYSYMBOL_NIL = 37,                       /* NIL  */
  YYSYMBOL_NOT = 38,                       /* NOT  */
  YYSYMBOL_NOTEQUAL = 39,                  /* NOTEQUAL  */
  YYSYMBOL_OF = 40,                        /* OF  */
  YYSYMBOL_OR = 41,                        /* OR  */
  YYSYMBOL_OTHERWISE = 42,                 /* OTHERWISE  */
  YYSYMBOL_PACKED = 43,                    /* PACKED  */
  YYSYMBOL_PBEGIN = 44,                    /* PBEGIN  */
  YYSYMBOL_PFILE = 45,                     /* PFILE  */
  YYSYMBOL_PLUS = 46,                      /* PLUS  */
  YYSYMBOL_PROCEDURE = 47,                 /* PROCEDURE  */
  YYSYMBOL_PROGRAM = 48,                   /* PROGRAM  */
  YYSYMBOL_RBRAC = 49,                     /* RBRAC  */
  YYSYMBOL_REALNUMBER = 50,                /* REALNUMBER  */
  YYSYMBOL_RECORD = 51,                    /* RECORD  */
  YYSYMBOL_REPEAT = 52,                    /* REPEAT  */
  YYSYMBOL_RPAREN = 53,                    /* RPAREN  */
  YYSYMBOL_SEMICOLON = 54,                 /* SEMICOLON  */
  YYSYMBOL_SET = 55,                       /* SET  */
  YYSYMBOL_SLASH = 56,                     /* SLASH  */
  YYSYMBOL_STAR = 57,                      /* STAR  */
  YYSYMBOL_STARSTAR = 58,                  /* STARSTAR  */
  YYSYMBOL_THEN = 59,                      /* THEN  */
  YYSYMBOL_TO = 60,                        /* TO  */
  YYSYMBOL_TYPE = 61,                      /* TYPE  */
  YYSYMBOL_UNTIL = 62,                     /* UNTIL  */
  YYSYMBOL_UPARROW = 63,                   /* UPARROW  */
  YYSYMBOL_VAR = 64,                       /* VAR  */
  YYSYMBOL_WHILE = 65,                     /* WHILE  */
  YYSYMBOL_WITH = 66,                      /* WITH  */
  YYSYMBOL_READ = 67,                      /* READ  */
  YYSYMBOL_WRITE = 68,                     /* WRITE  */
  YYSYMBOL_BOOLEAN = 69,                   /* BOOLEAN  */
  YYSYMBOL_CHAR = 70,                      /* CHAR  */
  YYSYMBOL_REAL = 71,                      /* REAL  */
  YYSYMBOL_INTEGER = 72,                   /* INTEGER  */
  YYSYMBOL_ERROR = 73,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 74,                  /* $accept  */
  YYSYMBOL_file = 75,                      /* file  */
  YYSYMBOL_program = 76,                   /* program  */
  YYSYMBOL_program_heading = 77,           /* program_heading  */
  YYSYMBOL_identifier_list = 78,           /* identifier_list  */
  YYSYMBOL_block = 79,                     /* block  */
  YYSYMBOL_label = 80,                     /* label  */
  YYSYMBOL_subrange_type = 81,             /* subrange_type  */
  YYSYMBOL_array_type = 82,                /* array_type  */
  YYSYMBOL_component_type = 83,            /* component_type  */
  YYSYMBOL_variable_declaration_part = 84, /* variable_declaration_part  */
  YYSYMBOL_variable_declaration_list = 85, /* variable_declaration_list  */
  YYSYMBOL_variable_declaration = 86,      /* variable_declaration  */
  YYSYMBOL_var_type = 87,                  /* var_type  */
  YYSYMBOL_statement_part = 88,            /* statement_part  */
  YYSYMBOL_compound_statement = 89,        /* compound_statement  */
  YYSYMBOL_statement_sequence = 90,        /* statement_sequence  */
  YYSYMBOL_statement = 91,                 /* statement  */
  YYSYMBOL_open_statement = 92,            /* open_statement  */
  YYSYMBOL_closed_statement = 93,          /* closed_statement  */
  YYSYMBOL_non_labeled_closed_statement = 94, /* non_labeled_closed_statement  */
  YYSYMBOL_non_labeled_open_statement = 95, /* non_labeled_open_statement  */
  YYSYMBOL_open_while_statement = 96,      /* open_while_statement  */
  YYSYMBOL_closed_while_statement = 97,    /* closed_while_statement  */
  YYSYMBOL_open_for_statement = 98,        /* open_for_statement  */
  YYSYMBOL_closed_for_statement = 99,      /* closed_for_statement  */
  YYSYMBOL_open_if_statement = 100,        /* open_if_statement  */
  YYSYMBOL_closed_if_statement = 101,      /* closed_if_statement  */
  YYSYMBOL_assignment_statement = 102,     /* assignment_statement  */
  YYSYMBOL_read_statement = 103,           /* read_statement  */
  YYSYMBOL_write_statement = 104,          /* write_statement  */
  YYSYMBOL_list = 105,                     /* list  */
  YYSYMBOL_identifier_list_1 = 106,        /* identifier_list_1  */
  YYSYMBOL_identifier_1 = 107,             /* identifier_1  */
  YYSYMBOL_variable_access = 108,          /* variable_access  */
  YYSYMBOL_indexed_variable = 109,         /* indexed_variable  */
  YYSYMBOL_control_variable = 110,         /* control_variable  */
  YYSYMBOL_initial_value = 111,            /* initial_value  */
  YYSYMBOL_direction = 112,                /* direction  */
  YYSYMBOL_final_value = 113,              /* final_value  */
  YYSYMBOL_boolean_expression = 114,       /* boolean_expression  */
  YYSYMBOL_expression = 115,               /* expression  */
  YYSYMBOL_simple_expression = 116,        /* simple_expression  */
  YYSYMBOL_term = 117,                     /* term  */
  YYSYMBOL_primary = 118,                  /* primary  */
  YYSYMBOL_unsigned_constant = 119,        /* unsigned_constant  */
  YYSYMBOL_addop = 120,                    /* addop  */
  YYSYMBOL_mulop = 121,                    /* mulop  */
  YYSYMBOL_relop = 122,                    /* relop  */
  YYSYMBOL_identifier = 123,               /* identifier  */
  YYSYMBOL_semicolon = 124,                /* semicolon  */
  YYSYMBOL_comma = 125                     /* comma  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   142

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   328


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,   103,   113,   122,   129,   137,   147,   155,
     166,   182,   187,   192,   197,   204,   212,   218,   224,   231,
     356,   361,   366,   371,   376,   384,   391,   403,   409,   416,
     421,   428,   435,   442,   449,   455,   460,   465,   470,   475,
     480,   485,   491,   496,   501,   506,   512,   522,   532,   549,
     572,   580,   592,   605,   641,   689,   700,   706,   714,   721,
     751,   783,   791,   823,   831,   842,   875,   900,   905,   912,
     936,   961,   984,  1001,  1024,  1038,  1060,  1074,  1096,  1118,
    1142,  1166,  1173,  1180,  1187,  1197,  1203,  1209,  1217,  1223,
    1229,  1235,  1241,  1249,  1255,  1261,  1267,  1273,  1279,  1285,
    1294,  1304,  1310
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AND", "ARRAY",
  "ASSIGNMENT", "CASE", "CHARACTER_STRING", "COLON", "COMMA", "CONST",
  "DIGSEQ", "DIV", "DO", "DOT", "DOTDOT", "DOWNTO", "ELSE", "END", "EQUAL",
  "EXTERNAL", "FOR", "FORWARD", "FUNCTION", "GE", "GOTO", "GT",
  "IDENTIFIER", "IF", "IN", "LABEL", "LBRAC", "LE", "LPAREN", "LT",
  "MINUS", "MOD", "NIL", "NOT", "NOTEQUAL", "OF", "OR", "OTHERWISE",
  "PACKED", "PBEGIN", "PFILE", "PLUS", "PROCEDURE", "PROGRAM", "RBRAC",
  "REALNUMBER", "RECORD", "REPEAT", "RPAREN", "SEMICOLON", "SET", "SLASH",
  "STAR", "STARSTAR", "THEN", "TO", "TYPE", "UNTIL", "UPARROW", "VAR",
  "WHILE", "WITH", "READ", "WRITE", "BOOLEAN", "CHAR", "REAL", "INTEGER",
  "ERROR", "$accept", "file", "program", "program_heading",
  "identifier_list", "block", "label", "subrange_type", "array_type",
  "component_type", "variable_declaration_part",
  "variable_declaration_list", "variable_declaration", "var_type",
  "statement_part", "compound_statement", "statement_sequence",
  "statement", "open_statement", "closed_statement",
  "non_labeled_closed_statement", "non_labeled_open_statement",
  "open_while_statement", "closed_while_statement", "open_for_statement",
  "closed_for_statement", "open_if_statement", "closed_if_statement",
  "assignment_statement", "read_statement", "write_statement", "list",
  "identifier_list_1", "identifier_1", "variable_access",
  "indexed_variable", "control_variable", "initial_value", "direction",
  "final_value", "boolean_expression", "expression", "simple_expression",
  "term", "primary", "unsigned_constant", "addop", "mulop", "relop",
  "identifier", "semicolon", "comma", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -30,    -2,    29,   -99,   -19,   -99,   -99,   -99,   -99,   -28,
      -2,    25,     4,     8,   -19,   -99,   -99,   -99,    19,   -99,
     -99,     1,   -99,    -2,    -2,   -99,    -2,    74,    74,    11,
      16,    47,   -99,   -12,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,     6,   -99,
     -99,    26,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
      60,   -99,   -99,   -99,    74,   -99,    74,   -99,    36,    21,
     -99,    96,    38,   -99,   -99,    62,    -2,     7,    24,   -99,
      19,    74,    74,    71,    74,    30,   -99,    19,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,    74,    74,
     -99,   -99,   -99,   -99,   -99,    74,    19,    37,    36,    69,
      72,   -99,    40,    93,   -99,   -99,   -99,   -99,   -99,    55,
      90,    57,    -7,   -99,   -99,   -99,    91,    38,    -8,   -99,
     -99,   -99,   -99,   -99,    -2,   -99,    98,    70,   -99,   -99,
      74,    19,   -99,   -99,    27,   100,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,    19,   -99,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,   100,     4,     1,   101,    16,
       0,     0,     0,     0,     0,    18,     6,     3,    42,     7,
      25,     0,   102,     0,    15,     8,     0,     0,     0,     0,
       0,     0,    38,     0,    28,    29,    30,    34,    32,    44,
      40,    45,    41,    43,    39,    35,    36,    37,     0,    63,
      62,     0,    23,    22,    21,    20,    24,    19,     5,    17,
       0,    65,    83,    81,     0,    84,     0,    82,    77,     0,
      70,    71,    73,    75,    78,     0,     0,     0,    42,    26,
      42,     0,     0,     0,     0,     0,    80,    42,    93,    98,
      96,    99,    97,    95,    86,    94,    87,    85,     0,     0,
      92,    90,    91,    89,    88,     0,    42,     0,     0,    61,
      60,    56,     0,    57,    59,    33,    31,    27,    53,     0,
       0,     0,     0,    66,    79,    50,    30,    74,    72,    76,
      46,    47,    54,    55,     0,    64,     0,     0,    68,    67,
       0,    42,    58,     9,     0,     0,    69,    51,    52,    14,
      13,    12,    11,    10,    42,    48,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,    94,   -99,   -99,   102,   -99,   -59,   -98,   -75,
      39,    41,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -70,   -18,   -73,   -99,   -99,   -99,   -99,
      99,   -62,    22,    28,   -51,   -99,   -99,   -99,   -99,     0,
      -1,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    13,    11,    31,   121,    56,   153,
      12,    14,    15,    57,    19,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,   112,   113,   107,    68,    49,    60,   122,   140,   145,
      69,    70,    71,    72,    73,    74,    98,   105,    99,    50,
       9,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,     6,    85,   109,   109,    51,    79,   114,   130,   138,
      16,    81,   126,    24,   111,    86,    21,    22,     1,   118,
     119,   117,   123,    58,    16,     5,    61,    94,   125,     7,
      25,   131,    80,    96,     5,     8,    10,    82,    97,    17,
      26,   100,     8,   147,    76,    26,     5,    27,    18,    77,
     101,     5,    27,   139,   129,    78,   155,    83,   108,   108,
      48,   109,    48,    18,   142,    84,   148,    82,    18,    48,
      52,    53,    54,    55,   102,   106,   110,   110,   146,   156,
      87,    62,   120,   124,    28,    63,    29,    30,    48,    28,
     132,    29,    30,   133,   103,   104,   149,   150,   151,   152,
     -63,     5,    22,   -62,   135,   136,   137,    64,   141,   143,
     144,    65,    66,   154,    20,    88,   108,   115,    59,   116,
      89,   128,    90,    48,    67,    91,   127,    75,    92,     0,
      93,    94,     0,   134,   110,    95,    48,    96,     0,     0,
       0,     0,    97
};

static const yytype_int16 yycheck[] =
{
      18,     1,    64,    76,    77,     4,    18,    77,   106,    16,
      10,     5,    87,    14,     7,    66,     8,     9,    48,    81,
      82,    80,    84,    23,    24,    27,    26,    35,    87,     0,
      11,   106,    33,    41,    27,    54,    64,    31,    46,    14,
      21,     3,    54,   141,    33,    21,    27,    28,    44,    33,
      12,    27,    28,    60,   105,     8,   154,    31,    76,    77,
      78,   134,    80,    44,   134,     5,   141,    31,    44,    87,
      69,    70,    71,    72,    36,    13,    76,    77,   140,   154,
      59,     7,    11,    53,    65,    11,    67,    68,   106,    65,
      53,    67,    68,    53,    56,    57,    69,    70,    71,    72,
      31,    27,     9,    31,    49,    15,    49,    33,    17,    11,
      40,    37,    38,    13,    12,    19,   134,    78,    24,    78,
      24,    99,    26,   141,    50,    29,    98,    28,    32,    -1,
      34,    35,    -1,   113,   134,    39,   154,    41,    -1,    -1,
      -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    75,    76,    77,    27,   123,     0,    54,   124,
      64,    79,    84,    78,    85,    86,   123,    14,    44,    88,
      89,     8,     9,   125,   124,    11,    21,    28,    65,    67,
      68,    80,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   108,   109,
     123,     4,    69,    70,    71,    72,    82,    87,   123,    86,
     110,   123,     7,    11,    33,    37,    38,    50,   108,   114,
     115,   116,   117,   118,   119,   114,    33,    33,     8,    18,
     124,     5,    31,    31,     5,   115,   118,    59,    19,    24,
      26,    29,    32,    34,    35,    39,    41,    46,   120,   122,
       3,    12,    36,    56,    57,   121,    13,   107,   108,   109,
     123,     7,   105,   106,   107,    94,    95,    91,   115,   115,
      11,    81,   111,   115,    53,    91,    93,   117,   116,   118,
      92,    93,    53,    53,   125,    49,    15,    49,    16,    60,
     112,    17,   107,    11,    40,   113,   115,    92,    93,    69,
      70,    71,    72,    83,    13,    92,    93
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    74,    75,    76,    77,    78,    78,    79,    80,    81,
      82,    83,    83,    83,    83,    84,    84,    85,    85,    86,
      87,    87,    87,    87,    87,    88,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    94,    94,    94,
      94,    94,    94,    95,    95,    95,    96,    97,    98,    99,
     100,   100,   101,   102,   103,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   110,   111,   112,   112,   113,
     114,   115,   115,   116,   116,   117,   117,   118,   118,   118,
     118,   119,   119,   119,   119,   120,   120,   120,   121,   121,
     121,   121,   121,   122,   122,   122,   122,   122,   122,   122,
     123,   124,   125
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     4,     2,     3,     1,     2,     1,     3,
       6,     1,     1,     1,     1,     3,     0,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     4,     4,     8,     8,
       4,     6,     6,     3,     4,     4,     1,     1,     3,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* file: program  */
#line 98 "remove_extra.y"
{
  //readConsole();
}
#line 1530 "y.tab.c"
    break;

  case 3: /* program: program_heading semicolon block DOT  */
#line 104 "remove_extra.y"
{
 		(yyval.node) = newNode(NODE_PROGRAM);
 		addChild((yyval.node), (yyvsp[-3].node));
 		addChild((yyval.node), newNode(PUC_SEMI));
 		addChild((yyval.node), (yyvsp[-1].node));
 		addChild((yyval.node), newNode(PUC_DOT));
 		ASTROOT = (yyval.node);
 	}
#line 1543 "y.tab.c"
    break;

  case 4: /* program_heading: PROGRAM identifier  */
#line 114 "remove_extra.y"
{
	
	(yyval.node) = newNode(NODE_PROGRAM_HEAD);
   addChild((yyval.node), newNode(RE_PROG));
   addChild((yyval.node), (yyvsp[0].node));
}
#line 1554 "y.tab.c"
    break;

  case 5: /* identifier_list: identifier_list comma identifier  */
#line 123 "remove_extra.y"
{
   (yyval.node) = (yyvsp[-2].node);
    addChild((yyval.node),newNode(PUC_COMMA));
    addChild((yyval.node), (yyvsp[0].node)); // variable_declaration

}
#line 1565 "y.tab.c"
    break;

  case 6: /* identifier_list: identifier  */
#line 130 "remove_extra.y"
 {
   (yyval.node) = newNode(NODE_ID_LIST);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 1574 "y.tab.c"
    break;

  case 7: /* block: variable_declaration_part statement_part  */
#line 139 "remove_extra.y"
  {
 	(yyval.node) = newNode(NODE_BLOCK);
    addChild((yyval.node), (yyvsp[-1].node));
    addChild((yyval.node), (yyvsp[0].node));
 }
#line 1584 "y.tab.c"
    break;

  case 8: /* label: DIGSEQ  */
#line 148 "remove_extra.y"
{
  (yyval.node) = newNode(NODE_LABEL);
   addChild((yyval.node), newNode(DIGSEQ_TOK));
}
#line 1593 "y.tab.c"
    break;

  case 9: /* subrange_type: DIGSEQ DOTDOT DIGSEQ  */
#line 156 "remove_extra.y"
{
   (yyval.node) = newNode(NODE_SUBRANGE);
   (yyval.node)->idxstart = (yyvsp[-2].number);
   (yyval.node)->idxend = (yyvsp[0].number);
   addChild((yyval.node), newNode(DIGSEQ_TOK));
   addChild((yyval.node), newNode(PUC_DOTDOT));
   addChild((yyval.node), newNode(DIGSEQ_TOK));
}
#line 1606 "y.tab.c"
    break;

  case 10: /* array_type: ARRAY LBRAC subrange_type RBRAC OF component_type  */
#line 167 "remove_extra.y"
{
   (yyval.node) = newNode(NODE_ARRAY);
   (yyval.node)->idxstart = (yyvsp[-3].node)->idxstart;
   (yyval.node)->idxend = (yyvsp[-3].node)->idxend;
   (yyval.node)->comp_type = (yyvsp[0].node)->childs[0]->nodeType;
   addChild((yyval.node), newNode(PUC_ARR));
   addChild((yyval.node), newNode(PUC_LBRAC));
   addChild((yyval.node), (yyvsp[-3].node));
   addChild((yyval.node), newNode(PUC_RBRAC));
   addChild((yyval.node), newNode(RE_OF));
   addChild((yyval.node), (yyvsp[0].node));
}
#line 1623 "y.tab.c"
    break;

  case 11: /* component_type: INTEGER  */
#line 183 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_COMP_TYPE);
  addChild((yyval.node), newNode(TY_INT)); 
}
#line 1632 "y.tab.c"
    break;

  case 12: /* component_type: REAL  */
#line 188 "remove_extra.y"
  {
  (yyval.node) = newNode(NODE_COMP_TYPE);
  addChild((yyval.node), newNode(TY_REAL)); 
}
#line 1641 "y.tab.c"
    break;

  case 13: /* component_type: CHAR  */
#line 193 "remove_extra.y"
  {
  (yyval.node) = newNode(NODE_COMP_TYPE);
  addChild((yyval.node), newNode(TY_CHAR)); 
}
#line 1650 "y.tab.c"
    break;

  case 14: /* component_type: BOOLEAN  */
#line 198 "remove_extra.y"
  {
  (yyval.node) = newNode(NODE_COMP_TYPE);
  addChild((yyval.node), newNode(TY_BOOL)); 
}
#line 1659 "y.tab.c"
    break;

  case 15: /* variable_declaration_part: VAR variable_declaration_list semicolon  */
#line 205 "remove_extra.y"
 {
   (yyval.node) = newNode(NODE_VAR_DECL_PART);
   addChild((yyval.node), newNode(RE_VAR));
   addChild((yyval.node), (yyvsp[-1].node));
   addChild((yyval.node), newNode(PUC_SEMI));
}
#line 1670 "y.tab.c"
    break;

  case 16: /* variable_declaration_part: %empty  */
#line 212 "remove_extra.y"
 {
   (yyval.node) = newNode(NODE_VAR_DECL_PART);
   }
#line 1678 "y.tab.c"
    break;

  case 17: /* variable_declaration_list: variable_declaration_list semicolon variable_declaration  */
#line 219 "remove_extra.y"
   {
      (yyval.node) = (yyvsp[-2].node);
    addChild((yyval.node),newNode(PUC_SEMI));
    addChild((yyval.node), (yyvsp[0].node));
   }
#line 1688 "y.tab.c"
    break;

  case 18: /* variable_declaration_list: variable_declaration  */
#line 225 "remove_extra.y"
 {
      (yyval.node) = newNode(NODE_VAR_ID_LIST);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 1697 "y.tab.c"
    break;

  case 19: /* variable_declaration: identifier_list COLON var_type  */
#line 232 "remove_extra.y"
{
    (yyval.node) = newNode(NODE_VAR_DECL);
    addChild((yyval.node), (yyvsp[-2].node));
    addChild((yyval.node), newNode(PUC_COLON));
    addChild((yyval.node), (yyvsp[0].node));
    Node *nodechild = (yyvsp[0].node)->childs[0];
    int type;
    switch (nodechild->nodeType) {
        case TY_INT:
            type = TYPE_INTEGER;
            break;
        case TY_REAL:
            type = TYPE_REAL;
            break;
        case TY_CHAR:
            type = TYPE_CHAR;
            break;
        case TY_BOOL:
            type = TYPE_BOOLEAN;
            break;
        case NODE_ARRAY:
            type = TYPE_ARRAY;
            break;
        default:
            // Default to integer if unknown type
            type = TYPE_INTEGER;
    }

    int num_childs = 0;
        while ((yyvsp[-2].node)->childs[num_childs] != NULL) {
            num_childs++;
        }

    for (int i = 0; i < num_childs; i++) {
        Node* idNode = (yyvsp[-2].node)->childs[i];
        if(idNode->nodeType==PUC_COMMA)continue;
        if(isSymbolPresent(idNode->strValue))
        {
            printf("SEMANTIC ERROR(1) : Multiple Declarations of the variable: %s\n",idNode->strValue);
        }
        SymbolValue value;
        if(type == TYPE_ARRAY)
        {
          value.int_val = 0;
          insertSymbol(idNode->strValue,TYPE_ARRAY , value);
          insertArray(idNode->strValue,nodechild->comp_type);
          int start = nodechild->idxstart;
          
          int end = nodechild->idxend;
          int newtype = nodechild->comp_type;
          int arraynewtype=0;
          switch (newtype) {
            case TY_INT:
            arraynewtype = TYPE_INTEGER;
            break;
            case TY_REAL:
            arraynewtype = TYPE_REAL;
            break;
            case TY_CHAR:
            arraynewtype = TYPE_CHAR;
            break;
            case TY_BOOL:
            arraynewtype = TYPE_BOOLEAN;
            break;
            default:
            // Default to integer if unknown type
            type = TYPE_INTEGER;
          }
          
          switch (arraynewtype) {
            case TYPE_INTEGER:
                value.int_val = 0;
                break;
            case TYPE_REAL:
                value.real_val = 0.0;
                break;
            case TYPE_CHAR:
                value.char_val = '\0';
                break;
            case TYPE_BOOLEAN:
                value.bool_val = 0; // 0 for false
                break;
            default:
                // Default to integer if unknown type
                value.int_val = 0;
          }
          for(int j=start ; j<=end;j++)
          {
            char buffer[100];
            snprintf(buffer, sizeof(buffer), "%s[%d]", idNode->strValue, j);
            if(isSymbolPresent(buffer))
        {
            printf("SEMANTIC ERROR(1): Multiple Declarations of the variable: %s\n",idNode->strValue);
            break;
        }
            insertSymbol(buffer, arraynewtype, value);
          }
          continue;
        }

        switch (type) {
            case TYPE_INTEGER:
                value.int_val = 0;
                break;
            case TYPE_REAL:
                value.real_val = 0.0;
                break;
            case TYPE_CHAR:
                value.char_val = '\0';
                break;
            case TYPE_BOOLEAN:
                value.bool_val = 0; // 0 for false
                break;
            default:
                // Default to integer if unknown type
                value.int_val = 0;
        }
        insertSymbol(idNode->strValue, type, value);
    }
}
#line 1822 "y.tab.c"
    break;

  case 20: /* var_type: INTEGER  */
#line 357 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_VAR_TYPE);
  addChild((yyval.node), newNode(TY_INT)); 
}
#line 1831 "y.tab.c"
    break;

  case 21: /* var_type: REAL  */
#line 362 "remove_extra.y"
  {
  (yyval.node) = newNode(NODE_VAR_TYPE);
  addChild((yyval.node), newNode(TY_REAL)); 
}
#line 1840 "y.tab.c"
    break;

  case 22: /* var_type: CHAR  */
#line 367 "remove_extra.y"
  {
  (yyval.node) = newNode(NODE_VAR_TYPE);
  addChild((yyval.node), newNode(TY_CHAR)); 
}
#line 1849 "y.tab.c"
    break;

  case 23: /* var_type: BOOLEAN  */
#line 372 "remove_extra.y"
  {
  (yyval.node) = newNode(NODE_VAR_TYPE);
  addChild((yyval.node), newNode(TY_BOOL)); 
}
#line 1858 "y.tab.c"
    break;

  case 24: /* var_type: array_type  */
#line 377 "remove_extra.y"
  {
  (yyval.node) = newNode(NODE_VAR_TYPE);
  (yyval.node)->comp_type = (yyvsp[0].node)->comp_type;
  addChild((yyval.node), (yyvsp[0].node)); 
}
#line 1868 "y.tab.c"
    break;

  case 25: /* statement_part: compound_statement  */
#line 385 "remove_extra.y"
{
  (yyval.node) = newNode(NODE_STMT_PART);
   addChild((yyval.node), (yyvsp[0].node));
}
#line 1877 "y.tab.c"
    break;

  case 26: /* compound_statement: PBEGIN statement_sequence END  */
#line 392 "remove_extra.y"
{
   
  (yyval.node) = newNode(NODE_COMP_STMT);
   addChild((yyval.node), newNode(RE_BEGIN));
   addChild((yyval.node), (yyvsp[-1].node));
   addChild((yyval.node), newNode(RE_END));

}
#line 1890 "y.tab.c"
    break;

  case 27: /* statement_sequence: statement_sequence semicolon statement  */
#line 404 "remove_extra.y"
 {
      (yyval.node) = (yyvsp[-2].node);
    addChild((yyval.node),newNode(PUC_SEMI));
    addChild((yyval.node), (yyvsp[0].node));
   }
#line 1900 "y.tab.c"
    break;

  case 28: /* statement_sequence: statement  */
#line 410 "remove_extra.y"
  {
      (yyval.node) = newNode(NODE_STMT_SEQ);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 1909 "y.tab.c"
    break;

  case 29: /* statement: open_statement  */
#line 417 "remove_extra.y"
 {
      (yyval.node) = newNode(NODE_STMT);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 1918 "y.tab.c"
    break;

  case 30: /* statement: closed_statement  */
#line 422 "remove_extra.y"
  {
      (yyval.node) = newNode(NODE_STMT);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 1927 "y.tab.c"
    break;

  case 31: /* open_statement: label COLON non_labeled_open_statement  */
#line 429 "remove_extra.y"
{
  (yyval.node) = newNode(NODE_OPEN_STMT);
  addChild((yyval.node), (yyvsp[-2].node));
  addChild((yyval.node), newNode(PUC_COLON));
  addChild((yyval.node), (yyvsp[0].node));
}
#line 1938 "y.tab.c"
    break;

  case 32: /* open_statement: non_labeled_open_statement  */
#line 436 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_OPEN_STMT);
  addChild((yyval.node), (yyvsp[0].node));
}
#line 1947 "y.tab.c"
    break;

  case 33: /* closed_statement: label COLON non_labeled_closed_statement  */
#line 443 "remove_extra.y"
  {
  (yyval.node) = newNode(NODE_CLOSED_STMT);
  addChild((yyval.node), (yyvsp[-2].node));
  addChild((yyval.node), newNode(PUC_COLON));
  addChild((yyval.node), (yyvsp[0].node));
}
#line 1958 "y.tab.c"
    break;

  case 34: /* closed_statement: non_labeled_closed_statement  */
#line 450 "remove_extra.y"
  {
  (yyval.node) = newNode(NODE_CLOSED_STMT);
  addChild((yyval.node), (yyvsp[0].node));
}
#line 1967 "y.tab.c"
    break;

  case 35: /* non_labeled_closed_statement: assignment_statement  */
#line 456 "remove_extra.y"
 {
      (yyval.node) = newNode(NODE_NL_CLOSED);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 1976 "y.tab.c"
    break;

  case 36: /* non_labeled_closed_statement: read_statement  */
#line 461 "remove_extra.y"
  {
      (yyval.node) = newNode(NODE_NL_CLOSED);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 1985 "y.tab.c"
    break;

  case 37: /* non_labeled_closed_statement: write_statement  */
#line 466 "remove_extra.y"
  {
      (yyval.node) = newNode(NODE_NL_CLOSED);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 1994 "y.tab.c"
    break;

  case 38: /* non_labeled_closed_statement: compound_statement  */
#line 471 "remove_extra.y"
  {
      (yyval.node) = newNode(NODE_NL_CLOSED);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 2003 "y.tab.c"
    break;

  case 39: /* non_labeled_closed_statement: closed_if_statement  */
#line 476 "remove_extra.y"
  {
      (yyval.node) = newNode(NODE_NL_CLOSED);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 2012 "y.tab.c"
    break;

  case 40: /* non_labeled_closed_statement: closed_while_statement  */
#line 481 "remove_extra.y"
  {
      (yyval.node) = newNode(NODE_NL_CLOSED);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 2021 "y.tab.c"
    break;

  case 41: /* non_labeled_closed_statement: closed_for_statement  */
#line 486 "remove_extra.y"
  {
      (yyval.node) = newNode(NODE_NL_CLOSED);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 2030 "y.tab.c"
    break;

  case 42: /* non_labeled_closed_statement: %empty  */
#line 491 "remove_extra.y"
 {
      (yyval.node) = newNode(NODE_NL_CLOSED);
 }
#line 2038 "y.tab.c"
    break;

  case 43: /* non_labeled_open_statement: open_if_statement  */
#line 497 "remove_extra.y"
 {
      (yyval.node) = newNode(NODE_NL_OPEN);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 2047 "y.tab.c"
    break;

  case 44: /* non_labeled_open_statement: open_while_statement  */
#line 502 "remove_extra.y"
  {
      (yyval.node) = newNode(NODE_NL_OPEN);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 2056 "y.tab.c"
    break;

  case 45: /* non_labeled_open_statement: open_for_statement  */
#line 507 "remove_extra.y"
  {
      (yyval.node) = newNode(NODE_NL_OPEN);
   addChild((yyval.node), (yyvsp[0].node));
 }
#line 2065 "y.tab.c"
    break;

  case 46: /* open_while_statement: WHILE boolean_expression DO open_statement  */
#line 513 "remove_extra.y"
{
       (yyval.node) = newNode(NODE_OPEN_WHILE);
      addChild((yyval.node), newNode(RE_WHILE));
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(RE_DO));
      addChild((yyval.node), (yyvsp[0].node));
   }
#line 2077 "y.tab.c"
    break;

  case 47: /* closed_while_statement: WHILE boolean_expression DO closed_statement  */
#line 523 "remove_extra.y"
{
       (yyval.node) = newNode(NODE_CLOSED_WHILE);
      addChild((yyval.node), newNode(RE_WHILE));
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(RE_DO));
      addChild((yyval.node), (yyvsp[0].node));
   }
#line 2089 "y.tab.c"
    break;

  case 48: /* open_for_statement: FOR control_variable ASSIGNMENT initial_value direction final_value DO open_statement  */
#line 534 "remove_extra.y"
{

       (yyval.node) = newNode(NODE_OPEN_FOR);
      addChild((yyval.node), newNode(RE_FOR));
      addChild((yyval.node), (yyvsp[-6].node));
      addChild((yyval.node), newNode(RE_ASGMNT));
      addChild((yyval.node), (yyvsp[-4].node));
      addChild((yyval.node), (yyvsp[-3].node));
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(RE_DO));
      addChild((yyval.node), (yyvsp[0].node));

}
#line 2107 "y.tab.c"
    break;

  case 49: /* closed_for_statement: FOR control_variable ASSIGNMENT initial_value direction final_value DO closed_statement  */
#line 551 "remove_extra.y"
   {
       (yyval.node) = newNode(NODE_CLOSED_FOR);
      addChild((yyval.node), newNode(RE_FOR));
      addChild((yyval.node), (yyvsp[-6].node));
      addChild((yyval.node), newNode(RE_ASGMNT));
      addChild((yyval.node), (yyvsp[-4].node));
      addChild((yyval.node), (yyvsp[-3].node));
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(RE_DO));
      addChild((yyval.node), (yyvsp[0].node));
      if((yyvsp[-6].node)->typeVar != (yyvsp[-4].node)->typeVar)
    {
      printf("SEMANTIC ERROR(3) : Type Mismatch : (%s) %s (%s)\n",convertType((yyvsp[-6].node)->typeVar) , ":=",convertType((yyvsp[-4].node)->typeVar));
    }
    if((yyvsp[-6].node)->typeVar != (yyvsp[-2].node)->typeVar)
    {
      printf("SEMANTIC ERROR(3) : Type Mismatch : (%s) %s (%s)\n",convertType((yyvsp[-6].node)->typeVar) , ":=",convertType((yyvsp[-2].node)->typeVar));
    }
    
}
#line 2132 "y.tab.c"
    break;

  case 50: /* open_if_statement: IF boolean_expression THEN statement  */
#line 573 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_OPEN_IF);
  addChild((yyval.node), newNode(RE_IF));
  addChild((yyval.node), (yyvsp[-2].node));
  addChild((yyval.node), newNode(RE_THEN));
  addChild((yyval.node), (yyvsp[0].node));
}
#line 2144 "y.tab.c"
    break;

  case 51: /* open_if_statement: IF boolean_expression THEN closed_statement ELSE open_statement  */
#line 581 "remove_extra.y"
  {
  (yyval.node) = newNode(NODE_OPEN_IF);
  addChild((yyval.node), newNode(RE_IF));
  addChild((yyval.node), (yyvsp[-4].node));
  addChild((yyval.node), newNode(RE_THEN));
  addChild((yyval.node), (yyvsp[-2].node));
  addChild((yyval.node), newNode(RE_ELSE));
  addChild((yyval.node), (yyvsp[0].node));
}
#line 2158 "y.tab.c"
    break;

  case 52: /* closed_if_statement: IF boolean_expression THEN closed_statement ELSE closed_statement  */
#line 594 "remove_extra.y"
   {
       (yyval.node) = newNode(NODE_CLOSED_IF);
      addChild((yyval.node), newNode(RE_IF));
      addChild((yyval.node), (yyvsp[-4].node));
      addChild((yyval.node), newNode(RE_THEN));
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(RE_ELSE));
      addChild((yyval.node), (yyvsp[0].node));
   }
#line 2172 "y.tab.c"
    break;

  case 53: /* assignment_statement: variable_access ASSIGNMENT expression  */
#line 606 "remove_extra.y"
{
       (yyval.node) = newNode(NODE_ASGMNT_STMT);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(RE_ASGMNT));
      addChild((yyval.node), (yyvsp[0].node));
      if((yyvsp[-2].node)->typeVar != (yyvsp[0].node)->typeVar)
    {
      printf("SEMANTIC ERROR(3) : Type Mismatch : (%s) %s (%s)\n",convertType((yyvsp[-2].node)->typeVar) , ":=",convertType((yyvsp[0].node)->typeVar));
    }
    (yyval.node)->typeVar = (yyvsp[-2].node)->typeVar;
//     SymbolValue value;
//     switch ($$->typeVar) {
//             case TY_INT:
//                 value.int_val = $3->iValue;
//                 printf("in assignment:%d\n",$3->iValue);
//                 break;
//             case TY_REAL:
//                 value.real_val = $3->rValue;
//                 break;
//             case TY_CHAR:
//                 value.char_val = $3->cValue;
//                 break;
//             case TY_BOOL:
//                 value.bool_val = $3->bValue; // 0 for false
//                 break;
//             default:
//                 // Default to integer if unknown type
//                 value.int_val = $3->iValue;
//                 //printf("in assignment:%d\n",$3->iValue);
//           }
//           printf("in assignment:%s\n",$1->strValue);
//           insertSymbol($1->strValue,$1->typeVar,value);
}
#line 2210 "y.tab.c"
    break;

  case 54: /* read_statement: READ LPAREN identifier_1 RPAREN  */
#line 642 "remove_extra.y"
   {
  (yyval.node) = newNode(NODE_READ_STMT);
  addChild((yyval.node), newNode(RE_READ));
  addChild((yyval.node), newNode(PUC_LPAREN));
  addChild((yyval.node), (yyvsp[-1].node));
  addChild((yyval.node), newNode(PUC_RPAREN));
  //SymbolType type = getSymbolType($3->strValue);
  //SymbolValue value;
  /*char inout[100];
      switch (type) {
        case TYPE_INTEGER:
            $$->typeVar = TY_INT;
            int temp1;
            printf("inside int\n");
            scanf("%d",&temp1);
            // int num = atoi(inout);
            value.int_val=temp1;
            break;
        case TYPE_REAL:
            $$->typeVar = TY_REAL;
            double temp2;
            scanf("%lf",&temp2);
            value.real_val=temp2;
            break;
        case TYPE_CHAR:
            $$->typeVar = TY_CHAR;
            char temp3;
            printf("inside\n");
            scanf(" %c",&temp3);
            value.char_val=temp3;
            printf("inside%c\n",temp3);
            break;
        case TYPE_BOOLEAN:
            $$->typeVar = TY_BOOL;
            int temp4;
            scanf("%d",&temp4);
            value.bool_val=temp4;
            break;
        case TYPE_ARRAY:
            $$->typeVar = TY_ARRAY;
            break;
    }
    insertSymbol($3->strValue,type,value);
    */
}
#line 2260 "y.tab.c"
    break;

  case 55: /* write_statement: WRITE LPAREN list RPAREN  */
#line 690 "remove_extra.y"
  {
  (yyval.node) = newNode(NODE_WRITE_STMT);
  addChild((yyval.node), newNode(RE_WRITE));
  addChild((yyval.node), newNode(PUC_LPAREN));
  addChild((yyval.node), (yyvsp[-1].node));
  addChild((yyval.node), newNode(PUC_RPAREN));
}
#line 2272 "y.tab.c"
    break;

  case 56: /* list: CHARACTER_STRING  */
#line 701 "remove_extra.y"
{
       (yyval.node) = newNode(NODE_LIST);
      addChild((yyval.node), newNode(CHAR_STRING_TOK));
      (yyval.node)->strValue = (yyvsp[0].string);
}
#line 2282 "y.tab.c"
    break;

  case 57: /* list: identifier_list_1  */
#line 707 "remove_extra.y"
{
       (yyval.node) = newNode(NODE_LIST);
      addChild((yyval.node), (yyvsp[0].node));
      (yyval.node)->typeVar = (yyvsp[0].node)->typeVar;
}
#line 2292 "y.tab.c"
    break;

  case 58: /* identifier_list_1: identifier_list_1 comma identifier_1  */
#line 715 "remove_extra.y"
{
   (yyval.node) = (yyvsp[-2].node);
    addChild((yyval.node),newNode(PUC_COMMA));
    addChild((yyval.node), (yyvsp[0].node));
    (yyval.node)->typeVar = (yyvsp[-2].node)->typeVar;
}
#line 2303 "y.tab.c"
    break;

  case 59: /* identifier_list_1: identifier_1  */
#line 722 "remove_extra.y"
 {
   (yyval.node) = newNode(NODE_ID_LIST1);
   addChild((yyval.node), (yyvsp[0].node));
  //  if(!(isSymbolPresent($1->strValue)))
  //       {
  //           printf("SEMANTIC ERROR(2) : Use without declaration of the variable: %s\n",$1->strValue);
  //       }
    //SymbolType type = getSymbolType($1->strValue);
    //   switch (type) {
    //     case TYPE_INTEGER:
    //         $$->typeVar = TY_INT;
    //         break;
    //     case TYPE_REAL:
    //         $$->typeVar = TY_REAL;
    //         break;
    //     case TYPE_CHAR:
    //         $$->typeVar = TY_CHAR;
    //         break;
    //     case TYPE_BOOLEAN:
    //         $$->typeVar = TY_BOOL;
    //         break;
    //     case TYPE_ARRAY:
    //         $$->typeVar = TY_ARRAY;
    //         break;
    // }
 }
#line 2334 "y.tab.c"
    break;

  case 60: /* identifier_1: identifier  */
#line 752 "remove_extra.y"
{
       (yyval.node) = newNode(NODE_ID1);
      addChild((yyval.node), (yyvsp[0].node));
      if(!(isSymbolPresent((yyvsp[0].node)->strValue)))
        {
            printf("SEMANTIC ERROR (2) : Use without declaration of the variable: %s\n",(yyvsp[0].node)->strValue);
        }
        SymbolType type = getSymbolType((yyvsp[0].node)->strValue);
      switch (type) {
        case TYPE_INTEGER:
            (yyval.node)->typeVar = TY_INT;
            //$$->iValue = (int)getSymbolValue($1->strValue).int_val;
            break;
        case TYPE_REAL:
            (yyval.node)->typeVar = TY_REAL;
            //$$->rValue = (double)getSymbolValue($1->strValue).real_val;
            break;
        case TYPE_CHAR:
            (yyval.node)->typeVar = TY_CHAR;
            //$$->cValue = (char)getSymbolValue($1->strValue).char_val;
            break;
        case TYPE_BOOLEAN:
            (yyval.node)->typeVar = TY_BOOL;
            //$$->bValue = (int)getSymbolValue($1->strValue).bool_val;
            break;
        case TYPE_ARRAY:
            (yyval.node)->typeVar = getArrayType((yyvsp[0].node)->strValue);
            break;
    }
    (yyval.node)->strValue = (yyvsp[0].node)->strValue;
}
#line 2370 "y.tab.c"
    break;

  case 61: /* identifier_1: indexed_variable  */
#line 784 "remove_extra.y"
{
       (yyval.node) = newNode(NODE_ID1);
      addChild((yyval.node), (yyvsp[0].node));
      (yyval.node)->typeVar = (yyvsp[0].node)->typeVar;
}
#line 2380 "y.tab.c"
    break;

  case 62: /* variable_access: identifier  */
#line 792 "remove_extra.y"
{
       (yyval.node) = newNode(NODE_VAR_ACC);
      addChild((yyval.node), (yyvsp[0].node));
      if(!(isSymbolPresent((yyvsp[0].node)->strValue)))
        {
            printf("SEMANTIC ERROR(2) : Use without declaration of the variable: %s\n",(yyvsp[0].node)->strValue);
        }
      SymbolType type = getSymbolType((yyvsp[0].node)->strValue);
      switch (type) {
        case TYPE_INTEGER:
            (yyval.node)->typeVar = TY_INT;
            //$$->iValue = (int)getSymbolValue($1->strValue).int_val;
            break;
        case TYPE_REAL:
            (yyval.node)->typeVar = TY_REAL;
            //$$->rValue = (double)getSymbolValue($1->strValue).real_val;
            break;
        case TYPE_CHAR:
            (yyval.node)->typeVar = TY_CHAR;
            //$$->cValue = (char)getSymbolValue($1->strValue).char_val;
            break;
        case TYPE_BOOLEAN:
            (yyval.node)->typeVar = TY_BOOL;
            //$$->bValue = (int)getSymbolValue($1->strValue).bool_val;
            break;
        case TYPE_ARRAY:
            (yyval.node)->typeVar = getArrayType((yyvsp[0].node)->strValue);
            break;
    }
    (yyval.node)->strValue = (yyvsp[0].node)->strValue;
}
#line 2416 "y.tab.c"
    break;

  case 63: /* variable_access: indexed_variable  */
#line 824 "remove_extra.y"
 {
       (yyval.node) = newNode(NODE_VAR_ACC);
      addChild((yyval.node), (yyvsp[0].node));
      (yyval.node)->typeVar = (yyvsp[0].node)->typeVar;
}
#line 2426 "y.tab.c"
    break;

  case 64: /* indexed_variable: variable_access LBRAC expression RBRAC  */
#line 832 "remove_extra.y"
{
   (yyval.node) = newNode(NODE_IND_VAR);
   addChild((yyval.node), (yyvsp[-3].node));
   addChild((yyval.node), newNode(PUC_LBRAC));
   addChild((yyval.node), (yyvsp[-1].node));
   addChild((yyval.node), newNode(PUC_RBRAC));
  (yyval.node)->typeVar = (yyvsp[-3].node)->typeVar;
}
#line 2439 "y.tab.c"
    break;

  case 65: /* control_variable: identifier  */
#line 843 "remove_extra.y"
{
 	(yyval.node) = newNode(NODE_CONT_VAR);
    addChild((yyval.node), (yyvsp[0].node));
    if(!(isSymbolPresent((yyvsp[0].node)->strValue)))
        {
            printf("SEMANTIC ERROR(2) : Use without declaration of the variable: %s\n",(yyvsp[0].node)->strValue);
        }
    SymbolType type = getSymbolType((yyvsp[0].node)->strValue);
      switch (type) {
        case TYPE_INTEGER:
            (yyval.node)->typeVar = TY_INT;
            //$$->iValue = (int)getSymbolValue($1->strValue).int_val;
            break;
        case TYPE_REAL:
            (yyval.node)->typeVar = TY_REAL;
            //$$->rValue = (double)getSymbolValue($1->strValue).real_val;
            break;
        case TYPE_CHAR:
            (yyval.node)->typeVar = TY_CHAR;
            //$$->cValue = (char)getSymbolValue($1->strValue).char_val;
            break;
        case TYPE_BOOLEAN:
            (yyval.node)->typeVar = TY_BOOL;
            //$$->bValue = (int)getSymbolValue($1->strValue).bool_val;
            break;
        case TYPE_ARRAY:
            (yyval.node)->typeVar = getArrayType((yyvsp[0].node)->strValue);
            break;
    }
    (yyval.node)->strValue = (yyvsp[0].node)->strValue;
 }
#line 2475 "y.tab.c"
    break;

  case 66: /* initial_value: expression  */
#line 876 "remove_extra.y"
{
 	(yyval.node) = newNode(NODE_INIT_VAL);
    addChild((yyval.node), (yyvsp[0].node));
    (yyval.node)->typeVar = (yyvsp[0].node)->typeVar;
    // switch ($1->typeVar) {
    //     case TY_INT:
    //         $$->iValue = $1->iValue;
    //         printf("in expression: %d\n",$$->iValue);
    //         break;
    //     case TY_REAL:
    //         $$->rValue = $1->rValue;
    //         break;
    //     case TY_CHAR:
    //         $$->cValue = $1->cValue;
    //         break;
    //     case TY_BOOL:
    //         $$->bValue =$$->bValue;
    //         break;
    //     case NODE_ARRAY:
    //         break;
    // }
    
 }
#line 2503 "y.tab.c"
    break;

  case 67: /* direction: TO  */
#line 901 "remove_extra.y"
{
 	(yyval.node) = newNode(NODE_DIR);
    addChild((yyval.node), newNode(RE_TO));
 }
#line 2512 "y.tab.c"
    break;

  case 68: /* direction: DOWNTO  */
#line 906 "remove_extra.y"
 {
 	(yyval.node) = newNode(NODE_DIR);
    addChild((yyval.node), newNode(RE_DOWNTO));
 }
#line 2521 "y.tab.c"
    break;

  case 69: /* final_value: expression  */
#line 913 "remove_extra.y"
{
 	(yyval.node) = newNode(NODE_FIN_VAL);
    addChild((yyval.node), (yyvsp[0].node));
    (yyval.node)->typeVar = (yyvsp[0].node)->typeVar;
    // switch ($1->typeVar) {
    //     case TY_INT:
    //         $$->iValue = $1->iValue;
    //         printf("in expression: %d\n",$$->iValue);
    //         break;
    //     case TY_REAL:
    //         $$->rValue = $1->rValue;
    //         break;
    //     case TY_CHAR:
    //         $$->cValue = $1->cValue;
    //         break;
    //     case TY_BOOL:
    //         $$->bValue =$$->bValue;
    //         break;
    //     case NODE_ARRAY:
    //         break;
    // }
 }
#line 2548 "y.tab.c"
    break;

  case 70: /* boolean_expression: expression  */
#line 937 "remove_extra.y"
{
 	(yyval.node) = newNode(NODE_BOOL_EXPR);
    addChild((yyval.node), (yyvsp[0].node));
    (yyval.node)->typeVar = (yyvsp[0].node)->typeVar;
    // switch ($1->typeVar) {
    //     case TY_INT:
    //         $$->iValue = $1->iValue;
    //         //printf("in expression: %d\n",$$->iValue);
    //         break;
    //     case TY_REAL:
    //         $$->rValue = $1->rValue;
    //         break;
    //     case TY_CHAR:
    //         $$->cValue = $1->cValue;
    //         break;
    //     case TY_BOOL:
    //         $$->bValue =$$->bValue;
    //         break;
    //     case NODE_ARRAY:
    //         break;
    // }
 }
#line 2575 "y.tab.c"
    break;

  case 71: /* expression: simple_expression  */
#line 962 "remove_extra.y"
{
 	(yyval.node) = newNode(NODE_EXPR);
    addChild((yyval.node), (yyvsp[0].node));
    (yyval.node)->typeVar = (yyvsp[0].node)->typeVar;
    // switch ($1->typeVar) {
    //     case TY_INT:
    //         $$->iValue = $1->iValue;
    //         //printf("in expression: %d\n",$$->iValue);
    //         break;
    //     case TY_REAL:
    //         $$->rValue = $1->rValue;
    //         break;
    //     case TY_CHAR:
    //         $$->cValue = $1->cValue;
    //         break;
    //     case TY_BOOL:
    //         $$->bValue =$$->bValue;
    //         break;
    //     case NODE_ARRAY:
    //         break;
    // }
 }
#line 2602 "y.tab.c"
    break;

  case 72: /* expression: simple_expression relop simple_expression  */
#line 985 "remove_extra.y"
{
 	(yyval.node) = newNode(NODE_EXPR);
    addChild((yyval.node), (yyvsp[-2].node));
    addChild((yyval.node), (yyvsp[-1].node));
    addChild((yyval.node), (yyvsp[0].node));
    if((yyvsp[-2].node)->typeVar != (yyvsp[0].node)->typeVar)
    {
      printf("SEMANTIC ERROR(3) : Type Mismatch : (%s) %s (%s)\n",convertType((yyvsp[-2].node)->typeVar) , (yyvsp[-1].node)->op,convertType((yyvsp[0].node)->typeVar));
    }
    (yyval.node)->typeVar = (yyvsp[-2].node)->typeVar;
    
    //RelOperation($$,$1,$2->op,$3);
    //printf("in expression: %d\n",$$->iValue);
 }
#line 2621 "y.tab.c"
    break;

  case 73: /* simple_expression: term  */
#line 1002 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_SIMPLE_EXP);
  addChild((yyval.node), (yyvsp[0].node)); 
  (yyval.node)->typeVar = (yyvsp[0].node)->typeVar;
  // switch ($1->typeVar) {
  //       case TY_INT:
  //           $$->iValue = $1->iValue;
  //           //printf("in simple: %d\n",$$->iValue);
  //           break;
  //       case TY_REAL:
  //           $$->rValue = $1->rValue;
  //           break;
  //       case TY_CHAR:
  //           $$->cValue = $1->cValue;
  //           break;
  //       case TY_BOOL:
  //           $$->bValue =$$->bValue;
  //           break;
  //       case NODE_ARRAY:
  //           break;
  //   }
}
#line 2648 "y.tab.c"
    break;

  case 74: /* simple_expression: simple_expression addop term  */
#line 1025 "remove_extra.y"
 {
    (yyval.node) = (yyvsp[-2].node);
    addChild((yyval.node), (yyvsp[-1].node));
    addChild((yyval.node), (yyvsp[0].node)); 
    if((yyvsp[-2].node)->typeVar != (yyvsp[0].node)->typeVar)
    {
      printf("SEMANTIC ERROR(3) : Type Mismatch : (%s) %s (%s)\n",convertType((yyvsp[-2].node)->typeVar) , (yyvsp[-1].node)->op,convertType((yyvsp[0].node)->typeVar));
    }
    (yyval.node)->typeVar = (yyvsp[-2].node)->typeVar;
    //AddOperation($$,$2->op,$3);
 }
#line 2664 "y.tab.c"
    break;

  case 75: /* term: primary  */
#line 1039 "remove_extra.y"
{
      (yyval.node) = newNode(NODE_TERM);
   addChild((yyval.node), (yyvsp[0].node));
   (yyval.node)->typeVar = (yyvsp[0].node)->typeVar;
  //  switch ($1->typeVar) {
  //       case TY_INT:
  //           $$->iValue = $1->iValue;
  //           break;
  //       case TY_REAL:
  //           $$->rValue = $1->rValue;
  //           break;
  //       case TY_CHAR:
  //           $$->cValue = $1->cValue;
  //           break;
  //       case TY_BOOL:
  //           $$->bValue =$$->bValue;
  //           break;
  //       case NODE_ARRAY:
  //           break;
  //   }
 }
#line 2690 "y.tab.c"
    break;

  case 76: /* term: term mulop primary  */
#line 1061 "remove_extra.y"
{
      (yyval.node) = (yyvsp[-2].node);
   addChild((yyval.node), (yyvsp[-1].node));
   addChild((yyval.node), (yyvsp[0].node));
   if((yyvsp[-2].node)->typeVar != (yyvsp[0].node)->typeVar)
    {
      printf("SEMANTIC ERROR(3) : Type Mismatch : (%s) %s (%s)\n",convertType((yyvsp[-2].node)->typeVar) , (yyvsp[-1].node)->op,convertType((yyvsp[0].node)->typeVar));
    }
    (yyval.node)->typeVar = (yyvsp[-2].node)->typeVar;
    //MulOperation($$,$2->op,$3);
 }
#line 2706 "y.tab.c"
    break;

  case 77: /* primary: variable_access  */
#line 1075 "remove_extra.y"
 {
      (yyval.node) = newNode(NODE_PRIMARY);
   addChild((yyval.node), (yyvsp[0].node));
   (yyval.node)->typeVar = (yyvsp[0].node)->typeVar;
    // switch ($1->typeVar) {
    //     case TY_INT:
    //         $$->iValue = $1->iValue;
    //         break;
    //     case TY_REAL:
    //         $$->rValue = $1->rValue;
    //         break;
    //     case TY_CHAR:
    //         $$->cValue = $1->cValue;
    //         break;
    //     case TY_BOOL:
    //         $$->bValue =$$->bValue;
    //         break;
    //     case NODE_ARRAY:
    //         break;
    // }
 }
#line 2732 "y.tab.c"
    break;

  case 78: /* primary: unsigned_constant  */
#line 1097 "remove_extra.y"
  {
      (yyval.node) = newNode(NODE_PRIMARY);
   addChild((yyval.node), (yyvsp[0].node));
   (yyval.node)->typeVar = (yyvsp[0].node)->typeVar;
  //  switch ($1->typeVar) {
  //       case TY_INT:
  //           $$->iValue = $1->iValue;
  //           break;
  //       case TY_REAL:
  //           $$->rValue = $1->rValue;
  //           break;
  //       case TY_CHAR:
  //           $$->cValue = $1->cValue;
  //           break;
  //       case TY_BOOL:
  //           $$->bValue =$$->bValue;
  //           break;
  //       case NODE_ARRAY:
  //           break;
  //   }
 }
#line 2758 "y.tab.c"
    break;

  case 79: /* primary: LPAREN expression RPAREN  */
#line 1119 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_PRIMARY);
  addChild((yyval.node), newNode(PUC_LPAREN));
  addChild((yyval.node), (yyvsp[-1].node));
  addChild((yyval.node), newNode(PUC_RPAREN));
  (yyval.node)->typeVar = (yyvsp[-1].node)->typeVar;
  //  switch ($2->typeVar) {
  //       case TY_INT:
  //           $$->iValue = $2->iValue;
  //           break;
  //       case TY_REAL:
  //           $$->rValue = $2->rValue;
  //           break;
  //       case TY_CHAR:
  //           $$->cValue = $2->cValue;
  //           break;
  //       case TY_BOOL:
  //           $$->bValue =$$->bValue;
  //           break;
  //       case NODE_ARRAY:
  //           break;
  //   }
}
#line 2786 "y.tab.c"
    break;

  case 80: /* primary: NOT primary  */
#line 1143 "remove_extra.y"
  {
  addChild((yyval.node), newNode(RE_NOT));
  (yyval.node)=(yyvsp[0].node);
  (yyval.node)->typeVar = TY_BOOL;
  //  switch ($2->typeVar) {
  //       case TY_INT:
  //           $$->bValue = ($2->iValue==0)?1:0;
  //           break;
  //       case TY_REAL:
  //           $$->bValue = ($2->rValue==0.0)?1:0;
  //           break;
  //       case TY_CHAR:
  //           $$->cValue = $2->cValue;
  //           break;
  //       case TY_BOOL:
  //           $$->bValue =($2->bValue==0)?1:0;
  //           break;
  //       case NODE_ARRAY:
  //           break;
  //   }
}
#line 2812 "y.tab.c"
    break;

  case 81: /* unsigned_constant: DIGSEQ  */
#line 1167 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_UNSIGN_CONST);
  addChild((yyval.node), newNode(DIGSEQ_TOK));
  (yyval.node)->typeVar = TY_INT;
  (yyval.node)->iValue =(int)(yyvsp[0].number); 
}
#line 2823 "y.tab.c"
    break;

  case 82: /* unsigned_constant: REALNUMBER  */
#line 1174 "remove_extra.y"
{
  (yyval.node) = newNode(NODE_UNSIGN_CONST);
  addChild((yyval.node), newNode(REALNUMBER_TOK));
  (yyval.node)->typeVar = TY_REAL;
  (yyval.node)->rValue =(yyvsp[0].number); 
}
#line 2834 "y.tab.c"
    break;

  case 83: /* unsigned_constant: CHARACTER_STRING  */
#line 1181 "remove_extra.y"
{
    (yyval.node) = newNode(NODE_UNSIGN_CONST);
    addChild((yyval.node), newNode(CHAR_STRING_TOK));
    (yyval.node)->typeVar = TY_STR;
    (yyval.node)->strValue = (yyvsp[0].string); 
}
#line 2845 "y.tab.c"
    break;

  case 84: /* unsigned_constant: NIL  */
#line 1188 "remove_extra.y"
 {
    (yyval.node) = newNode(NODE_UNSIGN_CONST);
    addChild((yyval.node), newNode(RE_NIL));
}
#line 2854 "y.tab.c"
    break;

  case 85: /* addop: PLUS  */
#line 1198 "remove_extra.y"
{
  (yyval.node) = newNode(NODE_ADDOP);
  addChild((yyval.node), newNode(OP_PLUS));
  (yyval.node)->op = "+";
}
#line 2864 "y.tab.c"
    break;

  case 86: /* addop: MINUS  */
#line 1204 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_ADDOP);
  addChild((yyval.node), newNode(OP_MINUS));
  (yyval.node)->op = "-";
}
#line 2874 "y.tab.c"
    break;

  case 87: /* addop: OR  */
#line 1210 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_ADDOP);
  addChild((yyval.node), newNode(OP_OR));
  (yyval.node)->op = "OR";
}
#line 2884 "y.tab.c"
    break;

  case 88: /* mulop: STAR  */
#line 1218 "remove_extra.y"
{
  (yyval.node) = newNode(NODE_MULOP);
  addChild((yyval.node), newNode(OP_STAR)); 
  (yyval.node)->op = "*";
}
#line 2894 "y.tab.c"
    break;

  case 89: /* mulop: SLASH  */
#line 1224 "remove_extra.y"
{
  (yyval.node) = newNode(NODE_MULOP);
  addChild((yyval.node), newNode(OP_SLASH));
  (yyval.node)->op = "/";
}
#line 2904 "y.tab.c"
    break;

  case 90: /* mulop: DIV  */
#line 1230 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_MULOP);
  addChild((yyval.node), newNode(OP_DIV)); 
  (yyval.node)->op = "/";
}
#line 2914 "y.tab.c"
    break;

  case 91: /* mulop: MOD  */
#line 1236 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_MULOP);
  addChild((yyval.node), newNode(OP_MOD)); 
  (yyval.node)->op = "%";
}
#line 2924 "y.tab.c"
    break;

  case 92: /* mulop: AND  */
#line 1242 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_MULOP);
  addChild((yyval.node), newNode(OP_AND));
  (yyval.node)->op = "AND"; 
}
#line 2934 "y.tab.c"
    break;

  case 93: /* relop: EQUAL  */
#line 1250 "remove_extra.y"
{
  (yyval.node) = newNode(NODE_RELOP);
  addChild((yyval.node), newNode(OP_EQUAL)); 
  (yyval.node)->op = "=";
}
#line 2944 "y.tab.c"
    break;

  case 94: /* relop: NOTEQUAL  */
#line 1256 "remove_extra.y"
{
  (yyval.node) = newNode(NODE_RELOP);
  addChild((yyval.node), newNode(OP_notEQUAL)); 
  (yyval.node)->op = "<>";
}
#line 2954 "y.tab.c"
    break;

  case 95: /* relop: LT  */
#line 1262 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_RELOP);
  addChild((yyval.node), newNode(OP_LT)); 
  (yyval.node)->op = "<";
}
#line 2964 "y.tab.c"
    break;

  case 96: /* relop: GT  */
#line 1268 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_RELOP);
  addChild((yyval.node), newNode(OP_GT));
  (yyval.node)->op = ">"; 
}
#line 2974 "y.tab.c"
    break;

  case 97: /* relop: LE  */
#line 1274 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_RELOP);
  addChild((yyval.node), newNode(OP_LE)); 
  (yyval.node)->op = "<=";
}
#line 2984 "y.tab.c"
    break;

  case 98: /* relop: GE  */
#line 1280 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_RELOP);
  addChild((yyval.node), newNode(OP_GE)); 
  (yyval.node)->op = ">=";
}
#line 2994 "y.tab.c"
    break;

  case 99: /* relop: IN  */
#line 1286 "remove_extra.y"
 {
  (yyval.node) = newNode(NODE_RELOP);
  addChild((yyval.node), newNode(OP_IN)); 
  (yyval.node)->op = "IN";
}
#line 3004 "y.tab.c"
    break;

  case 100: /* identifier: IDENTIFIER  */
#line 1295 "remove_extra.y"
{
  (yyval.node) = newNode(NODE_ID);
  addChild((yyval.node), newNode(ID_TOK)); 
  
  (yyval.node)->strValue = (yyvsp[0].string);
  
}
#line 3016 "y.tab.c"
    break;

  case 101: /* semicolon: SEMICOLON  */
#line 1305 "remove_extra.y"
{
  (yyval.node) = newNode(NODE_SEMI);
  addChild((yyval.node), newNode(PUC_SEMI)); 
}
#line 3025 "y.tab.c"
    break;

  case 102: /* comma: COMMA  */
#line 1311 "remove_extra.y"
{
  (yyval.node) = newNode(NODE_COMMA);
  addChild((yyval.node), newNode(PUC_COMMA));
}
#line 3034 "y.tab.c"
    break;


#line 3038 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1318 "remove_extra.y"


 /* void readConsole()
 {
  int temp;
  scanf("%d",&temp);
  printf("%d\n",temp);

 } */
 int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Set Flex to read from the input file
    yyin = input_file;
    
     initSymbolTable();
    yyparse();
    if(syntax_error == 0){
        printf("valid input\n");
    }
    printTree(ASTROOT,0);
   
     // Print the symbol table
    //printSymbolTable();
    
    executeNode(ASTROOT);
	printSymbolTable();
    // Free the symbol table
    freeSymbolTable();
    printTreeToFile(ASTROOT);

    return 0;
}
