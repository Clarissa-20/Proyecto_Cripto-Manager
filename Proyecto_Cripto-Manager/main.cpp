#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "ArchivoManager.h"
#include "Cesar.h"
#include "Xor.h"
#include "Vigenere.h"
#include "Usuario.h"
#include "Historial.h"
#include <windows.h>

bool esSoloLetras(const std::string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isalpha(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}

std::string seleccionarArchivoAmigable(const std::string& accionDesc, bool esCesar) {
    std::cout << "\n--- ARCHIVOS DISPONIBLES (" << accionDesc << ") ---\n";
    if (esCesar) {
        std::cout << "1. cesar_prueba1.txt\n";
        std::cout << "2. cesar_prueba2.txt\n";
        std::cout << "3. Escribir nombre manual\n";
    } else {
        std::cout << "1. xor_prueba1.txt\n";
        std::cout << "2. xor_prueba2.bin\n";
        std::cout << "3. Escribir nombre manual\n";
    }
    std::cout << "Seleccione una opción: ";

    int seleccion;
    if (!(std::cin >> seleccion)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return "";
    }
    std::cin.ignore(10000, '\n');

    if (esCesar) {
        if (seleccion == 1) return "cesar_prueba1.txt";
        if (seleccion == 2) return "cesar_prueba2.txt";
    } else {
        if (seleccion == 1) return "xor_prueba1.txt";
        if (seleccion == 2) return "xor_prueba2.bin";
    }

    if ((esCesar && seleccion == 3) || (!esCesar && seleccion == 3)) {
        std::string manual;
        std::cout << "Ingrese el nombre exacto del archivo: ";
        std::cin >> manual;
        std::cin.ignore(10000, '\n');
        return manual;
    }

    std::cout << "Selección inválida.\n";
    return "";
}

void registrarUsuario() {
    std::string user, pass, rol;
    system("cls||clear");
    std::cout << "=========================================\n";
    std::cout << "         CRIPTO-MANAGER - REGISTRO       \n";
    std::cout << "=========================================\n";

    std::cout << "Ingrese nuevo nombre de usuario (o escriba 'SALIR' para regresar): ";
    std::cin >> user;
    if (user == "SALIR" || user == "salir") return;

    std::ifstream verificar("usuarios.txt");
    std::string u, p, r;
    bool existe = false;
    if (verificar.is_open()) {
        while (verificar >> u >> p >> r) {
            if (u == user) {
                existe = true;
                break;
            }
        }
        verificar.close();
    }

    if (existe) {
        std::cout << "\nEl nombre de usuario ya existe. Intente con otro.\n";
        std::system("pause");
        return;
    }

    while (true) {
        std::cout << "\nRequisitos de contraseña:\n";
        std::cout << " 1. Al menos 5 caracteres\n";
        std::cout << " 2. Al menos una letra mayúscula\n";
        std::cout << " 3. Al menos un número\n";
        std::cout << " 4. Al menos un carácter especial\n";
        std::cout << "Ingrese contraseña (o 'SALIR' para cancelar): ";
        std::cin >> pass;
        if (pass == "SALIR" || pass == "salir") return;

        std::string errorPass = "";
        if (!Usuario::validarContrasena(pass, errorPass)) {
            std::cout << "\n[Error] " << errorPass << " Intente de nuevo.\n";
            continue;
        }
        break;
    }

    std::cout << "Ingrese rol (ej. Operador / Administrador): ";
    std::cin >> rol;

    std::ofstream archivo("usuarios.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << user << " " << pass << " " << rol << "\n";
        archivo.close();
        std::cout << "\n¡Cuenta creada exitosamente!\n";
    } else {
        std::cout << "\nError: No se pudo abrir o crear el archivo 'usuarios.txt'.\n";
    }
    std::system("pause");
}

bool realizarLogin(std::string& usuarioActualOut, std::string& rolOut) {
    int opcionAcceso = 0;
    do {
        system("cls||clear");
        std::cout << "=========================================\n";
        std::cout << "         CRIPTO-MANAGER - ACCESO         \n";
        std::cout << "=========================================\n";
        std::cout << "1. Iniciar Sesión\n";
        std::cout << "2. Crear una cuenta nueva\n";
        std::cout << "3. Salir del programa\n";
        std::cout << "Seleccione una opción: ";

        if (!(std::cin >> opcionAcceso)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (opcionAcceso == 2) {
            registrarUsuario();
            continue;
        } else if (opcionAcceso == 3) {
            return false;
        } else if (opcionAcceso == 1) {
            break;
        }
    } while (true);

    std::string user, pass;
    while (true) {
        system("cls||clear");
        std::cout << "=========================================\n";
        std::cout << "         CRIPTO-MANAGER - LOGIN          \n";
        std::cout << "=========================================\n";
        std::cout << "Usuario (o escriba 'SALIR' para regresar): ";
        std::cin >> user;
        if (user == "SALIR" || user == "salir") {
            return realizarLogin(usuarioActualOut, rolOut);
        }

        std::cout << "Contraseña: ";
        std::cin >> pass;

        std::ifstream archivo("usuarios.txt");
        if (!archivo.is_open()) {
            std::cout << "\nError: No se pudo abrir el archivo 'usuarios.txt'. Cree una cuenta primero.\n";
            std::system("pause");
            return false;
        }

        std::string u, p, r;
        bool encontrado = false;

        while (archivo >> u >> p >> r) {
            if (u == user && p == pass) {
                usuarioActualOut = u;
                rolOut = r;
                encontrado = true;
                break;
            }
        }
        archivo.close();

        if (encontrado) {
            std::cout << "\n¡Acceso concedido! Bienvenido, " << usuarioActualOut << " (" << rolOut << ").\n";
            std::cout << "\nPresione Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
            return true;
        } else {
            std::cout << "\nUsuario o contraseña incorrectos. Intente de nuevo.\n";
            std::system("pause");
        }
    }
}

void mostrarMenuPrincipal() {
    std::cout << "\n=========================================\n";
    std::cout << "            CRIPTO-MANAGER SYSTEM        \n";
    std::cout << "=========================================\n";
    std::cout << "1. Nivel 1: Cifrado/Descifrado Cesar\n";
    std::cout << "2. Nivel 2: Cifrado/Descifrado XOR\n";
    std::cout << "3. Nivel 3: Cifrado/Descifrado Vigenere\n";
    std::cout << "4. Nivel 4: Gestion de Historial, Estadisticas y Reportes\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    SetConsoleOutputCP(65001);

    while (true) {
        std::string usuarioActual = "";
        std::string rolUsuario = "";

        if (!realizarLogin(usuarioActual, rolUsuario)) {
            std::cout << "\nSaliendo del sistema...\n";
            break;
        }

        Historial historialGlobal;
        int opcion = 0;

        do {
            system("cls||clear");
            std::cout << "Sesion activa: " << usuarioActual << " | Rol: " << rolUsuario << "\n";
            mostrarMenuPrincipal();
            if (!(std::cin >> opcion)) {
                std::cout << "Entrada invalida. Intente de nuevo.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::system("pause");
                continue;
            }

            switch (opcion) {
            case 1: { // NIVEL 1: CESAR
                int opcionSub = 0;
                do {
                    system("cls||clear");
                    std::cout << "--- NIVEL 1: CIFRADO CESAR ---\n";
                    std::cout << "1. Cifrar texto plano\n";
                    std::cout << "2. Descifrar texto plano\n";
                    std::cout << "3. Cifrar archivo (.txt)\n";
                    std::cout << "4. Descifrar archivo (.txt)\n";
                    std::cout << "5. Volver al Menu Principal\n";
                    std::cout << "Seleccione una opcion: ";
                    std::cin >> opcionSub;

                    if (std::cin.fail() || opcionSub < 1 || opcionSub > 5) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "Opcion incorrecta. Intente de nuevo.\n";
                        std::system("pause");
                        continue;
                    }

                    if (opcionSub == 5) break;

                    if (opcionSub == 1 || opcionSub == 2) {
                        std::cin.ignore();
                        std::string texto;
                        std::cout << "Ingrese el texto: ";
                        std::getline(std::cin, texto);

                        int desplazamiento = 0;
                        while (true) {
                            std::cout << "Ingrese la clave (desplazamiento numerico entero): ";
                            std::cin >> desplazamiento;
                            if (std::cin.fail()) {
                                std::cin.clear();
                                std::cin.ignore(10000, '\n');
                                std::cout << "Error: Debe ingresar un numero entero valido.\n";
                            } else {
                                break;
                            }
                        }

                        Cesar cesarObj;
                        std::string resultado = "";
                        if (opcionSub == 1) {
                            resultado = cesarObj.cifrar(texto, desplazamiento);
                            std::cout << "\nResultado Cifrado: " << resultado << "\n";
                            historialGlobal.agregarOperacion(usuarioActual, "Cifrado Cesar de texto");
                        } else {
                            resultado = cesarObj.descifrar(texto, desplazamiento);
                            std::cout << "\nResultado Descifrado: " << resultado << "\n";
                            historialGlobal.agregarOperacion(usuarioActual, "Descifrado Cesar de texto");
                        }
                        std::cout << "\nPresione Enter para continuar...";
                        std::cin.ignore();
                        std::cin.get();
                    }
                    else if (opcionSub == 3 || opcionSub == 4) {
                        std::cin.ignore();
                        std::string archivoEntrada = seleccionarArchivoAmigable(opcionSub == 3 ? "Cifrar César" : "Descifrar César", true);
                        if (archivoEntrada.empty()) {
                            std::system("pause");
                            continue;
                        }

                        std::string archivoSalida;
                        std::cout << "Ingrese el nombre del archivo de salida: ";
                        std::cin >> archivoSalida;

                        int desplazamiento = 0;
                        std::cout << "Ingrese el desplazamiento (número entero): ";
                        std::cin >> desplazamiento;

                        Cesar cesarObj;
                        std::string contenidoFile;
                        bool exito = false;
                        std::string tipoAccion = "";

                        if (ArchivoManager::leerArchivoTexto(archivoEntrada, contenidoFile)) {
                            std::string resProc = (opcionSub == 3)
                            ? cesarObj.cifrar(contenidoFile, desplazamiento)
                            : cesarObj.descifrar(contenidoFile, desplazamiento);
                            exito = ArchivoManager::escribirArchivoTexto(archivoSalida, resProc);
                            tipoAccion = (opcionSub == 3) ? "Cifrado César de archivo" : "Descifrado César de archivo";
                        }

                        if (exito) {
                            std::cout << "\n¡Archivo procesado exitosamente con César!\n";
                            historialGlobal.agregarOperacion(usuarioActual, tipoAccion + " (" + archivoEntrada + ")");
                        } else {
                            std::cout << "\n[Error] No se pudo leer/escribir el archivo de texto.\n";
                        }
                        std::system("pause");
                    }
                } while (true);
                break;
            }
            case 2: { // NIVEL 2: XOR
                int opcionSub = 0;
                do {
                    system("cls||clear");
                    std::cout << "--- NIVEL 2: CIFRADO XOR ---\n";
                    std::cout << "1. Cifrar texto plano\n";
                    std::cout << "2. Descifrar texto plano\n";
                    std::cout << "3. Cifrar archivo (binario)\n";
                    std::cout << "4. Descifrar archivo (binario)\n";
                    std::cout << "5. Volver al Menu Principal\n";
                    std::cout << "Seleccione una opcion: ";
                    std::cin >> opcionSub;

                    if (std::cin.fail() || opcionSub < 1 || opcionSub > 5) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "Opcion incorrecta. Intente de nuevo.\n";
                        std::system("pause");
                        continue;
                    }

                    if (opcionSub == 5) break;

                    if (opcionSub == 1 || opcionSub == 2) {
                        std::cin.ignore();
                        std::string texto;
                        std::cout << "Ingrese el texto o mensaje: ";
                        std::getline(std::cin, texto);

                        std::string claveSecreta;
                        std::cout << "Ingrese la clave secreta (texto): ";
                        std::getline(std::cin, claveSecreta);

                        std::string resultado = texto;
                        Xor xorObj;
                        xorObj.cifrarBinario(const_cast<char*>(resultado.data()), static_cast<long>(resultado.size()), claveSecreta);

                        std::string tipoAccion = (opcionSub == 1) ? "Cifrado XOR de texto" : "Descifrado XOR de texto";
                        std::cout << "\nResultado (" << tipoAccion << "):\n" << resultado << "\n";
                        historialGlobal.agregarOperacion(usuarioActual, tipoAccion);

                        std::cout << "\nPresione Enter para continuar...";
                        std::system("pause");
                    }
                    else if (opcionSub == 3 || opcionSub == 4) {
                        std::cin.ignore();
                        std::string rutaArchivo = seleccionarArchivoAmigable(opcionSub == 3 ? "Cifrar XOR" : "Descifrar XOR", false);
                        if (rutaArchivo.empty()) {
                            std::system("pause");
                            continue;
                        }

                        std::string claveSecreta;
                        std::cout << "Ingrese la clave secreta en texto: ";
                        std::getline(std::cin, claveSecreta);

                        char* buffer = nullptr;
                        long tamano = 0;

                        if (ArchivoManager::leerArchivoBinario(rutaArchivo, buffer, tamano)) {
                            Xor xorObj;
                            xorObj.cifrarBinario(buffer, tamano, claveSecreta);
                            if (ArchivoManager::escribirArchivoBinario(rutaArchivo, buffer, tamano)) {
                                std::string tipoAccion = (opcionSub == 3) ? "Cifrado" : "Descifrado";
                                std::cout << "\n¡Archivo '" << rutaArchivo << "' " << tipoAccion << " exitosamente con XOR!\n";
                                historialGlobal.agregarOperacion(usuarioActual, tipoAccion + " XOR de archivo binario (" + rutaArchivo + ")");
                            } else {
                                std::cout << "Error al escribir el archivo procesado.\n";
                            }
                            delete[] buffer;
                        } else {
                            std::cout << "No se pudo leer el archivo especificado (" << rutaArchivo << "). Verifique que exista.\n";
                        }

                        std::cout << "\nPresione Enter para continuar...";
                        std::cin.get();
                    }
                } while (true);
                break;
            }
            case 3: { // NIVEL 3: VIGENERE
                int opcionSub = 0;
                do {
                    system("cls||clear");
                    std::cout << "--- NIVEL 3: CIFRADO VIGENERE ---\n";
                    std::cout << "1. Cifrar con clave de texto\n";
                    std::cout << "2. Descifrar con clave de texto\n";
                    std::cout << "3. Volver al Menu Principal\n";
                    std::cout << "Seleccione una opcion: ";
                    std::cin >> opcionSub;

                    if (std::cin.fail() || opcionSub < 1 || opcionSub > 3) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "Opcion incorrecta. Intente de nuevo.\n";
                        std::system("pause");
                        continue;
                    }

                    if (opcionSub == 3) break;

                    std::cin.ignore();
                    std::string texto;
                    std::cout << "Ingrese el texto o mensaje: ";
                    std::getline(std::cin, texto);

                    std::string clave;
                    while (true) {
                        std::cout << "Ingrese la clave de texto (solo letras, sin numeros): ";
                        std::getline(std::cin, clave);
                        if (!esSoloLetras(clave)) {
                            std::cout << "Error: La clave de Vigenere debe contener unicamente letras alfabeticas.\n";
                        } else {
                            break;
                        }
                    }

                    Vigenere vigenereObj;
                    std::string resultado = "";
                    if (opcionSub == 1) {
                        resultado = vigenereObj.cifrarConClaveTexto(texto, clave);
                        std::cout << "\nResultado Cifrado: " << resultado << "\n";
                        historialGlobal.agregarOperacion(usuarioActual, "Cifrado Vigenere de texto");
                    } else {
                        resultado = vigenereObj.descifrarConClaveTexto(texto, clave);
                        std::cout << "\nResultado Descifrado: " << resultado << "\n";
                        historialGlobal.agregarOperacion(usuarioActual, "Descifrado Vigenere de texto");
                    }

                    std::cout << "\nPresione Enter para continuar...";
                    std::cin.get();
                } while (true);
                break;
            }
            case 4: { // NIVEL 4: HISTORIAL Y REPORTES
                system("cls||clear");
                std::cout << "--- NIVEL 4: GESTION, HISTORIAL Y REPORTES ---\n";
                std::cout << "Usuario actual: " << usuarioActual << " | Rol: " << rolUsuario << "\n\n";

                historialGlobal.mostrarHistorial();

                std::cout << "\n--- ESTADISTICAS DE USO DEL SISTEMA ---\n";
                std::cout << "Total de operaciones realizadas: " << historialGlobal.obtenerTotalOperaciones() << "\n";

                historialGlobal.ordenarPorUsuario();

                std::cout << "\nPresione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                break;
            }
            case 5:
                std::cout << "\nCerrando sesión actual...\n";
                std::system("pause");
                break;
            default:
                std::cout << "\nOpcion no valida. Intente de nuevo.\n";
                std::system("pause");
                break;
            }
        } while (opcion != 5);

    }

    return 0;
}