#include "bubbleSort.h"
#include "stdlib.h"
#include "memory.h"

void bSort(void** base,int length, compareFPtr compare){
    int i,j;
    void* temp;
    for (i = 1; i < length; i++)
    	for (j = 0; j < length-i; j++)
            if(0 < compare(base[j],base[j+1])){
                temp = base[j];
                base[j] = base[j+1];
                base[j+1] = temp;                                
            }
};