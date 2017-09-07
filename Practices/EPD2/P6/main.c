#include <stdio.h>
#include <stdlib.h>

/*Considera la siguiente función recursiva:
Esta función, llamada función de Ackerman, es interesante porque crece rápidamente con
respecto a los valores m y n. Comprobar que Ackerman (1, 2) vale 4 y que Ackerman (3, 2)
vale 29.
Queda comprobado

¿Cuántas llamadas recursivas se hacen cuando queremos evaluar Ackerman (1,2)?
5 veces

¿Qué ocurre al intentar calcular Ackerman (5,1)?
No se puede calcular. */

int ackerman(int m, int n);

int main() {

    int m,n;
    printf("m = ");
    scanf("%d",&m);
    printf("n = ");
    scanf("%d",&n);
    printf("Ackerman(%d,%d) = %d",m,n,ackerman(m,n));

}

int ackerman(int m, int n){
    int ack;
    if(m==0){
        ack=n+1;
    }else if(m>0 && n==0){
        ack=ackerman(m-1,1);
    }else{
        ack=ackerman(m-1,ackerman(m,n-1));
    }
    return ack;
}
