#include "../doubly-Linked-List/doublyLinkedList.h"

typedef struct TreeNode{
	void* data;
	DList* next;
	struct Node* prev;
}TreeNode;
int isChild(void* data,void* parent);
int hasChild(void* parent);
TreeNode* createTreeNode(void* data,TreeNode* parent);
TreeNode* getTreeNode(DList* tree,void* nodeData,compareFPtr compare);
