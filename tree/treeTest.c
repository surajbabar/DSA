#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
int compareInts(void *a,void *b){
    return *(int*)a - *(int*)b;
};
void test_insert_root_node(){
    Tree tree = createTree(compareInts);
    int data = 2;
    int result = insert(&tree, NULL, &data);
    ASSERT(1 == result);
    deleteTree(&tree);
};
void test_insert_node_under_root_node(){
    Tree tree = createTree(compareInts);
    int data[] = {2,3,5};
    Iterator result;
    insert(&tree, NULL, &data[0]);
    insert(&tree, &data[0], &data[1]);
    insert(&tree, &data[0], &data[2]);
    result = getChildren(&tree, &data);
    ASSERT(5 == *(int*)result.next(&result));
    ASSERT(3 == *(int*)result.next(&result));
    deleteTree(&tree);
};
void test_insert_under_child_node(){
    Tree tree = createTree(compareInts);
    int data[] = {2,3,5};
    Iterator result;
    insert(&tree, NULL, &data[0]);
    insert(&tree, &data[0], &data[1]);
    insert(&tree, &data[1], &data[2]);
    result = getChildren(&tree, &data[1]);
    ASSERT(5 == *(int*)result.next(&result));
    deleteTree(&tree);

};
void test_insert_under_second_child(){
    Tree tree = createTree(compareInts);
    int data0 = 2;
    int data1[] = {3,5};
    int data2 = 9;
    Iterator result;
    insert(&tree, NULL, &data0);
    insert(&tree, &data0, &data1[0]);
    insert(&tree, &data0, &data1[1]);
    insert(&tree, &data1[1], &data2);
    result = getChildren(&tree, &data1[1]);
    ASSERT(9 == *(int*)result.next(&result));
    deleteTree(&tree);
};
void test_delete_node_under_root_node_from_tree(){
    Tree tree = createTree(compareInts);
    Iterator result;
    int data[2] = {10,23};
    ASSERT(insert(&tree, NULL, &data));
    ASSERT(insert(&tree, &data, &data[1]));
    ASSERT(deleteTreeNode(&tree,&data[1]));
    result = getChildren(&tree, &data);
    ASSERT(0 == result.hasNext(&result));
}
void test_delete_root_node_from_tree(){
    Tree tree = createTree(compareInts);
    Iterator result;
    int data[2] = {10,23};
    ASSERT(insert(&tree, NULL, &data));
}