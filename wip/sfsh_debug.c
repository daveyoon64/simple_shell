#include "sfsh.h"

void print_id(char *name)
{
	printf("============= print id debug ==============\n");
	printf("[%s] My ID is %d\n", name, getpid());
	printf("[%s] My parent ID is %d\n", name, getppid());
}

void print_args(char **args, char *desc)
{
	int i = 0;

	printf("&&&&&&&&&&&& [   %s    ] &&&&&&&&&&&&&&&\n", desc);
	for (i = 0; args[i] != NULL; i++)
	{
		printf("arg %d is %s\n", i, args[i]);
	}
}
