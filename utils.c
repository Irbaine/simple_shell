#include "main.h"

int _strlength(char *n)
{
  int length = 0;

  while (n[length])
  {
    length++;
  }

  return length;
}

char *_strcopy(char *dest, char *source)
{
  char *n = dest;
  while (*source)
  {
    *n = *source;
    n++;
    source++;
  }
  *n = '\0';
  return dest;
}


char *_strconcat(char *destination, char *source)
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
  return destination;
}

char *_strdup(const char *string)
{
	int n;
	int length = 0;
	char *ptr;
	
	if (string == NULL)
		return (NULL);
	while (*string != '\0')
	{
		length++;
		string++;
	}
	string = string - length;
	ptr = malloc(sizeof(char) * (length + 1));
	
	if (ptr == NULL)
		return (NULL);
	for (n = 0; n<= length; n++)
		ptr[n] = string[n];
	return (ptr);
}

int _strcompar(char *one, char *two)
{
	int compar;
	
	compar = (int)*one - (int)*two;
	while (*one)
	{
		if (*two != *one)
			break;
		one++;
		two++;
		compar = (int)*one - (int)*two;
	}
	return (compar);
}

void freeaos(char **arr)
{
	int n;
	if (!arr)
		return;
	
	for (n = 0; arr[n]; n++)
	{
		free(arr[n]);
		arr[n] = NULL;
	}
	free(arr);
	arr = NULL;
}

void err(char *cmd, char *shell, int index)
{
	char *in;
	char msg[] = ": not found\n";
	
	in = _itoa(index);
	
	write(STDERR_FILENO, shell, _strlength(shell));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, in, _strlength(in));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlength(cmd));
	write(STDERR_FILENO, msg, _strlength(msg));
	free(in);
}
