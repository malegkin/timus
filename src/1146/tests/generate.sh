#!/usr/bin/env bash

if [ $# -ne 1 ]; then
    echo "ERROR: no table width specified! "
    exit -1
fi

echo $1

for i in $(seq 0 $(($1-1))); do
    for j in $(seq 0 $(($1-1))); do
    echo -n "$(echo $RANDOM % 255 - 127 | bc) " 
    done
    echo
done
