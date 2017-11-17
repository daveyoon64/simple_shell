#include "sfsh.h"

/**
 * get_path   - Returns the path from the environment
 *
 * @dest:       E
 *
 * Return:      The path from the environment as a string
 */

char *get_path(char *dest)
{
	int i = 0;
	char temp[150];

	while (environ[i])
	{
		if (_strncmp("PATH=", environ[i], 5) == 0)
		{
			dest = _strcpy(temp, environ[i]);
			break;
		}
		i++;
	}

	return (dest);
}

