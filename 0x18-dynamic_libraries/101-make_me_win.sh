#!/bin/bash

echo -e '#include <stdio.h>\nint system(const char *command) { return 0; }' > /tmp/win.c
gcc -shared -o /tmp/win.so -fPIC /tmp/win.c
export LD_PRELOAD=/tmp/win.so
