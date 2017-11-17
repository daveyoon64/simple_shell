#include "sfsh.h"
/**
 * sfsh_loop - the loop of the Super Friendship Shell
 * @argc: number of args
 * @argv: pointer to string array
 * Return: void
 */
void sfsh_loop(int argc, char *argv[])
{
	char *line = NULL;
	char **tokens;
	int status = 1, arg_num;

	int i = 0;

	do {
		line = sfsh_getline();
		tokens = sfsh_tokenize(line);
		status = sfsh_execute(tokens);

		if (line != "")
		{
			free(line);
		}
		else
		{
			printf("cleanup\n");

		}

		free(tokens);

	} while (status);
}
