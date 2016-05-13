#ifndef _ITEM_H_
#define _ITEM_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct hashtag{
	char* tag;
	int count;
}*Item;



#define NULLITEM NULL 
#define IS_ITEM_NULL(A) (A == NULLITEM)
#define EQUAL_ITEM(A,B) (compare_items(A,B)==0)


Item create_item(char*);
/*
 * allocs memory for the table's items and their hashtags 
 * and updates the most popular item.
 * :: input: char*
 * :: output: Item
 */

void increment_item_counter(Item);
/*
 * increments an item's counter if needed and checks
 * if the most popular item needs updating.
 * :: input: Item item
 * :: output: no output
 */

Item get_most_popular_item();
/*
 * returns the current most popular item.
 * :: input: no input
 * :: output: returns Item (Most_Popular_Item)
 */

int compare_items(Item, Item);
/*
 * compares item1 and item2's hashtags and returns the compare value between them.
 * positive if the second is smaller than the first, negative if the second
 * is bigger than the first and 0 if they're equal.
 * :: input: Item item1, Item item 2
 * :: output: returns (value of the comparison)
 */

int compare_item_count(const Item, const Item);
/*
 * compares item1 and item2's counters and returns the compare value between them.
 * positive if the second is smaller than the first, negative if the second
 * is bigger than the first and 0 if they're equal.
 * :: input: Item item1, Item item 2
 * :: output: returns int (value of the comparison)
 */


void destroy_item(Item);
/*
 * free's the item's allocated memory, starting with the hashtag and then 
 * with the hashtable's position.
 * :: input: Item item
 * :: output: no output
 */

void destroy_item_vector(Item* , int);
/*
 * free's the item's vector and then free's the vector's pointer itself.
 * :: input: Item vector, int size
 * :: output: no output
 */

void update_most_popular_item(Item);
/*
 * compares the most popular item with given item and updates the most
 * popular item if needed. 
 * :: input: Item item
 * :: output: no output
 */

void print_item(Item);
/*
 * prints item's hashtag and count.
 * :: input: Item item
 * :: output: prints Item item
 */

void print_item_vector(Item*, int);
/*
 * prints a vector with every item of the hashtable.
 * :: input: Item* vector, int size
 * :: output: prints vector
 */


int sorting_compare_items(const void*, const void*);
/*
 * converts 2 voids into items and compares them.
 * :: input: void*, void*
 * :: output: returns int (value of the comparison)
 */
void sort_item_vector(Item*, int);
/*
 * sorts item vector.
 * :: input: Item*, int
 * :: output: no output
 */

#endif