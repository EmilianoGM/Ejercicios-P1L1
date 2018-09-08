#include <stdio.h>
#include "Biblioteca.h"

int pedirNumeroEntero(char texto[])
{
    int numero;
    printf("%s", texto);
    setbuf(stdin, NULL);
    scanf("%d", &numero);
    return numero;
}
