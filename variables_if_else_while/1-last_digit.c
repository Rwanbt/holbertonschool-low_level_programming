#include <stdlib.h>
#include <time.h>
/* more headers goes there */

/* betty style doc for function main goes there */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	int last_digit;
	/* ... génération de n ... */

	last_digit = n % 10;
	
	if (last_digit > 0)
	{
		printf("Last digit of %d is %d and is greater than\n", n, last_digit);
	}

	else if (last_digit == 5)
	{
		printf("Lasr digit of %d is %d and is less than\n", n, last_digit);
	}
	else (last_digit < 6, last_digit != 0)
	{
		printf("Last digit of %d is %d and is %d\n", n, last_digit);
	}
	
	return (0);

	int last_digit;
}

