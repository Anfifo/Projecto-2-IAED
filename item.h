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

void increment_item_counter(Item);

Item get_most_popular_item();

int compare_items(Item, Item);
int compare_item_count(const Item, const Item);



void destroy_item(Item);
void destroy_item_vector(Item* , int);

void update_most_popular_item(Item);

void print_item(Item);
void print_item_vector(Item*, int);


int sorting_compare_items(const void*, const void*);
void sort_item_vector(Item*, int);

#endif