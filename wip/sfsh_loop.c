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
//		arg_num = arg_count(line);
		tokens = sfsh_tokenize(line);
		status = sfsh_execute(tokens);

		if (line != "")
		{
			/* memory leak if 'enter' is user input. fix this */
			free(line);
		}
		free(tokens);

	} while (status);
}
