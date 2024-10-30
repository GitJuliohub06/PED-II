/*Ejercicio 2: Sistema de Deshacer y Rehacer (Pilas)
Descripción: Crea un sistema de "deshacer" y "rehacer" en un editor de texto simple usando pilas. Cada acción (escribir, borrar) se guarda en una pila de deshacer, y se puede rehacer si es necesario.

* Estructura Accion: Define una estructura que almacene el tipo de acción (escribir o borrar) y el texto afectado.
Funciones:
* void Escribir(std::stack<Accion> &deshacer, std::string &texto): Permite escribir texto y guarda esta acción en la pila de deshacer.
* void Borrar(std::stack<Accion> &deshacer, std::string &texto): Elimina el último carácter del texto y guarda esta acción en la pila de deshacer.
* void Deshacer(std::stack<Accion> &deshacer, std::stack<Accion> &rehacer, std::string &texto): Deshace la última acción, moviéndola a la pila de rehacer.
* void Rehacer(std::stack<Accion> &deshacer, std::stack<Accion> &rehacer, std::string &texto): Rehace la última acción deshecha.*/

#include <iostream>
#include <stack>

struct Accion
{
    std::string tipo = "";
    std::string texto = "";
};

void Escribir(std::stack<Accion> &deshacer, std::string &texto);
void Borrar(std::stack<Accion> &deshacer, std::string &texto);
void Deshacer(std::stack<Accion> &deshacer, std::stack<Accion> &rehacer, std::string &texto);
void Rehacer(std::stack<Accion> &deshacer, std::stack<Accion> &rehacer, std::string &texto);

int main(int argc, char *argv[])
{

    std::stack<Accion> deshace;

    std::stack<Accion> rehace;
    int opcion_menu = 0;
    std::string text = "Me gusta la comida ";

    do
    {
        std::cout << "-------TECLADO POR NUMERITOS--------" << '\n';
        std::cout << "Frase inicial: Me gusta la comida .........." << '\n';
        std::cout << "------OPCIONES------" << '\n';
        std::cout << "1. Agregar mas texto" << '\n';
        std::cout << "2. Delete" << '\n';
        std::cout << "3. CTRL + Z " << '\n';
        std::cout << "4. CTRL + Y" << '\n';
        std::cout << "5. Salir :("<<'\n';
        std::cout << "Ingrese su opcion (numero no sea tonto): ";
        std::cin >> opcion_menu;
        std::cin.ignore();
        

        switch (opcion_menu)
        {
        case 1:
            Escribir(deshace, text);
            std::cout << "\n";
            break;

        case 2:
            Borrar(deshace, text);
            std::cout << "\n";
            break;

        case 3:
            Deshacer(deshace, rehace, text);
            std::cout << "\n";

            break;

        case 4:
            Rehacer(deshace, rehace, text);
            std::cout << "\n";
            break;

        case 5:
            std::cout << "Saliendo del programa...\npc atacada :D";

            break;

        default:
            break;
        }

    } while (opcion_menu != 5);

    return 0;
}

void Escribir(std::stack<Accion> &deshacer, std::string &texto)
{
    std::string texto_del_usuario = "";
    std::cout << "Escriba un texto extra: ";
    std::getline(std::cin, texto_del_usuario);
    texto += texto_del_usuario;

    deshacer.push({"Escribir", texto});

    std::cout << "Tipo de accion: " << deshacer.top().tipo << "| Resultado : " << deshacer.top().texto << '\n';
}
// void Borrar(std::stack<Accion> &deshacer, std::string &texto): Elimina el último carácter del texto y guarda esta acción en la pila de deshacer.
void Borrar(std::stack<Accion> &deshacer, std::string &texto)
{
    char arregloChar[texto.length()];

    for (int i = 0; i < texto.length() - 1; i++)
    {
        arregloChar[i] = texto[i];
    }
    arregloChar[texto.length() - 1] = '\0';

    deshacer.push({"Borrar", arregloChar});
    std::cout << "Tipo de accion: " << deshacer.top().tipo << "| Resultado : " << deshacer.top().texto << '\n';
}
// void Deshacer(std::stack<Accion> &deshacer, std::stack<Accion> &rehacer, std::string &texto): Deshace la última acción, moviéndola a la pila de rehacer.
void Deshacer(std::stack<Accion> &deshacer, std::stack<Accion> &rehacer, std::string &texto)
{

    rehacer.push(deshacer.top());
    deshacer.pop();
    std::cout << "Resultado luego de deshacer : " << deshacer.top().texto << '\n';
}
// void Rehacer(std::stack<Accion> &deshacer, std::stack<Accion> &rehacer, std::string &texto): Rehace la última acción deshecha.
void Rehacer(std::stack<Accion> &deshacer, std::stack<Accion> &rehacer, std::string &texto)
{
    deshacer.push(rehacer.top());

    std::cout << "Resultado luego rehacer : " << deshacer.top().texto << '\n';
}
