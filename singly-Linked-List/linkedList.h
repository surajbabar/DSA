
typedef struct Node{
        void* data;
        struct Node *next;
}Node;

typedef struct List{
        Node* header;
        int length;
}List;

List* createList();

int deleteNode(List* list , int index);
int insertNode(List* list , int index , void* data);

void insertMiddle(List* list , int index ,Node* node );

void deleteFirst(List* list);
void deleteLast(List* list);
void deleteMiddle(List* list , int index);
void Free(List* list);