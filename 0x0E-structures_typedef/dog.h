#ifndef DOG_H
#define DOG_H

#include <stdio.h>

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

void print_dog(struct dog *d);
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif
