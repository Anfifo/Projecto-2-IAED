#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_ 

#include <stdio.h>
#include <stdlib.h>
#include "hash_table_item.h"

/* HT stands for hashtable */


/* JUMP function recommended to allow more of the table to
 * be filled, works better when hashtable's size is a power of 2 */
#define TABLE_JUMP(A) (A*A + A)/2

/* tested with public examples as the combination
 * that provided the fastest output */
#define HASHTABLE_EXPANSION_THRESHOLD 0.7
#define HASHTABLE_EXPANSION_VALUE 4 /*jump function works better when size is a power of 2 */


typedef struct HashTable{
	int size;
	int count;
	Item *table;
}* Hash_Table;

void init_hash_table_table(Hash_Table HT);
Hash_Table init_hash_table(int table_size);

void insert_hash_table(Hash_Table HT, Item item);

Item search_hash_table(Hash_Table HT, Item item);
int hash_table_item_count(Hash_Table HT);

void expand_hash_table(Hash_Table HT);
void destroy_hash_table(Hash_Table HT);

Item* hash_table_to_vector(Hash_Table HT);

#endif
