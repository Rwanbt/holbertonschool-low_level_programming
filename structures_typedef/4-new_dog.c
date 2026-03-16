#include "dog.h"
#include <stdlib.h>

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
	int i;

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);
	i = 0;
	while (name[i])
		i++;
	d->name = malloc(i + 1);
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}
	i = 0;
	while (owner[i])
		i++;
	d->owner = malloc(i + 1);
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}
	i = 0;
	while (name[i])
	{
		d->name[i] = name[i];
		i++;
	}
	d->name[i] = '\0';
	i = 0;
	while (owner[i])
	{
		d->owner[i] = owner[i];
		i++;
	}
	d->owner[i] = '\0';
	d->age = age;
	return (d);
}
