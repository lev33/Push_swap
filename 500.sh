#!/bin/bash

MAX=0
MIN=100000
ITERATIONS=0
SUM=0

for i in {1..30}
do
#		export ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
    export ARG=`node -e "console.log(Array(500).fill().map(() => Math.round(Math.random() * 10000000)).join(' '))"`
#		export ARG=`node -e "i = 500; s = ''; while (i) { s += ' ' + i--;};  console.log(s)"`
		NUMBER="$(./push_swap $ARG | wc -l | sed 's/ //g')"
		if [ "$NUMBER" -gt "$MAX" ]
			then
			MAX=$NUMBER;
		fi
		if [ "$MIN" -gt "$NUMBER" ]
			then
			MIN=$NUMBER;
		fi
		echo "Test" $i "->" $NUMBER
		let SUM+=$NUMBER;
		let ITERATIONS+=1
done

echo "-------------------------------"
echo "30 tests for 500 random numrers"
echo "min $MIN max $MAX operations"
echo "average $(($SUM / $ITERATIONS)) operations"
