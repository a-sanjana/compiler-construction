#ifndef __NODE_H__
#define __NODE_H__

#include <stdlib.h>
#include <string.h>

enum ntype {
    TEST,
    VALUE_INVALID,
    NODE_INT,
    NODE_TERM,
    NODE_PROGRAM,
    NODE_BLOCK,
    NODE_PROGRAM_HEAD,
    NODE_ID,
    NODE_VAR_DECL_PART,
    NODE_VAR_DECL,
    NODE_VAR_DECL_LIST,
    NODE_VAR_TYPE,
    NODE_DECL,
    NODE_STMT,
    NODE_STMT_PART,
    NODE_STMT_SEQ,
    NODE_EXPR,
    NODE_VAR,
    NODE_ID_LIST,
    NODE_VAR_ID_LIST,
    NODE_SUBRANGE,
    NODE_COMMA,
    NODE_SEMI,
    NODE_UNSIGN_INT,
    NODE_NL_CLOSED,
    NODE_NL_OPEN,
    NODE_CLOSED_IF,
    NODE_OPEN_WHILE,
    NODE_OPEN_FOR,
    NODE_ASGMNT_STMT,
    NODE_LIST,
    CHAR_STRING_TOK,
    NODE_ID1,
    NODE_VAR_ACC,
    RE_UPARROW,
    NODE_IND_VAR,
    NODE_CLOSED_WHILE,
    NODE_COMP_TYPE,
    NODE_OPEN_STMT,
    NODE_CLOSED_STMT,
    NODE_IND_EXPR,
    NODE_CONT_VAR,
    NODE_FIELD_DES,
    NODE_INIT_VAL,
    NODE_DIR,
    RE_TO,
    RE_DOWNTO,
    NODE_FIN_VAL,
    NODE_BOOL_EXPR,
    NODE_CLOSED_FOR,
    NODE_PRIMARY,
    
    OP_ADD,
    OP_SUB,
    PUC_COMMA,
    PUC_ARR,
    PUC_LBRAC,
    PUC_RBRAC,
    PUC_DOTDOT,
    PUC_COLON,
    PUC_SEMI,
    TY_INT,
    NODE_STDTYPE,
    NODE_TYPE,
    RE_ARR,
    RE_OF,
    NODE_NUM,
    NODE_STRING,
    NODE_SIGN,
    NODE_LAMDBA,
    NODE_OPTVAR,
    NODE_RELOP,
    NODE_ADDOP,
    NODE_TREM,
    NODE_SI_EXPR,
    NODE_EXPR_LI,
    NODE_PROC_STMT,
    NODE_TAIL,
    NODE_COMP_STMT,
    NODE_STMT_LI,
    NODE_OPT_STMT,
    NODE_PARAM_LI,
    NODE_ARG,
    NODE_ARRAY,
    NODE_SPROG_H,
    NODE_SPROG_DECL,
    NODE_SPROG_DECLS,
    NODE_IF_STMT,
    NODE_OPEN_IF,
    NODE_START,
    NODE_MULOP,
    NODE_REALNUMBER,
    NODE_EXP,
    NODE_SIMPLE_EXP,
    NODE_FACTOR,
    NODE_WRITE_STMT,
    NODE_READ_STMT,
    NODE_UNSIGN_CONST,
    NODE_UNSIGN_NUM,
    OP_notEQUAL,
    OP_GE,
    OP_LE,
    OP_EQUAL,
    OP_GT,
    OP_LT,
    OP_MUL,
    OP_DIV,
    OP_PLUS,
    OP_MINUS,
    OP_STAR,
    OP_STARSTAR,
    OP_SLASH,
    OP_AND,
    OP_MOD,
    OP_IN,
    PUC_LPAREN,
    PUC_RPAREN,
    PUC_DOT,
    RE_NOT,
    RE_VAR,
    RE_ASGMNT,
    RE_IF,
    RE_THEN,
    RE_ELSE,
    RE_WHILE,
    RE_DO,
    RE_BEGIN,
    RE_END,
    RE_FUNC,
    RE_PROC,
    RE_PROG,
    RE_CONST,
    RE_WRITE,
    RE_READ,
    RE_NIL,
    RE_TYPE,

    TY_CHAR,
    TY_REAL,
    TY_BOOL,
    TY_ARRAY,
    TY_STR,
    ID_TOK,
    NUM_TOK,
    REALNUMBER_TOK,
    PRIMARY_TOK,
    SIGN_TOK,
     EXP_TOK,
    DIGSEQ_TOK,
    NODE_LABEL,
    RE_FOR,
    OP_OR,
    NODE_ID_LIST1,
};

typedef struct Node {
    int nodeType;
    struct Node *parent;
    struct Node **childs;
    int typeVar;

    /* Attribute for NODE_TOKEN */
    int tokenType;

    /* items for Array */
    int idxstart;
    int idxend;
    int comp_type;
    int arraydepth;
    struct Node *ref;

    /* Values for general use */
    int iValue;
    double rValue;
    int bValue;
    char cValue;
    char valueValid;
    char* string;
    double number;
    char* strValue;

    /* Indicates which OP */
    char* op;
} Node;

Node* newNode(int type);
void deleteNode(Node* node);
void addChild(Node *node, Node *child);
char* convertType(int type);
void printTreeToFile(Node *node);
void writeNode(Node *node);
void closeOutputFile();
void openOutputFile();

#endif
