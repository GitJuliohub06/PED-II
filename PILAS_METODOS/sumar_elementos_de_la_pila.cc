#include <iostream>
#include <stack>

int sumarElementos(std::stack<int> pila) {
    int suma = 0;
    while (!pila.empty()) {
        suma += pila.top();
        pila.pop();
    }
    return suma;
}
