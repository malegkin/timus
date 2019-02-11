#!/usr/bin/env bash 
set -e
set -o pipefail
set -u

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"


find "$DIR/src" -name a.out -delete 
