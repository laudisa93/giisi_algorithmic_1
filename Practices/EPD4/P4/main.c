#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

void multiplicarIte(int f1, int c1,int f2, int c2,int mat1[f1][c1], int mat2[f2][c2], int mat3[f1][c2]);
void multiplicarRec(int f1, int c1,int f2,int c2,int mat1[f1][c1], int mat2[f2][c2], int mat3[f1][c2]);
void primerFOR(int f1, int c1,int f2,int c2,int mat1[f1][c1], int mat2[f2][c2], int mat3[f1][c2],int i);
void segundoFor(int f1,int c1,int f2,int c2,int mat1[f1][c1], int mat2[f2][c2], int mat3[f1][c2], int i, int j);
void tercerFor(int f1,int c1,int f2,int c2,int mat1[f1][c1], int mat2[f2][c2], int mat3[f1][c2], int i, int j, int k);
int comprobarMatrices(int c1,int f2);

int main()
{
    int f1,c1,f2,c2;

    do{
    printf("Matriz 1:\tNumero de filas: ");
    scanf("%d",&f1);
    printf("\tNumero de columnas: ");
    scanf("%d",&c1);
    printf("Matriz 2:\tNumero de filas: ");
    scanf("%d",&f2);
    printf("\tNumero de columnas: ");
    scanf("%d",&c2);

    }while(comprobarMatrices(c1,f2)==0);

    int mat1[f1][c1];
    int mat2[f2][c2];
    int mat3[f1][c2];
    int i=0,j=0;

    printf("\nMatriz 1:\n");
    for(i=0;i<f1;i++){
        for(j=0;j<c1;j++){
            printf("\tElemento [%d][%d]: ",i,j);
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("\nMatriz 2:\n");
    for(i=0;i<f2;i++){
        for(j=0;j<c2;j++){
            printf("\tElemento [%d][%d]: ",i,j);
            scanf("%d",&mat2[i][j]);
        }
    }
    multiplicarIte(f1,f2,c1,c2,mat1,mat2,mat3);
    multiplicarRec(f1,f2,c1,c2,mat1,mat2,mat3);
}

int comprobarMatrices(int c1,int f2){
    int devuelve=0;
    if(c1==f2){
        devuelve=1;
    }
    return devuelve;
}

void multiplicarIte(int f1, int c1,int f2, int c2,int mat1[f1][c1], int mat2[f2][c2], int mat3[f1][c2]){
    int i, j, k;

    for(i=0; i<f1; i++){    //Realiza el producto de matrices y guarda el resultado en una tercera matriz
        for(j=0; j<c2; j++){
            mat3[i][j]=0;
            for(k=0; k<c1; k++){
                mat3[i][j]=mat3[i][j]+(mat1[i][k]*mat2[k][j]);
            }
        }
    }

    printf("Resultado: \n");
    for (i=0 ; i<f1; i++){
        for(j=0; j<c2; j++){
            printf(" %2d ",mat3[i][j]);
        }
        printf("\n");
    }
}
void multiplicarRec(int f1, int c1,int f2,int c2,int mat1[f1][c1], int mat2[f2][c2], int mat3[f1][c2]){
    int i=0,j;
    primerFOR(f1,c1,f2,c2,mat1,mat2,mat3,i);

    printf("Resultado: \n");
    for (i=0 ; i<f1; i++){
        for(j=0; j<c2; j++){
            printf(" %2d ",mat3[i][j]);
        }
        printf("\n");
    }
}
void primerFOR(int f1, int c1,int f2,int c2,int mat1[f1][c1], int mat2[f2][c2], int mat3[f1][c2],int i){

    if(i<f1){
        segundoFor(f1,c1,f2,c2,mat1,mat2,mat3,i,0);
        primerFOR(f1,c1,f2,c2,mat1,mat2,mat3,i+1);
    }
}

void segundoFor(int f1,int c1,int f2,int c2,int mat1[f1][c1], int mat2[f2][c2], int mat3[f1][c2], int i, int j){

    if(j<f1){
        mat3[i][j]=0;
        tercerFor(f1,c1,f2,c2,mat1,mat2,mat3, i, j, 0);
        segundoFor(f1,c1,f2,c2,mat1,mat2,mat3, i, j+1);
    }

}

void tercerFor(int f1,int c1,int f2,int c2,int mat1[f1][c1], int mat2[f2][c2], int mat3[f1][c2], int i, int j, int k){

    if(k<c2){
        mat3[i][j]+=mat1[i][k]*mat2[k][j];
        tercerFor(f1,c1,f2,c2,mat1,mat2,mat3, i, j, k+1);
    }
}
