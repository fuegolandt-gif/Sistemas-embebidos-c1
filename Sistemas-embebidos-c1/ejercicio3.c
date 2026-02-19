/* Ejercicio 3: Encontrar números primos menores a un número dado usando la Criba de Eratóstenes 
*/

#include <stdio.h>
#include <stdbool.h> // Para usar el tipo bool en C

int main() {
    // Definimos el límite directamente
    int NUMERO = 20; // este es el valor que se cambia para encontrar los primos menores a este número. 

    // Arreglo para marcar si un número es primo
    bool esPrimo[NUMERO];

    // Inicializamos todos como verdaderos
    for (int i = 0; i < NUMERO; i++) {
        esPrimo[i] = true;
    }

    // 0 y 1 no son primos
    if (NUMERO > 0) esPrimo[0] = false;
    if (NUMERO > 1) esPrimo[1] = false;

    // Aplicamos la Criba de Eratóstenes
    for (int i = 2; i * i < NUMERO; i++) {
        if (esPrimo[i]) {
            for (int j = i * i; j < NUMERO; j += i) {
                esPrimo[j] = false;
            }
        }
    }

    // damos los resultados
    printf("Numeros primos menores que %d:\n", NUMERO);

    for (int i = 2; i < NUMERO; i++) {
        if (esPrimo[i]) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}