#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    char nombre[] = "#nombre";
    char ap1[]="#apellido1";
    char ap2[]="apellido2";
    char aux[1000];

    FILE * f;
    FILE * fout;

    f=fopen(argv[1],"r");
    fout=fopen(argv[2],"w");

    if(argc=!4){
        puts("ERROR\n");
    }

    if(f==NULL || fout==NULL)
    {
        puts("No se ha podido abrir el fichero\n");
    }

    fscanf(f,"%s",aux))
    printf("\nPalabra: %s", aux);

    while(!feof(f)){
        if(strcmp(aux,nombre)==0){
            fprintf(fout,"%s ",argv[1]);
        }
        else if(strcmp(aux,ap1)==0){
            fprintf(fout,"%s",argv[2]);
        }
        else if(strcmp(aux,ap2)==0){
            fprintf(fout,"%s",argv[3]);
        }
        else{
            fprintf(fout,"%s",aux);
        }

    }
    fclose(f);
    fclose(fout);
}
