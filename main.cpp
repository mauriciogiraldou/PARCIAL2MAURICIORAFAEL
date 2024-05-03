#include <iostream>
#include "linea.h"
#include "redmetro.h"
#include "funcion.h"
using namespace std;
int main() {
    int opcion;
    int crearred;
    cout << "Cuantas lineas quiere en la red? ";
    crearred = pedirNumeroValido();
    RedMetro redMetro(crearred,1);
    bool salir = false;
    while (!salir) {
        mostrarMenu();
        opcion=pedirNumeroValido();
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Logica para agregar estacion
            cout << "Agregar estacion" << endl;
            break;
        case 2:
            // Logica para eliminar estacion
            cout << "Eliminar estacion" << endl;
            break;
        case 3:
            // Logica para cantidad de lineas en la red
            cout << "Cantidad de lineas en la red" << endl;
            break;
        case 4:
            // Logica para cantidad de estaciones en una linea
            cout << "Cantidad de estaciones en una linea" << endl;
            break;
        case 5:
            // Logica para verificar si una estacion pertenece a una linea
            cout << "Ver si una estacion pertenece a una linea" << endl;
            break;
        case 6:
            // Logica para agregar una linea a la red
            cout << "Agregar una linea a la red" << endl;
            break;
        case 7:
            // Logica para eliminar una linea de la red
            cout << "Eliminar una linea de la red" << endl;
            break;
        case 8:
            // Logica para ver cuantas estaciones tiene la red
            cout << "Ver cuantas estaciones tiene la red" << endl;
            break;
        case 9:
            // Salir del programa
            salir = true;
            break;
        default:
            cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
        }
    }

    cout << "Saliendo del programa..." << endl;
    return 0;
}
