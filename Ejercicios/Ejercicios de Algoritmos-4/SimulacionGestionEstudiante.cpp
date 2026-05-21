#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>
using namespace std;
 
// <id, nombres, escuela, promedio>
using Estudiante = tuple<string, vector<string>, string, float>;
vector<Estudiante> listaEstudiantes;

// Función para limpiar la terminal
void LimpiarTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Pausa la ejecucion por un numero de segundos (default: 2)
void Pausar(int segundos = 2) {
    this_thread::sleep_for(chrono::seconds(segundos));
}

// Verifica si un ID ya existe en la lista de estudiantes
bool IdExiste(const string& id) {
    for (const auto& e : listaEstudiantes)
        if (get<0>(e) == id) return true;
    return false;
}

// Función para ingresar un nuevo estudiante
void IngresarEstudiante() {
    LimpiarTerminal();
    string id, escuela, nombre;
    float promedio;
    vector<string> nombres;
 
    cout << "=== Ingresar estudiante ===\n\n";
 
    cout << "ID: ";
    cin >> id;
 
    if (IdExiste(id)) {
        cout << "\nYa existe un estudiante con el ID \"" << id << "\".\n";
        Pausar();
        return;
    }
 
    cout << "Nombres (escriba 'fin' para terminar):\n";
    while (true) {
        cout << "  -> ";
        cin >> nombre;
        if (nombre == "fin") break;
        nombres.push_back(nombre);
    }
 
    if (nombres.empty()) {
        cout << "\nDebe ingresar al menos un nombre\n";
        Pausar();
        return;
    }
 
    cout << "Escuela: ";
    cin.ignore();
    getline(cin, escuela);
 
    cout << "Promedio (0-20): ";
    while (!(cin >> promedio) || promedio < 0 || promedio > 20) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Valor invalido. Ingrese un numero entre 0 y 20: ";
    }
 
    listaEstudiantes.emplace_back(id, nombres, escuela, promedio);
    LimpiarTerminal();
    cout << "Estudiante registrado correctamente\n";
    Pausar();
}

// Función para mostrar los detalles de un estudiante
void MostrarEstudiante(const Estudiante& e) {
    cout << "  ID       : " << get<0>(e) << "\n";
    cout << "  Nombres  : ";
    for (const auto& n : get<1>(e)) cout << n << " ";
    cout << "\n";
    cout << "  Escuela  : " << get<2>(e) << "\n";
    cout << "  Promedio : " << get<3>(e) << "\n";
    cout << string(30, '-') << "\n";
}

// Función para mostrar todos los estudiantes registrados
void MostrarTodos() {
    LimpiarTerminal();
    cout << "=== Lista de estudiantes ===\n\n";
 
    if (listaEstudiantes.empty()) {
        cout << "No hay estudiantes registrados\n";
        Pausar();
        return;
    }
 
    for (const auto& e : listaEstudiantes)
        MostrarEstudiante(e);
 
    cout << "\nTotal: " << listaEstudiantes.size() << " estudiante(s).\n";
    Pausar(3);
}
 
// Función para buscar un estudiante por ID
void BuscarEstudiante() {
    LimpiarTerminal();
    cout << "=== Buscar estudiante ===\n\n";
    string id;
    cout << "ID a buscar: ";
    cin >> id;
 
    for (const auto& e : listaEstudiantes) {
        if (get<0>(e) == id) {
            cout << "\n";
            MostrarEstudiante(e);
            Pausar(3);
            return;
        }
    }
 
    cout << "\nNo se encontro ningun estudiante con ID \"" << id << "\"\n";
    Pausar();
}
 
// Función para eliminar un estudiante por ID
void EliminarEstudiante() {
    LimpiarTerminal();
    cout << "=== Eliminar estudiante ===\n\n";
    string id;
    cout << "ID a eliminar: ";
    cin >> id;
 
    auto it = remove_if(listaEstudiantes.begin(), listaEstudiantes.end(),
        [&id](const Estudiante& e) { return get<0>(e) == id; });
 
    if (it == listaEstudiantes.end()) {
        cout << "\nNo se encontro el ID \"" << id << "\"\n";
    } else {
        listaEstudiantes.erase(it, listaEstudiantes.end());
        cout << "\nEstudiante eliminado\n";
    }
    Pausar();
}
 
int main() {
    LimpiarTerminal();

    // Bucle principal del programa
    while (true) {
        // Mostrar el menú
        cout << "=== Gestion de Estudiantes ===\n";
        cout << "  Registrados: " << listaEstudiantes.size() << "\n\n";
        cout << "1- Ingresar estudiante\n";
        cout << "2- Mostrar todos\n";
        cout << "3- Buscar por ID\n";
        cout << "4- Eliminar por ID\n";
        cout << "5- Salir\n\n";
        cout << "Opcion: ";
 
        int opcion;
        cin >> opcion;
 
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            LimpiarTerminal();
            cout << "Entrada no valida. Ingrese un numero\n\n";
            Pausar();
            LimpiarTerminal();
            continue;
        }
 
        // Ejecutar la opcion seleccionada
        switch (opcion) {
            case 1: IngresarEstudiante();  break;
            case 2: MostrarTodos();        break;
            case 3: BuscarEstudiante();    break;
            case 4: EliminarEstudiante();  break;
            case 5:
                LimpiarTerminal();
                cout << "Saliendo...\n";
                return 0;
            // Opcion no valida
            default:
                LimpiarTerminal();
                cout << "Opcion no valida\n\n";
                Pausar();
                LimpiarTerminal();
                break;
        }
    }
}
