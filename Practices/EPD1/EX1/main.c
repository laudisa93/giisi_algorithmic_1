#include<stdio.h>
void main(void)
{
    FILE * f;
    int c,suma=0;
    f = fopen("numeros.txt", "r");
    if ( f == NULL)
        puts("Error al abrir el fichero");
    else
    {
        fscanf (f,"%d",&c);
        while(!feof(f))
        {
            suma = suma + c;
            fscanf (f,"%d",&c);

        }
        fclose (f);
        printf("La suma es: %d",suma);
    }
}
