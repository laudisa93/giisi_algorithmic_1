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
    FILE * f,* fh,* fm;
    TPersona p1;
    char cad[MAXCAR];

    f = fopen("PERSONAS.txt","r");
    fh = fopen("HOMBRES.txt","w");
    fm = fopen("MUJERES.txt","w");

    if((f == NULL)||(fh == NULL)||(fm == NULL))
        puts("Error de apertura en alguno de los ficheros\n");
    else{
        fgets(cad,MAXCAR,f);
        while(!feof(f)){
            extraePersona(cad,&p1);
            if(p1.sexo == 'H'){
                fprintf(fh,"%s %s %ld %c %d\n",p1.nombre,p1.apellido1,p1.DNI,p1.sexo,p1.edad);
            }else{
                fprintf(fm,"%s %s %ld %c %d\n",p1.nombre,p1.apellido1,p1.DNI,p1.sexo,p1.edad);
            }
            fgets(cad,MAXCAR,f);
        }
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
