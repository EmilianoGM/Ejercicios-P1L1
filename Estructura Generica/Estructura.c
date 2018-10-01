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
