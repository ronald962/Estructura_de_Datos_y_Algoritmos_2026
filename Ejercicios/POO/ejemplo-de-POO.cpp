#include <iostream>
#include <string>

using namespace std;

class carro{
    protected:
        string marca;
        string modelo;
        int año;
    public:
        carro(){};
        carro(string m, string mo, int a){
            this->marca = m;
            this->modelo = mo;
            this->año = a;
        }
        void mostrar(){
            cout << "Marca: " << marca << endl;
            cout << "Modelo: " << modelo << endl;
            cout << "Año: " << año << endl;
        }
        virtual void acelerar(){
            cout << "El carro está acelerando" << endl;
        }
        ~carro(){};
};

class camion : public carro{
    private:
        int capacidad;
    public:
        camion(){};
        camion(string m, string mo, int a, int c) : carro(m, mo, a){
            this->capacidad = c;
        }
        void mostrar(){
            carro::mostrar();
            cout << "Capacidad: " << capacidad << " toneladas" << endl;
        }
        void acelerar() override{
            cout << "El camión está acelerando" << endl;
        }
};

int main(){
    carro camioneta("Toyota", "Corolla", 2020);
    camion cammion("Volvo", "FH16", 2019, 20);

    camioneta.mostrar();
    camioneta.acelerar();

    cout << endl << "-----------------" << endl << endl;

    cammion.mostrar();
    cammion.acelerar();

    return 0;
}