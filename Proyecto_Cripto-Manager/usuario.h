// #ifndef USUARIO_H
// #define USUARIO_H

// #include <string>

// class Usuario {
// private:
//     std::string username;
//     std::string password;
//     std::string rol;

// public:
//     Usuario();
//     Usuario(const std::string& user, const std::string& pass, const std::string& r);
//     ~Usuario();

//     std::string getUsername() const;
//     std::string getPassword() const;
//     std::string getRol() const;

//     void setUsername(const std::string& user);
//     void setPassword(const std::string& pass);
//     void setRol(const std::string& r);

//     //la serialización para guardar en archivos de texto
//     std::string serializar() const;
//     static Usuario deserializar(const std::string& lineaTexto);
// };

// #endif

#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    std::string username;
    std::string password;
    std::string rol;

public:
    Usuario();
    Usuario(const std::string& user, const std::string& pass, const std::string& r);
    ~Usuario();

    std::string getUsername() const;
    std::string getPassword() const;
    std::string getRol() const;

    void setUsername(const std::string& user);
    void setPassword(const std::string& pass);
    void setRol(const std::string& r);

    // La serialización para guardar en archivos de texto
    std::string serializar() const;
    static Usuario deserializar(const std::string& lineaTexto);

    // Validación de requisitos de contraseña (Modificación 5)
    static bool validarContrasena(const std::string& pass, std::string& mensajeError);
};

#endif