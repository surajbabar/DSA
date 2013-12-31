#include "stack.h"
#include <stdlib.h>

Stack* createStack(){
      return DList_create(); 
};
int push(Stack* stack,void* element){
        return DList_insertData(stack , stack->length, element);
};
void* pop(Stack* stack){
        void* data = top(stack);
        DList_deleteData(stack, stack->length-1);
        return data;
};
void* top(Stack* stack){
        return DList_getData(stack,stack->length);
};