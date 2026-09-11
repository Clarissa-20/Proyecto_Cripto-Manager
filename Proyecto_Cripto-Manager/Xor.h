#ifndef XOR_H
#define XOR_H

#include "Cifrador.h"
#include <string> //agg

class Xor : public Cifrador {
public:
    Xor();
    ~Xor();

    std::string cifrar(const std::string& texto, int clave) override;
    std::string descifrar(const std::string& texto, int clave) override;

    void cifrarBinario(char* buffer, long tamano, const std::string& claveSecreta);
};

#endif