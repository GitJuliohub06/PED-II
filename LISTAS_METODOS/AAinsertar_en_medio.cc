#include <iostream>
#include <list>

void insertarEnMedio(std::list<int>& lista, int valor, int posicion) {
    auto it = lista.begin();
    std::advance(it, posicion); // Mover el iterador a la posición deseada
    lista.insert(it, valor);
}

int main() {
    std::list<int> lista = {1, 2, 4, 5};
    insertarEnMedio(lista, 3, 2);
    for (auto x : lista) {
        std::cout << x << " ";
    }
}
// Salida: 1 2 3 4 5
