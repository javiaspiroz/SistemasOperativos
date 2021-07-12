#!/bin/bash
cd $1                                       #We are using ls $PWD, which requires us to be in the directory we are going to use, so we use cd to locate ourselves there
dira=$( ls -d -1 $PWD/*.*)                  #We initialize an array with the complete path of each element in the directory, using the 		command ls
max_size=1048576                            #The maximum size allowed in an image, in bytes
for ((i=0; i < ${#dira[@]}; i++)); do       #We run through each position of the array
	if ((du -b ${dira[i]})>max_size) then
		mogrify -resize 720 ${dira[i]}          #If the size of the image, found with du, is greater the max size, then we resize it whit the command resize, and adjust the width to 720
		echo "${dira[i]}"                       #And we print the path of the image
	fi
done
