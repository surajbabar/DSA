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
	map->buckets =(SinglyList*)calloc(map->capacity,sizeof(void*));
	map->compare = compare;
	map->hash =hash;
	return map;
};

int put(HashMap* map,void* key,void* value){
	SinglyList* Bucket = bucket(map,key);
	return SList_insertNode(Bucket,Bucket->length,createObject(key,value));
};

void rehash(HashMap* map){
	map->capacity*=2;		
	map->buckets =realloc(map->buckets,map->capacity);
	
};

int getIndex(SinglyList* bucket,void* key,compareFPtr compare){
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

void* search(SinglyList* bucket,void* key,compareFPtr compare){
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

SinglyList* bucket(HashMap* map,void* key){
	int bucketNumber = map->hash(key)%map->capacity;
	return map->buckets+bucketNumber*sizeof(void*);
};

void* get(HashMap* map,void* key){
	return search(bucket(map,key),key,map->compare);
};

int remove(HashMap* map,void* key){
	SinglyList* Bucket = bucket(map,key);
	return SList_deleteNode(Bucket,getIndex(Bucket,key,map->compare)); 
};

void dispose(HashMap* map){
	SinglyList* Bucket;
	int loop;
	for(loop=map->capacity;loop>0;loop--){
		Bucket =bucket(map,&loop);
		if (Bucket == NULL) continue;
		if(Bucket->header!= NULL)  SList_dispose(Bucket);
	}
};

Iterator getKeys(HashMap *map){
    int i;
    Object* element;
    SinglyList* tempList = SList_create();
    SinglyList* list = SList_create();
    Iterator it;
    for(i = 0;i < map->capacity; i++){
        list = (SinglyList*)map->buckets+i*sizeof(void*);
        if(tempList->header != NULL){
            it = SList_iterator(list);
            while(it.hasNext(&it)){
                element = (Object*)it.next(&it);
                SList_insertNode(tempList, tempList->length, element->key);                
            }            
        }
    }
    it = SList_iterator(tempList);
    return it;
};