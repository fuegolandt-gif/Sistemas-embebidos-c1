#include <iostream>

using namespace std;

int main() {
    int NUMERO;
    // Pedir al usuario un número
    cout << "Ingrese un numero: ";
    cin >> NUMERO;

    int suma = 0;
    
    // Imprimir y sumar los primeros NUMERO números impares
    for (int i = 1; i <= NUMERO; i++) {
        int impar = 2 * i - 1;
        suma += impar;
        cout << impar;
        
        // Imprimir el signo '+' si no es el último número
        if (i < NUMERO) {
            cout << "+";
        }
    }
    
    // Imprimir el resultado final
    cout << "=" << suma << endl;

    return 0;
}
