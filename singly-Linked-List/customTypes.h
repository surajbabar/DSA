#ifndef SinglyLinkedList
#define SinglyLinkedList
typedef struct Node{
        void* data;
        struct Node *next;
}Node;
#endif

void insertMiddle(void* list , int index ,Node* node );

void deleteFirst(void* list);
void deleteLast(void* list);
void deleteMiddle(void* list , int index);
typedef char string[50];
