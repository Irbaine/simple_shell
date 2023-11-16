#include "main.h"

/**
 * handle_cmd - Handles different commands based on input.
 * @stat: Pointer to an integer representing the program's status.
 * @cmd: Array of strings representing the command and its arguments.
 * @index: Index value (not currently used in this implementation).
 * @argv: Array of strings representing command-line arguments.
 */
void handle_cmd(int *stat, char **cmd, int index, char **argv)
{
	(void) argv; /* Function body remains unchanged */
	(void) index;

	if (strcompar(cmd[0], "env") == 0)
		show_env(stat, cmd);

	else if (strcompar(cmd[0], "exit") == 0)
		exit_sh(cmd, stat);

}

/**
 * show_env - Displays the environment variables.
 * @stat: Pointer to an integer representing the program's status.
 * @cmd: Array of strings representing the command and its arguments.
 */

void show_env(int *stat, char **cmd)
{/* Function body remains unchanged */

	int n;

	for (n = 0 ; environ[n]; n++)
	{
		write(STDOUT_FILENO, environ[n], _strlength(environ[n]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freeaos(cmd);
	(*stat) = 0;
}

/**
 * exit_sh - Exits the shell program.
 * @cmd: Array of strings representing the command and its arguments.
 * @stat: Pointer to an integer representing the program's status.
 */

void exit_sh(char **cmd, int *stat)
{
	freeaos(cmd);
	exit(*stat);
}
