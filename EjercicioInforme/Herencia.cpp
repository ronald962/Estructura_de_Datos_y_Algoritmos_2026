#include "Empleado.cpp"
#include <fstream>

void mostrarSalarios(Empleado* emp[], int n){

    cout << "\n=== SALARIOS ===\n";

    for(int i=0; i<n; i++){

        cout << emp[i]->getNombre()
             << " - "
             << emp[i]->getCargo()
             << " -> $"
             << emp[i]->salario()
             << endl;
    }
}

void mayorSalario(Empleado* emp[], int n){

    int pos = 0;

    for(int i=1; i<n; i++){

        if(emp[i]->salario() > emp[pos]->salario())
            pos = i;
    }

    cout << "\n=== MAYOR SALARIO ===\n";

    cout << emp[pos]->getNombre()
         << " - $"
         << emp[pos]->salario()
         << endl;
}

void mayorTiempoEmpresa(Empleado* emp[], int n){

    int mayor = emp[0]->getAnios();

    for(int i=1; i<n; i++){

        if(emp[i]->getAnios() > mayor)
            mayor = emp[i]->getAnios();
    }

    cout << "\n=== MAYOR TIEMPO EN LA EMPRESA ===\n";

    for(int i=0; i<n; i++){

        if(emp[i]->getAnios() == mayor){

            cout << emp[i]->getNombre()
                 << " - "
                 << mayor
                 << " anios"
                 << endl;
        }
    }
}

void ordenarPorCargo(Empleado* emp[], int n){

    for(int i=0; i<n-1; i++){

        for(int j=i+1; j<n; j++){

            if(emp[i]->getCargo() > emp[j]->getCargo()){

                Empleado* aux = emp[i];
                emp[i] = emp[j];
                emp[j] = aux;
            }
        }
    }

    cout << "\n=== ORDENADOS POR CARGO ===\n";

    for(int i=0; i<n; i++){

        cout << emp[i]->getCargo()
             << " - "
             << emp[i]->getNombre()
             << endl;
    }
}

void guardarArchivo(Empleado* emp[], int n){

    ofstream archivo("empleados.txt");

    for(int i=0; i<n; i++){

        archivo
        << emp[i]->getNombre() << " "
        << emp[i]->getCargo() << " "
        << emp[i]->getAnios() << " "
        << emp[i]->salario()
        << endl;
    }

    archivo.close();

    cout << "\nDatos guardados en empleados.txt\n";
}