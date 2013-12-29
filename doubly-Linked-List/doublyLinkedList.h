typedef char string[50];
#include "../iterator/iterator.h"
typedef struct Node{
        void* data;
        struct Node *next;
        struct Node *prev;
}Node;

typedef struct List{
        Node* header;
        int length;
}List;

typedef int (*compare)(void *elementToCompare,void *element);
List* createList();
int insertNode(List* list , int index , void* data);
int deleteNode(List* list , int index);

void insertFirst(List* list,Node* node );
void insertMiddle(List* list , int index ,Node* node );
void insertLast(List* list,Node* node );
void sort(List* dList, compare cmpFunc);
void deleteFirst(List* list);
void deleteLast(List* list);
void deleteMiddle(List* list , int index);
Iterator getIterator(List *list);