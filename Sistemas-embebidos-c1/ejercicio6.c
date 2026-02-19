/*
Enunciado:
Leer un número entero en la variable VALOR. Utilizar operadores de bits (bitwise)
para determinar si el número es par o impar (verificando el bit menos significativo)
y mostrar el resultado. No está permitido usar el operador de módulo (%).

Integrantes:
- Bohorquez Camilo, Gomez Diego, Gutierrez Juan, Rapello Julian. 
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Dato declarado en el programa (sin pedir entrada al usuario). */
    const char DATO[] = "0";

    char *fin = NULL;
    long convertido = strtol(DATO, &fin, 10);

    /*
    Si el dato no representa un entero válido, se informa el error.
    Casos: cadena vacía, sin dígitos, o con caracteres extra.
    */
    if (DATO[0] == '\0' || fin == DATO || *fin != '\0') {
        puts("Error: el tipo de dato no es el correcto y el programa no se puede ejecutar.");
        return 1;
    }

    /* Validación de compatibilidad con int (variable VALOR). */
    /* el int incluye 32 bits, por lo que si pasa de un numero mayor en esta parte saldra ese error y se terminara el programa*/
    int VALOR = (int)convertido;
    if ((long)VALOR != convertido) {
        puts("Error: el tipo de dato no es el correcto y el programa no se puede ejecutar.");
        return 1;
    }

    /* Verificación del bit menos significativo sin usar % */
    if ((VALOR & 1) == 0) {
        puts("PAR");
    } else {
        puts("IMPAR");
    }

    return 0;
}