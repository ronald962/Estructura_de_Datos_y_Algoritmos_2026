#include <iostream>
#include <stack>
#include <string>

using namespace std;

string palabra;
stack<char> pila;

int main(){
    cout << "Ingrese una palabra: ";
    getline(cin, palabra);

    for(char letra : palabra){
        pila.push(letra);
    }

    cout << endl << "Palabra invertida: ";

    for (int i = pila.size(); i > 0; i--)
    {
        cout << pila.top();
        pila.pop();
    }

    return 0;
}