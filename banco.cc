#include <iostream>
#include <queue>
#include <string>

// addClient agrega clientes, serveClient atiende y remueve al primero, y displayClients muestra la lista de todos los clientes en espera. Cada función permite gestionar la cola de manera ordenada y eficiente para simular una fila de espera en un banco.

void AddClient(std::queue<std::pair<int, std::string>> &clients, int ticketNumber, const std::string &name);
void ServeClient(std::queue<std::pair<int, std::string>> &clients);
void DisplayClients(const std::queue<std::pair<int, std::string>> &clients);

int main(int argc, char *argv[])
{
    int opcion_del_usuario_en_el_menu_principal = 0;
    std::string nombre_del_cliente = "";
    int num_ticket = 0;
    std::queue<std::pair<int, std::string>> clients;

    do
    {
        std::cout << "----------MENU----------" << '\n';
        std::cout << "1. Agregar cliente." << '\n';
        std::cout << "2. Despachar cliente." << '\n';
        std::cout << "3. Mostrar cola de clientes." << '\n';
        std::cout << "4. Salir." << '\n';
        std::cout << "Ingresa tu opcion: ";
        std::cin >> opcion_del_usuario_en_el_menu_principal;
        std::cin.ignore();

        switch (opcion_del_usuario_en_el_menu_principal)
        {
        case 1:

            std::cout << "\n---Escriba el nombre del cliente---\n";
            std::getline(std::cin, nombre_del_cliente);
            std::cin.ignore();
            num_ticket += 1;
            AddClient(clients, num_ticket, nombre_del_cliente);

            break;

        case 2:
            ServeClient(clients);

            break;

        case 3:
            DisplayClients(clients);

            break;

        case 4:
            std::cout << "\n---Saliendo del programa...---\n";

            break;

        default:
            break;
        }

    } while (opcion_del_usuario_en_el_menu_principal != 4);

    return 0;
}
void AddClient(std::queue<std::pair<int, std::string>> &clients, int ticketNumber, const std::string &name)
{
    /*    std::string nombre_cliente = "";
        int numero_cliente = 0;
        std::cout<<"\n----------AGREGAR CLIENTE----------\n";
        std::cout<<"Escriba el nombre del cliente:";
        std::getline(std::cin, nombre_cliente);
        std::cin.ignore();*/

    clients.push({ticketNumber, name});
    std::cout << "\n----------CLIENTE AGREGADO EXITOSAMENTE----------\n";
}

void ServeClient(std::queue<std::pair<int, std::string>> &clients)
{
    std::queue<std::pair<int, std::string>> goku;
    std::cout << "\n----------DESPACHAR CLIENTE----------\n";
    std::cout << "---------------------------------------------------------\n";
    std::cout << "\nNombre del cliente: " << clients.front().second << "\nNumero de ticket del cliente: " << clients.front().first << '\n';
    std::cout << "---------------------------------------------------------\n";
    clients.pop();
    std::cout << "\n----------CLIENTE DESPACHADO EXITOSAMENTE----------\n";
    while (!clients.empty())
    {
        goku.push({clients.front().first - 1, clients.front().second});
        clients.pop();
    }
    clients = goku;
}

void DisplayClients(const std::queue<std::pair<int, std::string>> &clients)
{
    std::queue<std::pair<int, std::string>> goku;
    goku = clients;
    std::cout << "\n----------LISTA DE CLIENTES----------\n";
    if (goku.empty())
    {
        std::cout << "No hay clientes en espera";
    }

    while (!goku.empty())
    {
        std::cout << "---------------------------------------------------------\n";
        std::cout << "\nNombre del cliente: " << goku.front().second << "\nNumero de ticket del cliente: " << goku.front().first << '\n';
        std::cout << "---------------------------------------------------------\n";
        goku.pop();
    }
}