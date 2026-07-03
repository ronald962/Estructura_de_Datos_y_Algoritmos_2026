#include <iostream>
#include <stack>
#include <string>

using namespace std;

string palabra = "", palabraInvertida = "";
stack<char> pila;

int main(){
    cout << "Ingresar palabra: ";
    getline(cin, palabra);

    for (char letra : palabra)
    {
        pila.push(letra);
    }
    
    int limite = pila.size();
    for(int i = limite; i > 0; i--){
        palabraInvertida += pila.top();
        pila.pop();
    }

    if(palabra == palabraInvertida){
        cout << "Es un palindromo" << endl;
    }else{
        cout << "No es palidromo" << endl;
    }
    return 0;
}