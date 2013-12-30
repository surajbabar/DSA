#include "doublyLinkedList.h"
#include <stdlib.h>
#include "customTypes.h"
DList* DList_create(){
    DList* list =calloc(1, sizeof(DList));
    list->header = NULL;
    return list; 
};

void DList_dispose(DList* list){
    while(list->length>0)
    DList_deleteNode(list,0);
};

void insertFirst(void* listaddress,Node* node ){
    DList* list =listaddress;
    node->next = list->header;
    list->header = node;
    node->prev = NULL;
};

void insertLast(void* listaddress,Node* node ){
    DList* list =listaddress;
    Node* temp = calloc(1, sizeof(Node*));
    temp = list->header;
    while(NULL!=temp->next)  temp =temp->next;
    node->prev=temp;
    temp->next =node;
    node->next = NULL;
};

void insertMiddle(void* listaddress , int index ,Node* node ){
    DList* list =listaddress;
    Node* temp= list->header;
    int i=0;
    while(i++ < index-1) temp =temp->next ;
    node->prev=temp;
    node->next=temp->next;
    temp->next =node;
    (node->next)->prev =node;
};

int DList_insertNode(DList* list , int index , void* data){
    Node* node = calloc(1,sizeof(node));
    if (index > list->length) return 0;
    if (index == 0)   insertFirst(list,node);
    else if(index == list->length)   insertLast(list,node);
    else insertMiddle(list, index, node);
    node->data = data;
    list->length++;
    return 1;
};
int DList_getIndex(DList* list, void* data,compareFPtr compare){
    int i=0;
    Node *node,*head = list->header;
    if(head == NULL) return -1;
    if(compare(data,head->data)==0) return 0;
    node=head;
    while(node->next !=NULL){
        node= node->next;
        i++;
        if(compare(data,node->data) == 0) return i;
    }
    return -1;       
}; 

void DList_sort(DList* list, compareFPtr compare){
    Node *temp,*node,*currentNode,*head =list->header;
    void *data;
    int change = 0;
    if(head == NULL) return;
    for (node = head->next; node != NULL; node = node->next){
        data = node->data;
        change = 0;
        for(temp = node->prev;temp != NULL;temp = temp->prev){
            currentNode = temp;
            if(compare(data,temp->data) < 0){
                change++;
                temp->next->data = temp->data;
            }
            else break;
        }
        if(change)
            currentNode->data = data;
    }
};
void deleteFirst(void* listAddress){
    DList* list =listAddress;    
    Node* node =list->header,*head =node;
    if(list->length == 1) list->header = NULL;
    else {
        list->header = head->next;
        head->prev = NULL;
    };
    free(node);
};

void deleteLast(void* listAddress){
    DList* list =listAddress;    
    Node* temp =list->header;
    while(NULL!=temp->next) temp =temp->next;
    temp->prev->next = NULL;
    free(temp);
};

void deleteMiddle(void* listAddress, int index){
    DList* list =listAddress;    
    Node* temp= list->header;
    int i=0;
    while(i++ < index) temp =temp->next ;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
};

int DList_deleteNode(DList* list , int index){
    if(index >= list->length) return 0;
    if(index == 0) deleteFirst(list);
    else if(index == list->length-1)  deleteLast(list);
    else deleteMiddle( list , index);
    list->length--;
    return 1;
};

int hasNextForList(Iterator *it){
    DList* list =it->list;
    if(it->position == list->length)  return 0;
    return 1;
};

void* nextForList(Iterator *it){
    int i = 0;
    DList* dList = it->list;
    Node* temp = dList->header;
    if(0 == hasNextForList(it)) return NULL;
    for(i = 0;i < it->position;i++)
        temp = temp->next;
    it->position++;
    return temp->data;
};

Iterator DList_getIterator(DList* list){
    Iterator listIterator;
    listIterator.position = 0;
    listIterator.list = list;
    listIterator.hasNext = &hasNextForList;
    listIterator.next = &nextForList;
    return listIterator;
};