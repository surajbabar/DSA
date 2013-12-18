#include "stack.h"
#include <stdlib.h>

Stack* createStack(){
      return createList(); 
};
int push(Stack* stack,void* element){
        return insertNode(stack , stack->length, element);
};
void* pop(Stack* stack){
        void* data = top(stack);
        deleteNode(stack, stack->length-1);
        return data;
};
void* top(Stack* stack){
        Node* node = stack->header;
        while(node->next != NULL) node = node->next;
        return node->data; 
};