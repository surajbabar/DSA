#include "../doubly-Linked-List/doublyLinkedList.h"

typedef  DList Stack;

Stack* createStack();
int push(Stack* stack,void* element);
void* pop(Stack* stack);
void* top(Stack* stack);