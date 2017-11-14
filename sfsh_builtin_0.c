#include "sfsh.h"


int sfsh_help(char **args)
{
	int i;
	printf("My have to remove printf and use custom printf\n");
	printf("This is our help file\n");
	printf("Here's a list of our built-ins: \n");

	for (i = 0; i < sfsh_num_builtins(); i++)
		printf(" %s\n", 
	
}
/**
 * sfsh_exit - function to exit our shell
 * @args: pointer to string array
 */
int sfsh_exit(char **args)
{
	return (0);
}
