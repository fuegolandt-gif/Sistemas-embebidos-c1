#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_message.H> // Para ventanas de alerta
#include <string>
#include <iostream>
#include <stdexcept> // Para manejar errores de conversión

using namespace std;

// -- WIDGETS GLOBALES --
Fl_Input *entrada;
Fl_Box *resultado;

// -- FUNCIONES DE LÓGICA --

// Función para mostrar el resultado en la interfaz
void mostrar_resultado(long long numero) {
    static char buffer[100];
    sprintf(buffer, "%lld", numero); // Convierte el número a texto
    resultado->label(buffer);
}

// Callback: Convertir de BINARIO a Decimal
void bin_cb(Fl_Widget *, void *) {
    string texto = entrada->value();
    
    if (texto.empty()) {
        fl_alert("¡Error! Escribe un numero binario primero.");
        return;
    }

    try {
        // stoll convierte string a long long. 
        // El '2' indica que la base es binaria.
        long long decimal = stoll(texto, nullptr, 2);
        mostrar_resultado(decimal);
    } catch (const invalid_argument& e) {
        fl_alert("Error: El texto contiene caracteres que NO son binarios (0 o 1).");
    } catch (const out_of_range& e) {
        fl_alert("Error: El numero es demasiado grande.");
    }
}

// Callback: Convertir de HEXADECIMAL a Decimal
void hex_cb(Fl_Widget *, void *) {
    string texto = entrada->value();

    if (texto.empty()) {
        fl_alert("¡Error! Escribe un numero hexadecimal primero.");
        return;
    }

    try {
        // El '16' indica que la base es hexadecimal.
        long long decimal = stoll(texto, nullptr, 16);
        mostrar_resultado(decimal);
    } catch (const invalid_argument& e) {
        fl_alert("Error: Caracteres invalidos. Solo usa 0-9 y A-F.");
    } catch (const out_of_range& e) {
        fl_alert("Error: El numero es demasiado grande.");
    }
}

// Callback: Limpiar pantalla
void limpiar_cb(Fl_Widget *, void *) {
    entrada->value("");
    resultado->label("0");
}

// -- MAIN --
int main(int argc, char **argv) {
    // 1. Configuración de la Ventana
    Fl_Window *ventana = new Fl_Window(400, 300, "Conversor Bin/Hex");
    ventana->color(fl_rgb_color(240, 240, 240)); // Fondo gris claro

    // 2. Título
    Fl_Box *titulo = new Fl_Box(0, 20, 400, 30, "CONVERSOR DE SISTEMAS");
    titulo->labelfont(FL_BOLD);
    titulo->labelsize(20);

    // 3. Campo de Entrada
    entrada = new Fl_Input(120, 70, 200, 30, "Entrada:");
    entrada->tooltip("Escribe aquí tu número binario o hexadecimal");

    // 4. Botones de Acción
    Fl_Button *btn_bin = new Fl_Button(40, 130, 150, 40, "Es Binario (Base 2)");
    btn_bin->color(fl_rgb_color(200, 230, 255)); // Azul claro
    btn_bin->callback(bin_cb);

    Fl_Button *btn_hex = new Fl_Button(210, 130, 150, 40, "Es Hex (Base 16)");
    btn_hex->color(fl_rgb_color(255, 230, 200)); // Naranja claro
    btn_hex->callback(hex_cb);

    // 5. Área de Resultado
    Fl_Box *lbl_res = new Fl_Box(0, 190, 400, 20, "Resultado Decimal:");
    lbl_res->labelsize(14);
    
    resultado = new Fl_Box(100, 215, 200, 40, "0");
    resultado->box(FL_DOWN_BOX); // Caja hundida
    resultado->color(FL_WHITE);
    resultado->labelsize(24);
    resultado->labelfont(FL_BOLD);
    resultado->labelcolor(fl_rgb_color(0, 100, 0)); // Texto verde

    // 6. Botón Limpiar
    Fl_Button *btn_clear = new Fl_Button(150, 265, 100, 25, "Limpiar");
    btn_clear->callback(limpiar_cb);

    ventana->end();
    ventana->show(argc, argv);
    return Fl::run();
}