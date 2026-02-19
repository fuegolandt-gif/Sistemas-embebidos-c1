/* Ejercicio 4: Sumar los primeros N números impares 
*/

#include <stdio.h>

int main() {
    // Definimos el número de impares a sumar directamente
    int NUMERO = 8; 

    int suma = 0;
    
    // Imprimir y sumar los primeros NUMERO números impares
    for (int i = 1; i <= NUMERO; i++) {
        int impar = 2 * i - 1;
        suma += impar;
        
        // Imprimimos el número impar
        printf("%d", impar);
        
        // Imprimir el signo '+' si no es el último número
        if (i < NUMERO) {
            printf("+");
        }
    }
    
    // Imprimir el resultado final con un salto de línea
    printf("=%d\n", suma);

    return 0;
}