#include <stdio.h>
#include <stdlib.h>

#define NCAR 20
typedef char cadena[NCAR];
#define N 3

int mochila(int [N], float [N], float , float [N]);
void muestraVector(float [N], cadena, int);

int main()
{
    int b[N]={15,24,25};
    float p[N]={10,15,18};
    float s[N];

    printf("Beneficio obtenido: %d\n",mochila(b,p,30.0,s));
	muestraVector(s, "proporciones", N);
	return 0;
}

int mochila(int B[N], float P[N], float m, float S[N]) {
    int i;
    float pesoAc=0.0;
    int benef=0;

    for (i=0; i<N; i++) {
        S[i] = 0;
    }

    i = 0;
    while ((pesoAc < m) && (i<N)) {
        if (P[i] + pesoAc <= m) {
            S[i] = 1.0;
        } else {
            S[i] = (m - pesoAc) / P[i];
        }
        pesoAc = pesoAc + (S[i] * P[i]);
        benef  = benef  + (S[i] * B[i]);
        i = i + 1;
    }
    return(benef);
}

void muestraVector(float v[N],cadena s, int n) {
    int i;
    printf("\nDatos vector %s: \n",s);
    for(i=0; i<n; i++)
        printf("%f ",v[i]);
}

