typedef struct Node{
        void* data;
        struct Node *next;
        struct Node *prev;
}Node;

void insertFirst(void* list,Node* node );
void insertMiddle(void* list , int index ,Node* node );
void insertLast(void* list,Node* node );
void deleteFirst(void* list);
void deleteLast(void* list);
void deleteMiddle(void* list , int index);
