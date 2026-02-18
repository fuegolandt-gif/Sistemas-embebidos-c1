#include <iostream>

int main() {
    int NUMERO;
    if (!(std::cin >> NUMERO))
        return 0;
    if (NUMERO < 1000 || NUMERO > 9999)
        return 0;

    int unidad = NUMERO % 10;
    int decena = (NUMERO / 10) % 10;
    int centena = (NUMERO / 100) % 10;
    int unidad_de_mil = (NUMERO / 1000) % 10;

    std::cout << "{'Número' : " << NUMERO
              << ", 'Unidad de mil' : " << unidad_de_mil
                << ", 'Centena' : " << centena
                << ", 'Decena' : " << decena
                << ", 'Unidad' : " << unidad
                  << "}\n";

    return 0;
}
