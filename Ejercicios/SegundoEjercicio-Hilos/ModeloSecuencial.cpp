#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

// Función para limpiar la terminal dependiendo del sistema operativo
void limpiarTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    limpiarTerminal();
    cout << "----Modelo Secuencial----" << endl;
    cout << "Situación: Preparar comida\nOpcion(Si o No): ";
    string realizar; cin >> realizar; // Se lee la opción del usuario para decidir si se prepara la comida o no
    if(realizar == "Si" || realizar == "si" || realizar == "SI"|| realizar == "sI"){
        limpiarTerminal(); // Limpia la terminal antes de mostrar el proceso de preparación de la comida
        // Simulación de la preparación de la comida con retrasos para cada paso
        cout << "---Preparando comida---" << endl; this_thread::sleep_for(chrono::seconds(1));
        cout << "Preparando salsa..." << endl; this_thread::sleep_for(chrono::seconds(1));
        cout << "Preparando pasta..." << endl; this_thread::sleep_for(chrono::seconds(1));
        cout << "Preparando ensalada..." << endl; this_thread::sleep_for(chrono::seconds(1));
        cout << "Comida echa!" << endl;
    } else {// Si el usuario no desea preparar la comida, se muestra un mensaje indicando que no se preparará
       cout << "No se preparará la comida." << endl;

    }
}