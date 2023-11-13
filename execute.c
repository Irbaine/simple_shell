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
		return 127;
	}
	
	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1 )
		{
			/*perror(argv[0]);*/
			freeaos(cmd);
			free(all);
			all = NULL;
			/*exit(127);*/
		}	
	}
	else
	{
	waitpid(child, &status, 0);
	free(all);
	all = NULL;
	freeaos(cmd);
	}
	return (WEXITSTATUS(status));
}
