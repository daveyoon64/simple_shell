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
	printf("exiting id: %d\n", getpid());
	printf("exiting parent id: %d\n", getppid());
	return (0);
}


