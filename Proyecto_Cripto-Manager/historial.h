#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <string>

struct Registro {
    std::string usuario;
    std::string operacion;
    std::string fechaHora;
};

class Historial {
private:
    Registro* registros;
    int capacidad;
    int contador;

    void redimensionar();

public:
    Historial(int capacidadInicial = 10);
    ~Historial();

    int obtenerTotalOperaciones() const;
    void agregarOperacion(const std::string& usuario, const std::string& operacion);
    void mostrarHistorial() const;

    void ordenarPorUsuario();

    int buscarPorUsuario(const std::string& usuarioBuscado) const;

    static std::string obtenerFechaHoraActual();
};

#endif