#include "testUtils.h"
#include "hashMap.h"
#include <stdlib.h>

int hashCodeGenerator(void* key){
	return *(int*)key % 10;
};

int compareInts(void *a,void *b){
    return *(int*)a - *(int*)b;
};

HashMap* map;

void setup(){
	map = createHashMap(hashCodeGenerator,compareInts);
};
void tearDown(){
	dispose(map);
}
void test_inserting_data_into_HashMap(){
	int key =5,value =21;
	put(map,&key,&value);
	ASSERT(&value == get(map,&key));
};

void test_getting_data_from_HashMap(){
	int key[] ={5,6,7},value[]={21,65,76};
	void* result;
	put(map,&key[0],&value[0]);
	put(map,&key[1],&value[1]);
	put(map,&key[2],&value[2]);
	ASSERT(&value[1] == get(map,&key[1]));
};

void test_deleting_data_from_HashMap(){
	int key[] ={5,15,25},value[]={21,65,76};
	put(map,&key[0],&value[0]);
	put(map,&key[1],&value[1]);
	put(map,&key[2],&value[2]);
	remove(map,&key[1]);
	ASSERT(NULL ==get(map,&key[1]));
};

void test_gives_all_keys_of_hashMap(){
	int i=0 ,key[] ={5,15,25},value[]={21,65,76};
	Iterator it;
	put(map,&key[0],&value[0]);
	put(map,&key[1],&value[1]);
	put(map,&key[2],&value[2]);
	it = keys(map);
	while(it.hasNext(&it)){
	ASSERT(&key[i] == it.next(&it));
	i++;
	}
};