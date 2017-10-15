#!/bin/bash

s=`../ordenar/./main $1`
d=`../maxim/./main $s`
i=0

for ((i=0; i < $d; i++))
do
	printf "%s	%3d\n" `./main $s $i` $i
done
#while [[ 0 != ${#s} ]]
#do
#	printf "%s	%3d\n" $s $i
#	s=`./main $s`
#	i=$((i+1))
#done
