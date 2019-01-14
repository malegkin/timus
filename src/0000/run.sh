#!/usr/bin/env bash 

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

for file in  $DIR/tests/*.in; do
    echo -n "START TEST: [$(basename $file .in)] "

    out=$(cat "$file" | "$DIR/a.out")

    etalon=$(cat "$DIR/tests/$(basename "$file" .in).out")

    if [ "$out" != "$etalon" ]; then
        echo "........ [FAIL]"
        echo "    OUT: [$out]"
        echo "    ETN: [$etalon]"
        exit -1
    fi

    echo ".........[DONE]"
done
