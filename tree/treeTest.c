#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
int compareInts(void *a,void *b){
    return *(int*)a - *(int*)b;
}
void test_insert_root_node(){
    Tree tree = createTree(compareInts);
    int data = 2;
    int result = insertTreeNode(&tree, NULL, &data);
    ASSERT(1 == result);
}
void test_insert_node_under_root_node(){
    Tree tree = createTree(compareInts);
    int data[] = {2,3,5};
    Iterator result;
    insertTreeNode(&tree, NULL, &data[0]);
    insertTreeNode(&tree, &data[0], &data[1]);
    insertTreeNode(&tree, &data[0], &data[2]);
    result = getChildren(&tree, &data);
    ASSERT(5 == *(int*)result.next(&result));
    ASSERT(3 == *(int*)result.next(&result));
}
void test_insert_under_child_node(){
    Tree tree = createTree(compareInts);
    int data[] = {2,3,5};
    Iterator result;
    insertTreeNode(&tree, NULL, &data[0]);
    insertTreeNode(&tree, &data[0], &data[1]);
    insertTreeNode(&tree, &data[1], &data[2]);
    result = getChildren(&tree, &data[1]);
    ASSERT(5 == *(int*)result.next(&result));
}
void test_insert_under_second_child(){
    Tree tree = createTree(compareInts);
    int data0 = 2;
    int data1[] = {3,5};
    int data2 = 9;
    Iterator result;
    insertTreeNode(&tree, NULL, &data0);
    insertTreeNode(&tree, &data0, &data1[0]);
    insertTreeNode(&tree, &data0, &data1[1]);
    insertTreeNode(&tree, &data1[1], &data2);
    result = getChildren(&tree, &data1[1]);
    ASSERT(9 == *(int*)result.next(&result));
}