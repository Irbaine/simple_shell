#include "main.h"

/**
 * _str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: The concatenated string or NULL on failure.
 */
char *_str_concat(char *s1, char *s2)
{
	char *result;
	int i, j, len1 = 0, len2 = 0;

	if (s1 != NULL)
		len1 = _strlen(s1);

	if (s2 != NULL)
		len2 = _strlen(s2);

	result = malloc(len1 + len2 + 1);

	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	for (j = 0; j < len2; j++, i++)
		result[i] = s2[j];

	result[i] = '\0';

	return (result);
}

/**
 * _strlen - Calculates the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 0 if the strings are equal, a negative value if s1 < s2,
 * and a positive value if s1 > s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;

	return (s1[i] - s2[i]);
}

