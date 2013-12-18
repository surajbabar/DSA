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

	testStarted("test_create_process_will_create_process");
	setup();
		test_create_process_will_create_process();
	tearDown();
	testEnded();
	testStarted("test_create_Scheduler_will_create_scheduler");
	setup();
		test_create_Scheduler_will_create_scheduler();
	tearDown();
	testEnded();
	testStarted("test_insert_process_will_insert_process_in_given_empty_scheduler");
	setup();
		test_insert_process_will_insert_process_in_given_empty_scheduler();
	tearDown();
	testEnded();
	testStarted("test_insert_process_will_insert_process_in_given_scheduler1");
	setup();
		test_insert_process_will_insert_process_in_given_scheduler1();
	tearDown();
	testEnded();
	testStarted("test_insert_process_will_insert_process_in_given_scheduler2");
	setup();
		test_insert_process_will_insert_process_in_given_scheduler2();
	tearDown();
	testEnded();
	testStarted("test_runScheduler_will_handle_its_processes");
	setup();
		test_runScheduler_will_handle_its_processes();
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
