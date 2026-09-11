#include "Historial.h"
#include <iostream>
#include <ctime>

Historial::Historial(int capacidadInicial) {
    capacidad = capacidadInicial;
    contador = 0;
    registros = new Registro[capacidad];
}

Historial::~Historial() {
    delete[] registros;
}

void Historial::redimensionar() {
    capacidad *= 2;
    Registro* nuevoArreglo = new Registro[capacidad];
    for (int i = 0; i < contador; ++i) {
        nuevoArreglo[i] = registros[i];
    }
    delete[] registros;
    registros = nuevoArreglo;
}

std::string Historial::obtenerFechaHoraActual() {
    std::time_t tiempoActual = std::time(nullptr);
    char buffer[80];
    struct tm* tiempoInfo = std::localtime(&tiempoActual);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tiempoInfo);
    return std::string(buffer);
}

void Historial::agregarOperacion(const std::string& usuario, const std::string& operacion) {
    if (contador >= capacidad) {
        redimensionar();
    }
    registros[contador].usuario = usuario;
    registros[contador].operacion = operacion;
    registros[contador].fechaHora = obtenerFechaHoraActual();
    contador++;
}

void Historial::mostrarHistorial() const {
    std::cout << "\n--- HISTORIAL DINAMICO DE OPERACIONES ---\n";
    for (int i = 0; i < contador; ++i) {
        std::cout << "[" << registros[i].fechaHora << "] "
                  << "Usuario: " << registros[i].usuario << " | "
                  << "Accion: " << registros[i].operacion << "\n";
    }
}

void Historial::ordenarPorUsuario() {
    for (int i = 0; i < contador - 1; ++i) {
        for (int j = 0; j < contador - i - 1; ++j) {
            if (registros[j].usuario > registros[j + 1].usuario) {
                Registro temp = registros[j];
                registros[j] = registros[j + 1];
                registros[j + 1] = temp;
            }
        }
    }
}

int Historial::buscarPorUsuario(const std::string& usuarioBuscado) const {
    for (int i = 0; i < contador; ++i) {
        if (registros[i].usuario == usuarioBuscado) {
            return i;
        }
    }
    return -1;
}

int Historial::obtenerTotalOperaciones() const {
    return contador;
}