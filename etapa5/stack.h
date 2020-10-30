#include "hash.h"

#ifndef STACK_HEADER
#define STACK_HEADER

typedef struct stacknode
{
    HASH_NODE* symbol;
    struct stacknode *next;
} STACK_NODE;

STACK_NODE* push_node(STACK_NODE* head, HASH_NODE* symbol);
STACK_NODE* pop_node(STACK_NODE* head);
void pop_all_nodes(STACK_NODE* head);

#endif