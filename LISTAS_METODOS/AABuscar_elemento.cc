#include <iostream>
#include <list>

bool buscarElemento(const std::list<int>& lista, int valor) {
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        if (*it == valor) {
            return true;
        }
    }
    return false;
}

int main() {
    std::list<int> lista = {1, 2, 3, 4, 5};
    if(buscarElemento(lista,6)){
        
        std::cout<<"Encontrado";
    }
    
    else{
        std::cout<<"No encontrado";
    }
}