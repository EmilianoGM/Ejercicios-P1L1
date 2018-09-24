typedef struct
{
    int legajo;
    char nombre[50];
    float altura;
    int nota;
    int estado;
}eAlumno;

void inicializarAlumnos(eAlumno listado[], int tam);

void mostrarAlumno(eAlumno);

eAlumno cargarAlumno();

int buscarLibre(eAlumno listado[], int tam, int ilogico);

int buscarLegajo(eAlumno listado[], int tam, int legajo);

int cargarListadoAlumno(eAlumno [], int);

void mostrarListadoAlumno(eAlumno [], int);

void ordenarListadoPorNombre(eAlumno [], int);

void mostrarListadoAprobados(eAlumno [], int);

void mostrarListadoMayoresNotas(eAlumno [], int);

void mostrarListadoNombreComienceConP(eAlumno [], int);

void mostrarListadoNombreJuan(eAlumno [], int);

void modificarListadoPorLegajo(eAlumno [], int);
