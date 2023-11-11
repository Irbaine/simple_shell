#include "main.h"

int _strlength(const char *str)
{
	int length = 0;

	while (str[length])
	{
		length++;
	}

	return (length);
}

char *_strcopy(char *dest, const char *source)
{
	char *n = dest;

	while (*source)
	{
		*n = *source;
		n++;
		source++;
	}
	*n = '\0';

	return (dest);
}

char *_strconcat(char *destination, const char *source)
{
	char *n = destination;

	while (*n)
	{
		n++;
	}

	while (*source)
	{
		*n = *source;
		n++;
		source++;
	}
	*n = '\0';

	return (destination);
}

char *_strdup(const char *string)
{
	int length = _strlength(string);
	char *ptr = malloc(sizeof(char) * (length + 1));

	if (ptr == NULL)
	{
		return (NULL);
	}

	for (int n = 0; n <= length; n++)
	{
		ptr[n] = string[n];
	}

	return (ptr);
}

int _strcompar(const char *one, const char *two)
{
	while (*one && (*one == *two))
	{
		one++;
		two++;
	}

	return ((int)(*one) - (int)(*two));
}

void freeaos(char **arr)
{
	if (!arr)
	{
		return;
	}

	for (int n = 0; arr[n]; n++)
	{
		free(arr[n]);
		arr[n] = NULL;
	}

	free(arr);
	arr = NULL;
}

void err(const char *cmd, const char *shell, int index)
{
	const char *msg = ": not found\n";
	char *in = _itoa(index);

	write(STDERR_FILENO, shell, _strlength(shell));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, in, _strlength(in));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlength(cmd));
	write(STDERR_FILENO, msg, _strlength(msg));

	free(in);
}
