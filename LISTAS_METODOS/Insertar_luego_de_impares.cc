#include <iostream>
#include <list>

void insertarDespuesImpar(std::list<int>& lista, int valor) {
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        if (*it % 2 != 0) {
            it = lista.insert(++it, valor); // Insertar y avanzar
        }
    }
}
