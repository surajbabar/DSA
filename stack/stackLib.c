#include "customTypes.h"
#include <stdlib.h>
#include <memory.h>

Stack* create(int length){
    Stack* stack = calloc(1,sizeof(Stack));
    stack->elements = calloc(length,sizeof(void*));
    stack->top = 0;
    stack->length = length;
    return stack;
};

void isFull(Stack* stack){
    if(stack->top>=(stack->length-1)){ 
        stack->length*=2;
        stack->elements =realloc(stack->elements,stack->length*sizeof(void*));
    }    
};
int isEmpty(Stack* stack){
    return stack->length == 0;
};

void push(Stack* stack,void* element){
    isFull(stack);
    *(stack->elements +stack->top*sizeof(void*))= element;
    stack->length++;
};

void* pop(Stack* stack){
    void* elementDeleted =*(stack->elements + stack->top*sizeof(void*));
    if(isEmpty(stack)) return NULL;
    stack->length--;
    return elementDeleted;
};

void* top(Stack* stack){
    if(isEmpty(stack)) return NULL;
    return *(stack->elements + stack->top*sizeof(void*));
};