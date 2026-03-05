#include "main.h"

/**
* _abs - computes and returns the absolute value of an integer
* @r: The character to check
*
* Return: The absolute value of the integer
*/
int _abs(int r)
{
	if (r >= 0)
	{
		return (r);
	}
	else
	{
		return (r * -1);
	}
}
