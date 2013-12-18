#include "linkedList.h"
#include <stdlib.h>
#include <string.h>
List* createList(){
    List* list =calloc(1, sizeof(List));
    list->header = NULL;
    return list; 
};

void insertFirst(List* list,Node* node ){
    node->next = list->header;
    list->header = node;
    node->prev = NULL;
};

void insertLast(List* list,Node* node ){
    Node* temp = calloc(1, sizeof(Node*));
    temp = list->header;
    while(NULL!=temp->next)  temp =temp->next;
    node->prev=temp;
    temp->next =node;
    node->next = NULL;
};

void insertMiddle(List* list , int index ,Node* node ){
    Node* temp;
    int i=0;
    temp = list->header;
    while(i++ < index-1) temp =temp->next ;
    node->prev=temp;
    node->next=temp->next;
    temp->next =node;
    (node->next)->prev =node;
};

int insertNode(List* list , int index , void* data){
    int i=0;
    Node* node = calloc(1,sizeof(node));
    if (index > list->length) return 0;
    if (index == 0)   insertFirst(list,node);
    else if(index == list->length)   insertLast(list,node);
    else insertMiddle(list, index, node);
    node->data = data;
    list->length++;
    return 1;
};

void deleteFirst(List* list){
    Node* node = list->header;
    if(list->length == 1) list->header = NULL;
    else {
            list->header = list->header->next;
            list->header->prev = NULL;
    };

  
    free(node);
};

void deleteLast(List* list){
    Node* temp = calloc(1, sizeof(Node*));
    temp = list->header;
    while(NULL!=temp->next) temp =temp->next;
    temp->prev->next = NULL;
    free(temp);
};

void deleteMiddle(List* list , int index){
    Node* temp;
    int i=0;
    temp = list->header;
    while(i++ < index) temp =temp->next ;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
};

int deleteNode(List* list , int index){
    if(index >= list->length) return 0;
    if(index == 0) deleteFirst(list);
    else if(index == list->length-1)  deleteLast(list);
    else deleteMiddle( list , index);
    list->length--;
    return 1;
};