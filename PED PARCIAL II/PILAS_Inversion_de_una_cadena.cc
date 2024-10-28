#include <iostream>
#include <stack>

/*Escribe un programa que use una pila para invertir una cadena de caracteres ingresada por el usuario. El programa debe:

Leer una cadena.
Insertar cada carácter en una pila.
Extraer los caracteres de la pila para reconstruir la cadena invertida y mostrarla.*/



void IngresarElementos (std::stack<char> &cadena);

void MostrarElementos (std::stack<char> cadena);

int main(int argc, char* argv[] ){
int opcion_del_usuario_en_el_menu = 0;

std::stack<char> cadena;

do
{
    std::cout<<"----------MENU-----------\n";
    std::cout<<"1. Ingresar elementos a la pila\n";
    std::cout<<"2. Mostrar la pila invertida\n";
    std::cout<<"3. Eliminar último elemento ingresado\n";
    std::cout<<"Ingrese su opcion aca:";
    std::cin>>opcion_del_usuario_en_el_menu;
    std::cout<<"\n";


    switch (opcion_del_usuario_en_el_menu)
    {
    case 1:
        IngresarElementos (cadena);
        break;

    case 2: 
        MostrarElementos(cadena);
    break;

    case 3: 
        cadena.pop();
    
    break;

    default:
        break;
    }


} while (opcion_del_usuario_en_el_menu !=4);




    return 0;
}

void IngresarElementos (std::stack<char> &cadena){
    char letra_del_usuario = 'a';
    std::cout<<"Ingrese una letra: ";
    std::cin>>letra_del_usuario;
    cadena.push(letra_del_usuario);
}

void MostrarElementos (std::stack<char> cadena){

    while (!cadena.empty())
    {
        std::cout<<cadena.top();
        cadena.pop();
    }
    
        
    
    std::cout<<"\n";

}