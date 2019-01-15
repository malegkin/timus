#!/usr/bin/env bash 
set -e
set -o pipefail

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
SRC="main.cpp"

if [ $# -eq 1 ] ; then
    SRC="$1"
fi

#compile
rm -f "$DIR/a.out" 
case "$SRC" in
"main.cpp")
    echo "COMPILE"
    g++ -std=c++17 "$DIR/$SRC"
;;

"main.c")
    gcc "$DIR/$SRC"
;;
esac

#test
for file in  $DIR/tests/*.in; do
    echo -n "START TEST: [$(basename $file .in)] "

    out=$(cat "$file" | "$DIR/a.out" | sed 's/[[:blank:]]*$//')

    etalon=$(cat "$DIR/tests/$(basename "$file" .in).out")

    if [ "$out" != "$etalon" ]; then
        echo "........ [FAIL]"
        echo "    OUT: [$out]"
        echo "    ETN: [$etalon]"
        exit -1
    fi

    echo ".........[DONE]"
done
