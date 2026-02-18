#include <iostream>
#include <cmath>   // Para funciones matemáticas (sin, cos, sqrt, pow)
#include <limits>  // Para limpiar el buffer de entrada

using namespace std;

// Constante para PI
const double PI = 3.14159265358979323846;

// Función para limpiar la pantalla (funciona en Mac/Linux/Windows)
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Función para pausar y esperar al usuario
void esperarUsuario() {
    cout << "\nPresiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Función para dibujar la interfaz
void mostrarMenu() {
    limpiarPantalla();
    cout << "==========================================" << endl;
    cout << "      CALCULADORA CIENTIFICA C++          " << endl;
    cout << "==========================================" << endl;
    cout << "  1. Suma                7. Seno (sin)" << endl;
    cout << "  2. Resta               8. Coseno (cos)" << endl;
    cout << "  3. Multiplicacion      9. Tangente (tan)" << endl;
    cout << "  4. Division           10. Logaritmo (log10)" << endl;
    cout << "  5. Potencia (x^y)     11. Logaritmo Natural (ln)" << endl;
    cout << "  6. Raiz Cuadrada      12. Salir" << endl;
    cout << "==========================================" << endl;
    cout << " Selecciona una opcion (1-12): ";
}

int main() {
    int opcion;
    double num1, num2;
    bool continuar = true;

    while (continuar) {
        mostrarMenu();
        
        // Validación de entrada para el menú
        if (!(cin >> opcion)) {
            cout << "\nError: Por favor ingresa un numero valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            esperarUsuario();
            continue;
        }

        if (opcion == 12) {
            continuar = false;
            cout << "\nGracias por usar la calculadora. Adios!" << endl;
            break;
        }

        // Lógica de operaciones
        switch (opcion) {
            case 1: // Suma
                cout << "\nIngresa el primer numero: "; cin >> num1;
                cout << "Ingresa el segundo numero: "; cin >> num2;
                cout << "\n>> Resultado: " << num1 + num2 << endl;
                break;

            case 2: // Resta
                cout << "\nIngresa el primer numero: "; cin >> num1;
                cout << "Ingresa el segundo numero: "; cin >> num2;
                cout << "\n>> Resultado: " << num1 - num2 << endl;
                break;

            case 3: // Multiplicación
                cout << "\nIngresa el primer numero: "; cin >> num1;
                cout << "Ingresa el segundo numero: "; cin >> num2;
                cout << "\n>> Resultado: " << num1 * num2 << endl;
                break;

            case 4: // División
                cout << "\nIngresa el dividendo: "; cin >> num1;
                cout << "Ingresa el divisor: "; cin >> num2;
                if (num2 == 0) 
                    cout << "\nError: No se puede dividir por cero." << endl;
                else 
                    cout << "\n>> Resultado: " << num1 / num2 << endl;
                break;

            case 5: // Potencia
                cout << "\nIngresa la base: "; cin >> num1;
                cout << "Ingresa el exponente: "; cin >> num2;
                cout << "\n>> Resultado: " << pow(num1, num2) << endl;
                break;

            case 6: // Raíz Cuadrada
                cout << "\nIngresa el numero: "; cin >> num1;
                if (num1 < 0)
                    cout << "\nError: No existe raiz real de numero negativo." << endl;
                else
                    cout << "\n>> Resultado: " << sqrt(num1) << endl;
                break;

            case 7: // Seno
                cout << "\nIngresa el angulo en GRADOS: "; cin >> num1;
                cout << "\n>> Resultado: " << sin(num1 * PI / 180.0) << endl;
                break;

            case 8: // Coseno
                cout << "\nIngresa el angulo en GRADOS: "; cin >> num1;
                cout << "\n>> Resultado: " << cos(num1 * PI / 180.0) << endl;
                break;

            case 9: // Tangente
                cout << "\nIngresa el angulo en GRADOS: "; cin >> num1;
                cout << "\n>> Resultado: " << tan(num1 * PI / 180.0) << endl;
                break;
            
            case 10: // Log Base 10
                cout << "\nIngresa el numero: "; cin >> num1;
                if(num1 <= 0) cout << "\nError: Solo numeros positivos." << endl;
                else cout << "\n>> Resultado: " << log10(num1) << endl;
                break;

            case 11: // Log Natural
                cout << "\nIngresa el numero: "; cin >> num1;
                if(num1 <= 0) cout << "\nError: Solo numeros positivos." << endl;
                else cout << "\n>> Resultado: " << log(num1) << endl;
                break;

            default:
                cout << "\nOpcion no valida. Intenta de nuevo." << endl;
        }
        esperarUsuario();
    }

    return 0;
}
