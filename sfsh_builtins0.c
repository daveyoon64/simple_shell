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
	printf("|-----------------------------------------------|\n");
	printf("| Name\t| Description\t\t\t\t|\n");
	printf("|-------|---------------------------------------|\n");
	printf("| help\t| This document\t\t\t\t|\n");
	printf("| env\t| Prints out the system environment\t|\n");
	printf("| exit\t| Exit Super Friendship shell\t\t|\n");
	printf("|-----------------------------------------------|\n");

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
	printf("Please enter a command\n");

	return (1);
}
