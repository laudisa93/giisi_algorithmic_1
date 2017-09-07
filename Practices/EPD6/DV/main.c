#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAXEDI 16

void SkylineDyV(int,int,int [],int [],int [],int[]);

void main()
{

    int x1[]= {1,2,4,6,11,14};
    int x2[]= {3,9,12,8,13,15};
    int h[]= {4,7,4,9,6,2};
    //int x1[]= {1,3,7,9,11};
    //int x2[]= {4,8,10,12,13};
    //int h[]= {10,5,3,7,10};
    int v[16]; //vector auxiliar para guardar las alturas
    int w[16]; //vector para guardar los puntos de las alturas
    int i;
    for(i=0; i<16; i++)
    {
        v[i]=0; //se rellena a ceros porque es la mínima altura
        w[i]=i; //se rellena con los valores del eje X
    }

    SkylineDyV(0,6,h,x1,x2,v);// tamaño de los vectores=6    }
    printf("Skyline: \n");
    printf("Alturas: ");
    for(i=1; i<MAXEDI; i++) //Inicializamos a 1 porque no existe edificio en la posicion 0
    {
        if(v[i-1]!=v[i])    //Para que no salgan valores repetidos
        {
            printf(" %2d",v[i]);
        }
    }
    printf("\nPuntos:  ");

    for(i=1; i<MAXEDI; i++) //Inicializamos a 1 porque no existe edificio en la posicion 0
    {
        if(v[i-1]!=v[i])    //Para que no salgan valores repetidos
        {
            printf(" %2d",w[i]);
        }
    }
}

void SkylineDyV(int inicio,int final,int h[],int x1[],int x2[],int v[])
{
    //inicio y final son posiciones del vector
    int medio=(inicio+final)/2; //cogemos la posicion del medio
    int tam,i;
    tam=final-inicio; //numero de elementos del vector
    int ini=x1[medio],fin=x2[medio]; //ini=el valor i del edificio del medio, fin=valor f del edificio del medio
    //int indice=(ini+fin)/2; //indice de v
    //if(indice<16) //cambiar por parametro
    //{
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
    //}
}
