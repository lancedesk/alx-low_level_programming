#!/bin/bash

# Compile all .c files (excluding 'main.c' and 'libmy.c') into .o files
find . -maxdepth 1 -type f \( -name '*.c' ! -name 'libmy.c' ! -name 'main.c' \) -exec gcc -c {} \;

# Create the static library 'liball.a' from all .o files (excluding 'libmy.o')
find . -maxdepth 1 -type f \( -name '*.o' ! -name 'libmy.o' ! -name 'main.o' ! -name '_puts.o' \) -exec ar rcs liball.a {} \;
