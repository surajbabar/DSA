#include "../doubly-Linked-List/doublyLinkedList.h"
#include "treeIterator.h"
 typedef int (*compareFPtr)(void* first, void* second);
typedef struct {
        compareFPtr compare;
        void* root;
} Tree;

typedef struct treeNode{
        void* data;
        DList* children;
        struct treeNode* parent;
} TreeNode;

Tree createTree(compareFPtr compare);
int insert(Tree* tree, void* parentData, void* data);
Iterator getChildren(Tree* tree, void* parentData);
int search(Tree* tree, void* data);
int deleteTreeNode(Tree* tree, void* data);
void deleteTree(Tree* tree);