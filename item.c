#include "item.h"

Item* Vector_Elementos;
Item Most_Popular_Item = NULLITEM;

Item create_item(char* line)
{
	int size = strlen(line);

	Item item = (Item) malloc(sizeof(struct hashtag));
	item->tag = (char*) malloc(sizeof(char) * size);

	strcpy(item->tag, line);

	item->count = 1;

	if(IS_ITEM_NULL(Most_Popular_Item))
		Most_Popular_Item = item;

	return item;
}


void print_item(Item item)
{
	printf("%s %d\n", item->tag, item->count);
}


void print_item_vector(Item* vector, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		printf("%s %d\n", vector[i]->tag, vector[i]->count);
	}
}


int compare_items(Item item1, Item item2)
{
	return strcmp(item1->tag, item2->tag);
}


void increment_item_counter(Item item)
{
	puts("\tincrementing...");
	item->count++;

	if (item->count > Most_Popular_Item->count)
		Most_Popular_Item = item;

}

int sort_compare_item(const void* item1, const void* item2)
{
	Item new_item_1 = (Item) item1;
	Item new_item_2 = (Item) item2;
	return compare_items(new_item_1, new_item_2);
} 

void sort_item_vector(Item* item_vector, int item_count)
{
	qsort(item_vector, item_count, sizeof(Item), sort_compare_item);

}

void delete_item(Item item)
{
	free(item->tag);
	free(item);
}

