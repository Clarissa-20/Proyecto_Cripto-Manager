#include "Xor.h"

Xor::Xor() {}

Xor::~Xor() {}

std::string Xor::cifrar(const std::string& texto, int clave) {
    std::string resultado = texto;
    char k = static_cast<char>(clave);
    for (size_t i = 0; i < resultado.length(); ++i) {
        resultado[i] = resultado[i] ^ k;
    }
    return resultado;
}

std::string Xor::descifrar(const std::string& texto, int clave) {
    return cifrar(texto, clave);
}

void Xor::cifrarBinario(char* buffer, long tamano, const std::string& claveSecreta) {
    if (claveSecreta.empty()) return;
    long longitudClave = claveSecreta.length();

    for (long i = 0; i < tamano; ++i) {
        buffer[i] = buffer[i] ^ claveSecreta[i % longitudClave];
    }
}