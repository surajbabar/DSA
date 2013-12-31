#include "testUtils.h"
#include "doublyLinkedList.h"
#include <stdlib.h>
#include <string.h>
# define NOTFOUND -1
# define failure 0
# define success 1
typedef char string[50];

DList* list;
Iterator it;

int compareInt(void *element1,void *element2){
    return *(int*)element1 - *(int*)element2;
};
int compareChars(void* first,void* second){
    return *(char*)first - *(char*)second;
};
int compareFloats(void* first,void* second){
    return *(float*)first - *(float*)second;
};
int compareDoubles(void* first,void* second){
    return *(double*)first - *(double*)second;
};
int compareStrings(void* first,void* second){
    return strcmp(first,second);
};


void setup(){
    list = DList_create();
    it = DList_getIterator(list);
};

void tearDown(){
    DList_dispose(list);
};

void test_insert_node_with_int_data_at_starting_of_linked_list(){
    int data = 10,index=0;
    DList_insertData(list,index,&data);
    ASSERT(index == DList_getIndex(list,&data,compareInt));
    ASSERT(&data == DList_getData(list,index));
};

void test_insert_node_will_not_add_node_at_index_which_does_not_exist(){
    int data1 = 10,data2= 20,index=0;
    DList_insertData(list,index,&data1);
    ASSERT(failure == DList_insertData(list,4,&data2));
    ASSERT(0 == DList_getIndex(list,&data1,compareInt));
    ASSERT(NOTFOUND == DList_getIndex(list,&data2,compareInt));
    ASSERT(&data1 == DList_getData(list,index));

};

void test_insert_node_with_string_data_at_starting_of_linked_list(){
    string data = "data";
    DList_insertData(list,0,&data);
    ASSERT(0 == DList_getIndex(list,data,compareStrings));
};

void test_insert_node_with_Float_data_at_starting_of_linked_list(){
    float data = 1.5f;
    DList_insertData(list,0,&data);
    ASSERT(0 == DList_getIndex(list,&data,compareFloats));
};

void test_insert_node_with_char_data_at_starting_of_linked_list(){
    char data = 'k';
    DList_insertData(list,0,&data);
    ASSERT(0 == DList_getIndex(list,&data,compareChars));
};

void test_insert_node_with_int_data_at_end_of_linked_list(){
    int data1 = 10,data2= 20;
    DList_insertData(list,0,&data1);
    DList_insertData(list,1,&data2);
    ASSERT(0 == DList_getIndex(list,&data1,compareInt));
    ASSERT(1 == DList_getIndex(list,&data2,compareInt));
};

void test_insert_node_with_float_data_at_end_of_linked_list(){
    float data1 = 10.5f,data2= 20.5f;
    DList_insertData(list,0,&data1);
    DList_insertData(list,1,&data2);
    ASSERT(0 == DList_getIndex(list,&data1,compareFloats));
    ASSERT(1 == DList_getIndex(list,&data2,compareFloats));
};

void test_insert_node_with_string_data_at_end_of_linked_list(){
    string data1 = "data1",data2 = "data2";
    DList_insertData(list,0,&data1);
    DList_insertData(list,1,&data2);
    ASSERT(0 == DList_getIndex(list,&data1,compareStrings));
    ASSERT(1 == DList_getIndex(list,&data2,compareStrings));
};

void test_insert_node_with_char_data_at_end_of_linked_list(){
    char data1 = 'k',data2 = 'j';
    DList_insertData(list,0,&data1);
    DList_insertData(list,1,&data2);
    ASSERT(0 == DList_getIndex(list,&data1,compareChars));
    ASSERT(1 == DList_getIndex(list,&data2,compareChars));
};

void test_insert_node_with_int_data_at_middle_of_linked_list(){
    int data1 = 10,data2= 20,data3=30;
    DList_insertData(list,0,&data1);
    DList_insertData(list,1,&data2);
    DList_insertData(list,1,&data3);
    ASSERT(0 == DList_getIndex(list,&data1,compareInt));
    ASSERT(2 == DList_getIndex(list,&data2,compareInt));
    ASSERT(1 == DList_getIndex(list,&data3,compareInt));
};

void test_insert_node_with_float_data_at_middle_of_linked_list(){
    float data1 = 10.5f,data2= 20.5f,data3=30.5f;
    DList_insertData(list,0,&data1);
    DList_insertData(list,1,&data2);
    DList_insertData(list,1,&data3);
    ASSERT(0 == DList_getIndex(list,&data1,compareFloats));
    ASSERT(2 == DList_getIndex(list,&data2,compareFloats));
    ASSERT(1 == DList_getIndex(list,&data3,compareFloats));
};

void test_insert_node_with_double_data_at_middle_of_linked_list(){
    double data1 = 10.5,data2= 20.5,data3=30.5;
    DList_insertData(list,0,&data1);
    DList_insertData(list,1,&data2);
    DList_insertData(list,1,&data3);
    ASSERT(0 == DList_getIndex(list,&data1,compareDoubles));
    ASSERT(2 == DList_getIndex(list,&data2,compareDoubles));
    ASSERT(1 == DList_getIndex(list,&data3,compareDoubles));
};
void test_insert_node_with_string_data_at_middle_of_linked_list(){
    string data1 = "data1",data2 = "data2",data3 = "data3";
    DList_insertData(list,0,&data1);
    DList_insertData(list,1,&data2);
    DList_insertData(list,1,&data3);
    ASSERT(0 == DList_getIndex(list,&data1,compareStrings));
    ASSERT(2 == DList_getIndex(list,&data2,compareStrings));
    ASSERT(1 == DList_getIndex(list,&data3,compareStrings));
}
void test_insert_node_with_int_data_at_middle_of_linked_list1(){
    int data1 = 10,data2= 20,data3=30,data4=40;
    DList_insertData(list,0,&data1);
    DList_insertData(list,1,&data2);
    DList_insertData(list,2,&data3);
    DList_insertData(list,2,&data4);
    ASSERT(0 == DList_getIndex(list,&data1,compareInt));
    ASSERT(1 == DList_getIndex(list,&data2,compareInt));
    ASSERT(3 == DList_getIndex(list,&data3,compareInt));
    ASSERT(2 == DList_getIndex(list,&data4,compareInt));
};

void test_insert_node_with_int_data_at_start_of_linked_list(){
    int data1 = 10,data2= 20,data3=30;
    DList_insertData(list,0,&data1);
    DList_insertData(list,1,&data2);
    DList_insertData(list,0,&data3);
    ASSERT(1 == DList_getIndex(list,&data1,compareInt));
    ASSERT(2 == DList_getIndex(list,&data2,compareInt));
    ASSERT(0 == DList_getIndex(list,&data3,compareInt));
};

void test_delete_node_with_int_data_at_starting_of_linked_list_which_length_is_1(){
    int data = 10;
    DList_insertData(list,0,&data);
    DList_deleteData(list,0);
    ASSERT(NOTFOUND == DList_getIndex(list,&data,compareInt));
};

void test_delete_node_with_index_that_not_exist_return_false(){
    int data = 10;
    DList_insertData(list,0,&data);
    ASSERT(failure == DList_deleteData(list,1));

};

void test_delete_node_with_float_data_at_starting_of_linked_list_which_length_is_1(){
    float data = 10.5f;
    DList_insertData(list,0,&data);
    DList_deleteData(list,0);
    ASSERT(NOTFOUND == DList_getIndex(list,&data,compareFloats));
};

void test_delete_node_with_double_data_at_starting_of_linked_list_which_length_is_1(){
    double data = 10.555;
    DList_insertData(list,0,&data);
    DList_deleteData(list,0);
    ASSERT(NOTFOUND == DList_getIndex(list,&data,compareDoubles));
};

void test_delete_node_with_string_data_at_starting_of_linked_list_which_length_is_1(){
    string data ="data";
    DList_insertData(list,0,&data);
    DList_deleteData(list,0);
    ASSERT(NOTFOUND == DList_getIndex(list,&data,compareStrings));
};

void test_delete_node_with_int_data_at_end_of_linked_list_which_length_is(){
    int data1 = 10 , data2 = 20 , data3 = 30;
    DList_insertData(list,0,&data1);
    DList_insertData(list,1,&data2);
    DList_insertData(list,1,&data3);
    DList_deleteData(list,2);
    ASSERT(NOTFOUND == DList_getIndex(list,&data2,compareInt));
};

void test_delete_node_with_int_data_at_middle_of_linked_list(){
    int data1 = 10,data2= 20,data3=30,data4=40;
    DList_insertData(list,0,&data1);
    DList_insertData(list,1,&data2);
    DList_insertData(list,2,&data3);
    DList_insertData(list,3,&data4);
    DList_deleteData(list, 1);
    ASSERT(NOTFOUND == DList_getIndex(list,&data2,compareInt));
};

void test_delete_node_with_float_data_at_middle_of_linked_list(){
    float data1 = 10.5f,data2= 20.5f,data3=30.5f;
    DList_insertData(list,0,&data1);
    DList_insertData(list,1,&data2);
    DList_insertData(list,2,&data3);
    DList_deleteData(list, 1);
    ASSERT(NOTFOUND == DList_getIndex(list,&data2,compareFloats));
};
void test_delete_node_with_string_data_at_middle_of_linked_list(){
    string data1 = "data1",data2 = "data2",data3 = "data3";
    DList_insertData(list,0,&data1);
    DList_insertData(list,1,&data2);
    DList_insertData(list,1,&data3);
    DList_deleteData(list, 1);
    ASSERT(NOTFOUND == DList_getIndex(list,&data3,compareStrings));
};

void test_hasnext_of_getiterator_gives_true_if_list_not_empty(){
    int number1 = 5,number2 = 9,number3 = 65;
    DList_insertData(list, 0, &number1);
    ASSERT(success == it.hasNext(&it));
};
void test_hasnext_of_getiterator_gives_false_if_list_is_empty(){
        ASSERT(failure == it.hasNext(&it));
}
void test_next_of_getiterator_gives_next_data(){
        int number1 = 5;
        DList_insertData(list, 0, &number1);
        if(it.hasNext(&it))
        ASSERT(5 == *(int*)it.next(&it));
}
void test_should_give_all_values_using_iterator(){
        int i = 0;
        int numbers[] = {5,10,15,20};
        DList_insertData(list, 0, numbers);
        DList_insertData(list, 1, &numbers[1]);
        DList_insertData(list, 2, &numbers[2]);
        DList_insertData(list, 3, &numbers[3]);
        while(i++ <4)  ASSERT(numbers[i-1] == *(int*)it.next(&it));
}