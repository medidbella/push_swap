#!/bin/bash

NUM=$1
MAX=$2

total=0
top=0

for i in {1..100}; do  # Change 10 to the number of times you want to run the command
    ARG=$(shuf -i 0-$MAX -n $NUM | awk -v sub_=$SUB '{printf "%d ", $1 - sub_}')
    res=$(./push_swap $ARG | ./checker_linux $ARG)
    output=$(./push_swap $ARG | wc -l)
    if [ $output -gt $top ]; then
        top=$output
    fi
    if [ "$res" != "OK" ]; then
	    echo $res
	    echo $ARG
	    break;
    fi
    total=$((total + output))
    if [ $output -gt 700 ]; then
	    echo $ARG;
	    break;
    fi
done

average=$((total / 100))
echo "Average: $average"
echo "max: $top"
