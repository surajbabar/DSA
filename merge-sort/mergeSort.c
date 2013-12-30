#include "mergeSort.h"
#include <stdlib.h>
#include "memory.h"
#include <stdio.h>
void mergeSort(void* base,int length,int typeSize, compareFPtr compare){
    int i,j=1,k=0,n;
    void* temp =calloc(length,sizeof(typeSize));
    for (i = 0; i < length; i+=2)
       if(0 < compare(base+i*typeSize , base+(i+1)*typeSize)){
            memcpy(temp,base+i*typeSize,typeSize);
            memcpy(base+i*typeSize,base+(i+1)*typeSize,typeSize);
            memcpy(base+(i+1)*typeSize,temp,typeSize);                                
        }
	for (i = 0; i < length; i++)
        printf("%c\n",*(char*)(base+(i*typeSize)));
        //5 6 1 3 7 8 2 4
    for (i = 0; i < length/2; i++){
        j++;
        if(i<(length/2)/2)
        if(0 <compare(base+k*typeSize,base+j*typeSize)){
                printf("%dsd%c\n",j,*(char*)(base+(j*typeSize)));

            memcpy(temp+i*typeSize,base+j*typeSize,typeSize);
            continue;
        }
        memcpy(temp+i*typeSize,base+k*typeSize,typeSize); 
        k++;
    }
    k=i;
    j=i+1;
    for (i = length/2; i < length; i++){
        j++;
        if(i<length-1)
        if(0 < compare(base+k*typeSize , base+j*typeSize)){
            memcpy(temp+i*typeSize,base+j*typeSize,typeSize);
            continue;
        }   
        memcpy(temp+i*typeSize,base+k*typeSize,typeSize); 
        k++;
    }
    memcpy(base,temp,length*typeSize);
        // 1 3 5 6 2 4 7 8
        k=0;j=3;
    for (i = 0; i < length-2; i++){
        j++;
         if(0 < compare(base+k*typeSize , base+j*typeSize)){
            memcpy(temp+i*typeSize,base+j*typeSize,typeSize);
            continue;
        }   
        memcpy(temp+i*typeSize,base+k*typeSize,typeSize); 
        k++;
        j--;
    }   
        memcpy(base,temp,(length-(length/3))*typeSize);
    //1 2 3 4 5 6 7 8   
    free(temp);
};  