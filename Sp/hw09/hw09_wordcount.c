
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
    int pipefd[2];
    int ret, wstat, pid1, pid2;
    char filename[256];
    char *vect[] = {"wc", (char*)NULL};
    pipe(pipefd);
    pid1 = fork();   //產生第一個child        
    if (pid1==0) {
        close(1);   //關閉stdout
        dup(pipefd[1]); //將pipefd[1]複製到stdout
        close(pipefd[1]);   //將沒用到的關閉
        close(pipefd[0]);   //將沒用到的關閉
        execlp("cat", "cat", argv[1], NULL);   //執行cat，cat會將東西藉由stdout輸出到pipefd[1]
    } 
    if (pid1>0) {    
        pid2 = fork();//產生第二個child
        if (pid2==0) {
            close(0);   //關閉stdin
            dup(pipefd[0]); //將pipefd[0]複製到stdin
            close(pipefd[1]);   //將沒用到的關閉
            close(pipefd[0]);   //將沒用到的關閉
            printf("    行數    字數    大小\n");
            execv("/usr/bin/wc",vect);   //執行wc，wc將透過stdin從pipefd[0]讀入資料
        } 
    }
    close(pipefd[0]); close(pipefd[1]);
    wait(&wstat);
    wait(&wstat);
}