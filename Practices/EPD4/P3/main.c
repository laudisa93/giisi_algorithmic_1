#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define TAM 5

int palindromoIntIte(int v[],int tam);
int palindromoIntRec (int v[],int fin, int i);
int palindromoCharIte (char [],int tam);
int palindromoCharRec (char [],int fin,int i);

int main()
{
    int tam;
    int v[]={1,2,5,2,1};
    int t[]={1,2,5,3,1};
    tam=5;
    if(palindromoIntIte(v,tam)==TRUE){
        printf("PALINDROMO\n");
    }else{
        printf("NO PALINDROMO\n");
    }
    if(palindromoIntRec(t,tam-1,0)==TRUE){
        printf("PALINDROMO\n");
    }else{
        printf("NO PALINDROMO\n");
    }

    char c[]={'s','a','l','a','s'};
    char s[]={'s','o','l','a','s'};
    tam=5;
    if(palindromoCharIte(c,tam)==TRUE){
        printf("PALINDROMO\n");
    }else{
        printf("NO PALINDROMO\n");
    }
    if(palindromoCharRec(s,tam-1,0)==TRUE){
        printf("PALINDROMO\n");
    }else{
        printf("NO PALINDROMO\n");
    }
}

int palindromoIntIte(int v[],int tam){
    int i=0;
    int j=tam-1;
    int devuelve=1;
    int aux[tam];

    while(i<tam && j>=0){
        aux[j]=v[i];
        i++;
        j--;
    }

    for(i=0;i<tam;i++){
        if(v[i]!=aux[i]){
            devuelve=0;
        }
    }
    return devuelve;
}

int palindromoIntRec (int v[],int fin, int i){
    int devuelve=1;
    if(i<(TAM/2)){
        if(v[i]==v[fin]){
            devuelve=palindromoIntRec(v,fin-1,i+1);
        }else{
            devuelve=0;
        }
    }
    return devuelve;
}

int palindromoCharIte (char c[],int tam){
    int i=0;
    int j=tam-1;
    int devuelve=1;
    char aux[tam];

    while(i<tam && j>=0){
        aux[j]=c[i];
        i++;
        j--;
    }

    for(i=0;i<tam;i++){
        if(c[i]!=aux[i]){
            devuelve=0;
        }
    }
    return devuelve;
}

int palindromoCharRec (char c[],int fin,int i){
    int devuelve=1;
    if(i<(TAM/2)){
        if(c[i]==c[fin]){
            devuelve=palindromoCharRec(c,fin-1,i+1);
        }else{
            devuelve=0;
        }
    }
    return devuelve;
}
