#include <stdio.h>
#include <stdlib.h>
#define N 8

void cambio(int [N], float , int [N]);

int main()
{
    int M[N]={200,100,50,20,10,5,2,1};
    int M2[N]={100,90,1};
    int I[N]={0,0,0,0,0,0,0,0};
    float importe;
    int i;
    importe=4.11;
    cambio(M,importe*100,I);
    printf("El cambio en monedas de %.2f es :",importe);
    for(i=0;i<N;i++){
        printf("\n%d monedas de %.2f €",I[i],M[i]/100.);
    }
    importe=400.11;
    cambio(M2,importe*100,I);
    printf("El cambio en monedas de %.2f es :",importe);
    for(i=0;i<N;i++){
        printf("\n%d monedas de %.2f €",I[i],M[i]/100.);
    }
}

void cambio(int monedas[N], float importe, int cambio[N]){
    int i = 0;
    while ((importe > 0) && (i < N)) {
        if (monedas[i] <= importe) {;
            cambio[i] += 1;
            importe -= monedas[i];
        } else {
            i++;
        };
    }
}
