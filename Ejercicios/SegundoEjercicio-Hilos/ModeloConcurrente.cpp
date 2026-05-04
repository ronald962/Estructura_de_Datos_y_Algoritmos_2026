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

void cocinar(string platillo, int segundos) {
    cout << "Cocinando " << platillo << "...\n";
    this_thread::sleep_for(chrono::seconds(segundos));
    cout << platillo << " listo!\n";
}

int main() {
    limpiarTerminal();
    cout << "----Modelo Concurrente----\n";
    cout << "Situacion: 3 ollas en la estufa a la vez\n\n";

    // Cada hilo cocina un platillo diferente al mismo tiempo
    thread t1(cocinar, "Tallarines rojos", 3);
    thread t2(cocinar, "Pollo Atomatado", 2);
    thread t3(cocinar, "Arroz con Pollo", 1);

    t1.join();
    t2.join();
    t3.join();

    cout << "\nTodas las comidas estan listas!\n";
    return 0;
}