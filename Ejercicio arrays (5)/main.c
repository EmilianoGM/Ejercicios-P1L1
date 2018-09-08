#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

#define CANTIDAD 5
int main()
{
    int numeros[CANTIDAD];
    int indiceDeArray;
    int opcion;
    for (indiceDeArray = 0; indiceDeArray < CANTIDAD; indiceDeArray++)
    {
        numeros[indiceDeArray] = pedirNumeroEntero("Introducir numero:");
    }
    system("cls");
    do {
        printf("1. Mostrar\n");
        printf("2. Modificar\n");
        printf("3. Salir\n");
        opcion = pedirNumeroEntero("\nIntroducir numero de opcion: ");
        printf("\n");

        switch(opcion)
        {
            case 1:
                for (indiceDeArray = 0; indiceDeArray < CANTIDAD; indiceDeArray++)
                {
                    printf("El %d vector es %d\n", indiceDeArray + 1, numeros[indiceDeArray]);
                }
                break;
            case 2:
                indiceDeArray = pedirNumeroEntero("\nIntroduzca indice del elemento a modificar:\n");
                if(indiceDeArray >= 0 && indiceDeArray < CANTIDAD)
                {
                    numeros[indiceDeArray] = pedirNumeroEntero("\nIntroduzca el valor:\n");
                } else
                {
                    printf("\nEl indice no existe.\n");
                }
                break;
            case 3:
                break;
            default:
                printf("\nOpcion no valida.\n");
        }

        printf("\n");
        system("pause");
        system("cls");

    } while(opcion != 3);

    printf("\nGracias por usar la aplicacion.\n");

    return 0;
}
