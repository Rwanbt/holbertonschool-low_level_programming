#include "dog.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to new string, or NULL if it fails
 */
char *_strdup(char *str)
{
	char *copy;
	int i;
	int len;

	len = 0;
	while (str[len])
		len++;
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/**
 * new_dog - creates a new dog
 * @name: name of dog's
 * @age: age of dog's
 * @owner: owner of dog's
 *
 * Return: pointer to new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);
	d->name = _strdup(name);
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}
	d->owner = _strdup(owner);
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}
	d->age = age;
	return (d);
}
