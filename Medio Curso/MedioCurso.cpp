#include <iostream>
#include <string>
#include <vector>
#include <windows.h> // Para system("cls") y Sleep()
using namespace std;

// Descuentos fijos definidos
const double AFP = 800.0;
const double SEGURO = 120.0;

// Beneficios fijos definidos
const double MANUTENCION = 1000.0;
const double BONO = 200.0;
const double TARIFA = 120.0; // Pago por hora

// Datos globales del empleado
string NombreEmpleado = "";
double Horas = 0;

// Opciones de sí o no (encendido/apagado)
bool AplicarAFP = false;
bool AplicarSeguro = false;
bool AplicarManutencion = false;
bool AplicarBono = false;

// Prototipos de funciones
void LimpiarMemoria();
void GestionDeTrabajadores();
void IngresarHoras();
void MostrarElSalario();
void IngresarDescuento();
void IngresarBeneficios();
void ImprimirBoleta();

int main() {
    system("cls"); // Limpia la consola
    cout << "---------------------------------------" << endl;
    cout << "          SILLICON VALLEY - EMPLEADO    " << endl;
    cout << "---------------------------------------" << endl;
    cout << "Nombre del trabajador: ";
    cin.ignore();                       // Limpia el buffer antes de leer
    getline(cin, NombreEmpleado);       // Lee el nombre con espacios

    GestionDeTrabajadores(); // Llama al menú principal
    return 0;
}

// Resetea el texto si hay un error (ej. letra en vez de número)
void LimpiarMemoria() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

// Bucle del menú principal
void GestionDeTrabajadores() {
    while (true) {
        system("cls");
        cout << "TRABAJADOR: " << NombreEmpleado << endl;
        cout << "---------------------------------------" << endl;
        cout << "1- Ingresar Horas Trabajadas" << endl;
        cout << "2- Mostrar Salario" << endl;
        cout << "3- Ingresar Descuento" << endl;
        cout << "4- Ingresar Beneficios" << endl;
        cout << "5- Imprimir Boleta" << endl;
        cout << "6- Salir" << endl;
        cout << "---------------------------------------" << endl;
        cout << "OPCION: ";
        int ops;
        cin >> ops;
        LimpiarMemoria();

        // Ejecuta la función según la opción elegida
        switch (ops) {
            case 1: IngresarHoras(); break;
            case 2: MostrarElSalario(); break;
            case 3: IngresarDescuento(); break;
            case 4: IngresarBeneficios(); break;
            case 5: ImprimirBoleta(); break;
            case 6: cout << "Saliendo..."; Sleep(2000); break;      // Pausa antes de salir
            default: cout << "Fuera de rango..."; Sleep(1000); break; // Opción inválida
        }

        if (ops == 6) { break; } // Rompe el bucle y sale
    }
}

// Registro de horas de trabajo
void IngresarHoras() {
    system("cls");
    cout << "---------------------------------------" << endl;
    cout << "INGRESAR HORAS TRABAJADAS" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Tarifa por hora: " << TARIFA << " $" << endl;
    cout << "Horas actuales : " << Horas << " h" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Nuevas horas : ";
    double h;
    cin >> h;
    LimpiarMemoria();

    // Validación para evitar horas negativas
    if (h < 0) {
        cout << "Las horas no pueden ser negativas.";
        Sleep(2000);
    } else {
        Horas = h; // Actualiza las horas
        cout << "Horas registradas correctamente.";
        Sleep(1500);
    }
}

// Calcula y muestra el sueldo en tiempo real
void MostrarElSalario() {
    system("cls");

    // Fórmulas matemáticas
    double bruto = Horas * TARIFA;
    double totalDesc = (AplicarAFP ? AFP : 0) + (AplicarSeguro ? SEGURO : 0);
    double totalBen  = (AplicarManutencion ? MANUTENCION : 0) + (AplicarBono ? BONO : 0);
    double neto = bruto - totalDesc + totalBen;

    cout << "---------------------------------------" << endl;
    cout << "SALARIO DEL EMPLEADO" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Horas trabajadas : " << Horas << " h" << endl;
    cout << "Tarifa / hora    : " << TARIFA << " $" << endl;
    cout << "Salario base     : " << bruto << " $" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Descuentos aplicados:" << endl;

    // Muestra el monto o dice "no aplicado"
    cout << " - AFP     : " << (AplicarAFP ? to_string((int)AFP) + " $" : "no aplicado") << endl;
    cout << " - Seguro  : " << (AplicarSeguro ? to_string((int)SEGURO) + " $" : "no aplicado") << endl;

    cout << "Beneficios aplicados:" << endl;
    cout << " - Manutencion : " << (AplicarManutencion ? to_string((int)MANUTENCION) + " $" : "no aplicado") << endl;
    cout << " - Bono        : " << (AplicarBono ? to_string((int)BONO) + " $" : "no aplicado") << endl;
    cout << "---------------------------------------" << endl;
    cout << "SUELDO NETO FINAL: " << neto << " $" << endl;
    cout << "---------------------------------------" << endl;

    cout << "\nPresiona ENTER para continuar...";
    cin.ignore();
    cin.get(); // Espera a que el usuario presione Enter
}

// Menú para encender o apagar descuentos
void IngresarDescuento() {
    system("cls");
    cout << "---------------------------------------" << endl;
    cout << "INGRESAR DESCUENTO" << endl;
    cout << "---------------------------------------" << endl;
    cout << "1- AFP    : 800 $ [" << (AplicarAFP ? "ACTIVO" : "inactivo") << "]" << endl;
    cout << "2- Seguro : 120 $ [" << (AplicarSeguro ? "ACTIVO" : "inactivo") << "]" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Selecciona opcion a activar/desactivar: ";
    int op;
    cin >> op;
    LimpiarMemoria();

    // Prende o apaga la opción elegida
    if (op == 1) {
        AplicarAFP = !AplicarAFP;
        cout << "AFP " << (AplicarAFP ? "activado." : "desactivado.");
        Sleep(1500);
    } else if (op == 2) {
        AplicarSeguro = !AplicarSeguro;
        cout << "Seguro " << (AplicarSeguro ? "activado." : "desactivado.");
        Sleep(1500);
    } else {
        cout << "Opcion invalida.";
        Sleep(1500);
    }
}

// Menú para encender o apagar beneficios
void IngresarBeneficios() {
    system("cls");
    cout << "---------------------------------------" << endl;
    cout << "INGRESAR BENEFICIO" << endl;
    cout << "---------------------------------------" << endl;
    cout << "1- Manutencion : 1000 $ [" << (AplicarManutencion ? "ACTIVO" : "inactivo") << "]" << endl;
    cout << "2- Bono        : 200 $ ["  << (AplicarBono ? "ACTIVO" : "inactivo") << "]" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Selecciona opcion a activar/desactivar: ";
    int op;
    cin >> op;
    LimpiarMemoria();

    // Prende o apaga la opción elegida
    if (op == 1) {
        AplicarManutencion = !AplicarManutencion;
        cout << "Manutencion " << (AplicarManutencion ? "activada." : "desactivada.");
        Sleep(1500);
    } else if (op == 2) {
        AplicarBono = !AplicarBono;
        cout << "Bono " << (AplicarBono ? "activado." : "desactivado.");
        Sleep(1500);
    } else {
        cout << "Opcion invalida.";
        Sleep(1500);
    }
}

// Imprime el resumen final formateado
void ImprimirBoleta() {
    system("cls");

    // Repite cálculos para el resumen
    double bruto = Horas * TARIFA;
    double totalDesc = (AplicarAFP ? AFP : 0) + (AplicarSeguro ? SEGURO : 0);
    double totalBen  = (AplicarManutencion ? MANUTENCION : 0) + (AplicarBono ? BONO : 0);
    double neto = bruto - totalDesc + totalBen;

    cout << "---------------------------------------" << endl;
    cout << "              BOLETA DE PAGO            " << endl;
    cout << "=======================================" << endl;
    cout << "Trabajador: " << NombreEmpleado << endl;
    cout << "---------------------------------------" << endl;
    cout << "Salario Base: " << bruto << " $" << endl;
    cout << "---------------------------------------" << endl;

    // Imprime los descuentos solo si están activados
    cout << "Descuentos aplicados:" << endl;
    if (!AplicarAFP && !AplicarSeguro) {
        cout << " (ninguno)" << endl;
    } else {
        if (AplicarAFP) cout << " - AFP: " << AFP << " $" << endl;
        if (AplicarSeguro) cout << " - Seguro: " << SEGURO << " $" << endl;
    }
    cout << endl;

    // Imprime los beneficios solo si están activados
    cout << "Beneficios aplicados:" << endl;
    if (!AplicarManutencion && !AplicarBono) {
        cout << " (ninguno)" << endl;
    } else {
        if (AplicarManutencion) cout << " - Manutencion: " << MANUTENCION << " $" << endl;
        if (AplicarBono) cout << " - Bono: " << BONO << " $" << endl;
    }

    cout << "---------------------------------------" << endl;
    cout << "SUELDO FINAL: " << neto << " $" << endl;
    cout << "=======================================" << endl;

    cout << "\nPresiona ENTER para continuar...";
    cin.ignore();
    cin.get(); // Pausa final antes de volver al menú
}