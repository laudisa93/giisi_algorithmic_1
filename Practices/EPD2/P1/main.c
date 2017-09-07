#include <stdio.h>
#include <stdlib.h>

/*P1. Lleva a cabo la suma de un vector de forma recursiva.
Recuerda determinar los casos base y el resto de casos generales*/

int sumaVec(int *,int);

int main()
{
    int v[]={10,25,30,45,50};
    int tam=4;
    printf("La suma es %d",sumaVec(v,tam));
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
