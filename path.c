#include "main.h"

/**
 * _check_path - Checks if the given path exists
 * @path: The path to check
 * @cmd: The command
 * @st: Pointer to struct stat
 * Return: Full path of the command if found, otherwise NULL
 */
char *_check_path(char *path, char *cmd, struct stat *st)
{
	char *full_path;

	full_path = malloc(2 + _strlength(path) + _strlength(cmd));
	if (full_path)
	{
		_strcopy(full_path, path);
		_strconcat(full_path, "/");
		_strconcat(full_path, cmd);
		if (stat(full_path, st) == 0)
			return (full_path);
		free(full_path);
		full_path = NULL;
	}
	return (NULL);
}

/**
 * _search_in_path - Searches for the command in the given directory
 * @env_path: The PATH environment variable
 * @cmd: The command
 * Return: Full path of the command if found, otherwise NULL
 */
char *_search_in_path(char *env_path, char *cmd)
{
	char *directory, *full_path;
	struct stat st;

	directory = strtok(env_path, ":");
	while (directory)
	{
		full_path = _check_path(directory, cmd, &st);
		if (full_path)
			return (full_path);
		directory = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * _getpath - Function to get the full path of a command
 * @cmd: The command to search for
 * Return: Full path of the command if found, otherwise NULL
 */
char *_getpath(char *cmd)
{
	char *env_path;
	struct stat st;

	env_path = _getenviron("PATH");
	if (env_path == NULL)
		return (NULL);

	for (int n = 0; cmd[n]; n++)
	{
		if (cmd[n] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}

	char *result = _search_in_path(env_path, cmd);

	free(env_path);

	return (result);
}

/**
 * main - Example usage of _getpath function
 * @ac: Argument count
 * @av: Argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *all;

	all = _getpath(av[1]);
	if (all)
		printf("%s\n", all);
	else
		printf("not exist");

	return (0);
}

