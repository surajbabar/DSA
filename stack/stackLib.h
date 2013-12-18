typedef struct {
    void** elements;
    int top;
    int length;
} Stack;

Stack* create(int length);

void  push(Stack* stack,void* element);
void  dispose(Stack* stack);

void* pop(Stack* stack);
void* top(Stack* stack);