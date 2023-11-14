#include "main.h"

int main(int ac, char **argv)
{
	char *line = NULL;
	char **cmd = NULL;
	int stat = 0, index = 0;
	(void) ac;
	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}
		index++;
		cmd = spliter(line);
		if (cmd == NULL)
			continue;
		if (strcompar(cmd[0], "env") == 0 ||
		strcompar(cmd[0], "cd") == 0 || strcompar(cmd[0], "setenv") == 0 ||
		strcompar(cmd[0], "exit") == 0) {
		handle_cmd(&stat, cmd, index, argv);
		}
	else

		stat = _execute(cmd, argv); /*add an index*/}
	}
