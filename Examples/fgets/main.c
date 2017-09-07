#include <stdio.h>
#include <stdlib.h>
#define MAXCAR 80

int main()
{
    FILE * f1,* f2;
    char cad[MAXCAR];

    f1 = fopen("DATOS.txt","r");
    f2 = fopen("COPIA.txt","w");

    if((f1 == NULL)||(f2 == NULL))
        puts("Error en la apertura de alguno de los ficheros\n");
    else{
        fgets(cad,MAXCAR,f1);
        while(!feof(f1)){
            fprintf(f2,"%s",cad);
            fgets(cad,MAXCAR,f1);
        }
        fclose(f1);
        fclose(f2);
    }

    return 0;
}
