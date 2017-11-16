#include "sfsh.h"

#define BUFFER_SIZE 32

int sfsh_launch(char **args)
{
	pid_t pid, wpid;
	int status, i = 0;
	char **dirs;
	char *command;
	struct dirent *p_Dirent;
	DIR *p_dir;

	/* allocate memory for 'dirs' to hold array of path directories */
	dirs = malloc(sizeof(char *) * BUFFER_SIZE);
	if (!dirs)
	{
		printf("Error allocating memory\n");
	}
	dirs = get_path();

	pid = fork();
	if (pid == 0)
	{
		/* given full path, run as is */
		if (args[0][0] == '/')
		{
			free(dirs);
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error launcher:");
			}
		}

		for (i = 0; dirs[i] != '\0'; i++)
		{
			p_dir = opendir(dirs[i]);

			while ((p_Dirent = readdir(p_dir)) != NULL)
			{
				if (_strcmp(p_Dirent->d_name, args[0]) == 0)
				{
					command = cmdcat(dirs[i], args[0]);
					if (execve(command, args, NULL) == -1)
					{
						perror("Error launcher:");
					}
				}
			}
			closedir(p_dir);
		}
	}
	else if (pid < 0)
	{
		perror("Error forking");
	}
	else
	{
		wait(&status);
		printf("returning to parent with id %d\n", getppid());
//		do {
//			wpid = waitpid(pid, &status, WUNTRACED);
//		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(dirs);
	free(args);

	return (1);
}
