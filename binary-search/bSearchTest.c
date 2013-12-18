#include "testUtils.h"
#include "bSearch.h"
#include <string.h>
#include <stdlib.h>
typedef char String[256];
//start of testing functions
int compare_int(const void* key,const void* element){
    return (*(int*)key - *(int*)element );
};
int compare_float(const void* key,const void* element){
    return (*(float*)key - *(float*)element );
};
int compare_double(const void* key,const void* element){
    return (*(double*)key - *(double*)element );
};
int compare_string(const void* key,const void* element){
    return strcmp(*(String*)key, *(String*)element );
};
//end of testing functions

void test_1_bSearch_finds_5_in_collection_of_3_4_5(){
	int collection[]={3,4,5},key =5;
	ASSERT(5==*(int*)bSearch(&key,collection,3,sizeof(int),compare_int));
};
void test_2_bSearch_finds_9_in_collection_of_3_4_5_6_7_8_9(){
	int collection[] ={3,4,5,6,7,8,9},key =9;
	ASSERT(9==*(int*)bSearch(&key,collection,7,sizeof(int),compare_int));
};
void test_3_bSearch_does_not_finds_9_in_collection_of_3_4_5_6_7_8(){
	int collection[] ={3,4,5,6,7,8},key =9;
	ASSERT(NULL==bSearch(&key, collection, 6,sizeof(int),compare_int));
};
void test_4_bSearch_finds_5_in_collection_of_3_5_4(){
	int collection[] ={3,5,4},key =5;
	ASSERT(5==*(int*)bSearch(&key, collection, 3,sizeof(int), compare_int));
};
void test_5_bSearch_finds_9_in_collection_of_3_9_5_7_6_8_4(){
	int collection[] ={3,9,5,7,6,8,4},key =9;
	ASSERT(9==*(int*)bSearch(&key,collection,7,sizeof(int),compare_int));
};
void test_6_bSearch_finds_0_pt_2__in_collection_of_3_floats(){
    float collection[]={0.1f,0.2f,0.3f},key=0.2f;
    ASSERT(0.2f==*(float*)bSearch(&key,collection,3,sizeof(int),compare_float));
};
void test_7_bSearch_does_not_find_absent_element_in_collection(){
    float collection[]={0.1f,0.2f,0.3f,0.4f,0.5f},key=8.8f;
    ASSERT(NULL==bSearch(&key,collection,5,sizeof(float),compare_float));
};
void test_8_bSearch_double_element_in_the_given_collection(){
    double collection[]={0.2,2.0,5.0},key=5.0;
    ASSERT(5.0==*(double*)bSearch(&key, collection,3,sizeof(double),compare_double));
};
void test_9_does_not_find_double_element_which_is_absent_in_collection(){
    double collection[]={0.1,0.2,0.3,0.4,0.5},key=8.8;
    ASSERT(NULL==(double*)bSearch(&key,collection,5,sizeof(double),compare_double));
};
void test_10_bsearch_String_element_in_the_collection(){
    String collection[]={"suraj","sumit","aniket"},key="suraj";
    ASSERT(0==strcmp("suraj",*(String*)bSearch(&key,collection,3,sizeof(String),compare_string)));
};
void test_11_does_not_find_absent_string_element_collection(){
    String collection[]={"ram","sham","ghansham","radhesham"},key="shamsham";
    ASSERT(NULL==bSearch(&key,collection,4, sizeof(String),compare_string));
};