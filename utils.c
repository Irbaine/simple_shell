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
	free(arr), arr = NULL;
}
