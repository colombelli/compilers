#ifndef TACS_HEADER
#define TACS_HEADER

#include "hash.h"
#include "ast.h"

#define TAC_SYMBOL 1

// IMPORTANT NOTE: THE TAC TYPES FOR BIN OPERATIONS ARE THE SAME
// FOR THE AST TYPES
#define TAC_ADD 2
#define TAC_SUB 3
#define TAC_MUL 4
#define TAC_DIV 5
#define TAC_EQ 6
#define TAC_GE 7
#define TAC_LE 8
#define TAC_DIF 9
#define TAC_GRE 10
#define TAC_LES 11
#define TAC_AND 12
#define TAC_OR 13

#define TAC_NOT 14

#define TAC_COPY 42


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

TAC* create_tac_bin_op(int tac_type, TAC* son1, TAC* son2);

// CODE GENERATION
TAC* generate_code(AST* node);


#endif