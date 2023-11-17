#include "main.h"
/**
* _strlength - Calculates the length of a string.
* @n: The input string.
*
* This function calculates and returns the length of the input string @n.
*
* Return: The length of the string @n.
*/
int _strlength(char *n)
{
int length = 0;
while (n[length])
{
length++;
}
return (length);
}

/**
* _strcopy - Copies a string from source to destination.
* @dest: The destination string.
* @source: The source string to be copied.
*
* This function copies the contents of the source string @source
* to the destination string @dest. It terminates the destination
* string with a null character ('\0').
*
* Return: A pointer to the destination string @dest.
*/
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

/**
* strcompar - Compares two strings.
* @one: The first string to compare.
* @two: The second string to compare.
*
* This function compares the strings @one and @two. It returns an integer
* value indicating their relationship: 0 if the strings are identical, a
* positive value if @one is greater than @two, and a negative value if
* @two is greater than @one.
*
* Return: An integer representing the comparison result.
*/
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

