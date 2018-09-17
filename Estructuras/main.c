#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A 2

typedef struct
{
    int legajo;
    char nombre[50];
    float altura;
    int nota;
}eAlumno;

void mostrarAlumno(eAlumno);

eAlumno cargarAlumno();

void cargarListado(eAlumno [], int);

void mostrarListado(eAlumno [], int);

void ordenarListadoPorNombre(eAlumno [], int);

int main()
{
    eAlumno listadoMain[A];

    cargarListado(listadoMain, A);

    mostrarListado(listadoMain, A);

    printf("\n");

    ordenarListadoPorNombre(listadoMain, A);

    mostrarListado(listadoMain, A);

    return 0;
}

void mostrarAlumno(eAlumno unAlumno)
{
    printf("\n%d--%s--%.2f--%d\n", unAlumno.legajo,
           unAlumno.nombre, unAlumno.altura,
           unAlumno.nota);

}
eAlumno cargarAlumno()
{
    eAlumno miAlumno;

    printf("Ingrese legajo:\n");
    setbuf(stdin, NULL);
    scanf("%d", &miAlumno.legajo);

    printf("Ingrese nombre:\n");
    setbuf(stdin, NULL);
    gets(miAlumno.nombre);

    printf("Ingrese altura:\n");
    setbuf(stdin, NULL);
    scanf("%f", &miAlumno.altura);

    printf("Ingrese nota:\n");
    setbuf(stdin, NULL);
    scanf("%d", &miAlumno.nota);

    return miAlumno;
}

void cargarListado(eAlumno listado[], int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        listado[i] = cargarAlumno();
    }

}

void mostrarListado(eAlumno listado[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        mostrarAlumno(listado[i]);
    }
}

void ordenarListadoPorNombre(eAlumno listado[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i = 0; i < tam; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            if(strcmp(listado[i].nombre, listado[j].nombre) > 0)
            {
                auxAlumno = listado[i];
                listado[i] = listado[j];
                listado[j] = auxAlumno;
            }
        }
    }
}
