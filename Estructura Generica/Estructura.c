#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Estructura.h"
#include "Biblioteca.h"

int iniciar_eGenerica(eGenerica listado[], int cantidad, int ilogico)
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

int buscarLibre_eGenerica(eGenerica listado[], int cantidad, int ilogico)
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

void mostrarElemento_eGenerica(eGenerica elemento)
{
    printf("%d--%s--%.2f--%d", elemento.legajo, elemento.nombre, elemento.altura, elemento.identificador);
}

int alta_eGenerica(eGenerica listado[], int cantidad)
{
    int retorno = -1;
    int indice;
    if(listado != NULL && cantidad > 0)
    {
        indice = buscarLibre_eGenerica(listado, cantidad, ILOGICO);
        if(indice > -1)
        {
            listado[indice].legajo = pedirEntero("Introduzca legajo.\n", "Error. Introduzca legajo.\n", 1, 1000);
            pedirArrayDeLetras(listado[indice].nombre, 50, "Introduzca nombre:\n", "Error. Introduzca nombre:\n");
            retorno = 0;
        }
    }
    return retorno;
}

int baja_eGenerica(eGenerica listado[], int cantidad, int id)
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
                    mostrarElemento_eGenerica(listado[indice]);
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

int modificar_eGenerica(eGenerica listado[], int cantidad, int id)
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
                mostrarElemento_eGenerica(listado[indice]);
            }
        }
    }
    return retorno;
}

int contarAltas(eGenerica listado[], int cantidad)
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

int generarListaOrdenadaDeIds(eGenerica listado[], int cantidad, int listaDeIdentificadores[], int cantidadDeIds)
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

int generarIdentificador(eGenerica listado[], int cantidad)
{
    int retorno = -1;
    int indice;
    int cantidadDeAltas;
    int listaArmada;
    if(listado != NULL && cantidad > 0 && (contarAltas(listado, cantidad)) > 0)
    {
        cantidadDeAltas = contarAltas(listado, cantidad);
        retorno = 1;
        if(cantidadDeAltas > 1)
        {
            int listadoDeIds[cantidadDeAltas];
            listaArmada = generarListaOrdenadaDeIds(listado, cantidad, listadoDeIds, cantidadDeAltas);
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

void ordenarPorNombre_eGenerica(eGenerica listado[], int cantidad)
{
    int indice;
    int j;
    eGenerica auxiliar;

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

int menuPrincipal(void)
{
    int respuesta;
    printf("Menu de opciones:\n");
    printf("1. Altas\n2. Bajas\n3.Modificaciones\n4.Salir\n");

    respuesta = pedirEntero("\nIntroduzca una opcion:\n", "\nError. Introduzca una opcion valida:\n", 1, 4);

    return respuesta;
}
