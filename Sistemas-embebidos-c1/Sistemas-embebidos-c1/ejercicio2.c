/* Ejercicio 2: Calcular la raíz cuadrada de un número usando el método de Newton 
*/

#include <stdio.h>

// Función que calcula la raíz cuadrada usando el metodo de newton
double raizNewton(int NUMERO) {
    double aproximacion = NUMERO;   // Valor inicial
    double anterior = 0;

    // Repetimos hasta que la diferencia sea muy pequeña
    
    while ((aproximacion - anterior > 0.000001) || (anterior - aproximacion > 0.000001)) {
        anterior = aproximacion;
        aproximacion = (aproximacion + NUMERO / aproximacion) / 2;
    }

    return aproximacion;
}

int main() {
    int NUMERO = 25; // se cambia este valor por el número que se desea calcular la raíz cuadrada

    // Calculamos el resultado llamando a la función
    double resultado = raizNewton(NUMERO);

    // Mostramos los resultados de forma sencilla
    printf("Numero: %d\n", NUMERO);
    printf("Raiz cuadrada usando Newton: %f\n", resultado);

    return 0;
}