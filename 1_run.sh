#!/bin/bash

name_cache="vMM_cachegrind_output.out"
name_call="vMM_callgrind_output.out"
ch_log="_cache_log.out"
cl_log="_cache_log.out"

cd builds

for n in {01..03}
do
    # Getting cachegrind files
    valgrind --tool=cachegrind --cache-sim=yes --branch-sim=yes \
        --instr-at-start=yes \
        --I1=32768,8,64 \
        --D1=32768,8,64 \
        --LL=2097152,16,64 \
        --main-stacksize=2097152    \
        --log-file=$n$ch_log \
        --cachegrind-out-file=${n}$name_cache \
        ./${n}vMM

        # --I1=32768,8,64 = 32KB, 8-way, 64B
        # --D1=32768,8,64 = 32KB, 8-way, 64B
        # --LL=2097152,16,64 = 2MB, 16-way, 64B

    # Getting callgrind files
    valgrind --tool=callgrind --cache-sim=yes --branch-sim=yes \
        --I1=32768,8,64 \
        --D1=32768,8,64 \
        --LL=2097152,16,64 \
        --main-stacksize=2097152 \
        --callgrind-out-file=${n}$name_call \
        ./${n}vMM

    # Moving files to correct locations
    mv ${n}$name_cache ../valgrind_cachegrind
    mv ${n}$name_call ../valgrind_callgrind
    mv ${n}$ch_log ../valgrind_cachegrind/logs
done


# valgrind --tool=cachegrind --cache-sim=yes --branch-sim=yes --log-file=$n$log --cachegrind-out-file=${n}$name_cache ./${n}vMM
# valgrind --tool=cachegrind --cache-sim=yes --branch-sim=yes --log-file=$n$log --cachegrind-out-file=${n}$name_cache ./${n}vMM
# valgrind --tool=cachegrind --cache-sim=yes --branch-sim=yes --log-file=$n$log --cachegrind-out-file=${n}$name_cache ./${n}vMM


# valgrind --tool=callgrind --callgrind-out-file=01$name_call ./01vMM
# valgrind --tool=callgrind --callgrind-out-file=02$name_call ./02vMM
# valgrind --tool=callgrind --callgrind-out-file=03$name_call ./03vMM

# mv 01$name_cache ../valgrind_cachegrind
# mv 02$name_cache ../valgrind_cachegrind
# mv 03$name_cache ../valgrind_cachegrind

# mv 01$log ../valgrind_cachegrind/logs
# mv 02$name_cache ../valgrind_cachegrind
# mv 03$name_cache ../valgrind_cachegrind

# mv 01$name_call ../valgrind_callgrind
# mv 02$name_call ../valgrind_callgrind
# mv 03$name_call ../valgrind_callgrind

# mv 01_cache_log.out ../logs

cd ..
