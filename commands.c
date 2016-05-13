#include "commands.h"

#define NUMSEP 11
static const char separators[] = {' ','\t',',',';','.','?','!','"','\n',':','\0'};
int total_hashtags_processed = 0;



void command_a(char *line)
{
	lowercase_transformer(line);
	split(line);
}

void command_s()
{
	printf("%d %d\n", hash_table_item_count(HT), total_hashtags_processed);
}

void command_m() 
{
	if (total_hashtags_processed > 0)
		print_item(get_most_popular_item());
}

void command_l()
{
	int item_count = hash_table_item_count(HT);
	Item* item_vector;

	item_vector = hash_table_to_vector(HT);
	sort_item_vector(item_vector, item_count);
	print_item_vector(item_vector, item_count);
	free(item_vector);
}

void command_x()
{
	destroy_hash_table(HT);
	return;
}




/* Auxiliar Functions */
void lowercase_transformer(char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
		if (line[i] >= 'A' && line[i] <= 'Z')
			line[i] -= ('A'-'a');
}



void split(char *line)
{
	char *token = strtok(line, separators);

	while(token!=NULL) 
	{
		process_hashtag(token);
		token = strtok(NULL, separators);
	}
}



void process_hashtag(char *token)
{
	Item item, test;
	if (token[0] == '#')
	{
		total_hashtags_processed++;

		item = create_item(token);
		test = search_hash_table(HT, item);

		if (IS_ITEM_NULL(test))
			insert_hash_table(HT, item);

		else
		{
			increment_item_counter(test);
			destroy_item(item);
		}
		
	}		
}


