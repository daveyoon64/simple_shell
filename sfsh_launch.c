#include "sfsh.h"

int sfsh_launch(char **args, char **dirs)
{
	int status = 1, i = 0;
	struct dirent *p_file;
	DIR *p_dir;
	pid_t pid;
	char *command = NULL;

	pid = fork();
	if (pid == 0)
	{
		/* Given full path to run program */
		if (args[0][0] == '/')
		{
//			printf("@@@@@@@ Operation Sad Cronut @@@@@@@\n");			
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error launching dir/prog\n");
			}
		}

		/* Given only program name, search path */
		for(i = 0; dirs[i] != '\0'; i++)
		{
			p_dir = opendir(dirs[i]);
			while ((p_file = readdir(p_dir)) != NULL)
			{
				if (_strcmp(p_file->d_name, args[0]) == 0)
				{
//					printf("!!!!! We're go for Azerbaijan !!!!!\n");					
					command = cmdcat(dirs[i], args[0]);
					if (execve(command, args, NULL) == -1)
					{
						perror("Error finding program in path\n");
					}
				}
			}
			closedir(p_dir);
		}
		exit(0);
	}
	else if (pid < 0)
	{
		perror("Fork error in launcher.\n");
		exit (103);
	}
	else
	{
		wait(&status);
//		printf("Returned to parent %d\n", getppid());
	}

	return (status);
}
