#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*#define TAM 1000
#define EXITO_INICIO 2
#define EXITO_MEDIO 1000
#define EXITO_FINAL 2000
#define FRACASO_INICIO 3
#define FRACASO_MEDIO 1001
#define FRACASO_FINAL 1999*/

/*#define TAM 2000
#define EXITO_INICIO 2
#define EXITO_MEDIO 2000
#define EXITO_FINAL 4000
#define FRACASO_INICIO 3
#define FRACASO_MEDIO 2001
#define FRACASO_FINAL 3999*/

/*#define TAM 5000
#define EXITO_INICIO 2
#define EXITO_MEDIO 5000
#define EXITO_FINAL 10000
#define FRACASO_INICIO 3
#define FRACASO_MEDIO 5001
#define FRACASO_FINAL 9999*/

/*#define TAM 10000
#define EXITO_INICIO 2
#define EXITO_MEDIO 10000
#define EXITO_FINAL 20000
#define FRACASO_INICIO 3
#define FRACASO_MEDIO 10001
#define FRACASO_FINAL 19999*/

/*#define TAM 20000
#define EXITO_INICIO 2
#define EXITO_MEDIO 20000
#define EXITO_FINAL 40000
#define FRACASO_INICIO 3
#define FRACASO_MEDIO 20001
#define FRACASO_FINAL 39999*/

/*#define TAM 30000
#define EXITO_INICIO 2
#define EXITO_MEDIO 30000
#define EXITO_FINAL 60000
#define FRACASO_INICIO 3
#define FRACASO_MEDIO 30001
#define FRACASO_FINAL 59999*/

/*#define TAM 40000
#define EXITO_INICIO 2
#define EXITO_MEDIO 40000
#define EXITO_FINAL 80000
#define FRACASO_INICIO 3
#define FRACASO_MEDIO 40001
#define FRACASO_FINAL 79999*/

#define TAM 50000
#define EXITO_INICIO 2
#define EXITO_MEDIO 50000
#define EXITO_FINAL 100000
#define FRACASO_INICIO 3
#define FRACASO_MEDIO 50001
#define FRACASO_FINAL 99999

void generarVectorOrdenado(int v[TAM]);
int busquedaLineal(int num,int v[TAM]);
int busquedaBinaria(int num,int v[TAM]);
int generarNumero(int caso);

int main()
{
    int i=0,v[TAM],caso=0,numBusca,pos;
    printf("Caso: ");
    scanf("%d",&caso);
    numBusca=generarNumero(caso);
    printf("\nNúmero buscado: %d",numBusca);

    long int inicio,final;
    double segundos, divisor=1000000;

    generarVectorOrdenado(v);

    inicio = GetTickCount();
    for(i=0;i<divisor;i++){
        pos=busquedaBinaria(numBusca,v);
    }
    final = GetTickCount();
    segundos=(final-inicio)/divisor;
    printf("\nPosicion: %d",pos);
    printf("\n\nTiempo: %e segundos",segundos);
    //for(i=0;i<TAM;i++){
    //    printf("%d, ",v[i]);
    //}

}

void generarVectorOrdenado(int v[TAM]){
    int i=0;
    for(i=0;i<TAM;i++){
        v[i]=2*(i+1);
    }
}

int busquedaLineal(int num,int v[TAM]){
    int encontrado=-1;
    int i=0;
    while(i<TAM && encontrado==-1){
        if(num==v[i]){
            encontrado=i;
        }else{
            i++;
        }
    }
    return encontrado;
}

int busquedaBinaria(int num, int v[TAM]){
    int inicio=0,fin=TAM-1,medio;
    int encontrado=-1;
    while(inicio<=fin && encontrado==-1){
        medio=(fin+inicio)/2;
        if(num==v[medio]){
            encontrado=medio;
        }else if(num<v[medio]){
            fin=medio-1;
        }else{
            inicio=medio+1;
        }
    }
    return encontrado;
}

int generarNumero(int caso){
    int num=0;
    switch(caso){
        case 1:
            num=EXITO_INICIO;
            break;
        case 2:
            num=EXITO_MEDIO;
            break;
        case 3:
            num=EXITO_FINAL;
            break;
        case 4:
            num=FRACASO_INICIO;
            break;
        case 5:
            num=FRACASO_MEDIO;
            break;
        case 6:
            num=FRACASO_FINAL;
            break;
    }
    return num;
}

