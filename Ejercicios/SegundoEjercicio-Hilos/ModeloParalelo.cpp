#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// Función para limpiar la terminal dependiendo del sistema operativo
void limpiarTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

const int TOTAL = 12;
int cajas[TOTAL] = {3,7,1,9, 4,6,8,2, 5,11,0,10};

// Cada amigo cuenta cuántos objetos hay en sus cajitas
void revisar(int ini, int fin, int id, int& resultado) {
    resultado = 0;
    cout << "Amigo " << id << " revisando cajas ["
         << ini << " - " << fin-1 << "]\n";

    for (int i = ini; i < fin; i++) {
        resultado += cajas[i];
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    cout << "Amigo " << id << " termino, encontro: "
         << resultado << " objetos\n";
}

int main() {
    limpiarTerminal();
    cout << "----Modelo Paralelo----\n";
    cout << "Situacion: 3 amigos revisando cajitas\n\n";

    int r1 = 0, r2 = 0, r3 = 0;

    // Cada hilo trabaja su propio bloque de cajas sin interferir con los demás
    thread t1(revisar, 0, 4,  1, ref(r1));
    thread t2(revisar, 4, 8,  2, ref(r2));
    thread t3(revisar, 8, 12, 3, ref(r3));

    // Esperamos a que cada amigo termine su revisión, sin importar el orden
    t1.join();
    t2.join();
    t3.join();

    cout << "\nTotal de objetos: " << r1 + r2 + r3 << "\n";
    return 0;
}