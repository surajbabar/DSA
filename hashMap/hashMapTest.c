#include "testUtils.h"
#include "hashMap.h"
#include <stdlib.h>

int hashCodeGenerator(void* key){
	return *(int*)key % 10;
};

int compareInts(void *a,void *b){
    return *(int*)a - *(int*)b;
};

void test_inserting_data_into_HashMap(){
	HashMap* map = createHashMap(hashCodeGenerator,compareInts);
	int key =5,value =21;
	void* result;
	put(map,&key,&value);
	result = get(map,&key);
	ASSERT(&value == result);
	dispose(map);
};

void test_getting_data_from_HashMap(){
	HashMap* map = createHashMap(hashCodeGenerator,compareInts);
	int key[] ={5,6,7},value[]={21,65,76};
	void* result;
	put(map,&key[0],&value[0]);
	put(map,&key[1],&value[1]);
	put(map,&key[2],&value[2]);
	result = get(map,&key[1]);
	ASSERT(&value[1] == result);
	dispose(map);
};

void test_deleting_data_from_HashMap(){
	HashMap* map = createHashMap(hashCodeGenerator,compareInts);
	int key[] ={5,15,25},value[]={21,65,76};
	void* result;
	put(map,&key[0],&value[0]);
	put(map,&key[1],&value[1]);
	put(map,&key[2],&value[2]);
	remove(map,&key[1]);
	result = get(map,&key[1]);
	ASSERT(NULL ==result);
	dispose(map);
};
