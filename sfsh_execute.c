#include "sfsh.h"


int sfsh_execute(char **args)
{
	int status = 1, i = 0;
	typedef struct builtin
	{
		char *name;
		int (*function)(char **);
	} builtin_t;


	builtin_t builtins[] = {
		{"help", hsh_help},
		{"exit", hsh_exit}
	};

	for (i = 0; i < 2; i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			return (builtins[i].function(args));
		}


	}

	return (0);
}
