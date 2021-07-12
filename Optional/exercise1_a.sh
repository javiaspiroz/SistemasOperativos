#!/bin/bash

if [ -z "$1" ]; then					#Check if there's arguments	
	echo Introduce an argument
else

	c=0                                             #We declare the variable to be used as a counter
	a=($@)                                          #We will be exploring an array with the parameters
	v=":"                                           #The string to print the semicolon between the name of the user and the path
	while [ $c -lt $# ]; do                         #The while loop to explore the array, it compares the counter with the number of 		parameters
  	cadFin=${a[c]}""$v                              #The variable that contains "user:" to be printed
  	if grep -e ${a[c]} /etc/passwd >/dev/null       #We use the grep command to locate the path of the user
  	then                                            #If the grep finds the user, it will print the corret message
    	echo -n $cadFin                                	#user:
    	grep "${a[c]}" /etc/passwd | cut -d':' -f7     	#Using grep and the command cut, we select only the part of the line that we want
  	else                                            #If it doesn't find the user, it will print an error message
    	echo -n $cadFin
    	echo " no such user"
  	fi
  	((c++))                                         #We update the counter
	done
fi
