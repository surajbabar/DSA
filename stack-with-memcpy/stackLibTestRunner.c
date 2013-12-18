#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_stackCreate_with_typesize_4_and_length_5_will_create_20_size_of_stack");
	setup();
		test_stackCreate_with_typesize_4_and_length_5_will_create_20_size_of_stack();
	tearDown();
	testEnded();
	testStarted("test_isEmpty_stack_on_empty_stack_will_return_true");
	setup();
		test_isEmpty_stack_on_empty_stack_will_return_true();
	tearDown();
	testEnded();
	testStarted("test_isFull_stack_on_Full_stack_will_allocate_new_stack");
	setup();
		test_isFull_stack_on_Full_stack_will_allocate_new_stack();
	tearDown();
	testEnded();
	testStarted("test_isEmpty_stack_on_unempty_stack_will_give_0");
	setup();
		test_isEmpty_stack_on_unempty_stack_will_give_0();
	tearDown();
	testEnded();
	testStarted("test_isFull_stack_on_unFull_stack_will_keep_stack_as_it_is");
	setup();
		test_isFull_stack_on_unFull_stack_will_keep_stack_as_it_is();
	tearDown();
	testEnded();
	testStarted("test_top_stack_will_give_top_Element");
	setup();
		test_top_stack_will_give_top_Element();
	tearDown();
	testEnded();
	testStarted("test_top_stack_on_empty_stack_will_give_null");
	setup();
		test_top_stack_on_empty_stack_will_give_null();
	tearDown();
	testEnded();
	testStarted("test_stack_push_element_5_into_stack_will_add_it_to_the_top_of_stack");
	setup();
		test_stack_push_element_5_into_stack_will_add_it_to_the_top_of_stack();
	tearDown();
	testEnded();
	testStarted("test_stack_push_element_5_into_fullStack_will_allocate_memory_and_add_5");
	setup();
		test_stack_push_element_5_into_fullStack_will_allocate_memory_and_add_5();
	tearDown();
	testEnded();
	testStarted("test_pop_stack_will_remove_element_of_the_top_of_stack");
	setup();
		test_pop_stack_will_remove_element_of_the_top_of_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_stack_on_empty_stack_will_give_null");
	setup();
		test_pop_stack_on_empty_stack_will_give_null();
	tearDown();
	testEnded();
	testStarted("test_deposit_amount_in_account");
	setup();
		test_deposit_amount_in_account();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
