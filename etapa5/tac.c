#include "tac.h"

TAC* tac_create(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2){

    TAC* new_tac=0;
    new_tac = (TAC*) calloc(1,sizeof(TAC));
    new_tac->type = type;
    new_tac->res = res;
    new_tac->op1 = op1;
    new_tac->op2 = op2;
    new_tac->prev = 0;
    new_tac->next = 0;

    return new_tac;
}


void tac_print(TAC* tac){

    if (!tac)
        return;

    fprintf(stderr, "TAC(");

    switch (tac->type){
    case TAC_SYMBOL:
        fprintf(stderr, "TAC_SYMBOL"); break;
    case TAC_ADD:
        fprintf(stderr, "TAC_ADD"); break;
    case TAC_SUB:
        fprintf(stderr, "TAC_SUB"); break;
    
    default: fprintf(stderr, "TAC_UNKNOWN"); break;
    }

    fprintf(stderr,", %s", (tac->res) ? tac->res->text : "0");
    fprintf(stderr,", %s", (tac->op1) ? tac->op1->text : "0");
    fprintf(stderr,", %s", (tac->op2) ? tac->op2->text : "0");

    fprintf(stderr, ");\n");

}


void tac_print_backwards(TAC* tac){

    if (!tac)
        return;
    
    else {
        tac_print_backwards(tac->prev);
        tac_print(tac);
    }
    return;
}


TAC* tac_join(TAC* l1, TAC* l2){
    
    TAC* point;

    if (!l1) return l2;
    if (!l2) return l1;

    for (point=l2; point->prev != 0; point = point->prev)
        ; // do nothing, what we are interested in is terminate pointing to the last tac

    point->prev = l1;
    return l2;

}



TAC* generate_code(AST* node){

    TAC* result = 0;
    TAC* code[MAX_SONS];

    if (!node)
        return 0;

    // PROCESS CHILDREN
    for(int i=0; i<MAX_SONS; i++)
        code[i] = generate_code(node->son[i]);


    // PROCESS THIS NODE
    switch (node->type){
    
    case AST_SYMBOL:
        result = tac_create(TAC_SYMBOL,node->symbol,0,0); break;
    
    
    
    default: 
        result = tac_join(code[0], tac_join(code[1], tac_join(code[2], code[3])));
        break;
    }


    return result;
}