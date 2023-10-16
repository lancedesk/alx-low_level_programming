#!/bin/bash

wget -qP /tmp/ https://github.com/lancedesk/alx-low_level_programming/raw/master/0x18-dynamic_libraries/congratulations.so
export LD_PRELOAD="/tmp/congratulations.so"
