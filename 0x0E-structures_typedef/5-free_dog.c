#include "dog.h"

/**
 * free_dog - frees my dog
 * @d: dog structure
 */

void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}

