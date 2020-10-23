#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_SIZE 997

#define SYMBOL_LIT_INT 1
#define SYMBOL_LIT_FLOAT 2
#define SYMBOL_LIT_CHAR 3
#define SYMBOL_LIT_STRING 4
#define SYMBOL_LIT_TRUE 5
#define SYMBOL_LIT_FALSE 6
#define SYMBOL_IDENTIFIER 7
#define SYMBOL_VARIABLE 8
#define SYMBOL_FUNCTION 9
#define SYMBOL_VECTOR 10
#define SYMBOL_PARAMETER 11
#define SYMBOL_OUT_OF_SCOPE 12

#define DATATYPE_INT 1
#define DATATYPE_FLOAT 2
#define DATATYPE_CHAR 3
#define DATATYPE_BOOL 4


typedef struct hash_node {

    int type;
    char *text;
    int datatype;
    struct hash_node * next;

} HASH_NODE;


void hashInit(void);
int hashAddress(char *text);
HASH_NODE *hashFind(char *text);
HASH_NODE *hashInsert(char *text, int lexType);
void hashPrint(void);
int hash_check_undeclared(void);

#endif
// END