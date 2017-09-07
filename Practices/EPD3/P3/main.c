#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int sumaVecRec(int *,int);
int sumaVecIte(int *t,int tam);

int main()
{
    int v[]={10,25,30,45,50};
    int tam=5;
    int i=0;

    long int inicio,final;
    double segundos, divisor=1000000;
    int suma=-1;
    inicio = GetTickCount();
    //for(i=0;i<divisor;i++){
    //    suma=sumaVecRec(v,tam-1);
    //}
    for(i=0;i<divisor;i++){
        suma=sumaVecIte(v,tam);
    }
    final = GetTickCount();
    segundos=(final-inicio)/divisor;
    printf("\nTiempo: %e segundos",segundos);
    printf("\nLa suma es %d",suma);

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

int sumaVecIte(int *t,int tam){
    int suma=0;
    int i=0;
    for(i=0;i<tam;i++){
        suma+=t[i];
    }
    return suma;
}
