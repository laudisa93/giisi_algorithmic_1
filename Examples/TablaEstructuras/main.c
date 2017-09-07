#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCAR 80
#define MAXPER 100

//Definición del tipo TPersona
typedef struct {
    char nombre[MAXCAR];
	char apellido1[MAXCAR];
    long DNI;
    char sexo;
    int edad;
} TPersona;

void mostrarTabla(TPersona [],int);
void mostrarPersona(TPersona);

int main(){
    FILE * f;
    TPersona t[MAXPER];
    int i=0;

    f = fopen("PERSONAS.txt","r");

    if(f == NULL)
        puts("Error de apertura\n");
    else{
        fscanf(f,"%s%s%ld %c%d",t[i].nombre,t[i].apellido1,&t[i].DNI,&t[i].sexo,&t[i].edad);
        while(!feof(f)){
            i++;
            fscanf(f,"%s%s%ld %c%d",t[i].nombre,t[i].apellido1,&t[i].DNI,&t[i].sexo,&t[i].edad);
        }
        fclose(f);
    }
    mostrarTabla(t,i);



    return 0;
}
void mostrarPersona(TPersona p){
    printf("Nombre: %s\n",p.nombre);
    printf("Primer apellido: %s\n",p.apellido1);
    printf("DNI: %ld\n",p.DNI);
    printf("Sexo: %c\n",p.sexo);
    printf("Edad: %d\n",p.edad);
}
void mostrarTabla(TPersona t[],int nelem){
    int i;
    for (i=0;i<nelem;i++){
       printf("----------------------\n");
       printf("Datos de la persona %d\n",i+1);
       printf("----------------------\n");
       mostrarPersona(t[i]);
    }
}






