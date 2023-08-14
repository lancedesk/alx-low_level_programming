#include "dog.h"

/**
 * new_dog - a copy of my dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * Return: new dog copy
*/

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *my_dog;

	if (name == NULL || owner == NULL)
	{
		return (NULL);
	}

	/* Allocate memory for the new dog_t structure */
	my_dog = (dog_t *)malloc(sizeof(dog_t));

	if (my_dog == NULL)
	{
		/* Memory allocation failed */
		return (NULL);
	}

	/* Copy the attributes to the new structure */
	my_dog->name = name;
	my_dog->age = age;
	my_dog->owner = owner;

	return (my_dog);
}
