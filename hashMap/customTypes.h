#include "../singly-Linked-List/SinglyLinkedList.h"
#include "hashMap.h"

typedef struct {
	void* key;
	void* value;
}Object;

Object* createObject(void* key,void* value);
void* search(SinglyList* bucket,void* key, compareFPtr compare );