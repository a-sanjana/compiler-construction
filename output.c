
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output.h"
#include "ast.h"
#include "sym.h"

void executeNode(Node *node)
{
    int num_childs = 0;
    while (node->childs[num_childs] != NULL)
    {
        num_childs++;
    }
    // printf("here\n");
    // int temp;
    // scanf("%d", &temp);
    switch (node->nodeType)
    {
    case NODE_PROGRAM:
        executeNode(node->childs[2]);
        break;
    case NODE_PROGRAM_HEAD:
        break;
    case NODE_ID_LIST:
        break;
    case NODE_BLOCK:
        executeNode(node->childs[1]);
        break;
    case NODE_VAR_DECL_PART:
        break;
    case NODE_VAR_ID_LIST:
        break;
    case NODE_VAR_DECL:
        break;
    case NODE_VAR_TYPE:
        break;
    case NODE_ARRAY:
        break;
    case NODE_SUBRANGE:
        break;
    case NODE_COMP_TYPE:
        break;
    case NODE_STMT_PART:
        executeNode(node->childs[0]);
        break;
    case NODE_COMP_STMT:
        executeNode(node->childs[1]);
        break;
    case NODE_STMT_SEQ:
        for (int i = 0; i < num_childs - 2; i += 2)
        {
            printf("out of stmt_%d\n", i);
            executeNode(node->childs[i]);
        }
        printf("out of stmt_seq\n");
        break;
    case NODE_STMT:
        executeNode(node->childs[0]);
        printf("out of statement\n");
        break;
    case NODE_OPEN_STMT:
        if (num_childs == 1)
        {
            executeNode(node->childs[0]);
        }
        else
        {
            executeNode(node->childs[2]);
        }
        break;
    case NODE_CLOSED_STMT:
        if (num_childs == 1)
        {
            executeNode(node->childs[0]);
        }
        else
        {
            executeNode(node->childs[2]);
        }
        printf("out of closed\n");
        break;
    case NODE_NL_OPEN:
        executeNode(node->childs[0]);
        break;
    case NODE_NL_CLOSED:
        executeNode(node->childs[0]);
        break;
    case NODE_OPEN_IF:

        if (num_childs == 4)
        {
            executeNode(node->childs[1]);
            Node *temp_open_if1 = node->childs[1];
            // printf("before if:%d\n",temp_open_if1->iValue);
            if (temp_open_if1->bValue)
            {
                executeNode(node->childs[3]);
            }
        }
        else
        {
            executeNode(node->childs[1]);
            Node *temp_open_if2 = node->childs[1];
            printf("before if:%d\n", temp_open_if2->bValue);
            if (temp_open_if2->bValue)
            {
                executeNode(node->childs[3]);
            }
            else
            {
                printf("in else\n");
                executeNode(node->childs[5]);
            }
        }
        break;
    case NODE_CLOSED_IF:
        executeNode(node->childs[1]);
        Node *temp_closed_if1 = node->childs[1];
        if (temp_closed_if1->bValue)
        {
            executeNode(node->childs[3]);
        }
        else
        {
            executeNode(node->childs[5]);
        }
        break;
    case NODE_OPEN_WHILE:
        executeNode(node->childs[1]);
        Node *temp_open_while1 = node->childs[1];
        while (temp_open_while1->bValue)
        {
            executeNode(node->childs[3]);
            executeNode(temp_open_while1);
        }
        break;
    case NODE_CLOSED_WHILE:
        executeNode(node->childs[1]);
        Node *temp_close_while = node->childs[1];
        while (temp_close_while->bValue)
        {
            executeNode(node->childs[3]);
            executeNode(temp_close_while);
        }
        break;
    case NODE_OPEN_FOR:
        executeNode(node->childs[3]);
        executeNode(node->childs[5]);
        Node *temp_open_for = node->childs[1];
        Node *temp_open_for_init = node->childs[3];
        Node *temp_open_for_fin = node->childs[5];
        int dir_node_type = node->childs[4]->childs[0]->nodeType;
        SymbolValue value_open_for;
        switch (temp_open_for->typeVar)
        {
        case TY_INT:
            value_open_for.int_val = temp_open_for_init->iValue;

            break;
        case TY_REAL:
            value_open_for.real_val = temp_open_for_init->rValue;
            break;
        case TY_CHAR:
            value_open_for.char_val = temp_open_for_init->cValue;
            break;
        case TY_BOOL:
            value_open_for.bool_val = temp_open_for_init->bValue; // 0 for false
            break;
        default:
            // Default to integer if unknown type
            value_open_for.int_val = temp_open_for_init->iValue;
            // printf("in assignment:%d\n",$3->iValue);
        }
        // printf("in assignment:%s\n",$1->strValue);
        insertSymbol(temp_open_for->strValue, temp_open_for->typeVar, value_open_for);
        //printSymbolTable();

        switch (temp_open_for->typeVar)
        {
        case TY_INT:
            if (dir_node_type == RE_TO)
            {
                int for1 = temp_open_for_init->iValue;
                while (for1 < temp_open_for_fin->iValue)
                {
                    executeNode(node->childs[7]);
                    for1++;
                    insertSymbol(temp_open_for->strValue, temp_open_for->typeVar, (SymbolValue){.int_val = for1});
                }
            }
            if (dir_node_type == RE_DOWNTO)
            {
                int for1 = temp_open_for_init->iValue;
                while (for1 > temp_open_for_fin->iValue)
                {
                    executeNode(node->childs[7]);
                    for1--;
                    insertSymbol(temp_open_for->strValue, temp_open_for->typeVar, (SymbolValue){.int_val = for1});
                    //printSymbolTable();
                }
            }

            break;
        case TY_REAL:
            if (dir_node_type == RE_TO)
            {
                double for2 = temp_open_for_init->rValue;
                while (for2 < temp_open_for_fin->rValue)
                {
                    executeNode(node->childs[7]);
                    for2++;
                    insertSymbol(temp_open_for->strValue, temp_open_for->typeVar, (SymbolValue){.real_val = for2});
                }
            }
            if (dir_node_type == RE_DOWNTO)
            {
                double for2 = temp_open_for_init->rValue;
                while (for2 > temp_open_for_fin->rValue)
                {
                    executeNode(node->childs[7]);
                    for2--;
                    insertSymbol(temp_open_for->strValue, temp_open_for->typeVar, (SymbolValue){.real_val = for2});
                }
            }

            break;
        case TY_CHAR:
            if (dir_node_type == RE_TO)
            {
                char for3 = temp_open_for_init->cValue;
                while (for3 < temp_open_for_fin->cValue)
                {
                    executeNode(node->childs[7]);
                    for3++;
                    insertSymbol(temp_open_for->strValue, temp_open_for->typeVar, (SymbolValue){.char_val = for3});
                }
            }
            if (dir_node_type == RE_DOWNTO)
            {
                char for3 = temp_open_for_init->cValue;
                while (for3 > temp_open_for_fin->cValue)
                {
                    executeNode(node->childs[7]);
                    for3--;
                    insertSymbol(temp_open_for->strValue, temp_open_for->typeVar, (SymbolValue){.char_val = for3});
                }
            }
            break;
        case TY_BOOL:
            if (dir_node_type == RE_TO)
            {
                int for4 = temp_open_for_init->bValue;
                while (for4 < temp_open_for_fin->bValue)
                {
                    executeNode(node->childs[7]);
                    for4++;
                    insertSymbol(temp_open_for->strValue, temp_open_for->typeVar, (SymbolValue){.bool_val = for4});
                }
            }
            if (dir_node_type == RE_DOWNTO)
            {
                int for4 = temp_open_for_init->bValue;
                while (for4 > temp_open_for_fin->bValue)
                {
                    executeNode(node->childs[7]);
                    for4--;
                    insertSymbol(temp_open_for->strValue, temp_open_for->typeVar, (SymbolValue){.bool_val = for4});
                }
            }
            break;
        default:
            // Default to integer if unknown type
            value_open_for.int_val = temp_open_for_init->iValue;
            // printf("in assignment:%d\n",$3->iValue);
        }
        break;
    case NODE_CLOSED_FOR:
        executeNode(node->childs[3]);
        executeNode(node->childs[5]);
        Node *temp_closed_for = node->childs[1];
        Node *temp_closed_for_init = node->childs[3];
        Node *temp_closed_for_fin = node->childs[5];
        int dir_node_type1 = node->childs[4]->childs[0]->nodeType;
        SymbolValue value_closed_for;
        switch (temp_closed_for->typeVar)
        {
        case TY_INT:
            value_closed_for.int_val = temp_closed_for_init->iValue;

            break;
        case TY_REAL:
            value_closed_for.real_val = temp_closed_for_init->rValue;
            break;
        case TY_CHAR:
            value_closed_for.char_val = temp_closed_for_init->cValue;
            break;
        case TY_BOOL:
            value_closed_for.bool_val = temp_closed_for_init->bValue; // 0 for false
            break;
        default:
            // Default to integer if unknown type
            value_closed_for.int_val = temp_closed_for_init->iValue;
            // printf("in assignment:%d\n",$3->iValue);
        }
        // printf("in assignment:%s\n",$1->strValue);
        insertSymbol(temp_closed_for->strValue, temp_closed_for->typeVar, value_closed_for);

        switch (temp_closed_for->typeVar)
        {
        case TY_INT:
            if (dir_node_type1 == RE_TO)
            {
                int for5 = temp_closed_for_init->iValue;
                while (for5 < temp_closed_for_fin->iValue)
                {
                    executeNode(node->childs[7]);
                    for5++;
                    insertSymbol(temp_closed_for->strValue, temp_closed_for->typeVar, (SymbolValue){.int_val = for5});
                    //printSymbolTable();
                }
            }
            if (dir_node_type1 == RE_DOWNTO)
            {
                int for5 = temp_closed_for_init->iValue;
                while (for5 > temp_closed_for_fin->iValue)
                {
                    executeNode(node->childs[7]);
                    for5--;
                    insertSymbol(temp_closed_for->strValue, temp_closed_for->typeVar, (SymbolValue){.int_val = for5});
                }
            }

            break;
        case TY_REAL:
            if (dir_node_type1 == RE_TO)
            {
                double for6 = temp_closed_for_init->rValue;
                while (for6 < temp_closed_for_fin->rValue)
                {
                    executeNode(node->childs[7]);
                    for6++;
                    insertSymbol(temp_closed_for->strValue, temp_closed_for->typeVar, (SymbolValue){.real_val = for6});
                }
            }
            if (dir_node_type1 == RE_DOWNTO)
            {
                double for6 = temp_closed_for_init->rValue;
                while (for6 > temp_closed_for_fin->rValue)
                {
                    executeNode(node->childs[7]);
                    for6--;
                    insertSymbol(temp_closed_for->strValue, temp_closed_for->typeVar, (SymbolValue){.real_val = for6});
                }
            }

            break;
        case TY_CHAR:
            if (dir_node_type1 == RE_TO)
            {
                char for7 = temp_closed_for_init->cValue;
                while (for7 < temp_closed_for_fin->cValue)
                {
                    executeNode(node->childs[7]);
                    for7++;
                    insertSymbol(temp_closed_for->strValue, temp_closed_for->typeVar, (SymbolValue){.char_val = for7});
                }
            }
            if (dir_node_type1 == RE_DOWNTO)
            {
                char for7 = temp_closed_for_init->cValue;
                while (for7 > temp_closed_for_fin->cValue)
                {
                    executeNode(node->childs[7]);
                    for7--;
                    insertSymbol(temp_closed_for->strValue, temp_closed_for->typeVar, (SymbolValue){.char_val = for7});
                }
            }
            break;
        case TY_BOOL:
            if (dir_node_type1 == RE_TO)
            {
                int for8 = temp_closed_for_init->bValue;
                while (for8 < temp_closed_for_fin->bValue)
                {
                    executeNode(node->childs[7]);
                    for8++;
                    insertSymbol(temp_closed_for->strValue, temp_closed_for->typeVar, (SymbolValue){.bool_val = for8});
                }
            }
            if (dir_node_type1 == RE_DOWNTO)
            {
                int for8 = temp_closed_for_init->bValue;
                while (for8 > temp_closed_for_fin->bValue)
                {
                    executeNode(node->childs[7]);
                    for8--;
                    insertSymbol(temp_closed_for->strValue, temp_closed_for->typeVar, (SymbolValue){.bool_val = for8});
                }
            }
            break;
        default:
            // Default to integer if unknown type
            value_closed_for.int_val = temp_closed_for_init->iValue;
            // printf("in assignment:%d\n",$3->iValue);
        }
        break;
    case NODE_ASGMNT_STMT:
        SymbolValue value1;
        executeNode(node->childs[0]);
        executeNode(node->childs[2]);
        Node *temp_ass = node->childs[2];
        switch (node->typeVar)
        {
        case TY_INT:
            value1.int_val = temp_ass->iValue;
            printf("in assignment:%d\n", temp_ass->iValue);
            break;
        case TY_REAL:
            value1.real_val = temp_ass->rValue;
            break;
        case TY_CHAR:
            value1.char_val = temp_ass->cValue;
            break;
        case TY_BOOL:
            value1.bool_val = temp_ass->bValue; // 0 for false
            break;
        default:
            // Default to integer if unknown type
            value1.int_val = temp_ass->iValue;
            // printf("in assignment:%d\n",$3->iValue);
        }
        printf("in assignment:%s\n", node->childs[0]->strValue);
        insertSymbol(node->childs[0]->strValue, node->childs[0]->typeVar, value1);
        //printSymbolTable();
        break;
    case NODE_READ_STMT:
        executeNode(node->childs[2]);
        Node *mynode = node->childs[2];
        printf("checking for:%s\n",mynode->strValue);
        SymbolType type_read = getSymbolType(mynode->strValue);
        printf("inside read\n");
        SymbolValue value2;
        switch (type_read)
        {
        case TYPE_INTEGER:
            node->typeVar = TY_INT;
            int temp1;
            printf("inside\n");
            scanf("%d", &temp1);
            value2.int_val = temp1;
            break;
        case TYPE_REAL:
            node->typeVar = TY_REAL;
            double temp2;
            scanf("%lf", &temp2);
            value2.real_val = temp2;
            break;
        case TYPE_CHAR:
            node->typeVar = TY_CHAR;
            char temp3;
            printf("inside\n");
            scanf("%c", &temp3);
            value2.char_val = temp3;
            printf("inside%c\n", temp3);
            break;
        case TYPE_BOOLEAN:
            node->typeVar = TY_BOOL;
            int temp4;
            scanf("%d", &temp4);
            value2.bool_val = temp4;
            break;
        case TYPE_ARRAY:
            node->typeVar = TY_ARRAY;
            break;
        }
        printf("checking for:%s\n",mynode->strValue);
        insertSymbol(mynode->strValue, mynode->typeVar, value2);
    
        break;
    case NODE_WRITE_STMT:
        Node *charchild = node->childs[2]->childs[0];

    if(charchild->nodeType == CHAR_STRING_TOK)
    {
        printf("%s", node->childs[2]->strValue);
        break;
    }
    executeNode(node->childs[2]->childs[0]);

        break;
    case NODE_ID_LIST1:
        for(int ij=0;ij<num_childs;ij+=2)
        {
            executeNode(node->childs[ij]);
            Node *childnow = node->childs[ij];
            SymbolType typenow= getSymbolType(childnow->strValue);
            switch (typenow)
        {
        case TYPE_INTEGER:
            printf("%d\n",(int)getSymbolValue(childnow->strValue).int_val);
            break;
        case TYPE_REAL:
            printf("%lf\n",(double)getSymbolValue(childnow->strValue).real_val);
            break;
        case TYPE_CHAR:
            printf("%c\n",(char)getSymbolValue(childnow->strValue).char_val);
            break;
        case TYPE_BOOLEAN:
            printf("%d\n",(int)getSymbolValue(childnow->strValue).bool_val);
            break;
        case TYPE_ARRAY:
            // node->typeVar = getArrayType(temp_var_ac->strValue);
            break;
        }
        }
        break;
    case NODE_LIST:
        break;
    case NODE_ID1:
    executeNode(node->childs[0]);
    if (node->childs[0]->nodeType == NODE_IND_VAR)
        {
            printf("var acc array\n");
            executeNode(node->childs[0]);
            node->strValue = node->childs[0]->strValue;
            Node *node_var_acc_child1 = node->childs[0];
            switch (node->typeVar)
            {
            case TY_INT:
                node->iValue = node_var_acc_child1->iValue;
                printf("var acc for array %d\n",node->iValue);
                break;
            case TY_REAL:
                node->rValue = node_var_acc_child1->rValue;
                break;
            case TY_CHAR:
                node->cValue = node_var_acc_child1->cValue;
                break;
            case TY_BOOL:
                node->bValue = node_var_acc_child1->bValue;
                break;
            case TYPE_ARRAY:
                // node->typeVar = getArrayType(temp_var_ac->strValue);
                break;
            }
            printf("checking for:%s\n",node->strValue);
            break;
        }
        char *temp_var_ac1 = node->childs[0]->strValue;
        SymbolType type_var_acc1 = getSymbolType(temp_var_ac1);
        switch (type_var_acc1)
        {
        case TYPE_INTEGER:
            node->typeVar = TY_INT;
            node->iValue = (int)getSymbolValue(temp_var_ac1).int_val;
            break;
        case TYPE_REAL:
            node->typeVar = TY_REAL;
            node->rValue = (double)getSymbolValue(temp_var_ac1).real_val;
            break;
        case TYPE_CHAR:
            node->typeVar = TY_CHAR;
            node->cValue = (char)getSymbolValue(temp_var_ac1).char_val;
            break;
        case TYPE_BOOLEAN:
            node->typeVar = TY_BOOL;
            node->bValue = (int)getSymbolValue(temp_var_ac1).bool_val;
            break;
        case TYPE_ARRAY:
            // node->typeVar = getArrayType(temp_var_ac->strValue);
            break;
        }
        break;
    case NODE_VAR_ACC:
        if (node->childs[0]->nodeType == NODE_IND_VAR)
        {
            printf("var acc array\n");
            executeNode(node->childs[0]);
            node->strValue = node->childs[0]->strValue;
            Node *node_var_acc_child = node->childs[0];
            switch (node->typeVar)
            {
            case TY_INT:
                node->iValue = node_var_acc_child->iValue;
                printf("var acc for array %d\n",node->iValue);
                break;
            case TY_REAL:
                node->rValue = node_var_acc_child->rValue;
                break;
            case TY_CHAR:
                node->cValue = node_var_acc_child->cValue;
                break;
            case TY_BOOL:
                node->bValue = node_var_acc_child->bValue;
                break;
            case TYPE_ARRAY:
                // node->typeVar = getArrayType(temp_var_ac->strValue);
                break;
            }
            break;
        }
        char *temp_var_ac = node->childs[0]->strValue;
        SymbolType type_var_acc = getSymbolType(temp_var_ac);
        switch (type_var_acc)
        {
        case TYPE_INTEGER:
            node->typeVar = TY_INT;
            node->iValue = (int)getSymbolValue(temp_var_ac).int_val;
            break;
        case TYPE_REAL:
            node->typeVar = TY_REAL;
            node->rValue = (double)getSymbolValue(temp_var_ac).real_val;
            break;
        case TYPE_CHAR:
            node->typeVar = TY_CHAR;
            node->cValue = (char)getSymbolValue(temp_var_ac).char_val;
            break;
        case TYPE_BOOLEAN:
            node->typeVar = TY_BOOL;
            node->bValue = (int)getSymbolValue(temp_var_ac).bool_val;
            break;
        case TYPE_ARRAY:
            // node->typeVar = getArrayType(temp_var_ac->strValue);
            break;
        }
        break;
    case NODE_IND_VAR:
        executeNode(node->childs[2]);
        char *temp_ind_var = node->childs[0]->strValue;
        printf("strvale :%s\n",temp_ind_var);
        
        int index = node->childs[2]->iValue;
        printf("index value %d\n",index);
        char buffer[100];
        snprintf(buffer, sizeof(buffer), "%s[%d]", temp_ind_var, index);
        printf("in node ind var:%s\n", buffer);
        SymbolType type_var_ac = getSymbolType(buffer);
        node->strValue = buffer;
        switch (type_var_ac)
        {
        case TYPE_INTEGER:
            node->typeVar = TY_INT;
            node->iValue = (int)getSymbolValue(buffer).int_val;
            printf("ind var: %d\n",node->iValue);
            break;
        case TYPE_REAL:
            node->typeVar = TY_REAL;
            node->rValue = (double)getSymbolValue(buffer).real_val;
            break;
        case TYPE_CHAR:
            node->typeVar = TY_CHAR;
            node->cValue = (char)getSymbolValue(buffer).char_val;
            break;
        case TYPE_BOOLEAN:
            node->typeVar = TY_BOOL;
            node->bValue = (int)getSymbolValue(buffer).bool_val;
            break;
        case TYPE_ARRAY:
            // node->typeVar = getArrayType(temp_var_ac->strValue);
            break;
        }
        break;
    case NODE_CONT_VAR:
        char *temp_cont_var = node->childs[0]->strValue;
        SymbolType type_cont_var = getSymbolType(temp_cont_var);
        switch (type_cont_var)
        {
        case TYPE_INTEGER:
            node->typeVar = TY_INT;
            node->iValue = (int)getSymbolValue(temp_cont_var).int_val;
            break;
        case TYPE_REAL:
            node->typeVar = TY_REAL;
            node->rValue = (double)getSymbolValue(temp_cont_var).real_val;
            break;
        case TYPE_CHAR:
            node->typeVar = TY_CHAR;
            node->cValue = (char)getSymbolValue(temp_cont_var).char_val;
            break;
        case TYPE_BOOLEAN:
            node->typeVar = TY_BOOL;
            node->bValue = (int)getSymbolValue(temp_cont_var).bool_val;
            break;
        case TYPE_ARRAY:
            node->typeVar = getArrayType(node->childs[0]->strValue);
            break;
        }
        break;
    case NODE_INIT_VAL:
        executeNode(node->childs[0]);
        Node *temp_init_val = node->childs[0];
        switch (temp_init_val->typeVar)
        {
        case TY_INT:
            node->iValue = (temp_init_val->iValue);
            break;
        case TY_REAL:
            node->rValue = (temp_init_val->rValue);
            break;
        case TY_CHAR:
            node->cValue = (temp_init_val->cValue);
            break;
        case TY_BOOL:
            node->bValue = (temp_init_val->bValue);
            break;
        case NODE_ARRAY:
            break;
        }
        break;
    case NODE_DIR:
        break;
    case NODE_FIN_VAL:
        executeNode(node->childs[0]);
        Node *temp_fin_val = node->childs[0];
        switch (temp_fin_val->typeVar)
        {
        case TY_INT:
            node->iValue = (temp_fin_val->iValue);
            break;
        case TY_REAL:
            node->rValue = (temp_fin_val->rValue);
            break;
        case TY_CHAR:
            node->cValue = (temp_fin_val->cValue);
            break;
        case TY_BOOL:
            node->bValue = (temp_fin_val->bValue);
            break;
        case NODE_ARRAY:
            break;
        }
        break;
    case NODE_BOOL_EXPR:
        executeNode(node->childs[0]);
        Node *temp_bool_expr = node->childs[0];
        switch (temp_bool_expr->typeVar)
        {
        case TY_INT:
            node->bValue = (int)(temp_bool_expr->iValue);
            break;
        case TY_REAL:
            node->bValue = (int)(temp_bool_expr->rValue);
            break;
        case TY_CHAR:
            node->bValue = (int)(temp_bool_expr->cValue);
            break;
        case TY_BOOL:
            node->bValue = (int)(temp_bool_expr->bValue);
            break;
        case NODE_ARRAY:
            break;
        }
        printf("boolean value:%d\n", node->iValue);
        break;
    case NODE_EXPR:
        if (num_childs == 3)
        {
            executeNode(node->childs[0]);
            executeNode(node->childs[2]);
            Node *temp_expr1 = node->childs[0];
            Node *temp2 = node->childs[2];
            RelOperation(node, temp_expr1, node->childs[1]->op, temp2);
        }
        else
        {
            executeNode(node->childs[0]);
            Node *temp_expr1 = node->childs[0];
            switch (temp_expr1->typeVar)
            {
            case TY_INT:
                node->iValue = (temp_expr1->iValue);
                break;
            case TY_REAL:
                node->rValue = (temp_expr1->rValue);
                break;
            case TY_CHAR:
                node->cValue = (temp_expr1->cValue);
                break;
            case TY_BOOL:
                node->bValue = (temp_expr1->bValue);
                break;
            case NODE_ARRAY:
                break;
            }
        }
        break;
    case NODE_SIMPLE_EXP:
        if (num_childs == 3)
        {
            executeNode(node->childs[0]);
            executeNode(node->childs[2]);
            Node *temp6 = node->childs[0];
            Node *temp7 = node->childs[2];
            AddOperation(node, temp6, node->childs[1]->op, temp7);
        }
        else
        {
            executeNode(node->childs[0]);
            Node *temp5 = node->childs[0];
            switch (temp5->typeVar)
            {
            case TY_INT:
                node->iValue = (temp5->iValue);
                break;
            case TY_REAL:
                node->rValue = (temp5->rValue);
                break;
            case TY_CHAR:
                node->cValue = (temp5->cValue);
                break;
            case TY_BOOL:
                node->bValue = (temp5->bValue);
                break;
            case NODE_ARRAY:
                break;
            }
        }
        break;
    case NODE_TERM:
        if (num_childs == 3)
        {
            executeNode(node->childs[0]);
            executeNode(node->childs[2]);
            Node *temp_term1 = node->childs[0];
            Node *temp2 = node->childs[2];
            MulOperation(node, temp_term1, node->childs[1]->op, temp2);
        }
        else
        {
            executeNode(node->childs[0]);
            Node *temp4 = node->childs[0];
            switch (temp4->typeVar)
            {
            case TY_INT:
                node->iValue = (temp4->iValue);
                break;
            case TY_REAL:
                node->rValue = (temp4->rValue);
                break;
            case TY_CHAR:
                node->cValue = (temp4->cValue);
                break;
            case TY_BOOL:
                node->bValue = (temp4->bValue);
                break;
            case NODE_ARRAY:
                break;
            }
        }
        break;
    case NODE_PRIMARY:
        if (num_childs == 2)
        {
            executeNode(node->childs[1]);
            Node *temp_term1 = node->childs[1];
            switch (temp_term1->typeVar)
            {
            case TY_INT:
                node->bValue = !(temp_term1->iValue);
                break;
            case TY_REAL:
                node->bValue = !(temp_term1->rValue);
                break;
            case TY_CHAR:
                node->bValue = !(temp_term1->cValue);
                break;
            case TY_BOOL:
                node->bValue = !(temp_term1->bValue);
                break;
            case NODE_ARRAY:
                break;
            }
        }
        else if (num_childs == 3)
        {
            executeNode(node->childs[1]);
            Node *temp3 = node->childs[1];
            switch (temp3->typeVar)
            {
            case TY_INT:
                node->iValue = (temp3->iValue);
                break;
            case TY_REAL:
                node->rValue = (temp3->rValue);
                break;
            case TY_CHAR:
                node->cValue = (temp3->cValue);
                break;
            case TY_BOOL:
                node->bValue = (temp3->bValue);
                break;
            case NODE_ARRAY:
                break;
            }
        }
        else
        {
            executeNode(node->childs[0]);
            Node *node_prim_var_acc_child = node->childs[0];
            if (node->childs[0]->nodeType == NODE_VAR_ACC)
            {
                
                switch (node->typeVar)
                {
                case TY_INT:
                    node->iValue = node_prim_var_acc_child->iValue;
                    printf("var acc array primary %d\n",node->iValue);
                    break;
                case TY_REAL:
                    node->rValue = node_prim_var_acc_child->rValue;
                    break;
                case TY_CHAR:
                    node->cValue = node_prim_var_acc_child->cValue;
                    break;
                case TY_BOOL:
                    node->bValue = node_prim_var_acc_child->bValue;
                    break;
                case TYPE_ARRAY:
                    // node->typeVar = getArrayType(temp_var_ac->strValue);
                    break;
                }
                break;
            }
            Node *temp2 = node->childs[0];
            switch (temp2->typeVar)
            {
            case TY_INT:
                node->iValue = (temp2->iValue);
                break;
            case TY_REAL:
                node->rValue = (temp2->rValue);
                break;
            case TY_CHAR:
                node->cValue = (temp2->cValue);
                break;
            case TY_BOOL:
                node->bValue = (temp2->bValue);
                break;
            case NODE_ARRAY:
                break;
            }
        }
        break;
    case NODE_UNSIGN_CONST:
        // switch(node->childs[0]->nodeType)
        // {
        //     case DIGSEQ_TOK:
        //     node->iValue =(int)$1;
        //     break;
        //     case REALNUMBER_TOK:
        //     node->rValue =$1;
        //     break;
        //     case CHAR_STRING_TOK:
        //     $$->strValue =$1;
        //     break;
        // }
        break;
    case NODE_ADDOP:
        break;
    case NODE_MULOP:
        break;
    case NODE_RELOP:
        break;
    case NODE_SEMI:
        break;
    case NODE_COMMA:
        break;
    case NODE_LABEL:
        break;
    default:
        // Handle unexpected node types
        break;
    }
}

void MulOperation(Node *node3, Node *node1, char *op, Node *node2)
{
    switch (node1->typeVar)
    {

    case TY_INT:
        if (strcmp(op, "*") == 0)
        {
            node3->iValue = (node1->iValue) * (node2->iValue);
        }
        else if (strcmp(op, "/") == 0)
        {
            node3->iValue = node1->iValue / node2->iValue;
        }
        else if (strcmp(op, "%") == 0)
        {
            node3->iValue = node1->iValue % node2->iValue;
        }
        else if (strcmp(op, "AND") == 0)
        {
            node3->iValue = node1->iValue && node2->iValue;
        }
        break;
    case TY_REAL:
        if (strcmp(op, "*") == 0)
        {
            node3->rValue = node1->rValue * node2->rValue;
        }
        else if (strcmp(op, "/") == 0)
        {
            node3->rValue = node1->rValue / node2->rValue;
        }
        else if (strcmp(op, "%") == 0)
        {
            node3->rValue = fmod(node1->rValue, node2->rValue);
        }
        else if (strcmp(op, "AND") == 0)
        {
            node3->iValue = node1->rValue && node2->rValue;
        }
        break;
    case TY_CHAR:
        if (strcmp(op, "*") == 0)
        {
            node3->cValue = node1->cValue * node2->cValue;
        }
        else if (strcmp(op, "/") == 0)
        {
            node3->cValue = node1->cValue / node2->cValue;
        }
        else if (strcmp(op, "%") == 0)
        {
            node3->cValue = node1->cValue % node2->cValue;
        }
        else if (strcmp(op, "AND") == 0)
        {
            node3->cValue = node1->cValue && node2->cValue;
        }
        break;
    case TY_BOOL:
        if (strcmp(op, "*") == 0)
        {
            node3->bValue = node1->bValue * node2->bValue;
        }
        else if (strcmp(op, "/") == 0)
        {
            node3->bValue = node1->bValue / node2->bValue;
        }
        else if (strcmp(op, "%") == 0)
        {
            node3->bValue = node1->bValue % node2->bValue;
        }
        else if (strcmp(op, "AND") == 0)
        {
            node3->bValue = node1->bValue && node2->bValue;
        }
        break;
    case NODE_ARRAY:
        break;
    }
}

void AddOperation(Node *node3, Node *node1, char *op, Node *node2)
{
    switch (node1->typeVar)
    {

    case TY_INT:
        if (strcmp(op, "+") == 0)
        {
            node3->iValue = (node1->iValue) + (node2->iValue);
        }
        else if (strcmp(op, "-") == 0)
        {
            node3->iValue = node1->iValue - node2->iValue;
        }
        else if (strcmp(op, "OR") == 0)
        {
            node3->iValue = node1->iValue || node2->iValue;
        }
        break;
    case TY_REAL:
        if (strcmp(op, "+") == 0)
        {
            node3->rValue = node1->rValue + node2->rValue;
        }
        else if (strcmp(op, "-") == 0)
        {
            node3->rValue = node1->rValue - node2->rValue;
        }
        else if (strcmp(op, "OR") == 0)
        {
            node3->rValue = node1->rValue || node2->rValue;
        }
        break;
    case TY_CHAR:
        if (strcmp(op, "+") == 0)
        {
            node3->cValue = node1->cValue * node2->cValue;
        }
        else if (strcmp(op, "-") == 0)
        {
            node3->cValue = node1->cValue / node2->cValue;
        }
        else if (strcmp(op, "OR") == 0)
        {
            node3->cValue = node1->cValue % node2->cValue;
        }
        break;
    case TY_BOOL:
        if (strcmp(op, "+") == 0)
        {
            node3->bValue = node1->bValue + node2->bValue;
        }
        else if (strcmp(op, "-") == 0)
        {
            node3->bValue = node1->bValue - node2->bValue;
        }
        else if (strcmp(op, "OR") == 0)
        {
            node3->bValue = node1->bValue || node2->bValue;
        }

        break;
    case NODE_ARRAY:
        break;
    }
}

void RelOperation(Node *node3, Node *node1, char *op, Node *node2)
{
    switch (node1->typeVar)
    {
    case TY_INT:
        if (strcmp(op, "=") == 0)
        {
            node3->iValue = (node1->iValue) == (node2->iValue);
        }
        else if (strcmp(op, "<>") == 0)
        {
            node3->iValue = node1->iValue != node2->iValue;
        }
        else if (strcmp(op, "<") == 0)
        {
            node3->iValue = node1->iValue < node2->iValue;
        }
        else if (strcmp(op, ">") == 0)
        {
            node3->iValue = node1->iValue > node2->iValue;
        }
        else if (strcmp(op, "<=") == 0)
        {
            node3->iValue = node1->iValue <= node2->iValue;
        }
        else if (strcmp(op, ">=") == 0)
        {
            node3->iValue = node1->iValue >= node2->iValue;
        }
        break;
    case TY_REAL:
        if (strcmp(op, "=") == 0)
        {
            node3->rValue = (node1->rValue) == (node2->rValue);
        }
        else if (strcmp(op, "<>") == 0)
        {
            node3->rValue = node1->rValue != node2->rValue;
        }
        else if (strcmp(op, "<") == 0)
        {
            node3->rValue = node1->rValue < node2->rValue;
        }
        else if (strcmp(op, ">") == 0)
        {
            node3->rValue = node1->rValue > node2->rValue;
        }
        else if (strcmp(op, "<=") == 0)
        {
            node3->rValue = node1->rValue <= node2->rValue;
        }
        else if (strcmp(op, ">=") == 0)
        {
            node3->rValue = node1->rValue >= node2->rValue;
        }
        break;
    case TY_CHAR:
        if (strcmp(op, "=") == 0)
        {
            node3->cValue = (node1->cValue) == (node2->cValue);
        }
        else if (strcmp(op, "<>") == 0)
        {
            node3->cValue = node1->cValue != node2->cValue;
        }
        else if (strcmp(op, "<") == 0)
        {
            node3->cValue = node1->cValue < node2->cValue;
        }
        else if (strcmp(op, ">") == 0)
        {
            node3->cValue = node1->cValue > node2->cValue;
        }
        else if (strcmp(op, "<=") == 0)
        {
            node3->cValue = node1->cValue <= node2->cValue;
        }
        else if (strcmp(op, ">=") == 0)
        {
            node3->cValue = node1->cValue >= node2->cValue;
        }
        break;
    case TY_BOOL:
        if (strcmp(op, "=") == 0)
        {
            node3->bValue = (node1->bValue) == (node2->bValue);
        }
        else if (strcmp(op, "<>") == 0)
        {
            node3->bValue = node1->bValue != node2->bValue;
        }
        else if (strcmp(op, "<") == 0)
        {
            node3->bValue = node1->bValue < node2->bValue;
        }
        else if (strcmp(op, ">") == 0)
        {
            node3->bValue = node1->bValue > node2->bValue;
        }
        else if (strcmp(op, "<=") == 0)
        {
            node3->bValue = node1->bValue <= node2->bValue;
        }
        else if (strcmp(op, ">=") == 0)
        {
            node3->bValue = node1->bValue >= node2->bValue;
        }

        break;
    case NODE_ARRAY:
        break;
    }
}