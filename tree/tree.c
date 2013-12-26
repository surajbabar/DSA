#include "tree.h"
#include <stdlib.h>

Tree createTree(compare cmp){
    Tree tree = {cmp,NULL}; 
    return tree;
};

TreeNode* createTreeNode(void *data,TreeNode *parent){
    TreeNode *treeNode = malloc(sizeof(TreeNode));
    treeNode->data = data;
    treeNode->parent = parent;
    treeNode->children = createList();
    return treeNode;
};

TreeNode* getTreeNode(List* tree,void *dataToFind,compare cmp){
    Iterator it = getIterator(tree);
    TreeNode *tn;
    while(it.hasNext(&it)){
        tn = (TreeNode*)it.next(&it);
        if(!cmp(tn->data,dataToFind))  return tn;
        if(tn->children->header)
            getTreeNode(tn->children, dataToFind, cmp);
    }
    return NULL;
};



int insertTreeNode(Tree* tree, void* parentData, void* data) {
    TreeNode *root = (TreeNode*)tree->root;
    TreeNode *nodeToInsert, *parentNode;
    if(NULL == tree->root){
        tree->root = createTreeNode(data, NULL);
        return 1;
    }
    if(0 == tree->compare(root->data,parentData)){
        parentNode = root;
        nodeToInsert = createTreeNode(data, parentNode);
        insertNode(root->children, 0, nodeToInsert);
        return 1;
    }
    parentNode = getTreeNode(root->children, parentData, tree->compare);
    nodeToInsert = createTreeNode(data, parentNode);
    insertNode(parentNode->children, 0, nodeToInsert);
    return 1;
};

void* deleteTreeNode(Tree* tree, void* data){
    TreeNode *root = (TreeNode*)tree->root;
    TreeNode* nodeToDelete;
    if(NULL == tree->root) return NULL;
    nodeToDelete = getTreeNode(root->children,data,tree->compare);
    if(NULL ==nodeToDelete) return NULL;
    nodeToDelete->parent

};

void* treeNext(Iterator *it){
    TreeNode *node;
    Iterator treeIterator = getIterator(it->list);
    treeIterator.position = it->position;
    node = treeIterator.next(&treeIterator);
    it->position++;
    return node->data;
};

Iterator getChildren(Tree* tree, void *parent) {
    TreeNode *temp,*root = (TreeNode*)tree->root;
    Iterator it;
    if(!tree->compare(root->data,parent))
        temp = root;
    else 
        temp = getTreeNode(root->children, parent, tree->compare);
    it = getIterator(temp->children);
    it.next = &treeNext;
    return it;
};