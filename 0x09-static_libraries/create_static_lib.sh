#!/bin/bash

gcc -c *.c         # Compile all .c files into .o files
ar rcs liball.a *.o  # Create the static library liball.a from the .o files
