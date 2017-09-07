#include <stdio.h>
#include <stdlib.h>

/*P1. Escribir una función recursiva que sume todos los elementos de un vector.*/

int sumaVec(int *,int);

int main()
{
    int v[]={10,25,30,45,50};
    int tam=5;
    printf("La suma es %d",sumaVec(v,tam-1));
}

int sumaVec(int *t,int n){
    int suma=0;
    if(n==0){
        suma=t[0];
    }else{
        suma=t[n]+sumaVec(t,n-1);
    }
    return suma;
}
