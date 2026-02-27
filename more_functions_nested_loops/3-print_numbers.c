#include "main.h"
#include <stdio.h>

/**
 * print_numbers - Prints the numbers from 0 to 9, followed by a new line
 */
void print_numbers(void)
{
	int c = '0';

	for (c = 0; c <= 9; c++)
	{
	_putchar(c + '0');
	}
	_putchar('\n')
}

