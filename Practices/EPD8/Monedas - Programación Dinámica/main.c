#include <stdio.h>
#include <stdlib.h>
#define INFINITO 1000
#define n 100
#define m 6
void cambio(int, int,int[m][n],int [m]);
void combinar(int,int,int[m][n],int[m]);
int main()
{
    int monedas[m][n],i,j;
    int tipo[m]= {0,1,5,10,20,25};
    int entero=0;
    cambio(m,n,monedas,tipo);

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            combinar(i,j,monedas,tipo);
        }
    }
    entero= monedas[m-1][55];

    printf("TOTAL: %d",entero);

}
void cambio(int x, int y,int monedas[m][n],int tipo[m])
{
    int aux=0,i,j,k;
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            if(j==0)
            {
                monedas[i][j]=0;
            }
            else if(i==0)
            {
                monedas[i][j]=INFINITO;
            }
            else
            {
                aux=j;
                monedas[i][j]=0;
                k=i;
                while(k>=0)
                {
                    if(aux-tipo[k]>=0 && aux!=0)
                    {

                        aux=aux-tipo[k];
                        monedas[i][j]++;
                    }
                    else
                    {
                        k--;
                    }
                }
            }
        }
    }
}
void combinar(int x, int y,int monedas[m][n],int tipo[m])
{
    if(x==0 && y!=0)
    {
        monedas[x][y]=INFINITO;
    }
    else if(y==0)
    {
        monedas[x][y]=0;
    }
    else
    {

        if(x-1>=0 && y-tipo[x]>=0)
        {
            if(monedas[x-1][y]>1+monedas[x][y-tipo[x]])
            {
                monedas[x][y]=1+monedas[x][y-tipo[x]];
                combinar(x,y-tipo[x],monedas,tipo);
            }
            else
            {
                monedas[x][y]=monedas[x-1][y];
                combinar(x-1,y,monedas,tipo);
            }
        }
        else if(x-1>=0)
        {
            monedas[x][y]=monedas[x-1][y];
            combinar(x-1,y,monedas,tipo);
        }
        else if(y-tipo[x]>=0)
        {
            monedas[x][y]=1+monedas[x][y-tipo[x]];
            combinar(x,y-tipo[x],monedas,tipo);
        }
    }
}
