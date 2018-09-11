#include <stdio.h>
#include <string.h>
#include "Biblioteca.h"
#include <ctype.h>

void pedirCadenaCaracteres(char cadena[], int cantidadDeElementos, char mensaje[])
{
    char buffer[1024];
    printf("%s\n", mensaje);
    setbuf(stdin, NULL);
    gets(buffer);
    while(strlen(buffer) > 20)
    {
        printf("Error, reingrese:\n");
        setbuf(stdin, NULL);
        gets(buffer);
    }
    strcpy(cadena, buffer);
}

void capitalizarCadenaCaracteres(char cadena[], int cantidadDeElementos)
{
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);
    for(;cantidadDeElementos > 1; cantidadDeElementos--)
    {
        if(cadena[cantidadDeElementos - 1] == ' ')
        {
            cadena[cantidadDeElementos] = toupper(cadena[cantidadDeElementos]);
        }
    }
}
