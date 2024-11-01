#include <iostream>
#include <stack>

void eliminarImpares(std::stack<int>& pila) {
    std::stack<int> temp;
    while (!pila.empty()) {
        if (pila.top() % 2 == 0) temp.push(pila.top());
        pila.pop();
    }
    while (!temp.empty()) {
        pila.push(temp.top());
        temp.pop();
    }
}
