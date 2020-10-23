#include "stack.h"


STACK_NODE* push(STACK_NODE* head, HASH_NODE* symbol){ 
    STACK_NODE* newNode = (STACK_NODE*) calloc(1, sizeof(STACK_NODE));
    newNode->symbol =  symbol;
    newNode->next = head; 
    head = newNode; 
    return head;
} 
  

STACK_NODE* pop(STACK_NODE* head){ 
    if (head == NULL) 
        return; 
    STACK_NODE* temp = head; 
    head = head->next;
    temp->symbol = NULL;  //i don't know if i need to, but it's better to prevent it from being freed
    free(temp); 
    return head; 
} 
  

void pop_all_function_ended(STACK_NODE* head){

    while (head != NULL){
        head->symbol->datatype = SYMBOL_IDENTIFIER;
        head = pop(head);
    } 
    return;
}
  
