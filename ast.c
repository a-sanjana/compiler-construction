#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "ast.h"

Node* newNode(int type) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    node->nodeType = type;
    node->valueValid = VALUE_INVALID;
    node->string = NULL;
    node->parent = NULL;
    node->childs = NULL;

    return node;
}

void addChild(Node* node, Node *child) {
    if (node == NULL || child == NULL) {
        fprintf(stderr, "Cannot add child to NULL node\n");
        exit(EXIT_FAILURE);
    }

    child->parent = node;

    if (node->childs == NULL) {
        node->childs = (Node**)malloc(sizeof(Node*));
        if (node->childs == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        node->childs[0] = child;
    } else {
        int num_childs = 0;
        while (node->childs[num_childs] != NULL) {
            num_childs++;
        }
        node->childs = (Node**)realloc(node->childs, (num_childs + 2) * sizeof(Node*));
        if (node->childs == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        node->childs[num_childs] = child;
        node->childs[num_childs + 1] = NULL;
    }
}

void deleteNode(Node *node) {
    if (node == NULL)
        return;

    if (node->string != NULL)
        free(node->string);
    if (node->childs != NULL)
        free(node->childs);
    free(node);
}

void printTree(Node *node, int ident) {
    static char blank[1024];

    for (int i = 0; i < ident; i++)
        blank[i] = ' ';
    blank[ident] = 0;

    switch (node->nodeType) {
        case OP_ADD:
            printf("%s|-ADD\n", blank);
            break;
        case OP_SUB:
            printf("%s|-SUB\n", blank);
            break;
        case NODE_INT:
            printf("%s|-%d\n", blank, node->iValue);
            ident += 3;
            break;
        case NODE_STMT:
            printf("%s|-STMT\n", blank);
            ident += 3;
            break;
        case NODE_TERM:
            printf("%s|-TERM\n", blank);
            ident += 3;
            break;
        case NODE_PROGRAM:
            printf("%s|-PROGRAM\n", blank);
            ident += 3;
            break;
        case NODE_ID:
            printf("%s|-[ID] %s\n", blank, node->strValue);
            ident += 3;
            break;
        case ID_TOK:
            break;
        case NODE_DECL:
            printf("%s|-DECL\n", blank);
            ident += 3;
            break;
        case NODE_EXPR:
            printf("%s|-EXPR\n", blank);
            ident += 3;
            break;
        case NODE_VAR:
            printf("%s|-VAR\n", blank);
            ident += 3;
            break;
        case NODE_ID_LIST:
            printf("%s|-ID_LIST\n", blank);
            ident += 3;
            break;
        case PUC_COMMA:
            printf("%s|- ,\n", blank);
            ident += 3;
            break;
        case PUC_LBRAC:
            printf("%s|- [ \n", blank);
            ident += 3;
            break;
        case PUC_RBRAC:
            printf("%s|- ]\n", blank);
            ident += 3;
            break;
        case PUC_DOTDOT:
            printf("%s|- ..\n", blank);
            ident += 3;
            break;
        case PUC_COLON:
            printf("%s|- :\n", blank);
            ident += 3;
            break;
        case PUC_SEMI:
            printf("%s|- ;\n", blank);
            ident += 3;
            break;
        case TY_INT:
            printf("%s|-INTEGER(type)\n", blank);
            ident += 3;
            break;
        case NODE_STDTYPE:
            printf("%s|-STDTYPE\n", blank);
            ident += 3;
            break;
        case NODE_TYPE:
            printf("%s|-TYPE\n", blank);
            ident += 3;
            break;
        case RE_ARR:
            printf("%s|-ARRAY\n", blank);
            ident += 3;
            break;
        case RE_OF:
            printf("%s|-OF\n", blank);
            ident += 3;
            break;
        case NODE_NUM:
            printf("%s|-[NUM] %f\n", blank, node->number);
            ident += 3;
            break;
        case NUM_TOK:
            break;
        case NODE_LAMDBA:
            printf("%s|- (LAMDBA)\n", blank);
            ident += 3;
            break;
        case NODE_STRING:
            printf("%s|-STRING\n", blank);
            ident += 3;
            break;
        case NODE_IF_STMT:
            printf("%s|-IF_STMT\n", blank);
            ident += 3;
            break;
        case NODE_OPTVAR:
            printf("%s|-OPTVAR\n", blank);
            ident += 3;
            break;
        case NODE_RELOP:
            printf("%s|-RELOP\n", blank);
            ident += 3;
            break;
        case NODE_MULOP:
            printf("%s|-MULOP\n", blank);
            ident += 3;
            break;
        case NODE_ADDOP:
            printf("%s|-ADDOP\n", blank);
            ident += 3;
            break;
        case NODE_FACTOR:
            printf("%s|-FACTOR\n", blank);
            ident += 3;
            break;
        case NODE_TREM:
            printf("%s|-TERM\n", blank);
            ident += 3;
            break;
        case NODE_SI_EXPR:
            printf("%s|-SI_EXPR\n", blank);
            ident += 3;
            break;
        case NODE_EXPR_LI:
            printf("%s|-EXPR_LI\n", blank);
            ident += 3;
            break;
        case NODE_PROC_STMT:
            printf("%s|-PROC_STMT\n", blank);
            ident += 3;
            break;
        case NODE_TAIL:
            printf("%s|-TAIL\n", blank);
            ident += 3;
            break;
        case NODE_COMP_STMT:
            printf("%s|-COMP_STMT\n", blank);
            ident += 3;
            break;
        case NODE_STMT_LI:
            printf("%s|-STMT_LI\n", blank);
            ident += 3;
            break;
        case NODE_OPT_STMT:
            printf("%s|-OPT_STMT\n", blank);
            ident += 3;
            break;
        case NODE_PARAM_LI:
            printf("%s|-PARAM_LI\n", blank);
            ident += 3;
            break;
        case NODE_ARG:
            printf("%s|-ARG\n", blank);
            ident += 3;
            break;
        case NODE_SPROG_H:
            printf("%s|-SPROG\n", blank);
            ident += 3;
            break;
        case NODE_SPROG_DECL:
            printf("%s|-SPROG_DECL\n", blank);
            ident += 3;
            break;
        case NODE_SPROG_DECLS:
            printf("%s|-SPROG_DECLS\n", blank);
            ident += 3;
            break;
        case NODE_START:
            printf("%s|-START\n", blank);
            ident += 3;
            break;
        case OP_notEQUAL:
            printf("%s|-NOTEQUAL\n", blank);
            ident += 3;
            break;
        case OP_GE:
            printf("%s|- >=\n", blank);
            ident += 3;
            break;
        case OP_LE:
            printf("%s|- <=\n", blank);
            ident += 3;
            break;
        case OP_EQUAL:
            printf("%s|- =\n", blank);
            ident += 3;
            break;
        case OP_GT:
            printf("%s|- >\n", blank);
            ident += 3;
            break;
        case OP_LT:
            printf("%s|- <\n", blank);
            ident += 3;
            break;
        case OP_MUL:
            printf("%s|-MUL\n", blank);
            ident += 3;
            break;
        case OP_DIV:
            printf("%s|-DIV\n", blank);
            ident += 3;
            break;
        case OP_PLUS:
            printf("%s|-ADD\n", blank);
            ident += 3;
            break;
        case OP_MINUS:
            printf("%s|-MINUS\n", blank);
            ident += 3;
            break;
        case PUC_LPAREN:
            printf("%s|- ( \n", blank);
            ident += 3;
            break;
        case PUC_RPAREN:
            printf("%s|- ) \n", blank);
            ident += 3;
            break;
        case PUC_DOT:
            printf("%s|- . \n", blank);
            ident += 3;
            break;
        case RE_NOT:
            printf("%s|-NOT\n", blank);
            ident += 3;
            break;
        case RE_VAR:
            printf("%s|-VAR\n", blank);
            ident += 3;
            break;
        case RE_ASGMNT:
            printf("%s|-ASGMNT\n", blank);
            ident += 3;
            break;
        case RE_IF:
            printf("%s|-IF\n", blank);
            ident += 3;
            break;
        case RE_THEN:
            printf("%s|-THEN\n", blank);
            ident += 3;
            break;
        case RE_ELSE:
            printf("%s|-ELSE\n", blank);
            ident += 3;
            break;
        case RE_WHILE:
            printf("%s|-WHILE\n", blank);
            ident += 3;
            break;
        case RE_DO:
            printf("%s|-DO\n", blank);
            ident += 3;
            break;
        case RE_BEGIN:
            printf("%s|-BEGIN\n", blank);
            ident += 3;
            break;
        case RE_END:
            printf("%s|-END\n", blank);
            ident += 3;
            break;
        case RE_FUNC:
            printf("%s|-FUNCTION\n", blank);
            ident += 3;
            break;
        case RE_PROC:
            printf("%s|-PROCEDURE\n", blank);
            ident += 3;
            break;
        case RE_PROG:
            printf("%s|-PROGRAM\n", blank);
            ident += 3;
            break;
        case RE_CONST:
            printf("%s|-CONST\n", blank);
            ident += 3;
            break;
        case RE_TYPE:
            printf("%s|-TYPE\n", blank);
            ident += 3;
            break;
        case TY_REAL:
            printf("%s|-REAL\n", blank);
            ident += 3;
            break;
        case TY_STR:
            printf("%s|-STRING\n", blank);
            ident += 3;
            break;
        case NODE_PROGRAM_HEAD:
            printf("%s|-PROGRAM_HEAD\n", blank);
            ident += 3;
            break;
        case NODE_BLOCK:
            printf("%s|-BLOCK\n", blank);
            ident += 3;
            break;
        case NODE_LABEL:
            printf("%s|-LABEL\n", blank);
            ident += 3;
            break;
        case DIGSEQ_TOK:
            printf("%s|-DIGSEQ_TOK\n", blank);
            ident += 3;
            break;
        case NODE_SIGN:
            printf("%s|-SIGN\n", blank);
            ident += 3;
            break;       
        case NODE_SUBRANGE:
            printf("%s|-SUBRANGE\n", blank);
            ident += 3;
            break;
        case NODE_ARRAY:
            printf("%s|-ARRAY\n", blank);
            ident += 3;
            break;
        case PUC_ARR:
            printf("%s|-ARR\n", blank);
            ident += 3;
            break;
        case NODE_COMP_TYPE:
            printf("%s|-COMP_TYPE\n", blank);
            ident += 3;
            break;
        case TY_CHAR:
            printf("%s|-CHAR\n", blank);
            ident += 3;
            break;
        case TY_BOOL:
            printf("%s|-BOOL\n", blank);
            ident += 3;
            break;
        case NODE_VAR_DECL_PART:
            printf("%s|-VAR_DECL_PART\n", blank);
            ident += 3;
            break;
        case NODE_VAR_ID_LIST:
            printf("%s|-VAR_ID_LIST\n", blank);
            ident += 3;
            break;
        case NODE_VAR_DECL:
            printf("%s|-VAR_DECL\n", blank);
            ident += 3;
            break;
        case NODE_VAR_TYPE:
            printf("%s|-VAR_TYPE\n", blank);
            ident += 3;
            break;
        case NODE_STMT_PART:
            printf("%s|-STMT_PART\n", blank);
            ident += 3;
            break;
        case NODE_STMT_SEQ:
            printf("%s|-STMT_SEQ\n", blank);
            ident += 3;
            break;
        case NODE_OPEN_STMT:
            printf("%s|-OPEN_STMT\n", blank);
            ident += 3;
            break;
        case NODE_CLOSED_STMT:
            printf("%s|-CLOSED_STMT\n", blank);
            ident += 3;
            break;
        case NODE_NL_CLOSED:
            printf("%s|-NL_CLOSED\n", blank);
            ident += 3;
            break;
        case NODE_NL_OPEN:
            printf("%s|-NL_OPEN\n", blank);
            ident += 3;
            break;
        case NODE_OPEN_WHILE:
            printf("%s|-OPEN_WHILE\n", blank);
            ident += 3;
            break;
        case NODE_CLOSED_WHILE:
            printf("%s|-CLOSED_WHILE\n", blank);
            ident += 3;
            break;
        case NODE_OPEN_FOR:
            printf("%s|-OPEN_FOR\n", blank);
            ident += 3;
            break;
        case RE_FOR:
            printf("%s|-FOR\n", blank);
            ident += 3;
            break;
        case NODE_CLOSED_FOR:
            printf("%s|-CLOSED_FOR\n", blank);
            ident += 3;
            break;
        case NODE_OPEN_IF:
            printf("%s|-OPEN_IF\n", blank);
            ident += 3;
            break;
        case NODE_CLOSED_IF:
            printf("%s|-CLOSED_IF\n", blank);
            ident += 3;
            break;
        case NODE_READ_STMT:
            printf("%s|-READ_STMT\n", blank);
            ident += 3;
            break;
        case RE_READ:
            printf("%s|-READ\n", blank);
            ident += 3;
            break;
        case NODE_WRITE_STMT:
            printf("%s|-WRITE_STMT\n", blank);
            ident += 3;
            break;
        case RE_WRITE:
            printf("%s|-WRITE\n", blank);
            ident += 3;
            break;
        case NODE_LIST:
            printf("%s|-LIST\n", blank);
            ident += 3;
            break;
        case CHAR_STRING_TOK:
            printf("%s|-CHAR_STRING\n", blank);
            ident += 3;
            break;
        case NODE_ID1:
            printf("%s|-ID1\n", blank);
            ident += 3;
            break;
        case NODE_VAR_ACC:
            printf("%s|-VAR_ACC\n", blank);
            ident += 3;
            break;
        case NODE_IND_VAR:
            printf("%s|-IND_VAR\n", blank);
            ident += 3;
            break;
        case NODE_IND_EXPR:
            printf("%s|-IND_EXPR\n", blank);
            ident += 3;
            break;
        case NODE_FIELD_DES:
            printf("%s|-FIELD_DES\n", blank);
            ident += 3;
            break;
        case NODE_CONT_VAR:
            printf("%s|-CONT_VAR\n", blank);
            ident += 3;
            break;
        case NODE_INIT_VAL:
            printf("%s|-INIT_VAL\n", blank);
            ident += 3;
            break;
        case NODE_DIR:
            printf("%s|-DIR\n", blank);
            ident += 3;
            break;
        case RE_DOWNTO:
            printf("%s|-DOWNTO\n", blank);
            ident += 3;
            break;
        case NODE_FIN_VAL:
            printf("%s|-FIN_VAL\n", blank);
            ident += 3;
            break;
        case NODE_SIMPLE_EXP:
            printf("%s|-SIMPLE_EXP\n", blank);
            ident += 3;
            break;
        case OP_STARSTAR:
            printf("%s|-STARSTAR\n", blank);
            ident += 3;
            break;
        case NODE_PRIMARY:
            printf("%s|-PRIMARY\n", blank);
            ident += 3;
            break;
        case NODE_UNSIGN_CONST:
            printf("%s|-UNSIGN_CONST\n", blank);
            ident += 3;
            break;
        case RE_NIL:
            printf("%s|-NIL\n", blank);
            ident += 3;
            break;
        case NODE_UNSIGN_NUM:
            printf("%s|-UNSIGN_NUM\n", blank);
            ident += 3;
            break;
        case NODE_UNSIGN_INT:
            printf("%s|-UNSIGN_INT\n", blank);
            ident += 3;
            break;
        case NODE_REALNUMBER:
            printf("%s|-REALNUMBER\n", blank);
            ident += 3;
            break;
        case REALNUMBER_TOK:
            printf("%s|-REALNUMBER_TOK\n", blank);
            ident += 3;
            break;
        case OP_OR:
            printf("%s|-OR\n", blank);
            ident += 3;
            break;
        case OP_STAR:
            printf("%s|-STAR\n", blank);
            ident += 3;
            break;
        case OP_SLASH:
            printf("%s|-SLASH\n", blank);
            ident += 3;
            break;
        case OP_MOD:
            printf("%s|-MOD\n", blank);
            ident += 3;
            break;
        case OP_AND:
            printf("%s|-AND\n", blank);
            ident += 3;
            break;
        case OP_IN:
            printf("%s|-IN\n", blank);
            ident += 3;
            break;
        case NODE_SEMI:
            printf("%s|-SEMI\n", blank);
            ident += 3;
            break;
        case NODE_COMMA:
            printf("%s|-COMMA\n", blank);
            ident += 3;
            break;
        default:
            printf("%sdefault:%d\n", blank, node->nodeType);
            break;
    }

    if (node->childs != NULL) {
        for (int i = 0; node->childs[i] != NULL; i++) {
            printTree(node->childs[i], ident);
        }
    }
}

char* convertType(int type)
{
    switch (type) {
        case TY_INT:
            return "INTEGER";
            break;
        case TY_REAL:
            return "REAL";
            break;
        case TY_CHAR:
            return "CHAR";
            break;
        case TY_BOOL:
            return "INTEGER";
            break;
        case TY_ARRAY:
            return "ARRAY";
            break;
    }
}

FILE *outputFile;

void openOutputFile() {
    outputFile = fopen("tree_string.txt", "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening file tree_string.txt\n");
        exit(EXIT_FAILURE);
    }
}

void closeOutputFile() {
    fclose(outputFile);
}

void writeNode(Node *node) {
    if (node == NULL)
        return;

    switch (node->nodeType) {
        case OP_ADD:
            fprintf(outputFile, "+");
            break;
        case OP_SUB:
            fprintf(outputFile, "-");
            break;
        case NODE_INT:
            fprintf(outputFile, "%d", node->iValue);
            
            break;
        case NODE_STMT:
            fprintf(outputFile, "STMT");
            
            break;
        case NODE_TERM:
            //fprintf(outputFile, "TERM");
            
            break;
        case NODE_PROGRAM:
            fprintf(outputFile, "PROGRAM");
            
            break;
        case NODE_ID:
            fprintf(outputFile, "ID-%s", node->strValue);
            
            break;
        case ID_TOK:
            break;
        case NODE_DECL:
            fprintf(outputFile, "DECL");
            
            break;
        case NODE_EXPR:
            fprintf(outputFile, "EXPR");
            
            break;
        case NODE_VAR:
            fprintf(outputFile, "VAR");
            
            break;
        case NODE_ID_LIST:
            fprintf(outputFile, "ID_LIST");
            
            break;
        case PUC_COMMA:
            fprintf(outputFile, " ,");
            
            break;
        case PUC_LBRAC:
            fprintf(outputFile, "LBRAC");
            
            break;
        case PUC_RBRAC:
            fprintf(outputFile, " RBRAC");
            
            break;
        case PUC_DOTDOT:
            fprintf(outputFile, " ..");
            
            break;
        case PUC_COLON:
            fprintf(outputFile, " :");
            
            break;
        case PUC_SEMI:
            fprintf(outputFile, " ;");
            
            break;
        case TY_INT:
            fprintf(outputFile, "INTEGER(type)");
            
            break;
        case NODE_STDTYPE:
            fprintf(outputFile, "STDTYPE");
            
            break;
        case NODE_TYPE:
            fprintf(outputFile, "TYPE");
            
            break;
        case RE_ARR:
            fprintf(outputFile, "ARRAY");
            
            break;
        case RE_OF:
            fprintf(outputFile, "OF");
            
            break;
        case NODE_NUM:
            fprintf(outputFile, "[NUM] %f", node->number);
            
            break;
        case NUM_TOK:
            break;
        case NODE_LAMDBA:
            fprintf(outputFile, " (LAMDBA)");
            
            break;
        case NODE_STRING:
            fprintf(outputFile, "STRING");
            
            break;
        case NODE_IF_STMT:
            fprintf(outputFile, "IF_STMT");
            
            break;
        case NODE_OPTVAR:
            fprintf(outputFile, "OPTVAR");
            
            break;
        case NODE_RELOP:
            fprintf(outputFile, "RELOP");
            
            break;
        case NODE_MULOP:
            fprintf(outputFile, "MULOP");
            
            break;
        case NODE_ADDOP:
            fprintf(outputFile, "ADDOP");
            
            break;
        case NODE_FACTOR:
            //fprintf(outputFile, "FACTOR");
            
            break;
        case NODE_TREM:
            //fprintf(outputFile, "TERM");
            
            break;
        case NODE_SI_EXPR:
            //fprintf(outputFile, "SI_EXPR");
            
            break;
        case NODE_EXPR_LI:
            //fprintf(outputFile, "EXPR_LI");
            
            break;
        case NODE_PROC_STMT:
            //fprintf(outputFile, "PROC_STMT");
            
            break;
        case NODE_TAIL:
            fprintf(outputFile, "TAIL");
            
            break;
        case NODE_COMP_STMT:
            fprintf(outputFile, "COMP_STMT");
            
            break;
        case NODE_STMT_LI:
            //fprintf(outputFile, "STMT_LI");
            
            break;
        case NODE_OPT_STMT:
            //fprintf(outputFile, "OPT_STMT");
            
            break;
        case NODE_PARAM_LI:
            //fprintf(outputFile, "PARAM_LI");
            
            break;
        case NODE_ARG:
            //fprintf(outputFile, "ARG");
            
            break;
        case NODE_SPROG_H:
            //fprintf(outputFile, "SPROG");
            
            break;
        case NODE_SPROG_DECL:
            //fprintf(outputFile, "SPROG_DECL");
            
            break;
        case NODE_SPROG_DECLS:
            //fprintf(outputFile, "SPROG_DECLS");
            
            break;
        case NODE_START:
            fprintf(outputFile, "START");
            
            break;
        case OP_notEQUAL:
            fprintf(outputFile, "<>");
            
            break;
        case OP_GE:
            fprintf(outputFile, " >=");
            
            break;
        case OP_LE:
            fprintf(outputFile, " <=");
            
            break;
        case OP_EQUAL:
            fprintf(outputFile, " =");
            
            break;
        case OP_GT:
            fprintf(outputFile, " >");
            
            break;
        case OP_LT:
            fprintf(outputFile, " <");
            
            break;
        case OP_MUL:
            fprintf(outputFile, "*");
            
            break;
        case OP_DIV:
            fprintf(outputFile, "/");
            
            break;
        case OP_PLUS:
            fprintf(outputFile, "+");
            
            break;
        case OP_MINUS:
            fprintf(outputFile, "-");
            
            break;
        case PUC_LPAREN:
            fprintf(outputFile, " ( ");
            
            break;
        case PUC_RPAREN:
            fprintf(outputFile, " ) ");
            
            break;
        case PUC_DOT:
            fprintf(outputFile, " . ");
            
            break;
        case RE_NOT:
            fprintf(outputFile, "!");
            
            break;
        case RE_VAR:
            fprintf(outputFile, "VAR");
            
            break;
        case RE_ASGMNT:
            fprintf(outputFile, "ASGMNT");
            
            break;
        case RE_IF:
            fprintf(outputFile, "IF");
            
            break;
        case RE_THEN:
            fprintf(outputFile, "THEN");
            
            break;
        case RE_ELSE:
            fprintf(outputFile, "ELSE");
            
            break;
        case RE_WHILE:
            fprintf(outputFile, "WHILE");
            
            break;
        case RE_DO:
            fprintf(outputFile, "DO");
            
            break;
        case RE_BEGIN:
            fprintf(outputFile, "BEGIN");
            
            break;
        case RE_END:
            fprintf(outputFile, "END");
            
            break;
        case RE_FUNC:
            fprintf(outputFile, "FUNCTION");
            
            break;
        case RE_PROC:
            fprintf(outputFile, "PROCEDURE");
            
            break;
        case RE_PROG:
            fprintf(outputFile, "PROGRAM");
            
            break;
        case RE_CONST:
            fprintf(outputFile, "CONST");
            
            break;
        case RE_TYPE:
            fprintf(outputFile, "TYPE");
            
            break;
        case TY_REAL:
            fprintf(outputFile, "REAL");
            
            break;
        case TY_STR:
            fprintf(outputFile, "STRING");
            
            break;
        case NODE_PROGRAM_HEAD:
            fprintf(outputFile, "PROGRAM_HEAD");
            
            break;
        case NODE_BLOCK:
            fprintf(outputFile, "BLOCK");
            
            break;
        case NODE_LABEL:
            fprintf(outputFile, "LABEL");
            
            break;
        case DIGSEQ_TOK:
            fprintf(outputFile, "DIGSEQ_TOK");
            
            break;
        case NODE_SIGN:
            fprintf(outputFile, "SIGN");
            
            break;       
        case NODE_SUBRANGE:
            //fprintf(outputFile, "SUBRANGE");
            
            break;
        case NODE_ARRAY:
            fprintf(outputFile, "ARRAY");
            
            break;
        case PUC_ARR:
            fprintf(outputFile, "ARR");
            
            break;
        case NODE_COMP_TYPE:
            //fprintf(outputFile, "COMP_TYPE");
            
            break;
        case TY_CHAR:
            fprintf(outputFile, "CHAR");
            
            break;
        case TY_BOOL:
            fprintf(outputFile, "BOOL");
            
            break;
        case NODE_VAR_DECL_PART:
            //fprintf(outputFile, "VAR_DECL_PART");
            
            break;
        case NODE_VAR_ID_LIST:
            //fprintf(outputFile, "VAR_ID_LIST");
            
            break;
        case NODE_VAR_DECL:
            fprintf(outputFile, "VAR_DECL");
            
            break;
        case NODE_VAR_TYPE:
            fprintf(outputFile, "VAR_TYPE");
            
            break;
        case NODE_STMT_PART:
            //fprintf(outputFile, "STMT_PART");
            
            break;
        case NODE_STMT_SEQ:
            //fprintf(outputFile, "STMT_SEQ");
            
            break;
        case NODE_OPEN_STMT:
            //fprintf(outputFile, "OPEN_STMT");
            
            break;
        case NODE_CLOSED_STMT:
            //fprintf(outputFile, "CLOSED_STMT");
            
            break;
        case NODE_NL_CLOSED:
            //fprintf(outputFile, "NL_CLOSED");
            
            break;
        case NODE_NL_OPEN:
            //fprintf(outputFile, "NL_OPEN");
            
            break;
        case NODE_OPEN_WHILE:
            fprintf(outputFile, "OPEN_WHILE");
            
            break;
        case NODE_CLOSED_WHILE:
            fprintf(outputFile, "CLOSED_WHILE");
            
            break;
        case NODE_OPEN_FOR:
            fprintf(outputFile, "OPEN_FOR");
            
            break;
        case RE_FOR:
            fprintf(outputFile, "FOR");
            
            break;
        case NODE_CLOSED_FOR:
            fprintf(outputFile, "CLOSED_FOR");
            
            break;
        case NODE_OPEN_IF:
            fprintf(outputFile, "OPEN_IF");
            
            break;
        case NODE_CLOSED_IF:
            fprintf(outputFile, "CLOSED_IF");
            
            break;
        case NODE_READ_STMT:
            fprintf(outputFile, "READ_STMT");
            
            break;
        case RE_READ:
            fprintf(outputFile, "READ");
            
            break;
        case NODE_WRITE_STMT:
            fprintf(outputFile, "WRITE_STMT");
            
            break;
        case RE_WRITE:
            fprintf(outputFile, "WRITE");
            
            break;
        case NODE_LIST:
            fprintf(outputFile, "LIST");
            
            break;
        case CHAR_STRING_TOK:
            fprintf(outputFile, "CHAR_STRING");
            
            break;
        case NODE_ID1:
            fprintf(outputFile, "ID1");
            
            break;
        case NODE_VAR_ACC:
            //fprintf(outputFile, "VAR_ACC");
            
            break;
        case NODE_IND_VAR:
            //fprintf(outputFile, "IND_VAR");
            
            break;
        case NODE_IND_EXPR:
            //fprintf(outputFile, "IND_EXPR");
            
            break;
        case NODE_FIELD_DES:
            //fprintf(outputFile, "FIELD_DES");
            
            break;
        case NODE_CONT_VAR:
            //fprintf(outputFile, "CONT_VAR");
            
            break;
        case NODE_INIT_VAL:
            //fprintf(outputFile, "INIT_VAL");
            
            break;
        case NODE_DIR:
            //fprintf(outputFile, "DIR");
            
            break;
        case RE_DOWNTO:
            fprintf(outputFile, "DOWNTO");
            
            break;
        case NODE_FIN_VAL:
            fprintf(outputFile, "FIN_VAL");
            
            break;
        case NODE_SIMPLE_EXP:
            fprintf(outputFile, "SIMPLE_EXP");
            
            break;
        case OP_STARSTAR:
            fprintf(outputFile, "STARSTAR");
            
            break;
        case NODE_PRIMARY:
            //fprintf(outputFile, "PRIMARY");
            
            break;
        case NODE_UNSIGN_CONST:
            //fprintf(outputFile, "UNSIGN_CONST");
            
            break;
        case RE_NIL:
            fprintf(outputFile, "NIL");
            
            break;
        case NODE_UNSIGN_NUM:
            fprintf(outputFile, "UNSIGN_NUM");
            
            break;
        case NODE_UNSIGN_INT:
            fprintf(outputFile, "UNSIGN_INT");
            
            break;
        case NODE_REALNUMBER:
            fprintf(outputFile, "REALNUMBER");
            
            break;
        case REALNUMBER_TOK:
            fprintf(outputFile, "REALNUMBER_TOK");
            
            break;
        case OP_OR:
            fprintf(outputFile, "OR");
            
            break;
        case OP_STAR:
            fprintf(outputFile, "STAR");
            
            break;
        case OP_SLASH:
            fprintf(outputFile, "SLASH");
            
            break;
        case OP_MOD:
            fprintf(outputFile, "MOD");
            
            break;
        case OP_AND:
            fprintf(outputFile, "AND");
            
            break;
        case OP_IN:
            fprintf(outputFile, "IN");
            
            break;
        case NODE_SEMI:
            fprintf(outputFile, "SEMI");
            
            break;
        case NODE_COMMA:
            fprintf(outputFile, "COMMA");
            
            
            break;
        default:
            fprintf(outputFile, "Unknown");
            break;
    }
	fprintf(outputFile, "[");
    if (node->childs != NULL) {
       
        for (int i = 0; node->childs[i] != NULL; i++) {
        fprintf(outputFile, "[");
            writeNode(node->childs[i]);
        fprintf(outputFile, "]");
        }
        
    }
    fprintf(outputFile, "]");
}

void printTreeToFile(Node *node) {
    openOutputFile();
    fprintf(outputFile, "[");
    writeNode(node);
    fprintf(outputFile, "]");
    closeOutputFile();
}