#include <iostream>
#include <windows.h>

using namespace std;

HANDLE posicion = GetStdHandle(STD_OUTPUT_HANDLE);

void input();
double logic(double, double, int);

int main(){
    input(); return 0;
}

void input(){
    while(true){
        int eleccion = 0;
        double dato[2]={0, 0};
        system("cls");
        cout << "---CALCULADORA---" << endl;
        cout << "1- Suma\n2- Resta\n3- Multiplicacion\n4- Division\n5- Salir\nOpcion: "; cin >> eleccion;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Dato invalido...";
            Sleep(1000);
            continue;
        }
        if(eleccion != 5){
            system("cls");
            cout << "Primer dato:\nSegundo dato:\nResultado:";
            SetConsoleCursorPosition(posicion, {13, 0}); cin >> dato[0];
            SetConsoleCursorPosition(posicion, {14, 1}); cin >> dato[1];
            SetConsoleCursorPosition(posicion, {11, 2});
            if(eleccion == 4 && dato[1] == 0){
                cout << "Error"; Sleep(1000);
            }else{
                cout << logic(dato[0], dato[1], eleccion);
            }Sleep(1000);
        }else{break;}
    }
}

double logic(double dato1, double dato2, int operador){
    switch (operador)
    {
    case 1:{return dato1 + dato2;}
    case 2:{return dato1 - dato2;}
    case 3:{return dato1 * dato2;}
    case 4:{return dato1/dato2;}
    }
    return 0;
}