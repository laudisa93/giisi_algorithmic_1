#include<stdio.h>
#include<stdlib.h>
void main(void)
{
    FILE * f;
    int i;
    f = fopen("salidaLetras.txt","a");
    if(f==NULL)
        puts("Error al abrir el fichero");
    else
        for(i='a'; i<='z'; i++)
            fputc(i,f);
    fclose(f);
    abort(); // Aborta la ejecución intencionadamente

}
