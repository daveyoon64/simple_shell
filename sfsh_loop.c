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
	int status = 1;

	(void) argc;
	(void) argv;
	do {
		line = sfsh_getline();
		tokens = sfsh_tokenize(line);
		status = sfsh_execute(tokens);

		if (status == 1)
		{
			/* when 1, line has already been freed */
			free(tokens);
		}
		else
		{
			free(line);	
			free(tokens);
		}
	} while (status);
}
