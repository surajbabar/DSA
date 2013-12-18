#include "bSearch.h"
#include <stdlib.h>

void* bSearch (void* key,void* base,int high,int size, CompareFPtr compare){
	int low=0,mid,result;
	qsort(base,high,size,compare);
	while(low<high){
		mid=(low+high)/2;
		result = compare(key,base+mid*size);
		if(0==result) return key;
		if(result>0) low=mid+1;
		else high=mid-1; 
	}
	return NULL;
};