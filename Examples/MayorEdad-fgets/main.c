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

void extraePersona(char [],TPersona *);

int main(){
    FILE * f;
    TPersona p1;
    char cad[MAXCAR];
    char nombre[MAXCAR];
    char apellido[MAXCAR];
    int edad,max=0;

    f = fopen("PERSONAS.txt","r");

    if(f == NULL)
        puts("Error de apertura\n");
    else{
        fgets(cad,MAXCAR,f);
        while(!feof(f)){
            extraePersona(cad,&p1);
            if(p1.edad > max){
                max = p1.edad;
                strcpy(nombre,p1.nombre);
                strcpy(apellido,p1.apellido1);
                edad = p1.edad;
            }
            fgets(cad,MAXCAR,f);
        }
        printf("La persona de mayor edad es %s %s que tiene %d\n",nombre,apellido,edad);
        fclose(f);
    }


    return 0;
}

void extraePersona(char linea[],TPersona * t){
    char *campo;

    campo = strtok(linea," ");
    strcpy(t->nombre,campo);

    campo = strtok(NULL," ");
    strcpy(t->apellido1,campo);

    campo = strtok(NULL," ");
    t->DNI = atoi(campo);

    campo = strtok(NULL," ");
    t->sexo = campo[0];

    campo = strtok(NULL," ");
    t->edad = atoi(campo);
}
