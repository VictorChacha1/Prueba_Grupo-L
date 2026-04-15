#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

// ==================== CLASE REPUESTO ====================
class Repuesto {
private:
    string codigo;
    string nombre;
    double precioUnitario;
    int cantidad;

public:
    Repuesto() {
        codigo = "";
        nombre = "";
        precioUnitario = 0.0;
        cantidad = 0;
    }

    void setCodigo(string c)    { codigo = c; }
    void setNombre(string n)    { nombre = n; }
    void setPrecio(double p)    { precioUnitario = p; }
    void setCantidad(int c)     { cantidad = c; }

    string getCodigo()          { return codigo; }
    string getNombre()          { return nombre; }
    double getPrecio()          { return precioUnitario; }
    int getCantidad()           { return cantidad; }
};

// ==================== CLASE ORDENTALLER ====================
class OrdenTaller {
private:
    string placa;
    string cliente;
    string cedula;
    string tipoServicio;
    double horasManoObra;
    double costoPorHora;
    string estado;
    string repuestosUsados[5];
    int cantidadRepuestos[5];
    int numRepuestos;

public:
    OrdenTaller() {
        placa = "";
        cliente = "";
        cedula = "";
        tipoServicio = "";
        horasManoObra = 0.0;
        costoPorHora = 0.0;
        estado = "pendiente";
        numRepuestos = 0;
    }

    void setPlaca(string p)         { placa = p; }
    void setCliente(string c)       { cliente = c; }
    void setCedula(string c)        { cedula = c; }
    void setTipoServicio(string t)  { tipoServicio = t; }
    void setHoras(double h)         { horasManoObra = h; }
    void setCostoPorHora(double c)  { costoPorHora = c; }
    void setEstado(string e)        { estado = e; }

    string getPlaca()               { return placa; }
    string getCliente()             { return cliente; }
    string getCedula()              { return cedula; }
    string getTipoServicio()        { return tipoServicio; }
    double getHoras()               { return horasManoObra; }
    double getCostoPorHora()        { return costoPorHora; }
    string getEstado()              { return estado; }
    int getNumRepuestos()           { return numRepuestos; }
    string getRepuestoNombre(int i) { return repuestosUsados[i]; }
    int getRepuestoCantidad(int i)  { return cantidadRepuestos[i]; }

    void agregarRepuesto(string nombre, int cant) {
        if (numRepuestos < 5) {
            repuestosUsados[numRepuestos] = nombre;
            cantidadRepuestos[numRepuestos] = cant;
            numRepuestos++;
        }
    }

    double getCostoManoObra() {
        return horasManoObra * costoPorHora;
    }

    double getCostoRepuestos(Repuesto repuestos[], int numRep) {
        double total = 0;
        for (int i = 0; i < numRepuestos; i++) {
            for (int j = 0; j < numRep; j++) {
                if (repuestosUsados[i] == repuestos[j].getNombre()) {
                    total += repuestos[j].getPrecio() * cantidadRepuestos[i];
                }
            }
        }
        return total;
    }

    double getValorFinal(Repuesto repuestos[], int numRep) {
        double subtotal = getCostoManoObra() + getCostoRepuestos(repuestos, numRep);
        double descuento = 0;
        if (tipoServicio == "preventivo") descuento = subtotal * 0.10;
        else if (tipoServicio == "express") descuento = subtotal * 0.05;
        double impuesto = (subtotal - descuento) * 0.15;
        return subtotal - descuento + impuesto;
    }

    string getClasificacion(Repuesto repuestos[], int numRep) {
        double valor = getValorFinal(repuestos, numRep);
        if (valor < 100) return "Menor";
        else if (valor <= 500) return "Moderada";
        else return "Mayor";
    }
};

// ==================== ARREGLOS GLOBALES ====================
const int MAX = 50;
Repuesto repuestos[MAX];
OrdenTaller ordenes[MAX];
int numRepuestos = 0;
int numOrdenes = 0;

// ==================== MENU AHORCADO ====================
void menuAhorcado() {
    cout << "\n===== MODULO AHORCADO - TALLER =====" << endl;
    cout << "  (modulo en construccion)" << endl;
}

// ==================== MENU PRINCIPAL ====================
void menuPrincipal() {
    int opcion;
    do {
        cout << "\n========================================" << endl;
        cout << "   SISTEMA DE GESTION - TALLER MECANICO" << endl;
        cout << "========================================" << endl;
        cout << "  1. Registrar repuesto" << endl;
        cout << "  2. Registrar orden de trabajo" << endl;
        cout << "  3. Buscar orden" << endl;
        cout << "  4. Ordenar ordenes" << endl;
        cout << "  5. Ver historial" << endl;
        cout << "  6. Total facturado (recursivo)" << endl;
        cout << "  7. Modulo Ahorcado" << endl;
        cout << "  0. Salir" << endl;
        cout << "----------------------------------------" << endl;
        cout << "  Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: cout << "\n[Registrar repuesto - en construccion]" << endl; break;
            case 2: cout << "\n[Registrar orden - en construccion]" << endl; break;
            case 3: cout << "\n[Buscar orden - en construccion]" << endl; break;
            case 4: cout << "\n[Ordenar ordenes - en construccion]" << endl; break;
            case 5: cout << "\n[Historial - en construccion]" << endl; break;
            case 6: cout << "\n[Total facturado - en construccion]" << endl; break;
            case 7: menuAhorcado(); break;
            case 0: cout << "\nCerrando sistema..." << endl; break;
            default: cout << "\nOpcion invalida." << endl;
        }
    } while (opcion != 0);
}

// ==================== MAIN ====================
int main() {
    menuPrincipal();
    return 0;
}