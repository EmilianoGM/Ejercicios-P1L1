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
    char apellidoYNombre[CANTIDADRESULTADO];

    pedirCadenaCaracteres(nombre, CANTIDAD, "Introduzca su nombre:");
    pedirCadenaCaracteres(apellido, CANTIDAD, "Introduzca su apellido:");

    strcpy(apellidoYNombre, apellido);
    strcat(apellidoYNombre, ", ");
    strcat(apellidoYNombre, nombre);

    capitalizarCadenaCaracteres(apellidoYNombre, strlen(apellidoYNombre));

    printf("Apellido y nombre:\n%s\n", apellidoYNombre);

    return 0;
}
