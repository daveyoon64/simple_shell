#ifndef SFSH_H_
#define SFSH_H_

extern char **environ;

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <dirent.h>

#include "sfsh_debug.c"
#include "sfsh_string_helpers.c"
#include "sfsh_helpers.c"
#include "sfsh_launch.c"
#include "sfsh_builtins0.c"
#include "sfsh_getline.c"
#include "sfsh_tokenize.c"
#include "sfsh_execute.c"
#include "sfsh_loop.c"





void sfsh_loop(int argc, char *argv[]);
char *sfsh_getline(void);
char **sfsh_tokenize(char *line, int number_of_arguments);
int sfsh_execute(char **args);
int sfsh_launch(char **args);

/* built-ins */
int sfsh_help(char **args);
int sfsh_exit(char **args);

/* helpers */
char **get_path();


#endif /* end of SFSH_H_ header guard */
