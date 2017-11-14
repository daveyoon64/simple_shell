#include "sfsh.h"
/**
 * sfsh_getline - get the command as one large string
 * @void: no args
 * Return: pointer to the string
 */
char *sfsh_getline(void)
{
	char *line = NULL;
	size_t b_size = 0;

	getline(&line, &b_size, stdin);
	return (line);
}
