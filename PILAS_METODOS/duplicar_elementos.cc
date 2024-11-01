#include <iostream>
#include <stack>

void duplicarPila(std::stack<int>& pila) {
    std::stack<int> temp = pila;
    while (!temp.empty()) {
        pila.push(temp.top());
        temp.pop();
    }
}
