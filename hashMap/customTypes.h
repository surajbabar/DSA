#include "hashMap.h"
#include "../singly-Linked-List/SinglyLinkedList.h"

typedef struct {
	void* key;
	void* value;
}Object;

Object* createObject(void* key,void* value);
void* search(SinglyList* bucket,void* key, compareFPtr compare );
void rehash(HashMap* map);
SinglyList* bucket(HashMap* map,void* key);
