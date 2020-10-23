#include "stack.h"

STACK_NODE* push_node(STACK_NODE* head, HASH_NODE* symbol){ 
    STACK_NODE* newNode = (STACK_NODE*) calloc(1, sizeof(STACK_NODE));
    newNode->symbol =  symbol;
    newNode->next = head; 
    head = newNode; 
    return head;
} 
  

STACK_NODE* pop_node(STACK_NODE* head){ 
    if (head == NULL) 
        return NULL; 
    
    STACK_NODE* temp = head; 
    head = head->next;
    temp->symbol = NULL;  //i don't know if i need to, but it's better to prevent it from being freed
    free(temp); 
    return head; 
} 
  

void pop_all_nodes(STACK_NODE* head){

    while (head != NULL){
        head->symbol->type = SYMBOL_OUT_OF_SCOPE;
        head = pop_node(head);
    } 
    return;
}
  
