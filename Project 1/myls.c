#include <stdio.h>              /* Cabecera llamada al sistema printf  */
#include <unistd.h>             /* Cabecera llamada al sistema gtcwd  */
#include <sys/types.h>          /* Cabeceras llamadas al sistema opendir, readdir y closedir  */
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[]){
	//Define variables to be used
	
	char buf[PATH_MAX]; //Buffer (where the path will be saved)
	struct dirent *dirent; //Struct that contains important file information such as its name
	DIR *dir; //Pointer refering to the directory

	if(argv[1]!=NULL && argv[2]==NULL){//If arguments are passed
		//Change to requested directory
		if (chdir(argv[1]) < 0) {
    	printf("Error chdir");
    	return -1;
  	}  	
	}
	
	//This function gets the current path and saves it in the buffer
	if(getcwd(buf, PATH_MAX)==NULL){
		printf("Error ocurred while finding the directory");
		return -1;
	}	
	//Opens the path directory
	if((dir = opendir(buf))==NULL){
		printf("Error ocurred while opening the directory");
		return -1;
	}
	
	//Printing files names
	while((dirent = readdir(dir)) != NULL){
		printf("%s\n", dirent->d_name);
	}
	
	//Closes the directory
	closedir(dir);

	//Program finishes
	return 0;
}
