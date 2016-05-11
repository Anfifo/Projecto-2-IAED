#include <stdio.h>
#include "hashtable.h"
#include "item.h"

#define MAXSIZE (140 + 1)
#define NUMSEP 11
static const char separators[] = {' ','\t',',',';','.','?','!','"','\n',':','\0'};

Hash_Table HT;
static int total_hashtag_count = 0;

void command_a(char*);
void command_s();
void command_m();
void command_l();
void command_x();
void lowercase_transformer(char*);
void split(char*);
void process_hashtag(char*);
void command_x();

int main()
{
	HT = init_hash_table(128);
	char command;
	char line[MAXSIZE];

	while ((command = getchar()))
	{
		puts("\twhile loop...");
		fgets(line, MAXSIZE, stdin);
		switch (command)
		{
			case 'a':
			puts("case a");
				command_a(line);
				break;

			case 's':
			puts("case s");
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
				printf("test\n");
		}
	}
	return 0;
}



void command_a(char *line)
{
	lowercase_transformer(line);
	split(line);
}

void command_s()
{
	printf("%d %d", hash_table_item_count(HT), total_hashtag_count);
}

void command_m() 
{
	print_item(Most_Popular_Item);
}

void command_l()
{
	int item_count = hash_table_item_count(HT);
	Item* item_vector;

	item_vector = hash_table_to_vector(HT);
	sort_item_vector(item_vector, item_count);
	print_item_vector(item_vector, item_count);
}

void command_x()
{
	printf("command x\n");
}


void lowercase_transformer(char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
		if (i >= 'A' && i <= 'Z')
			line[i] -= ('A'-'a');
}


void split(char *line)
{
	char *token = strtok(line, separators);

	while(token!=NULL) 
	{
		/* process aqui a palavra guardada em token */
		process_hashtag(token);
		token = strtok(NULL, separators);
	}

}

void process_hashtag(char *token)
{
	Item item, test;
	if (token[0] == '#')
	{
		total_hashtag_count++;

		item = create_item(token);
		test = search_hash_table(HT, item);

		if (IS_ITEM_NULL(test))
			insert_hash_table(HT, item);

		else
			increment_item_counter(test);		
	}		
}







/*
void find_hashtag(char *line)
{
	int i;
	for (i = 1; line[i] != '\0'; i++)
	{
		if (line[i-1] == ' ' && line[i] == '#')
	}
}
*/