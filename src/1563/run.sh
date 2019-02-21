#!/usr/bin/env bash 
set -e
set -o pipefail
set -u

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
SRC="main.cpp"
TESTS_DIR="$DIR/tests"

if [ $# -gt 0 ] ; then
    SRC="$1"
fi

#compile
case $(echo "$SRC" | sed 's/^.*\.//') in
"cpp")
    rm -f "$DIR/a.out" 
    echo "COMPILE"
#-stack_size size
#                 Specifies the maximum stack size for the main thread in a program.  Without this option a program has a 8MB stack.  The argu-
#                 ment size is a hexadecimal number with an optional leading 0x. The size should be a multiple of the architecture's page size (4KB or 16KB).
    g++ -fno-strict-aliasing -DONLINE_JUDGE -lm -x c++ -std=c++14 -Wl,-stack_size,0x600000 -O2 "$DIR/$SRC"
;;

"c")
    rm -f "$DIR/a.out" 
    echo "COMPILE"
    gcc -fno-strict-aliasing -DONLINE_JUDGE -lm -std=c11 -Wl,-stack_size,0x600000 -O2 "$DIR/$SRC" 
;;
esac

#tests

if [ $# -gt 1 ] ; then
    TESTS="${@:2}"
else
    TESTS=$( find "$TESTS_DIR" -name *.in -exec basename {} .in \; | sort -n )
fi

for test in $TESTS; do
    echo -n "START TEST: [$test] "
    TEST_FN_IN="$TESTS_DIR/$test.in"
    TEST_FN_OUT="$TESTS_DIR/$test.out"

## The 'date' program in OS X is different than GNU's coreutils date program. 
## You must install 'coreutils' (including gnu-date), then you will have a version of date that supports nanoseconds.
## brew install coreutils
## gdate +%s%N
    
    START_NS=$(gdate +%s%N)    
    out=$(cat "$TEST_FN_IN" | "$DIR/a.out" | LC_ALL=C sed 's/[[:blank:]]*$//')
    FINISH_NS=$(gdate +%s%N)

    etalon=$(cat "$TEST_FN_OUT")

    if [ "$out" != "$etalon" ]; then
        echo "........ [FAIL]"
        echo "    OUT: [$out]"
        echo "    ETN: [$etalon]"
        exit -1
    fi

    echo ".........[DONE][$((($FINISH_NS-$START_NS)/1000/1000))ms]"
done
