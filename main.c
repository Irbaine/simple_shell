#include "main.h"

/**
 * main - Entry point for the shell.
 * @ac: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, non-zero on failure.
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int stat = 0, index = 0;

	(void)ac;

	while (1)
	{
		line = read_line();
		if (!line)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}
		index++;
		command = spliter(line);
		if (command == NULL)
			continue;

		stat = _execute(command, argv, index);

		/*
		 * Uncomment the block if you want to print each element in the command array
		 * int i;
		 * for (i = 0; command[i]; i++)
		 * {
		 *     printf("%s\n", command[i]);
		 *     free(command[i]);
		 *     command[i] = NULL;
		 * }
		 * free(command);
		 * command = NULL;
		 */
	}
}

