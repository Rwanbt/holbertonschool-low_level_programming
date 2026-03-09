#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: the string given as a parameter
 *
 * Return: pointer to a newly allocated space in memory,
 * It returns NULL if insufficient memory was available.
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int len, i;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len] != '\0'; len++)
		;
	duplicate = malloc((len + 1) * sizeof(char));

	if (duplicate == 0)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		duplicate[i] = str[i];
	}

	return (duplicate);
}
