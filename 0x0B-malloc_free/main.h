#ifndef MAIN_H
#define MAIN_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **allocate_and_fill(char *str, int num_words);
void free_and_copy_memory(char **finalstring, int word_index, char *src, int start, int length);
char *create_word(char *src, int start, int length);
int count_words(char *str);
char **strtow(char *str);
char *argstostr(int ac, char **av);
void free_grid(int **grid, int height);
int **alloc_grid(int width, int height);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
char *create_array(unsigned int size, char c);

#endif
