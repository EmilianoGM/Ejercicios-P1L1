#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int pedirEntero(char mensaje[], char mensajeError[])
{
    int numero;
    int bandera = 0;
    printf("%s", mensaje);
    while(bandera == 0)
    {
        fflush(stdin);
        if(scanf("%d", &numero) == 1)
        {
            bandera = 1;
        }else
        {
            printf("%s", mensajeError);
        }
    }
    return numero;
}

float pedirFlotante(char mensaje[], char mensajeError[])
{
    float numero;
    int bandera = 0;
    printf("%s", mensaje);
    while(bandera == 0)
    {
        fflush(stdin);
        if(scanf("%f", &numero) == 1)
        {
            bandera = 1;
        }else
        {
            printf("%s", mensajeError);
        }
    }
    return numero;
}
