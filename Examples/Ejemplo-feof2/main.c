#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * f;
    int num;

    f=fopen("DATOS.txt","r");

    if(f==NULL)
        puts("Error en la apertura\n");
    else{

        while(!feof(f)){
            fscanf(f,"%d",&num);
            printf("%d\t",num);
        }
        fclose(f);
    }
    return 0;
}
