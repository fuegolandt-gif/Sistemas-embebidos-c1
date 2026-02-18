#include <iostream>
using namespace std;

int main() {
    int NUMERO;

    cout << "Ingrese un numero entero positivo: ";
    cin >> NUMERO;

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

    cout << "Numeros primos menores que " << NUMERO << ":" << endl;

    for (int i = 2; i < NUMERO; i++) {
        if (esPrimo[i]) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}