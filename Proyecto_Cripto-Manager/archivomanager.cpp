// #include "archivomanager.h"

// ArchivoManager::ArchivoManager() {}

// ArchivoManager:: ~ArchivoManager(){}

// bool ArchivoManager::leerArchivoTexto(const std::string& ruta, std::string& contenido){
//     std::ifstream archivo(ruta.c_str());
//     if(!archivo.is_open()){
//         return false;
//     }

//     contenido = "";
//     std::string linea;
//     while(std::getline(archivo, linea)){
//         contenido += linea + "\n";
//     }

//     archivo.close();
//     return true;
// }

// bool ArchivoManager::escribirArchivoTexto(const std::string& ruta, const std::string& contenido){
//     std::ofstream archivo(ruta.c_str());
//     if(!archivo.is_open()){
//         return false;
//     }

//     archivo<<contenido;
//     archivo.close();
//     return true;
// }

// bool ArchivoManager::leerArchivoBinario(const std::string& ruta, char*& bufferOut, long& tamanoOut){
//     std::ifstream archivo(ruta.c_str(), std::ios::binary | std::ios::ate);
//     if(!archivo.is_open()){
//         return false;
//     }

//     tamanoOut = archivo.tellg();
//     archivo.seekg(0, std::ios::beg);

//     bufferOut = new char[tamanoOut];
//     archivo.read(bufferOut, tamanoOut);
//     archivo.close();
//     return true;
// }

// bool ArchivoManager::escribirArchivoBinario(const std::string& ruta, const char* buffer, long tamano){
//     std::ofstream archivo(ruta.c_str(), std::ios::binary);
//     if(!archivo.is_open()){
//         return false;
//     }

//     archivo.write(buffer, tamano);
//     archivo.close();
//     return true;
// }

// #include "archivomanager.h"
// #include <vector>

// #if defined(_WIN32) || defined(_WIN64)
// #include <windows.h>
// #else
// #include <dirent.h>
// #endif

// ArchivoManager::ArchivoManager() {}

// ArchivoManager::~ArchivoManager() {}

// bool ArchivoManager::leerArchivoTexto(const std::string& ruta, std::string& contenido){
//     std::ifstream archivo(ruta.c_str());
//     if(!archivo.is_open()){
//         return false;
//     }

//     contenido = "";
//     std::string linea;
//     while(std::getline(archivo, linea)){
//         contenido += linea + "\n";
//     }

//     archivo.close();
//     return true;
// }

// bool ArchivoManager::escribirArchivoTexto(const std::string& ruta, const std::string& contenido){
//     std::ofstream archivo(ruta.c_str());
//     if(!archivo.is_open()){
//         return false;
//     }

//     archivo << contenido;
//     archivo.close();
//     return true;
// }

// bool ArchivoManager::leerArchivoBinario(const std::string& ruta, char*& bufferOut, long& tamanoOut){
//     std::ifstream archivo(ruta.c_str(), std::ios::binary | std::ios::ate);
//     if(!archivo.is_open()){
//         return false;
//     }

//     tamanoOut = archivo.tellg();
//     archivo.seekg(0, std::ios::beg);

//     bufferOut = new char[tamanoOut];
//     archivo.read(bufferOut, tamanoOut);
//     archivo.close();
//     return true;
// }

// bool ArchivoManager::escribirArchivoBinario(const std::string& ruta, const char* buffer, long tamano){
//     std::ofstream archivo(ruta.c_str(), std::ios::binary);
//     if(!archivo.is_open()){
//         return false;
//     }

//     archivo.write(buffer, tamano);
//     archivo.close();
//     return true;
// }

// std::vector<std::string> ArchivoManager::listarArchivosDirectorio() {
//     std::vector<std::string> listaArchivos;

// #if defined(_WIN32) || defined(_WIN64)
//     WIN32_FIND_DATAA findFileData;
//     HANDLE hFind = FindFirstFileA("*.*", &findFileData);
//     if (hFind != INVALID_HANDLE_VALUE) {
//         do {
//             if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
//                 listaArchivos.push_back(findFileData.cFileName);
//             }
//         } while (FindNextFileA(hFind, &findFileData) != 0);
//         FindClose(hFind);
//     }
// #else
//     DIR* dir = opendir(".");
//     if (dir != nullptr) {
//         struct dirent* entry;
//         while ((entry = readdir(dir)) != nullptr) {
//             if (entry->d_type == DT_REG) {
//                 listaArchivos.push_back(entry->d_name);
//             }
//         }
//         closedir(dir);
//     }
// #endif
//     return listaArchivos;
// }

//#archivomanager.cpp
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