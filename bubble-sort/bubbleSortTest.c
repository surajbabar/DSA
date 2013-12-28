#include "bubbleSort.h"
#include "testUtils.h"
#include <string.h>
#include "../insertion-sort/sort.h"

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

void test_sort_integers_using_bubble_Sort(){
    int i,noOfElements = 3,elementsToSort[] = {2,1,3}, expected[] = {1,2,3};
    void *actual[3];
    for(i = 0; i < noOfElements; i++)
        actual[i] = &elementsToSort[i];
    bSort(actual,noOfElements,compareInts);
    sort(elementsToSort,noOfElements,sizeof(int),compareInts);
        ASSERT(expected[0] == *(int*)actual[0]);
        ASSERT(expected[1] == *(int*)actual[1]);
        ASSERT(expected[2] == *(int*)actual[2]);
}

void test_sort_chars_using_bSort(){
        int i,noOfElements = 3;
        char elementsToSort[] = {'b','c','a'}, expected[] = {'a','b','c'};
        void *actual[3];
        for(i = 0; i < noOfElements; i++)
                actual[i] = &elementsToSort[i];
    bSort(actual,noOfElements,compareChars);
           ASSERT(expected[0] == *(char*)actual[0]);
           ASSERT(expected[1] == *(char*)actual[1]);
           ASSERT(expected[2] == *(char*)actual[2]);
}

void test_sort_floats_using_bSort(){
        int i,noOfElements = 3;
        float elementsToSort[] = {1.2, 3.2, 2.2}, expected[] = {1.2, 2.2, 3.2};
        void *actual[3];
        for(i = 0; i < noOfElements; i++)
                actual[i] = &elementsToSort[i];
    bSort(actual,noOfElements,compareFloats);
           ASSERT(expected[0] == *(float*)actual[0]);
           ASSERT(expected[1] == *(float*)actual[1]);
           ASSERT(expected[2] == *(float*)actual[2]);
}

void test_sort_doubles_using_bSort(){
        int i,noOfElements = 3;
        double elementsToSort[] = {1.2, 3.2, 2.2}, expected[] = {1.2, 2.2, 3.2};
        void *actual[3];
        for(i = 0; i < noOfElements; i++)
                actual[i] = &elementsToSort[i];
    bSort(actual,noOfElements,compareDoubles);
           ASSERT(expected[0] == *(double*)actual[0]);
           ASSERT(expected[1] == *(double*)actual[1]);
           ASSERT(expected[2] == *(double*)actual[2]);
}