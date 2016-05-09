#ifndef _ITEM_H_
#define _ITEM_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct testItem{
	char* random;
	int chair;
}*Item;



#define NULLITEM NULL 
#define IS_ITEM_NULL(A) (A == NULLITEM)
#define EQUAL_ITEM(A,B) (KEY(A) == KEY(B))

Item create_item(char*);
void print_item_vector(Item* vector, int size);



#endif