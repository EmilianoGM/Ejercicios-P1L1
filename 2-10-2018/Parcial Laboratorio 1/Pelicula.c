#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Pelicula.h"
#include "Biblioteca.h"

int iniciar_ePelicula(ePelicula listado[], int cantidad, int ilogico)
{
    int retorno = -1;
    int indice;
    if(listado != NULL && cantidad > 0)
    {
        for(indice = 0; indice < cantidad; indice ++)
        {
            listado[indice].estado = ilogico;
        }
        retorno = 0;
    }
    return retorno;
}

int buscarLibre_ePelicula(ePelicula listado[], int cantidad, int ilogico)
{
    int retorno = -1;
    int indice;
    if(listado != NULL && cantidad > 0)
    {
        retorno = -2;
        for(indice = 0; indice < cantidad; indice ++)
        {
            if(listado[indice].estado == ilogico)
            {
                retorno = indice;
                break;
            }
        }
    }
    return retorno;
}

void mostrarElemento_ePelicula(ePelicula elemento)
{
    //printf("%d--%s--%.2f--%d", elemento.legajo, elemento.nombre, elemento.altura, elemento.identificador);
    printf("d");
}

int alta_ePelicula(ePelicula listado[], int cantidad)
{
    int retorno = -1;
    int indice;
    if(listado != NULL && cantidad > 0)
    {
        indice = buscarLibre_ePelicula(listado, cantidad, LIBRE);
        if(indice > -1)
        {
            pedirTexto(listado[indice].titulo, TAMANIO_TITULO, "Ingrese el titulo de la pelicula:\n",
                               "Error, titulo invalido. Ingreso el titulo de la pelicula nuevamente:\n");
            listado[indice].anio = pedirEntero("Introduzca anio:\n", "Error, anio invalido. Introduzca anio nuevamente:\n", 1000, 2050);
            pedirTexto(listado[indice].nacionalidad, TAMANIO_NACIONALIDAD, "Introduzca nacionalidad:\n",
                               "Error, nacionalidad invalida. Introduzca nacionaliad nuevamente:\n");
            pedirTexto(listado[indice].director, TAMANIO_DIRECTOR, "Introduzca director:\n",
                               "Error, director invalido. Introduzca director nuevamente.\n" );
            listado[indice].identificador = generarIdentificador_ePelicula(listado, cantidad);
            retorno = 0;
        }
    }
    return retorno;
}

int baja_ePelicula(ePelicula listado[], int cantidad, int id)
{
    int retorno = -1;
    int indice;
    char respuesta;
    if(listado != NULL && cantidad > 0)
    {
        for(indice = 0; indice < cantidad; indice ++)
        {
            if(listado[indice].identificador == id)
            {
                retorno = -2;
                if(listado[indice].estado == OCUPADO)
                {
                    mostrarElemento_ePelicula(listado[indice]);
                    printf("Dar de baja? (s/n):\n");
                    do
                    {
                        respuesta = getchar();
                        respuesta = tolower(respuesta);
                        if(respuesta != 's' || respuesta != 'n')
                        {
                            printf("Respuesta invalida. Ingrese s(para si) o n (para no).");
                        }
                    } while(respuesta != 's' || respuesta != 'n');
                    if(respuesta == 's')
                    {
                        listado[indice].estado = BORRADO;
                        retorno = 0;
                    } else
                    {
                        retorno = -3;
                    }
                    break;
                }
            }
        }
    }
    return retorno;
}

int modificar_ePelicula(ePelicula listado[], int cantidad, int id)
{
    int retorno = -1;
    int indice;
    if(listado != NULL && cantidad > 0)
    {
        retorno = -2;
        for(indice = 0; indice < cantidad; indice ++)
        {
            if(listado[indice].identificador == id && listado[indice].estado == OCUPADO)
            {
                retorno = -3;
                mostrarElemento_ePelicula(listado[indice]);
            }
        }
    }
    return retorno;
}

int contarAltas_ePelicula(ePelicula listado[], int cantidad)
{
    int retorno = -1;
    int indice;
    if(listado != NULL && cantidad > 0)
    {
        retorno = 0;
        for(indice = 0; indice < cantidad; indice ++)
        {
            if(listado[indice].estado == OCUPADO);
            {
                retorno++;
            }
        }
    }
    return retorno;
}

int generarListaOrdenadaDeIds_ePelicula(ePelicula listado[], int cantidad, int listaDeIdentificadores[], int cantidadDeIds)
{
    int retorno = -1;
    int indice;
    int indiceDeId = 0;
    if(listado != NULL && cantidad > 0 && listaDeIdentificadores != NULL && cantidadDeIds > 0)
    {
        for(indice = 0; indice < cantidad; indice ++)
        {
            if(listado[indice].estado == OCUPADO && indiceDeId < cantidadDeIds)
            {
                listaDeIdentificadores[indiceDeId] = listado[indice].identificador;
                indiceDeId++;
            }
        }
        ordenarArrayNumerica(listaDeIdentificadores, cantidadDeIds);
        retorno = 0;
    }
    return retorno;
}

int generarIdentificador_ePelicula(ePelicula listado[], int cantidad)
{
    int retorno = -1;
    int indice;
    int cantidadDeAltas;
    int listaArmada;
    if(listado != NULL && cantidad > 0 && (contarAltas_ePelicula(listado, cantidad)) > 0)
    {
        cantidadDeAltas = contarAltas_ePelicula(listado, cantidad);
        retorno = 1;
        if(cantidadDeAltas > 1)
        {
            int listadoDeIds[cantidadDeAltas];
            listaArmada = generarListaOrdenadaDeIds_ePelicula(listado, cantidad, listadoDeIds, cantidadDeAltas);
            for(indice = 0; indice < (cantidadDeAltas - 1); indice++)
            {
                if((listadoDeIds[indice + 1] - listadoDeIds[indice]) == 1)
                {
                    retorno++;
                }
            }
        }
    }
    return retorno;
}
/*
void ordenarPorNombre_ePelicula(ePelicula listado[], int cantidad)
{
    int indice;
    int j;
    ePelicula auxiliar;

    for(indice = 0; indice < cantidad; indice++)
    {
        for(j = indice + 1; j < cantidad; j++)
        {
            if(strcmp(listado[indice].nombre, listado[j].nombre) > 0)
            {
                auxiliar = listado[indice];
                listado[indice] = listado[j];
                listado[j] = auxiliar;
            }
        }
    }
}
*/
int menuPrincipal(void)
{
    int respuesta;
    printf("Menu de opciones:\n");
    printf("1. Altas\n2. Bajas\n3.Modificaciones\n4.Salir\n");

    respuesta = pedirEntero("\nIntroduzca una opcion:\n", "\nError. Introduzca una opcion valida:\n", 1, 4);

    return respuesta;
}
