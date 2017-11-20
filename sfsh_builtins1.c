#include "sfsh.h"

/**
 * sfsh_cd       - Changes current directory to first element of @args
 *
 * @args:          @args[1] will be destination directory to change to
 *
 * Return:         (1) Success
 */
int sfsh_cd(char **args)
{
	if (chdir(args[1]) != 0)
	{
		perror("");
	}



	return (1);
}
/**
 * sfsh_setenv   - Sets or updates an entry in the environment
 *
 * @args:          @args[1] is the name of the environment variable
 *                 @args[2] is the new value for @args[1]
 *                 @args[3] None-zero overwrite, zero to not overwrite
 *
 * Return:         (1) Success
 */
int sfsh_setenv(char **args)
{
	int i = 0, length = 0;
	char *new_env;

	/* check for proper number of arguments, else return */
	while (args[++i])
		;

	if (i != 4 || args[3] == 0)
	{
		printf("Wrong arg count\n");
		return (1);
	}

	/* ensure no '=' for proper syntax processing */
	for (length = 0; args[1][length] != '\0'; length++)
	{
		if (args[1][length] == '=')
		{
			printf("Incorrect format\n");
			return (1);
		}
	}

	new_env = malloc(_strlen(args[0]) + _strlen(args[1]) + 2);
	_strcpy(new_env, args[1]);
	_strcpy(&new_env[_strlen(new_env)], "=");
	_strcpy(&new_env[_strlen(new_env)], args[2]);

	i = 0;
	while (environ[i])
	{
		if (_strncmp(args[1], environ[i], length) == 0)
		{
			environ[i] = new_env;
		}
		i++;
	}

	return (1);
}
/**
 * sfsh_unsetenv - Deletes an entry in the environment
 *
 * @args:          @args[1] The entry to be deleted from the environment
 *
 * Return:         (1) Success
 */
int sfsh_unsetenv(char **args)
{
	int i = 0, length = 0, j = 0;
	char **new_env;

	/* check for proper number of arguments, else return */
	while (args[++i])
		;
	if (i != 2)
	{
		printf("wrong arg count\n");
		return (1);
	}
	/* ensure no '=' for proper syntax processing */
	for (length = 0; args[1][length] != '\0'; length++)
	{
		if (args[1][length] == '=')
		{
			printf("Incorrect format\n");
			return (1);
		}
	}
	i = 0;
	while (environ[++i])
		;
	new_env = malloc(sizeof(char *) * i);
	i = 0;
	length = _strlen(args[1]);
	while (environ[i])
	{
		if (_strncmp(args[1], environ[i], length) == 0)
			j--;
		else
		{
			new_env[j] = environ[i];
		}
		i++;
		j++;
	}
	environ = new_env;
	return (1);
}
