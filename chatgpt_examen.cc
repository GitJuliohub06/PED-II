
#include <iostream>
#include <list>
#include <stack>
#include <queue>

struct Libro
{
    std::string titulo = "";
    std::string autor = "";
    int codigo = 0;
};
/* 1. Gestión de Operaciones (Pilas)
   - Función PushOperation(stack<string>& operations, const string& op): Permite agregar una
 nueva operación a la pila.
   - Función PopOperation(stack<string>& operations): Remueve la operación más reciente y la
 muestra en pantalla.
   - Función PeekOperation(const stack<string>& operations): Muestra la operación más reciente sin
 eliminarla.*/

void PushOperation(std::stack<std::string>& operations, const std::string& op);
void PopOperation(std::stack<std::string>& operations);
void PeekOperation(const std::stack<std::string>& operations);
/////-/-/-/-/-/-/--/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/

/* 2. Gestión de Tareas (Colas)
   - Función AddTask(queue<string>& tasks, const string& task): Agrega una nueva tarea a la cola
 de tareas pendientes.
   - Función ProcessTask(queue<string>& tasks): Procesa (remueve y muestra) la tarea más
 antigua en la cola.
   - Función ListTasks(const queue<string>& tasks): Muestra todas las tareas pendientes.*/
void AddTask(std::queue<std::string>& tasks, const std::string& task);
void ProcessTask(std::queue<std::string>& tasks);
void ListTasks(const std::queue<std::string>& tasks);
//-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/4--//-/-/-//-/-/-/-/-/-/-//-/-/-//-/-/-/-/-/-//-

/*3. Gestión de Colección Ordenada (Listas)
   - Función AddElement(list<int>& elements, int element): Agrega un elemento a la lista de forma
 ordenada.
   - Función RemoveElement(list<int>& elements, int element): Elimina un elemento específico de la
 lista, si existe.
   - Función ListElements(const list<int>& elements): Muestra todos los elementos de la lista en
 orden.*/

void AddElement(std::list<int>& elements, int element);
void RemoveElement(std::list<int>& elements, int element);
void ListElements(const std::list<int>& elements);




int main(int argc, char *argv[])
{
    int opcion_del_usuario_en_el_menu_principal = 0;
    int opcion_del_usuario_en_el_menu_secundario = 0;
    std::string op = "";
    std::string task = "";
    int element = 0;
    std::stack<std::string> operations;
    std::queue<std::string> tasks;
    std::list<int> elements;

    do
    {
        std::cout << "----------MENU----------" << '\n';
        std::cout << "1. Funciones de pilas." << '\n';
        std::cout << "2. Funciones de colas." << '\n';
        std::cout << "3. Funciones de listas." << '\n';
        std::cout << "4. Salir." << '\n';
        std::cout << "Ingresa tu opcion: ";
        std::cin >> opcion_del_usuario_en_el_menu_principal;
        std::cin.ignore();

        switch (opcion_del_usuario_en_el_menu_principal)
        {
        case 1:
        do
        {
        std::cout << "----------MENU DE PILAS----------" << '\n';
        std::cout << "1. Agregar operacion a la pila." << '\n';
        std::cout << "2. Remover la operacion mas reciente." << '\n';
        std::cout << "3. Mostrar operacion mas reciente." << '\n';
        std::cout << "4. Salir." << '\n';
        std::cout << "Ingresa tu opcion: ";
        std::cin >> opcion_del_usuario_en_el_menu_secundario;
        std::cin.ignore();

            switch (opcion_del_usuario_en_el_menu_secundario)
            {
            case 1:
            std::cout<<"Ingrese la operacion a realizar: ";
            std::getline(std::cin, op);
            std::cin.ignore();
            PushOperation(operations, op);
                
                break;
            
            case 2: 
            PopOperation (operations);

                break;

            case 3: 
            PeekOperation(operations);

                break;
            
            case 4: 
            std::cout << "\n---Saliendo de la seccion de pilas---\n";

                break;


            default:
            std::cout<<"Ingrese una opcion valida";
                break;
            }
            
        } while (opcion_del_usuario_en_el_menu_secundario !=4);
        


            break;

        case 2:
            do
        {
        std::cout << "----------MENU DE COLAS----------" << '\n';
        std::cout << "1. Agregar una tarea a la cola de tareas pendientes." << '\n';
        std::cout << "2. Hacer la tarea mas antigua." << '\n';
        std::cout << "3. Mostrar todas las tareas pendientes." << '\n';
        std::cout << "4. Salir." << '\n';
        std::cout << "Ingresa tu opcion: ";
        std::cin >> opcion_del_usuario_en_el_menu_secundario;
        std::cin.ignore();

            switch (opcion_del_usuario_en_el_menu_secundario)
            {
            case 1:
            std::cout<<"Ingrese el nombre de la nueva tarea: ";
            std::getline(std::cin, task);
            std::cin.ignore();
            AddTask(tasks, task);
                
                break;
            
            case 2: 
            ProcessTask(tasks);

                break;

            case 3: 
            ListTasks(tasks);

                break;
            
            case 4: 
            std::cout << "\n---Saliendo de la seccion de pilas---\n";

                break;


            default:
            std::cout<<"Ingrese una opcion valida";
                break;
            }
            
        } while (opcion_del_usuario_en_el_menu_secundario !=4);

            break;

        case 3:
        do{
        std::cout << "----------MENU DE LISTAS----------" << '\n';
        std::cout << "1. Agregar un elemento a la lista." << '\n';
        std::cout << "2. Elimia un elemento en especifico." << '\n';
        std::cout << "3. Mostrar todos los elementos en orden." << '\n';
        std::cout << "4. Salir." << '\n';
        std::cout << "Ingresa tu opcion: ";
        std::cin >> opcion_del_usuario_en_el_menu_secundario;
        std::cin.ignore();

            switch (opcion_del_usuario_en_el_menu_secundario)
            {
            case 1:
            std::cout<<"Ingrese un numero para agregar a la lista: ";
            std::cin>>element;
            std::cin.ignore();
            AddElement(elements,element);
                
                break;
            
            case 2:
            std::cout<<"Ingrese el numero que desea borrar de la lista: ";
            std::cin>>element;
            std::cin.ignore();
            RemoveElement(elements, element);

                break;

            case 3: 
            ListElements(elements);

                break;
            
            case 4: 
            std::cout << "\n---Saliendo de la seccion de pilas---\n";

                break;


            default:
            std::cout<<"Ingrese una opcion valida";
                break;
            }
            
        } while (opcion_del_usuario_en_el_menu_secundario !=4);

            break;

        case 4:
            std::cout << "\n---Saliendo del programa...---\n";
            break;

        default:
        std::cout<<"Ingrese una opcion valida";
            break;
        }

    } while (opcion_del_usuario_en_el_menu_principal != 4);

    return 0;
}

void PushOperation(std::stack<std::string>& operations, const std::string& op){
/*Función PushOperation(stack<string>& operations, const string& op): Permite agregar una
 nueva operación a la pila.*/
std::cout<<"\nLa operación ''"<<op<<"'' Ha sido agregada exitosamente \n";
operations.push(op);
}

void PopOperation(std::stack<std::string>& operations){
std::cout<<"\nSe eliminara la ultima operacion ''"<<operations.top()<<"''\n";
operations.pop();

}

void PeekOperation(const std::stack<std::string>& operations){
std::cout<<"\n--------------------------------------------------------\n";
std::cout<<"\nLa ultima operacion registrada es: "<<operations.top();
std::cout<<"\n--------------------------------------------------------\n";
}


void AddTask(std::queue<std::string>& tasks, const std::string& task){
std::cout<<"\nLa tarea ''"<<task<<"'' Ha sido agregada exitosamente a la cola de tareas pendientes, metele que se nos acumulan :((((\n";
tasks.push(task);

}


void ProcessTask(std::queue<std::string>& tasks){
std::cout<<"\n--------------------------------------------------------\n";
std::cout<<"\nLa tarea : "<<tasks.front()<<" Ha sido finalizada, bien hecho champ :D";
std::cout<<"\n--------------------------------------------------------\n";
tasks.pop();

}


void ListTasks(const std::queue<std::string>& tasks){
    std::queue<std::string>tareitas;
    tareitas = tasks;
std::cout<<"\n--------------------------------------------------------\n";
if (tasks.empty())
{
    std::cout<<"Tranquilo campeon/na, no tienes tareas pendientes, descansa :)\n";
    std::cout<<"\n--------------------------------------------------------\n";
    return;
}

std::cout<<"\n-------------------TAREAS PENDIENTES-------------------";
while (!tareitas.empty())
{
    std::cout<<"*"<<tareitas.front()<<"\n";
    tareitas.pop();
}

std::cout<<"\n--------------------------------------------------------\n";    


}


void AddElement(std::list<int>& elements, int element){
std::cout<<"\nEl elemento ''"<<element<<"'' Ha sido agregada exitosamente a la lista de elementos\n";
elements.push_front(element);

}


void RemoveElement(std::list<int>& elements, int element){

    for (auto it = elements.begin(); it != elements.end(); ++it) {
        if (*it == element) {
            elements.erase(it);
            std::cout << "Elemento " << element << " eliminado de la lista.\n";
            return;
        }
    }
    std::cout << "Elemento " << element << " no encontrado en la lista.\n";
}


void ListElements(const std::list<int>& elements){

std::list<int> temp;
temp = elements;
int n = 1;

if (elements.empty())
{
    std::cout<<"La lista esta vacia";
    return;
}


   std::cout<<"\n---------------ELEMENTOS EN LA LISTA---------------\n";
while (!temp.empty())
{
 
    std::cout<<'\n'<<n<<": "<<temp.front()<<'\n';
    n++;
    temp.pop_front();
}


}

