#include <stdio.h>
#include <stdlib.h>

int sumaVecIte(int v[],int n);
int sumaVecRec(int *,int);

int main()
{
    int v[]={10,25,30,45,50};
    int tam=5;
    printf("La suma iterativa es %d\n",sumaVecIte(v,tam));
    printf("La suma recursiva es %d\n",sumaVecRec(v,tam-1));
}

int sumaVecIte(int v[],int n){
    int i=0;
    int suma=0;

    for(i=0;i<n;i++){
        suma+=v[i];
    }

    return suma;
}

int sumaVecRec(int *t,int n){
    int suma=0;
    if(n==0){
        suma=t[0];
    }else{
        suma=t[n]+sumaVecRec(t,n-1);
    }
    return suma;
}

