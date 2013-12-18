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

	testStarted("test_enqueue_will_add_node_according_to_priority");
	setup();
		test_enqueue_will_add_node_according_to_priority();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_string_data_at_starting_of_linked_queue");
	setup();
		test_insert_node_with_string_data_at_starting_of_linked_queue();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_Float_data_at_starting_of_linked_queue");
	setup();
		test_insert_node_with_Float_data_at_starting_of_linked_queue();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_char_data_at_starting_of_linked_queue");
	setup();
		test_insert_node_with_char_data_at_starting_of_linked_queue();
	tearDown();
	testEnded();
	testStarted("test_delete_node_with_int_data_at_starting_of_linked_queue_which_length_is_1");
	setup();
		test_delete_node_with_int_data_at_starting_of_linked_queue_which_length_is_1();
	tearDown();
	testEnded();
	testStarted("test_delete_node_with_float_data_at_starting_of_linked_queue_which_length_is_1");
	setup();
		test_delete_node_with_float_data_at_starting_of_linked_queue_which_length_is_1();
	tearDown();
	testEnded();
	testStarted("test_delete_node_with_double_data_at_starting_of_linked_queue_which_length_is_1");
	setup();
		test_delete_node_with_double_data_at_starting_of_linked_queue_which_length_is_1();
	tearDown();
	testEnded();
	testStarted("test_delete_node_with_string_data_at_starting_of_linked_queue_which_length_is_1");
	setup();
		test_delete_node_with_string_data_at_starting_of_linked_queue_which_length_is_1();
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
