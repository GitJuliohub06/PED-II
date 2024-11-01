#include <iostream>
#include <list>

void eliminarMayores(std::list<int>& lista, int limite) {
    for (auto it = lista.begin(); it != lista.end(); ) {
        if (*it > limite) {
            it = lista.erase(it);
        } else {
            ++it;
        }
    }
}
