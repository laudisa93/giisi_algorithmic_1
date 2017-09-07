#include <stdio.h>
#include <stdlib.h>

int Fibonnacci(int);


int main(){
    int i=0;
    int ifinal=10;
    for(i=0;i<=ifinal;i++){
        printf("Fibonnaci de %d: %d\n",i,Fibonacci(i));
    }
}

int Fibonacci(int n) {
    int r=0;
    if (n==0 || n==1)
        r=n;
    else
        r = Fibonacci(n-1) + Fibonacci(n-2);
        return r;
}
