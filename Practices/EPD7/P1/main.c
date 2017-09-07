#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int vectorX [5] = {3,1,0,4,2};
    int vectorY [5] = {4,7,10,2,5};
    int tam=4;

    Quicksort(vectorX,vectorY,0,tam);

    int mx = vectorX[(tam)/2];

    int i;
    for (i=0;i<=mx;i++){
        printf("%d-%d\n",vectorX[i],vectorY[i]);
    }

    printf("--------------\n");

    for (i=mx+1;i<=tam;i++){
        printf("%d-%d\n",vectorX[i],vectorY[i]);
    }
    int raiz=16;
    printf("Raiz cuadrada de 16: %f\n",raizCuadrada(1,3,2,5));

    printf("TODOS:\n");
    for (i=0;i<=tam;i++){
        printf("%d-%d\n",vectorX[i],vectorY[i]);
    }

    printf("mediana: %d\n",mx);

}

int pivot(int arrayX[],int arrayY[], int izq, int der){
    int i;
    int pivote, valor_pivote;
    int auxX,auxY;

    pivote = izq;
    valor_pivote = arrayX[pivote];
    for (i=izq+1; i<=der; i++){
        if (arrayX[i] < valor_pivote){
                pivote++;
                auxX=arrayX[i];
                auxY=arrayY[i];
                arrayX[i]=arrayX[pivote];
                arrayY[i]=arrayY[pivote];
                arrayX[pivote]=auxX;
                arrayY[pivote]=auxY;

        }
    }
    auxX=arrayX[izq];
    auxY=arrayY[izq];
    arrayX[izq]=arrayX[pivote];
    arrayY[izq]=arrayY[pivote];
    arrayX[pivote]=auxX;
    arrayY[pivote]=auxY;
    return pivote;
}

void Quicksort(int arrayX[],int arrayY[], int izq, int der){
     int pivote;
     if(izq < der){
        pivote=pivot(arrayX,arrayY, izq, der);
        Quicksort(arrayX,arrayY, izq, pivote-1);
        Quicksort(arrayX,arrayY, pivote+1, der);
     }
}

float raizCuadrada (int num1x, int num1y, int num2x, int num2y){

    return sqrt (pow((double)num1x-(double)num2x,2)+pow((double)num1y-(double)num2y,2));
}
