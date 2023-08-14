#ifndef DOG_H
#define DOG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* struct dog - info about my dog
* @name: name of the dog
* @age: age of the dog
* @owner: owner of the dog
*/

typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void free_dog(dog_t *d);
void print_dog(struct dog *d);
void init_dog(struct dog *d, char *name, float age, char *owner);
dog_t *new_dog(char *name, float age, char *owner);

#endif
