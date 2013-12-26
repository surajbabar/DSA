typedef struct iterator{
	void* list;
	int position;
	int (*hasNext)(struct iterator *it );
	void* (*next)(struct iterator *it );
}Iterator;