#include "sfsh.h"
/**
 * sfsh_getline - get the command as one large string
 * @void: no args
 * Return: pointer to the string
 */
char *sfsh_getline(void)
{
	/* line is not freed on return, still reachable in valgrind */
	char *line = NULL;
	size_t b_size = 0;
	int i = 0;

	printf("($)");
	getline(&line, &b_size, stdin);

	while (line[i]){
		i++;
	}

	if (i <= 1)
	{
		line = "";
	}

	return (line);
}
