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
//Declaración de prototipos
void leer(TPersona *);
void readString (int long_cadena, char cadena[ ]);

int main(){
    FILE * f;
    TPersona p1;
    char otra;

    f = fopen("PERSONAS.txt","w");

    if(f == NULL)
        puts("Error de apertura\n");
    else{
        do{
            leer(&p1);
            fprintf(f,"%s %s %ld %c %d\n",p1.nombre,p1.apellido1,p1.DNI,p1.sexo,p1.edad);
            printf("Otra persona? (S/N)\n");
            scanf("%c",&otra);
            fflush(stdin);
        }while(otra=='S');
        fclose(f);
    }


    return 0;
}

void leer(TPersona * p){
    printf("Introduzca nombre\n");
    readString(MAXCAR,p->nombre);
    printf("Introduzca el primer apellido\n");
    readString(MAXCAR,p->apellido1);
    printf("Introduzca el DNI\n");
    scanf("%ld",&p->DNI);
    fflush(stdin);
    printf("Introduzca el sexo\n");
    scanf("%c",&p->sexo);
    fflush(stdin);
    printf("Introduzca la edad\n");
    scanf("%d",&p->edad);
    fflush(stdin);
}

void readString (int long_cadena, char cadena[ ]){
	fgets(cadena, long_cadena+1, stdin);
	int longitud = strlen(cadena);
	// Eliminamos el ’\n’ si se ha insertado
	if (cadena[longitud-1] == '\n')
		cadena[longitud-1] = '\0';
}

