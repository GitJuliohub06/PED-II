#include <iostream>
#include <list>

void reemplazarPrimero(std::list<int>& lista, int buscar, int reemplazo) {
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        if (*it == buscar) {
            *it = reemplazo;
            break;
        }
    }
}

int main() {
    std::list<int> lista = {5, 10, 15, 10, 20};
    reemplazarPrimero(lista, 10, 99);
    for (auto x : lista) {
        std::cout << x << " ";
    }
}
// Salida: 5 99 15 10 20
