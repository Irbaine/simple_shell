#include "main.h"

int _execute(char **cmd, char **argv)
{
	int status;
	pid_t child;
	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			freeaos(cmd);
			exit(127);
		}
	}
	else
	{
	waitpid(child, &status, 0);
	freeaos(cmd);
	}
	return (WEXITSTATUS(status));
}
