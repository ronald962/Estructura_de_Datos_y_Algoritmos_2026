#include <iostream>
#include <queue>
#include <string>
#include <thread>

using namespace std;

queue<string> filaClientes;
string nombreCliente;
int opcionMenu;

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
        cout << "1- Registrar cliente\n2- Atender cliente\n3- Mostrar clientes pendientes\n4- Salir\n";
        cout << "------------------------------\nOpcion: "; cin >> opcionMenu;
        
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        
        cin.ignore(1000, '\n');
        limpiar();
        
        switch (opcionMenu)
        {
        case 1:{
            cout << "Ingrese nombre del cliente: "; 
            getline(cin, nombreCliente);
            filaClientes.push(nombreCliente);
            cout << "Cliente registrado con exito\n";
            cout << "Presione enter para continuar...\n";
            cin.get();
            break;
        }
        case 2:{
            if (filaClientes.empty()) {
                cout << "No hay clientes en la cola para atender\n";
                cout << "Presione enter para continuar...\n";
                cin.get();
                break;
            }

            cout << ">>> CLIENTE ATENDIDO: " << filaClientes.front() << " <<<\n";
            filaClientes.pop();
            
            cout << "\nPresione enter para continuar...\n";
            cin.get();
            break;
        }
        case 3:{
            if (filaClientes.empty()) {
                cout << "La cola esta vacia, no hay clientes pendientes\n";
            } else {
                cout << "--- CLIENTES PENDIENTES EN FILA ---\n";
                cout << "Total en espera: " << filaClientes.size() << "\n\n";
                
                queue<string> Temporal = filaClientes;
                int contador = 1;
                
                while (!Temporal.empty()) {
                    cout << contador << "- " << Temporal.front() << "\n";
                    Temporal.pop();
                    contador++;
                }
            }
            cout << "\nPresione enter para volver al menu...\n";
            cin.get();
            break;
        }
        case 4:{
            cout << "Saliendo del sistema...";
            cin.get();
            break;
        }
        default:
            cout << "Opcion invalida, vuelve a intentarlo...\n";
            cin.get();
            break;
        }
        
        if(opcionMenu == 4){break;}
    }

    return 0;
}
