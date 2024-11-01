#include <iostream>
#include <queue>

void duplicarValores(std::queue<int>& cola) {
    std::queue<int> temp;
    while (!cola.empty()) {
        temp.push(cola.front() * 2);
        cola.pop();
    }
    cola = temp;
}
