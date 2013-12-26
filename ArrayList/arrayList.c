#include "arrayList.h"
#include <stdlib.h>

ArrayList create(int capacity) {
	ArrayList list;
	list.base = (void*)malloc(sizeof(void*) * capacity);
	list.capacity = capacity;
	list.length = 0;
	return list;
};

void shiftElementsToRightIfNeeded(ArrayList *list, int index) {
	int i;
	if (index < list->length) 
		for (i = list->length - 1; i >= index; i--) 
			list->base[i+1] = list->base[i];
};
void shiftElementsToLeftIfNeeded(ArrayList *list, int index) {
	int i;
	if (index < list->length)
		for (i =index; i < list->length; i++)
			list->base[i] = list->base[i+1];
};

void increaseCapacity(ArrayList *list) {
	if (list->length == list->capacity) {
		list->capacity *= 2;
		list->base = realloc(list->base, list->capacity * sizeof(void*));
	}	
};

void* remove(ArrayList *list,int index){
	void* deletedElement = list->base[index];
	if (list == NULL ||index < 0 || index > list->length) return NULL;
	shiftElementsToLeftIfNeeded(list, index);
	list->length--;
	return deletedElement; 
};
int insert(ArrayList *list, int index, void* data) {
	if (list == NULL ||index < 0 || index > list->length) return 0;
	increaseCapacity(list);
	shiftElementsToRightIfNeeded(list, index);
	list->base[index] = data;
	list->length++;
	return 1;
};

int add(ArrayList *list, void* data){
	return insert(list,list->length,data);
};

void* get(ArrayList *list, int index) {
	if (list ==NULL || index < 0 || index >= list->length) return NULL;
	return list->base[index];
};

int search(ArrayList *list,void* data, CompareFPtr compare){
	int i;
	if (list == NULL) return -1;
	for (i =0; i < list->length; i++)
		if(0==compare(data,list->base[i]))
			return i;
	return -1;	
};
int hasNextForArrayList(Iterator* it){
    ArrayList *list = it->list;
    if(list->length <= it->position) return 0;
    return 1;
}
void* getNextDataForArrayList(Iterator* it){
        ArrayList* list = it->list;
    if(!hasNextForArrayList(it)) return NULL;
    return list->base[it->position++];
}
Iterator getIterator(ArrayList* list){
    Iterator it;
    it.list = list;
    it.position = 0;
    it.hasNext = &hasNextForArrayList;
    it.next = &getNextDataForArrayList;
    return it;
}
void dispose(ArrayList *list) {
	free(list->base);
};