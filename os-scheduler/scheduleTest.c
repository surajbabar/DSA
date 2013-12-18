#include "testUtils.h"
#include "schedule.h"
#include <stdlib.h>
#include <stdio.h>

void test_create_process_will_create_process(){
	Process* process= createProcess(5,10);
	ASSERT(5==process->priority);
	ASSERT(10==process->time);
	ASSERT(NULL==process->next);
};
void test_create_Scheduler_will_create_scheduler(){
	Scheduler* scheduler= createScheduler(5,NULL);
	ASSERT(5==scheduler->slice);
	ASSERT(0==scheduler->length);
	ASSERT(NULL==scheduler->processes);
};
void test_insert_process_will_insert_process_in_given_empty_scheduler(){
	Process* process= createProcess(5,10);
	Scheduler* scheduler = createScheduler(5,NULL);
	ASSERT(insertProcess(scheduler,process));
	ASSERT(1==scheduler->length);
	ASSERT(5==scheduler->slice);
	ASSERT(process==scheduler->processes);
};
void test_insert_process_will_insert_process_in_given_scheduler1(){
	Process* process1= createProcess(5,10);
	Process* process2= createProcess(7,10);
	Scheduler* scheduler = createScheduler(5,NULL);
	ASSERT(insertProcess(scheduler,process1));
	ASSERT(insertProcess(scheduler,process2));
	ASSERT(2==scheduler->length);
	ASSERT(5==scheduler->slice);
	ASSERT(scheduler->processes==process2);
	ASSERT(process2->next==process1);
	ASSERT(process1->next==NULL);
};

void test_insert_process_will_insert_process_in_given_scheduler2(){
	Process* process1= createProcess(5,10);
	Process* process2= createProcess(9,10);
	Process* process3= createProcess(7,10);
	Scheduler* scheduler = createScheduler(5,NULL);
	ASSERT(insertProcess(scheduler,process1));
	ASSERT(insertProcess(scheduler,process2));
	ASSERT(insertProcess(scheduler,process3));
	ASSERT(3==scheduler->length);
	ASSERT(5==scheduler->slice);
	ASSERT(scheduler->processes==process2);
	ASSERT(process2->next==process3);
	ASSERT(process3->next==process1);
	ASSERT(process1->next==NULL);
};
void test_runScheduler_will_handle_its_processes(){
	Process* process1= createProcess(5,13);
	Process* process2= createProcess(5,15);
	Scheduler* scheduler = createScheduler(5,NULL);
	ASSERT(insertProcess(scheduler,process1));
	ASSERT(insertProcess(scheduler,process2));
	ASSERT(2==scheduler->length);
	ASSERT(5==scheduler->slice);
	ASSERT(scheduler->processes==process2);
	ASSERT(process2->next==process1);
	ASSERT(process1->next==NULL);
	ASSERT(startScheduler(scheduler));
	ASSERT(0==scheduler->length);

};