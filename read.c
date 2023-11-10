#include "main.h"

/**
*
* Return : always 0
*/

char *read_line(void)
{
	ssize_t number;
	size_t size = 0;
	char *buff = NULL;
	
	if(isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "$ ", 2);
	/* we can use read fucntion instead of getline*/
	number = getline(&buff, &size, stdin);
	if( number == -1)
	{
	free(buff);
	buff = NULL;
	return (NULL);
	}

	return (buff);
	}
