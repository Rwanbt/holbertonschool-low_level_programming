#include "main.h"

/**
* print_last_digit - prints the last digit
* @r: The number to extract the digit from
*
* Return: The value of the last digit
*/
int print_last_digit(int r)
{
	int last;

	last = r % 10;

	if (last < 0)
	{
		last = last * -1
	}

	_putchar (last + '0');
	return (last);
}