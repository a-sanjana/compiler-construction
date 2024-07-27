#ifndef OUTPUT_H
#define OUTPUT_H

#include "ast.h"
#include "sym.h"
#include <math.h>


void executeNode(Node *node);
void MulOperation(Node *node3,Node *node1, char *op, Node *node2);
void AddOperation(Node *node3,Node *node1, char *op, Node *node2);
void RelOperation(Node *node3, Node *node1,char *op, Node *node2);

#endif /* OUTPUT_H */
