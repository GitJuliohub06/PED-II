#include <iostream>
#include <stack>

int contarElementos(std::stack<int> pila) {
    int contador = 0;
    while (!pila.empty()) {
        contador++;
        pila.pop();
    }
    return contador;
}
