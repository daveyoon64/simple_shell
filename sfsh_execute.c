#include "sfsh.h"
/**
 * sfsh_execute - search builtins for function to execute & send to sfsh_launch
 * @args: pointer to list of arguments
 * Return: 1 if successful
 */
int sfsh_execute(char **args)
{
	int i = 0, size = 0;
	char temp[150];
	char *path = NULL;
	char **dirs;

	builtin_t builtins[] = {
		{"help", sfsh_help},
		{"exit", sfsh_exit},
		{"env", sfsh_env},
		{"", sfsh_error}
	};
	dirs = malloc(sizeof(char *) * BUFFER_SIZE);
	if (!dirs)
	{
		printf("Malloc error in execute\n");
		exit(101);
	}
	size = (sizeof(builtins) / (sizeof(char *) * 2));
	for (i = 0; i < size; i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
		{
			/* Running found matching builtin */
			free(path);
			free(dirs);
			return (builtins[i].function(args));
		}
	}
	/* No matching builtins, search for program in path */
	while (environ[i])
	{
		if (_strncmp("PATH=", environ[i], 5) == 0)
		{
			path = _strcpy(temp, environ[i]);
			break;
		}
		i++;
	}
	path += 5;
	i = 0;
	path = strtok(path, ":");
	while (path != '\0')
	{
		dirs[i] = path;
		i++;
		path = strtok(NULL, ":");
	}
	dirs[i] = '\0';
	free(path);
	/* No builtins found, search path and run matching executable */
	sfsh_launch(args, dirs);
	free(dirs);
	return (1);
}
