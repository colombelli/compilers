#include "hash.h"

#ifndef STACK_HEADER
#define STACK_HEADER

typedef struct stacknode
{
    HASH_NODE* symbol;
    struct stacknode *next;
} STACK_NODE;

#endif