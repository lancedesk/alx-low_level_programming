#!/bin/bash
gcc -c -Wall -fpic $(find . -name '*.c' ! -name '0-main.c')
gcc -shared -o liball.so *.o
