#include "Herencia.cpp"
#include <string>
#include <iostream>
#include <thread>

string EmPlanta[5][2];
string EmHora[5][2];
Empleado* empleados[10];

void limpiar(){
    #if _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void generarEmpleados();

int main(){

    generarEmpleados();

    empleados[0] = new EmpleadoPlanta(EmPlanta[0][0],EmPlanta[0][1],10);
    empleados[1] = new EmpleadoPlanta(EmPlanta[1][0],EmPlanta[1][1],8);
    empleados[2] = new EmpleadoPlanta(EmPlanta[2][0],EmPlanta[2][1],5);
    empleados[3] = new EmpleadoPlanta(EmPlanta[3][0],EmPlanta[3][1],12);
    empleados[4] = new EmpleadoPlanta(EmPlanta[4][0],EmPlanta[4][1],7);

    empleados[5] = new EmpleadoHora(EmHora[0][0],EmHora[0][1],4,30);
    empleados[6] = new EmpleadoHora(EmHora[1][0],EmHora[1][1],3,25);
    empleados[7] = new EmpleadoHora(EmHora[2][0],EmHora[2][1],6,35);
    empleados[8] = new EmpleadoHora(EmHora[3][0],EmHora[3][1],9,20);
    empleados[9] = new EmpleadoHora(EmHora[4][0],EmHora[4][1],15,40);

    mostrarSalarios(empleados,10);

    mayorSalario(empleados,10);

    mayorTiempoEmpresa(empleados,10);

    ordenarPorCargo(empleados,10);

    guardarArchivo(empleados,10);

    for(int i=0; i<10; i++){
        delete empleados[i];
    }

    return 0;
}

void generarEmpleados(){
    for (int i = 0; i < 5; i++)
    {
        limpiar();
        cout << "=====Generando Empleados - Por Planta=====" << endl;
        cout << "Nombre: ";
        cin >> EmPlanta[i][0];
        cout << "Puesto(Gerente, Supervisor, Operador): ";
        cin >> EmPlanta[i][1];
    }

    for (int i = 0; i < 5; i++)
    {
        limpiar();
        cout << "=====Generando Empleados - Por Hora=====" << endl;
        cout << "Nombre: ";
        cin >> EmHora[i][0];
        cout << "Puesto(Gerente, Supervisor, Operador): ";
        cin >> EmHora[i][1];
    }
}