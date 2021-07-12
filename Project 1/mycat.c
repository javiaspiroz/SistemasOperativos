#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_LEN 1024
 
int main(int argc, char *argv[])
{	
	if(argc < 2) {						// Only happens if there's
		printf("Usage: ./mycat file\n");		// 1 arg (name of program)
		return -1;
	}

	char* buf[BUF_LEN];
	
	int fd = open(argv[1], O_RDONLY); 		// Read only just needed
	if(fd < 0) {
   		printf("Error: opening file\n");
		close(fd);
   		return -1;
 	}	
	
	ssize_t rd_sz, wt_sz;	
	while((rd_sz = read(fd, &buf, BUF_LEN)) > 0) {		// Read into buf and save length
            	wt_sz = write(STDOUT_FILENO, &buf, rd_sz);	// Use that length to write
            	if(rd_sz != wt_sz) {
			printf("Error: writing file\n");
			close(fd);
			return -1;
            	}
    	}

	close(fd);
  	return 0;
}
