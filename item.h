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

extern Item* Vector_Elementos;
extern Item Most_Popular_Item;

Item create_item(char*);
void print_item(Item);
void print_item_vector(Item* vector, int size);
int compare_items(Item, Item);
void increment_item_counter(Item);
void delete_item(Item);

#endif