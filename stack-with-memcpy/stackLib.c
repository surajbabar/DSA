#include "stackLib.h"
#include <stdlib.h>
#include <string.h>

stack* create (int typeSize, int length){
    stack* Stack = calloc(1,sizeof(stack));
    Stack->elements=calloc(length,typeSize);
    Stack->typeSize=typeSize;
    Stack->length=length;
    Stack->top=-1;
    return Stack;
};

int isEmpty(stack* Stack){
  return (-1 == Stack->top);
};

void isFull(stack* Stack){
    if(Stack->top>=(Stack->length-1)){ 
        Stack->length*=2;
        Stack->elements =realloc(Stack->elements,Stack->length*Stack->typeSize);
    }    
};

void* top(stack* Stack){
    if(isEmpty(Stack)) return NULL;        
    return (Stack->elements+(Stack->top*Stack->typeSize));
};

int push(stack* Stack, void* element){
    isFull(Stack);
    memcpy(Stack->elements+(++Stack->top*Stack->typeSize),element,Stack->typeSize);
    return 1;
};

void* pop(stack* Stack){
    if(isEmpty(Stack)) return NULL;        
    Stack->top --;
    return Stack->elements+((Stack->top+1)*Stack->typeSize);
};