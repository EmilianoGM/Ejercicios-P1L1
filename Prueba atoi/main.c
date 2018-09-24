#include <stdio.h>
#include <stdlib.h>

int main()
{
    char listado[10] = "-129";
    char listadoDos[10] = "-1.29";

    /**int i;
    for(i = 0; i < 4; i++)
    {
        printf("%c\n", listado[i]);
    }
    */
    int j;
    for(j = 0; j < 4; j++)
    {
        printf("%c\n", listado[j]);
    }
    /**
    float numeroDos;
    int numero;

    numero = atoi(listado);
    numeroDos = atof(listadoDos);
    numeroDos = numeroDos + -2;

    printf("\n%d", numero);
    printf("\n%f", numeroDos);
    */
    return 0;
}
