#include "hash.h"

HASH_NODE*Table[HASH_SIZE];


void hashInit(void) {
    int i;
    for (i=0; i<HASH_SIZE; ++i)
        Table[i]=0;
}


int hashAddress(char *text){

    int newAddress = 1;
    for (int i=0; i<strlen(text); ++i){
        newAddress = (newAddress * text[i]) % HASH_SIZE+1;
    }
    return newAddress;
}


HASH_NODE *hashFind(char *text){
    return 0; // TODO
}


HASH_NODE *hashInsert(char *text){
    HASH_NODE *newNode;
    int nodeAddress = hashAddress(text);

    newNode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
    newNode-> type = 1;
    newNode-> type = (char*) calloc(strlen(text) + 1, sizeof(char));
    strcpy(newNode->text, text);
    newNode->next = Table[nodeAddress];
    return newNode;
}


void hashPrint(void){
    HASH_NODE *node;
    for(int i=0; i<HASH_SIZE; ++i){
        for(node=Table[i]; node; node=node->next){
            printf("Hashtable %d : %s\n", i, node->text);
        }
    }
}