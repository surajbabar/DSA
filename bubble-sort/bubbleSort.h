typedef int (*compareFPtr)(void* element1, void* element2);

void bSort(void** base,int length, compareFPtr compare);