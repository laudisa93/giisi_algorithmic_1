#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * f;
    char caracter;

    f=fopen("DATOS.txt","r");

    if(f==NULL)
        puts("Error en la apertura\n");
    else{
        caracter = fgetc(f);
        while(!feof(f)){
            printf("%c",caracter);
            caracter = fgetc(f);
        }
        fclose(f);
    }

    return 0;
}
