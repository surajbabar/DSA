#include "queue.h"

Queue* create (int typeSize, int length){
	Queue* queue = calloc(1,sizeof(Queue));
	queue->elements=calloc(length,typeSize); 
 	queue->typeSize=typeSize;
 	queue->length=length;
	queue->rear=-1;
	return queue;
};

int isEmpty(Queue* queue){  
	return -1 == queue->rear;
};

int isFull(Queue* queue){
	return queue->rear>=(queue->length-1);
};

void* rear(Queue* queue){
	if(isEmpty(queue)) return NULL;	
	return queue->elements+(queue->rear*queue->typeSize); 
};

int enqueue(Queue* queue, void* element){
	if(isFull(queue)) return 0;
	memcpy(queue->elements+(++queue->rear*queue->typeSize),element,queue->typeSize);
	return 1; 
};

void* dequeue(Queue* queue){
	void* poppedElement = malloc(queue->typeSize);	
	memcpy(poppedElement,queue->elements,queue->typeSize);
	if(isEmpty(queue)) return NULL;	
	memmove(queue->elements,queue->elements+queue->typeSize,queue->length-1);
	queue->rear--;
	return poppedElement;
};