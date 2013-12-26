#include "../doubly-Linked-List/linkedList.h"
 typedef int (*compareFPtr)(void* first, void* second);
typedef struct {
        compareFPtr compare;
        void* root;
} Tree;

typedef struct treeNode{
        void* data;
        List* children;
        struct treeNode* parent;
} TreeNode;

Tree createTree(compareFPtr compare);
TreeNode* createTreeNode(void* data,TreeNode* parent);
int insertTreeNode(Tree* tree, void* parentData, void* data);
TreeNode* getTreeNode(List* tree,void* nodeData,compareFPtr compare);
Iterator getChildren(Tree* tree, void* parentData);
void* deleteTreeNode(Tree* tree, void* data);
