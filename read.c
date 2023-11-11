#include "main.h"

/**
 * read_line - Reads a line of input from the user.
 *
 * Return: Always returns the read line (including newline character).
 *         Returns NULL on failure or end of input.
 */
char *read_line(void)
{
	ssize_t number;
	size_t size = 0;
	char *buff = NULL;

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "$ ", 2);

	/* We can use the read function instead of getline */
	number = getline(&buff, &size, stdin);

	if (number == -1)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}

	return (buff);
}

