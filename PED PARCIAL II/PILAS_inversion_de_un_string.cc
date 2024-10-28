#include <iostream>
#include <stack>
#include <string>

void IngresarElementos(std::stack<char>& cadena);
void MostrarElementos(std::stack<char> cadena);

int main() {
    int opcion = 0;
    std::stack<char> cadena;

    do {
        std::cout << "----------MENU-----------\n";
        std::cout << "1. Ingresar elementos a la pila\n";
        std::cout << "2. Mostrar la pila invertida\n";
        std::cout << "3. Eliminar elementos de la pila\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;
        std::cin.ignore();  // Para limpiar el buffer de entrada

        switch (opcion) {
        case 1:
            IngresarElementos(cadena);
            break;

        case 2:
            MostrarElementos(cadena);
            break;

        case 3:
            while (!cadena.empty()) {
                cadena.pop();
            }
            std::cout << "La pila ha sido vaciada.\n";
            break;

        case 4:
            std::cout << "Saliendo del programa.\n";
            break;

        default:
            std::cout << "Opcion invalida. Intente nuevamente.\n";
            break;
        }
        std::cout << "\n";

    } while (opcion != 4);

    return 0;
}

void IngresarElementos(std::stack<char>& cadena) {
    std::string input;
    std::cout << "Ingrese una cadena: ";
    std::getline(std::cin, input);

    // Insertar cada carácter en la pila
    for (char letra : input) {
        cadena.push(letra);
    }
}

void MostrarElementos(std::stack<char> cadena) {
    std::cout << "Cadena invertida: ";
    while (!cadena.empty()) {
        std::cout << cadena.top();
        cadena.pop();
    }
    std::cout << "\n";
}
