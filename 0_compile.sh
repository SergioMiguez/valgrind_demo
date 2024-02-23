#!/bin/bash

./clean.sh

# Compile the source code
gcc -o builds/01vMM src/01vMM.c
gcc -o builds/02vMM src/02vMM.c
gcc -o builds/03vMM src/03vMM.c
