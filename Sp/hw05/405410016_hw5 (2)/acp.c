#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 4096

 
int main(int argc, char* argv[]) {
    char c;
    int inputFd, outputFd;
    ssize_t numIn, numOut;
    char buffer[BUF_SIZE];
    off_t begin=0, end=0;
    int fileSize, blockSize, pos=0;
    char cmd[BUF_SIZE];
    char tmpfile[11] = "temp-XXXXXX";

    inputFd = open (argv [1], O_RDONLY); 
    outputFd = mkstemp(tmpfile);
    ftruncate(outputFd, 0);
    
    fileSize = lseek(inputFd, 0, SEEK_END);
    lseek(inputFd, 0, SEEK_SET);

	while (1) {
		pos = lseek(inputFd, pos, SEEK_DATA);
		begin = pos;
		pos = lseek(inputFd, pos, SEEK_HOLE);
		end = pos;
		blockSize=end-begin;
		lseek(inputFd, begin, SEEK_SET);
		lseek(outputFd, begin, SEEK_SET);
		while((numIn = read (inputFd, buffer, BUF_SIZE)) > 0) {
			numOut = write (outputFd, buffer, (ssize_t) numIn);
			if (numIn != numOut) perror("numIn != numOut");
			blockSize-=numIn;
			if (blockSize == 0) break;
		}
		if (lseek(outputFd, 0, SEEK_CUR) == fileSize) break;
    }
     
    memset(cmd,'\0',sizeof(cmd));
    fprintf(stderr,"The tmpFile is constructed ,please check,\n\nthen input anykey to continue move\n");
    scanf("%c",&c);
    sprintf(cmd,"mv  %s %s",tmpfile,argv[2]);
    system(cmd);
    close (inputFd);
    close (outputFd);
 
    return (EXIT_SUCCESS);
}
