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

void amigo(const string& nombre, const string& actividad, int segundos) {
    cout << nombre << " empezo: " << actividad << "\n";
    this_thread::sleep_for(chrono::seconds(segundos));
    cout << nombre << " termino: " << actividad << "\n";
}

int main() {
    limpiarTerminal();
    cout << "----Modelo Hilos Independientes----\n";
    cout << "Situacion: 3 amigos de vacaciones\n\n";

    // Cada hilo hace lo suyo sin saber de los demas
    thread t1(amigo, "Luis",   "ir a la playa",  3);
    thread t2(amigo, "Maria",  "visitar museo",  2);
    thread t3(amigo, "Carlos", "buscar restaurante", 1);

    // Esperamos a que cada uno termine lo suyo, sin importar el orden
    t1.join();
    t2.join();
    t3.join();

    cout << "\nTodos regresaron al hotel!\n";
    return 0;
}