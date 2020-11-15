#include "tac.h"
#include <string.h>


// used to know how many init values were
// given for the vector declaration
int vec_init_i = 0;


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

    if (tac->type == TAC_SYMBOL) return;
    //fprintf(stderr, "TAC(");

    switch (tac->type){
    case TAC_SYMBOL:
        fprintf(stderr, "TAC_SYMBOL"); break;
    case TAC_ADD:
        fprintf(stderr, "TAC_ADD"); break;
    case TAC_SUB:
        fprintf(stderr, "TAC_SUB"); break;
    case TAC_MUL:
        fprintf(stderr, "TAC_MUL"); break;
    case TAC_DIV:
        fprintf(stderr, "TAC_DIV"); break;
    case TAC_EQ:
        fprintf(stderr, "TAC_EQ"); break;
    case TAC_GE:
        fprintf(stderr, "TAC_GE"); break;
    case TAC_LE:
        fprintf(stderr, "TAC_LE"); break;
    case TAC_DIF:
        fprintf(stderr, "TAC_DIF"); break;
    case TAC_GRE:
        fprintf(stderr, "TAC_GRE"); break;
    case TAC_LES:
        fprintf(stderr, "TAC_LES"); break;
    case TAC_AND:
        fprintf(stderr, "TAC_AND"); break;
    case TAC_OR:
        fprintf(stderr, "TAC_OR"); break;
    case TAC_NOT:
        fprintf(stderr, "TAC_NOT"); break;
    case TAC_IFZ:
        fprintf(stderr, "TAC_IFZ"); break;
    case TAC_LABEL:
        fprintf(stderr, "TAC_LABEL"); break;
    case TAC_JUMP:
        fprintf(stderr, "TAC_JUMP"); break;
    case TAC_PRINT:
        fprintf(stderr, "TAC_PRINT"); break;
    case TAC_READ:
        fprintf(stderr, "TAC_READ"); break;
    case TAC_RET:
        fprintf(stderr, "TAC_RET"); break;
    case TAC_CALL:
        fprintf(stderr, "TAC_CALL"); break;
    case TAC_ARG:
        fprintf(stderr, "TAC_ARG"); break;
    case TAC_BEGINFUN:
        fprintf(stderr, "TAC_BEGINFUN"); break;
    case TAC_ENDFUN:
        fprintf(stderr, "TAC_ENDFUN"); break;
    
    case TAC_MOVE:
        fprintf(stderr, "TAC_MOVE"); break;
    
    default: fprintf(stderr, "TAC_UNKNOWN"); break;
    }

    fprintf(stderr,", %s", (tac->res) ? tac->res->text : "0");
    fprintf(stderr,", %s", (tac->op1) ? tac->op1->text : "0");
    fprintf(stderr,", %s", (tac->op2) ? tac->op2->text : "0");

    fprintf(stderr, "\n");

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


TAC* create_tac_bin_op(int tac_type, TAC* son1, TAC* son2){

    return tac_join(tac_join(son1, son2),
            tac_create(tac_type, make_temp(), son1?son1->res:0, son2?son2->res:0)); 
}


TAC* create_tac_if(TAC* son1, TAC* son2){

    TAC* jumptac = 0;
    TAC* labeltac = 0;
    HASH_NODE* newlabel = 0;

    newlabel = make_label();

    jumptac = tac_create(TAC_IFZ, newlabel, son1?son1->res:0, 0);
    jumptac->prev = son1;
    labeltac = tac_create(TAC_LABEL,newlabel,0,0);
    labeltac->prev = son2;

    return tac_join(jumptac, labeltac);
}


TAC* create_tac_if_else(TAC* son1, TAC* son2, TAC* son3){

    TAC* jumpz_tac = 0;
    TAC* jump_tac = 0;

    TAC* label_else_tac = 0;
    TAC* label_after_else_tac = 0;
    
    HASH_NODE* label_else = 0;
    HASH_NODE* label_after_else = 0;

    label_else = make_label();
    label_after_else = make_label();

    jumpz_tac = tac_create(TAC_IFZ, label_else, son1?son1->res:0, 0);
    jumpz_tac->prev = son1;

    jump_tac = tac_create(TAC_JUMP, label_after_else, 0, 0);
    jump_tac->prev = son2;

    label_else_tac = tac_create(TAC_LABEL,label_else,0,0);
    label_else_tac->prev = jump_tac;

    label_after_else_tac = tac_create(TAC_LABEL,label_after_else,0,0);
    label_after_else_tac->prev = son3;

    
    tac_join(jumpz_tac, jump_tac);
    return tac_join(label_else_tac,  label_after_else_tac);
}


TAC* create_tac_while(TAC* son1, TAC* son2){

    TAC* jumpz = 0;
    TAC* jump = 0;

    TAC* label_before_tac = 0;
    TAC* label_after_tac = 0;
    
    HASH_NODE* label_before = 0;
    HASH_NODE* label_after = 0;
    label_before = make_label();
    label_after = make_label();


    label_before_tac = tac_create(TAC_LABEL,label_before,0,0);
    label_before_tac->prev = son1;

    jumpz = tac_create(TAC_IFZ, label_after, son1?son1->res:0, 0);
    jumpz->prev = label_before_tac;

    jump = tac_create(TAC_JUMP, label_before, 0, 0);
    jump->prev = son2;

    label_after_tac = tac_create(TAC_LABEL,label_after,0,0);
    label_after_tac->prev = jump;

    tac_join(jumpz, jump);
    return label_after_tac;
}


TAC* create_tac_loop(HASH_NODE* symbol, TAC* son1, TAC* son2, TAC* son3, TAC* son4){

    HASH_NODE* label_before = make_label();
    HASH_NODE* label_after = make_label();
    HASH_NODE* temp_test = make_temp();
    HASH_NODE* temp_add = make_temp();
   
    TAC* init_i = tac_create(TAC_MOVE, symbol, son1?son1->res:0, 0);
    TAC* label_loop = tac_create(TAC_LABEL, label_before, 0, 0);
    TAC* les_test = tac_create(TAC_LES, temp_test, symbol, son2?son2->res:0);
    TAC* jumpz = tac_create(TAC_IFZ, label_after, temp_test, 0);
    TAC* add_i = tac_create(TAC_ADD, temp_add, symbol, son3?son3->res:0);
    TAC* update_i = tac_create(TAC_MOVE, symbol, temp_add, 0);   
    TAC* jump = tac_create(TAC_JUMP, label_before, 0, 0); 
    TAC* label_exit = tac_create(TAC_LABEL, label_after, 0, 0);



    init_i->prev = tac_join(son1, tac_join(son2, son3));
    label_loop->prev = init_i;
    les_test->prev = label_loop;
    jumpz->prev = les_test;
    add_i->prev = jumpz;
    update_i->prev = add_i;
    jump->prev = son4;
    label_exit->prev = tac_join(update_i, jump);

    return label_exit;
}


void fix_vec_initial_value_tacs(HASH_NODE* vec_identifier, TAC* current_tac_node){

    if (!current_tac_node)
        return;

    char buffer[8];
    TAC* aux_node = current_tac_node;
    for (aux_node; vec_init_i; aux_node=aux_node->prev){
        aux_node->res = vec_identifier;
        sprintf(buffer,"%d",vec_init_i-1);  //converts integer for indexation to string 
        aux_node->op2 = hashInsert(buffer, SYMBOL_LIT_INT);
        vec_init_i--;
    }
    return;
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
        result = tac_create(TAC_SYMBOL,node->symbol,0,0); 
        break;
    

    // IMPORTANT NOTE: THE TAC TYPES  VALUE FOR BIN OPERATORS ARE THE SAME
    // FOR THE AST TYPES (AST_ADD == 2 == TAC_ADD)
    case AST_ADD ... AST_OR: 
        result = create_tac_bin_op(node->type, code[0], code[1]);
        break;

    case AST_NOT:
        result = tac_join(code[0], tac_create(TAC_NOT, make_temp(), code[0]?code[0]->res:0, 0));
        break;

    

    case AST_ATTR:
        result = tac_join(code[0], tac_create(TAC_MOVE, node->symbol, code[0]?code[0]->res:0, 0));
        break;
    
    case AST_VAR_DEC:
        result = tac_join(code[0], tac_create(TAC_MOVE, node->symbol, code[1]?code[1]->res:0, 0));
        break;
    
    case AST_VEC_ATTR: 
        result = tac_join(code[0], 
                    tac_create(TAC_MOVE, node->symbol, code[1]?code[1]->res:0, code[0]?code[0]->res:0));
        break;
    
    case AST_VEC_INIT_VAL:
        // since there's no vector inside a vector declaration, we can count on a global manager variable
        result = tac_join(tac_create(TAC_MOVE, 0, code[0]?code[0]->res:0, 0), code[1]);
        // note: when reaching AST_VEC_DEC the TAC_MOVE will receive it's symbol and index
        vec_init_i++;
        break;

    case AST_VEC_DEC:
        fix_vec_initial_value_tacs(node->symbol, code[2]);
        result = code[2];
        break;

    case AST_IF:
        result = create_tac_if(code[0], code[1]);
        break;

    case AST_IF_ELSE:
        result = create_tac_if_else(code[0], code[1], code[2]);
        break;

    case AST_WHILE:
        result = create_tac_while(code[0], code[1]);
        break;
    
    case AST_LOOP:
        result = create_tac_loop(node->symbol, code[0], code[1], code[2], code[3]);
        break;

    case AST_LPRINT:
        if (code[0] && code[0]->type != TAC_SYMBOL)
            result = tac_join(tac_join(code[0], tac_create(TAC_PRINT, code[0]?code[0]->res:0, 0, 0)), code[1]);
        else
            result = tac_join(tac_create(TAC_PRINT, code[0]?code[0]->res:0, 0, 0), code[1]);
        break;
    
    case AST_READ:
        result = tac_create(TAC_READ, node->symbol, 0, 0);
        break;
    
    case AST_RETURN:
        result = tac_join(code[0], tac_create(TAC_RET, 0, code[0]?code[0]->res:0, 0));
        break;

    case AST_FOO_CALL:
        result = tac_join(code[0], tac_create(TAC_CALL,make_temp(),node->symbol,0));
        break;

    case AST_FOO_CALL_ARG:
        result = tac_join(tac_join(code[0], tac_create(TAC_ARG, 0, code[0]?code[0]->res:0, 0)), code[1]);
        break;

    case AST_FOO_DEC:
        result = tac_join(tac_join(tac_create(TAC_BEGINFUN,node->son[0]->symbol,0,0), code[1]),
                                    tac_create(TAC_ENDFUN,node->son[0]->symbol,0,0));
        break;
    

    default: 
        result = tac_join(code[0], tac_join(code[1], tac_join(code[2], code[3])));
        break;
    }


    return result;
}



TAC* tac_reverse(TAC* tac){

    TAC* t = tac;
    for (t=tac; t->prev; t=t->prev)
        t->prev->next = t;
    return t;
}