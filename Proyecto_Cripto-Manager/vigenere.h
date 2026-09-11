#ifndef VIGENERE_H
#define VIGENERE_H

#include "Cifrador.h"

class Vigenere : public Cifrador {
public:
    Vigenere();
    ~Vigenere();

    std::string cifrar(const std::string& texto, int claveNumIgnorada) override;
    std::string descifrar(const std::string& texto, int claveNumIgnorada) override;

    std::string cifrarConClaveTexto(const std::string& texto, const std::string& claveTexto);
    std::string descifrarConClaveTexto(const std::string& texto, const std::string& claveTexto);
};

#endif