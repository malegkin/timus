#!/usr/bin/env bash 
set -e
set -o pipefail
set -u

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

#remove files by name
for fn in a.out .DS_Store;
do
    find "$DIR" -name "$fn" -exec rm {} \;
done 
