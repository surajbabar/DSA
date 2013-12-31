#include "schedule.h"
#include <stdlib.h>

Process* createProcess(int priority, int time){
	Process* process  = malloc(sizeof(Process));
	process->priority = priority;	
	process->time = time;
	process->next = NULL;
	return process;

};
Scheduler* createScheduler(int slice,Process* process){
	Scheduler* scheduler  =malloc(sizeof(Scheduler));
	scheduler->slice =slice;	
	scheduler->length=0;
	scheduler->processes =process;
	return scheduler;

};
int insertProcess(Scheduler* scheduler,Process* process){
	Process *back,*temp = scheduler->processes;
	if(temp == NULL) scheduler->processes =process; 
	else{	
	while(process->priority<temp->priority && temp->next!=NULL){
		back=temp;
	 	temp = temp->next;
	}
	process->next=temp;
	back->next = process;
	}
	scheduler->length++;
	return 1;
};

int startScheduler(Scheduler* scheduler){
	int i;
	Process *prev,*temp = scheduler->processes;
	while(scheduler->length!=0){
	for (i = 0; i < scheduler->length; ++i){
		temp->time-=scheduler->slice; 	
		 if(temp->time<=0) {
			prev->next=temp->next;
		 	scheduler->length--;
		 }
		prev= temp;
		temp = temp->next;
	}
	temp = scheduler->processes;
	}
	free(temp);
	return 1;
};
