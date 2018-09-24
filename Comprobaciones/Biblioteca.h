/** \brief Solicita un numero entero al usuario y verifica que se haya intrucido un numero.
 * \param mensaje[] char Es el mensaje mostrado para solicitar el numero.
 * \param mensajeError[] char Es el mensaje mostrado en caso que no se introduzca un numero.
 * \return int Devuelve el numero ingresado.
 *
 */
int pedirEntero(char mensaje[], char mensajeError[]);

/** \brief Solicita un numero con decimales al usuario y verifica que se haya intrucido un numero.
 * \param mensaje[] char Es el mensaje mostrado para solicitar el numero.
 * \param mensajeError[] char Es el mensaje mostrado en caso que no se introduzca un numero.
 * \return float Devuelve el numero ingresado.
 *
 */
float pedirFlotante(char mensaje[], char mensajeError[]);
int comprobarArrayNumerica(char cadenaNumerica[]);
