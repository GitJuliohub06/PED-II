#include <iostream>
#include <list>

void moverElementos(std::list<int>& origen, std::list<int>& destino) {
    destino.splice(destino.end(), origen); // Mueve todos los elementos
}
