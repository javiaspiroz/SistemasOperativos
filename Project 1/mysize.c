#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	//Define variables to be used

	int fd; //File descriptor
	int fsize; //File size
	char buf[PATH_MAX]; //Buffer (where the path will be saved)
	struct dirent *dirent; //Struct that contains important file information such as its name
	DIR *dir; //Pointer refering to the directory
	
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
	
	//While loop will read the directory and save the next entry in variable dirent until there are not more entries
	while((dirent = readdir(dir))!=NULL){
		//If the type of entry is equal to the constant DT_REG
		if(dirent->d_type==DT_REG){
			//Opens the file with read permissions and saves file descriptor in variable fd
			if ((fd = open(dirent->d_name,O_RDONLY,0666))<0){
				printf("Error opening file");
				return -1;
			}
			//Gets the pointer to the end of the file and saves its size in variable fsize
			if((fsize = lseek(fd,0,SEEK_END))<0){
				perror("Positioning error");
				return -1;
			}
			//Closes the current file
			close(fd);
			
			//Prints the name and size of the file
			printf("%s\t%d\n", dirent->d_name, fsize);
		}
	}
	
	//Closes the directory
	closedir(dir);

	//Program finishes
	return 0;
}
