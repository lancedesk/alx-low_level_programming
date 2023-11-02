#include "hash_tables.h"

/**
 * key_index - Calculates the index of a key in the hash table array.
 * @key: The key to be hashed.
 * @size: The size of the hash table array.
 *
 * Return: The index at which the key/value pair should be stored in the array.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

	/* Calculate the hash value using hash_djb2 function */
	hash_value = hash_djb2(key);

	/* Calculate the index using modulo operator */
	return (hash_value % size);
}
