#!/bin/bash

if [ $# != 2 ]; then									#Check if there's exactly two arguments	
	echo Introduce two numbers
else

	low=$1                              #We set the first parameter as the lower boundary
	high=$2                             #We set the second parameter as the higher boundary
	for (( i=$low; i<=$high; i++ ));    #The for loop will run through each number inside the range
	do
	if [ $(factor $i |wc -w) -le 2 ]    #Factor command displays the number of factors. If it is two, it means the number is prime
	then
		echo -n "$i"                      #If it is prime, we print it
		echo                              #Printing a blank line to match the statement example
	fi
	done;
fi
