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

	testStarted("test_1matching_brackets_gives_1");
	setup();
		test_1matching_brackets_gives_1();
	tearDown();
	testEnded();
	testStarted("test_2gives_0_as_brackets_not_matched");
	setup();
		test_2gives_0_as_brackets_not_matched();
	tearDown();
	testEnded();
	testStarted("test_3expression_with_valid_bracket_sequence_gives_1");
	setup();
		test_3expression_with_valid_bracket_sequence_gives_1();
	tearDown();
	testEnded();
	testStarted("test_4expression_with_valid_bracket_sequence_gives_1");
	setup();
		test_4expression_with_valid_bracket_sequence_gives_1();
	tearDown();
	testEnded();
	testStarted("test_expression_without_brackets_gives_0");
	setup();
		test_expression_without_brackets_gives_0();
	tearDown();
	testEnded();
	testStarted("test_expression_with_incorrect_brackets_gives_0");
	setup();
		test_expression_with_incorrect_brackets_gives_0();
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
