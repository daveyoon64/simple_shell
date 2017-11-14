#ifndef SFSH_H_
#define SFSH_H_

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

#include "sfsh_builtins0.c"
#include "sfsh_helpers.c"
#include "sfsh_getline.c"
#include "sfsh_tokenize.c"
#include "sfsh_execute.c"
#include "sfsh_loop.c"
#include "sfsh_launch.c"



/**
 * builtin - data type for our built-in commads, paired with function pointers
 * @name: name of our built-in command
 * @f: function pointer of related command
 */
typedef struct builtin {
	char *name;
	int (*f)(args);
} builtin_t;



void sfsh_loop(int argc, char *argv[]);
char *sfsh_getline(void);
char **sfsh_tokenize(char *line, int number_of_arguments);
int sfsh_execute(char **args);
int sfsh_launch(char **args);

/* built-ins */
int sfsh_help(char **args);
int sfsh_exit(char **args);





/* built-ins */
int hsh_help(char **args);
int hsh_exit(char **args);





#endif /* end of SFSH_H_ header guard */
