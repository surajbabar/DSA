#include "../doubly-Linked-List/linkedList.h"
typedef struct TreeNode{
	void* data;
	List* next;
	struct Node* prev;
}TreeNode;
int isChild(void* data,void* parent);
int hasChild(void* parent);
