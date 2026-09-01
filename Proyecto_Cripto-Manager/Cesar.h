#ifndef CESAR_H
#define CESAR_H

#include "Cifrador.h"

class Cesar: public Cifrador{
public:
    Cesar();
    ~Cesar();

    std::string cifrar(const std::string& texto, int clave) override;
    std::string descifrar(const std::string& texto, int clave) override;
};

#endif // CESAR_H
