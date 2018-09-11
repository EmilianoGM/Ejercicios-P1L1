#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Biblioteca.h"

#define CANTIDAD 21
#define CANTIDADRESULTADO 43
int main()
{
    char nombre[CANTIDAD];
    char apellido[CANTIDAD];
    char nombreAuxiliar[CANTIDAD];
    char apellidoAuxiliar[CANTIDAD];
    char apellidoYNombre[CANTIDADRESULTADO];

    pedirCadenaCaracteres(nombre, CANTIDAD, "Introduzca su nombre:");
    pedirCadenaCaracteres(apellido, CANTIDAD, "Introduzca su apellido:");

    capitalizarCadenaCaracteres(nombre, nombreAuxiliar, CANTIDAD);
    capitalizarCadenaCaracteres(apellido, apellidoAuxiliar, CANTIDAD);

    strcpy(apellidoYNombre, apellidoAuxiliar);
    strcat(apellidoYNombre, ", ");
    strcat(apellidoYNombre, nombreAuxiliar);

    printf("\nNombre: %s\n", nombreAuxiliar);
    printf("Apellido: %s\n", apellidoAuxiliar);
    printf("Apellido y nombre: %s\n", apellidoYNombre);

    return 0;
}
