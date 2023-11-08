#include "main.h"

int main(int ac, char **argv)
{
	char *line = NULL;
	int status = 0;
	(void) ac;
	(void) argv;
	
	
	while (1)
	{
		line = readln();
		if(line == NULL)
		{
			if(isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		
		printf("%s\n", line);
		free(line);
	}
}
