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
	int status, arg_num;

	(void) argc;
	(void) argv;
	do {
		line = sfsh_getline();
		arg_num = arg_count(line);
		tokens = sfsh_tokenize(line, arg_num);
		status = sfsh_execute(tokens);
	} while (status);
}
