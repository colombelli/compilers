#ifndef TACS_HEADER
#define TACS_HEADER

#include "hash.h"
#include "ast.h"

#define TAC_SYMBOL 1
#define TAC_ADD 2
#define TAC_SUB 3


typedef struct tac_node{
    int type;
    HASH_NODE* res;
    HASH_NODE* op1;
    HASH_NODE* op2;
    struct tac_node* prev;
    struct tac_node* next;
} TAC;


TAC* tac_create(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2);
void tac_print(TAC* tac);
void tac_print_backwards(TAC* tac);
TAC* tac_join(TAC* l1, TAC* l2);


// CODE GENERATION
TAC* generate_code(AST* node);


#endif