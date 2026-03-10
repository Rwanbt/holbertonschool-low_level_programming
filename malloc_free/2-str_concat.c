#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return:
 */
char *str_concat(char *s1, char *s2)
{
	unsigned len1, len2, i;
	char *concat;

	if (s1 == NULL)
	s1 = "";

	if (s2 == NULL)
	s2 = "";

	for (len1 = 0; s1[len1] != '\0'; len1++)
		;
	for (len2 = 0; s2[len2] != '\0'; len2++)
		;
	concat = malloc((len1 + len2 + 1) * sizeof(char));

	if (concat == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
	{
		concat[i] = s1[i];
	}
	for (i = 0; i < len2; i++)
	{
		concat[len1 + i] = s2[i];
	}
	concat[len1 + len2] = '\0';

	return (concat);
}
