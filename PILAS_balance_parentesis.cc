/*

Ejercicio 2: Comprobación de Paréntesis Balanceados
Crea un programa que verifique si una expresión tiene paréntesis equilibrada. Por ejemplo, en ((a + b) * (c - d)), los paréntesis están equilibrados, pero en ((a + b) * (c - d)no. El programa debe:

Leer una expresión de paréntesis.
Usar una pila para gestionar los paréntesis abiertos y cerrados.
Informar si la expresión está equilibrada o no.*/
#include <iostream>
#include <stack>
#include <string>

bool estaBalanceado(const std::string& expresion);

int main() {
    std::string expresion;
    std::cout << "Ingrese una expresion con paréntesis: ";
    std::getline(std::cin, expresion);

    if (estaBalanceado(expresion)) {
        std::cout << "La expresion esta balanceada.\n";
    } else {
        std::cout << "La expresion no esta balanceada.\n";
    }

    return 0;
}

bool estaBalanceado(const std::string& expresion) {
    std::stack<char> pila;

    for (char ch : expresion) {
        if (ch == '(') {
            pila.push(ch);  // Paréntesis de apertura, lo agregamos a la pila
        } else if (ch == ')') {
            if (pila.empty()) {
                return false;  // Paréntesis de cierre sin pareja
            }
            pila.pop();  // Empareja un paréntesis de apertura con uno de cierre
        }
    }

    return pila.empty();  // Si la pila está vacía, los paréntesis están balanceados
}
