#include "main.h"

/**
* main - execve
*
* Return : always 0
*/

int main(void)
{
	int i = 1, status = 0;
	char *prompt = "$ ", *buff = NULL, *command = NULL, **arr = NULL;
	size_t size = 0;
	

			/* we can use read fucntion instead of getline*/
			getline(&buff,&size,stdin);
			printf("%s",buff);
			free(buff);
		
	return (0);
	}
