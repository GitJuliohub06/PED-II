#include <iostream>
#include <queue>

void duplicarCola(std::queue<int>& cola) {
    std::queue<int> temp = cola;
    while (!temp.empty()) {
        cola.push(temp.front());
        temp.pop();
    }
}
