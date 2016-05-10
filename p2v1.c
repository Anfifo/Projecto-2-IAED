#include <stdio.h>

#define MAXSIZE (140 + 1)
#define NUMSEP 11
static const char separators[] = {' ','\t',',',';','.','?','!','"','\n',':','\0'};

Hash_Table HT = init_hash_table(128);
static int total_hashtag_count = 0;


int main()
{
	char command;
	char *line;

	while (command = getchar())
	{
		fgets(line, MAXSIZE, stdio);
		switch (command)
		{
			case 'a':

				command_a();
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
				break;

				return;

			default:
				printf("test\n");

		}
	}
}



void command_a(char *line)
{
	lowercase_transformer(line);
	split(line);
}

void command_s()
{
	printf("%d %d", hash_table_size(HT), total_hashtag_count);
}

void command_m() 
{
	print_item(Most_Popular_Item);
}

void command_l()
{
	Item* item_vector;
	item_vector = hash_table_to_vector(HT);
	qsort();
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

process_hashtag(char *token)
{
	Item item;
	if (token[0] == '#')
	{
		total_hashtag_count++;

		item = create_item(token);
		test = search_hash_table(HT, item);

		if (IS_ITEM_NULL(test))
			insert_hash_table(HT, test);

		else
			increment_item_counter(item);		
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