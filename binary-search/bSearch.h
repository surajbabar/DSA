typedef int (*CompareFPtr) 
		(const void* first, const void* second);

void* bSearch (void* elementToSearch, void* baseAddress,
				int numberOfElements, int elementSize, CompareFPtr);