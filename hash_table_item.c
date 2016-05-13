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

#include "hash_table_item.h"



Key item_to_key(Item item)
{
	return item->tag;
} 

/* djb2 (edited to work better in this case)
 * an algorithm that was recommended
 * to be used when hashing strings
 * this algorithm (k=33) was first reported by 
 * dan bernstein many years ago in comp.lang.c. */
unsigned long string_hash(char *str, int size)
{
	unsigned long hash = 5381; /* magic constant */
	int c;

	while ((c = *str++))
	    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */ 
	
	return hash%(size-1); /* -1 because the size is usually a power of 2 */
}
