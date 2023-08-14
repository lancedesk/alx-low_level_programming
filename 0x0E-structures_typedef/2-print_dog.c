#include "dog.h"

/**
 * print_dog - prints dog
 * @d: dog structure
 */

void print_dog(struct dog *d)
{
	if (!d)
	{
		return;
	}
	else
	{
		printf("Name: %s\n", d->name ? d->name : "(nil)");
		printf("Age: %f\n", d->age);
		printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
	}
}
