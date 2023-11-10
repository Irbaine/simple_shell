#include "main.h"

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

void freeaos(char **arr)
{
	int n;
	if (arr == NULL )
		return;
	
	for (n = 0; arr[n]; n++)
	{
		free(arr[n]);
		arr[n] = NULL;
	}

	free(arr), arr = NULL;
}
