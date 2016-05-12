#include "item.h"


Item Most_Popular_Item = NULLITEM;

/* Constructors */
Item create_item(char* line)
{
	int size = strlen(line);

	Item item = (Item) malloc(sizeof(struct hashtag));
	item->tag = (char*) malloc(sizeof(char) * (size+1));

	strcpy(item->tag, line);

	item->count = 1;

	update_most_popular_item(item);

	return item;
}

/* Modifiers */

void increment_item_counter(Item item)
{
	item->count++;
	update_most_popular_item(item);
}


/* Selectors */
Item get_most_popular_item()
{
	return Most_Popular_Item;
}


/* Destructors */

void destroy_item(Item item)
{
	free(item->tag);
	free(item);
}

void destroy_item_vector(Item* vector, int size)
{
	int i;
	for (i = 0; i < size; i++)
		destroy_item(vector[i]);

	free(vector);
}

/* Compare Functions */
int compare_items(Item item1, Item item2)
{
	return strcmp(item1->tag, item2->tag);
}


int compare_item_count(const Item item1, const Item item2)
{
	return (item1->count - item2->count);
}





/* OUTPUT FUNCTIONS */
void print_item(Item item)
{
	printf("%s %d\n", item->tag, item->count);

}


void print_item_vector(Item* vector, int size)
{
	int i;

	for(i = 0; i < size; i++)
		print_item(vector[i]);
}


/* Auxiliar Functions */


void update_most_popular_item(Item item)
{
	if (IS_ITEM_NULL(Most_Popular_Item))
	{
		Most_Popular_Item = item;
		return;
	}

	if (compare_item_count(item, Most_Popular_Item) == 0)
		if (compare_items(item, Most_Popular_Item) < 0 )
			Most_Popular_Item = item;

	if(compare_item_count(item, Most_Popular_Item) > 0)
		Most_Popular_Item = item;
}



int sorting_compare_items(const void* v_item1, const void* v_item2)
{
	Item item1 = *(Item*) v_item1;
	Item item2 = *(Item*) v_item2;

	int diff = compare_item_count(item2, item1);

	if (!diff)
		return compare_items(item1, item2);
	
	return diff;
}


void sort_item_vector(Item* item_vector, int item_count)
{
	qsort(item_vector, item_count, sizeof(Item), sorting_compare_items);
}
