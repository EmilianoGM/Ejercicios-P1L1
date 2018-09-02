/******************************************************************
* Programa: Ejemplo Clase 3
*
* Objetivo:
*   -Crear una función que permita ingresar un numero al usuario y lo retorne.
*   -Crear una función que reciba el radio de un círculo y retorne su área
*   -Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule
*    el área de un círculo cuyo radio es ingresado por el usuario
*   -Documentar las funciones al estilo Doxygen
* *******************************************************************/


#include <stdio.h>
#include <stdlib.h>

float pedirNumero(void);
float calcularAreaDeCirculo(float);

int main()
{
    float radio;
    float area;

    radio = pedirNumero();
    area = calcularAreaDeCirculo(radio);
    printf("El area del circulo es %.2f\n", area);

    return 0;
}

float pedirNumero(void){
    float numero;

    printf("Ingrese un numero:\n");
    setbuf(stdin, NULL);
    scanf("%f", &numero);

    return numero;
}

float calcularAreaDeCirculo(float radio){
    float resultado;
    resultado = 3.14 * radio * radio;
    return resultado;
}
