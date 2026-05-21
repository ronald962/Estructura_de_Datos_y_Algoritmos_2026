#include <iostream>
#include <queue>
#include <stack>
#include <thread>
#include <chrono>

using namespace std;

// Declaración de la cola y la pila
queue<int> cola;
stack<int> pila;
int n;

// Función para limpiar la terminal
void limpiarTerminal(){
    #if _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Función para invertir la cola utilizando la pila
void invertirCola(queue<int>& Cola, stack<int>& Pila) {
    while (!Cola.empty()) {
        Pila.push(Cola.front());
        Cola.pop();
    }
    while (!Pila.empty()) {
        Cola.push(Pila.top());
        Pila.pop();
    }
}

// Función para mostrar los elementos de la cola
void mostrarCola(queue<int> Cola) {
    while (!Cola.empty()) {
        cout << Cola.front() << " ";
        Cola.pop();
    }
    cout << endl;
}

int main() {
    limpiarTerminal();

    cout << "Ingrese el número de elementos a agregar a la cola: ";
    cin >> n;
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Entrada no válida. Por favor, ingrese un número.\n";
        limpiarTerminal();
        return 1;
    }
    // Agregar elementos a la cola
    for (int i = 0; i < n; ++i) {
        int elemento;
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> elemento;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada no válida. Por favor, ingrese un número.\n";
            limpiarTerminal();
            return 1;
        }
        cola.push(elemento);
    }
    // Mostrar la cola original, invertirla y mostrarla nuevamente
    cout << "Cola original:\n";
    mostrarCola(cola);
    cout << "Invirtiendo la cola...\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Cola invertida:\n";
    invertirCola(cola, pila);
    mostrarCola(cola);

    return 0;
}