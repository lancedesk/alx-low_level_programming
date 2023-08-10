#include "main.h"

/**
 * _memcpy - copies memory area
 * @dest: destination pointer
 * @src: source pointer
 * @n: number of bytes to copy
 * Return: pointer to destination
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	char *cdest = dest;
	const char *csrc = src;
	size_t i;

	for (i = 0; i < n; i++)
		cdest[i] = csrc[i];

	return (dest);
}

/**
 * _realloc - reallocates a memory block
 * using malloc and free
 * @ptr: old memory pointer
 * @old_size: old memory size
 * @new_size: new memory size
 * Return: pointer to new reallocated space
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_pointer;

	if (new_size == old_size)
		return (ptr);

	if (!ptr)
	{
		new_pointer = malloc(new_size);
		return (new_pointer);
	}

	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}

	new_pointer = malloc(new_size);
	if (!new_pointer)
		return (NULL);

	_memcpy(new_pointer, ptr, old_size < new_size ? old_size : new_size);
	free(ptr);

	return (new_pointer);
}
