#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Biblioteca.h"

int pedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo)
{
    int numero;
    int error;
    printf("%s", mensaje);
    do
    {
        error = 0;
        fflush(stdin);
        scanf("%d", &numero);
        if(isdigit(numero) < 1)
        {
            error = 1;
        } else
        {
            if(numero > maximo || numero < minimo)
            {
                error = 1;
            }
        }
        if(error == 1)
        {
            printf("%s", mensajeError);
        }
    }while(error == 1);
}
/*
int pedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo)
{
    char array[13];
    int numero;
    int error;
    printf("%s", mensaje);
    do
    {
        error = 0;
        fflush(stdin);
        fgets(array, 13, stdin);
        if(array[(strlen(array) - 1)] != '\n')
        {
            error = 1;
        } else
        {
            if(array[0] != '-' && isdigit(array[0]) == 0)
            {
                error = 1;
            }else
            {
                if(comprobarArrayNumerica(array, (strlen(array) - 1)) == 0)
                {
                    error = 1;
                }else
                {
                    array[(strlen(array) - 1)] = '\0';
                    numero = atoi(array);
                    if(numero > maximo || numero < minimo)
                    {
                        error = 1;
                    }
                }
            }
        }
        if(error == 1)
        {
            printf("%s", mensajeError);
        }
    } while(error == 1);

    return numero;
}
*/
char pedirLetra(char mensaje[], char mensajeError[])
{
    char letra;
    int error;
    printf("%s", mensaje);
    do
    {
        error = 0;
        fflush(stdin);
        letra = getche();
        printf("\n");
        if(isalpha(letra) == 0)
        {
            error = 1;
            printf("%s", mensajeError);
        }
    }while(error == 1);

    return letra;
}

void pedirArrayDeLetras(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[])
{
    int error;
    char arrayAuxiliar[tamanio + 2];
    printf("%s", mensaje);
    do
    {
        error = 0;
        fflush(stdin);
        fgets(arrayAuxiliar, (tamanio + 2), stdin);
        if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
        {
            error = 1;
        } else
        {
            if(comprobarArrayDeLetras(arrayAuxiliar, (strlen(arrayAuxiliar) - 2)) == 0)
            {
                error = 1;
            }
        }
        if(error == 1)
        {
            printf("%s", mensajeError);
        }
    }while(error == 1);

    arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
    strncpy(arrayLetras, arrayAuxiliar, strlen(arrayAuxiliar));
}

void pedirTexto(char arrayTexto[], int tamanio, char mensaje[], char mensajeError[])
{
    int error;
    char arrayAuxiliar[tamanio + 2];
    printf("%s", mensaje);
    do
    {
        error = 0;
        fflush(stdin);
        fgets(arrayAuxiliar, (tamanio + 2), stdin);
        if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
        {
            error = 1;
            printf("%s", mensajeError);
        }
    }while(error == 1);

    arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
    strncpy(arrayTexto, arrayAuxiliar, strlen(arrayAuxiliar));
}

int comprobarArrayDeLetras(char cadenaDeLetras[], int tamanio)
{
    int retorno = 1;
    int indice;
    if(cadenaDeLetras != NULL)
    {
        for(indice = 0; indice < tamanio; indice++)
        {
            if(isalpha(cadenaDeLetras[indice]) == 0)
            {
                retorno = 0;
                break;
            }
        }
    } else
    {
        retorno = 0;
    }
    return retorno;
}

int comprobarArrayNumerica(char cadenaNumerica[], int tamanio)
{
    int error = 0;
    int indice;
    if(cadenaNumerica != NULL)
    {
        for(indice = 0; indice < tamanio; indice++)
        {
            if(isdigit(cadenaNumerica[indice]) == 0)
            {
                error = 1;
                break;
            }
        }
    } else
    {
        error = 1;
    }
    return error;
}

void ordenarArrayNumerica(int arrayNumerica[],int tamanio)
{
    int indice;
    int j;
    int auxiliar;
    for(indice = 1; indice < tamanio; indice++)
    {
        auxiliar = arrayNumerica[indice];
        j = indice - 1;
        while(j>=0 && auxiliar < arrayNumerica[j])
        {
            arrayNumerica[j+1] = arrayNumerica[j];
            j--;
        }
        arrayNumerica[j+1] = auxiliar;
    }
}
