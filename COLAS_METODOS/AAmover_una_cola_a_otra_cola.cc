#include <iostream>
#include <queue>

void moverCola(std::queue<int>& origen, std::queue<int>& destino) {
    while (!origen.empty()) {
        destino.push(origen.front());
        origen.pop();
    }
}
