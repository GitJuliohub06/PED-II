#include <iostream>
#include <list>

void eliminarElemento(std::list<int>& lista, int valor) {
    auto it = lista.begin();
    while (it != lista.end()) {
        if (*it == valor) {
            it = lista.erase(it); // Elimina el elemento y devuelve el siguiente
        } else {
            ++it;
        }
    }
}

int main() {
    std::list<int> lista = {1, 2, 3, 4, 5};
    eliminarElemento(lista, 3);
    for (auto x : lista) {
        std::cout << x << " ";
    }
}
// Salida: 1 2 4 5
