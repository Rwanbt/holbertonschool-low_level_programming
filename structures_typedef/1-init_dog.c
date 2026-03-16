#include "dog.h"
#include <stddef.h>

/**
 * init_dog - initialize a variable of type struct dog
 * @d: pointer of struct dog
 * @name: name of dog's
 * @age: age of dog's
 * @owner: owner of dog's
 *
 * return: Nothing.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;
	d->name = name;
	d->age = age;
	d->owner = owner;
}
