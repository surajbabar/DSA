#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int rear;
	int typeSize;
	int length;
	void* elements;
}Queue;

Queue* create(int typeSize, int length);						

void* dequeue(Queue* queue);
void* rear(Queue* queue);

int enqueue(Queue* queue ,void* element);
int isEmpty(Queue* queue); 
int isFull(Queue* queue); 
