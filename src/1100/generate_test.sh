#!/bin/bash

echo $1
for i in $(gshuf -i 0-$1 -n $1)
do
    echo -e "$i $((RANDOM%100))"
done
