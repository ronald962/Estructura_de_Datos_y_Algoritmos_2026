#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
int eleccion = 0;
double dato[2] = {0, 0}, resultado = 0;

int main(){
    HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
    while(true)
    {
        system("cls");
        cout << "---calculadora---" << endl;
        cout << "1- Suma\n2- Resta\n3- Multiplicacion\n4- Division\n5- Salir" << endl;
        cout << "Eleccion: ";
        cin >> eleccion;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "No es una eleccion..";
            Sleep(2000);
            continue;
        }
        switch (eleccion)
        {
        case 1:{
            system("cls");
            cout << "Primer dato:\nSegundo dato:\nRespuesta:";
            SetConsoleCursorPosition(a, {13, 0});
            cin >> dato[0];
            SetConsoleCursorPosition(a, {14, 1});
            cin >> dato[1];
            SetConsoleCursorPosition(a, {11, 2});
            resultado = dato[0] + dato[1];
            cout << resultado << endl;
            Sleep(2000);
            break;
        }
        case 2:{
            system("cls");
            cout << "Primer dato:\nSegundo dato:\nRespuesta:";
            SetConsoleCursorPosition(a, {13, 0});
            cin >> dato[0];
            SetConsoleCursorPosition(a, {14, 1});
            cin >> dato[1];
            SetConsoleCursorPosition(a, {11, 2});
            resultado = dato[0] - dato[1];
            cout << resultado << endl;
            Sleep(2000);
            break;
        }
        case 3:{
            system("cls");
            cout << "Primer dato:\nSegundo dato:\nRespuesta:";
            SetConsoleCursorPosition(a, {13, 0});
            cin >> dato[0];
            SetConsoleCursorPosition(a, {14, 1});
            cin >> dato[1];
            SetConsoleCursorPosition(a, {11, 2});
            resultado = dato[0] * dato[1];
            cout << resultado << endl;
            Sleep(2000);
            break;
        }
        case 4:{
            system("cls");
            cout << "Primer dato:\nSegundo dato:\nRespuesta:";
            SetConsoleCursorPosition(a, {13, 0});
            cin >> dato[0];
            SetConsoleCursorPosition(a, {14, 1});
            cin >> dato[1];
            SetConsoleCursorPosition(a, {11, 2});
            if(dato[1] != 0){
            resultado = dato[0] / dato[1];
            cout << resultado << endl;
            }else{
                system("cls");
                cout << "no se puede calcular...";
            }
            Sleep(2000);
            break;
        }
        case 5:{
            system("cls");
            cout << "Saliendo...";
            Sleep(1000);
            break;
        }
        default:
            system("cls");
            cout << "no seleccionaste ningun resultado...";
            Sleep(1000);
            break;
        }
        if(eleccion == 5){
            break;
        }
    }

    return 0;
}