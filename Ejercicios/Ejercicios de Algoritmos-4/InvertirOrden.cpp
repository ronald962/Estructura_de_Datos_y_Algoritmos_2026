#include <iostream>
using namespace std;

// Invertir lista

int lista[6] = {1, 2, 3, 4, 5, 6};

// Función para invertir la lista

void invertirLista(int listaParametro[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = listaParametro[i];
        listaParametro[i] = listaParametro[size - 1 - i];
        listaParametro[size - 1 - i] = temp;
    }
}

int main() {
    // Imprimir la lista original

    cout << "Lista original: ";
    for (int i = 0; i < 6; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;

    // Llamar a la función para invertir la lista

    invertirLista(lista, sizeof(lista) / sizeof(lista[0]));

    // Imprimir la lista invertida

    cout << "Lista invertida: ";
    for (int i = 0; i < 6; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;

    return 0;
}