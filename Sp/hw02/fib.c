#include <stdio.h>

long double  fib(int n){
   long  double a=0,b=1,c=0; //a is f0 ,b is f1 ,c is f0+f1=f2
    int i=0;
    if(n==0){

        return 0;
    }
    if(n==1){
        return 1;
    }
    for(i=2;i<=n;i++){
        c=a+b; 
        a=b;
        b=c;
    }
    return c;
}
int main(){  
    int i=0;
  //  while(1){   << run perf
        for(i=0;i<1000;i++){
          printf("%.0LF\n",fib(i)); //call fib then print;
        }
  // }
     return 0;
}