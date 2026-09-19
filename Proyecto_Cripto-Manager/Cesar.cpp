#include "Cesar.h"
#include "ArchivoManager.h"

Cesar::Cesar() {}

Cesar::~Cesar() {}

std::string Cesar::cifrar(const std::string& texto, int clave) {
    std::string resultado = "";
    for(size_t i = 0; i < texto.length(); ++i){
        char c = texto[i];

        // cifrado para letras minusculas
        if(c >= 'a' && c <= 'z'){
            c = char(((c - 'a' + clave) % 26 + 26) % 26 + 'a');
        }
        // cifrado para letras mayusculas
        else if(c >= 'A' && c <= 'Z'){
            c = char(((c - 'A' + clave) % 26 + 26) % 26 + 'A');
        }

        // los caracteres especiales o numeros se mantienen igual
        resultado += c;
    }
    return resultado;
}

std::string Cesar::descifrar(const std::string& texto, int clave) {
    // descifrar en cesar es simplemente cifrar con la clave negativa
    return cifrar(texto, -clave);
}

bool Cesar::cifrarArchivo(const std::string& nombreArchivoEntrada, const std::string& nombreArchivoSalida, int clave) {
    std::string contenido = "";
    if (!ArchivoManager::leerArchivoTexto(nombreArchivoEntrada, contenido)) {
        return false;
    }
    std::string contenidoCifrado = cifrar(contenido, clave);
    return ArchivoManager::escribirArchivoTexto(nombreArchivoSalida, contenidoCifrado);
}

bool Cesar::descifrarArchivo(const std::string& nombreArchivoEntrada, const std::string& nombreArchivoSalida, int clave) {
    std::string contenido = "";
    if (!ArchivoManager::leerArchivoTexto(nombreArchivoEntrada, contenido)) {
        return false;
    }
    std::string contenidoDescifrado = descifrar(contenido, clave);
    return ArchivoManager::escribirArchivoTexto(nombreArchivoSalida, contenidoDescifrado);
}