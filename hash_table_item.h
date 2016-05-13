#ifndef _HASH_TABLE_ITEM_
#define _HASH_TABLE_ITEM_ 

#include "item.h"

/* 
 * this file hash_table_item.h is responsible for making
 * the connection between the hastable and the item
 * in case of input/item change only this file should change
 */ 


#define KEY(A) (item_to_key(A))
/* abstraction for function that turns item into key */

#define HASH(A,B) (string_hash(A,B))
/* abstraction for the hashing function */

#define HASHTABLE_DESTROY_ITEM_VECTOR(A,B) destroy_item_vector(A,B)
/* abstraction for function that destroys an item vector */


/* Types */
typedef char* Key;
/* changing the type of the key */



/* KEY CONVERTER FUNCTION */
Key item_to_key(Item item);
/* 
 * finds something unique for the item so that is used to hash
 * :: input: Item
 * -> return: Key - Type that will be used to generate hash's position 
 */ 


/* HASHING FUNCTION */
unsigned long string_hash(char *str, int size);
/* 
 * djb2 (edited to work better on this case)
 * an algorithm that was recommended
 * to be used when hashing strings
 * this algorithm (k=33) was first reported by 
 * dan bernstein many years ago in comp.lang.c. 
 *
 * converts string into interger
 * :: input: string/key
 * -> return: int (hashing position)
 */

#endif