// #include "Usuario.h"
// #include <sstream>

// Usuario::Usuario() : username(""), password(""), rol("User") {}

// Usuario::Usuario(const std::string& user, const std::string& pass, const std::string& r)
//     : username(user), password(pass), rol(r) {}

// Usuario::~Usuario() {}

// std::string Usuario::getUsername() const { return username; }
// std::string Usuario::getPassword() const { return password; }
// std::string Usuario::getRol() const { return rol; }

// void Usuario::setUsername(const std::string& user) { username = user; }
// void Usuario::setPassword(const std::string& pass) { password = pass; }
// void Usuario::setRol(const std::string& r) { rol = r; }

// std::string Usuario::serializar() const {
//     return username + "," + password + "," + rol;
// }

// Usuario Usuario::deserializar(const std::string& lineaTexto) {
//     std::stringstream ss(lineaTexto);
//     std::string user, pass, r;

//     std::getline(ss, user, ',');
//     std::getline(ss, pass, ',');
//     std::getline(ss, r, ',');

//     return Usuario(user, pass, r);
// }

#include "Usuario.h"
#include <sstream>
#include <cctype>

Usuario::Usuario() : username(""), password(""), rol("User") {}

Usuario::Usuario(const std::string& user, const std::string& pass, const std::string& r)
    : username(user), password(pass), rol(r) {}

Usuario::~Usuario() {}

std::string Usuario::getUsername() const { return username; }
std::string Usuario::getPassword() const { return password; }
std::string Usuario::getRol() const { return rol; }

void Usuario::setUsername(const std::string& user) { username = user; }
void Usuario::setPassword(const std::string& pass) { password = pass; }
void Usuario::setRol(const std::string& r) { rol = r; }

std::string Usuario::serializar() const {
    return username + "," + password + "," + rol;
}

Usuario Usuario::deserializar(const std::string& lineaTexto) {
    std::stringstream ss(lineaTexto);
    std::string user, pass, r;

    std::getline(ss, user, ',');
    std::getline(ss, pass, ',');
    std::getline(ss, r, ',');

    return Usuario(user, pass, r);
}

bool Usuario::validarContrasena(const std::string& pass, std::string& mensajeError) {
    if (pass.length() < 5) {
        mensajeError = "La contraseña debe tener al menos 5 caracteres.";
        return false;
    }
    bool tieneMayus = false;
    bool tieneNum = false;
    bool tieneEspecial = false;

    for (size_t i = 0; i < pass.length(); ++i) {
        char c = pass[i];
        if (std::isupper(c)) {
            tieneMayus = true;
        } else if (std::isdigit(c)) {
            tieneNum = true;
        } else if (!std::isalnum(c)) {
            tieneEspecial = true;
        }
    }

    if (!tieneMayus) {
        mensajeError = "La contraseña debe incluir al menos una letra mayúscula.";
        return false;
    }
    if (!tieneNum) {
        mensajeError = "La contraseña debe incluir al menos un número.";
        return false;
    }
    if (!tieneEspecial) {
        mensajeError = "La contraseña debe incluir al menos un carácter especial.";
        return false;
    }

    return true;
}