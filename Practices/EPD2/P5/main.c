#include <stdio.h>
#include <stdlib.h>

/*Implemente un procedimiento que lleve a cabo la suma de dos matrices de manera recursiva.
Para que dos matrices puedan ser sumadas han de tener las mismas dimensiones.*/

void sumaMat(int nfi,int nco,int mat1[nfi][nco],int mat2[nfi][nco],int matRes[nfi][nco]);

int main(){

    int nfi,nco,i,j;
    printf("Número de filas: ");
    scanf("%d",&nfi);
    printf("Número de columnas: ");
    scanf("%d",&nco);

    printf("Matriz 1:\n");
    int mat1[nfi][nco];
    for(i=0;i<nfi;i++){
        for(j=0;j<nco;j++){
            printf("Elemento [%d][%d]: ", i,j);
            scanf("%d",&mat1[i][j]);
        }
    }

    printf("Matriz 2:\n");
    int mat2[nfi][nco];
    for(i=0;i<nfi;i++){
        for(j=0;j<nco;j++){
            printf("Elemento [%d][%d]: ", i,j);
            scanf("%d",&mat2[i][j]);
        }
    }
    printf("La suma de las matrices es: \n");
    int matRes[nfi][nco];
    sumaMat(nfi-1,nco-1,mat1,mat2,matRes);
    for(i=0;i<nfi;i++){
        for(j=0;j<nco;j++){
            printf("%d ", matRes[i][j]);
        }printf("\n");
    }
}

void sumaMat(int nfi,int nco,int mat1[nfi][nco],int mat2[nfi][nco],int matRes[nfi][nco]){

    if(nfi==0 && nco==0){
        matRes[nfi][nco]=mat1[nfi][nco]+mat2[nfi][nco];
    }else{
        if (nco==0){
            matRes[nfi][nco]=mat1[nfi][nco]+mat2[nfi][nco];
            sumaMat(nfi-1,1,mat1,mat2,matRes);//max nco
        }else{
            matRes[nfi][nco]=mat1[nfi][nco]+mat2[nfi][nco];
            sumaMat(nfi,nco-1,mat1,mat2,matRes);
        }
    }
    printf("nfi: %d, nco: %d res: %d\n",nfi,nco,matRes[nfi][nco]);
}
