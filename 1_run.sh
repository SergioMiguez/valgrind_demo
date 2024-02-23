#!/bin/bash

name="vMM_cachegrind_output.out"

cd builds


valgrind --tool=cachegrind --cachegrind-out-file=01$name ./01vMM
valgrind --tool=cachegrind --cachegrind-out-file=02$name ./02vMM
valgrind --tool=cachegrind --cachegrind-out-file=03$name ./03vMM

mv 01$name ../valgrind_cachegrind
mv 02$name ../valgrind_cachegrind
mv 03$name ../valgrind_cachegrind

cd ..
