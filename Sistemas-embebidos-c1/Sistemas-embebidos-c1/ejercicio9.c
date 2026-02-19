#include <stdio.h>

int main() {
    int bits[] = {1, 0, 1, 1, 0, 1, 1};
    int longitud = sizeof(bits) / sizeof(bits[0]);

    int estado = 0;

    for (int i = 0; i < longitud; i++) {
        int bit = bits[i];

        switch (estado) {
            case 0:
                estado = (bit == 1) ? 1 : 0;
                break;
            case 1:
                estado = (bit == 0) ? 2 : 1;
                break;
            case 2:
                estado = (bit == 1) ? 3 : 0;
                break;
            case 3:
                if (bit == 1) {
                    printf("Cerradura abierta\n");
                    estado = 0;
                } else {
                    estado = 2;
                }
                break;
        }
    }

    return 0;
}
