typedef struct
{
    int legajo;
    char nombre[50];
    float altura;
    int nota;
}eAlumno;


void mostrarAlumno(eAlumno);

eAlumno cargarAlumno();

void cargarListadoAlumno(eAlumno [], int);

void mostrarListadoAlumno(eAlumno [], int);

void ordenarListadoPorNombre(eAlumno [], int);

void mostrarListadoAprobados(eAlumno [], int);

void mostrarListadoMayoresNotas(eAlumno [], int);

void mostrarListadoNombreConJ(eAlumno [], int);
