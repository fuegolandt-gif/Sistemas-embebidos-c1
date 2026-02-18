#include <iostream>
using namespace std;

// Función que calcula la raíz cuadrada usando el método de Newton
double raizNewton(int NUMERO) {
    double aproximacion = NUMERO;   // Valor inicial
    double anterior = 0;

    // Repetimos hasta que la diferencia sea muy pequeña
    while (aproximacion - anterior > 0.000001 || anterior - aproximacion > 0.000001) {
        anterior = aproximacion;
        aproximacion = (aproximacion + NUMERO / aproximacion) / 2;
    }

    return aproximacion;
}

int main() {
    int NUMERO;

    cout << "Ingrese un numero entero positivo: ";
    cin >> NUMERO;

    double resultado = raizNewton(NUMERO);

    cout << "{'Numero' : " << NUMERO 
         << ", 'Raiz cuadrada usando Newton' : " 
         << resultado << "}" << endl;

    return 0;
}