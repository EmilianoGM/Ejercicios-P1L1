/** \brief Solicita un numero decimal al usuario y lo retorna.
 *
 * \param mensaje[] char Mensaje mostrado para solicitar el numero.
 * \param mensajeError[] char Mensaje mostrado en caso de error, que no sea un numero o supere los limites.
 * \param minimo int Valor minimo aceptado.
 * \param maximo int Valor maximo aceptado.
 * \return int
 *
 */
int pedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo);

/** \brief Solicita un numero entero al usuario y lo retorna.
 *
 * \param mensaje[] char Mensaje mostrado para solicitar el numero.
 * \param mensajeError[] char Mensaje mostrado en caso de error, que no sea un numero o supere los limites.
 * \param minimo float Valor minimo aceptado.
 * \param maximo float Valor maximo aceptado.
 * \return float
 *
 */
float pedirFlotante(char mensaje[], char mensajeError[], float minimo, float maximo);

/** \brief
 *
 * \param mensaje[] char
 * \param mensajeError[] char
 * \return char
 *
 */
char pedirLetra(char mensaje[], char mensajeError[]);

/** \brief
 *
 * \param arrayNumerica[] int
 * \param tamanio int
 * \param mensaje[] char
 * \param mensajeError[] char
 * \param minimo int
 * \param maximo int
 * \return void
 *
 */
void pedirArrayNumericaDeEnteros(int arrayNumerica[], int tamanio, char mensaje[], char mensajeError[], int minimo, int maximo);

/** \brief
 *
 * \param arrayNumerica[] float
 * \param tamanio int
 * \param mensaje[] char
 * \param mensajeError[] char
 * \param minimo float
 * \param maximo float
 * \return void
 *
 */
void pedirArrayNumericaDeDecimales(float arrayNumerica[], int tamanio, char mensaje[], char mensajeError[],
                                   float minimo, float maximo);

/** \brief
 *
 * \param arrayLetras[] char
 * \param tamanio int
 * \param mensaje[] char
 * \param mensajeError[] char
 * \return void
 *
 */
void pedirArrayDeLetras(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[]);

/** \brief
 *
 * \param arrayAlfanumerica[] char
 * \param tamanio int
 * \param mensaje[] char
 * \param mensajeError[] char
 * \return void
 *
 */
void pedirArrayAlfanumerica(char arrayAlfanumerica[], int tamanio, char mensaje[], char mensajeError[]);

/** \brief
 *
 * \param arrayTexto[] char
 * \param tamanio int
 * \param mensaje[] char
 * \param mensajeError[] char
 * \return void
 *
 */
void pedirTexto(char arrayTexto[], int tamanio, char mensaje[], char mensajeError[]);

/** \brief
 *
 * \param cadenaNumerica[] char
 * \param tamanio int
 * \return int
 *
 */
int comprobarArrayNumerica(char cadenaNumerica[], int tamanio);

/** \brief
 *
 * \param cadenaDeLetras[] char
 * \param tamanio int
 * \return int
 *
 */
int comprobarArrayDeLetras(char cadenaDeLetras[], int tamanio);

/** \brief
 *
 * \param arrayAlfanumerica[] char
 * \param tamanio int
 * \return int
 *
 */
int comprobarArrayAlfanumerica(char arrayAlfanumerica[], int tamanio);

/** \brief
 *
 * \param cuit[] char
 * \param mensaje[] char
 * \param mensajeError[] char
 * \return void
 *
 */
void pedirCuit(char cuit[], char mensaje[], char mensajeError[]);
