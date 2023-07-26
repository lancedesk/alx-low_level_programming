#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>


void print_number(int n);
int _putchar(char c);
char *rot13(char *str);
char *leet(char *str);
char *cap_string(char *string);
char *string_toupper(char *str);
void reverse_array(int *a, int n);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);

#endif

