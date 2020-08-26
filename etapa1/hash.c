#include "hash.h"

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


HASH_NODE *hashInsert(char *text){
    int nodeAddress = hashAddress(text);

    HASH_NODE *newNode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
    newNode->type = 1;
    newNode->text = (char*) calloc(strlen(text) + 1, sizeof(char));
    strcpy(newNode->text, text);
    newNode->next = Hashtable[nodeAddress];

    Hashtable[nodeAddress] = newNode;
    return newNode;
}


void hashPrint(void){

    printf("\n---- Hashtable ----\n\n");

    HASH_NODE *node;
    for(int i=0; i<HASH_SIZE; i++){
        for(node=Hashtable[i]; node; node=node->next){
            printf("Address %d: %s\n", i, node->text);
        }
    }
    printf("\n---- End of Hashtable ----\n\n");
}