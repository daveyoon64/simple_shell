#include "sfsh.h"


int sfsh_execute(char **args)
{
	int status = 1, i = 0, size = 0;
	typedef struct builtin
	{
		char *name;
		int (*function)(char **);
	} builtin_t;
	
	builtin_t builtins[] = {
		{"help", sfsh_help},
		{"exit", sfsh_exit},
		{"env", sfsh_env},
	};

	size = (sizeof(builtins) / (sizeof(char *) * 2)) - 1;

	for (i = 0; i < size; i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			return (builtins[i].function(args));
		}
	}

	/* No builtins found, search path and run matching executable */
	return (sfsh_launch(args));
}
