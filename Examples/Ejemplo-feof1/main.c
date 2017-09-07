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
        fscanf(f,"%d",&num);
        while(!feof(f)){
            printf("%d\t",num);
            fscanf(f,"%d",&num);
        }
        fclose(f);
    }
    return 0;
}
