#include <iostream>
#include <list>

void ordenarDescendente(std::list<int>& lista) {
    lista.sort(std::greater<int>());
}
