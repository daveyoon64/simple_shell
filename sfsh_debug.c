#include "sfsh.h"

void print_id(char *name)
{
	printf("============= print id debug ==============\n");
	printf("[%s] My ID is %d\n", name, getpid());
	printf("[%s] My parent ID is %d\n", name, getppid());
}
