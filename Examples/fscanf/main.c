#include <stdio.h>
#include <stdlib.h>
#define MAXCAR 80

int main()
{
    FILE * f;
    char nombre[MAXCAR];
    char apellido[MAXCAR];
    float nota,media = 0,num=0;

    f=fopen("ALUMNOS.txt","r");

    if(f==NULL)
        puts("Error en la apertura\n");
    else{
        fscanf(f,"%s%s%f",nombre,apellido,&nota);
        while(!feof(f)){
            media += nota;
            num++;
            fscanf(f,"%s%s%f",nombre,apellido,&nota);
        }
        printf("La nota media de la clase es: %.2f",media/num);
        fclose(f);
    }

    return 0;
}
