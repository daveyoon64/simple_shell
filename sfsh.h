#ifndef SFSH_H_
#define SFSH_H_
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void sfsh_loop(int argc, char *argv[]);
char *sfsh_getline(void);
char **sfsh_tokenize(char *line);
int sfsh_execute(char **args);

#endif /* end of SFSH_H_ header guard */
