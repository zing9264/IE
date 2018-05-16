#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(){
    int outfd;
    char buffer[500];
    int num[6];
    ssize_t numOut;
    size_t len;
    int i=0;
    int *ptr;
    outfd=open("grade",O_APPEND|O_RDWR|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if(outfd==-1){
        printf("error to open");
        return 0;
    }
    while(1){
            printf(">>>");
            scanf("%d %d %d %d %d %d",&num[0],&num[1],&num[2],&num[3],&num[4],&num[5]);
            if(flock(outfd,LOCK_NB|LOCK_EX)==-1){
                printf("grade file is locked by other process -- please wait 5 second\n");
                sleep(5);
            }
            if(flock(outfd,LOCK_NB|LOCK_EX)==0){
            printf("grade file is Locked by You\n");
            printf("Inputting the grade Now\n");           
            memset(buffer,'\0',sizeof(buffer));         
            sprintf(buffer,"%d %d %d %d %d %d\n",num[0],num[1],num[2],num[3],num[4],num[5]);
            printf("%s",buffer);
            len=strlen(buffer);
            numOut=write(outfd,buffer,len); 
            printf("-----sleep 5 second for test Critical Section-----\n");
            sleep(5);
            flock(outfd,LOCK_UN);
            printf("grade file is Unlocked -- everyone can access\n");
            }        
    }
    close(outfd);
    return 0;
}