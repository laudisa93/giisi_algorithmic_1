#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define N 2

/*EJ1. Haga un estudio comparativo entre implementación iterativa y recursiva de la suma de dos
matrices. Mida tiempos para distintas dimensiones de matrices y haga una gráfica (dimensión
frente a tiempo) con los resultados obtenidos. ¿Las dos implementaciones aceptan cualquier
dimensión de la matriz de entrada?, si no es así explique el motivo. ¿Que implementación
tarda más?, ¿Existe mucha diferencia entre ambas? Justifique estas respuestas.*/

void sumaMatRec(int nfi,int nco,int mat1[nfi][nco],int mat2[nfi][nco],int matRes[nfi][nco]);
void sumaMatIte(int nfi,int nco,int mat1[nfi][nco],int mat2[nfi][nco],int matRes[nfi][nco]);

void main(){
    long inicio, final;
    long segundos,divisor;
    divisor=1000.00;
    int i,j,nfi=2,nco=2;
    int mat1[][N]={{1,2},{3,4},{5,6}};
    int mat2[][N]={{1,1},{1,1},{1,1}};
    int matRes[N][N];

    inicio = GetTickCount();
    sumaMatIte(2,2,mat1,mat2,matRes);
    final = GetTickCount();
    segundos=final-inicio;
    printf("Tiempo: %e\n",segundos/divisor);
    for(i=0;i<nfi;i++){
        for(j=0;j<nco;j++){
            printf("%d ", matRes[i][j]);
        }printf("\n");
    }
    inicio = GetTickCount();
    sumaMatRec(2,2,mat1,mat2,matRes);
    final = GetTickCount();
    segundos=final-inicio;
    printf("Tiempo: %e\n",segundos/divisor);
    for(i=0;i<nfi;i++){
        for(j=0;j<nco;j++){
            printf("%d ", matRes[i][j]);
        }printf("\n");
    }

}

void sumaMatRec(int nfi,int nco,int mat1[nfi][nco],int mat2[nfi][nco],int matRes[nfi][nco]){
    if(nfi==0 && nco==0){
        matRes[nfi][nco]=mat1[nfi][nco]+mat2[nfi][nco];
    }else{
        if (nco==0){
            matRes[nfi][nco]=mat1[nfi][nco]+mat2[nfi][nco];
            sumaMatRec(nfi-1,1,mat1,mat2,matRes);//max nco
        }else{
            matRes[nfi][nco]=mat1[nfi][nco]+mat2[nfi][nco];
            sumaMatRec(nfi,nco-1,mat1,mat2,matRes);
        }
    }
}

void sumaMatIte(int nfi,int nco,int mat1[nfi][nco],int mat2[nfi][nco],int matRes[nfi][nco]){
    int i,j;
    for(i=0;i<nfi;i++){
        for(j=0;j<nco;j++){
            matRes[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
}
