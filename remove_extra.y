%{
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

%}

%union
{
    struct Node* node;
    double number;
    char* string;
}

%token <node> AND 
%token <node> ARRAY ASSIGNMENT 
%token <node> CASE 
%token <string> CHARACTER_STRING 
%token <node> COLON 
%token <node> COMMA CONST 
%token <number> DIGSEQ
%token <node> DIV 
%token <node> DO 
%token <node> DOT DOTDOT 
%token <node> DOWNTO ELSE 
%token <node> END 
%token <node> EQUAL 
%token <node> EXTERNAL FOR 
%token <node> FORWARD 
%token <node> FUNCTION
%token <node> GE 
%token <node> GOTO GT 
%token <string> IDENTIFIER 
%token<node>IF 
%token <node> IN LABEL 
%token <node> LBRAC 
%token <node> LE LPAREN 
%token <node> LT 
%token <node> MINUS
%token <node> MOD 
%token <node> NIL 
%token <node> NOT
%token <node> NOTEQUAL OF 
%token <node> OR OTHERWISE 
%token <node> PACKED 
%token <node> PBEGIN PFILE 
%token <node> PLUS 
%token <node> PROCEDURE
%token <node> PROGRAM RBRAC
%token <number> REALNUMBER 
%token <node> RECORD REPEAT 
%token <node> RPAREN 
%token <node> SEMICOLON 
%token <node> SET 
%token <node> SLASH STAR 
%token <node> STARSTAR THEN
%token <node> TO 
%token <node> TYPE 
%token <node> UNTIL UPARROW 
%token <node> VAR 
%token <node> WHILE 
%token <node> WITH READ 
%token <node> WRITE 
%token <node> BOOLEAN CHAR 
%token <node> REAL INTEGER 
%token <node> ERROR

%type<node> program program_heading block variable_declaration_part
%type<node> variable_declaration_list variable_declaration identifier_list
%type<node> statement_part compound_statement statement_sequence statement
%type<node> open_statement closed_statement non_labeled_open_statement
%type<node> open_if_statement open_while_statement open_for_statement
%type<node> non_labeled_closed_statement assignment_statement read_statement
%type<node> write_statement closed_if_statement closed_while_statement
%type<node> closed_for_statement array_type subrange_type list identifier_list_1
%type<node> identifier_1 indexed_variable 
%type<node> variable_access control_variable initial_value direction
%type<node> final_value boolean_expression expression term primary
%type<node> unsigned_constant simple_expression component_type 
%type<node> addop var_type relop identifier 
%type<node> semicolon mulop comma label

%%

file : program
{
  //readConsole();
}
 ;

program : program_heading semicolon block DOT
{
 		$$ = newNode(NODE_PROGRAM);
 		addChild($$, $1);
 		addChild($$, newNode(PUC_SEMI));
 		addChild($$, $3);
 		addChild($$, newNode(PUC_DOT));
 		ASTROOT = $$;
 	}
 ;
program_heading : PROGRAM identifier
{
	
	$$ = newNode(NODE_PROGRAM_HEAD);
   addChild($$, newNode(RE_PROG));
   addChild($$, $2);
}
 ;

identifier_list : identifier_list comma identifier
{
   $$ = $1;
    addChild($$,newNode(PUC_COMMA));
    addChild($$, $3); // variable_declaration

}
 | identifier
 {
   $$ = newNode(NODE_ID_LIST);
   addChild($$, $1);
 }
 ;


block : variable_declaration_part
 statement_part
  {
 	$$ = newNode(NODE_BLOCK);
    addChild($$, $1);
    addChild($$, $2);
 }
 ;


label : DIGSEQ
{
  $$ = newNode(NODE_LABEL);
   addChild($$, newNode(DIGSEQ_TOK));
}
 ;


subrange_type : DIGSEQ DOTDOT DIGSEQ
{
   $$ = newNode(NODE_SUBRANGE);
   $$->idxstart = $1;
   $$->idxend = $3;
   addChild($$, newNode(DIGSEQ_TOK));
   addChild($$, newNode(PUC_DOTDOT));
   addChild($$, newNode(DIGSEQ_TOK));
}
 ;

array_type : ARRAY LBRAC subrange_type RBRAC OF component_type
{
   $$ = newNode(NODE_ARRAY);
   $$->idxstart = $3->idxstart;
   $$->idxend = $3->idxend;
   $$->comp_type = $6->childs[0]->nodeType;
   addChild($$, newNode(PUC_ARR));
   addChild($$, newNode(PUC_LBRAC));
   addChild($$, $3);
   addChild($$, newNode(PUC_RBRAC));
   addChild($$, newNode(RE_OF));
   addChild($$, $6);
}
 ;


component_type : INTEGER
 {
  $$ = newNode(NODE_COMP_TYPE);
  addChild($$, newNode(TY_INT)); 
}
  | REAL
  {
  $$ = newNode(NODE_COMP_TYPE);
  addChild($$, newNode(TY_REAL)); 
}
  | CHAR
  {
  $$ = newNode(NODE_COMP_TYPE);
  addChild($$, newNode(TY_CHAR)); 
}
  | BOOLEAN
  {
  $$ = newNode(NODE_COMP_TYPE);
  addChild($$, newNode(TY_BOOL)); 
}
 ;
 
variable_declaration_part : VAR variable_declaration_list semicolon
 {
   $$ = newNode(NODE_VAR_DECL_PART);
   addChild($$, newNode(RE_VAR));
   addChild($$, $2);
   addChild($$, newNode(PUC_SEMI));
}
|
 {
   $$ = newNode(NODE_VAR_DECL_PART);
   }
 ;

variable_declaration_list :
   variable_declaration_list semicolon variable_declaration
   {
      $$ = $1;
    addChild($$,newNode(PUC_SEMI));
    addChild($$, $3);
   }
 | variable_declaration
 {
      $$ = newNode(NODE_VAR_ID_LIST);
   addChild($$, $1);
 }
 ;

variable_declaration : identifier_list COLON var_type
{
    $$ = newNode(NODE_VAR_DECL);
    addChild($$, $1);
    addChild($$, newNode(PUC_COLON));
    addChild($$, $3);
    Node *nodechild = $3->childs[0];
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
        while ($1->childs[num_childs] != NULL) {
            num_childs++;
        }

    for (int i = 0; i < num_childs; i++) {
        Node* idNode = $1->childs[i];
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
;



 var_type: INTEGER
 {
  $$ = newNode(NODE_VAR_TYPE);
  addChild($$, newNode(TY_INT)); 
}
  | REAL
  {
  $$ = newNode(NODE_VAR_TYPE);
  addChild($$, newNode(TY_REAL)); 
}
  | CHAR
  {
  $$ = newNode(NODE_VAR_TYPE);
  addChild($$, newNode(TY_CHAR)); 
}
  | BOOLEAN
  {
  $$ = newNode(NODE_VAR_TYPE);
  addChild($$, newNode(TY_BOOL)); 
}
  | array_type
  {
  $$ = newNode(NODE_VAR_TYPE);
  $$->comp_type = $1->comp_type;
  addChild($$, $1); 
}
  ;

statement_part : compound_statement 
{
  $$ = newNode(NODE_STMT_PART);
   addChild($$, $1);
}
;

compound_statement : PBEGIN statement_sequence END 
{
   
  $$ = newNode(NODE_COMP_STMT);
   addChild($$, newNode(RE_BEGIN));
   addChild($$, $2);
   addChild($$, newNode(RE_END));

}
;


statement_sequence : statement_sequence semicolon statement
 {
      $$ = $1;
    addChild($$,newNode(PUC_SEMI));
    addChild($$, $3);
   }
 | statement
  {
      $$ = newNode(NODE_STMT_SEQ);
   addChild($$, $1);
 }
 ;

statement : open_statement
 {
      $$ = newNode(NODE_STMT);
   addChild($$, $1);
 }
 | closed_statement
  {
      $$ = newNode(NODE_STMT);
   addChild($$, $1);
 }
 ;

open_statement : label COLON non_labeled_open_statement
{
  $$ = newNode(NODE_OPEN_STMT);
  addChild($$, $1);
  addChild($$, newNode(PUC_COLON));
  addChild($$, $3);
}
 | non_labeled_open_statement
 {
  $$ = newNode(NODE_OPEN_STMT);
  addChild($$, $1);
}
 ;

closed_statement : label COLON non_labeled_closed_statement
  {
  $$ = newNode(NODE_CLOSED_STMT);
  addChild($$, $1);
  addChild($$, newNode(PUC_COLON));
  addChild($$, $3);
}
 | non_labeled_closed_statement
  {
  $$ = newNode(NODE_CLOSED_STMT);
  addChild($$, $1);
}
 ;
non_labeled_closed_statement : assignment_statement
 {
      $$ = newNode(NODE_NL_CLOSED);
   addChild($$, $1);
 }
 | read_statement
  {
      $$ = newNode(NODE_NL_CLOSED);
   addChild($$, $1);
 }
 | write_statement
  {
      $$ = newNode(NODE_NL_CLOSED);
   addChild($$, $1);
 }
 | compound_statement
  {
      $$ = newNode(NODE_NL_CLOSED);
   addChild($$, $1);
 }
 | closed_if_statement
  {
      $$ = newNode(NODE_NL_CLOSED);
   addChild($$, $1);
 }
 | closed_while_statement
  {
      $$ = newNode(NODE_NL_CLOSED);
   addChild($$, $1);
 }
 | closed_for_statement
  {
      $$ = newNode(NODE_NL_CLOSED);
   addChild($$, $1);
 }
 |
 {
      $$ = newNode(NODE_NL_CLOSED);
 }
 ;

non_labeled_open_statement : open_if_statement
 {
      $$ = newNode(NODE_NL_OPEN);
   addChild($$, $1);
 }
 | open_while_statement
  {
      $$ = newNode(NODE_NL_OPEN);
   addChild($$, $1);
 }
 | open_for_statement
  {
      $$ = newNode(NODE_NL_OPEN);
   addChild($$, $1);
 }
 ;
open_while_statement : WHILE boolean_expression DO open_statement
{
       $$ = newNode(NODE_OPEN_WHILE);
      addChild($$, newNode(RE_WHILE));
      addChild($$, $2);
      addChild($$, newNode(RE_DO));
      addChild($$, $4);
   }
 ;

closed_while_statement : WHILE boolean_expression DO closed_statement
{
       $$ = newNode(NODE_CLOSED_WHILE);
      addChild($$, newNode(RE_WHILE));
      addChild($$, $2);
      addChild($$, newNode(RE_DO));
      addChild($$, $4);
   }
 ;

open_for_statement : FOR control_variable ASSIGNMENT initial_value direction
   final_value DO open_statement
{

       $$ = newNode(NODE_OPEN_FOR);
      addChild($$, newNode(RE_FOR));
      addChild($$, $2);
      addChild($$, newNode(RE_ASGMNT));
      addChild($$, $4);
      addChild($$, $5);
      addChild($$, $6);
      addChild($$, newNode(RE_DO));
      addChild($$, $8);

}
 ;

 closed_for_statement : FOR control_variable ASSIGNMENT initial_value direction
   final_value DO closed_statement
   {
       $$ = newNode(NODE_CLOSED_FOR);
      addChild($$, newNode(RE_FOR));
      addChild($$, $2);
      addChild($$, newNode(RE_ASGMNT));
      addChild($$, $4);
      addChild($$, $5);
      addChild($$, $6);
      addChild($$, newNode(RE_DO));
      addChild($$, $8);
      if($2->typeVar != $4->typeVar)
    {
      printf("SEMANTIC ERROR(3) : Type Mismatch : (%s) %s (%s)\n",convertType($2->typeVar) , ":=",convertType($4->typeVar));
    }
    if($2->typeVar != $6->typeVar)
    {
      printf("SEMANTIC ERROR(3) : Type Mismatch : (%s) %s (%s)\n",convertType($2->typeVar) , ":=",convertType($6->typeVar));
    }
    
}
 ;
open_if_statement : IF boolean_expression THEN statement
 {
  $$ = newNode(NODE_OPEN_IF);
  addChild($$, newNode(RE_IF));
  addChild($$, $2);
  addChild($$, newNode(RE_THEN));
  addChild($$, $4);
}
 | IF boolean_expression THEN closed_statement ELSE open_statement
  {
  $$ = newNode(NODE_OPEN_IF);
  addChild($$, newNode(RE_IF));
  addChild($$, $2);
  addChild($$, newNode(RE_THEN));
  addChild($$, $4);
  addChild($$, newNode(RE_ELSE));
  addChild($$, $6);
}
 ;

closed_if_statement : IF boolean_expression THEN closed_statement
   ELSE closed_statement
   {
       $$ = newNode(NODE_CLOSED_IF);
      addChild($$, newNode(RE_IF));
      addChild($$, $2);
      addChild($$, newNode(RE_THEN));
      addChild($$, $4);
      addChild($$, newNode(RE_ELSE));
      addChild($$, $6);
   }
 ;

assignment_statement : variable_access ASSIGNMENT expression
{
       $$ = newNode(NODE_ASGMNT_STMT);
      addChild($$, $1);
      addChild($$, newNode(RE_ASGMNT));
      addChild($$, $3);
      if($1->typeVar != $3->typeVar)
    {
      printf("SEMANTIC ERROR(3) : Type Mismatch : (%s) %s (%s)\n",convertType($1->typeVar) , ":=",convertType($3->typeVar));
    }
    $$->typeVar = $1->typeVar;
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
 ;

read_statement: READ LPAREN identifier_1 RPAREN
   {
  $$ = newNode(NODE_READ_STMT);
  addChild($$, newNode(RE_READ));
  addChild($$, newNode(PUC_LPAREN));
  addChild($$, $3);
  addChild($$, newNode(PUC_RPAREN));
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
;

write_statement: WRITE LPAREN list RPAREN
  {
  $$ = newNode(NODE_WRITE_STMT);
  addChild($$, newNode(RE_WRITE));
  addChild($$, newNode(PUC_LPAREN));
  addChild($$, $3);
  addChild($$, newNode(PUC_RPAREN));
}
;


list: CHARACTER_STRING
{
       $$ = newNode(NODE_LIST);
      addChild($$, newNode(CHAR_STRING_TOK));
      $$->strValue = $1;
}
  | identifier_list_1
{
       $$ = newNode(NODE_LIST);
      addChild($$, $1);
      $$->typeVar = $1->typeVar;
}
;

 identifier_list_1 : identifier_list_1 comma identifier_1
{
   $$ = $1;
    addChild($$,newNode(PUC_COMMA));
    addChild($$, $3);
    $$->typeVar = $1->typeVar;
}
 | identifier_1
 {
   $$ = newNode(NODE_ID_LIST1);
   addChild($$, $1);
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
 ;


identifier_1: identifier
{
       $$ = newNode(NODE_ID1);
      addChild($$, $1);
      if(!(isSymbolPresent($1->strValue)))
        {
            printf("SEMANTIC ERROR (2) : Use without declaration of the variable: %s\n",$1->strValue);
        }
        SymbolType type = getSymbolType($1->strValue);
      switch (type) {
        case TYPE_INTEGER:
            $$->typeVar = TY_INT;
            //$$->iValue = (int)getSymbolValue($1->strValue).int_val;
            break;
        case TYPE_REAL:
            $$->typeVar = TY_REAL;
            //$$->rValue = (double)getSymbolValue($1->strValue).real_val;
            break;
        case TYPE_CHAR:
            $$->typeVar = TY_CHAR;
            //$$->cValue = (char)getSymbolValue($1->strValue).char_val;
            break;
        case TYPE_BOOLEAN:
            $$->typeVar = TY_BOOL;
            //$$->bValue = (int)getSymbolValue($1->strValue).bool_val;
            break;
        case TYPE_ARRAY:
            $$->typeVar = getArrayType($1->strValue);
            break;
    }
    $$->strValue = $1->strValue;
}
 | indexed_variable
{
       $$ = newNode(NODE_ID1);
      addChild($$, $1);
      $$->typeVar = $1->typeVar;
} 
 ;

variable_access : identifier
{
       $$ = newNode(NODE_VAR_ACC);
      addChild($$, $1);
      if(!(isSymbolPresent($1->strValue)))
        {
            printf("SEMANTIC ERROR(2) : Use without declaration of the variable: %s\n",$1->strValue);
        }
      SymbolType type = getSymbolType($1->strValue);
      switch (type) {
        case TYPE_INTEGER:
            $$->typeVar = TY_INT;
            //$$->iValue = (int)getSymbolValue($1->strValue).int_val;
            break;
        case TYPE_REAL:
            $$->typeVar = TY_REAL;
            //$$->rValue = (double)getSymbolValue($1->strValue).real_val;
            break;
        case TYPE_CHAR:
            $$->typeVar = TY_CHAR;
            //$$->cValue = (char)getSymbolValue($1->strValue).char_val;
            break;
        case TYPE_BOOLEAN:
            $$->typeVar = TY_BOOL;
            //$$->bValue = (int)getSymbolValue($1->strValue).bool_val;
            break;
        case TYPE_ARRAY:
            $$->typeVar = getArrayType($1->strValue);
            break;
    }
    $$->strValue = $1->strValue;
} 
 | indexed_variable
 {
       $$ = newNode(NODE_VAR_ACC);
      addChild($$, $1);
      $$->typeVar = $1->typeVar;
} 
 ;

indexed_variable : variable_access LBRAC expression RBRAC
{
   $$ = newNode(NODE_IND_VAR);
   addChild($$, $1);
   addChild($$, newNode(PUC_LBRAC));
   addChild($$, $3);
   addChild($$, newNode(PUC_RBRAC));
  $$->typeVar = $1->typeVar;
}
 ;

control_variable : identifier 
{
 	$$ = newNode(NODE_CONT_VAR);
    addChild($$, $1);
    if(!(isSymbolPresent($1->strValue)))
        {
            printf("SEMANTIC ERROR(2) : Use without declaration of the variable: %s\n",$1->strValue);
        }
    SymbolType type = getSymbolType($1->strValue);
      switch (type) {
        case TYPE_INTEGER:
            $$->typeVar = TY_INT;
            //$$->iValue = (int)getSymbolValue($1->strValue).int_val;
            break;
        case TYPE_REAL:
            $$->typeVar = TY_REAL;
            //$$->rValue = (double)getSymbolValue($1->strValue).real_val;
            break;
        case TYPE_CHAR:
            $$->typeVar = TY_CHAR;
            //$$->cValue = (char)getSymbolValue($1->strValue).char_val;
            break;
        case TYPE_BOOLEAN:
            $$->typeVar = TY_BOOL;
            //$$->bValue = (int)getSymbolValue($1->strValue).bool_val;
            break;
        case TYPE_ARRAY:
            $$->typeVar = getArrayType($1->strValue);
            break;
    }
    $$->strValue = $1->strValue;
 }
;
initial_value : expression 
{
 	$$ = newNode(NODE_INIT_VAL);
    addChild($$, $1);
    $$->typeVar = $1->typeVar;
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
;
direction : TO
{
 	$$ = newNode(NODE_DIR);
    addChild($$, newNode(RE_TO));
 }
 | DOWNTO
 {
 	$$ = newNode(NODE_DIR);
    addChild($$, newNode(RE_DOWNTO));
 }
 ;

final_value : expression 
{
 	$$ = newNode(NODE_FIN_VAL);
    addChild($$, $1);
    $$->typeVar = $1->typeVar;
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
 };

boolean_expression : expression 
{
 	$$ = newNode(NODE_BOOL_EXPR);
    addChild($$, $1);
    $$->typeVar = $1->typeVar;
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
 };


expression : simple_expression
{
 	$$ = newNode(NODE_EXPR);
    addChild($$, $1);
    $$->typeVar = $1->typeVar;
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
 | simple_expression relop simple_expression
{
 	$$ = newNode(NODE_EXPR);
    addChild($$, $1);
    addChild($$, $2);
    addChild($$, $3);
    if($1->typeVar != $3->typeVar)
    {
      printf("SEMANTIC ERROR(3) : Type Mismatch : (%s) %s (%s)\n",convertType($1->typeVar) , $2->op,convertType($3->typeVar));
    }
    $$->typeVar = $1->typeVar;
    
    //RelOperation($$,$1,$2->op,$3);
    //printf("in expression: %d\n",$$->iValue);
 }
 ;

simple_expression : term
 {
  $$ = newNode(NODE_SIMPLE_EXP);
  addChild($$, $1); 
  $$->typeVar = $1->typeVar;
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
 | simple_expression addop term
 {
    $$ = $1;
    addChild($$, $2);
    addChild($$, $3); 
    if($1->typeVar != $3->typeVar)
    {
      printf("SEMANTIC ERROR(3) : Type Mismatch : (%s) %s (%s)\n",convertType($1->typeVar) , $2->op,convertType($3->typeVar));
    }
    $$->typeVar = $1->typeVar;
    //AddOperation($$,$2->op,$3);
 }
 ;
 
term : primary
{
      $$ = newNode(NODE_TERM);
   addChild($$, $1);
   $$->typeVar = $1->typeVar;
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
 | term mulop primary
{
      $$ = $1;
   addChild($$, $2);
   addChild($$, $3);
   if($1->typeVar != $3->typeVar)
    {
      printf("SEMANTIC ERROR(3) : Type Mismatch : (%s) %s (%s)\n",convertType($1->typeVar) , $2->op,convertType($3->typeVar));
    }
    $$->typeVar = $1->typeVar;
    //MulOperation($$,$2->op,$3);
 }
 ;
 
primary : variable_access
 {
      $$ = newNode(NODE_PRIMARY);
   addChild($$, $1);
   $$->typeVar = $1->typeVar;
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
 | unsigned_constant
  {
      $$ = newNode(NODE_PRIMARY);
   addChild($$, $1);
   $$->typeVar = $1->typeVar;
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
 | LPAREN expression RPAREN
 {
  $$ = newNode(NODE_PRIMARY);
  addChild($$, newNode(PUC_LPAREN));
  addChild($$, $2);
  addChild($$, newNode(PUC_RPAREN));
  $$->typeVar = $2->typeVar;
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
 | NOT primary
  {
  addChild($$, newNode(RE_NOT));
  $$=$2;
  $$->typeVar = TY_BOOL;
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
 ;

unsigned_constant : DIGSEQ
 {
  $$ = newNode(NODE_UNSIGN_CONST);
  addChild($$, newNode(DIGSEQ_TOK));
  $$->typeVar = TY_INT;
  $$->iValue =(int)$1; 
}
|REALNUMBER
{
  $$ = newNode(NODE_UNSIGN_CONST);
  addChild($$, newNode(REALNUMBER_TOK));
  $$->typeVar = TY_REAL;
  $$->rValue =$1; 
}
 | CHARACTER_STRING
{
    $$ = newNode(NODE_UNSIGN_CONST);
    addChild($$, newNode(CHAR_STRING_TOK));
    $$->typeVar = TY_STR;
    $$->strValue = $1; 
}
 | NIL
 {
    $$ = newNode(NODE_UNSIGN_CONST);
    addChild($$, newNode(RE_NIL));
}
 ;




addop: PLUS
{
  $$ = newNode(NODE_ADDOP);
  addChild($$, newNode(OP_PLUS));
  $$->op = "+";
}
 | MINUS
 {
  $$ = newNode(NODE_ADDOP);
  addChild($$, newNode(OP_MINUS));
  $$->op = "-";
}
 | OR
 {
  $$ = newNode(NODE_ADDOP);
  addChild($$, newNode(OP_OR));
  $$->op = "OR";
}
 ;

mulop : STAR
{
  $$ = newNode(NODE_MULOP);
  addChild($$, newNode(OP_STAR)); 
  $$->op = "*";
}
 | SLASH
{
  $$ = newNode(NODE_MULOP);
  addChild($$, newNode(OP_SLASH));
  $$->op = "/";
}
 | DIV
 {
  $$ = newNode(NODE_MULOP);
  addChild($$, newNode(OP_DIV)); 
  $$->op = "/";
}
 | MOD
 {
  $$ = newNode(NODE_MULOP);
  addChild($$, newNode(OP_MOD)); 
  $$->op = "%";
}
 | AND
 {
  $$ = newNode(NODE_MULOP);
  addChild($$, newNode(OP_AND));
  $$->op = "AND"; 
}
 ;

relop : EQUAL
{
  $$ = newNode(NODE_RELOP);
  addChild($$, newNode(OP_EQUAL)); 
  $$->op = "=";
}
 | NOTEQUAL
{
  $$ = newNode(NODE_RELOP);
  addChild($$, newNode(OP_notEQUAL)); 
  $$->op = "<>";
}
 | LT
 {
  $$ = newNode(NODE_RELOP);
  addChild($$, newNode(OP_LT)); 
  $$->op = "<";
}
 | GT
 {
  $$ = newNode(NODE_RELOP);
  addChild($$, newNode(OP_GT));
  $$->op = ">"; 
}
 | LE
 {
  $$ = newNode(NODE_RELOP);
  addChild($$, newNode(OP_LE)); 
  $$->op = "<=";
}
 | GE
 {
  $$ = newNode(NODE_RELOP);
  addChild($$, newNode(OP_GE)); 
  $$->op = ">=";
}
 | IN
 {
  $$ = newNode(NODE_RELOP);
  addChild($$, newNode(OP_IN)); 
  $$->op = "IN";
}
 ;


identifier : IDENTIFIER
{
  $$ = newNode(NODE_ID);
  addChild($$, newNode(ID_TOK)); 
  
  $$->strValue = $1;
  
}
 ;

semicolon : SEMICOLON
{
  $$ = newNode(NODE_SEMI);
  addChild($$, newNode(PUC_SEMI)); 
}
 ;
comma : COMMA
{
  $$ = newNode(NODE_COMMA);
  addChild($$, newNode(PUC_COMMA));
}
;


 %%

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