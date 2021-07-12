#!/bin/bash

if [ $# != 1 ]; then				#Check if there's only one arguments
	echo Introduce only one argument
else

	if grep -e $1 /etc/group>/dev/null      #Same as before, we check if the name of the group exists
	then
 	 grep $1 /etc/passwd | cut -d':' -f1    #If it does, we print all the members of the group
	else
 	 echo "No such group"                   #If it doesn't, we print the message and end
	fi
fi
