/*
Ejercicio 8:
Crear una función que reciba tres variables booleanas (A, B, C)
y retorne el resultado de la siguiente expresión lógica:

F = (A · B) + C̅

El resultado debe mostrarse como una pequeña tabla de verdad
en la consola para todas las combinaciones posibles de las entradas.
*/

#include <stdio.h>

//Funcion Logica
int funcion_logica(int A, int B, int C) {
    int resultado;
    resultado = (A && B) || (!C);
    return resultado;
}

int main() {

    int A, B, C;

    printf("A B C | F\n");
    printf("-------------\n");

    // Generar todas las combinaciones posibles (2^3 = 8)
    for (A = 0; A <= 1; A++) {
        for (B = 0; B <= 1; B++) {
            for (C = 0; C <= 1; C++) {
                printf("%d %d %d | %d\n", A, B, C, funcion_logica(A, B, C));
            }
        }
    }

    return 0;
}