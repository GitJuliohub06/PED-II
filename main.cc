#include <iostream>
#include <stack>

struct Members
{
    std::string first_name;
    std::string last_name;
    int age;
};

struct Club
{
    std::string name;
    std::string creation_date;
    int max_capacity;
    std::stack<Members> miembros_del_club;
};
void RegistrarClubs(std::stack<struct Club> &pila_club);
void ListClubs(std::stack<struct Club> pila_club);

void RegisterMember(Club &club);
void ListMembers(Club club);

int main(int argc, char *argv[])
{

    int opcion_del_usuario_en_el_menu_principal = 0;
    Club club1;
    club1.creation_date = "dsf";
    club1.max_capacity = 3;
    club1.name = "FAS";

    std::stack<Club> clubs;
    clubs.push(club1);
    do
    {
        std::cout << "----------MENU----------" << '\n';
        std::cout << "1. Crear un club." << '\n';
        std::cout << "2. Listar clubs." << '\n';
        std::cout << "3. Ingresar a un club." << '\n';
        std::cout << "4. Listar miembros de un club." << '\n';
        std::cout << "5. Total de miembros de un club." << '\n';
        std::cout << "6. Salir." << '\n';
        std::cout << "Ingresa tu opcion: ";
        std::cin >> opcion_del_usuario_en_el_menu_principal;

        switch (opcion_del_usuario_en_el_menu_principal)
        {
        case 1:

            std::cout << "\n---REGISTRAR UN CLUB---\n";
            RegistrarClubs(clubs);

            break;

        case 2:
            std::cout << "\n---CLUBS REGISTRADOS---\n";
            ListClubs(clubs);

            break;

        case 3:
            RegisterMember(club1);

            break;

        case 4:
            ListMembers(club1);

            break;

        case 5:

            break;

        case 6:

            break;

        default:
            break;
        }

    } while (opcion_del_usuario_en_el_menu_principal != 6);

    return 0;
}

void RegistrarClubs(std::stack<struct Club> &pila_club)
{
    Club clubes_aux;
    std::cout << "Nombre del club: ";
    std::cin.ignore();
    getline(std::cin, clubes_aux.name);
    std::cout << "Fecha de creacion: ";
    getline(std::cin, clubes_aux.creation_date);
    std::cout << "Maxima cantidad de miembros: ";
    std::cin >> clubes_aux.max_capacity;

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
        std::cout << "- CLUB " << pila_club.top().name << "\n";
        std::cout << "Fecha de creacion: " << pila_club.top().creation_date << "\n";
        std::cout << "Maxima cantidad de miembros: " << pila_club.top().max_capacity;
        std::cout << "\n--------------------------\n";
        pila_club.pop();
    }
}

void RegisterMember(Club &club)
{

    /*oRegistra un miembro en un club y lo almacena en el arreglo de miembros del club.*/
    Members miembro_temporal;
    if (club.miembros_del_club.size() < club.max_capacity)
    {
        std::cout << "Ingrese el nombre del miemrbo: ";
        std::cin >> miembro_temporal.first_name;
        std::cout << "Ingrese el apellido del miembro: ";
        std::cin >> miembro_temporal.last_name;
        std::cout << "Ingrese la edad del miembro: ";
        std::cin >> miembro_temporal.age;

        club.miembros_del_club.push(miembro_temporal);
    }
}

void ListMembers(Club club)
{
    // Club club_temporal;
    // std::stack<Member> miembros_temporales;
    while (!club.miembros_del_club.empty())
    {
        std::cout << "Nombre: " << club.miembros_del_club.top().first_name << " " << club.miembros_del_club.top().last_name << " Edad: " << club.miembros_del_club.top().age << "\n";
        // miembros_temporales.push(club.miembros_del_club.top());
        club.miembros_del_club.pop();
    }
    /*while ((club.miembros_del_club.empty())&&(!miembros_temporales.empty()))
    {
        club.miembros_del_club.push(miembros_temporales.top());
        miembros_temporales.pop();
    }*/
}
