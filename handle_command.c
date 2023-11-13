#include "main.h"
void handle_cmd(int *stat, char **cmd, int index, char **argv)
{
	(void) argv;
	(void) index;
	if(strcompar(cmd[0], "env") == 0)
		show_env(stat, cmd);

	else if (strcompar(cmd[0], "exit") == 0)
		exit_sh(cmd, stat);

}

void show_env(int *stat, char **cmd)
{
	int n;
	for(n =0 ; environ[n]; n++)
	{
		write(STDOUT_FILENO, environ[n], _strlength(environ[n]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freeaos(cmd);
	(*stat) = 0;
}

void exit_sh(char **cmd, int *stat)
{	
	freeaos(cmd);
	exit(*stat);
}
