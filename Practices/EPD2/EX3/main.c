#include <stdio.h>
#include <stdlib.h>

int factorial_i(int);
int factorial_r(int);

int main()
{
    int i=20;
    printf("Factorial iterativo de %d: %d\n",i, factorial_i(i));
    printf("Factorial recursivo de %d: %d",i, factorial_r(i));
}

int factorial_r(int n) {
    int i,factorial;
    factorial=1;
    for(i=0;i<n;i++)
        factorial=factorial*(n-i);
    return factorial;
}

int factorial_i(int n) {
    int r=0;
    if (n==0)
        r =1;
    else
        r = n* factorial_i(n-1);
    return r;
}
