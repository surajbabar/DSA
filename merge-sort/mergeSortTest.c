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

void test_sort_integers_using_bubble_Sort(){
    int i=0,noOfElements = 8,elementsToSort[] = {6,5,3,1,8,7,2,4}, 
    expected[] = {1,2,3,4,5,6,7,8};
    mergeSort(elementsToSort,noOfElements,sizeof(int),compareInts);
    while(i++ <noOfElements)    ASSERT(expected[i-1] == elementsToSort[i-1]);
};

void test_sort_chars_using_bSort(){
    int i=0,noOfElements =8;
    char elementsToSort[] = {'b','c','a','d','b','c','a','d'}, expected[] = {'a','a','b','b','c','c','d','d'};
    mergeSort(elementsToSort,noOfElements,1,compareChars);
   while(i++ <noOfElements) ASSERT(expected[i-1] == elementsToSort[i-1]);
};
// void test_sorts_an_array_of_floats(){
//     float actual[8] = {1.0,4.0,3.0,8.0,6.0,7.0,2.0,5.0};
//     float expected[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
//     int i=0;
//     mergeSort(actual, 8,sizeof(float),compareFloats);
//    while(i++ <8) ASSERT(expected[i-1] == actual[i-1]);
// }

// void test_sorts_an_array_of_doubles(){
//     double actual[6] = {1.000000,4.000000,3.000000,8.000000,6.000000,7.000000};
//     double expected[6] = {1.000000,3.000000,4.000000,6.000000,7.000000,8.000000};
//     int i=0;
//     mergeSort(actual, 6,sizeof(double),compareDoubles);
//    while(i++ <6) ASSERT(expected[i-1] == actual[i-1]);
// }
// void test_sorts_an_array_of_characters_which_is_already_sorted(){
//     char actual[8] = {'a','b','c','d','e','f','g','h'};
//     char expected[8] = {'a','b','c','d','e','f','g','h'};
//     int i;
//     mergeSort(actual, 8,sizeof(char),compareChars);
//     for (i = 0; i < 8; ++i){
//         ASSERT(expected[i] == actual[i]);
//     }
// }

// void test_sorts_an_array_of_Strings(){
//     String actual[5] = {"digvijay","manali","kajal","taj","shital"};
//     String expected[5] = {"digvijay","kajal","manali","shital","taj"};
//     int i;
//     mergeSort(actual, 5,sizeof(String),compareStrings);
//     for (i = 0; i < 5; ++i){
//         ASSERT(0 == strcmp(expected[i],actual[i]));
//     }
// }
// void test_sorts_worst_case_array(){
//     int actual[8] = {8,7,6,5,4,3,2,1};
//     int expected[8] = {1,2,3,4,5,6,7,8};
//     int i;
//     mergeSort(actual, 8,sizeof(int),compareInts);
//     for (i = 0; i < 8; ++i){
//         ASSERT(expected[i] == actual[i]);
//     }
// }
// void test_sort_floats_using_bSort(){
//     int i,noOfElements = 3;
//     float elementsToSort[] = {1.2, 3.2, 2.2}, expected[] = {1.2, 2.2, 3.2};
//     void *actual[3];
//     for(i = 0; i < noOfElements; i++)
//         actual[i] = &elementsToSort[i];
//     mergeSort(elementsToSort,noOfElements,1,compareInts);
//     ASSERT(expected[0] == elementsToSort[0]);
//     ASSERT(expected[1] == elementsToSort[1]);
//     ASSERT(expected[2] == elementsToSort[2]);
// };

// void test_sort_doubles_using_bSort(){
//     int i,noOfElements = 3;
//     double elementsToSort[] = {1.2, 3.2, 2.2}, expected[] = {1.2, 2.2, 3.2};
//     mergeSort(elementsToSort,noOfElements,sizeof(double),compareInts);
//     ASSERT(expected[0] == elementsToSort[0]);
//     ASSERT(expected[1] == elementsToSort[1]);
//     ASSERT(expected[2] == elementsToSort[2]);
// };
