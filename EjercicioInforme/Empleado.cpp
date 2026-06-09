#include <iostream>
#include <string>

using namespace std;

class Empleado{
protected:
    string nombre;
    string cargo;
    int anios;

public:
    Empleado(string n, string c, int a){
        nombre = n;
        cargo = c;
        anios = a;
    }

    virtual double salario() = 0;

    string getNombre(){
        return nombre;
    }

    string getCargo(){
        return cargo;
    }

    int getAnios(){
        return anios;
    }
};

class EmpleadoPlanta : public Empleado{
public:
    EmpleadoPlanta(string n, string c, int a)
        : Empleado(n,c,a){}

    double salario(){

        if(cargo == "Gerente")
            return 100 * 40;

        if(cargo == "Supervisor")
            return 80 * 40;

        return 50 * 40;
    }
};

class EmpleadoHora : public Empleado{
private:
    int horas;

public:
    EmpleadoHora(string n, string c, int a, int h)
        : Empleado(n,c,a){

        horas = h;
    }

    double salario(){

        if(cargo == "Gerente")
            return 100 * horas;

        if(cargo == "Supervisor")
            return 80 * horas;

        return 50 * horas;
    }
};