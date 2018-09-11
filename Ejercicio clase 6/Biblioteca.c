#include <stdio.h>
#include <string.h>
#include "Biblioteca.h"
#include <ctype.h>

void pedirCadenaCaracteres(char cadena[], int cantidadDeElementos, char mensaje[])
{
    printf("%s\n", mensaje);
    setbuf(stdin, NULL);
    gets(cadena);
}

void capitalizarCadenaCaracteres(char cadena[], char cadenaAuxiliar[], int cantidadDeElementos)
{
    strcpy(cadenaAuxiliar, cadena);
    strlwr(cadenaAuxiliar);
    cadenaAuxiliar[0] = toupper(cadenaAuxiliar[0]);
    for(;cantidadDeElementos > 1; cantidadDeElementos--)
    {
        if(cadenaAuxiliar[cantidadDeElementos - 1] == ' ')
        {
            cadenaAuxiliar[cantidadDeElementos] = toupper(cadenaAuxiliar[cantidadDeElementos]);
        }
    }
}
