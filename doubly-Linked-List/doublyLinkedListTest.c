#include "testUtils.h"
#include "linkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int isHeader(List* list){
        return (list->header->next ==NULL && list->header->prev == NULL);
}

int compareInt(void *element1,void *element2){
        return *(int*)element1 - *(int*)element2;
}
void test_insert_node_will_not_add_node_at_index_which_does_not_exist(){
        List* list = createList();
        int data1 = 10,data2= 20;
        Node* node = calloc(1,sizeof(node));
        ASSERT(insertNode(list,0,&data1));
        ASSERT(0 == insertNode(list,4,&data2));
        ASSERT(1 == list->length);
        ASSERT(*(int*)list->header->data == 10);
}
void test_insert_node_with_int_data_at_starting_of_linked_list(){
        List* list = createList();
        int data = 10;
        ASSERT(insertNode(list,0,&data));
        ASSERT(1 == list->length);
        ASSERT(*(int*)list->header->data == 10);
        ASSERT(isHeader(list));
}
void test_insert_node_with_string_data_at_starting_of_linked_list(){
        List* list = createList();
        string data = "data";
        ASSERT(insertNode(list,0,&data));
        ASSERT(1 == list->length);
        ASSERT(0 == strcmp(*(string*)list->header->data , "data"));
        ASSERT(isHeader(list));
}
void test_insert_node_with_Float_data_at_starting_of_linked_list(){
        List* list = createList();
        float data = 1.5f;
        ASSERT(insertNode(list,0,&data));
        ASSERT(1 == list->length);
        ASSERT(*(float*)list->header->data == 1.5f);
        ASSERT(isHeader(list));
}
void test_insert_node_with_char_data_at_starting_of_linked_list(){
        List* list = createList();
        char data = 'k';
        ASSERT(insertNode(list,0,&data));
        ASSERT(1 == list->length);
        ASSERT(*(char*)list->header->data == 'k');
        ASSERT(isHeader(list));
}
void test_insert_node_with_int_data_at_end_of_linked_list(){
        List* list = createList();
        int data1 = 10,data2= 20;
        Node* node = calloc(1,sizeof(node));
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        ASSERT(2 == list->length);
        ASSERT(*(int*)list->header->data == 10);
        node = list->header;
        ASSERT(*(int*)(node->next->data) == 20);
}
void test_insert_node_with_float_data_at_end_of_linked_list(){
        List* list = createList();
        float data1 = 10.5f,data2= 20.5f;
        Node* node = calloc(1,sizeof(node));
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        ASSERT(2 == list->length);
        ASSERT(*(float*)list->header->data == 10.5f);
        node = list->header;
        ASSERT(*(float*)(node->next->data) == 20.5f);
}
void test_insert_node_with_string_data_at_end_of_linked_list(){
        List* list = createList();
        string data1 = "data1",data2 = "data2";
        Node* node = calloc(1,sizeof(node));
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        ASSERT(2 == list->length);
        ASSERT(0 == strcmp(*(string*)list->header->data , "data1"));
        node = list->header;
        ASSERT(0 == strcmp(*(string*)(node->next->data) , "data2"));
}
void test_insert_node_with_char_data_at_end_of_linked_list(){
        List* list = createList();
        char data1 = 'k',data2 = 'j';
        Node* node = calloc(1,sizeof(node));
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        ASSERT(2 == list->length);
        ASSERT(*(char*)list->header->data = 'k');
        node = list->header;
        ASSERT(*(char*)(node->next->data) = 'j');
}
void test_insert_node_with_int_data_at_middle_of_linked_list(){
        List* list = createList();
        int data1 = 10,data2= 20,data3=30;
        Node* node = calloc(1,sizeof(node));
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        insertNode(list,1,&data3);
        ASSERT(3 == list->length);
        ASSERT(*(int*)list->header->data == 10);
        node = (list->header)->next;
        ASSERT(*(int*)(node->data) == 30);
        node = node->next;
        ASSERT(*(int*)(node->data) == 20);
}
void test_insert_node_with_float_data_at_middle_of_linked_list(){
        List* list = createList();
        float data1 = 10.5f,data2= 20.5f,data3=30.5f;
        Node* node = calloc(1,sizeof(node));
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        insertNode(list,1,&data3);
        ASSERT(3 == list->length);
        ASSERT(*(float*)list->header->data == 10.5f);
        node = (list->header)->next;
        ASSERT(*(float*)(node->data) == 30.5f);
        node = node->next;
        ASSERT(*(float*)(node->data) == 20.5f);
}
void test_insert_node_with_double_data_at_middle_of_linked_list(){
        List* list = createList();
        double data1 = 10.5,data2= 20.5,data3=30.5;
        Node* node = calloc(1,sizeof(node));
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        insertNode(list,1,&data3);
        ASSERT(3 == list->length);
        ASSERT(*(double*)list->header->data == 10.5);
        node = (list->header)->next;
        ASSERT(*(double*)(node->data) == 30.5);
        node = node->next;
        ASSERT(*(double*)(node->data) == 20.5);
}
void test_insert_node_with_string_data_at_middle_of_linked_list(){
        List* list = createList();
        string data1 = "data1",data2 = "data2",data3 = "data3";
        Node* node = calloc(1,sizeof(node));
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        insertNode(list,1,&data3);
        ASSERT(3 == list->length);
        ASSERT(0 == strcmp(*(string*)list->header->data , "data1"));
        node = (list->header)->next;
        ASSERT(0 == strcmp(*(string*)(node->data) , "data3"));
        node = node->next;
        ASSERT(0 == strcmp(*(string*)(node->data) , "data2"));
}
void test_insert_node_with_int_data_at_middle_of_linked_list1(){
        List* list = createList();
        int data1 = 10,data2= 20,data3=30,data4=40;
        Node* node = calloc(1,sizeof(node));
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        insertNode(list,2,&data3);
        insertNode(list,2,&data4);
        ASSERT(4 == list->length);
        ASSERT(*(int*)list->header->data == 10);
        node = (list->header)->next;
        ASSERT(*(int*)(node->data) == 20);
        node = node->next;
        ASSERT(*(int*)(node->data) == 40);
        node = node->next;
        ASSERT(*(int*)(node->data) == 30);
}

void test_insert_node_with_int_data_at_start_of_linked_list(){
        List* list = createList();
        int data1 = 10,data2= 20,data3=30;
        Node* node = calloc(1,sizeof(node));
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        insertNode(list,0,&data3);
        ASSERT(3 == list->length);
        ASSERT(*(int*)list->header->data == 30);
        node = (list->header)->next;
        ASSERT(*(int*)(node->data) == 10);
        node = node->next;
        ASSERT(*(int*)(node->data) == 20);
}
void test_delete_node_with_int_data_at_starting_of_linked_list_which_length_is_1(){
        List* list = createList();
        int data = 10;
        insertNode(list,0,&data);
        ASSERT(1 == list->length);
        ASSERT(*(int*)list->header->data == 10);
        deleteNode(list,0);
        ASSERT(list->header == NULL);
        ASSERT(0 == list->length);
}
void test_delete_node_with_index_that_not_exist_return_false(){
        List* list = createList();
        int data = 10;
        insertNode(list,0,&data);
        ASSERT(1 == list->length);
        ASSERT(0 == deleteNode(list,2));
}
void test_delete_node_with_float_data_at_starting_of_linked_list_which_length_is_1(){
        List* list = createList();
        float data = 10.5f;
        insertNode(list,0,&data);
        ASSERT(1 == list->length);
        ASSERT(*(float*)list->header->data == 10.5f);
        deleteNode(list,0);
        ASSERT(list->header == NULL);
        ASSERT(0 == list->length);
}
void test_delete_node_with_double_data_at_starting_of_linked_list_which_length_is_1(){
        List* list = createList();
        double data = 10.555;
        insertNode(list,0,&data);
        ASSERT(1 == list->length);
        ASSERT(*(double*)list->header->data == 10.555);
        deleteNode(list,0);
        ASSERT(list->header == NULL);
        ASSERT(0 == list->length);
}
void test_delete_node_with_string_data_at_starting_of_linked_list_which_length_is_1(){
        List* list = createList();
        string data ="data";
        insertNode(list,0,&data);
        ASSERT(1 == list->length);
        ASSERT(0 == strcmp(*(string*)list->header->data , "data"));
        deleteNode(list,0);
        ASSERT(list->header == NULL);
        ASSERT(0 == list->length);
}
void test_delete_node_with_int_data_at_end_of_linked_list_which_length_is(){
        List* list = createList();
        Node* node;
        int data1 = 10 , data2 = 20 , data3 = 30;
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        insertNode(list,1,&data3);
        ASSERT(3 == list->length);
        deleteNode(list,2);
        ASSERT(*(int*)list->header->data == 10);
        node = list->header->next;
        ASSERT(*(int*)node->data == 30);
        node = node->next;
        ASSERT(2 == list->length);
}
void test_delete_node_with_float_data_at_end_of_linked_list_which_length_is(){
        List* list = createList();
        Node* node;
        int data1 = 10 , data2 = 20 , data3 = 30;
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        insertNode(list,2,&data3);
        ASSERT(3 == list->length);
        deleteNode(list,2);
        ASSERT(*(int*)list->header->data == 10);
        node = list->header->next;
        ASSERT(*(int*)node->data == 20);
        node = node->next;
        ASSERT(2 == list->length);
}
void test_delete_node_with_int_data_at_middle_of_linked_list(){
        List* list = createList();
        int data1 = 10,data2= 20,data3=30,data4=40;
        Node* node = calloc(1,sizeof(node));
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        insertNode(list,2,&data3);
        insertNode(list,3,&data4);
        ASSERT(4 == list->length);
        deleteNode(list, 1);
        ASSERT(*(int*)list->header->data == 10);
        node = (list->header)->next;
        ASSERT(*(int*)(node->data) == 30);
        node = node->next;
        ASSERT(*(int*)(node->data) == 40);
        ASSERT(3 == list->length);
}       
void test_delete_node_with_float_data_at_middle_of_linked_list(){
        List* list = createList();
        float data1 = 10.5f,data2= 20.5f,data3=30.5f;
        Node* node = calloc(1,sizeof(node));
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        insertNode(list,2,&data3);
        ASSERT(3 == list->length);
        deleteNode(list, 1);
        ASSERT(*(float*)list->header->data == 10.5f);
        node = (list->header)->next;
        ASSERT(*(float*)(node->data) == 30.5f);
        ASSERT(2 == list->length);
}
void test_delete_node_with_string_data_at_middle_of_linked_list(){
        List* list = createList();
        string data1 = "data1",data2 = "data2",data3 = "data3";
        Node* node = calloc(1,sizeof(node));
        insertNode(list,0,&data1);
        insertNode(list,1,&data2);
        insertNode(list,1,&data3);
        ASSERT(3 == list->length);
        deleteNode(list, 1);
        ASSERT(0 == strcmp(*(string*)list->header->data , "data1"));
        node = (list->header)->next;
        ASSERT(0 == strcmp(*(string*)(node->data) , "data2"));
}


void test_hasnext_of_getiterator_gives_true_if_list_not_empty(){
        List* dList = createList();
        Iterator it;
        int number1 = 5,number2 = 9,number3 = 65;
        insertNode(dList, 0, &number1);
        it = getIterator(dList);
        ASSERT(1 == it.hasNext(&it));
};
void test_hasnext_of_getiterator_gives_false_if_list_not_empty(){
        List* dList = createList();
        Iterator it;
        it = getIterator(dList);
        ASSERT(0 == it.hasNext(&it));
}
void test_next_of_getiterator_gives_next_data(){
        List* dList = createList();
        Iterator it;
        int number1 = 5;
        insertNode(dList, 0, &number1);
        it = getIterator(dList);
        if(it.hasNext(&it))
        ASSERT(5 == *(int*)it.next(&it));
}
void test_should_give_all_values_using_iterator(){
        List* dList = createList();
        Iterator it;
        int i = 0;
        int numbers[] = {5,10,15,20};
        insertNode(dList, 0, numbers);
        insertNode(dList, 1, &numbers[1]);
        insertNode(dList, 2, &numbers[2]);
        insertNode(dList, 3, &numbers[3]);
        it = getIterator(dList);
        while(i++ <4)  ASSERT(numbers[i-1] == *(int*)it.next(&it));
}