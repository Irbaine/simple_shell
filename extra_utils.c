#include "main.h"

/**
* _strconcat - concatinate the string
* @dest: destination
* @source: the original string
*
* Return: a concatinated string
*/

char *_strconcat(char *dest, const char *source)
{
char *n = dest;
while (*n != '\0')
	n++;

while (*source != '\0')
{
*n = *source;
n++;
source++;
}
*n = '\0';
return (dest);
}

/**
* _strdup - duplicates the string
* @string: the original string
*
* Return: a concatinated string
*/
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
	for (n = 0; n <= length; n++)
		ptr[n] = string[n];
	return (ptr);
}

