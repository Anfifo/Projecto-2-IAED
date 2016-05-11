#ifndef _HASH_TABLE_ITEM_
#define _HASH_TABLE_ITEM_ 

#include "item.h"

/* to change the input of the hash table, simply change this file */ 
#define KEY(A) (item_to_key(A))
#define HASH(A,B) (string_hash(A,B))

typedef char* Key;

Key item_to_key(Item item);

/* djb2
 * an algorithm that was recommend
 * to be used when hashing strings
 * this algorithm (k=33) was first reported by 
 * dan bernstein many years ago in comp.lang.c. */

unsigned long string_hash(char *str, int size);

#endif