#include <iostream>
#include <string>
#include <queue>
#include <thread>

using namespace std;

queue<string> fila;
string nombre;

void limpiar(){

    #if _WIN32
        system("cls");
    #else
        system("clear");
    #endif

}

int main() {
    limpiar();

    cout << "--- REGISTRO DE 10 PERSONAS - FIFO ---" << endl;

    for (int i = 1; i <= 10; i++) {
        cout << "Ingrese el nombre de la persona " << i << ": ";
        getline(cin, nombre);
        fila.push(nombre);
    }

    cout << "\n--- ATENCION DE PERSONAS ---" << endl;

    while (!fila.empty()) {
        cout << "Atendiendo a: " << fila.front() << endl;
        fila.pop(); 
    }

    cout << "\nYa se atendio a todas las personas..." << endl;
    cout << "\nPresione enter para salir..." << endl;
    cin.get();

    return 0;
}