#include <iostream>
#include <stack>
#include <string>
#include <thread>

using namespace std;

stack<string> historial;
string URL;
int opcion;

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
        cout << "1- Visitar pagina\n2- Retroceder\n3- Mostrar pagina actual\n4- Salir\n";
        cout << "------------------------------\nOpcion: ";cin >> opcion;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore(1000, '\n');
        limpiar();
        switch (opcion)
        {
        case 1:{
            cout << "Coloque URL de la pagina: "; getline(cin, URL);
            historial.push(URL);
            break;
        }
        case 2:{
            if (historial.empty()) {
                cout << "El historial esta vacio, no puedes retroceder.\n";
                cout << "Presione enter para continuar...\n";
                cin.get();
                break;
            }

            int opc;
            cout << "Deseas retroceder a la pagina anterior?\n1- Si\n2- No\nOpcion: "; cin >> opc;
            if(cin.fail()){cin.clear();cin.ignore(1000, '\n');}
            cin.ignore(1000, '\n');
            if(1 == opc){
                historial.pop();
                cout << "Retrocedio 1 pagina, presione enter para continuar...\n";
                cin.get();
            }else if (2 == opc)
            {
                cout << "No retrocedio, presione enter para continuar...\n";
                cin.get();
            }else{
                cout << "Ninguna opcion es valida, presione enter para continuar....\n";
                cin.get();
            }
            break;
        }
        case 3:{
            if (!historial.empty()) {
                cout << "Pagina actual: " << historial.top();
            } else {
                cout << "No hay paginas en el historial";
            }
            cout << "\nPresione enter para volver...\n";
            cin.get();
            break;
        }
        case 4:{
            cout << "Saliendo...";
            cin.get();
            break;
        }
        default:
            cout << "Opcion invalida, vuelve a intentarlo...\n";
            cin.get();
            break;
        }
        if(opcion == 4){break;}
    }

    return 0;
}