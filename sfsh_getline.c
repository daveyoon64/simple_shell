#include "sfsh.h"
/**
 * sfsh_getline - get the command as one large string
 * @void: no args
 * Return: pointer to the string
 */
char *sfsh_getline(void)
{
	/* line is still reachable in valgrind if 'enter' as input */
	char *line = NULL;
	size_t b_size = 0;
	int i = 0;

	printf("($)");
	getline(&line, &b_size, stdin);
	if (_strcmp(line, "\n") == 0)
	{
		/* checks condition when enter is pressed */
		free(line);
		return (NULL);
	}	
	while (line[i])
	{
		i++;
	}
	if (i <= 1)
	{
		fflush(stdin);
		line = "";
	}
	return (line);
}
