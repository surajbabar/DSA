#include "../iterator/iterator.h"

typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

ArrayList create(int capacity);
void dispose(ArrayList *list);

int insert(ArrayList *list, int index, void* data);
void* remove(ArrayList *list,int index);

void* get(ArrayList *list, int index);
int add(ArrayList *list,void* data);
typedef int (*CompareFPtr) (const void* first, const void* second);
int search(ArrayList *list,void* data,CompareFPtr);
Iterator getIterator(ArrayList* list);