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
	
	while(1){
			printf("$ ");
			/* we can use read fucntion instead of getline*/
			getline(&buff,&size,stdin);
			printf("%s",buff);
		}
	return (0);
	}
