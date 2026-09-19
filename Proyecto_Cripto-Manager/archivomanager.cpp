#include "archivomanager.h"

ArchivoManager::ArchivoManager() {}

ArchivoManager::~ArchivoManager() {}

bool ArchivoManager::leerArchivoTexto(const std::string& ruta, std::string& contenido){
    std::ifstream archivo(ruta.c_str());
    if(!archivo.is_open()){
        return false;
    }

    contenido = "";
    std::string linea;
    while(std::getline(archivo, linea)){
        contenido += linea + "\n";
    }

    archivo.close();
    return true;
}

bool ArchivoManager::escribirArchivoTexto(const std::string& ruta, const std::string& contenido){
    std::ofstream archivo(ruta.c_str());
    if(!archivo.is_open()){
        return false;
    }

    archivo << contenido;
    archivo.close();
    return true;
}

bool ArchivoManager::leerArchivoBinario(const std::string& ruta, char*& bufferOut, long& tamanoOut){
    std::ifstream archivo(ruta.c_str(), std::ios::binary | std::ios::ate);
    if(!archivo.is_open()){
        return false;
    }

    tamanoOut = archivo.tellg();
    archivo.seekg(0, std::ios::beg);

    bufferOut = new char[tamanoOut];
    archivo.read(bufferOut, tamanoOut);
    archivo.close();
    return true;
}

bool ArchivoManager::escribirArchivoBinario(const std::string& ruta, const char* buffer, long tamano){
    std::ofstream archivo(ruta.c_str(), std::ios::binary);
    if(!archivo.is_open()){
        return false;
    }

    archivo.write(buffer, tamano);
    archivo.close();
    return true;
}