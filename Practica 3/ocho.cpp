#include <iostream>
#include <queue>
#include <string>
#include <thread>

using namespace std;

class Ticket {
private:
    string codigo;
    string cliente;
    int prioridad;

public:
    Ticket(string codigo, string cliente, int prioridad){
        this->codigo = codigo;
        this->cliente = cliente;
        this->prioridad = prioridad;
    }

    string getCodigo(){
        return codigo;
    }

    string getCliente(){
        return cliente;
    }

    int getPrioridad(){
        return prioridad;
    }
};

queue<Ticket> filaTickets;
int contadorTickets = 0;
int opcionSoporte;

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
        cout << "--- SIMULADOR DE SOPORTE TECNICO ---\n";
        cout << "1- Agregar ticket\n2- Atender ticket\n3- Mostrar siguiente ticket\n4- Mostrar cantidad de tickets\n5- Mostrar orden de atencion\n6- Salir\n";
        cout << "------------------------------\nOpcion: "; cin >> opcionSoporte;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        cin.ignore(1000, '\n');
        limpiar();

        switch (opcionSoporte)
        {
        case 1:{
            string cliente;
            int prioridad;

            cout << "Ingrese el nombre del cliente: ";
            getline(cin, cliente);

            cout << "Ingrese la prioridad (1 = Alta, 2 = Media, 3 = Baja): ";
            cin >> prioridad;

            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Prioridad invalida, ticket no agregado\n";
                cout << "Presione enter para continuar...\n";
                cin.get();
                break;
            }

            cin.ignore(1000, '\n');

            contadorTickets++;
            string codigo = "TK-" + to_string(contadorTickets);

            Ticket nuevoTicket(codigo, cliente, prioridad);
            filaTickets.push(nuevoTicket);

            cout << "Ticket " << codigo << " agregado a la fila de soporte\n";
            cout << "Presione enter para continuar...\n";
            cin.get();
            break;
        }
        case 2:{
            if (filaTickets.empty()) {
                cout << "No hay tickets en la fila para atender\n";
                cout << "Presione enter para continuar...\n";
                cin.get();
                break;
            }

            Ticket actual = filaTickets.front();

            cout << ">>> ATENDIENDO TICKET " << actual.getCodigo() << " <<<\n";
            cout << "Cliente: " << actual.getCliente() << "\n";
            cout << "Prioridad: " << actual.getPrioridad() << "\n";

            filaTickets.pop();

            cout << "\nPresione enter para continuar...\n";
            cin.get();
            break;
        }
        case 3:{
            if (filaTickets.empty()) {
                cout << "La fila esta vacia, no hay ticket... esperando...\n";
            } else {
                Ticket siguiente = filaTickets.front();
                cout << "El siguiente ticket a ser atendido es: " << siguiente.getCodigo() << " - " << siguiente.getCliente() << "\n";
            }
            cout << "\nPresione enter para volver al menu...\n";
            cin.get();
            break;
        }
        case 4:{
            cout << "Cantidad de tickets actualmente en fila: " << filaTickets.size() << "\n";
            cout << "\nPresione enter para volver al menu...\n";
            cin.get();
            break;
        }
        case 5:{
            if (filaTickets.empty()) {
                cout << "No hay tickets en la fila\n";
            } else {
                queue<Ticket> copiaFila = filaTickets;
                int orden = 1;

                cout << "Orden de atencion actual:\n";
                while (!copiaFila.empty())
                {
                    Ticket t = copiaFila.front();
                    cout << orden << ". " << t.getCodigo() << " - " << t.getCliente() << " (Prioridad: " << t.getPrioridad() << ")\n";
                    copiaFila.pop();
                    orden++;
                }
            }
            cout << "\nPresione enter para volver al menu...\n";
            cin.get();
            break;
        }
        case 6:{
            cout << "Cerrando el sistema de soporte...";
            cin.get();
            break;
        }
        default:
            cout << "Opcion invalida, vuelve a intentarlo...\n";
            cin.get();
            break;
        }

        if(opcionSoporte == 6){break;}
    }

    return 0;
}