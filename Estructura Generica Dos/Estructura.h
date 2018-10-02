#define ILOGICO -1
#define OCUPADO 1
#define BORRADO 0

typedef struct
{
    int legajo;
    char nombre[50];
    char apellido[50];
    float altura;
    int nota;
    int estado;
    int identificador;
}eGenerica;

int iniciar_eGenerica(eGenerica listado[], int cantidad, int ilogico);

int buscarLibre_eGenerica(eGenerica listado[], int cantidad, int ilogico);

int alta_eGenerica(eGenerica listado[], int cantidad);

int baja_eGenerica(eGenerica listado[], int cantidad, int id);

int contarAltas(eGenerica listado[], int cantidad);

int generarListaOrdenadaDeIds(eGenerica listado[], int cantidad, int listaDeIdentificadores[], int cantidadDeIds);

int generarIdentificador(eGenerica listado[], int cantidad);

void ordenarPorNombre_eGenerica(eGenerica listado[], int cantidad);

int menuPrincipal(void);
