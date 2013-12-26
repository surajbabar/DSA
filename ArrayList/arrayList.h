#include "iterator.h"

typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);

void* get(ArrayList *list, int index);

void dispose(ArrayList *list);
int add(ArrayList *list,void* data);
void* remove(ArrayList *list,int index);
typedef int (*CompareFPtr) (const void* first, const void* second);
int search(ArrayList *list,void* data,CompareFPtr);
Iterator getIterator(ArrayList* list);
