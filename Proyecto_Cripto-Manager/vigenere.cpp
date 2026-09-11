#include "Vigenere.h"

Vigenere::Vigenere() {}

Vigenere::~Vigenere() {}

std::string Vigenere::cifrar(const std::string& texto, int claveNumIgnorada) {
    return cifrarConClaveTexto(texto, "KEY");
}

std::string Vigenere::descifrar(const std::string& texto, int claveNumIgnorada) {
    return descifrarConClaveTexto(texto, "KEY");
}

std::string Vigenere::cifrarConClaveTexto(const std::string& texto, const std::string& claveTexto) {
    if (claveTexto.empty()) return texto;

    std::string resultado = "";
    size_t indiceClave = 0;
    size_t longitudClave = claveTexto.length();

    for (size_t i = 0; i < texto.length(); ++i) {
        char c = texto[i];
        char k = claveTexto[indiceClave % longitudClave];

        if (c >= 'a' && c <= 'z') {
            int desplazamiento = (k >= 'A' && k <= 'Z') ? (k - 'A') : (k - 'a');
            c = char(((c - 'a' + desplazamiento) % 26 + 26) % 26 + 'a');
            indiceClave++;
        } else if (c >= 'A' && c <= 'Z') {
            int desplazamiento = (k >= 'A' && k <= 'Z') ? (k - 'A') : (k - 'a');
            c = char(((c - 'A' + desplazamiento) % 26 + 26) % 26 + 'A');
            indiceClave++;
        }
        resultado += c;
    }
    return resultado;
}

std::string Vigenere::descifrarConClaveTexto(const std::string& texto, const std::string& claveTexto) {
    if (claveTexto.empty()) return texto;

    std::string resultado = "";
    size_t indiceClave = 0;
    size_t longitudClave = claveTexto.length();

    for (size_t i = 0; i < texto.length(); ++i) {
        char c = texto[i];
        char k = claveTexto[indiceClave % longitudClave];

        if (c >= 'a' && c <= 'z') {
            int desplazamiento = (k >= 'A' && k <= 'Z') ? (k - 'A') : (k - 'a');
            c = char(((c - 'a' - desplazamiento) % 26 + 26) % 26 + 'a');
            indiceClave++;
        } else if (c >= 'A' && c <= 'Z') {
            int desplazamiento = (k >= 'A' && k <= 'Z') ? (k - 'A') : (k - 'a');
            c = char(((c - 'A' - desplazamiento) % 26 + 26) % 26 + 'A');
            indiceClave++;
        }
        resultado += c;
    }
    return resultado;
}