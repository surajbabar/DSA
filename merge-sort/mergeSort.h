typedef int (*compareFPtr)(void* element1, void* element2);

void mergeSort(void* base,int length,int typeSize, compareFPtr compare);