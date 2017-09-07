#include <stdio.h>
#include <stdlib.h>

/*P2. Calcular el m�ximo de un vector. Este es un caso sencillo de aplicaci�n
de las t�cnicas de divide y vencer�s. Para que calcular el m�ximo del vector
completo si puedo obtener el m�ximo de cada una de sus mitades y compararlos
entre si. Piensa como ir�s dividiendo el problema en subproblemas y encuentra
los distintos casos para llevar a cabo la implementaci�n recursiva.*/

int N=4;

int maxVec(int[N],int,int);

int main()
{
    int v[]={2,1,5,4,3};
    int tam=5;
    printf("El maximo del vector es %d",maxVec(v,0,tam-1));
}

int maxVec(int t[N],int ini,int fin){
    int max,n,m1,m2;

    if(ini==fin){
        max=t[ini];
    }else{
        n=(fin+ini)/2;
        m1=maxVec(t,ini,n);
        m2=maxVec(t,n + 1,fin);

        if(m1>m2){
            max=m1;
        }else{
            max=m2;
        }
    }
    return max;
}
