/*
== = = = = = = = = = = ==
= /////// tg034 /////// =
== = = = = = = = = = = ==
=  84698 Andre Fonseca	=
=  84726 Isabel Dias	=
== = = = = = = = = = = ==
=  2o Projecto de IAED	=
=   LEIC-T 2015-2016	=
== = = = = = = = = = = == 
*/

#include "hashtable.h"


/* CONSTRUCTORS */
void init_hash_table_table(Hash_Table HT)
{
	int i;
	HT->table = (Item *) malloc(sizeof(Item) * HT->size);

	for (i = 0; i < HT->size; i++)
		HT->table[i] = NULLITEM;
}


Hash_Table init_hash_table(int table_size)
{
	Hash_Table HT = (Hash_Table) malloc(sizeof(struct HashTable));
	
	HT->count = 0;
	HT->size = table_size;
	init_hash_table_table(HT);

	return HT;
}




/* MODIFIERS */
void insert_hash_table(Hash_Table HT, Item item)
{	
	int i = 0;

	/* Checks if Table needs expansion */
	if (HT->count > (HT->size * HASHTABLE_EXPANSION_THRESHOLD))
		expand_hash_table(HT);

	int index = HASH(KEY(item), HT->size);
	int position = index;
	HT->count ++;

	/* In case of collisions, calculates next position */
	while (!(IS_ITEM_NULL(HT->table[position])))
	{
		i++;
		position = (index+TABLE_JUMP(i))%HT->size;
	}

	HT->table[position] = item;
}


void expand_hash_table(Hash_Table HT)
{
	int i;
	int old_size = HT->size;
	Item *tempTable = HT->table;

	HT->count = 0;
	HT->size = old_size * HASHTABLE_EXPANSION_VALUE;
	init_hash_table_table(HT);

	for (i = 0; i < old_size; i++)
		if (!IS_ITEM_NULL(tempTable[i]))
			insert_hash_table(HT,tempTable[i]);

	free(tempTable);
}




/* SELECTORS */
Item search_hash_table(Hash_Table HT, Item item)
{
	int i = 0;
	int index = HASH(KEY(item), HT->size);
	int position = index;
	
	/* checking possible positions where item could be */
	while (!IS_ITEM_NULL(HT->table[position]))
	{
		if (EQUAL_ITEM(HT->table[position], item))
			return HT->table[position];

		i++;
		position = (index+TABLE_JUMP(i))%HT->size;
	}

	return NULLITEM;
}


int hash_table_item_count(Hash_Table HT)
{
	return(HT->count);
}




/* DESTRUCTORS */
void destroy_hash_table(Hash_Table HT)
{
	HASHTABLE_DESTROY_ITEM_VECTOR(hash_table_to_vector(HT),hash_table_item_count(HT));
	free(HT->table);
	free(HT);
}


/* CONVERTERS */
Item* hash_table_to_vector(Hash_Table HT)
{
	Item* vector = (Item*) malloc(sizeof(Item) * HT->count);
	int i, j = 0;
	
	for (i = 0; i < HT->size; i++)
		if (!IS_ITEM_NULL(HT->table[i]))
			vector[j++] = HT->table[i];
	
	return vector;
}
