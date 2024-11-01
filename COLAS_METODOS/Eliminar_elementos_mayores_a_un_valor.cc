#include <iostream>
#include <queue>

void eliminarMayores(std::queue<int>& cola, int limite) {
    std::queue<int> temp;
    while (!cola.empty()) {
        if (cola.front() <= limite) temp.push(cola.front());
        cola.pop();
    }
    cola = temp;
}
