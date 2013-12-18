typedef struct Node{
    void* data;
    int priority;
    struct Node *next;
}Node;

typedef struct{
        Node* header;
        int length;
	
}Queue;

Queue* createQueue();						
Node* createNode(int priority,void* data);
Node* dequeue(Queue* queue);
void* rear(Queue* queue);

int enqueue(Queue* queue ,Node* element);
int isEmpty(Queue* queue); 
int isFull(Queue* queue); 
