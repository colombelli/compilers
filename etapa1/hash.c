#include "hash.h"

HASH_NODE *Hashtable[HASH_SIZE];


void hashInit(void) {
    for (int i=0; i<HASH_SIZE; i++){
        Hashtable[i]=0;
    } 
}


int hashAddress(char *text){

    int newAddress = 1;
    for (int i=0; i<strlen(text); i++){
        newAddress = ((newAddress * text[i]) % HASH_SIZE)+1;
    }
    return newAddress-1;
}


HASH_NODE *hashFind(char *text){
    return 0; // TODO
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
            printf("Hashtable %d : %s\n", i, node->text);
        }
    }
    printf("\n---- End of Hashtable ----\n\n");
}