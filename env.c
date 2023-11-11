#include "main.h"

/**
 * _getenviron - Get the value of a specified environment variable.
 * @var: The environment variable to search for.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenviron(char *var)
{
	char *key;
	char *temp;
	char *env;
	char *val;
	char *delim = "=";
	int n;

	for (n = 0; environ[n]; n++)
	{
		temp = _strdup(environ[n]);
		key = strtok(temp, delim);
		if (_strcompar(key, var) == 0)
		{
			val = strtok(NULL, "\n"); /* Remove the "\n" from here */
			env = _strdup(val);
			free(temp);
			return (env);
		}
		free(temp);
		temp = NULL;
	}
	return (NULL);
}

/**
 * main - Main function of the program.
 *
 * Return: 0 on success.
 */
int main(void)
{
	char *env = _getenviron("PWD");

	if (env != NULL)
	{
		printf("%s\n", env);
		free(env);
	}

	return (0);
}
