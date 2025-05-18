#!/bin/bash

# Clean previous build
make clean

# Flash firmware
make flash

# Upload files
make upload

# Clean again
make clean

