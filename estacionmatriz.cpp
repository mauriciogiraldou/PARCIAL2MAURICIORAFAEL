#include "estacionmatriz.h"
#include <iostream>
#include <algorithm>
using namespace std;
EstacionMatriz::EstacionMatriz(int filas, int columnas) : filas(filas), columnas(columnas) {
    matriz = new Estacion**[filas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new Estacion*[columnas];
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = nullptr;
        }
    }
}

EstacionMatriz::~EstacionMatriz() {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            delete matriz[i][j];
        }
        delete[] matriz[i];
    }
    delete[] matriz;
}

Estacion* EstacionMatriz::getEstacion(int fila, int columna) const {
    return matriz[fila][columna];
}

void EstacionMatriz::setEstacion(int fila, int columna, Estacion* estacion) {
    // Verificar si la posición está dentro de los límites de la matriz
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        // Verificar si ya hay un objeto en la posición especificada
        if (matriz[fila][columna] != nullptr) {
            // Si ya hay una estación en esta posición, mostrar un mensaje de error
            cout << "Ya hay una estacion en esta posicion. No se puede agregar una nueva estacion aqui." << endl;
        } else {
            // Asignar la nueva estación a la posición especificada
            matriz[fila][columna] = estacion;
        }
    } else {
        // Redimensionar solo las columnas de la matriz para tener espacio adicional y asignar la nueva estación
        cout << "Posicion fuera de los limites de la matriz. Redimensionando las columnas de la matriz..." << endl;
        redimensionar(filas, max(columna + 1, columnas));
        matriz[fila][columna] = estacion;
    }
}

void EstacionMatriz::redimensionar(int nuevaFilas, int nuevasColumnas) {
    Estacion*** nuevaMatriz = new Estacion**[nuevaFilas];
    for (int i = 0; i < nuevaFilas; ++i) {
        nuevaMatriz[i] = new Estacion*[nuevasColumnas]; // Utilizar nuevasColumnas en lugar de columnas
        for (int j = 0; j < nuevasColumnas; ++j) { // Utilizar nuevasColumnas
            nuevaMatriz[i][j] = nullptr;
        }
    }

    // Copiar las estaciones de la matriz anterior a la nueva matriz
    int filasCopiadas = min(nuevaFilas, filas);
    int columnasCopiadas = min(nuevasColumnas, columnas); // Utilizar nuevasColumnas
    for (int i = 0; i < filasCopiadas; ++i) {
        for (int j = 0; j < columnasCopiadas; ++j) { // Utilizar columnasCopiadas
            nuevaMatriz[i][j] = matriz[i][j];
        }
    }

    // Liberar memoria de la matriz anterior
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    // Actualizar la matriz con la nueva matriz
    matriz = nuevaMatriz;
    filas = nuevaFilas;
    columnas = nuevasColumnas; // Actualizar el número de columnas
}

void EstacionMatriz::borrarEstacion(int fila, int columna) {
    // Verificar si la posición está dentro de los límites de la matriz
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        // Verificar si la estación en esa posición tiene un '+'
        if (matriz[fila][columna] != nullptr && matriz[fila][columna]->getNombre().find("+") == string::npos) {
            // Si no tiene un '+', liberar memoria de la estación en esa posición
            delete matriz[fila][columna];
            matriz[fila][columna] = nullptr;
            cout << "Estacion borrada en la posicion [" << fila << ", " << columna << "]" << endl;
        } else {
            cout << "No se puede borrar la estacion en la posicion [" << fila << ", " << columna << "]" <<"porque es una estacion de transferencia. " <<endl;
        }
    } else {
        cout << "Posicion fuera de los limites de la matriz" << endl;
    }
}
int EstacionMatriz::cantidadLineas() const {
    return filas;
}
int EstacionMatriz::cantidadColumnasEnFila(int fila) const {
    if (fila >= 0 && fila < filas) {
        int contadorColumnas = 0; // Inicializar el contador de columnas
        for (int j = 0; j < columnas; ++j) {
            if (matriz[fila][j] != nullptr) {
                contadorColumnas++; // Incrementar el contador si la columna contiene una estación
            }
        }
        return contadorColumnas; // Devuelve la cantidad de columnas con estaciones en la fila
    } else {
        cout << "La fila especificada esta fuera de los limites de la matriz." << endl;
        return -1; // Retorna un valor negativo para indicar un error
    }
}
bool EstacionMatriz::estacionPerteneceALinea(const string& nombreEstacion, int linea) const {
    if (linea >= 0 && linea < filas) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[linea][j] != nullptr && matriz[linea][j]->getNombre() == nombreEstacion) {
                // Si la estación en la posición (linea, j) no es nullptr y su nombre coincide, retorna verdadero
                return true;
            }
        }
        // Si no se encuentra la estación en la línea especificada, retorna falso
        return false;
    } else {
        cout << "La linea especificada esta fuera de los limites de la matriz." << endl;
        return false; // Retorna falso si la línea está fuera de los límites de la matriz
    }
}
int EstacionMatriz::cantidadEstacionesSinTransferencia() const {
    int contador = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[i][j] != nullptr) {
                // Verificar si el nombre de la estación contiene un '+'
                string nombreEstacion = matriz[i][j]->getNombre();
                if (nombreEstacion.find('+') == string::npos) {
                    // Si el nombre de la estación no contiene un '+', se cuenta como estación normal
                    contador++;
                }
            }
        }
    }
    return contador;
}

void EstacionMatriz::mostrarMatriz() const {
    cout << "Lineas y estaciones de la Red:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[i][j] != nullptr) {
                cout << "Estacion en la linea [" << i << "],posicion [ " << j << "]: ";
                matriz[i][j]->getEstacion();
                cout << endl;
            }

        }
    }
}
void EstacionMatriz::copiarElemento(int origen, int destino, int indiceElemento) {
    // Verificar que las posiciones de origen y destino estén dentro de los límites de la matriz
    if (origen >= 0 && origen < filas && destino >= 0 && destino < filas) {
        // Verificar que el índice del elemento esté dentro de los límites de las columnas
        if (indiceElemento >= 0 && indiceElemento < columnas) {
            // Obtener la estación en la posición (origen, indiceElemento)
            Estacion* estacionOrigen = matriz[origen][indiceElemento];
            // Modificar el nombre de la estación de origen para agregar el índice de la línea destino
            string nombreEstacionOrigen = estacionOrigen->getNombre();
            string nombreModificadoOrigen = nombreEstacionOrigen + "+" + to_string(origen);
            // Modificar el nombre de la estación copiada para agregar el índice de la línea destino
            string nombreModificadoDestino = nombreEstacionOrigen + "+" + to_string(destino);
            // Asignar la estación modificada a la posición correspondiente en la línea de destino
            matriz[origen][indiceElemento] = new Estacion(nombreModificadoOrigen); // Modificamos la estación de origen
            matriz[destino][indiceElemento] = new Estacion(nombreModificadoDestino); // Copiamos la estación modificada a la línea de destino
            cout << "La estacion en la posicion [" << origen << ", " << indiceElemento << "] ha sido copiada a la linea " << destino << endl;
        } else {
            cout << "El indice del elemento a copiar esta fuera de los limites de las columnas." << endl;
        }
    } else {
        cout << "Las posiciones de origen y destino estan fuera de los limites de la matriz." << endl;
    }
}


