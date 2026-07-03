#include <iostream>
#include <stack>

using namespace std;

stack<double> Pila;
double num = 0;

int main(){
    while (true)
    {
        cout << "Ingrese numeros a la pila(ingresar '-1' para parar): "; cin >> num;
        if(num == -1){break;}
        Pila.push(num);
    }
    cout << endl << "\nTamaño de pila: " << Pila.size() << "\nUltimo elemento de pila: " << Pila.top();

    return 0;
}