#include <stdio.h>
#include <stdlib.h>

/*Complete el algoritmo para calcular el máximo común divisor de dos números enteros positivos. Se ha
descompuesto este problema matemático en los siguientes casos:
a=b --> m=a=b
a>b --> m=mcd(__b__,a-b)
a<b --> m=mcd(__b-a__,a)
Rellene los huecos, e impleméntelo de forma recursiva.*/

int mcd(int,int);

int main()
{
    int a, b;

    printf("Introduzca dos números: \na:");
    scanf("%d", &a);
    printf("\nb:");
    scanf("%d", &b);

    printf("El máximo comun divisor de %d y %d es %d",a,b,mcd(a,b));

    return 0;
}

int mcd(int a, int b){
    int max;

    if(a==b){
        max=a;
    }else if(a>b){
        max=mcd(b,a-b);
    }else{
        max=mcd(b-a,a);
    }

    return max;
}
