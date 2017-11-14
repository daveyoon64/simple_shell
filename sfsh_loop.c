#include "sfsh.h"
/**
 * sfsh_loop - the loop of the Super Friendship Shell
 * @argc: number of args
 * @argv: pointer to string array
 * Return: void
 */
void sfsh_loop(int argc, char *argv[])
{
	char *line;
	char **tokens;
	int status;

	(void) argc;
	(void) argv;
	do {
		line = sfsh_getline();
		tokens = sfsh_tokenize(line);
		status = sfsh_execute(tokens);
	} while (status);
}
