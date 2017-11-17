#include "sfsh.h"

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


/**
 * get_path   - Returns the path from the environment
 *
 * Return:      The path from the environment as a string
 */

/*
char **get_path()
{
	char **dirs;
	char *path, *path_dupe;
	int i = 0;

	dirs = malloc(sizeof(char *) * 32);
	if (!dirs)
	{
		printf("error allocating memory\n");
		exit(101);
	}

	while (environ[i])
	{
		if (_strncmp("PATH=", environ[i], 5) == 0)
		{
			path = environ[i];
			break;
		}
		i++;
	}

/*
	/* Make a copy of env path so as not to alter actual path */
/*	path_dupe = _strdup(path);
	path += 5;

	i = 0;
	path = strtok(path, ":");
	while (path != NULL)
	{
		dirs[i] = path;
		i++;
		path = strtok(NULL, ":");
	}

	for (i = 0; dirs[i] != '\0'; i++)
	{
		printf("list: %s\n", dirs[i]);
	}

	return (dirs);
}
*/
