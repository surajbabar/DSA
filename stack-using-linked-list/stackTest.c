#include "testUtils.h"
#include "stack.h"
#include <string.h>
typedef char string[256];

Stack* stack;
void setup(){
    stack = createStack();
};

void test_push_char_element_at_start_of_stack(){
    char element = 'k';
    push(stack , &element);
    ASSERT(&element ==top(stack));         
};

void test_push_int_element_at_start_of_stack(){
    int element = 10;
    push(stack , &element);
    ASSERT(&element ==top(stack));         
};
void test_push_string_element_at_start_of_stack(){
    string data = "data";
    push(stack , &data);
    ASSERT(&data ==top(stack));         
};
void test_push_float_element_at_start_of_stack(){
    float element = 10.5f;
    push(stack , &element);
    ASSERT(&element ==top(stack));         

};
void test_push_int_element_at_top_of_stack(){
        Stack* stack = createStack();
        int element1 = 10,element2 = 20,element3 = 30;
        push(stack , &element1);
        push(stack , &element2);
        push(stack , &element3);
};
void test_pop_int_element_at_top_of_stack(){
        Stack* stack = createStack();
        int element1 = 10,element2 = 20,element3 = 30;
        push(stack , &element1);
        push(stack , &element2);
        push(stack , &element3);
        ASSERT(stack->length == 3);
        ASSERT(*(int*)pop(stack)== 30);         
        ASSERT(stack->length == 2);         
}
void test_pop_float_element_at_top_of_stack(){
        Stack* stack = createStack();
        float element1 = 10.5f,element2 = 20.5f,element3 = 30.5f;
        push(stack , &element1);
        push(stack , &element2);
        push(stack , &element3);
        ASSERT(stack->length == 3);
        ASSERT(*(float*)pop(stack) == 30.5);         
        ASSERT(stack->length == 2);         
}
void test_pop_string_element_at_top_of_stack(){
        Stack* stack = createStack();
        string data1="data1" , data2="data2" , data3="data3" ;
        push(stack , &data1);
        push(stack , &data2);
        push(stack , &data3);
        ASSERT(stack->length == 3);
        ASSERT(!strcmp(*(string*)pop(stack) , "data3"));         
        ASSERT(stack->length == 2);         
}
void test_top_gives_element_at_top_of_stack(){
        Stack* stack = createStack();
        int element1 = 10,element2 = 20,element3 = 30;
        push(stack , &element1);
        push(stack , &element2);
        push(stack , &element3);
        ASSERT(30 == *(int*)top(stack));
}