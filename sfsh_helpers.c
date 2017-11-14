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
	int i = 1, match = 1;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == ' ')
		{
			match++;
		}
	}

	return (match);
}



