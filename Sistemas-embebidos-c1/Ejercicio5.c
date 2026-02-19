/*
Ejercicio 5:
Preguntar al usuario un número entero y almacenar en la variable NUMERO.
Imprimir el valor de la posición NUMERO de la secuencia de Fibonacci
asumiendo que f0 = 0 y f1 = 1.
Verificar que NUMERO debe ser >= 2, en caso contrario,
mostrar un mensaje que NUMERO debe cumplir esa condición.

*/
#include <stdio.h>

int main() {

    int NUMERO = 5;   //Se declara el valor de NUMERO

    // Condición
    if (NUMERO < 2) {
        printf("Error: NUMERO debe ser mayor o igual a 2. ");
        return 0;
    }

    int f0 = 0;
    int f1 = 1;
    int fn;
    int i;

    // Cálculo de Fibonacci
    for (i = 2; i <= NUMERO; i++) {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }

    printf("El valor en la posicion %d de Fibonacci es: %d ", NUMERO, fn);

    return 0;
}