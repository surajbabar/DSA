typedef struct {
	int priority;
	int time;
	void* next;
}Process;

typedef struct {
	int length;
	int slice;
	Process* processes;
}Scheduler;

Process* createProcess(int priority,int time);
Scheduler* createScheduler(int slice,Process* process);
int insertProcess(Scheduler* scheduler,Process* process);
int startScheduler(Scheduler* scheduler);
