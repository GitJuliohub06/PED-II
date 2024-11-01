#include <iostream>
#include <queue>

int contarOcurrencias(std::queue<int> cola, int valor) {
    int contador = 0;
    while (!cola.empty()) {
        if (cola.front() == valor) contador++;
        cola.pop();
    }
    return contador;
}
