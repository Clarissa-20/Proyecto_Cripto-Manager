//MAIN CRIPTO

// #include <iostream>
// #include <string>
// #include <cctype>
// #include <fstream>
// #include "ArchivoManager.h"
// #include "Cesar.h"
// #include "Xor.h"
// #include "Vigenere.h"
// #include "Usuario.h"
// #include "Historial.h"
// #include <windows.h>

// bool esSoloLetras(const std::string& str) {
//     if (str.empty()) return false;
//     for (char c : str) {
//         if (!isalpha(static_cast<unsigned char>(c))) {
//             return false;
//         }
//     }
//     return true;
// }

// void registrarUsuario() {
//     std::string user, pass, rol;
//     system("cls||clear");
//     std::cout << "=========================================\n";
//     std::cout << "         CRIPTO-MANAGER - REGISTRO       \n";
//     std::cout << "=========================================\n";

//     std::cout << "Ingrese nuevo nombre de usuario: ";
//     std::cin >> user;

//     std::ifstream verificar("usuarios.txt");
//     std::string u, p, r;
//     bool existe = false;
//     if (verificar.is_open()) {
//         while (verificar >> u >> p >> r) {
//             if (u == user) {
//                 existe = true;
//                 break;
//             }
//         }
//         verificar.close();
//     }

//     if (existe) {
//         std::cout << "\nEl nombre de usuario ya existe. Intente con otro.\n";
//         std::system("pause");
//         return;
//     }

//     std::cout << "Ingrese contraseña: ";
//     std::cin >> pass;
//     std::cout << "Ingrese rol (ej. Operador / Administrador): ";
//     std::cin >> rol;

//     std::ofstream archivo("usuarios.txt", std::ios::app);
//     if (archivo.is_open()) {
//         archivo << user << " " << pass << " " << rol << "\n";
//         archivo.close();
//         std::cout << "\n¡Cuenta creada exitosamente!\n";
//     } else {
//         std::cout << "\nError: No se pudo abrir o crear el archivo 'usuarios.txt'.\n";
//     }
//     std::system("pause");
// }

// bool realizarLogin(std::string& usuarioActualOut, std::string& rolOut) {
//     int opcionAcceso = 0;
//     do {
//         system("cls||clear");
//         std::cout << "=========================================\n";
//         std::cout << "         CRIPTO-MANAGER - ACCESO         \n";
//         std::cout << "=========================================\n";
//         std::cout << "1. Iniciar Sesión\n";
//         std::cout << "2. Crear una cuenta nueva\n";
//         std::cout << "3. Salir del programa\n";
//         std::cout << "Seleccione una opción: ";

//         if (!(std::cin >> opcionAcceso)) {
//             std::cin.clear();
//             std::cin.ignore(10000, '\n');
//             continue;
//         }

//         if (opcionAcceso == 2) {
//             registrarUsuario();
//             continue;
//         } else if (opcionAcceso == 3) {
//             return false;
//         } else if (opcionAcceso == 1) {
//             break;
//         }
//     } while (true);

//     std::string user, pass;
//     while (true) {
//         system("cls||clear");
//         std::cout << "=========================================\n";
//         std::cout << "        CRIPTO-MANAGER - LOGIN           \n";
//         std::cout << "=========================================\n";
//         std::cout << "Usuario: ";
//         std::cin >> user;
//         std::cout << "Contraseña: ";
//         std::cin >> pass;

//         std::ifstream archivo("usuarios.txt");
//         if (!archivo.is_open()) {
//             std::cout << "\nError: No se pudo abrir el archivo 'usuarios.txt'. Asegúrese de que el archivo exista o cree una cuenta primero.\n";
//             std::system("pause");
//             return false;
//         }

//         std::string u, p, r;
//         bool encontrado = false;

//         while (archivo >> u >> p >> r) {
//             if (u == user && p == pass) {
//                 usuarioActualOut = u;
//                 rolOut = r;
//                 encontrado = true;
//                 break;
//             }
//         }
//         archivo.close();

//         if (encontrado) {
//             std::cout << "\n¡Acceso concedido! Bienvenido, " << usuarioActualOut << " (" << rolOut << ").\n";
//             std::cout << "\nPresione Enter para continuar...";
//             std::cin.ignore();
//             std::cin.get();
//             return true;
//         } else {
//             std::cout << "\nUsuario o contraseña incorrectos. Intente de nuevo.\n";
//             std::system("pause");
//         }
//     }
// }

// void mostrarMenuPrincipal() {
//     std::cout << "\n=========================================\n";
//     std::cout << "            CRIPTO-MANAGER SYSTEM         \n";
//     std::cout << "=========================================\n";
//     std::cout << "1. Nivel 1: Cifrado/Descifrado Cesar (.txt)\n";
//     std::cout << "2. Nivel 2: Cifrado/Descifrado XOR (Binario)\n";
//     std::cout << "3. Nivel 3: Cifrado/Descifrado Vigenere\n";
//     std::cout << "4. Nivel 4: Gestion de Historial, Estadisticas y Reportes\n";
//     std::cout << "5. Salir\n";
//     std::cout << "Seleccione una opcion: ";
// }

// int main() {
//     SetConsoleOutputCP(65001);

//     std::string usuarioActual = "";
//     std::string rolUsuario = "";

//     if (!realizarLogin(usuarioActual, rolUsuario)) {
//         std::cout << "\nSaliendo del sistema...\n";
//         return 0;
//     }

//     Historial historialGlobal;
//     int opcion = 0;

//     do {
//         system("cls||clear");
//         std::cout << "Sesion activa: " << usuarioActual << " | Rol: " << rolUsuario << "\n";
//         mostrarMenuPrincipal();
//         if (!(std::cin >> opcion)) {
//             std::cout << "Entrada invalida. Intente de nuevo.\n";
//             std::cin.clear();
//             std::cin.ignore(10000, '\n');
//             std::system("pause");
//             continue;
//         }

//         switch (opcion) {
//         case 1: {
//             system("cls||clear");
//             std::cout << "--- NIVEL 1: CIFRADO CESAR ---\n";
//             int opcionSub;

//             do {
//                 std::cout << "1. Cifrar texto\n";
//                 std::cout << "2. Descifrar texto\n";
//                 std::cout << "Seleccione una opcion valida (1 o 2): ";
//                 std::cin >> opcionSub;

//                 if (std::cin.fail() || (opcionSub != 1 && opcionSub != 2)) {
//                     std::cin.clear();
//                     std::cin.ignore(10000, '\n');
//                     std::cout << "Opcion incorrecta. Intente de nuevo.\n\n";
//                 } else {
//                     break;
//                 }
//             } while (true);

//             std::cin.ignore();

//             std::string texto;
//             std::cout << "Ingrese el texto: ";
//             std::getline(std::cin, texto);

//             int desplazamiento = 0;
//             while (true) {
//                 std::cout << "Ingrese la clave (desplazamiento numerico entero): ";
//                 std::cin >> desplazamiento;
//                 if (std::cin.fail()) {
//                     std::cin.clear();
//                     std::cin.ignore(10000, '\n');
//                     std::cout << "Error: Debe ingresar un numero entero valido (no se permiten letras).\n";
//                 } else {
//                     std::cin.ignore();
//                     break;
//                 }
//             }

//             Cesar cesarObj;
//             std::string resultado = "";
//             if (opcionSub == 1) {
//                 resultado = cesarObj.cifrar(texto, desplazamiento);
//                 std::cout << "\nResultado Cifrado: " << resultado << "\n";
//                 historialGlobal.agregarOperacion(usuarioActual, "Cifrado Cesar de texto");
//             } else {
//                 resultado = cesarObj.descifrar(texto, desplazamiento);
//                 std::cout << "\nResultado Descifrado: " << resultado << "\n";
//                 historialGlobal.agregarOperacion(usuarioActual, "Descifrado Cesar de texto");
//             }

//             std::cout << "\nPresione Enter para continuar...";
//             std::cin.get();
//             break;
//         }
//         case 2: {
//             system("cls||clear");
//             std::cout << "--- NIVEL 2: CIFRADO XOR (BLOQUES BINARIOS) ---\n";

//             int subOpcionArchivo = 0;
//             do {
//                 std::cout << "Seleccione el archivo a procesar:\n";
//                 std::cout << "1. datos.dat (Archivo principal por defecto)\n";
//                 std::cout << "2. prueba.txt (Archivo de texto plano)\n";
//                 std::cout << "3. Escribir nombre del archivo personalizado\n";
//                 std::cout << "Seleccion (1-3): ";
//                 std::cin >> subOpcionArchivo;

//                 if (std::cin.fail() || subOpcionArchivo < 1 || subOpcionArchivo > 3) {
//                     std::cin.clear();
//                     std::cin.ignore(10000, '\n');
//                     std::cout << "Opcion no valida. Por favor seleccione 1, 2 o 3.\n\n";
//                 } else {
//                     break;
//                 }
//             } while (true);

//             std::cin.ignore();

//             std::string rutaArchivo;
//             if (subOpcionArchivo == 1) {
//                 rutaArchivo = "datos.dat";
//             } else if (subOpcionArchivo == 2) {
//                 rutaArchivo = "prueba.txt";
//             } else {
//                 std::cout << "Ingrese el nombre exacto del archivo: ";
//                 std::getline(std::cin, rutaArchivo);
//             }

//             int accionXor = 0;
//             do {
//                 std::cout << "\n¿Que desea hacer con el archivo?\n";
//                 std::cout << "1. Cifrar archivo\n";
//                 std::cout << "2. Descifrar archivo\n";
//                 std::cout << "Seleccion (1 o 2): ";
//                 std::cin >> accionXor;

//                 if (std::cin.fail() || (accionXor != 1 && accionXor != 2)) {
//                     std::cin.clear();
//                     std::cin.ignore(10000, '\n');
//                     std::cout << "Opcion invalida. Intente de nuevo.\n";
//                 } else {
//                     break;
//                 }
//             } while (true);
//             std::cin.ignore();

//             std::string claveSecreta;
//             std::cout << "Ingrese la clave secreta en texto: ";
//             std::getline(std::cin, claveSecreta);

//             char* buffer = nullptr;
//             long tamano = 0;

//             if (ArchivoManager::leerArchivoBinario(rutaArchivo, buffer, tamano)) {
//                 Xor xorObj;
//                 xorObj.cifrarBinario(buffer, tamano, claveSecreta);
//                 if (ArchivoManager::escribirArchivoBinario(rutaArchivo, buffer, tamano)) {
//                     std::string tipoAccion = (accionXor == 1) ? "Cifrado" : "Descifrado";
//                     std::cout << "\n¡Archivo '" << rutaArchivo << "' " << tipoAccion << " exitosamente con XOR!\n";
//                     historialGlobal.agregarOperacion(usuarioActual, tipoAccion + " XOR de archivo binario (" + rutaArchivo + ")");
//                 } else {
//                     std::cout << "Error al escribir el archivo procesado.\n";
//                 }
//                 delete[] buffer;
//             } else {
//                 std::cout << "No se pudo leer el archivo especificado (" << rutaArchivo << "). Verifique que exista.\n";
//             }

//             std::cout << "\nPresione Enter para continuar...";
//             std::cin.get();
//             break;
//         }
//         case 3: {
//             system("cls||clear");
//             std::cout << "--- NIVEL 3: CIFRADO VIGENERE ---\n";
//             int opcionSub = 0;

//             do {
//                 std::cout << "1. Cifrar con clave de texto\n";
//                 std::cout << "2. Descifrar con clave de texto\n";
//                 std::cout << "Seleccione una opcion valida (1 o 2): ";
//                 std::cin >> opcionSub;

//                 if (std::cin.fail() || (opcionSub != 1 && opcionSub != 2)) {
//                     std::cin.clear();
//                     std::cin.ignore(10000, '\n');
//                     std::cout << "Opcion incorrecta. Intente de nuevo.\n\n";
//                 } else {
//                     break;
//                 }
//             } while (true);

//             std::cin.ignore();

//             std::string texto;
//             std::cout << "Ingrese el texto o mensaje: ";
//             std::getline(std::cin, texto);

//             std::string clave;
//             while (true) {
//                 std::cout << "Ingrese la clave de texto (solo letras, sin numeros): ";
//                 std::getline(std::cin, clave);
//                 if (!esSoloLetras(clave)) {
//                     std::cout << "Error: La clave de Vigenere debe contener unicamente letras alfabeticas.\n";
//                 } else {
//                     break;
//                 }
//             }

//             Vigenere vigenereObj;
//             std::string resultado = "";
//             if (opcionSub == 1) {
//                 resultado = vigenereObj.cifrarConClaveTexto(texto, clave);
//                 std::cout << "\nResultado Cifrado: " << resultado << "\n";
//                 historialGlobal.agregarOperacion(usuarioActual, "Cifrado Vigenere de texto");
//             } else {
//                 resultado = vigenereObj.descifrarConClaveTexto(texto, clave);
//                 std::cout << "\nResultado Descifrado: " << resultado << "\n";
//                 historialGlobal.agregarOperacion(usuarioActual, "Descifrado Vigenere de texto");
//             }

//             std::cout << "\nPresione Enter para continuar...";
//             std::cin.get();
//             break;
//         }
//         case 4: {
//             system("cls||clear");
//             std::cout << "--- NIVEL 4: GESTION, HISTORIAL Y REPORTES ---\n";
//             std::cout << "Usuario actual: " << usuarioActual << " | Rol: " << rolUsuario << "\n\n";

//             historialGlobal.mostrarHistorial();

//             std::cout << "\n--- ESTADISTICAS DE USO DEL SISTEMA ---\n";
//             std::cout << "Total de operaciones realizadas: " << historialGlobal.obtenerTotalOperaciones() << "\n";

//             std::cout << "\nAplicando metodo de ordenamiento (Burbuja por usuario)...\n";
//             historialGlobal.ordenarPorUsuario();
//             std::cout << "Historial ordenado correctamente.\n";

//             std::cout << "\nPresione Enter para continuar...";
//             std::cin.ignore();
//             std::cin.get();
//             break;
//         }
//         case 5:
//             std::cout << "\nSaliendo del sistema Cripto-Manager...\n";
//             break;
//         default:
//             std::cout << "\nOpcion no valida. Intente de nuevo.\n";
//             std::system("pause");
//             break;
//         }
//     } while (opcion != 5);

//     return 0;
// }



// #include <iostream>
// #include <string>
// #include <cctype>
// #include <fstream>
// #include <vector>
// #include "ArchivoManager.h"
// #include "Cesar.h"
// #include "Xor.h"
// #include "Vigenere.h"
// #include "Usuario.h"
// #include "Historial.h"
// #include <windows.h>

// bool esSoloLetras(const std::string& str) {
//     if (str.empty()) return false;
//     for (char c : str) {
//         if (!isalpha(static_cast<unsigned char>(c))) {
//             return false;
//         }
//     }
//     return true;
// }

// // Selección amigable de archivos enumerados (Modificación 3)
// std::string seleccionarArchivoAmigable(const std::string& accionDesc) {
//     std::vector<std::string> archivos = ArchivoManager::listarArchivosDirectorio();
//     if (archivos.empty()) {
//         std::cout << "\nNo se encontraron archivos en el directorio actual. Ingrese el nombre manualmente.\n";
//         std::string manual;
//         std::cout << "Nombre del archivo: ";
//         std::cin >> manual;
//         return manual;
//     }

//     std::cout << "\n--- ARCHIVOS DISPONIBLES (" << accionDesc << ") ---\n";
//     for (size_t i = 0; i < archivos.size(); ++i) {
//         std::cout << i + 1 << ". " << archivos[i] << "\n";
//     }
//     std::cout << "0. Escribir nombre manual\n";
//     std::cout << "Seleccione el número de archivo: ";

//     int seleccion;
//     if (!(std::cin >> seleccion)) {
//         std::cin.clear();
//         std::cin.ignore(10000, '\n');
//         return "";
//     }

//     if (seleccion > 0 && static_cast<size_t>(seleccion) <= archivos.size()) {
//         return archivos[seleccion - 1];
//     } else if (seleccion == 0) {
//         std::string manual;
//         std::cout << "Ingrese el nombre exacto del archivo: ";
//         std::cin >> manual;
//         return manual;
//     }

//     std::cout << "Selección inválida.\n";
//     return "";
// }

// void registrarUsuario() {
//     std::string user, pass, rol;
//     system("cls||clear");
//     std::cout << "=========================================\n";
//     std::cout << "         CRIPTO-MANAGER - REGISTRO       \n";
//     std::cout << "=========================================\n";

//     std::cout << "Ingrese nuevo nombre de usuario (o escriba 'SALIR' para regresar): ";
//     std::cin >> user;
//     if (user == "SALIR" || user == "salir") return;

//     std::ifstream verificar("usuarios.txt");
//     std::string u, p, r;
//     bool existe = false;
//     if (verificar.is_open()) {
//         while (verificar >> u >> p >> r) {
//             if (u == user) {
//                 existe = true;
//                 break;
//             }
//         }
//         verificar.close();
//     }

//     if (existe) {
//         std::cout << "\nEl nombre de usuario ya existe. Intente con otro.\n";
//         std::system("pause");
//         return;
//     }

//     // Validación de requisitos de contraseña (Modificación 5)
//     while (true) {
//         std::cout << "\nRequisitos de contraseña:\n";
//         std::cout << " 1. Al menos 5 caracteres\n";
//         std::cout << " 2. Al menos una letra mayúscula\n";
//         std::cout << " 3. Al menos un número\n";
//         std::cout << " 4. Al menos un carácter especial\n";
//         std::cout << "Ingrese contraseña (o 'SALIR' para cancelar): ";
//         std::cin >> pass;
//         if (pass == "SALIR" || pass == "salir") return;

//         std::string errorPass = "";
//         if (!Usuario::validarContrasena(pass, errorPass)) {
//             std::cout << "\n[Error] " << errorPass << " Intente de nuevo.\n";
//             continue;
//         }
//         break;
//     }

//     std::cout << "Ingrese rol (ej. Operador / Administrador): ";
//     std::cin >> rol;

//     std::ofstream archivo("usuarios.txt", std::ios::app);
//     if (archivo.is_open()) {
//         archivo << user << " " << pass << " " << rol << "\n";
//         archivo.close();
//         std::cout << "\n¡Cuenta creada exitosamente!\n";
//     } else {
//         std::cout << "\nError: No se pudo abrir o crear el archivo 'usuarios.txt'.\n";
//     }
//     std::system("pause");
// }

// bool realizarLogin(std::string& usuarioActualOut, std::string& rolOut) {
//     int opcionAcceso = 0;
//     do {
//         system("cls||clear");
//         std::cout << "=========================================\n";
//         std::cout << "         CRIPTO-MANAGER - ACCESO         \n";
//         std::cout << "=========================================\n";
//         std::cout << "1. Iniciar Sesión\n";
//         std::cout << "2. Crear una cuenta nueva\n";
//         std::cout << "3. Salir del programa\n"; // Opción de salida en el menú de acceso (Modificación 4)
//         std::cout << "Seleccione una opción: ";

//         if (!(std::cin >> opcionAcceso)) {
//             std::cin.clear();
//             std::cin.ignore(10000, '\n');
//             continue;
//         }

//         if (opcionAcceso == 2) {
//             registrarUsuario();
//             continue;
//         } else if (opcionAcceso == 3) {
//             return false;
//         } else if (opcionAcceso == 1) {
//             break;
//         }
//     } while (true);

//     std::string user, pass;
//     while (true) {
//         system("cls||clear");
//         std::cout << "=========================================\n";
//         std::cout << "        CRIPTO-MANAGER - LOGIN           \n";
//         std::cout << "=========================================\n";
//         std::cout << "Usuario (o escriba 'SALIR' para regresar): ";
//         std::cin >> user;
//         if (user == "SALIR" || user == "salir") {
//             return realizarLogin(usuarioActualOut, rolOut); // Regresar al menú de acceso principal
//         }

//         std::cout << "Contraseña: ";
//         std::cin >> pass;

//         std::ifstream archivo("usuarios.txt");
//         if (!archivo.is_open()) {
//             std::cout << "\nError: No se pudo abrir el archivo 'usuarios.txt'. Cree una cuenta primero.\n";
//             std::system("pause");
//             return false;
//         }

//         std::string u, p, r;
//         bool encontrado = false;

//         while (archivo >> u >> p >> r) {
//             if (u == user && p == pass) {
//                 usuarioActualOut = u;
//                 rolOut = r;
//                 encontrado = true;
//                 break;
//             }
//         }
//         archivo.close();

//         if (encontrado) {
//             std::cout << "\n¡Acceso concedido! Bienvenido, " << usuarioActualOut << " (" << rolOut << ").\n";
//             std::cout << "\nPresione Enter para continuar...";
//             std::cin.ignore();
//             std::cin.get();
//             return true;
//         } else {
//             std::cout << "\nUsuario o contraseña incorrectos. Intente de nuevo.\n";
//             std::system("pause");
//         }
//     }
// }

// void mostrarMenuPrincipal() {
//     std::cout << "\n=========================================\n";
//     std::cout << "            CRIPTO-MANAGER SYSTEM        \n";
//     std::cout << "=========================================\n";
//     std::cout << "1. Nivel 1: Cifrado/Descifrado Cesar (.txt)\n";
//     std::cout << "2. Nivel 2: Cifrado/Descifrado XOR (Binario)\n";
//     std::cout << "3. Nivel 3: Cifrado/Descifrado Vigenere\n";
//     std::cout << "4. Nivel 4: Gestion de Historial, Estadisticas y Reportes\n";
//     std::cout << "5. Salir\n";
//     std::cout << "Seleccione una opcion: ";
// }

// int main() {
//     SetConsoleOutputCP(65001);

//     std::string usuarioActual = "";
//     std::string rolUsuario = "";

//     if (!realizarLogin(usuarioActual, rolUsuario)) {
//         std::cout << "\nSaliendo del sistema...\n";
//         return 0;
//     }

//     Historial historialGlobal;
//     int opcion = 0;

//     do {
//         system("cls||clear");
//         std::cout << "Sesion activa: " << usuarioActual << " | Rol: " << rolUsuario << "\n";
//         mostrarMenuPrincipal();
//         if (!(std::cin >> opcion)) {
//             std::cout << "Entrada invalida. Intente de nuevo.\n";
//             std::cin.clear();
//             std::cin.ignore(10000, '\n');
//             std::system("pause");
//             continue;
//         }

//         switch (opcion) {
//         case 1: { // NIVEL 1: CESAR
//             int opcionSub = 0;
//             do {
//                 system("cls||clear");
//                 std::cout << "--- NIVEL 1: CIFRADO CESAR ---\n";
//                 std::cout << "1. Cifrar texto plano\n";
//                 std::cout << "2. Descifrar texto plano\n";
//                 std::cout << "3. Cifrar archivo (César)\n";
//                 std::cout << "4. Descifrar archivo (César)\n";
//                 std::cout << "5. Volver al Menu Principal\n"; // Opción de salida al menú principal (Modificación 1 y 2)
//                 std::cout << "Seleccione una opcion: ";
//                 std::cin >> opcionSub;

//                 if (std::cin.fail() || opcionSub < 1 || opcionSub > 5) {
//                     std::cin.clear();
//                     std::cin.ignore(10000, '\n');
//                     std::cout << "Opcion incorrecta. Intente de nuevo.\n";
//                     std::system("pause");
//                     continue;
//                 }

//                 if (opcionSub == 5) break;

//                 if (opcionSub == 1 || opcionSub == 2) {
//                     std::cin.ignore();
//                     std::string texto;
//                     std::cout << "Ingrese el texto: ";
//                     std::getline(std::cin, texto);

//                     int desplazamiento = 0;
//                     while (true) {
//                         std::cout << "Ingrese la clave (desplazamiento numerico entero): ";
//                         std::cin >> desplazamiento;
//                         if (std::cin.fail()) {
//                             std::cin.clear();
//                             std::cin.ignore(10000, '\n');
//                             std::cout << "Error: Debe ingresar un numero entero valido.\n";
//                         } else {
//                             break;
//                         }
//                     }

//                     Cesar cesarObj;
//                     std::string resultado = "";
//                     if (opcionSub == 1) {
//                         resultado = cesarObj.cifrar(texto, desplazamiento);
//                         std::cout << "\nResultado Cifrado: " << resultado << "\n";
//                         historialGlobal.agregarOperacion(usuarioActual, "Cifrado Cesar de texto");
//                     } else {
//                         resultado = cesarObj.descifrar(texto, desplazamiento);
//                         std::cout << "\nResultado Descifrado: " << resultado << "\n";
//                         historialGlobal.agregarOperacion(usuarioActual, "Descifrado Cesar de texto");
//                     }
//                     std::cout << "\nPresione Enter para continuar...";
//                     std::cin.ignore();
//                     std::cin.get();
//                 }
//                 else if (opcionSub == 3 || opcionSub == 4) {
//                     std::cin.ignore();
//                     std::string archivoEntrada = seleccionarArchivoAmigable(opcionSub == 3 ? "Cifrar César" : "Descifrar César");
//                     if (archivoEntrada.empty()) {
//                         std::system("pause");
//                         continue;
//                     }

//                     std::string archivoSalida;
//                     std::cout << "Ingrese el nombre del archivo de salida: ";
//                     std::cin >> archivoSalida;

//                     int desplazamiento = 0;
//                     std::cout << "Ingrese el desplazamiento (número entero): ";
//                     std::cin >> desplazamiento;

//                     Cesar cesarObj;
//                     bool exito = false;
//                     std::string tipoAccion = "";
//                     if (opcionSub == 3) {
//                         exito = cesarObj.cifrarArchivo(archivoEntrada, archivoSalida, desplazamiento);
//                         tipoAccion = "Cifrado César de archivo";
//                     } else {
//                         exito = cesarObj.descifrarArchivo(archivoEntrada, archivoSalida, desplazamiento);
//                         tipoAccion = "Descifrado César de archivo";
//                     }

//                     if (exito) {
//                         std::cout << "\n¡Archivo procesado exitosamente con César!\n";
//                         historialGlobal.agregarOperacion(usuarioActual, tipoAccion + " (" + archivoEntrada + ")");
//                     } else {
//                         std::cout << "\n[Error] No se pudo completar la operación con los archivos.\n";
//                     }
//                     std::system("pause");
//                 }
//             } while (true);
//             break;
//         }
//         case 2: { // NIVEL 2: XOR
//             int subOpcionMenu = 0;
//             do {
//                 system("cls||clear");
//                 std::cout << "--- NIVEL 2: CIFRADO XOR (BLOQUES BINARIOS) ---\n";
//                 std::cout << "1. Cifrar/Descifrar archivo binario\n";
//                 std::cout << "2. Volver al Menu Principal\n"; // Opción de salida al menú principal (Modificación 1)
//                 std::cout << "Seleccione una opcion: ";
//                 std::cin >> subOpcionMenu;

//                 if (std::cin.fail() || (subOpcionMenu != 1 && subOpcionMenu != 2)) {
//                     std::cin.clear();
//                     std::cin.ignore(10000, '\n');
//                     std::cout << "Opcion no valida. Intente de nuevo.\n";
//                     std::system("pause");
//                     continue;
//                 }

//                 if (subOpcionMenu == 2) break;

//                 std::cin.ignore();
//                 std::string rutaArchivo = seleccionarArchivoAmigable("para XOR");
//                 if (rutaArchivo.empty()) {
//                     std::system("pause");
//                     continue;
//                 }

//                 int accionXor = 0;
//                 do {
//                     std::cout << "\n¿Que desea hacer con el archivo?\n";
//                     std::cout << "1. Cifrar archivo\n";
//                     std::cout << "2. Descifrar archivo\n";
//                     std::cout << "Seleccion (1 o 2): ";
//                     std::cin >> accionXor;

//                     if (std::cin.fail() || (accionXor != 1 && accionXor != 2)) {
//                         std::cin.clear();
//                         std::cin.ignore(10000, '\n');
//                         std::cout << "Opcion invalida. Intente de nuevo.\n";
//                     } else {
//                         break;
//                     }
//                 } while (true);
//                 std::cin.ignore();

//                 std::string claveSecreta;
//                 std::cout << "Ingrese la clave secreta en texto: ";
//                 std::getline(std::cin, claveSecreta);

//                 char* buffer = nullptr;
//                 long tamano = 0;

//                 if (ArchivoManager::leerArchivoBinario(rutaArchivo, buffer, tamano)) {
//                     Xor xorObj;
//                     xorObj.cifrarBinario(buffer, tamano, claveSecreta);
//                     if (ArchivoManager::escribirArchivoBinario(rutaArchivo, buffer, tamano)) {
//                         std::string tipoAccion = (accionXor == 1) ? "Cifrado" : "Descifrado";
//                         std::cout << "\n¡Archivo '" << rutaArchivo << "' " << tipoAccion << " exitosamente con XOR!\n";
//                         historialGlobal.agregarOperacion(usuarioActual, tipoAccion + " XOR de archivo binario (" + rutaArchivo + ")");
//                     } else {
//                         std::cout << "Error al escribir el archivo procesado.\n";
//                     }
//                     delete[] buffer;
//                 } else {
//                     std::cout << "No se pudo leer el archivo especificado (" << rutaArchivo << "). Verifique que exista.\n";
//                 }

//                 std::cout << "\nPresione Enter para continuar...";
//                 std::cin.get();
//             } while (true);
//             break;
//         }
//         case 3: { // NIVEL 3: VIGENERE
//             int opcionSub = 0;
//             do {
//                 system("cls||clear");
//                 std::cout << "--- NIVEL 3: CIFRADO VIGENERE ---\n";
//                 std::cout << "1. Cifrar con clave de texto\n";
//                 std::cout << "2. Descifrar con clave de texto\n";
//                 std::cout << "3. Volver al Menu Principal\n"; // Opción de salida al menú principal (Modificación 1)
//                 std::cout << "Seleccione una opcion: ";
//                 std::cin >> opcionSub;

//                 if (std::cin.fail() || opcionSub < 1 || opcionSub > 3) {
//                     std::cin.clear();
//                     std::cin.ignore(10000, '\n');
//                     std::cout << "Opcion incorrecta. Intente de nuevo.\n";
//                     std::system("pause");
//                     continue;
//                 }

//                 if (opcionSub == 3) break;

//                 std::cin.ignore();
//                 std::string texto;
//                 std::cout << "Ingrese el texto o mensaje: ";
//                 std::getline(std::cin, texto);

//                 std::string clave;
//                 while (true) {
//                     std::cout << "Ingrese la clave de texto (solo letras, sin numeros): ";
//                     std::getline(std::cin, clave);
//                     if (!esSoloLetras(clave)) {
//                         std::cout << "Error: La clave de Vigenere debe contener unicamente letras alfabeticas.\n";
//                     } else {
//                         break;
//                     }
//                 }

//                 Vigenere vigenereObj;
//                 std::string resultado = "";
//                 if (opcionSub == 1) {
//                     resultado = vigenereObj.cifrarConClaveTexto(texto, clave);
//                     std::cout << "\nResultado Cifrado: " << resultado << "\n";
//                     historialGlobal.agregarOperacion(usuarioActual, "Cifrado Vigenere de texto");
//                 } else {
//                     resultado = vigenereObj.descifrarConClaveTexto(texto, clave);
//                     std::cout << "\nResultado Descifrado: " << resultado << "\n";
//                     historialGlobal.agregarOperacion(usuarioActual, "Descifrado Vigenere de texto");
//                 }

//                 std::cout << "\nPresione Enter para continuar...";
//                 std::cin.get();
//             } while (true);
//             break;
//         }
//         case 4: { // NIVEL 4: HISTORIAL Y REPORTES
//             system("cls||clear");
//             std::cout << "--- NIVEL 4: GESTION, HISTORIAL Y REPORTES ---\n";
//             std::cout << "Usuario actual: " << usuarioActual << " | Rol: " << rolUsuario << "\n\n";

//             historialGlobal.mostrarHistorial();

//             std::cout << "\n--- ESTADISTICAS DE USO DEL SISTEMA ---\n";
//             std::cout << "Total de operaciones realizadas: " << historialGlobal.obtenerTotalOperaciones() << "\n";

//             std::cout << "\nAplicando metodo de ordenamiento (Burbuja por usuario)...\n";
//             historialGlobal.ordenarPorUsuario();
//             std::cout << "Historial ordenado correctamente.\n";

//             std::cout << "\nPresione Enter para continuar...";
//             std::cin.ignore();
//             std::cin.get();
//             break;
//         }
//         case 5:
//             std::cout << "\nSaliendo del sistema Cripto-Manager...\n";
//             break;
//         default:
//             std::cout << "\nOpcion no valida. Intente de nuevo.\n";
//             std::system("pause");
//             break;
//         }
//     } while (opcion != 5);

//     return 0;
// }

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

// Selección fija y segura de archivos sin utilizar vectores
std::string seleccionarArchivoAmigable(const std::string& accionDesc) {
    std::cout << "\n--- ARCHIVOS DISPONIBLES (" << accionDesc << ") ---\n";
    std::cout << "1. prueba.txt\n";
    std::cout << "2. datos.dat\n";
    std::cout << "3. Escribir nombre manual\n";
    std::cout << "Seleccione una opción: ";

    int seleccion;
    if (!(std::cin >> seleccion)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return "";
    }

    if (seleccion == 1) {
        return "prueba.txt";
    } else if (seleccion == 2) {
        return "datos.dat";
    } else if (seleccion == 3) {
        std::string manual;
        std::cout << "Ingrese el nombre exacto del archivo: ";
        std::cin >> manual;
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

    std::string usuarioActual = "";
    std::string rolUsuario = "";

    if (!realizarLogin(usuarioActual, rolUsuario)) {
        std::cout << "\nSaliendo del sistema...\n";
        return 0;
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
                std::cout << "3. Cifrar archivo\n";
                std::cout << "4. Descifrar archivo\n";
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
                    std::string archivoEntrada = seleccionarArchivoAmigable(opcionSub == 3 ? "Cifrar César" : "Descifrar César");
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
                    bool exito = false;
                    std::string tipoAccion = "";
                    if (opcionSub == 3) {
                        exito = cesarObj.cifrarArchivo(archivoEntrada, archivoSalida, desplazamiento);
                        tipoAccion = "Cifrado César de archivo";
                    } else {
                        exito = cesarObj.descifrarArchivo(archivoEntrada, archivoSalida, desplazamiento);
                        tipoAccion = "Descifrado César de archivo";
                    }

                    if (exito) {
                        std::cout << "\n¡Archivo procesado exitosamente con César!\n";
                        historialGlobal.agregarOperacion(usuarioActual, tipoAccion + " (" + archivoEntrada + ")");
                    } else {
                        std::cout << "\n[Error] No se pudo completar la operación con los archivos.\n";
                    }
                    std::system("pause");
                }
            } while (true);
            break;
        }
        case 2: { // NIVEL 2: XOR
            int subOpcionMenu = 0;
            do {
                system("cls||clear");
                std::cout << "--- NIVEL 2: CIFRADO XOR (BLOQUES BINARIOS) ---\n";
                std::cout << "1. Cifrar/Descifrar archivo binario\n";
                std::cout << "2. Volver al Menu Principal\n";
                std::cout << "Seleccione una opcion: ";
                std::cin >> subOpcionMenu;

                if (std::cin.fail() || (subOpcionMenu != 1 && subOpcionMenu != 2)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Opcion no valida. Intente de nuevo.\n";
                    std::system("pause");
                    continue;
                }

                if (subOpcionMenu == 2) break;

                std::cin.ignore();
                std::string rutaArchivo = seleccionarArchivoAmigable("para XOR");
                if (rutaArchivo.empty()) {
                    std::system("pause");
                    continue;
                }

                int accionXor = 0;
                do {
                    std::cout << "\n¿Que desea hacer con el archivo?\n";
                    std::cout << "1. Cifrar archivo\n";
                    std::cout << "2. Descifrar archivo\n";
                    std::cout << "Seleccion (1 o 2): ";
                    std::cin >> accionXor;

                    if (std::cin.fail() || (accionXor != 1 && accionXor != 2)) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "Opcion invalida. Intente de nuevo.\n";
                    } else {
                        break;
                    }
                } while (true);
                std::cin.ignore();

                std::string claveSecreta;
                std::cout << "Ingrese la clave secreta en texto: ";
                std::getline(std::cin, claveSecreta);

                char* buffer = nullptr;
                long tamano = 0;

                if (ArchivoManager::leerArchivoBinario(rutaArchivo, buffer, tamano)) {
                    Xor xorObj;
                    xorObj.cifrarBinario(buffer, tamano, claveSecreta);
                    if (ArchivoManager::escribirArchivoBinario(rutaArchivo, buffer, tamano)) {
                        std::string tipoAccion = (accionXor == 1) ? "Cifrado" : "Descifrado";
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

            std::cout << "\nAplicando metodo de ordenamiento (Burbuja por usuario)...\n";
            historialGlobal.ordenarPorUsuario();
            std::cout << "Historial ordenado correctamente.\n";

            std::cout << "\nPresione Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 5:
            std::cout << "\nSaliendo del sistema Cripto-Manager...\n";
            break;
        default:
            std::cout << "\nOpcion no valida. Intente de nuevo.\n";
            std::system("pause");
            break;
        }
    } while (opcion != 5);

    return 0;
}