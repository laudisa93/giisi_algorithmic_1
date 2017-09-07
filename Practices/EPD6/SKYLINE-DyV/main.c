#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAXEDI 16

void SkylineDyV(int,int,int [],int [],int [],int[]);

int main(int argc,char **argv)
{
    if(argc!=3)
    {
        printf("\nERROR: se deben introducir 3 parametros de entrada");
        exit(-1);
    }

    FILE *f=fopen(argv[1],"r");
    FILE *f2;

    int x1[MAXEDI],x2[MAXEDI],h[MAXEDI];
    int tam=0;
    if(f==NULL)
    {
        printf("\nERROR: no se pudo abrir el fichero %s",argv[1]);
        exit(-1);
    }
    int i=0;
    int x,y,z;
    while(!feof(f))
    {
        fscanf(f,"%d %d %d\n",&x,&y,&z);
        x1[i]=x;
        x2[i]=y;
        h[i]=z;
        i++;
    }
    fclose(f);
    tam=i;

    int v[16]; //vector auxiliar para guardar las alturas
    int w[16]; //vector para guardar los puntos de las alturas

    for(i=0; i<16; i++)
    {
        v[i]=0; //se rellena a ceros porque es la mínima altura
        w[i]=i; //se rellena con los valores del eje X
    }


    long int inicio,final;
    double segundos, divisor=1000000;

    inicio = GetTickCount();
    for(i=0; i<divisor; i++)
    {
        SkylineDyV(0,tam,h,x1,x2,v);// tamaño de los vectores=6
    }
    final = GetTickCount();
    segundos=(final-inicio)/divisor;
    printf("\n\tTiempo: %e segundos: ",segundos);
    printf("\n");
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

void SkylineDyV(int inicio,int final,int h[],int x1[],int x2[],int v[])
{
    //inicio y final son posiciones del vector
    int medio=(inicio+final)/2; //cogemos la posicion del medio
    int tam,i;
    tam=final-inicio; //numero de elementos del vector
    int ini=x1[medio],fin=x2[medio]; //ini=el valor i del edificio del medio, fin=valor f del edificio del medio
    int indice=(ini+fin)/2; //indice de v
    if(indice<16) //cambiar por parametro
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

            SkylineDyV(inicio,medio,h,x1,x2,v);     //Miramos los edificios de la izquierda
            SkylineDyV(medio+1,final,h,x1,x2,v);    //Miramos los edificios de la derecha
        }
    }
}
