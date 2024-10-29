#include <iostream>
#include <stack>

struct Members
{
    std::string first_name;
    std::string last_name;
    int edad;
};

struct Club
{
    std::string nombre;
    std::string fecha_de_creacion;
    int max_cantidad_miebros;
    std::stack<Members> member;
};

void RegristrarClubs(std::stack<struct Club> &pila_club);
void ListClubs(std::stack<struct Club> &pila_club);

int main(int argc, char *argv[])
{
    int num_clubs;
    std::stack<Club> equipos;

    int menu_opcion = 0;

    do
    {
        std::cout << "-----MENU-----\n";
        std::cout << "1. Registrar un club\n";
        std::cout << "2.Mostrar los club creados\n";
        std::cin >> menu_opcion;

        switch (menu_opcion)
        {
        case 1:
            std::cout << "REGISTRAR UN CLUB\n";
            RegristrarClubs(equipos);
            break;

        case 2:
            std::cout << "CLUBES REGISTRADOS\n";
            ListClubs(equipos);

        default:
            break;
        }
    } while (menu_opcion != 3);

    return 0;
}

void RegristrarClubs(std::stack<struct Club> &pila_club)
{
    Club clubes_aux;
    std::cout << "Nombre del club:";
    std::cin.ignore();
    getline(std::cin, clubes_aux.nombre);
    std::cout << "Fecha de creacion: ";
    getline(std::cin, clubes_aux.fecha_de_creacion);
    std::cout << "Maxima cantidad de mimebros: ";
    std::cin >> clubes_aux.max_cantidad_miebros;

    pila_club.push(clubes_aux);
}

void ListClubs(std::stack<struct Club> &pila_club)
{
    if (pila_club.empty())
    {
        std::cout << "No hay clubes registrados";
        return;
    }

    std::cout << "CLUBES REGISTRADOS\n";
    while (!pila_club.empty())
    {
        std::cout << "-CLUB " << pila_club.top().nombre << "\n";
        std::cout << "Fecha de creacion: " << pila_club.top().fecha_de_creacion;
        std::cout << "\nMaxima cantidad de miembros: " << pila_club.top().max_cantidad_miebros;
        pila_club.pop();
        std::cout << "\n--------------------------\n";
    }
    std::cout << std::endl;
}
