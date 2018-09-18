#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define T 4

typedef struct
{
    int legajo;
    char nombre[21];
    int nota;
} eAlumno;

int buscarLibre(int numeros[], int tam, int ilogico);

int main()
{
    int enteros[T];
    int i;
    for(i = 0; i < T; i++)
    {
        enteros[i] = -1;
    }
    char respuesta;
    int indice;
    do
    {
        indice = buscarLibre(enteros, T, -1);
        if(indice != -1)
        {
            printf("Ingrese entero:\n");
            setbuf(stdin, NULL);
            scanf("%d", &enteros[indice]);
        }else
        {
            printf("Error.\n");
            break;
        }
        printf("Continuar(s-n)\n");
        setbuf(stdin, NULL);
        respuesta = getche();
        printf("\n");

    }while(respuesta == 's');

    for(i = 0; i < T; i++)
    {
        printf("%d - %d\n", i, enteros[i]);
    }
    /**<
    eAlumno listadoAlumno[T];
    Agrego un item (estado), que permite diferenciar a un indice cargado de uno libre.

    */
    return 0;
}

int buscarLibre(int numeros[], int tam, int ilogico)
{
    int index = ilogico;
    int i;
    for(i = 0; i < tam; i++)
    {
        if(numeros[i] == ilogico)
        {
            index = i;
            break;
        }
    }
    return index;
}
