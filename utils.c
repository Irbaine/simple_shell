#include "main.h"

int _strlength(char *n)
{
  int length = 0;

  while (n[length])
  {
    length++;
  }

  return (length);
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
  return (dest);
}


char *_strconcat(char *dest, const char *source)
{
  char *n = dest;
  while (*n != '\0')
  {
    n++;
  }
  while (*source != '\0')
  {
    *n = *source;
    n++;
    source++;
  }
  *n = '\0';
  return (dest);
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
	for (n = 0; n < = length; n++)
		ptr[n] = string[n];
	return (ptr);
}

int strcompar(char *one, char *two)
{
	int compar;
	compar = (int)*one - (int)*two;
	while (*one)
	{
		if (*one != *two)
			break;
		one++;
		two++;
		compar = (int)*one - (int)*two;
	}
	return (compar);
}

void freeaos (char **arr)
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
