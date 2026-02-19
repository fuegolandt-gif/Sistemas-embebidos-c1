/*
Enunciado:
En sistemas embebidos, los registros suelen empaquetar varios estados.
Leer una variable de 8 bits llamada REGISTRO_ESTADO. El programa debe extraer
y mostrar por separado el valor de los 4 bits menos significativos (nibble inferior)
y el estado (0 o 1) del bit numero 5. Usar exclusivamente operadores de bits (&, >>).

Integrantes:
- Bohorquez Camilo, Gomez Diego, Gutierrez Juan, Rapello Julian. 
*/ 
#include <stdint.h>
#include <stdio.h>

// Función para imprimir un número en binario (8 bits)
void imprimir_binario(uint8_t num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main(void) {
    int registro_estado_entrada = 181; /* Valor de ejemplo: 0 a 255 */

    if (registro_estado_entrada < 0 || registro_estado_entrada > 255) {
        printf("El tipo de dato no es el correcto y el programa no se puede ejecutar.\n");
        return 0;
    }

    uint8_t REGISTRO_ESTADO = (uint8_t)registro_estado_entrada;
    uint8_t nibble_inferior = REGISTRO_ESTADO & 0x0F;
    uint8_t bit_5 = (REGISTRO_ESTADO >> 5) & 0x01;

    printf("REGISTRO_ESTADO en binario: ");
    imprimir_binario(REGISTRO_ESTADO);
    printf("\n");

    printf("{\"nibble_inferior\": %u, \"bit_5\": %u}\n", nibble_inferior, bit_5);

    return 0;
}