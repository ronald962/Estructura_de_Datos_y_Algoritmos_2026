#include <iostream>
#include <vector>
#include <string>
#include <thread>

using namespace std;

class Estudiante {
private:
    string codigo;
    string nombre;
    int edad;
    string carrera;

public:
    Estudiante(string codigo, string nombre, int edad, string carrera){
        this->codigo = codigo;
        this->nombre = nombre;
        this->edad = edad;
        this->carrera = carrera;
    }

    string getCodigo(){
        return codigo;
    }

    string getNombre(){
        return nombre;
    }

    int getEdad(){
        return edad;
    }

    string getCarrera(){
        return carrera;
    }

    void mostrar(){
        cout << "Codigo: " << codigo << "\n";
        cout << "Nombre: " << nombre << "\n";
        cout << "Edad: " << edad << "\n";
        cout << "Carrera: " << carrera << "\n";
    }
};

vector<Estudiante> listaEstudiantes;
int opcionEstudiante;

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
        cout << "--- SISTEMA DE ESTUDIANTES ---\n";
        cout << "1- Registrar estudiante\n2- Mostrar todos los estudiantes\n3- Buscar estudiante por codigo\n4- Salir\n";
        cout << "------------------------------\nOpcion: "; cin >> opcionEstudiante;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        cin.ignore(1000, '\n');
        limpiar();

        switch (opcionEstudiante)
        {
        case 1:{
            string codigo, nombre, carrera;
            int edad;

            cout << "Ingrese el codigo del estudiante: ";
            getline(cin, codigo);

            cout << "Ingrese el nombre del estudiante: ";
            getline(cin, nombre);

            cout << "Ingrese la edad del estudiante: ";
            cin >> edad;

            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Edad invalida, estudiante no registrado\n";
                cout << "Presione enter para continuar...\n";
                cin.get();
                break;
            }

            cin.ignore(1000, '\n');

            cout << "Ingrese la carrera del estudiante: ";
            getline(cin, carrera);

            Estudiante nuevoEstudiante(codigo, nombre, edad, carrera);
            listaEstudiantes.push_back(nuevoEstudiante);

            cout << "Estudiante registrado\n";
            cout << "Presione enter para continuar...\n";
            cin.get();
            break;
        }
        case 2:{
            if (listaEstudiantes.empty()) {
                cout << "No hay estudiantes registrados\n";
            } else {
                cout << "--- LISTA DE ESTUDIANTES ---\n";
                for (int i = 0; i < listaEstudiantes.size(); i++)
                {
                    cout << "\n[" << i + 1 << "]\n";
                    listaEstudiantes[i].mostrar();
                }
            }
            cout << "\nPresione enter para volver al menu...\n";
            cin.get();
            break;
        }
        case 3:{
            if (listaEstudiantes.empty()) {
                cout << "No hay estudiantes registrados\n";
                cout << "\nPresione enter para volver al menu...\n";
                cin.get();
                break;
            }

            string codigoBuscado;
            cout << "Ingrese el codigo a buscar: ";
            getline(cin, codigoBuscado);

            bool encontrado = false;
            for (int i = 0; i < listaEstudiantes.size(); i++)
            {
                if (listaEstudiantes[i].getCodigo() == codigoBuscado) {
                    cout << "\nEstudiante encontrado:\n";
                    listaEstudiantes[i].mostrar();
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado) {
                cout << "No se encontro ningun estudiante con ese codigo\n";
            }

            cout << "\nPresione enter para volver al menu...\n";
            cin.get();
            break;
        }
        case 4:{
            cout << "Cerrando el sistema de estudiantes...";
            cin.get();
            break;
        }
        default:
            cout << "Opcion invalida, vuelve a intentarlo...\n";
            cin.get();
            break;
        }

        if(opcionEstudiante == 4){break;}
    }

    return 0;
}