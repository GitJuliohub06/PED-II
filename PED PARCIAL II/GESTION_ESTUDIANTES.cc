#include <iostream>
#include <list>
#include <stack>
#include <string>

struct Usuario {
    int id;
    std::string nombre;
};

void agregarUsuario(std::list<Usuario>& usuarios, int id, std::string nombre) {
    Usuario usuario;
    usuario.id = id;
    usuario.nombre = nombre;
    usuarios.push_back(usuario);
}
void insertarUsuario(std::list<Usuario>& usuarios, int id, std::string nombre, int posicion) {
    Usuario usuario;
    usuario.id = id;
    usuario.nombre = nombre;

    auto it = usuarios.begin();
    std::advance(it, posicion);
    usuarios.insert(it, usuario);
}

void eliminarUsuarioPorID(std::list<Usuario>& usuarios, std::stack<int>& idsEliminados, int id) {
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        if (it->id == id) {
            idsEliminados.push(it->id); // Guardar en pila
            usuarios.erase(it); // Borrar usuario de la lista
            return;
        }
    }
    std::cout << "Usuario con ID " << id << " no encontrado.\n";
}
void mostrarUsuarios(const std::list<Usuario>& usuarios) {
    for (const auto& usuario : usuarios) {
        std::cout << "ID: " << usuario.id << ", Nombre: " << usuario.nombre << std::endl;
    }
}
void mostrarIDsEliminados(std::stack<int>& idsEliminados) {
    while (!idsEliminados.empty()) {
        std::cout << "ID eliminado: " << idsEliminados.top() << std::endl;
        idsEliminados.pop();
    }
}
int main() {
    std::list<Usuario> usuarios;
    std::stack<int> idsEliminados;

    // Insertar usuarios
    insertarUsuario(usuarios, 1, "Juan", 0);
    insertarUsuario(usuarios, 2, "Ana", 1);
    insertarUsuario(usuarios, 3, "Luis", 2);

    // Mostrar lista inicial
    std::cout << "Lista inicial de usuarios:\n";
    mostrarUsuarios(usuarios);

    // Eliminar un usuario
    eliminarUsuarioPorID(usuarios, idsEliminados, 2);

    // Mostrar lista después de eliminación
    std::cout << "\nLista después de eliminar usuario con ID 2:\n";
    mostrarUsuarios(usuarios);

    // Mostrar IDs eliminados
    std::cout << "\nIDs eliminados:\n";
    mostrarIDsEliminados(idsEliminados);

    return 0;
}
