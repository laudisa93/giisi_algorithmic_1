#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define N 4
/*Diseñar una función que determine si una matriz M de dimensión n × n, con n >= 1,
es o no simétrica con respecto a la diagonal principal. Para ello, hay que implementar
una función recursiva auxiliar que compruebe si la
fila M[i][0..i-1] es simétrica a la columna M[0..i-1][i].*/

int simetriaMat(int,int,int[][N]);

int main(){
    int n,i,j;
    printf("Dimension matriz: ");
    scanf("%d",&n);
    int mat[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Elemento [%d][%d]: ", i,j);
            scanf("%d",&mat[i][j]);
        }
    }
    if(simetriaMat(n,n-1,mat)==TRUE){
        printf("La matriz es simétrica");
    }else{
        printf("La matriz no es simétrica");
    }
}

int simetriaMat(int dim,int n, int mat[dim][dim]){
    int fil=n,col=n-1;
    if(mat[1][0]==mat[0][1]){
        return TRUE;
    }else{
        if (col!=0){
            if(mat[fil][col]==mat[col][fil]){
                simetriaMat(fil,col--,mat);
            }else{
                return FALSE;
            }
        }else{
            if(mat[fil][col]==mat[col][fil]){
                simetriaMat(fil-1,fil-2,mat);
            }else{
                return FALSE;
            }
        }
    }
}
