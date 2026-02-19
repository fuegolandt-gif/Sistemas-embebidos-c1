/* Ejercicio 1: Descomponer un número de 4 dígitos */

#include <stdio.h>

int main() {
    // Definimos el número directamente 
    int NUMERO = 4567; 

    // Verificamos que sea de 4 dígitos 
    if (NUMERO < 1000 || NUMERO > 9999) {
        return 0;
    }

    // Cálculos
    int unidad = NUMERO % 10;
    int decena = (NUMERO / 10) % 10;
    int centena = (NUMERO / 100) % 10;
    int unidad_de_mil = (NUMERO / 1000) % 10;

    // Salida simple línea por línea
    printf("Numero: %d\n", NUMERO);
    printf("Unidad de mil: %d\n", unidad_de_mil);
    printf("Centena: %d\n", centena);
    printf("Decena: %d\n", decena);
    printf("Unidad: %d\n", unidad);

    return 0;
}