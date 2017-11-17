#include "sfsh.h"

/**
 * get_path   - Returns the path from the environment
 *
 * Return:      The path from the environment as a string
 */

char **get_path(void)
{
	char **dirs;
	char *path = NULL;
	int i = 0;
	char temp[150];

	dirs = malloc(sizeof(char *) * BUFFER_SIZE);
	if (!dirs)
	{
		printf("Error allocating memory\n");
	}

	while (environ[i])
	{
		if (_strncmp("PATH=", environ[i], 5) == 0)
		{
			path = _strcpy(temp, environ[i]);
			break;
		}
		i++;
	}
	printf("path %s\n", path);
	path += 5;
	i = 0;

	path = strtok(path, ":");
	while (path != NULL)
	{
		dirs[i] = path;
		printf("added %s\n", dirs[i]);
		i++;
		path = strtok(NULL, ":");
	}
	dirs[i] = NULL;

	printf("last token: %s\n", path);

	for (i = 0; dirs[i] != '\0'; i++)
	{
		printf("list: %s\n", dirs[i]);
	}

	return (dirs);
}

/**
 * arg_count      - Count how many sections @line can be broken into
 *
 * @line:           User input stored as a string
 *
 * Return:          How many tokens @line was broken into
 */

int arg_count(char *line)
{
	int i = 0, match = 1;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == ' ')
		{
			match++;
		}
	}

	return (match);
}

