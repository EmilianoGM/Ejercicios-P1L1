#define LIBRE -1
#define OCUPADO 1
#define BORRADO 0
#define TAMANIO_TITULO 50
#define TAMANIO_NACIONALIDAD 50
#define TAMANIO_DIRECTOR 100

typedef struct
{
    char titulo[TAMANIO_TITULO];
    int anio;
    char nacionalidad[50];
    int director;
    int estado;
    int identificador;
}ePelicula;

void iniciar_ePelicula(ePelicula listado[], int cantidad);

int buscarLibre_ePelicula(ePelicula listado[], int cantidad, int ilogico);

int alta_ePelicula(ePelicula listado[], int cantidad);

int baja_ePelicula(ePelicula listado[], int cantidad, int id);

int contarAltas_ePelicula(ePelicula listado[], int cantidad);

int generarListaOrdenadaDeIds_ePelicula(ePelicula listado[], int cantidad, int listaDeIdentificadores[], int cantidadDeIds);

int generarIdentificador_ePelicula(ePelicula listado[], int cantidad);

void ordenarPorNombre_ePelicula(ePelicula listado[], int cantidad);

int siguienteId_ePelicula(ePelicula listado[],int cantidad);

void mostrarElemento_ePelicula(ePelicula elemento);

void mostrarListado_ePelicula(ePelicula listado[], int cantidad);

int menuPrincipal(void);
