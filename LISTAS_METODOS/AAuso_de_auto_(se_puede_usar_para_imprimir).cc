#include <iostream>
#include <list>

void imprimirLista(const std::list<int>& lista) {
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> lista = {10, 20, 30, 40};
    imprimirLista(lista);
}
// Salida: 10 20 30 40
