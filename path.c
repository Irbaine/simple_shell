#include "main.h"
char *_getpath(char *cmd)
{
	char *env_path, *all, *directory;
	char *val = "PATH", *delim = ":";
	int n;
	
	struct stat st;
	
	env_path = _getenviron(val);
	if (env_path == NULL)
	{
		return NULL;
	}	
	directory = strtok(env_path, delim);
	
	for (n =0; cmd[n]; n++)
	{
		if (cmd[n] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return NULL;
		}
	}
	
	
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
		}
		free(env_path);
		return (NULL);
}

/*
int main(int ac, char **av)
{
	char *all;
	
	all = _getpath(av[1]);
	if (all)
		printf("%s\n", all);
		else
			printf("not exist");
}
*/

