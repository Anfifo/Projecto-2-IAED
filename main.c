#include <stdio.h>

#include "commands.h"

/* for this project, max size of a string is 140+'\0' */
#define MAXSIZE (140 + 1) 
/* hashtable's jump works better with size being a power of 2 */
#define HASH_TABLE_STARTING_SIZE 64 


Hash_Table HT;


int main()
{
	HT = init_hash_table(HASH_TABLE_STARTING_SIZE);
	char command;
	char line[MAXSIZE];

	while ((command = getchar()))
	{
		getchar();
		switch (command)
		{
			case 'a':
				fgets(line, MAXSIZE, stdin);
				command_a(line);
				break;

			case 's':
				command_s();
				break;

			case 'm':
				command_m();
				break;

			case 'l':

				command_l();
				break;

			case 'x':
				command_x();
				return 0;

			default:
				printf("unknown command: %c\n", command);
		}
	}
	return 0;
}







