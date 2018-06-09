#include <stdio.h>
#include <unistd.h>


int main() {


pid_t pid1,pid2,pid3,pid4;
int val=1; //1;

pid1=fork();//1 , 1->2
val*=2;
pid2=fork();// 1 , 2 , 1->3 , 2->4;
val*=2;
pid3=fork();//1 , 2 , 3 , 4 , 1->5 , 2->6 , 3->7 , 4->8;
val*=2;
pid4=fork();//1 , 2 , 3 ,4 ......>8->16
val*=2;
printf("*");

if(pid1!=0&&pid2!=0&&pid3!=0&&pid4!=0){
    printf(">>>total star(*) count<<< =%d",val);
}

return 0;
}