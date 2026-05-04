#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std;

// Función para limpiar la terminal dependiendo del sistema operativo
void limpiarTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

string tareas[8] = {
    "Pintar pared A",
    "Pintar pared B",
    "Poner ceramica",
    "Instalar puerta",
    "Instalar ventana",
    "Limpiar escombros",
    "Revision final A",
    "Revision final B"
};

int  hechas_por[3] = {0, 0, 0};

// Cada albanil tiene su propio rango de tareas asignado
void albanil(int id, int ini, int fin) {
    for (int i = ini; i < fin; i++) {
        cout << "[Albanil " << id << "] Haciendo: " << tareas[i] << "\n";
        this_thread::sleep_for(chrono::seconds(1));
        cout << "[Albanil " << id << "] Listo   : " << tareas[i] << "\n";
        hechas_por[id - 1]++;
    }
    cout << "[Albanil " << id << "] Termine mis tareas.\n";
}

int main() {
    limpiarTerminal();
    cout << "----Modelo Maestro-Trabajador----\n";
    cout << "Situacion: Jefe reparte tareas a 3 albaniles\n\n";
    cout << "[Jefe] Repartiendo 8 tareas entre 3 albaniles...\n\n";

    // El jefe asigna el rango de cada uno
    thread a1(albanil, 1, 0, 3);  // tareas 0,1,2
    thread a2(albanil, 2, 3, 6);  // tareas 3,4,5
    thread a3(albanil, 3, 6, 8);  // tareas 6,7

    // El jefe espera a que cada albanil termine sus tareas asignadas
    a1.join();
    a2.join();
    a3.join();

    cout << "\n[Jefe] Obra terminada!\n";
    cout << "--- Reporte ---\n";
    cout << "Albanil 1: " << hechas_por[0] << " tareas\n";
    cout << "Albanil 2: " << hechas_por[1] << " tareas\n";
    cout << "Albanil 3: " << hechas_por[2] << " tareas\n";
    return 0;
}