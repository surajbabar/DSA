#include "customTypes.h"
#include <stdlib.h>

Object* createObject(void* key,void* value){
	Object* object =calloc(1,sizeof(Object));
	object->key =key;
	object->value =value;
	return object;
};

HashMap* createHashMap(HashCodeGeneratorFPtr hash, compareFPtr compare){
	int i;
	HashMap* map=calloc(1,sizeof(map));
	map->capacity =10; 
	map->buckets =(List**)calloc(map->capacity,sizeof(void*));
	map->compare = compare;
	map->hash =hash;
	return map;
};

int getIndex(List* bucket,void* key,compareFPtr compare){
	int i;
	Object* object;
	Node* node = bucket->header;
    for(i = 0;i<bucket->length;i++){
    	if(NULL == node) return -1;
    	object = node->data;
    	if(0 == compare(object->key,key))  return i;
    	node = node->next;
    }	
	return -1;
};

void* search(List* bucket,void* key,compareFPtr compare){
	int i;
	Object* object;
	Node* node = bucket->header;
    for(i = 0;i<bucket->length;i++){
    	if(NULL == node) return NULL;
    	object = node->data;
    	if(0 == compare(object->key,key))
    		return object->value;
 	    node =node->next;
    }         
    return NULL;
};

List* bucket(HashMap* map,void* key){
	return (List*)(map->buckets)+(map->hash(key)*sizeof(void*));
};
int put(HashMap* map,void* key,void* value){
	List* Bucket = bucket(map,key);
	return insertNode(Bucket,Bucket->length,createObject(key,value));
};

void* get(HashMap* map,void* key){
	return search(bucket(map,key),key,map->compare);
};

int remove(HashMap* map,void* key){
	List* Bucket = bucket(map,key);
	return deleteNode(Bucket,getIndex(Bucket,key,map->compare)); 
};

void dispose(HashMap* map){
	// Free(map->buckets);
}; 
