#include "hash_tables.h"
#include <stdlib.h>

/**
 * key_index - Give the index of a key
 * @key: The key of hash table
 * @size: The size of table
 *
 * Return: index at which the key pair be stored in the array of the hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
