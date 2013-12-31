#include "testUtils.h"
#include "singlyLinkedList.h"
#include "customTypes.h"
SinglyList* list;
Iterator it;
void setup(){
    list = SList_create();
    it = SList_iterator(list);
};

void tearDown(){
    SList_dispose(list);
};
void test_insert_node_will_not_add_node_at_index_which_does_not_exist(){
    int data = 10;
    ASSERT(0 == SList_insertNode(list,4,&data));
};
void test_insert_node_with_int_data_at_starting_of_linked_list(){
    int data = 10;
    SList_insertNode(list,0,&data);
    ASSERT(SList_deleteNode(list,0));
};
void test_insert_node_with_string_data_at_starting_of_linked_list(){
    string data = "suraj";
    SList_insertNode(list,0,&data);
    ASSERT(SList_deleteNode(list,0));
};
void test_insert_node_with_Float_data_at_starting_of_linked_list(){
    float data = 5.5f;
    SList_insertNode(list,0,&data);
    ASSERT(SList_deleteNode(list,0));
};

void test_insert_node_with_char_data_at_starting_of_linked_list(){
    char data1 = 'k' ,data2 = 'j';
    SList_insertNode(list,0,&data1);
    SList_insertNode(list,0,&data2);
    ASSERT(SList_deleteNode(list,0));
    ASSERT(SList_deleteNode(list,0));
};

void test_insert_node_with_int_data_at_end_of_linked_list(){
    int data1 = 10,data2= 20;
    SList_insertNode(list,0,&data1);
    SList_insertNode(list,1,&data2);
    ASSERT(SList_deleteNode(list,0));
    ASSERT(SList_deleteNode(list,0));
};
void test_insert_node_with_float_data_at_end_of_linked_list(){
    float data1 = 10.5f,data2= 20.5f;
    SList_insertNode(list,0,&data1);
    SList_insertNode(list,1,&data2);
    ASSERT(SList_deleteNode(list,0));
    ASSERT(SList_deleteNode(list,0));
};
void test_insert_node_with_string_data_at_end_of_linked_list(){
    string data1="data1",data2 = "data2";
   SList_insertNode(list,0,&data1);
    SList_insertNode(list,1,&data2);
    ASSERT(SList_deleteNode(list,0));
    ASSERT(SList_deleteNode(list,0));

};
void test_insert_node_with_char_data_at_end_of_linked_list(){
    char data1 = 'k',data2 = 'j';
    SList_insertNode(list,0,&data1);
    SList_insertNode(list,1,&data2);
    ASSERT(SList_deleteNode(list,0));
    ASSERT(SList_deleteNode(list,0));
};

void test_insert_node_with_int_data_at_middle_of_linked_list(){
    int data1 = 10,data2= 20,data3=30;
    SList_insertNode(list,0,&data1);
    SList_insertNode(list,1,&data2);
    ASSERT(SList_deleteNode(list,0));
    ASSERT(SList_deleteNode(list,0));
};
void test_insert_node_with_float_data_at_middle_of_linked_list(){
    float data1 = 10.5f,data2= 20.5f,data3=30.5f;
    SList_insertNode(list,0,&data1);
    SList_insertNode(list,1,&data2);
    ASSERT(SList_deleteNode(list,0));
    ASSERT(SList_deleteNode(list,0));
};
void test_insert_node_with_double_data_at_middle_of_linked_list(){
    double data1 = 10.5,data2= 20.5,data3=30.5;
    SList_insertNode(list,0,&data1);
    SList_insertNode(list,1,&data2);
    ASSERT(SList_deleteNode(list,0));
    ASSERT(SList_deleteNode(list,0));
};
void test_insert_node_with_string_data_at_middle_of_linked_list(){
    string data1 ="data1",data2 = "data2",data3 = "data3";
    SList_insertNode(list,0,&data1);
    SList_insertNode(list,1,&data2);
    ASSERT(SList_deleteNode(list,0));
    ASSERT(SList_deleteNode(list,0));
};
void test_insert_node_with_int_data_at_middle_of_linked_list1(){
    int data1 = 10,data2= 20,data3=30,data4=40;
   SList_insertNode(list,0,&data1);
    SList_insertNode(list,1,&data2);
    ASSERT(SList_deleteNode(list,0));
    ASSERT(SList_deleteNode(list,0));
};

void test_delete_node_with_int_data_at_starting_of_linked_list_which_length_is_1(){
    int data = 10;
    SList_insertNode(list,0,&data);
    ASSERT(SList_deleteNode(list,0));
    
};
void test_delete_node_with_index_that_not_exist_return_false(){
    int data = 10;
    SList_insertNode(list,0,&data);
    ASSERT(SList_deleteNode(list,0));
};
void test_delete_node_with_float_data_at_starting_of_linked_list_which_length_is_1(){
    float data = 10.5f;
  SList_insertNode(list,0,&data);
    ASSERT(SList_deleteNode(list,0));
};
void test_delete_node_with_double_data_at_starting_of_linked_list_which_length_is_1(){
    double data = 10.555;
  SList_insertNode(list,0,&data);
    ASSERT(SList_deleteNode(list,0));
};
void test_delete_node_with_string_data_at_starting_of_linked_list_which_length_is_1(){
    string data = "data";
  SList_insertNode(list,0,&data);
    ASSERT(SList_deleteNode(list,0));
};
void test_delete_node_with_int_data_at_end_of_linked_list(){
    Node* node;
    int data1 = 10 , data2 = 20 , data3 = 30;
    SList_insertNode(list,0,&data1);
    SList_insertNode(list,1,&data2);
    SList_insertNode(list,1,&data3);
    ASSERT(SList_deleteNode(list,2));
    ASSERT(SList_deleteNode(list,0));
    ASSERT(SList_deleteNode(list,0));
};
void test_delete_node_with_float_data_at_end_of_linked_list(){
    Node* node;
    int data1 = 10 , data2 = 20 , data3 = 30;
    SList_insertNode(list,0,&data1);
    SList_insertNode(list,1,&data2);
    SList_insertNode(list,2,&data3);
    ASSERT(SList_deleteNode(list,2));
    ASSERT(SList_deleteNode(list,0));
    ASSERT(SList_deleteNode(list,0));
};
void test_delete_node_with_int_data_at_middle_of_linked_list(){
    int data1 = 10,data2= 20,data3=30,data4=40;
    Node* second;
    SList_insertNode(list,0,&data1);
    SList_insertNode(list,1,&data2);
    SList_insertNode(list,2,&data3);
    SList_insertNode(list,3,&data4);
    ASSERT(SList_deleteNode(list,3));
    ASSERT(SList_deleteNode(list,2));
    ASSERT(SList_deleteNode(list,1));
};
void test_delete_node_with_float_data_at_middle_of_linked_list(){
    float data1 = 10.5f,data2= 20.5f,data3=30.5f;
    SList_insertNode(list,0,&data1);
    SList_insertNode(list,1,&data2);
    SList_insertNode(list,2,&data3);
    ASSERT(SList_deleteNode(list, 1));

};
void test_delete_node_with_string_data_at_middle_of_linked_list(){
    string data1 = "data1",data2 = "data2",data3 = "data3";
    SList_insertNode(list,0,&data1);
    SList_insertNode(list,1,&data2);
    SList_insertNode(list,1,&data3);
    ASSERT(SList_deleteNode(list, 1));
};

void test_hasnext_of_getiterator_gives_true_if_list_not_empty(){
    int number1 = 5,number2 = 9,number3 = 65;
    SList_insertNode(list, 0, &number1);
    ASSERT(1 == it.hasNext(&it));
};
void test_hasnext_of_getiterator_gives_false_if_list_is_empty(){
        ASSERT(0 == it.hasNext(&it));
}
void test_next_of_getiterator_gives_next_data(){
        int number1 = 5;
        SList_insertNode(list, 0, &number1);
        if(it.hasNext(&it))
        ASSERT(5 == *(int*)it.next(&it));
}
void test_should_give_all_values_using_iterator(){
        int i = 0;
        int numbers[] = {5,10,15,20};
        SList_insertNode(list, 0, numbers);
        SList_insertNode(list, 1, &numbers[1]);
        SList_insertNode(list, 2, &numbers[2]);
        SList_insertNode(list, 3, &numbers[3]);
        while(i++ <4)  ASSERT(numbers[i-1] == *(int*)it.next(&it));
}