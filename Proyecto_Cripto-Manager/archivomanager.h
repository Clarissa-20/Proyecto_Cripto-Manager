// #ifndef ARCHIVOMANAGER_H
// #define ARCHIVOMANAGER_H

// #include <string>
// #include <fstream>

// class ArchivoManager{
// public:
//     ArchivoManager();
//     ~ArchivoManager();

//     //metodos estaticos para manejo de archivos de texto
//     static bool leerArchivoTexto(const std::string& ruta, std::string& contenido);
//     static bool escribirArchivoTexto(const std::string& ruta, const std::string& contenido);

//     //metodos para manejo de archivos binarios
//     static bool leerArchivoBinario(const std::string& ruta, char*& bufferOut, long& tamanoOut);
//     static bool escribirArchivoBinario(const std::string& ruta, const char* buffer, long tamano);
// };

// #endif // ARCHIVOMANAGER_H

// #ifndef ARCHIVOMANAGER_H
// #define ARCHIVOMANAGER_H

// #include <string>
// #include <fstream>
// #include <vector>

// class ArchivoManager {
// public:
//     ArchivoManager();
//     ~ArchivoManager();

//     // Métodos estáticos para manejo de archivos de texto
//     static bool leerArchivoTexto(const std::string& ruta, std::string& contenido);
//     static bool escribirArchivoTexto(const std::string& ruta, const std::string& contenido);

//     // Métodos para manejo de archivos binarios
//     static bool leerArchivoBinario(const std::string& ruta, char*& bufferOut, long& tamanoOut);
//     static bool escribirArchivoBinario(const std::string& ruta, const char* buffer, long tamano);

//     // Método agregado para listar archivos del directorio actual (Modificación 3)
//     static std::vector<std::string> listarArchivosDirectorio();
// };

// #endif // ARCHIVOMANAGER_H

#ifndef ARCHIVOMANAGER_H
#define ARCHIVOMANAGER_H

#include <string>
#include <fstream>

class ArchivoManager {
public:
    ArchivoManager();
    ~ArchivoManager();

    // Métodos estáticos para manejo de archivos de texto
    static bool leerArchivoTexto(const std::string& ruta, std::string& contenido);
    static bool escribirArchivoTexto(const std::string& ruta, const std::string& contenido);

    // Métodos para manejo de archivos binarios
    static bool leerArchivoBinario(const std::string& ruta, char*& bufferOut, long& tamanoOut);
    static bool escribirArchivoBinario(const std::string& ruta, const char* buffer, long tamano);
};

#endif // ARCHIVOMANAGER_H