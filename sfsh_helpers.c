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
/**
 * strcmp - compare two strings
 * @s1: the first string
 * @s2: the second string
 * Return: 0 if the same, positive/negative value otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int s1d, s2d;

	do {
		s1d = *s1++;
		s2d = *s2++;
		if (s1d == '\0')
			return (s1d -s2d);
	} while (s1d == s2d);
	return (s1d - s2d);
}
