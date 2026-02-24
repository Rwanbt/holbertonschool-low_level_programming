#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	int last_digit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	/* 1. Calculer le dernier chiffre ici */
	last_digit = n % 10;

	/* 2. Afficher le début commun de la phrase */
	printf("Last digit of %d is %d ", n, last_digit);
	
	/* 3. Ajouter la fin de la phrase selon la condition */
	if (last_digit > 5)
	{
		printf("and is greater than 5\n");
	}

	else if (last_digit == 0)
	{
		printf("and is 0\n");
	}
	
	else
	{
		printf("and is less than 6 and not 0\n");
	}

	return (0);
}

