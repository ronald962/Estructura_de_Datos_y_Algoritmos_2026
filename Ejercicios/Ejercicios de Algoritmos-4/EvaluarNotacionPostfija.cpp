#include <iostream>
#include <stack>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;
 
stack<double> pila;

// Función para limpiar la terminal
void limpiarTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Función para pausar la ejecución por un número de segundos (default: 2)
void pausar(int seg = 2) {
    this_thread::sleep_for(chrono::seconds(seg));
}

// Funciones para verificar si un token es operador o número
bool esOperador(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// Verifica si el token es un número (entero o decimal)
bool esNumero(const string& token) {
    if (token.empty()) return false;
    size_t inicio = (token[0] == '-') ? 1 : 0;
    if (inicio == token.size()) return false;
    bool tienePunto = false;
    for (size_t i = inicio; i < token.size(); i++) {
        if (token[i] == '.') {
            if (tienePunto) return false;
            tienePunto = true;
        } else if (!isdigit(token[i])) {
            return false;
        }
    }
    return true;
}

// Función para aplicar la operación a dos operandos
double aplicarOperacion(double a, double b, const string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    return 0;
}
 
int main() {
    limpiarTerminal();
    //ejemplo de etrada: 3 4 + 2 * 7 -
    //el algoritmo hace: (3 + 4) * 2 - 7 = 7 * 2 - 7 = 14 - 7 = 7
    while(true) {
        cout << "Ingrese una expresión en notación postfija (o 'salir' para terminar): ";
        string input;
        getline(cin, input);
        // Si el usuario ingresa "salir", se termina el programa
        if (input == "salir") break;
 
        // Dividir la entrada en tokens
        vector<string> tokens;
        size_t pos = 0;

        // Dividir la entrada en tokens usando el espacio como delimitador
        while ((pos = input.find(' ')) != string::npos) {
            tokens.push_back(input.substr(0, pos));
            input.erase(0, pos + 1);
        }
        // Agregar el último token si no está vacío
        if (!input.empty()) tokens.push_back(input);
 
        bool error = false;
 
        // Procesar cada token
        for (const string& token : tokens) {
            if (esNumero(token)) {
                pila.push(stod(token));
            } else if (esOperador(token)) {
                if (pila.size() < 2) {
                    cout << "Error: No hay suficientes operandos para el operador '" << token << "'.\n";
                    error = true;
                    break;
                }
                double b = pila.top(); pila.pop();
                double a = pila.top(); pila.pop();
                double resultado = aplicarOperacion(a, b, token);
                pila.push(resultado);
            } else {
                cout << "Error: Token no reconocido '" << token << "'.\n";
                error = true;
                break;
            }
        }
        // Si no hubo errores, el resultado final debería ser el único elemento en la pila
        if (!error) {
            if (pila.size() == 1) {
                cout << "Resultado: " << pila.top() << "\n";
            } else {
                cout << "Error: La expresión no es válida. Quedan operandos sin usar.\n";
            }
        }
 
        // Limpiar la pila para la siguiente expresión
        while (!pila.empty()) pila.pop();
 
        pausar();
        limpiarTerminal();
    }
 
    return 0;
}
