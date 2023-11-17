#include "main.h"

/**
* spliter - Splits a string into tokens based on delimiters.
* @line: The string to be split.
*
* This function takes an input string @line and splits it into tokens based on
* space, tab, and newline delimiters. It allocates memory for the tokens and
* returns an array of strings containing these tokens. The last element of the
* array is set to NULL.
*
* Return: An array of strings (tokens) if successful, NULL on failure or if
* the input string is NULL.
*/
char **spliter(char *line)
{
int counter = 0;
int n = 0;
char *temp = NULL, delimiter[] = " \t\n ", *tk = NULL;
char **cmd = NULL;
if (line == NULL)
return (NULL);
temp = _strdup(line); /* get the first token */
tk = strtok(temp, delimiter);
if (tk == NULL) /* if user entered whitespaces only*/
{
free(line), line = NULL;
free(temp), temp = NULL;
return (NULL);
}
while (tk != NULL) /* walk through other tokens */
{
counter++;
tk = strtok(NULL, delimiter);
}
free(temp);
cmd = malloc(sizeof(char *) * (counter + 1));
if (cmd == NULL)
{
free(line), line = NULL;
return (NULL);
}
tk = strtok(line, delimiter);
while (tk != NULL)
{
cmd[n++] = _strdup(tk);
tk = strtok(NULL, delimiter);
}
free(line);
cmd[n] = NULL;
return (cmd);
}

