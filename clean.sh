#!/bin/bash

name_cache="vMM_cachegrind_output.out"
name_call="vMM_callgrind_output.out"
log="_cache_log.out"

v_cache="valgrind_cachegrind"
v_call="valgrind_callgrind"

for n in {01..03}
do
    [ -f builds/${n}vMM ] && rm builds/${n}vMM
    [ -f $v_cache/${n}$name_cache ] && rm $v_cache/${n}$name_cache
    [ -f $v_cache/logs/${n}$log ] && rm $v_cache/logs/${n}$log
    [ -f $v_call/${n}$name_call ] && rm $v_call/${n}$name_call
done


# [ -f builds/01vMM ] && rm builds/01vMM
# [ -f builds/02vMM ] && rm builds/02vMM
# [ -f builds/03vMM ] && rm builds/03vMM

# [ -f $v_cache/01$name_cache ] && rm $v_cache/01$name_cache
# [ -f $v_cache/02$name_cache ] && rm $v_cache/02$name_cache
# [ -f $v_cache/03$name_cache ] && rm $v_cache/03$name_cache

# [ -f $v_cache/logs/01$log ] && rm $v_cache/logs/01$log
# [ -f $v_cache/logs/02$log ] && rm $v_cache/logs/02$log
# [ -f $v_cache/logs/03$log ] && rm $v_cache/logs/03$log

# [ -f $v_call/01$name_call ] && rm $v_call/01$name_call
# [ -f $v_call/02$name_call ] && rm $v_call/02$name_call
# [ -f $v_call/03$name_call ] && rm $v_call/03$name_call