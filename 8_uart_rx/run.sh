#!/bin/bash

# Clean previous build
make clean

# Flash firmware
make flash

# Upload files
make upload

# Clean again
make clean

# Start Minicom with the specified settings
sudo minicom -b 115200 -o -D /dev/ttyACM0
