#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAXEDI 16//Puntos maximos eje x

//Declaracion de funciones

void skyVoraz(int,int [],int [],int [],int[]);

int main(int argc,char **argv)//Si los argumentos en el fichero no son 3 nos dara un error
{
    if(argc!=3)
    {
        printf("\nERROR: se deben introducir 3 parametros de entrada");
        exit(-1);
    }

    FILE *f=fopen(argv[1],"r");//Fichero en modo lectura
    FILE *f2;

    int x1[MAXEDI],x2[MAXEDI],h[MAXEDI];//Inicializamos los vectores x1,x2 y alturas
    int tam=0;//Inicializamos tam a 0
    if(f==NULL)
    {
        printf("\nERROR: no se pudo abrir el fichero %s",argv[1]);
        exit(-1);
    }
    int i=0;
    int x,y,z;
    while(!feof(f))
    {
        fscanf(f,"%d %d %d\n",&x,&y,&z);//Voy guardando cada punto x1(comienzo edificio),x2(final edificio),h(altura)
        x1[i]=x;
        x2[i]=y;
        h[i]=z;
        i++;
    }
    fclose(f);
    tam=i;//Inicializo tam con cada linea leida en el fichero que correspondera a un edificio,tam = numero de edificios


    int v[MAXEDI]; //vector auxiliar para guardar las alturas
    int w[MAXEDI]; //vector para guardar los puntos de las alturas

    for(i=0; i<MAXEDI; i++)
    {
        v[i]=0; //se rellena a ceros porque es la mínima altura
        w[i]=0; //se rellena con los valores del eje X
    }

    //Estudio del tiempo de ejecucion

    long int inicio,final;
    double segundos, divisor=1000000;

    inicio = GetTickCount();
    for(i=0;i<divisor;i++){
        skyVoraz(tam,v,h,x1,x2);// Llamada a funcion Skyline
    }
    final = GetTickCount();
    segundos=(final-inicio)/divisor;
    printf("\n\tTiempo: %e segundos: ",segundos);
    printf("\n");

    //Escribo en el fichero la solucion del problema

    for(i=0; i<MAXEDI; i++)
    {
        f2=fopen(argv[2],"w");
        if(f2==NULL)
        {
            printf("\nERROR: al leer fichero.");
        }
        else
        {
            fprintf(f2,"Skyline: \n");
            fprintf(f2,"Alturas: ");
                for(i=0; i<MAXEDI; i++)//Inicializamos a 1 porque no existe edificio en la posicion 0
                {
                    if(v[i-1]!=v[i])
                    {
                        fprintf(f2," %2d",v[i]);
                        w[i]=i;
                    }
                }
                fprintf(f2,"\nPuntos:  ");

                for(i=0; i<MAXEDI; i++)
                {
                    if(v[i-1]!=v[i])
                        fprintf(f2," %2d",w[i]+1);
                }


        }
        fclose(f2);
    }
}
//Funcion Voraz
void skyVoraz(int tam,int v[],int h[],int x1[],int x2[])
{
    int inicio,fin,i,k=0; //inicio y fin de edificio
    while(k<tam)//Mientras k sea menor que el numero total de edificios
    {
        inicio=x1[k]; //posicion inicial del edificio
        fin=x2[k];//posicion final edificio
        i=inicio;
        while(i<MAXEDI && i<fin )
        {
            if(v[i-1]<h[k])//Guarda en v(vector donde guardaremos los cambios de alturas)
            {
                v[i-1]=h[k];//Guarda en v(vector donde guardaremos los cambios de alturas)
            }
            i++;
        }
        k++;
    }
}
