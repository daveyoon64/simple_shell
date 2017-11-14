#include "sfsh.h"
#define DELIM " \t\r\n"

/**
 * sfsh_tokenize        - Split @line into tokens and store in an array
 *
 * @line:                 User input stored as a string
 * @number_of_arguments:  How many tokens we are splitting @line into
 *
 * Return:                pointer to the string
 */



char **sfsh_tokenize(char *line, int number_of_arguments)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char*) *number_of_arguments);

	if (tokens == NULL)
	{
		printf("Failure to allocate\n");
		exit(101);
	}

	token = strtok(line, DELIM);

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, DELIM);
	}

	return (tokens);
}
