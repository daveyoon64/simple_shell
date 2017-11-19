#include "sfsh.h"
/**
 * sfsh_env - prints the current environment
 * @args: pointer to array of tokens
 * Return: 1 on success
 */
int sfsh_env(char **args)
{
	int i = 0;
	int len = 0;

	(void) args;
	while (environ[i])
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(1, "\n", 1);
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
	char *line = "|-----------------------------------------------|\n";
	char *name = "| Name\t| Description\t\t\t\t|\n";
	char *help = "| help\t| This document\t\t\t\t|\n";
	char *env = "| env\t| Prints out the system environment\t|\n";
	char *exit = "| exit\t| Exit Super Friendship shell\t\t|\n";

	(void) args;
	write(1, line, _strlen(line));
	write(1, name, _strlen(name));
	write(1, line, _strlen(line));
	write(1, help, _strlen(help));
	write(1, env, _strlen(env));
	write(1, exit, _strlen(exit));
	write(1, line, _strlen(line));
	return (1);
}
/**
 * sfsh_exit - function to exit sfsh
 * @args: pointer to array of tokens
 * Return: 0
 */
int sfsh_exit(char **args)
{
	char *msg = "Leaving Super Friendship Shell. Your loss\n";

	(void) args;
	write(1, msg, _strlen(msg));
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
	(void) args;
	return (1);
}
