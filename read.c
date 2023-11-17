#include "main.h"

/**
* read_line - Reads a line from standard input.
*
* This function reads a line from standard input using getline.
* If successful, it returns a pointer to the string read from input.
* On failure or end of input, it returns NULL.
*
* Return: On success, returns a pointer to the string read from input.
* On failure or end of input, returns NULL.
*/

char *read_line(void)
{
	ssize_t number;
	size_t size = 0;
	char *buff = NULL;

	if (isatty(STDIN_FILENO) == 1)
	write(STDOUT_FILENO, "$ ", 2);
	/* we can use read fucntion instead of getline*/
	number = getline(&buff, &size, stdin);
	if (number == -1)
	{
	free(buff);
	buff = NULL;
	return (NULL);
	}

	return (buff);
	}

