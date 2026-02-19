/* */

#include <stdio.h>

#
int main() {
    int LECTURAS_ADC[10] = {100, 102, 101, 105, 107, 106, 108, 110, 109, 111};
    float FILTRADAS[10];

    for (int i = 0; i < 10; i++) {
        if (i < 2 || i == 9) {
            FILTRADAS[i] = 0;
        } else {
            FILTRADAS[i] = (LECTURAS_ADC[i] +
                            LECTURAS_ADC[i - 1] +
                            LECTURAS_ADC[i - 2]) / 3.0;
        }
    }

    printf("{'Lecturas originales' : [");
    for (int i = 0; i < 10; i++) {
        printf("%d", LECTURAS_ADC[i]);
        if (i < 9) printf(", ");
    }
    
    printf("]}\n");

    printf("{'Lecturas filtradas' : [");
    
    for (int i = 0; i < 10; i++) {
        printf("%.2f", FILTRADAS[i]);
        if (i < 9) printf(", ");
    }
    printf("]}\n");

    return 0;
}
