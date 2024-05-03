#include "funcion.h"
void mostrarMenu() {
    cout << "=== Menu de Creacion de red metro ===" << endl;
    cout << "1. Agregar estacion" << endl;
    cout << "2. Eliminar estacion" << endl;
    cout << "3. Cantidad de lineas en la red" << endl;
    cout << "4. Cantidad de estaciones en una linea" << endl;
    cout << "5. Ver si una estacion pertenece a una linea" << endl;
    cout << "6. Agregar una linea a la red" << endl;
    cout << "7. Eliminar una linea de la red" << endl;
    cout << "8. Ver cuantas estaciones tiene la red" << endl;
    cout << "9. Salir" << endl;
    cout << "Ingrese una opcion: ";
}
bool esNumeroValido(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Función para pedir al usuario un número válido
int pedirNumeroValido() {
    string entrada;
    cout << "Por favor, ingrese un numero valido mayor que cero: ";
    cin >> entrada;

    while (!esNumeroValido(entrada)) {
        cout << "Entrada invalida. Por favor, ingrese un numero valido mayor que cero: ";
        cin >> entrada;
    }

    // Convertir la entrada a entero y devolverlo
    return stoi(entrada);
}
