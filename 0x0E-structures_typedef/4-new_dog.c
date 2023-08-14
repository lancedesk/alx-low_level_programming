#include "dog.h"

/**
 * new_dog - a copy of my dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *my_dog;

	if (name == NULL || owner == NULL)
	{
		return (NULL);
	}

	my_dog = (dog_t *)malloc(sizeof(dog_t));

	if (my_dog == NULL)
	{
		return (NULL);
	}

	/* Allocate memory for the strings and copy their content */
	/* +1 for the null terminator */
	my_dog->name = malloc(strlen(name) + 1);
	my_dog->owner = malloc(strlen(owner) + 1);

	if (my_dog->name == NULL || my_dog->owner == NULL)
	{
		free(my_dog->name);
		free(my_dog->owner);
		free(my_dog);
		return (NULL);
	}

	strcpy(my_dog->name, name);
	strcpy(my_dog->owner, owner);

	my_dog->age = age;

	return (my_dog);
}
