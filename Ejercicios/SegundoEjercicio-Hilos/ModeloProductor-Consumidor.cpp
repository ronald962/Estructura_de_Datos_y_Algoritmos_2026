#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std;

//Función para limpiar la terminal dependiendo del sistema operativo
void limpiarTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

string mostrador = "";
bool hay_pan = false;

void panadero() {
    string panes[4] = {"Pan dulce","Baguette","Croissant","Ciabatta"};

    for (int i = 0; i < 4; i++) {
        this_thread::sleep_for(chrono::seconds(1));
        mostrador = panes[i];
        hay_pan   = true;
        cout << "[Panadero] Dejo: " << panes[i] << "\n";
        // espera a que el vendedor recoja antes de dejar otro
        while (hay_pan) {
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
}

void vendedor() {
    int vendidos = 0;
    while (vendidos < 4) {
        // espera hasta que haya pan en el mostrador
        while (!hay_pan) {
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        cout << "[Vendedor] Vendio: " << mostrador << "\n";
        hay_pan = false;
        vendidos++;
    }
    cout << "\n[Vendedor] Total vendido: " << vendidos << " panes\n";
}

int main() {
    limpiarTerminal();
    cout << "----Modelo Productor-Consumidor----\n";
    cout << "Situacion: Panadero y vendedor de pan\n\n";

    // El panadero produce pan y el vendedor lo vende, sincronizados por la variable 'hay_pan'
    thread p(panadero);
    thread v(vendedor);

    // Esperamos a que ambos terminen su trabajo
    p.join();
    v.join();

    cout << "Panaderia cerrada.\n";
    return 0;
}