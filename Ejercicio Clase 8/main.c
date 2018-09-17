/**<
-ORDENAR NOMBRE
-MUESTRE LOS ALUMNOS APROBADOS (NOTA>6)
-MUESTRE LOS ALUMNOS QUE SE LLAMAN JUAN
-MUESTRE LOS ALUMNOS CUYO NOMBRE COMIENZAN CON P
-EL ALUMNO CON MAS NOTA (SABIENDO QUE PUEDE SER MAS QUE UNO)
-"EL MAS MEDIOCRE LEGAJO=100 NOTA=5 SE LLAME PEPE MEDIR 1.75"
-INGRESAR UN LEGAJO Y PERMITIR LA MODIFICACION DE LA NOTA
-TRANSFORMAR LA CARGA DE DATOS EN UNA CARGA ALEATORIA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

#define A 2

int main()
{
    eAlumno listadoMain[A];

    cargarListadoAlumno(listadoMain, A);

    mostrarListadoAlumno(listadoMain, A);

    printf("\n");

    ordenarListadoPorNombre(listadoMain, A);

    mostrarListadoAlumno(listadoMain, A);

    return 0;
}
