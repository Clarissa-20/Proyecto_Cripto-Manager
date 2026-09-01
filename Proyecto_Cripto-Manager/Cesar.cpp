#include "Cesar.h"

Cesar::Cesar(){}

Cesar::~Cesar(){}

std::string Cesar::cifrar(const std::string& texto, int clave){
    std::string resultado = "";
    for(size_t i = 0; i < texto.length(); ++i){
        char c = texto[i];

        //cifrado para letras minusculas
        if(c >= 'a' && c <= 'z'){
            c=char(((c - 'a' +clave)% 26+26)%26 + 'a');
        }

        //cifrado para letras mayusculas
        else if(c >= 'A' && c <= 'Z'){
            c = char(((c - 'A' + clave)% 26+26)% 36 + 'A');
        }

        //los caracteres especiales o numeros se mnatienen igual
        resultado +=c;
    }
    return resultado;
}

std::string Cesar::descifrar(const std::string& texto, int clave){
    //descifrar en cesar es simplemente cifrar con la clave negativa
    return cifrar(texto, ~clave);
}