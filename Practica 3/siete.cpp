#include <iostream>
#include <queue>
#include <string>
#include <thread>

using namespace std;

queue<string> filaBanco;
string nombreBanco;
int opcionBanco;

void limpiar(){
    #if _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){
    while (true)
    {
        limpiar();
        cout << "--- SIMULADOR DE BANCO ---\n";
        cout << "1- Agregar cliente\n2- Atender cliente\n3- Mostrar siguiente cliente\n" <<
        "4- Mostrar cantidad de clientes\n5- Salir\n";
        cout << "------------------------------\nOpcion: "; cin >> opcionBanco;
        
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        
        cin.ignore(1000, '\n');
        limpiar();
        
        switch (opcionBanco)
        {
        case 1:{
            cout << "Ingrese el nombre del cliente: "; 
            getline(cin, nombreBanco);
            filaBanco.push(nombreBanco);
            cout << "Cliente agregado a la fila del banco\n";
            cout << "Presione enter para continuar...\n";
            cin.get();
            break;
        }
        case 2:{
            if (filaBanco.empty()) {
                cout << "No hay clientes en la fila para atender\n";
                cout << "Presione enter para continuar...\n";
                cin.get();
                break;
            }

            cout << ">>> ATENDIENDO A: " << filaBanco.front() << " <<<\n";
            filaBanco.pop();
            
            cout << "\nPresione enter para continuar...\n";
            cin.get();
            break;
        }
        case 3:{
            if (filaBanco.empty()) {
                cout << "La fila esta vacia, no hay cliente... esperando...\n";
            } else {
                cout << "El siguiente cliente a ser atendido es: " << filaBanco.front() << "\n";
            }
            cout << "\nPresione enter para volver al menu...\n";
            cin.get();
            break;
        }
        case 4:{
            cout << "Cantidad de clientes actualmente en fila: " << filaBanco.size() << "\n";
            cout << "\nPresione enter para volver al menu...\n";
            cin.get();
            break;
        }
        case 5:{
            cout << "Cerrando el sistema del banco...";
            cin.get();
            break;
        }
        default:
            cout << "Opcion invalida, vuelve a intentarlo...\n";
            cin.get();
            break;
        }
        
        if(opcionBanco == 5){break;}
    }

    return 0;
}
