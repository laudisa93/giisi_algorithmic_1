#include <stdio.h>
#include <stdlib.h>
#define TAM 10
int main(/*int argc, char **argv */) // **argv crea una tabla (matriz) de caracteres
{
    int matriz[TAM][TAM];
    int filas, colums;
    int i=0,j=0;

    /*printf("Introduzca el numero de filas: ");
    scanf("%d",&filas);
    printf("Introduzca el numero de columnas: ");
    scanf("%d",&colums);
    printf("\n");

    for(i=0;i<filas;i++){
        for(j=0;j<colums;j++){
            printf("Introduzca el elemento (%d, %d)",i+1,j+1);
            scanf("%d",&matriz[i][j]);
        }
    }
    printf("\n");
    for(i=0;i<filas;i++){
        for(j=0;j<colums;j++){
            printf("%d ",matriz[i][j]);
        }printf("\n");
    }*/

    FILE * f;
    FILE * fout;
    f=fopen("matriz.txt","r"); //f=fopen(argv[1],"r");
    fout=fopen("salida.txt","w"); //fout=fopen(argv[2]","w");
    /*
    if(argc!=3){
        printf("ERROR: Número de parámetros incorrecto");
        exit(-1);
    }
    */
    if(f==NULL)
    {
        puts("No se ha podido abrir el fichero\n");
    }
    else if(fout==NULL)
    {
        puts("No se ha podido abrir el fichero\n");
    }
    else
    {
        fscanf(f,"%d" "%d",&filas,&colums);
        printf("\nFilas: %d, Columnas: %d",filas,colums);

        for(i=0; i<filas; i++)
        {
            for(j=0; j<colums; j++)
            {
                fscanf(f,"%d ",&matriz[i][j]);
            }
        }

        fprintf(fout,"%d %d\n",filas,colums);

        for(i=0; i<filas; i++)
        {
            printf("\n");
            fprintf(fout,"\n");

            for(j=0; j<colums; j++)
            {
                fprintf(fout,"%d ",matriz[i][j]);

            }
        }
    }
    fclose(f);
    fclose(fout);
}
