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

	testStarted("test_1_bSearch_finds_5_in_collection_of_3_4_5");
	setup();
		test_1_bSearch_finds_5_in_collection_of_3_4_5();
	tearDown();
	testEnded();
	testStarted("test_2_bSearch_finds_9_in_collection_of_3_4_5_6_7_8_9");
	setup();
		test_2_bSearch_finds_9_in_collection_of_3_4_5_6_7_8_9();
	tearDown();
	testEnded();
	testStarted("test_3_bSearch_does_not_finds_9_in_collection_of_3_4_5_6_7_8");
	setup();
		test_3_bSearch_does_not_finds_9_in_collection_of_3_4_5_6_7_8();
	tearDown();
	testEnded();
	testStarted("test_4_bSearch_finds_5_in_collection_of_3_5_4");
	setup();
		test_4_bSearch_finds_5_in_collection_of_3_5_4();
	tearDown();
	testEnded();
	testStarted("test_5_bSearch_finds_9_in_collection_of_3_9_5_7_6_8_4");
	setup();
		test_5_bSearch_finds_9_in_collection_of_3_9_5_7_6_8_4();
	tearDown();
	testEnded();
	testStarted("test_6_bSearch_finds_0_pt_2__in_collection_of_3_floats");
	setup();
		test_6_bSearch_finds_0_pt_2__in_collection_of_3_floats();
	tearDown();
	testEnded();
	testStarted("test_7_bSearch_does_not_find_absent_element_in_collection");
	setup();
		test_7_bSearch_does_not_find_absent_element_in_collection();
	tearDown();
	testEnded();
	testStarted("test_8_bSearch_double_element_in_the_given_collection");
	setup();
		test_8_bSearch_double_element_in_the_given_collection();
	tearDown();
	testEnded();
	testStarted("test_9_does_not_find_double_element_which_is_absent_in_collection");
	setup();
		test_9_does_not_find_double_element_which_is_absent_in_collection();
	tearDown();
	testEnded();
	testStarted("test_10_bsearch_String_element_in_the_collection");
	setup();
		test_10_bsearch_String_element_in_the_collection();
	tearDown();
	testEnded();
	testStarted("test_11_does_not_find_absent_string_element_collection");
	setup();
		test_11_does_not_find_absent_string_element_collection();
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
