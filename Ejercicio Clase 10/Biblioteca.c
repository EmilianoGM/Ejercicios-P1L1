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

void inicializarAlumnos(eAlumno listado[], int tam)
{
    int legajo[3] = {001, 002, 003};
    char nombre[3][50] = {"Juan", "Maria", "Luis"};
    float altura[3] = {1.8, 1.5, 1.9};
    int nota[3] = {4, 7, 9};

    int i;
    for(i = 0; i < 3; i++)
    {
        listado[i].legajo = legajo[i];
        strcpy(listado[i].nombre, nombre[i]);
        listado[i].altura = altura[i];
        listado[i].nota = nota[i];
        listado[i].estado = 1;
    }
}

int buscarLibre(eAlumno listado[], int tam, int ilogico)
{
    int index = ilogico;
    int i;
    for(i = 0; i < tam; i++)
    {
        if(listado[i].estado == ilogico)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarLegajo(eAlumno listado[], int tam, int legajo)
{
    int indice;
    int bandera = 0;
    for(indice = 0; i < tam; indice++)
    {
        if(listado[i].legajo == legajo && listado[i].estado == 1)
        {
            printf("Legajo encontrado.");
            bandera = 1;
            break;
        }
    }
    if(bandera == 0)
    {
        printf("Legajo no encontrado.");
        i = -1;
    }
    return indice;
}

int cargarListadoAlumno(eAlumno listado[], int tam)
{
    int indice;
    indice = buscarLibre(listado[], tam, -1);
    if(indice != -1)
    {
        listado[indice] = cargarAlumno();
        listado[indice].estado = 1;
    }
    return indice;

}

void mostrarListadoAlumno(eAlumno listado[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        if(listado[i].estado == 1)
        {
            mostrarAlumno(listado[i]);
        }
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
/**
    mostrar el alumno
    pedir nueva nota
    pregunte si esta seguro de realizar
    si hago la asignacion
    no aviso que se cancelo
*/
{
    int legajoAux;
    printf("Legajo a buscar:\n");
    setbuf(stdin, NULL);
    scanf("%d", &legajoAux);

    int indice = buscarLegajo(listado, tam, legajoAux);
    int bandera;
    if(indice != -1)
    {
        mostrarAlumno(listado[indice]);
        printf("Quiere modificar?\n");
        setbuf(stdin, NULL);
        scanf("%d", &bandera);
        if(bandera == 1)
        {
            printf("Introduzca la nueva nota:\n");
            setbuf(stdin, NULL);
            scanf("%d", &listado[indice].nota);
            printf("La nueva nota es %d.\n", listado[indice].nota);
        }
        if(bandera == 0)
        {
            printf("La nota no ha sido modificada.\n");
        }
    }
}
