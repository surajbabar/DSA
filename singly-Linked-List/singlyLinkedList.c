#include "singlyLinkedList.h"
#include "customtypes.h"
#include <stdlib.h>

SinglyList* SList_create(){
    return calloc(1, sizeof(SinglyList)); 
};

void SList_dispose(SinglyList* list){
    while(list->length>0)
        SList_deleteNode(list,0);
};

int SList_insertNode(SinglyList* list , int index , void* data){
    Node* node = calloc(1,sizeof(Node));
    if (index > list->length) return 0;
    if (index == 0){
        node->next = list->header;
        list->header = node;          
    }
    else if(index == list->length){
        Node* temp = list->header;
        while(temp->next!=NULL) temp =temp->next;
        temp->next =node;
        node->next = NULL;
    } 
    else insertMiddle(list, index, node);
    node->data = data;
    list->length++;
    return 1;
};

int SList_deleteNode(SinglyList* list , int index){
    if(index >= list->length) return 0;
    if(index == 0) deleteFirst(list);
    else if(index == list->length-1)  deleteLast(list);
    else deleteMiddle( list , index);
    list->length--;
    return 1;
};

Iterator SList_iterator(SinglyList* list){
    Iterator it;
    return it;
};

void insertMiddle(void* listAddress , int index ,Node* node ){
    SinglyList* list =(SinglyList*)listAddress;
    Node* temp;
    int i=0;
    temp = list->header;
    while(i++ < index-1) temp =temp->next ;
    node->next=temp->next;
    temp->next =node;
};

void deleteFirst(void* listAddress){
    SinglyList* list =(SinglyList*)listAddress;
    void* first = list->header;
    if(first == NULL) return;
    list->header = list->header->next;
    free(first);
};

void deleteLast(void* listAddress){
    SinglyList* list =(SinglyList*)listAddress;
    Node *last = list->header , *pre;
    while(last->next!=NULL){
            pre = last;
            last = last->next;
    }
    pre->next = NULL;
    free(last);
};

void deleteMiddle(void* listAddress , int index){
    SinglyList* list =(SinglyList*)listAddress;
    int i=0;
    Node *temp = list->header , *middle;
    while(i++ < index-1) temp = temp->next ;
    middle = temp->next;
    temp->next = middle->next;
    free(middle);
};