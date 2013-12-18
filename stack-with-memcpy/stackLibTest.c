#include "testUtils.h"
#include "stackLib.h"
#include <string.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int areEqual(stack* expected, stack* actual){
	int result = expected->length == actual->length && expected->typeSize == actual->typeSize;
	if(!result) return result;
	return 0 == memcmp(expected->elements,actual->elements,actual->typeSize);
};

void test_stackCreate_with_typesize_4_and_length_5_will_create_20_size_of_stack(){
	int *a =calloc(5,sizeof(int));
	stack* actual =create(4,5);      
	stack expected = {-1,4,5,a};      
	ASSERT(areEqual(&expected,actual));
	free(a);
};

void test_isEmpty_stack_on_empty_stack_will_return_true(){
	stack* s = create(sizeof(int), 5);
	ASSERT(isEmpty(s));
};

void test_isFull_stack_on_Full_stack_will_allocate_new_stack(){
	stack* s = create(sizeof(int), 5);
	s->top=s->length-1;
	isFull(s);
	ASSERT(10 == s->length);
};

void test_isEmpty_stack_on_unempty_stack_will_give_0(){
	stack* s = create(sizeof(int),5);
	int c = 5; 
	ASSERT(push(s,&c));
	ASSERT(0==isEmpty(s));
};

void test_isFull_stack_on_unFull_stack_will_keep_stack_as_it_is(){
	stack* s = create(sizeof(int),5);
	int c = 5; 
	ASSERT(push(s,&c));
	isFull(s);
	ASSERT(5 == s->length);

};

void test_top_stack_will_give_top_Element(){
	stack* s = create(sizeof(int),1);
	int a = 5,b = 6,c = 7; 
	int* Top;
	ASSERT(push(s,&a));
	ASSERT(push(s,&b));
	ASSERT(push(s,&c));
	Top =top(s);
	ASSERT(7==*Top);
};

void test_top_stack_on_empty_stack_will_give_null(){
	stack* s = create(sizeof(int),5);
	ASSERT(NULL == top(s));
};

void test_stack_push_element_5_into_stack_will_add_it_to_the_top_of_stack(){
	stack* s = create(sizeof(int), 5);
	int *a =calloc(5,sizeof(int));
	int c = 5; 
	stack expected = {0,4,5,a};     
	a[0]=5;
	ASSERT(push(s,&c));
	ASSERT(areEqual(&expected,s));
	free(a);
};

void test_stack_push_element_5_into_fullStack_will_allocate_memory_and_add_5(){
	stack* s = create(sizeof(int),5);
	int c = 5; 
	s->top=4;
	ASSERT(push(s,&c));
};

void test_pop_stack_will_remove_element_of_the_top_of_stack(){
	stack* d=create(sizeof(int),5);
	int c = 4,e=5; 
	int* result;
   	ASSERT(push(d,&c));
   	ASSERT(push(d,&e));
	result = pop(d);
	ASSERT(*result == 5);
	ASSERT(0== d->top);
};

void test_pop_stack_on_empty_stack_will_give_null(){
	stack* d=create(sizeof(int),5);
	ASSERT(NULL==pop(d));
}; 
typedef struct 
{
	int acc_no;	
	int balance;
} Account;
void test_deposit_amount_in_account(){
	Account acc1 = {5,5};
	Account acc2 = {10,10};
	Account* poppedAccount;
	stack* accounts = create(sizeof(Account),5);
	push(accounts, &acc1);
	poppedAccount =pop(accounts);
	poppedAccount->balance+=10;
	ASSERT(5==acc1.balance);
	ASSERT(15==poppedAccount->balance);
	push(accounts,&acc2);
	ASSERT(10==poppedAccount->balance);
};