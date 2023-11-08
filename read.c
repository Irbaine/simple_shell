#include "main.h"

/**
* main - execve
*
* Return : always 0
*/

char *readln(void)
{
	char *buff = NULL;
	size_t size = 0;
	ssize_t x;
	
	/* we can use read fucntion instead of getline*/
	if(isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "$ ", 2);
	x = getline(&buff,&size,stdin);
	if( x == -1)
	{
	free(buff);
	return (NULL);
	}

	return (buff);
	}
