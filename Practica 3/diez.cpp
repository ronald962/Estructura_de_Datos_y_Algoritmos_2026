#include <iostream>
#include <vector>
#include <string>
#include <thread>

using namespace std;

class Contacto {
private:
    string nombre;
    string telefono;
    string correo;

public:
    Contacto(string nombre, string telefono, string correo){
        this->nombre = nombre;
        this->telefono = telefono;
        this->correo = correo;
    }

    string getNombre(){
        return nombre;
    }

    string getTelefono(){
        return telefono;
    }

    string getCorreo(){
        return correo;
    }

    void mostrar(){
        cout << "Nombre: " << nombre << "\n";
        cout << "Telefono: " << telefono << "\n";
        cout << "Correo: " << correo << "\n";
    }
};

vector<Contacto> listaContactos;
int opcionContacto;

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
        cout << "--- AGENDA DE CONTACTOS ---\n";
        cout << "1- Agregar contacto\n2- Buscar por nombre\n3- Eliminar contacto\n4- Mostrar todos los contactos\n5- Salir\n";
        cout << "------------------------------\nOpcion: "; cin >> opcionContacto;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        cin.ignore(1000, '\n');
        limpiar();

        switch (opcionContacto)
        {
        case 1:{
            string nombre, telefono, correo;

            cout << "Ingrese el nombre del contacto: ";
            getline(cin, nombre);

            cout << "Ingrese el telefono del contacto: ";
            getline(cin, telefono);

            cout << "Ingrese el correo del contacto: ";
            getline(cin, correo);

            Contacto nuevoContacto(nombre, telefono, correo);
            listaContactos.push_back(nuevoContacto);

            cout << "Contacto agregado con exito\n";
            cout << "Presione enter para continuar...\n";
            cin.get();
            break;
        }
        case 2:{
            if (listaContactos.empty()) {
                cout << "No hay contactos registrados\n";
                cout << "\nPresione enter para volver al menu...\n";
                cin.get();
                break;
            }

            string nombreBuscado;
            cout << "Ingrese el nombre a buscar: ";
            getline(cin, nombreBuscado);

            bool encontrado = false;
            for (int i = 0; i < listaContactos.size(); i++)
            {
                if (listaContactos[i].getNombre() == nombreBuscado) {
                    cout << "\nContacto encontrado:\n";
                    listaContactos[i].mostrar();
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado) {
                cout << "No se encontro ningun contacto con ese nombre\n";
            }

            cout << "\nPresione enter para volver al menu...\n";
            cin.get();
            break;
        }
        case 3:{
            if (listaContactos.empty()) {
                cout << "No hay contactos registrados\n";
                cout << "\nPresione enter para volver al menu...\n";
                cin.get();
                break;
            }

            string nombreEliminar;
            cout << "Ingrese el nombre del contacto a eliminar: ";
            getline(cin, nombreEliminar);

            bool encontrado = false;
            for (int i = 0; i < listaContactos.size(); i++)
            {
                if (listaContactos[i].getNombre() == nombreEliminar) {
                    listaContactos.erase(listaContactos.begin() + i);
                    cout << "Contacto eliminado con exito\n";
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado) {
                cout << "No se encontro ningun contacto con ese nombre\n";
            }

            cout << "\nPresione enter para volver al menu...\n";
            cin.get();
            break;
        }
        case 4:{
            if (listaContactos.empty()) {
                cout << "No hay contactos registrados\n";
            } else {
                cout << "--- LISTA DE CONTACTOS ---\n";
                for (int i = 0; i < listaContactos.size(); i++)
                {
                    cout << "\n[" << i + 1 << "]\n";
                    listaContactos[i].mostrar();
                }
            }
            cout << "\nPresione enter para volver al menu...\n";
            cin.get();
            break;
        }
        case 5:{
            cout << "Cerrando la agenda de contactos...";
            cin.get();
            break;
        }
        default:
            cout << "Opcion invalida, vuelve a intentarlo...\n";
            cin.get();
            break;
        }

        if(opcionContacto == 5){break;}
    }

    return 0;
}