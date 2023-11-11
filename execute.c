#include "main.h"

int _execute(char **cmd, char **argv, int index)
{
	int status;
	pid_t child;
	char *all;

	all = _getpath(cmd[0]);
	if (all == NULL)
	{
		err(cmd[0], argv[0], index);
		freeaos(cmd);
		return (127);
	}

	child = fork();
	if (child == -1)
	{
		perror("fork");
		free(all);
		freeaos(cmd);
		return (127);
	}

	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror("execve");
			freeaos(cmd);
			free(all);
			_exit(127); /* Use _exit to avoid calling atexit functions */
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free(all);
		freeaos(cmd);
	}

	return (WEXITSTATUS(status));
}

