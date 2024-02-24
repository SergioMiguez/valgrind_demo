#!/bin/bash

name_cache="vMM_cachegrind_output.out"
name_call="vMM_callgrind_output.out"

cd builds


valgrind --tool=cachegrind --cachegrind-out-file=01$name_cache ./01vMM
valgrind --tool=cachegrind --cachegrind-out-file=02$name_cache ./02vMM
valgrind --tool=cachegrind --cachegrind-out-file=03$name_cache ./03vMM

valgrind --tool=callgrind --callgrind-out-file=01$name_call ./01vMM
valgrind --tool=callgrind --callgrind-out-file=02$name_call ./02vMM
valgrind --tool=callgrind --callgrind-out-file=03$name_call ./03vMM

mv 01$name_cache ../valgrind_cachegrind
mv 02$name_cache ../valgrind_cachegrind
mv 03$name_cache ../valgrind_cachegrind

mv 01$name_call ../valgrind_cachegrind
mv 02$name_call ../valgrind_cachegrind
mv 03$name_call ../valgrind_cachegrind

cd ..
