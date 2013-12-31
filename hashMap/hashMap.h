#include "../iterator/iterator.h"
typedef int (*compareFPtr)(void* first, void* second);
typedef int (*HashCodeGeneratorFPtr)(void* key);

typedef	struct {
	void* buckets;
	int capacity;
	HashCodeGeneratorFPtr hash;
    compareFPtr compare;
}HashMap;

HashMap* createHashMap(HashCodeGeneratorFPtr hash, compareFPtr compare);
int put(HashMap* map,void* key,void* value);
void* get(HashMap* map,void* key);
int remove(HashMap* map,void* key);
void dispose(HashMap* map); 
Iterator keys(HashMap* map);