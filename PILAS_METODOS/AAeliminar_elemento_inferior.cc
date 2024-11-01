#include <iostream>
#include <stack>

void eliminarInferior(std::stack<int>& pila) {
    std::stack<int> temp;
    while (pila.size() > 1) {
        temp.push(pila.top());
        pila.pop();
    }
    pila.pop(); // Eliminar el último elemento original
    while (!temp.empty()) {
        pila.push(temp.top());
        temp.pop();
    }
}
