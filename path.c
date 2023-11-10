#include "main.h"

char *_getpath(char *cmd)
{
	char *env_path;
	char *all;
	char *val = "PATH";
	char *delim = ":";
	char *directory;
	struct stat st;
	
	
	env_path = _getenviron(val);
	
	directory = strtok(env_path, delim);
	
	while (directory)
	{
		all = malloc(2 + _strlength(directory) + _strlength(cmd));
		if(all)
		{
			_strcopy(all, directory);
			_strconcat(all, "/");
			_strconcat(all, cmd);
			if (stat(all, &st) == 0)
			{
				free(env_path);
				return (all);
			}
			free(all);
			all = NULL;
			
			directory = strtok(NULL, delim);
		}
		free(env_path);
		return NULL;
}

int main(int ac, char **av)
{
	char *all;
	
	all = _getpath(av[1]);
	if (all)
		printf("%s\n", all);
		else
			printf("not exist");
	}
	}
