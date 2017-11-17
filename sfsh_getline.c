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
	char **temp;
	size_t b_size = 0;
	int i = 0;

	printf("($)");
	getline(&line, &b_size, stdin);

	while (line[i])
	{
		i++;
	}

	if (i <= 1)
	{
		line = "";
	}

	return (line);
}
