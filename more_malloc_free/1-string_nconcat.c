#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat -  concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes of s2 copy
 *
 * Return: pointer shall point to a newly allocated space in memory
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i, j;
	char *nconcat;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	if (n >= len2)
		n = len2;

	nconcat = malloc(sizeof(char) * (len1 + n + 1));
	if (nconcat == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		nconcat[i] = s1[i];

	for (j = 0; j < n; j++)
	{
		nconcat[i] = s2[j];
		i++;
	}

	nconcat[i] = '\0';

	return(nconcat);
}
