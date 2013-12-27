#include "../singly-Linked-List/linkedList.h"
#include "hashMap.h"

typedef struct {
	void* key;
	void* value;
}Object;

Object* createObject(void* key,void* value);
void* search(List* bucket,void* key, compareFPtr compare );