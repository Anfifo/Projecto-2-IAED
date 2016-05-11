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

	update_most_popular_item(item);

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
		print_item(vector[i]);
	}
}


void increment_item_counter(Item item)
{
	puts("\tincrementing...");
	item->count++;
	update_most_popular_item(item);
}


int compare_items(Item item1, Item item2)
{
	return strcmp(item1->tag, item2->tag);
}


int compare_item_count(const Item item1, const Item item2)
{
	return item1->count - item2->count;
}


int sorting_compare_items(const void* v_item1, const void* v_item2)
{
	Item item1 = *(Item*) v_item1;
	Item item2 = *(Item*) v_item2;

	int dif = compare_item_count(item1, item2);

	if (!dif)
		return compare_items(item1, item2);
	
	return dif;
}


void sort_item_vector(Item* item_vector, int item_count)
{
	qsort((void*)item_vector, item_count, sizeof(Item), sorting_compare_items);
}


void update_most_popular_item(Item item)
{
	if (IS_ITEM_NULL(Most_Popular_Item))
	{
		Most_Popular_Item = item;
		return;
	}

	if (compare_item_count(item, Most_Popular_Item) == 0)
		if (compare_items(item, Most_Popular_Item) > 0)
			Most_Popular_Item = item;

	if(compare_item_count(item, Most_Popular_Item) > 0)
		Most_Popular_Item = item;
}


void delete_item(Item item)
{
	free(item->tag);
	free(item);
}







