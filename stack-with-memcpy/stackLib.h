typedef struct {
	int top;
	int typeSize;
	int length;
	void* elements;
}stack;

stack* create(int typeSize, int length);						

void* pop(stack* Stack);
void* top(stack* Stack);

int push(stack* Stack ,void* element);
int isEmpty(stack* Stack); 
void isFull(stack* Stack); 
