#include <iostream>
#include <queue>
#include <stack>

void invertirCola(std::queue<int>& cola) {
    std::stack<int> pila;
    while (!cola.empty()) {
        pila.push(cola.front());
        cola.pop();
    }
    while (!pila.empty()) {
        cola.push(pila.top());
        pila.pop();
    }
}
