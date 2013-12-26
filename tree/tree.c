#include "tree.h"
#include <stdlib.h>

Tree createTree(compare cmp){
    Tree tree = {cmp,NULL}; 
    return tree;
};

TreeNode* createTreeNode(void* data,TreeNode* parent){
    TreeNode* newNode = malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->parent = parent;
    newNode->children = createList();
    return newNode;
};

TreeNode* getTreeNode(List* tree,void *dataToFind,compare cmp){
    Iterator it = getIterator(tree);
    TreeNode *tn;
    while(it.hasNext(&it)){
        tn = (TreeNode*)it.next(&it);
        if(0 == cmp(tn->data,dataToFind))  return tn;
        if(tn->children->header)
            getTreeNode(tn->children, dataToFind, cmp);
    }
    return NULL;
};

int insert(Tree* tree, void* parentData, void* data) {
    TreeNode *parent,*root = (TreeNode*)tree->root;
    if(NULL == tree->root){
        tree->root = createTreeNode(data, NULL);
        return 1;
    }
    if(0 == tree->compare(root->data,parentData)){
        insertNode(root->children, 0,createTreeNode(data,root));
        return 1;
    }
    parent = getTreeNode(root->children, parentData, tree->compare);
    insertNode(parent->children, 0, createTreeNode(data, parent));
    return 1;
};

int deleteTreeNode(Tree* tree, void* data){
    TreeNode *root = (TreeNode*)tree->root;
    TreeNode *tn,*parent;
    Iterator it;
    List * list = (List*)root->children;
    tn = getTreeNode(list, data, tree->compare);
    if(0 == tn->children->length){
        parent = tn->parent;
        it = getIterator(parent->children);
        while(it.hasNext(&it)){
            if(tree->compare(data,it.next(&it)))
                break;
        }
        deleteNode(parent->children, it.position - 1);
        return 1;
    }
    return 0;
};

void deleteTree(Tree* tree){
   free(tree->root);
};
void* treeNext(Iterator *it){
    TreeNode *node;
    Iterator tree = getIterator(it->list);
    tree.position = it->position;
    node = tree.next(&tree);
    it->position++;
    return node->data;
};

Iterator getChildren(Tree* tree, void* parent) {
    TreeNode *temp,*root = (TreeNode*)tree->root;
    Iterator it;
    if(0 == tree->compare(root->data,parent))
        temp = root;
    else 
        temp = getTreeNode(root->children, parent, tree->compare);
    it = getIterator(temp->children);
    it.next = &treeNext;
    return it;
};
int search(Tree* tree, void* data){
    TreeNode* root = (TreeNode*)(tree->root);
    if(0 == tree->compare(data,root->data))
        return 1;
    if(NULL != getTreeNode(root->children,data,tree->compare))
        return 1;
    return 0;
}