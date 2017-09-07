#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCAR 80

//Definición del tipo TPersona
typedef struct {
    char nombre[MAXCAR];
	char apellido1[MAXCAR];
    long DNI;
    char sexo;
    int edad;
} TPersona;

int main(){
    FILE * f;
    TPersona p1;
    char nombre[MAXCAR];
    char apellido[MAXCAR];
    int edad,max;

    f = fopen("PERSONAS.txt","r");

    if(f == NULL)
        puts("Error de apertura\n");
    else{
        fscanf(f,"%s%s%ld %c%d",p1.nombre,p1.apellido1,&p1.DNI,&p1.sexo,&p1.edad);
        max = p1.edad;
        strcpy(nombre,p1.nombre);
        strcpy(apellido,p1.apellido1);
        edad = p1.edad;
        while(!feof(f)){
            if(p1.edad > max){
                max = p1.edad;
                strcpy(nombre,p1.nombre);
                strcpy(apellido,p1.apellido1);
                edad = p1.edad;
            }
             fscanf(f,"%s%s%ld %c%d",p1.nombre,p1.apellido1,&p1.DNI,&p1.sexo,&p1.edad);
        }
        printf("La persona de mayor edas es %s %s que tiene %d\n",nombre,apellido,edad);
        fclose(f);
    }


    return 0;
}




