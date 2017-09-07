#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define TAM 5
/*P2. Escriba una función que diga si un vector es o no un palíndromo. Implemente dicha funcón para el caso en que el
vector sea de enteros y una cadena de caracteres.*/

int palindromoChar (char [],int fin,int i);
int palindromoInt (int [],int fin,int i);

int main()
{
    int tam;
    int v[]={1,2,5,2,1};
    int t[]={1,2,5,3,1};
    tam=5;
    if(palindromoInt(v,tam-1,0)==TRUE){
        printf("PALINDROMO\n");
    }else{
        printf("NO PALINDROMO\n");
    }
    if(palindromoInt(t,tam-1,0)==TRUE){
        printf("PALINDROMO\n");
    }else{
        printf("NO PALINDROMO\n");
    }

    char c[]={'s','a','l','a','s'};
    char s[]={'s','o','l','a','s'};
    tam=5;
    if(palindromoChar(c,tam-1,0)==TRUE){
        printf("PALINDROMO\n");
    }else{
        printf("NO PALINDROMO\n");
    }
    if(palindromoChar(s,tam-1,0)==TRUE){
        printf("PALINDROMO\n");
    }else{
        printf("NO PALINDROMO\n");
    }

}

int palindromoChar (char c[],int fin,int i){
    int devuelve=1;
    if(i<(TAM/2)){
        if(c[i]==c[fin]){
            devuelve=palindromoChar(c,fin-1,i+1);
        }else{
            devuelve=0;
        }
    }
    return devuelve;
}

int palindromoInt (int v[],int fin, int i){
    int devuelve=1;
    if(i<(TAM/2)){
        if(v[i]==v[fin]){
            devuelve=palindromoInt(v,fin-1,i+1);
        }else{
            devuelve=0;
        }
    }
    return devuelve;

}
