#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void skyVoraz(int,int [],int [], int [],int []);

int main()
{
    int x1[]= {1,3,7,9,11};
    int x2[]= {4,8,10,12,13};
    int h[]= {10,5,3,7,10};

    int v[16];
    int w[16]; //vector auxiliar
    int i=0;

    for(i=0; i<16; i++)
    {
        v[i]=0;
        w[i]=0;
    }
    long int inicio,final;
    double segundos, divisor=1000000;
    inicio = GetTickCount();
    for(i=0; i<divisor; i++)
    {
        skyVoraz(6,v,h,x1,x2);// tamaño de los vectores=6    }
    }
    final = GetTickCount();
    segundos=(final-inicio)/divisor;
    printf("\n\nTiempo: %e segundos",segundos);

    printf("\nAlturas: ");
    for(i=0; i<16; i++)
    {
        if(v[i-1]!=v[i])
        {
            printf(" %2d",v[i]);
            w[i]=i;
        }
    }
    printf("\nPuntos:  ");

    for(i=0; i<16; i++)
    {
        if(v[i-1]!=v[i])
            printf(" %2d",w[i]+1);
    }


}
void skyVoraz(int tam,int v[],int h[],int x1[],int x2[])
{
    int inicio,fin,i,k=0; //inicio y fin de edificio
    while(k<tam)
    {
        inicio=x1[k]; //k = posicion
        fin=x2[k];
        i=inicio;
        while(i<fin)
        {
            if(v[i-1]<h[k])
            {
                v[i-1]=h[k];
            }
            i++;
        }
        k++;
    }
}

