#include "main.h"

/**
* _getenviron - the env builtin
* @var: the name of the env var to get
*
* Return: the value of the env
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
		if (strcompar(key, var) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(temp);
			return (env);
		}
		free(temp);
		temp = NULL;
	}
	return (NULL);
}

/*
* int main()
* {
*	char *env = _getenviron("PWD");
*	free(env);
*	return (0);
*}
*/
