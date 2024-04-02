#include "main.h"

/**
*split_line - tokenizer
*
*@line: input
*
*Return:
*/

char** split_line(char *line)
{
	int buffer = MAX_INPUT, pos = 0;
	char **tokens = malloc(buffer * sizeof(char*));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIMITERS);

	while (token != NULL)
	{
		tokens[pos++] = token;
	
		if (pos >= buffer)
		{
			buffer += MAX_INPUT;
			tokens = realloc(tokens, buffer * sizeof(char*));

			if (!tokens)
			{
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMITERS);
	}
	tokens[pos] = NULL;

	return (tokens);
}

