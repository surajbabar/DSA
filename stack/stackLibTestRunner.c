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

	testStarted("test_pop_on_Empty_Stack_will_give_null");
	setup();
		test_pop_on_Empty_Stack_will_give_null();
	tearDown();
	testEnded();
	testStarted("test_top_Stack_will_give_top_Element");
	setup();
		test_top_Stack_will_give_top_Element();
	tearDown();
	testEnded();
	testStarted("test_top_Stack_on_empty_Stack_will_give_null");
	setup();
		test_top_Stack_on_empty_Stack_will_give_null();
	tearDown();
	testEnded();
	testStarted("test_Stack_push_element_5_into_Stack_will_add_it_to_the_top_of_Stack");
	setup();
		test_Stack_push_element_5_into_Stack_will_add_it_to_the_top_of_Stack();
	tearDown();
	testEnded();
	testStarted("test_pop_Stack_will_remove_element_of_the_top_of_Stack");
	setup();
		test_pop_Stack_will_remove_element_of_the_top_of_Stack();
	tearDown();
	testEnded();
	testStarted("test_pop_Stack_on_empty_Stack_will_give_null");
	setup();
		test_pop_Stack_on_empty_Stack_will_give_null();
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
