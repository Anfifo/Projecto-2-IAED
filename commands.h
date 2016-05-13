#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "item.h"

extern int total_hashtags_processed;
extern Hash_Table HT;

void command_a(char*);
void command_s();
void command_m();
void command_l();
void command_x();

void lowercase_transformer(char*);
void split(char*);
void process_hashtag(char*);



#endif