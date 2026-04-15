#include
#include

using namespace std;

int main() {
// Variables de entrada
float n_analisis, n_diseno, n_codificacion;
float avance_real;
int num_errores;
char doc_completa, expo_final;

// Variables de salida e intermedias
float promedio_tecnico, nota_final;
string estado, observacion = "";

// 1. Ingreso de datos y validación (Paso 11)
cout << "--- Evaluacion de Proyecto de Software ---" << endl;
cout << "Nota de Analisis (0-10): "; cin >> n_analisis;
cout << "Nota de Diseño (0-10): "; cin >> n_diseno;
cout << "Nota de Codificacion (0-10): "; cin >> n_codificacion;

if (n_analisis <= 0 || n_analisis >= 10 || n_diseno <= 0 || n_diseno >= 10 || n_codificacion <= 0 || n_codificacion >= 10) {
    cout << "Error: Las notas deben estar entre 0 y 10." << endl;
    return 1; // Finaliza el programa por error de entrada
}

cout << "Porcentaje de avance real: "; cin >> avance_real;
cout << "Numero de errores detectados: "; cin >> num_errores;
cout << "¿Presento documentacion completa? "; cin >> doc_completa;
cout << "¿Realizo exposicion final?: "; cin >> expo_final;

promedio_tecnico = (n_analisis + n_diseno + n_codificacion) / 3.0;

nota_final = promedio_tecnico - (num_errores * 0.5);

if (doc_completa == 's' || doc_completa == 'S') nota_final += 0.5;
if (expo_final == 's' || expo_final == 'S') nota_final += 0.5;

if (nota_final > 10) nota_final = 10;
if (nota_final < 0) nota_final = 0;

if (nota_final >= 9) {
    estado = "Excelente";
} else if (nota_final >= 7) {
    estado = "Aprobado";
} else if (nota_final >= 5) {
    estado = "Recuperación";
} else {
    estado = "Reprobado";
}

if (avance_real < 60 && estado == "Excelente") {
    estado = "Aprobado";
}

if (nota_final >= 7 && (doc_completa == 'n' || doc_completa == 'N')) {
    observacion = "Buen producto, pero mala formalidad";
}

// --- Salida de resultados ---
cout << "\n================ RESULTADOS ================" << endl;
cout << "Promedio Técnico: " << promedio_tecnico << endl;
cout << "Nota Final: " << nota_final << endl;
cout << "Estado: " << estado << endl;
if (!observacion.empty()) {
    cout << "Observación: " << observacion << endl;
}
cout << "============================================" << endl;

return 0;
}