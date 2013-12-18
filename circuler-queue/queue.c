#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Queue* create (int typeSize, int length){
	Queue* queue = calloc(1,sizeof(Queue));
	queue->elements=calloc(length,typeSize); 
 	queue->typeSize=typeSize;
 	queue->length=length;
	queue->front=-1;
	queue->rear=-1;
	return queue;
};

int isEmpty(Queue* queue){  
	return -2 == queue->rear+queue->front;
};

int isFull(Queue* queue){
	return (queue->rear==queue->length-1 && queue->front==-1 )||queue->front-queue->rear==1;
};

void* top(Queue* queue){
	if(isEmpty(queue)) return NULL;	
	return queue->elements+(queue->rear*queue->typeSize); 
};

int enqueue(Queue* queue, void* element){
	if(isFull(queue)) return 0;
		if(queue->rear==queue->length-1) queue->rear=-1;
	memcpy(queue->elements+(++queue->rear*queue->typeSize),element,queue->typeSize);
	return 1;
};

void* dequeue(Queue* queue){
	if(isEmpty(queue)) return NULL;	
	queue->front++;
	return queue->elements;
};