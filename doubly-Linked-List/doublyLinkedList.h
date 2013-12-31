#include "../iterator/iterator.h"

typedef int (*compareFPtr)(void *elementToCompare,void *element);

typedef struct {
        void* header;
        int length;
}DList;

DList* DList_create();
void DList_dispose(DList* list);
int DList_insertData(DList* list , int index , void* data);
int DList_deleteData(DList* list , int index);
int DList_getIndex(DList* list, void* data, compareFPtr compare); 
void* DList_getData(DList* list,int index); 
void DList_sort(DList* dList, compareFPtr compare);
Iterator DList_getIterator(DList* list);