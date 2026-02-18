#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_message.H>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

// Widgets globales para acceder a ellos desde las funciones
Fl_Float_Input *input1;
Fl_Float_Input *input2;
Fl_Box *box_resultado;

// Función auxiliar para obtener números
double get_num(Fl_Float_Input *in) {
    const char *val = in->value();
    if (!val || val[0] == 0) return 0.0; // Si está vacío devuelve 0
    return atof(val);
}

// Función auxiliar para mostrar resultado
void set_result(double val) {
    static char buffer[100];
    // Formatear el número a texto (string)
    sprintf(buffer, "Res: %.4f", val);
    box_resultado->label(buffer); // Poner el texto en la etiqueta
}

// --- CALLBACKS (Lo que pasa al hacer clic) ---

void suma_cb(Fl_Widget *, void *) {
    double r = get_num(input1) + get_num(input2);
    set_result(r);
}

void resta_cb(Fl_Widget *, void *) {
    double r = get_num(input1) - get_num(input2);
    set_result(r);
}

void multi_cb(Fl_Widget *, void *) {
    double r = get_num(input1) * get_num(input2);
    set_result(r);
}

void div_cb(Fl_Widget *, void *) {
    double n2 = get_num(input2);
    if (n2 == 0) fl_alert("Error: No puedes dividir por cero!");
    else set_result(get_num(input1) / n2);
}

void sin_cb(Fl_Widget *, void *) {
    // Calcula el Seno del primer número (convierte a radianes)
    double r = sin(get_num(input1) * 3.14159265 / 180.0);
    set_result(r);
}

void cos_cb(Fl_Widget *, void *) {
    double r = cos(get_num(input1) * 3.14159265 / 180.0);
    set_result(r);
}

void sqrt_cb(Fl_Widget *, void *) {
    double n = get_num(input1);
    if (n < 0) fl_alert("Error: Raíz negativa!");
    else set_result(sqrt(n));
}

void pow_cb(Fl_Widget *, void *) {
    double r = pow(get_num(input1), get_num(input2));
    set_result(r);
}

// --- MAIN ---
int main(int argc, char **argv) {
    // Crear la ventana (Ancho, Alto, Título)
    Fl_Window *window = new Fl_Window(340, 320, "Calculadora C++ Mac");

    // Título interno
    Fl_Box *title = new Fl_Box(20, 10, 300, 30, "CALCULADORA CIENTIFICA");
    title->labelsize(18);
    title->labelfont(FL_BOLD);

    // Entradas de texto
    input1 = new Fl_Float_Input(80, 50, 200, 30, "Num 1:");
    input2 = new Fl_Float_Input(80, 90, 200, 30, "Num 2:");

    // Caja de Resultado (Grande y centrada)
    box_resultado = new Fl_Box(20, 130, 300, 40, "Res: 0.0");
    box_resultado->box(FL_DOWN_BOX); // Borde hundido
    box_resultado->color(FL_WHITE);
    box_resultado->labelsize(20);
    box_resultado->labelfont(FL_BOLD);

    // Botones - Fila 1
    Fl_Button *btn_sum = new Fl_Button(30, 190, 60, 40, "+");
    btn_sum->callback(suma_cb);
    
    Fl_Button *btn_res = new Fl_Button(100, 190, 60, 40, "-");
    btn_res->callback(resta_cb);

    Fl_Button *btn_mul = new Fl_Button(170, 190, 60, 40, "x");
    btn_mul->callback(multi_cb);

    Fl_Button *btn_div = new Fl_Button(240, 190, 60, 40, "/");
    btn_div->callback(div_cb);

    // Botones - Fila 2 (Científicos)
    Fl_Button *btn_sin = new Fl_Button(30, 250, 60, 40, "Sin");
    btn_sin->tooltip("Seno del Num 1 (Grados)");
    btn_sin->callback(sin_cb);

    Fl_Button *btn_cos = new Fl_Button(100, 250, 60, 40, "Cos");
    btn_cos->tooltip("Coseno del Num 1 (Grados)");
    btn_cos->callback(cos_cb);

    Fl_Button *btn_pow = new Fl_Button(170, 250, 60, 40, "^");
    btn_pow->tooltip("Num 1 elevado a Num 2");
    btn_pow->callback(pow_cb);

    Fl_Button *btn_sqrt = new Fl_Button(240, 250, 60, 40, "Raiz");
    btn_sqrt->tooltip("Raíz cuadrada del Num 1");
    btn_sqrt->callback(sqrt_cb);

    window->end();
    window->show(argc, argv);
    return Fl::run();
}