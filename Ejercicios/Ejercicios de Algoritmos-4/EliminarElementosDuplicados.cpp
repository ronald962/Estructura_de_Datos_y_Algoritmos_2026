#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <chrono>
using namespace std;

vector<string> Elementos = {"CPU"};

void LimpiarTerminal(){
    #if _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    LimpiarTerminal();
    while (true)
    {
        int elemento;
        cout << "1- Ingresar elemento\n2- Mostrar elementos\n3- Eliminar elementos duplicados\n4- Salir\n";
        cin >> elemento;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada no válida. Por favor, ingrese un número.\n";
            this_thread::sleep_for(chrono::seconds(2));
            LimpiarTerminal();
            continue;
        }
        switch (elemento)
        {
        case 1:{
            LimpiarTerminal(); cout << "Ingrese el elemento a agregar: ";
            string elementO;cin >> elementO;Elementos.push_back(elementO);LimpiarTerminal();            
            break;
        }

        case 2:{
            LimpiarTerminal();
            cout << "Elementos:\n";
            for (auto &elem : Elementos) {
                cout << "- " << elem << "\n";
            }
            cout << endl;
            break;
        }

        case 3:{
            LimpiarTerminal();
            cout << "Eliminando elementos duplicados...\n";
            vector<string> ElementosUnicos;
            for (const auto& elem : Elementos) {
                if (find(ElementosUnicos.begin(), ElementosUnicos.end(), elem) == ElementosUnicos.end()) {
                    ElementosUnicos.push_back(elem);
                }
            }
            Elementos = ElementosUnicos;
            cout << "Elementos duplicados eliminados\n";
            this_thread::sleep_for(chrono::seconds(1));
            LimpiarTerminal();
            break;
        }

        case 4:{
            LimpiarTerminal();
            return 0;
        }

        default:
            cout << "Opción no válida\n";
            break;
        }   
    }
    return 0;
}