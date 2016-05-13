#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_ 

#include <stdio.h>
#include <stdlib.h>
#include "hash_table_item.h"

/*
 * This Header constains all includes, defines and structs that
 * belong only to hash_table that won't need to be changed
 * in case the Item type is changed, for that check
 * hash_table_item.h / c files 
 */


/* Recommended JUMP function, works better 
 * when table's size is a power of 2 */
#define TABLE_JUMP(A) (A*A + A)/2

/* tested with public examples as the combination
 * that provided the fastest output */
#define HASHTABLE_EXPANSION_THRESHOLD 0.7
/* keep size a power of 2 so JUMP functions works better */
#define HASHTABLE_EXPANSION_VALUE 4 



/* STRUCTURES */
typedef struct HashTable{
	int size;
	int count;
	Item *table;
}* Hash_Table;





/* CONSTRUCTORS */
void init_hash_table_table(Hash_Table HT);
/*
 * initializes the hash table's table with NULLITEMs
 * :: input: Hash_Table (Pointer to hashtable's structure) 
 */

Hash_Table init_hash_table(int table_size);
/*
 * allocates memory and initializes an hashtable's elements
 * :: input: int with size for a table
 * -> returns Hash_Table (Pointer to stucture) (initialized) 
 */




/* MODIFIERS */
void insert_hash_table(Hash_Table HT, Item item);
/*
 * insert's the item in the Hash_Table's Table 
 * and increase's Hash_Table's element counter
 * if the Hash_Table's count surpasses the EXPANSION_THRESHOLD,
 * it expands the Hash_Table's Table
 * :: input: Hash_Table (pointer to struct), Item;
 */

void expand_hash_table(Hash_Table HT);
/*
 * Modifies Hash_Table's Table to increase it's size
 * :: input:  Hash_Table
 */




/* SELECTORS */
Item search_hash_table(Hash_Table HT, Item item);
/*
 * searches Item in Hash_Table and return's it's pointer
 * in case item isn't in table, returns NULLITEM
 * :: input: Hash_Table(struct_ptr), Item;
 * -> return: Found Item or NULLITEM
 */

int hash_table_item_count(Hash_Table HT);
/*
 * return's Hasht_Table's item count
 * :: input: Hash_Table
 * -> return: int (Hash_Table's item counter)
 */




/* DESTRUCTORS */
void destroy_hash_table(Hash_Table HT);
/*
 * Destroy's Hash_Table (Free's all the pointers) 
 * :: input: Hash_Table
 */




/* CONVERTER */
Item* hash_table_to_vector(Hash_Table HT);
/*
 * places all the non Null Items in a vector/array
 * :: input: Hash_Table
 * -> return: pointer to an Item vector/array
 */


#endif
