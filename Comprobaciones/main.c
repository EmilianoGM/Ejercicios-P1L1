#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main()
{
    int pedido = pedirEntero("Ingrese numero:\n", "Error. Ingrese numero nuevamente:\n");
    printf("\n%d\n", pedido);

    float pedidoDos = pedirFlotante("Ingrese numero flotante:\n", "Error. Ingrese numero flotante nuevamente:\n");
    printf("\n%f\n", pedidoDos);

    return 0;
}
