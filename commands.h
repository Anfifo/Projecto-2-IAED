#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "item.h"

extern int total_hashtags_processed;
extern Hash_Table HT;

void command_a(char*);
/*
 * receives a message with a maximum of 140 characters, processes its hashtags
 * and saves them on the hashtable along with its counter.
 * :: input: char <message>
 */
void command_s();
/*
 * prints the number of hashtags existent on the hastable and the sum of their
 * counters.
 * :: no input
 */
void command_m();
/*
 * prints the most popular hashtag according to its counter, if equal prints
 * the smallest alphabetically. 
 * :: input: no input
 */
void command_l();
/*
 * lists all the hashtags on the hashtable sorted in a descending order
 * according, if equal prints them alphabetically.
 * :: input: no input
 */
void command_x();
/*
 * exits the program.
 * :: input: no input
 */

/* -- Auxiliar Functions -- */

void lowercase_transformer(char*);
/*
 * receives a message with a maximum of 140 characters and if there are
 * any uppercase letters it transforms them into lowercase letters.
 * :: input: char <message>
 */
void split(char*);
/*
 * receives a message with a maximum of 140 characters and it splits
 * every word of the string into single tokens.
 * :: input: char <message>
 */
void process_hashtag(char*)
/*
 * receives split's tokens and checks whether they are hashtags. 
 * if they are inserts them on the hashtable.
 * :: input: char <message>
 */;



#endif