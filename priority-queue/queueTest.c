#include "testUtils.h"
#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef char string[256];
int isHeader(Queue* queue){
        return (queue->header->next ==NULL);
};
void test_enqueue_will_add_node_according_to_priority(){
        Queue* queue = createQueue();
        int data1 = 10,data2= 20;
        Node* node1 = createNode(5,&data1);
        Node* node2 = createNode(7,&data2);
        enqueue(queue,node1);
        enqueue(queue,node2);
        ASSERT(&data1 == rear(queue));
};
void test_insert_node_with_string_data_at_starting_of_linked_queue(){
        Queue* queue = createQueue();
        char* data = "data";
        Node* node = createNode(5,data);
        enqueue(queue,node);
        ASSERT(0 ==strcmp(data,rear(queue)));

};
void test_insert_node_with_Float_data_at_starting_of_linked_queue(){
        Queue* queue = createQueue();
        float data = 1.5f;
        Node* node = createNode(5,&data);
        enqueue(queue,node);
        ASSERT(&data == rear(queue));

};
void test_insert_node_with_char_data_at_starting_of_linked_queue(){
        Queue* queue = createQueue();
        char data = 'k';
        Node* node = createNode(5,&data);
        enqueue(queue,node);
        ASSERT(&data == rear(queue));
};
void test_delete_node_with_int_data_at_starting_of_linked_queue_which_length_is_1(){
        Queue* queue = createQueue();
        int data = 10;
        Node* node = createNode(5,&data);
        enqueue(queue,node);
        enqueue(queue,node);
        ASSERT(node == dequeue(queue));
};
void test_delete_node_with_float_data_at_starting_of_linked_queue_which_length_is_1(){
        Queue* queue = createQueue();
        float data = 10.5f;
        Node* node = createNode(5,&data);
        enqueue(queue,node);
        dequeue(queue);
        ASSERT(NULL == rear(queue));
}
void test_delete_node_with_double_data_at_starting_of_linked_queue_which_length_is_1(){
         Queue* queue = createQueue();
        double data = 10.5f;
        Node* node = createNode(5,&data);
        enqueue(queue,node);
        dequeue(queue);
        ASSERT(NULL == rear(queue));}
void test_delete_node_with_string_data_at_starting_of_linked_queue_which_length_is_1(){
        Queue* queue = createQueue();
        char* data ="data";
        Node* node = createNode(5,data);
        enqueue(queue,node);
        dequeue(queue);
        ASSERT(NULL == rear(queue));
};
