#!/bin/bash

# if files exist, them remove
[ -f builds/01vMM ] && rm builds/01vMM
[ -f builds/02vMM ] && rm builds/02vMM
[ -f builds/03vMM ] && rm builds/03vMM

[ -f valgrind_cachegrind/01vMM_cachegrind_output.out ] && rm valgrind_cachegrind/01vMM_cachegrind_output.out
[ -f valgrind_cachegrind/02vMM_cachegrind_output.out ] && rm valgrind_cachegrind/02vMM_cachegrind_output.out
[ -f valgrind_cachegrind/03vMM_cachegrind_output.out ] && rm valgrind_cachegrind/03vMM_cachegrind_output.out