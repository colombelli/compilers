#include "hash.h"
#include "stack.h"
#include <stdio.h>

HASH_NODE *Hashtable[HASH_SIZE];


void hashInit(void) {
    for (int i=0; i<HASH_SIZE; i++){
        Hashtable[i]=0;
    } 
}


int hashAddress(char *text){

    int address = 1;
    for(int i=0; i<strlen(text); i++){
        address = ((address * text[i]) % HASH_SIZE)+1;
    }
    return address-1;
}


HASH_NODE *hashFind(char *text){

    int address = hashAddress(text);
    HASH_NODE *node;

    for(node=Hashtable[address]; node; node=node->next){
        if (!strcmp(node->text, text)){
            return node;
        }
    }
    return NULL; 
}


HASH_NODE *hashInsert(char *text, int lexType){
    int nodeAddress = hashAddress(text);
    HASH_NODE *newNode = hashFind(text);

    if(newNode){
        return newNode;
    }

    newNode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
    newNode->type = lexType;
    newNode->text = (char*) calloc(strlen(text) + 1, sizeof(char));
    strcpy(newNode->text, text);
    newNode->next = Hashtable[nodeAddress];
    newNode->foo_args = NULL;
    Hashtable[nodeAddress] = newNode;
    return newNode;
}


void hashPrint(void){

    printf("\n---- Hashtable ----\n\n");

    HASH_NODE *node;
    for(int i=0; i<HASH_SIZE; i++){
        for(node=Hashtable[i]; node; node=node->next){
            printf("Address %d: %s (TYPE: %d | DATATYPE: %d)\n", i, node->text, node->type, node->datatype);
        }
    }
    printf("\n---- End of Hashtable ----\n\n");
}



int hash_check_undeclared(void){
    int undeclared = 0;
    HASH_NODE *node;


    for(int i=0; i<HASH_SIZE; i++){
        for(node=Hashtable[i]; node; node=node->next){

            if (node->type == SYMBOL_IDENTIFIER){ //i.e. it was inserted on hash, but didn't received a specific type by semantic.c
                fprintf(stderr, "(hash)Semantic ERROR! Undeclared identifier: %s\n", node->text);
                ++undeclared;
            }
        }
    }
    return undeclared;
}


void insert_symbol_arg(HASH_NODE* foo_symbol, HASH_NODE* new_parameter){ //inserts the symbol in the end of the foo_args list

    ARGS* newArg = (ARGS*)calloc(1, sizeof(ARGS));
    newArg->arg = new_parameter;
    newArg->next = NULL;

    if (!foo_symbol->foo_args){
        foo_symbol->foo_args = newArg;
        return;
    }

    ARGS* arguments = foo_symbol->foo_args;
    while(arguments->next)
        arguments = arguments->next;

    arguments->next = newArg;
    
    return;
}


HASH_NODE* make_temp(){
    static int serial = 0;
    char buffer[256] = "";

    // NOTE: the goal here is to not colide with user defined identifiers
    // normally, the compiler does that by changing all user identifier names
    // from something like userVar to _userVar. This way it's possible to 
    // distinguish between user defined identifiers and compiler ones 
    sprintf(buffer, "mYWeeirT_emp%d", serial++);
    hashInsert(buffer, SYMBOL_VARIABLE);
}


HASH_NODE* make_label(){
    static int serial = 0;
    char buffer[256] = "";

    sprintf(buffer, "mYLabule_%d", serial++);
    hashInsert(buffer, SYMBOL_LABEL);
}


void print_asm(FILE *fout){

    fprintf(fout,   "\n## DATA SECTION\n"
                    ".data\n");

    HASH_NODE *node;
    for(int i=0; i<HASH_SIZE; i++){
        for(node=Hashtable[i]; node; node=node->next){
            
            switch (node->type)
            {
            case SYMBOL_VARIABLE:
                fprintf(fout, "_%s: .long\t0\n", node->text);
                break;
            
            case SYMBOL_VECTOR:
                fprintf(fout, "_%s: .zero\t400\n", node->text);
                break;

            case SYMBOL_LIT_INT:
                fprintf(fout, "_%s: .long\t%s\n", node->text, node->text);
                break;
            
            case SYMBOL_LIT_FLOAT:  //TODO: convert to assembly float
                fprintf(fout, "_%s: .long\t%s\n", node->text, node->text);
                break;
            
            case SYMBOL_LIT_CHAR:   //TODO: convert to assembly char
                fprintf(fout, "_%s: \t'%s'\n", node->text, node->text);
                break;
            
            case SYMBOL_LIT_STRING:
                fprintf(fout, "_%s: .string\t%s\n", node->text, node->text);
                break;

            default:
                break;
            }

        }
    }
    fprintf(fout, "_TRUE: .long\t1\n");
    fprintf(fout, "_FALSE: .long\t0\n");

    fprintf(fout,   ".section .rodata\n");
}
