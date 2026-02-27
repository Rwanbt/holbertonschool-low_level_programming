#include "main.h"
#include <stdio.h>

/**
 * _isupper - Checks for uppercase character
 * 
 * Return: 1 if c is uppercase, 0 otherwise
 */
int _isupper(int c)
{
	if (c <= 'Z' && c >= 'A')
	{
		return (1);
	}
	return (0);
}