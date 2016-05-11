#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_ 

#include <stdio.h>
#include <stdlib.h>
#include "hash_table_item.h"

/* HT stands for hashtable */


#define TABLE_JUMP(A) (A*A + A)/2


typedef struct HASHTABLE{
	int size;
	int count;
	Item *table;
}* Hash_Table;


Hash_Table init_hash_table(int table_size);
void insert_hash_table(Hash_Table HT, Item item);
Item search_hash_table(Hash_Table HT, Item item);
void expand_hash_table(Hash_Table HT);
Item* hash_table_to_vector(Hash_Table HT);
int hash_table_item_count(Hash_Table HT);
void sort_item_vector(Item* vector, int item_count);



#endif
