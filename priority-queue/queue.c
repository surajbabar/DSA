#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
Queue* createQueue(){
        Queue* queue =calloc(1, sizeof(queue));
    queue->header = NULL;
    queue->length = 0;
    return queue; 
};
Node* createNode(int priority, void* data){
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->priority = priority;
    return node;
};
int isEmpty(Queue* queue){  
        return NULL== queue->header;
};

void* rear(Queue* queue){
        Node* node = queue->header;
        if(isEmpty(queue)) return NULL;
        while(node->next != NULL) node = node->next;
        return node->data; 
};

int enqueue(Queue* queue, Node* node){
    Node *back,*temp = queue->header;
    if(isEmpty(queue) ||node->priority >= queue->header->priority){
        node->next=queue->header;  
        queue->header=node;
    } 
     else{   
        while(node->priority < temp->priority && temp->next!=NULL){
            back=temp;
            temp = temp->next;
        }
        node->next=temp;
        back->next = node;
    }
    queue->length++;
    return 1; 
};

Node* dequeue(Queue* queue){
    Node* poppedElement = queue->header;  
    if(isEmpty(queue)) return NULL; 
    queue->header = queue->header->next;
    queue->length--;
    return poppedElement;
};