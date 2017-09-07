#include<stdio.h>
void main(void)
{
    float altura,peso;
    char apellidos[255],nombre[255];
    printf("Altura: ");
    scanf("%f",&altura);
    printf("Peso: ");
    scanf("%f",&peso);
    printf("Nombre: ");
    gets(nombre);
    printf("Apellidos: ");
    gets(apellidos);
    printf("El atleta %s %s mide %f m. y pesa %f kg.",nombre,apellidos,altura,peso);
}
