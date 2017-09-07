#include <stdio.h>
#include <stdlib.h>
#define MAXEDI 16

void skyVoraz(int ,int [],int [],int [],int []);

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

    int v[MAXEDI]; //vector auxiliar para guardar las alturas
    int w[MAXEDI]; //vector para guardar los puntos de las alturas

    for(i=0; i<MAXEDI; i++)
    {
        v[i]=0; //se rellena a ceros porque es la mínima altura
        w[i]=0; //se rellena con los valores del eje X
    }

    skyVoraz(0,v,h,x1,x2);

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
            for(i=0; i<MAXEDI; i++) //Inicializamos a 1 porque no existe edificio en la posicion 0
            {
                if(v[i-1]!=v[i])    //Para que no salgan valores repetidos
                {
                    fprintf(f2," %2d",v[i]);
                    w[i]=i;
                }
            }
            fprintf(f2,"\nPuntos:  ");

            for(i=0; i<MAXEDI; i++) //Inicializamos a 1 porque no existe edificio en la posicion 0
            {
                if(v[i-1]!=v[i])    //Para que no salgan valores repetidos
                {
                    fprintf(f2," %2d",w[i]+1);
                }
            }
        }
        fclose(f2);
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
