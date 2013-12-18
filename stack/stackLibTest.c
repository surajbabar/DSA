#include "testUtils.h"
#include "stackLib.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void test_pop_on_Empty_Stack_will_give_null(){
	Stack* stack = create(5);
	ASSERT(NULL==pop(stack));
};

void test_top_Stack_will_give_top_Element(){
	Stack* stack = create(5);
	int a = 5,b = 6,c = 7; 
	push(stack,&a);
	push(stack,&b);
	push(stack,&c);
	ASSERT(&c ==top(stack));
};

void test_top_Stack_on_empty_Stack_will_give_null(){
	Stack* s = create(5);
	ASSERT(NULL == top(s));
};

void test_Stack_push_element_5_into_Stack_will_add_it_to_the_top_of_Stack(){
	Stack* s = create( 5);
	int c = 5; 
	push(s,&c);
	ASSERT(&c ==top(s));
};

void test_pop_Stack_will_remove_element_of_the_top_of_Stack(){
	Stack* d=create(5);
	int c = 4,e=5; 
	int* result;
   	push(d,&c);
   	push(d,&e);
	result = pop(d);
	ASSERT(*result == 5);
	ASSERT(0== d->top);
};

void test_pop_Stack_on_empty_Stack_will_give_null(){
	Stack* d=create(5);
	ASSERT(NULL==pop(d));
}; 