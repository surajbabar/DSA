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

	testStarted("test_insert_node_will_not_add_node_at_index_which_does_not_exist");
	setup();
		test_insert_node_will_not_add_node_at_index_which_does_not_exist();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_int_data_at_starting_of_linked_list");
	setup();
		test_insert_node_with_int_data_at_starting_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_string_data_at_starting_of_linked_list");
	setup();
		test_insert_node_with_string_data_at_starting_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_Float_data_at_starting_of_linked_list");
	setup();
		test_insert_node_with_Float_data_at_starting_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_char_data_at_starting_of_linked_list");
	setup();
		test_insert_node_with_char_data_at_starting_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_int_data_at_end_of_linked_list");
	setup();
		test_insert_node_with_int_data_at_end_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_float_data_at_end_of_linked_list");
	setup();
		test_insert_node_with_float_data_at_end_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_string_data_at_end_of_linked_list");
	setup();
		test_insert_node_with_string_data_at_end_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_char_data_at_end_of_linked_list");
	setup();
		test_insert_node_with_char_data_at_end_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_int_data_at_middle_of_linked_list");
	setup();
		test_insert_node_with_int_data_at_middle_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_float_data_at_middle_of_linked_list");
	setup();
		test_insert_node_with_float_data_at_middle_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_double_data_at_middle_of_linked_list");
	setup();
		test_insert_node_with_double_data_at_middle_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_string_data_at_middle_of_linked_list");
	setup();
		test_insert_node_with_string_data_at_middle_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_int_data_at_middle_of_linked_list1");
	setup();
		test_insert_node_with_int_data_at_middle_of_linked_list1();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_int_data_at_start_of_linked_list");
	setup();
		test_insert_node_with_int_data_at_start_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_delete_node_with_int_data_at_starting_of_linked_list_which_length_is_1");
	setup();
		test_delete_node_with_int_data_at_starting_of_linked_list_which_length_is_1();
	tearDown();
	testEnded();
	testStarted("test_delete_node_with_index_that_not_exist_return_false");
	setup();
		test_delete_node_with_index_that_not_exist_return_false();
	tearDown();
	testEnded();
	testStarted("test_delete_node_with_float_data_at_starting_of_linked_list_which_length_is_1");
	setup();
		test_delete_node_with_float_data_at_starting_of_linked_list_which_length_is_1();
	tearDown();
	testEnded();
	testStarted("test_delete_node_with_double_data_at_starting_of_linked_list_which_length_is_1");
	setup();
		test_delete_node_with_double_data_at_starting_of_linked_list_which_length_is_1();
	tearDown();
	testEnded();
	testStarted("test_delete_node_with_string_data_at_starting_of_linked_list_which_length_is_1");
	setup();
		test_delete_node_with_string_data_at_starting_of_linked_list_which_length_is_1();
	tearDown();
	testEnded();
	testStarted("test_delete_node_with_int_data_at_end_of_linked_list_which_length_is");
	setup();
		test_delete_node_with_int_data_at_end_of_linked_list_which_length_is();
	tearDown();
	testEnded();
	testStarted("test_delete_node_with_float_data_at_end_of_linked_list_which_length_is");
	setup();
		test_delete_node_with_float_data_at_end_of_linked_list_which_length_is();
	tearDown();
	testEnded();
	testStarted("test_delete_node_with_int_data_at_middle_of_linked_list");
	setup();
		test_delete_node_with_int_data_at_middle_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_delete_node_with_float_data_at_middle_of_linked_list");
	setup();
		test_delete_node_with_float_data_at_middle_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_delete_node_with_string_data_at_middle_of_linked_list");
	setup();
		test_delete_node_with_string_data_at_middle_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_hasnext_of_getiterator_gives_true_if_list_not_empty");
	setup();
		test_hasnext_of_getiterator_gives_true_if_list_not_empty();
	tearDown();
	testEnded();
	testStarted("test_hasnext_of_getiterator_gives_false_if_list_not_empty");
	setup();
		test_hasnext_of_getiterator_gives_false_if_list_not_empty();
	tearDown();
	testEnded();
	testStarted("test_next_of_getiterator_gives_next_data");
	setup();
		test_next_of_getiterator_gives_next_data();
	tearDown();
	testEnded();
	testStarted("test_should_give_all_values_using_iterator");
	setup();
		test_should_give_all_values_using_iterator();
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
