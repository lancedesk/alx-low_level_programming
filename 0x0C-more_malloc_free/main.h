#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>

int _putchar(char c);
void performMultiplication(char *num1_str, char *num2_str);
int isOnlyDigits(char *str);
int strLength(char *str);
void *allocateAndInitialize(unsigned int size);
void initializeMemory(void *mem, char value, unsigned int size);
void printProduct(int *product_array, int total);

void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
