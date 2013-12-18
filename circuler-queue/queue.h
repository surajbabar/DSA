typedef struct {
	int front;
	int rear;
	int typeSize;
	int length;
	void* elements;
}Queue;

Queue* create(int typeSize, int length);						

void* dequeue(Queue* queue);
void* top(Queue* queue);

int enqueue(Queue* queue ,void* element);
int isEmpty(Queue* queue); 
int isFull(Queue* queue); 
