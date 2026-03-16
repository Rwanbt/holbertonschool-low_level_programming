#ifndef DOG_H
#define DOG_H

/**
 * struct dog - represents a dog
 * @name: the dog's name
 * @age: the dog's age
 * @owner: the dog's owner
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;
#endif /* DOG_H */
