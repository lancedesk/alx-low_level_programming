#!/bin/bash

gcc -shared -o congratulations.so -fpic congratulations.c
export LD_PRELOAD=./congratulations.so:$LD_LIBRARY_PATH
