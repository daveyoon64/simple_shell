#include "sfsh.h"
extern char **environ;

/**
 * sfsh_env - prints the current environment
 * @args: pointer to array of tokens
 * Return: 1 on success
 */

int sfsh_env(char **args)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (1);
}

/**
 * sfsh_help - displays help
 * @args: pointer to array of tokens
 * Return: 1 if runs
 */

int sfsh_help(char **args)
{
 	int i;
	int builtin_amount = 2;


	printf("List of built-ins\n");

	return (1);
}

/**
 * sfsh_exit - function to exit sfsh
 * @args: pointer to array of tokens
 * Return: 0
 */

int sfsh_exit(char **args)
{
	printf("Leaving Super Friendship Shell.  Your loss\n");
	return (0);
}

/**
 * sfsh_error    - Triggered if user enters no input
 *
 * @args:          pointer to array of tokens
 *
 * Return:         1
 */

int sfsh_error(char **args)
{
	printf("Give me something to do!\n");

	return (1);
}
