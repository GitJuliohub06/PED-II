/*Ejercicio 3: Sistema de Gestión de una Biblioteca (Listas Enlazadas)
Descripción: Crea un sistema para gestionar una lista de libros en una biblioteca usando una lista enlazada.
* Estructura Libro: Define una estructura para representar un libro, con los campos titulo, autor, y codigo.
Funciones:
* void AgregarLibro(std::list<Libro> &biblioteca): Añade un nuevo libro a la lista.
* void EliminarLibro(std::list<Libro> &biblioteca, std::string codigo): Elimina un libro de la lista según su código.
* void BuscarLibro(std::list<Libro> biblioteca, std::string titulo): Busca un libro por título y muestra sus detalles.
* void ListarLibros(std::list<Libro> biblioteca): Muestra todos los libros de la biblioteca.
Extra: Implementa una función int TotalLibros(std::list<Libro> biblioteca) que retorne el número total de libros.*/
#include <iostream>
#include <list>

struct Libro
{
    std::string titulo = "";
    std::string autor = "";
    int codigo = 0;
};

void AgregarLibro(std::list<Libro> &biblioteca);
void EliminarLibro(std::list<Libro> &biblioteca, int codigo);
void BuscarLibro(std::list<Libro> biblioteca, std::string titulo);
void ListarLibros(std::list<Libro> biblioteca);
int TotalLibros(std::list<Libro> biblioteca);

int main(int argc, char *argv[])
{
    int opcion_del_usuario_en_el_menu_principal = 0;
    std::string libro_a_buscar = "";
    int libro_a_borrar = 0;
    std::list<Libro> biblioteca;

    do
    {
        std::cout << "----------MENU----------" << '\n';
        std::cout << "1. Agregar libro." << '\n';
        std::cout << "2. Eliminar libro." << '\n';
        std::cout << "3. Buscar libro." << '\n';
        std::cout << "4. Base de datos de los libros." << '\n';
        std::cout << "5. Salir." << '\n';
        std::cout << "Ingresa tu opcion: ";
        std::cin >> opcion_del_usuario_en_el_menu_principal;
        std::cin.ignore();

        switch (opcion_del_usuario_en_el_menu_principal)
        {
        case 1:

            std::cout << "\n---REGISTRAR UN LIBRO---\n";
            AgregarLibro(biblioteca);

            break;

        case 2:
            std::cout << "\n---ELIMINAR LIBRO---\n";
            std::cout << "Ingrese el codigo del libro que quiere borrar: ";
            std::cin >> libro_a_borrar;
            EliminarLibro(biblioteca, libro_a_borrar);

            break;

        case 3:
            std::cout << "\n---BUSCAR LIBRO---\n";
            std::cout << "Escriba el nombre del libro a buscar: ";
            std::getline(std::cin, libro_a_buscar);
            std::cin.ignore();
            BuscarLibro(biblioteca, libro_a_buscar);

            break;

        case 4:
            std::cout << "\n---BASE DE DATOS DE LIBROS---\n";
            ListarLibros(biblioteca);
            std::cout << "\n Total de libros: " << TotalLibros(biblioteca) << '\n';

            break;

        case 5:
            std::cout << "\n---Saliendo del programa...---\n";

            break;

        default:
            break;
        }

    } while (opcion_del_usuario_en_el_menu_principal != 5);

    return 0;
}

void AgregarLibro(std::list<Libro> &biblioteca)
{
    Libro libro_temporal;
    std::cout << "----------AGREGAR LIBROS----------\n";
    std::cout << "Ingrese el nombre del libro: ";
    std::getline(std::cin, libro_temporal.titulo);
    std::cin.ignore();
    std::cout << "Ingrese el autor del libro: ";
    std::getline(std::cin, libro_temporal.autor);
    std::cin.ignore();
    std::cout << "Ingrese el codigo del libro: ";
    std::cin >> libro_temporal.codigo;
    std::cin.ignore();

    biblioteca.push_front(libro_temporal);
}

// void EliminarLibro(std::list<Libro> &biblioteca, std::string codigo): Elimina un libro de la lista según su código.
void EliminarLibro(std::list<Libro> &biblioteca, int codigo)
{
    if (biblioteca.empty())
    {
        std::cout << "\nNo hay ningun libro registrado en el sistema\n";
        return;
    }

    bool encontrado = false;
    
    for (auto it = biblioteca.begin(); it != biblioteca.end(); ++it)
    {
        if (it->codigo == codigo)
        {
            std::cout << "El libro " << it->titulo << " sera eliminado :(" << std::endl;
            biblioteca.erase(it); 
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
    {
        std::cout << "El libro no pudo ser encontrado." << std::endl;
    }
}


void BuscarLibro(std::list<Libro> biblioteca, std::string titulo)
{
    bool encontrado = false;
    if (biblioteca.empty())
    {
        std::cout << "No hay ningun libro registrado en el sistema";
    }

    while (!biblioteca.empty())
    {
        for (int i = 0; i < biblioteca.size(); i++)
        {
            if (biblioteca.front().titulo == titulo)
            {
                std::cout << "\n------------------------------------------------------------\n";
                std::cout << "Nombre del libro: " << biblioteca.front().titulo << "\n";
                std::cout << "Autor del libro: " << biblioteca.front().autor << "\n";
                std::cout << "codigo del libro: " << biblioteca.front().codigo << "\n";
                std::cout << "------------------------------------------------------------\n";
            }
            biblioteca.pop_front();
        }
    }
    if (!encontrado)
    {
        std::cout << "El libro no pudo ser encontrado.";
    }
}
void ListarLibros(std::list<Libro> biblioteca)
{

    if (biblioteca.empty())
    {
        std::cout << "No hay ningun libro registrado en el sistema";
    }

    while (!biblioteca.empty())
    {

        std::cout << "\n------------------------------------------------------------\n";
        std::cout << "Nombre del libro: " << biblioteca.front().titulo << "\n";
        std::cout << "Autor del libro: " << biblioteca.front().autor << "\n";
        std::cout << "codigo del libro: " << biblioteca.front().codigo << "\n";
        std::cout << "------------------------------------------------------------\n";

        biblioteca.pop_front();
    }
}

int TotalLibros(std::list<Libro> biblioteca)
{

    return biblioteca.size();
}
