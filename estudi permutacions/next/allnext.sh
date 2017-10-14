#!/bin/bash

s=`../ordenar/./main $1`
i=0

while [[ 0 != ${#s} ]]
do
	printf "%s	%3d\n" $s $i
	s=`./main $s`
	i=$((i+1))
done
