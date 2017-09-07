#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAXEDI 200 //Tamaño total de punto en eje x

//Declaracion de metodos

void SkylineDyV(int,int,int [],int [],int [],int[]);

//Funcion principal

void main(int argc,char **argv)
{
    if(argc!=3)//Si los argumentos en el fichero no son 3 nos dara un error
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

    int v[MAXEDI]; //Vector auxiliar para guardar las alturas
    int w[MAXEDI]; //Vector para guardar los puntos de las alturas

    for(i=0; i<MAXEDI; i++)
    {
        v[i]=0; //Se rellena a ceros porque es la mínima altura
        w[i]=i; //Se rellena con los valores del eje X
    }

    //Estudio del tiempo de ejecucion

    long int inicio,final;
    double segundos, divisor=1000000;

    inicio = GetTickCount();
    for(i=0; i<divisor; i++)
    {
        SkylineDyV(0,tam,h,x1,x2,v);// Llamada a funcion Skyline
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
            for(i=1; i<MAXEDI; i++) //Inicializamos a 1 porque no existe edificio en la posicion 0
            {
                if(v[i-1]!=v[i])    //Para que no salgan valores repetidos
                {
                    fprintf(f2," %2d",v[i]);
                }
            }
            fprintf(f2,"\nPuntos:  ");

            for(i=1; i<MAXEDI; i++) //Inicializamos a 1 porque no existe edificio en la posicion 0
            {
                if(v[i-1]!=v[i])    //Para que no salgan valores repetidos
                {
                    fprintf(f2," %2d",w[i]);
                }
            }
        }
        fclose(f2);
    }
}

//Funcion Divide y Venceras Skyline

void SkylineDyV(int inicio,int final,int h[],int x1[],int x2[],int v[])
{
    //Inicio y final son posiciones del vector
    int medio=(inicio+final)/2; //Cogemos la posicion del medio
    int tam,i;
    tam=final-inicio; //Numero de elementos del vector
    int ini=x1[medio],fin=x2[medio]; //ini=el punto inicial del edificio del medio, fin=punto final del edificio del medio
    int indice=(ini+fin)/2; //Indice de v,que sera el vector donde guardemos los cambios de alturas
    if(indice<MAXEDI)
    {
        if(inicio==final)   //Caso base: si solo hay un edificio
        {
            if(v[ini]<h[medio]) //Si la altura es mayor que la guardada en el vector v
            {
                v[ini]=h[medio];    //Se sobreescribe sobre la guardada
            }
        }
        else
        {
            for(i=ini; i<fin; i++)  //Miramos todos los puntos del edificio a tratar
            {
                if(v[i]<h[medio])   //Si la altura es mayor que la guardada en el vector v
                {
                    v[i]=h[medio];  //Se sobreescribe sobre la guardada
                }
            }

            SkylineDyV(inicio,medio,h,x1,x2,v);     //Miramos los edificios de la Izquierda
            SkylineDyV(medio+1,final,h,x1,x2,v);    //Miramos los edificios de la Derecha
        }
    }
}
