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
    int max_cantidad_miembros;
    int numero_club;
    std::stack<Members> member;
};

void RegistrarClubs(std::stack<struct Club> &pila_club);
void ListClubs(std::stack<struct Club> pila_club);

int main(int argc, char *argv[])
{
    std::stack<Club> equipos;

    int menu_opcion = 0;

    do
    {
        std::cout << "\n-----MENU-----\n";
        std::cout << "1. Registrar un club\n";
        std::cout << "2. Mostrar los clubes creados\n";
        std::cout << "3. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> menu_opcion;

        switch (menu_opcion)
        {
        case 1:
            std::cout << "\n---REGISTRAR UN CLUB---\n";
            RegistrarClubs(equipos);
            break;

        case 2:
            std::cout << "\n---CLUBES REGISTRADOS---\n";
            ListClubs(equipos);
            break;

        case 3:
            std::cout << "Saliendo del programa...\n";
            break;

        default:
            std::cout << "Opcion no valida. Por favor, ingrese una opcion valida.\n";
            break;
        }
    } while (menu_opcion != 3);

    return 0;
}

void RegistrarClubs(std::stack<struct Club> &pila_club)
{
    Club clubes_aux;
    std::cout << "Nombre del club: ";
    std::cin.ignore();
    getline(std::cin, clubes_aux.nombre);
    std::cout << "Fecha de creacion: ";
    getline(std::cin, clubes_aux.fecha_de_creacion);
    std::cout << "Maxima cantidad de miembros: ";
    std::cin >> clubes_aux.max_cantidad_miembros;

    pila_club.push(clubes_aux);
}

void ListClubs(std::stack<struct Club> pila_club)
{
    if (pila_club.empty())
    {
        std::cout << "No hay clubes registrados\n";
        return;
    }


    while (!pila_club.empty())
    {
        std::cout << "- CLUB: " << pila_club.top().nombre << "\n";
        std::cout << "Fecha de creacion: " << pila_club.top().fecha_de_creacion << "\n";
        std::cout << "Maxima cantidad de miembros: " << pila_club.top().max_cantidad_miembros;
        std::cout << "\n--------------------------\n";
        pila_club.pop();
    }
}
