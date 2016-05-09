#include "item.h"

Item create_item(char* test)
{
	Item item = (Item) malloc(sizeof(struct testItem));
	item->random = (char*) malloc(sizeof(char)*141);
	strcpy(item->random, test);
	return item;
}

void print_item_vector(Item* vector, int size)
{
	int i;
	for (i = 0; i < size ; i++)
		if (! IS_ITEM_NULL( vector[i]))
			printf("%s\n", vector[i]->random);
}
