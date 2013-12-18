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

	testStarted("test_Queue_Create_with_typesize_4_and_length_5_will_create_20_size_of_Queue");
	setup();
		test_Queue_Create_with_typesize_4_and_length_5_will_create_20_size_of_Queue();
	tearDown();
	testEnded();
	testStarted("test_isEmpty_Queue_on_empty_Queue_will_return_true");
	setup();
		test_isEmpty_Queue_on_empty_Queue_will_return_true();
	tearDown();
	testEnded();
	testStarted("test_isFull_Queue_on_Full_Queue_will_return_true");
	setup();
		test_isFull_Queue_on_Full_Queue_will_return_true();
	tearDown();
	testEnded();
	testStarted("test_isEmpty_Queue_on_unempty_Queue_will_give_0");
	setup();
		test_isEmpty_Queue_on_unempty_Queue_will_give_0();
	tearDown();
	testEnded();
	testStarted("test_isFull_Queue_on_unFull_Queue_will_give_0");
	setup();
		test_isFull_Queue_on_unFull_Queue_will_give_0();
	tearDown();
	testEnded();
	testStarted("test_top_Queue_will_give_top_Element");
	setup();
		test_top_Queue_will_give_top_Element();
	tearDown();
	testEnded();
	testStarted("test_top_Queue_on_empty_Queue_will_give_null");
	setup();
		test_top_Queue_on_empty_Queue_will_give_null();
	tearDown();
	testEnded();
	testStarted("test_Queue_enqueue_element_5_into_Queue_will_add_it_to_the_top_of_Queue");
	setup();
		test_Queue_enqueue_element_5_into_Queue_will_add_it_to_the_top_of_Queue();
	tearDown();
	testEnded();
	testStarted("test_Queue_enqueue_element_5_into_fullQueue_will_add_5_to_start_of_queue");
	setup();
		test_Queue_enqueue_element_5_into_fullQueue_will_add_5_to_start_of_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_Queue_will_remove_element_of_the_top_of_Queue");
	setup();
		test_dequeue_Queue_will_remove_element_of_the_top_of_Queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_Queue_on_empty_Queue_will_give_null");
	setup();
		test_dequeue_Queue_on_empty_Queue_will_give_null();
	tearDown();
	testEnded();
	testStarted("test_enqueue_overwrites_after_queue_is_full");
	setup();
		test_enqueue_overwrites_after_queue_is_full();
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
