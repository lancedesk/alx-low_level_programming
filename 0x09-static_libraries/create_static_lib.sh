#!/bin/bash

# Compile all .c files (excluding 'main.c' and 'libmy.c') into .o files
find . -maxdepth 1 -type f \( -name '*.c' ! -name 'libmy.c' ! -name 'main.c' \) -exec gcc -c {} \;

# Create the static library 'liball.a' with the desired order of .o files
ar rcs liball.a 0-isupper.o 0-memset.o 0-strcat.o 100-atoi.o 1-isdigit.o 1-memcpy.o 1-strncat.o 2-strchr.o 2-strlen.o 2-strncpy.o 3-islower.o 3-puts.o 3-strcmp.o 3-strspn.o 4-isalpha.o 4-strpbrk.o 5-strstr.o 6-abs.o 9-strcpy.o _putchar.o
