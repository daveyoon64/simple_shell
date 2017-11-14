#include "sfsh.h"


int sfsh_execute(char **args)
{
	int i;
	builtin_t builtin[] = {
		{"cd", sfsh_cd},
		{"help", sfsh_help},
		{"exit", sfsh_exit},
		{NULL, NULL }
	};

	


	return (0);
}
