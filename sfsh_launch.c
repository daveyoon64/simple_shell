#include "sfsh.h"
//extern char **environ;

int sfsh_launch(char **args)
{
	pid_t pid, wpid;
	int status, i = 0;
	char **dirs;
	char *command;
	struct dirent *p_Dirent;
	DIR *p_dir;
	char slash;

	/* allocate memory for 'dirs' to hold array of path directories */
	dirs = malloc(sizeof(char *) * 32);
	if (!dirs)
	{
		printf("Error allocating memory\n");
	}
	dirs = get_path();

	pid = fork();
	if (pid == 0)
	{
		slash = args[0][0];
		/* given full path, run as is */
		if (slash == '/')
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error launcher:");
			}
			free(args);
			free(dirs);
			exit(102);
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
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(dirs);
	free(args);

	return (1);
}
