#include <iostream>
#include <stack>

bool buscarValor(std::stack<int> pila, int valor) {
    while (!pila.empty()) {
        if (pila.top() == valor) return true;
        pila.pop();
    }
    return false;
}
