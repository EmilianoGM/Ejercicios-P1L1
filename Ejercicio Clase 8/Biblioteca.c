#include <stdio.h>
#include <string.h>
#include "Biblioteca.h"

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

void cargarListadoAlumno(eAlumno listado[], int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        listado[i] = cargarAlumno();
    }

}

void mostrarListadoAlumno(eAlumno listado[], int tam)
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

void mostrarListadoAprobados(eAlumno listado[], int tam)
{
    int i;
    for(i = 0;i < tam; i++)
    {
        if(listado[i].nota > 6)
        {
            mostrarAlumno(listado[i]);
        }
    }
}

void mostrarListadoMayoresNotas(eAlumno listado[], int tam)
{
    int maxNota;
    int i;
    maxNota = listado[0].nota;
    for(i = 1;i < tam; i++)
    {
        if (listado[i].nota > maxNota)
        {
            maxNota = listado[i].nota;
        }
    }
    for(i = 1;i < tam; i++)
    {
        if(listado[i].nota == maxNota)
        {
            mostrarAlumno(listado[i]);
        }
    }
}

void mostrarListadoNombreConP(eAlumno listado[], int tam)
{
    int i;
    int bandera = 0;

    for(i = 0;i < tam; i++)
    {
        if(listado[i].nombre[0] == 'p')
        {
            mostrarAlumno(listado[i]);
            bandera = 1;
        }
    }
    if(bandera == 0)
    {
        printf("No hay alumnos que se llamen Juan.\n");
    }
}

void mostrarListadoNombreJuan(eAlumno listado[], int tam)
{
    int i;
    int bandera = 0;
    for(i = 0;i < tam; i++)
    {
        if(strcmp(listado[i].nombre, "Juan") == 0)
        {
            mostrarAlumno(listado[i]);
            bandera = 1;
        }
    }
    if(bandera == 0)
    {
        printf("No hay alumnos que se llamen Juan.\n");
    }
}

void modificarListadoNotaPorLegajo(eAlumno listado[], int tam)
{
    int legajoAux;
    printf("Legajo a buscar:\n");
    setbuf(stdin, NULL);
    scanf("%d", &legajoAux);
    /**
    mostrar el alumno
    pedir nueva nota
    pregunte si esta seguro de realizar
    si hago la asignacion
    no aviso que se cancelo
    */
    int i;
    int bandera = 0;
    for(i = 0;i < tam; i++)
    {
        if(listado[i].legajo == legajoAux)
        {
            bandera = 1;
        }
    }
    if(bandera == 1)
    {
        printf("Introduzca la nueva nota:\n");
        setbuf(stdin, NULL);
        scanf("%d", &listado[i].nota);
    } else
    {
        printf("Ese legajo no existe.\n");
    }
}
