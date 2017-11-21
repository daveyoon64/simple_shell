#include "sfsh.h"


void update_pwd(char *cwd)
{
	int i = 0, j = 0, length;
	char *magic_path;
	char *prefix = "OLDPWD=";

	length = _strlen(cwd) + 7;
	magic_path = malloc(sizeof(char) * length);

	for (i = 0; i < length; i++)
	{
		if (i < _strlen(prefix))
		{
			magic_path[i] = prefix[i];
		}
		else
		{
			magic_path[i] = cwd[j];
			j++;
		}
	}
	magic_path[i] = '\0';
	i = 0;

	while (environ[i])
	{
		if (_strncmp("OLDPWD=", environ[i], 7) == 0)
		{
			environ[i] = magic_path;
			break;
		}
		i++;
	}
}
/**
 * sfsh_cd       - Changes current directory to first element of @args
 *
 * @args:          @args[1] will be destination directory to change to
 *
 * Return:         (1) Success
 */
int sfsh_cd(char **args)
{
	int i = 0;
	char *target;
	char cwd[128];

	while (args[++i])
		;
	if (i < 2)
	{
		i = 0;
		while (environ[i])
		{
			if (_strncmp("HOME=", environ[i], 5) == 0)
			{
				target = environ[i];
				break;
			}
			i++;
		}
		target += 5;
		getcwd(cwd, sizeof(cwd));
		update_pwd(cwd);
		if (chdir(target) != 0)
			perror("");
	}
	else
	{
		if (args[1][0] == '-')
		{
			i = 0;
			while (environ[i])
			{
				if (_strncmp("OLDPWD=", environ[i], 7) == 0)
				{
					target = environ[i];
					break;
				}
				i++;
			}
			target += 7;
			getcwd(cwd, sizeof(cwd));
			update_pwd(cwd);
			if (chdir(target) != 0)
				perror("");
		}
		else
		{
			getcwd(cwd, sizeof(cwd));
			update_pwd(cwd);
			if (chdir(args[1]) != 0)
				perror("");
		}
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
	int i = 0, length = 0, new_entry = 0;
	char *new_value;

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
	new_value = malloc(_strlen(args[0]) + _strlen(args[1]) + 2);
	_strcpy(new_value, args[1]);
	_strcpy(&new_value[_strlen(new_value)], "=");
	_strcpy(&new_value[_strlen(new_value)], args[2]);
	i = 0;
	while (environ[i])
	{
		if (_strncmp(args[1], environ[i], length) == 0)
		{
			environ[i] = new_value;
			new_entry = 1;
		}
		i++;
	}
	if (new_entry == 0)
	{
		environ[i++] = new_value;
		environ[i] = NULL;
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
