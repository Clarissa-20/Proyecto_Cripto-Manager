// #ifndef CESAR_H
// #define CESAR_H

// #include "Cifrador.h"

// class Cesar: public Cifrador{
// public:
//     Cesar();
//     ~Cesar();

//     std::string cifrar(const std::string& texto, int clave) override;
//     std::string descifrar(const std::string& texto, int clave) override;
// };

// #endif // CESAR_H

#ifndef CESAR_H
#define CESAR_H

#include "Cifrador.h"

class Cesar : public Cifrador {
public:
    Cesar();
    ~Cesar();

    std::string cifrar(const std::string& texto, int clave) override;
    std::string descifrar(const std::string& texto, int clave) override;

    // Métodos para archivos (siguiendo la idea de XOR)
    bool cifrarArchivo(const std::string& nombreArchivoEntrada, const std::string& nombreArchivoSalida, int clave);
    bool descifrarArchivo(const std::string& nombreArchivoEntrada, const std::string& nombreArchivoSalida, int clave);
};

#endif // CESAR_H