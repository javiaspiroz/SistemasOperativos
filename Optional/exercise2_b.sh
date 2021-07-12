#!/bin/bash

if [ $# != 2 ] && ![["$2" =~ "^[0-9]+$"]]                               #If the number of arguments is different of two, we display the usage message
then
	echo -e "Usage: ./exercise2_b.sh \e[4mFILE\e[0m \e[4mNUM\e[0m"      	#This characters are for underlining the type of parameters
else
	tr -c [:alnum:] [\\n\*] < $1 | sort | uniq -c | sort -nr | head -$2 	#If it is two, then it will execute normally.
fi
