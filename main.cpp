#include <iostream>
#include "funcion.h"
using namespace std;
int Lineas=0;
int main() {
    int transferencia,posiciontransferencia,posicion,estacion,posicionestacion,n,linea=0;
    EstacionMatriz sistemametro=inicializarmatriz(n);
    int opcion = 0;
    while (opcion != 9) {
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
        cin >> opcion;
        cin.ignore();
        if (opcion == 1) {
            cout << "Has seleccionado agregar estacion" << endl;
            sistemametro.mostrarMatriz();
            cout<<"Ingrese la linea donde quiere crear la estacion: "<<endl;
            cin>>linea;
            cin.ignore();
            cout<<"Ingrese la posicion donde quiere crear la estacion: "<<endl;
            cin>>posicionestacion;
            cin.ignore();
            crearestacion(sistemametro,linea,posicionestacion);
        } else if (opcion == 2) {
            cout << "Has seleccionado eliminar estacion" << endl;
            sistemametro.mostrarMatriz();
            cout<<"ingrese la linea donde quiera borrar una estacion: "<<endl;
            cin>>estacion;
            cin.ignore();
            cout<<"ingrese la posicion de la estacion que quiera borrar: "<<endl;
            cin>>posicionestacion;
            cin.ignore();
            sistemametro.borrarEstacion(estacion,posicionestacion);
        } else if (opcion == 3) {
            cout << "Has seleccionado cantidad de lineas en la red" << endl;
            int cantidadlineas=sistemametro.cantidadLineas();
            cout<<"cantidad de lineas en la red: "<<cantidadlineas<<endl;
        } else if (opcion == 4) {
            cout << "Has seleccionado cantidad de estaciones en una linea" << endl;
            cout<<"ingrese la linea para saber sus estaciones: "<<endl;
            cin>>linea;
            cin.ignore();
            int cantidadcolumnas=sistemametro.cantidadColumnasEnFila(linea);
            cout<<"Hay "<<cantidadcolumnas<<" estaciones en la linea "<<linea<<endl;
        } else if (opcion == 5) {
            cout << "Has seleccionado ver si una estacion pertenece a una linea" << endl;
            cout<<"ingrese la linea para saber si pertenece: "<<endl;
            cin>>linea;
            cin.ignore();
            cout<<"ingrese el nombre de la estacion para saber si pertenece: "<<endl;
            string nombreaestacion;
            getline(cin, nombreaestacion);
            cin.ignore();
            if (sistemametro.estacionPerteneceALinea(nombreaestacion, linea)) {
                cout << "La estacion "<<nombreaestacion<<" pertenece a la linea "<<linea << endl;
            } else {
                cout << "La estacion "<<nombreaestacion<<" no pertenece a la linea " <<linea<< endl;
            }
        } else if (opcion == 6) {
            cout << "Has seleccionado agregar una linea a la red" << endl;
            if(Lineas==0){
                crearestacion(sistemametro,Lineas,0);
            }else if(Lineas!=0){
                  crearestacion(sistemametro,Lineas,0);
                sistemametro.mostrarMatriz();
                cout<<"ingrese la linea con la que quiere transferencia: "<<endl;
                cin>>transferencia;
                cin.ignore();
                cout<<"ingrese la posicion de la estacion donde quiere que sea de transferencia: "<<endl;
                cin>>posiciontransferencia;
                cin.ignore();
                sistemametro.copiarElemento(transferencia,Lineas,posiciontransferencia);

            }
            Lineas++;
        } else if (opcion == 7) {
            cout << "Has seleccionado eliminar una linea de la red" << endl;
        } else if (opcion == 8) {
            cout << "Has seleccionado ver cuantas estaciones tiene la red" << endl;
            int cantidaestaciones=sistemametro.cantidadEstacionesSinTransferencia();
            cout<<"La cantidad de estaciones que tiene la red es: "<<cantidaestaciones<<endl;
        } else if (opcion == 9) {
            cout << "Saliendo del programa..." << endl;
        } else {
            cout << "Opcion no valida. Por favor, ingrese una opcion valida del menu." << endl;

        }
    }

    return 0;
}
