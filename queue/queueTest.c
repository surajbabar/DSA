#include "testUtils.h"
#include "queue.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int areEqual(Queue* expected, Queue* actual){
	int result = expected->length == actual->length && expected->typeSize == actual->typeSize;
	if(!result) return result;
	return 0 == memcmp(expected->elements,actual->elements,actual->typeSize);
};

void test_Queue_Create_with_typesize_4_and_length_5_will_create_20_size_of_Queue(){
	int a[]={0,0,0,0,0};
	Queue* actual =create(4,5);      
	Queue expected = {-1,4,5,a};      
	ASSERT(areEqual(&expected,actual));
};

void test_isEmpty_Queue_on_empty_Queue_will_return_true(){
	Queue* s = create(sizeof(int), 5);
	ASSERT(isEmpty(s));
};

void test_isFull_Queue_on_Full_Queue_will_return_true(){
	Queue* s = create(sizeof(int), 5);
	ASSERT(!isFull(s));
};

void test_isEmpty_Queue_on_unempty_Queue_will_give_0(){
	Queue* s = create(sizeof(int),5);
	int c = 5; 
	ASSERT(enqueue(s,&c));
	ASSERT(0==isEmpty(s));
};

void test_isFull_Queue_on_unFull_Queue_will_give_0(){
	Queue* s = create(sizeof(int),5);
	int c = 5; 
	ASSERT(enqueue(s,&c));
	ASSERT(!isFull(s));
};

void test_top_Queue_will_give_top_Element(){
	Queue* s = create(sizeof(int),5);
	int a = 5,b = 6,c = 7; 
	int* Rear;
	ASSERT(enqueue(s,&a));
	ASSERT(enqueue(s,&b));
	ASSERT(enqueue(s,&c));
	Rear =rear(s);
	ASSERT(7==*Rear);
};

void test_top_Queue_on_empty_Queue_will_give_null(){
	Queue* s = create(sizeof(int),5);
	ASSERT(NULL == rear(s));
};

void test_Queue_enqueue_element_5_into_Queue_will_add_it_to_the_top_of_Queue(){
	Queue* s = create(sizeof(int), 5);
	int a[] = {5,0,0,0,0};
	int c = 5; 
	Queue expected = {0,4,5,a};     
	ASSERT(enqueue(s,&c));
	ASSERT(areEqual(&expected,s));
};

void test_Queue_enqueue_element_5_into_fullQueue_will_not_add_5(){
	Queue* s = create(sizeof(int),5);
	int c = 5; 
	s->rear=4;
	ASSERT(!enqueue(s,&c));
};

void test_dequeue_Queue_will_remove_element_of_the_top_of_Queue(){
	Queue* d=create(sizeof(int),5);
	int c = 4,e=5; 
	int* result;
   	ASSERT(enqueue(d,&c));
   	ASSERT(enqueue(d,&e));
	result = dequeue(d);
	ASSERT(*result ==4);
	ASSERT(0 == d->rear);
};

void test_dequeue_Queue_on_empty_Queue_will_give_null(){
	Queue* d=create(sizeof(int),5);
	ASSERT(NULL==dequeue(d));
}; 

typedef struct 
{
	int acc_no;	
	int balance;
} Account;

void test_deposit_amount_in_account(){
	Account acc1 = {5,5};
	Account acc2 = {10,10};
	Account* dequeuedAccount;
	Queue* accounts = create(sizeof(Account),5);
	ASSERT(enqueue(accounts, &acc1));
	ASSERT(enqueue(accounts, &acc1));
	dequeuedAccount =dequeue(accounts);
	dequeuedAccount->balance+=10;
	ASSERT(5 ==acc1.balance);
	ASSERT(15 ==dequeuedAccount->balance);
	ASSERT(enqueue(accounts,&acc2));
	ASSERT(15 == dequeuedAccount->balance);
};