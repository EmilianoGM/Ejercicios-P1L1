#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Pelicula.h"
#include "Biblioteca.h"

#define TAMANIO_PELICULAS 2

int main()
{
    ePelicula lista[TAMANIO_PELICULAS];
    iniciar_ePelicula(lista, TAMANIO_PELICULAS);
    int respuesta;
    int alta;
    char respuestaDos;
    do
    {
        respuesta = menuPrincipal();
        printf("\n");
        switch(respuesta)
        {
            case 1:
                do
                {
                    alta = alta_ePelicula(lista, TAMANIO_PELICULAS);
                    if(alta > -1)
                    {
                        printf("%20s | %4s | %20s | %8s | %5s\n", "Titulo", "Anio", "Nacionalidad", "Director", "ID");
                        mostrarElemento_ePelicula(lista[alta]);
                        printf("\nContinuar? (s/n)\n");
                        respuestaDos = getche();
                        printf("\n");
                    } else
                    {
                        printf("Lista llena.\n");
                        break;
                    }
                }while(respuestaDos == 's');
            break;

        case 6:
            mostrarListado_ePelicula(lista, TAMANIO_PELICULAS);
            break;

        case 7:
            break;
        }
        printf("\n");
        system("pause");
        system("cls");
    } while(respuesta != 7);

    printf("Fin");

    return 0;
}
