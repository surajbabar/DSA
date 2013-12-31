#include "testUtils.h"
#include "mergeSort.h"
#include <string.h>
typedef  char String[256];

int compareInts(void* first,void* second){
    return *(int*)first - *(int*)second;
};
int compareChars(void* first,void* second){
    return *(char*)first - *(char*)second;
};
int compareFloats(void* first,void* second){
    return *(float*)first - *(float*)second;
};
int compareDoubles(void* first,void* second){
    return *(double*)first - *(double*)second;
};

int compareStrings(void* a, void* b){
    return 0 < strcmp(a,b) ? 0 : 1;
}

void test_sort_integers_using_merge_Sort(){
    int i=0,noOfElements = 8,elementsToSort[] = {6,5,3,1,8,7,2,4}, 
    expected[] = {1,2,3,4,5,6,7,8};
    mergeSort(elementsToSort,noOfElements,sizeof(int),compareInts);
    while(i++ <noOfElements)    ASSERT(expected[i-1] == elementsToSort[i-1]);
};

void test_sort_chars_using_merge_Sort(){
    int i=0,noOfElements =8;
    char elementsToSort[] = {'b','c','a','d','b','c','a','d'}, expected[] = {'a','a','b','b','c','c','d','d'};
    mergeSort(elementsToSort,noOfElements,1,compareChars);
   while(i++ <noOfElements) ASSERT(expected[i-1] == elementsToSort[i-1]);
};