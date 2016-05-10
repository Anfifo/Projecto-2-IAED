#include "hashtable.h"

Hash_Table init_hash_table(int table_size)
{
	int i;
	Hash_Table HT = (Hash_Table) malloc(sizeof(struct HASHTABLE));

	HT->count = 0;
	HT->size = 2 * table_size;
	HT->table = (Item *) malloc(sizeof(Item) * HT->size);

	for (i = 0; i < HT->size; i++)
		(HT->table)[i] = NULLITEM;

	return HT;
}


void insert_hash_table(Hash_Table HT, Item item)
{
	int i = 0;
	int index = HASH(KEY(item), HT->size);
	int position = index;
	HT->count ++;

	if (HT->count > (HT->size/2))
		expand_hash_table(HT);

	while (!(IS_ITEM_NULL(HT->table[i])))
	{
		i++;
		position = (index+TABLE_JUMP(i))%HT->size;
	}

	HT->table[position] = item;
}


Item search_hash_table(Hash_Table HT, Item item)
{
	int i = 0;
	int index = HASH(KEY(item), HT->size);
	int position = index;
	
	while (!IS_ITEM_NULL(HT->table[position]))
	{
		if (IS_ITEM_NULL(HT->table[position]))
			return HT->table[position];

		i++;
		position = (index+TABLE_JUMP(i))%HT->size;
	}
	return NULLITEM;
}


void expand_hash_table(Hash_Table HT)
{
	int i;
	int size = HT->size;
	int count = HT->count;
	Item *tempTable = HT->table;

	HT = init_hash_table( 2 * size);
	HT->size = size;
	HT->count = count;

	for (i = 0; i < size; i++)
		if (IS_ITEM_NULL(tempTable[i]))
			insert_hash_table(HT,tempTable[i]);

	free(tempTable);
}



Item* hash_table_to_vector(Hash_Table HT)
{
	Item* vector = (Item*) malloc(sizeof(Item) * HT->count);
	int i, j = 0;
	for (i = 0; i < HT->size; i++)
		if (!IS_ITEM_NULL(HT->table[i]))
			vector[j++] = HT->table[i];
	return vector;
}

int hash_table_item_count(Hash_Table HT)
{
	return(HT->count);
}


/*

for tests

int main(int argc, char const *argv[])
{
	Hash_Table ash_ketchum = init_hash_table (10);
	Item a = create_item("rock");
	Item b = create_item("paper");
	Item c = create_item("scisors");
	insert_hash_table(ash_ketchum, a);
	insert_hash_table(ash_ketchum, b);
	insert_hash_table(ash_ketchum, c);
	printf("count: %d, size: %d\n", ash_ketchum->count, ash_ketchum->size);

	print_item_vector(hash_table_to_vector(ash_ketchum), ash_ketchum->count);

	return 0;
}
*/