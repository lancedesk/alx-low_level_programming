#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>


void print_name_as_is(char *name);
void print_name_uppercase(char *name);
void print_name(char *name, void (*f)(char *));
int _putchar(char c);

#endif
