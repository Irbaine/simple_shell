#include "main.h"

/**
 * count_tokens - Count the number of tokens in a string.
 * @line: The input string.
 *
 * Return: The number of tokens.
 */
static int count_tokens(char *line)
{
	int counter = 0;
	char *temp, *tk, delimiter[] = " \t\n";

	if (line == NULL)
		return (0);

	temp = _strdup(line);
	tk = strtok(temp, delimiter);

	while (tk != NULL)
	{
		counter++;
		tk = strtok(NULL, delimiter);
	}

	free(temp);
	return (counter);
}

/**
 * allocate_tokens - Allocate memory for an array of tokens.
 * @counter: The number of tokens.
 * @line: The input string.
 *
 * Return: An array of tokens.
 */
static char **allocate_tokens(int counter, char *line)
{
	char **tokens;

	tokens = malloc(sizeof(char *) * (counter + 1));

	if (tokens == NULL)
	{
		free(line);
		return (NULL);
	}

	return (tokens);
}

/**
 * split - Splits a string into an array of tokens.
 * @line: The input string to be split.
 *
 * Return: An array of tokens (strings).
 */
char **split(char *line)
{
	int counter = 0, n = 0;
	char *temp = NULL;
	char delimiter[] = " \t\n";
	char *tk = NULL, **tokens = NULL;

	if (line == NULL)
		return (NULL);

	counter = count_tokens(line);
	tokens = allocate_tokens(counter, line);

	if (tokens == NULL)
		return (NULL);

	temp = _strdup(line);
	tk = strtok(temp, delimiter);

	while (tk != NULL)
	{
		tokens[n++] = _strdup(tk);
		tk = strtok(NULL, delimiter);
	}

	free(line);
	free(temp);
	tokens[n] = NULL;

	return (tokens);
}

