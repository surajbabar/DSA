#include "../iterator/iterator.h"
#ifndef SinglyLinkedList
#define SinglyLinkedList
typedef struct Node{
        void* data;
        struct Node *next;
}Node;

typedef struct{
        Node* header;
        int length;
}SinglyList;

SinglyList* SList_create();
void SList_dispose(SinglyList* list);

int SList_deleteNode(SinglyList* list , int index);
int SList_insertNode(SinglyList* list , int index , void* data);
Iterator SList_iterator(SinglyList* list); 
#endif