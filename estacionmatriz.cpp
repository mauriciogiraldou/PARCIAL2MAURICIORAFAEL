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
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        if (matriz[fila][columna] != nullptr) {
            cout << "Ya hay una estacion en esta posicion. No se puede agregar una nueva estacion aqui." << endl;
        } else {
            matriz[fila][columna] = estacion;
        }
    } else {
        cout << "Posicion fuera de los limites de la matriz. Redimensionando las columnas de la matriz..." << endl;
        redimensionar(filas, max(columna + 1, columnas));
        matriz[fila][columna] = estacion;
    }
}
void EstacionMatriz::redimensionar(int nuevaFilas, int nuevasColumnas) {
    Estacion*** nuevaMatriz = new Estacion**[nuevaFilas];
    for (int i = 0; i < nuevaFilas; ++i) {
        nuevaMatriz[i] = new Estacion*[nuevasColumnas];
        for (int j = 0; j < nuevasColumnas; ++j) {
            nuevaMatriz[i][j] = nullptr;
        }
    }

    int filasCopiadas = min(nuevaFilas, filas);
    int columnasCopiadas = min(nuevasColumnas, columnas);
    for (int i = 0; i < filasCopiadas; ++i) {
        for (int j = 0; j < columnasCopiadas; ++j) {
            nuevaMatriz[i][j] = matriz[i][j];
        }
    }

    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    matriz = nuevaMatriz;
    filas = nuevaFilas;
    columnas = nuevasColumnas;
}

void EstacionMatriz::borrarEstacion(int fila, int columna) {
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        if (matriz[fila][columna] != nullptr && matriz[fila][columna]->getNombre().find("+") == string::npos) {
            delete matriz[fila][columna];
            matriz[fila][columna] = nullptr;
            cout << "Estacion borrada en la linea [" << fila << "] posicion [ " << columna << "]" << endl;
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
        int contadorColumnas = 0;
        for (int j = 0; j < columnas; ++j) {
            if (matriz[fila][j] != nullptr) {
                contadorColumnas++;
            }
        }
        return contadorColumnas;
    } else {
        cout << "La fila especificada esta fuera de los limites de la matriz." << endl;
        return -1;
    }
}
bool EstacionMatriz::estacionPerteneceALinea(const string& nombreEstacion, int linea) const {
    if (linea >= 0 && linea < filas) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[linea][j] != nullptr && matriz[linea][j]->getNombre() == nombreEstacion) {

                return true;
            }
        }

        return false;
    } else {
        cout << "La linea especificada esta fuera de los limites de la matriz." << endl;
        return false;
    }
}
int EstacionMatriz::cantidadEstacionesSinTransferencia() const {
    int contador = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[i][j] != nullptr) {
                string nombreEstacion = matriz[i][j]->getNombre();
                if (nombreEstacion.find('+') == string::npos) {
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
    if (origen >= 0 && origen < filas && destino >= 0 && destino < filas) {
        if (indiceElemento >= 0 && indiceElemento < columnas) {
            Estacion* estacionOrigen = matriz[origen][indiceElemento];
            string nombreEstacionOrigen = estacionOrigen->getNombre();
            string nombreModificadoOrigen = nombreEstacionOrigen + "+" + to_string(origen);
            string nombreModificadoDestino = nombreEstacionOrigen + "+" + to_string(destino);
            matriz[origen][indiceElemento] = new Estacion(nombreModificadoOrigen);
            matriz[destino][indiceElemento] = new Estacion(nombreModificadoDestino);
            cout << "La estacion en la posicion [" << origen << ", " << indiceElemento << "] ha sido copiada a la linea " << destino << endl;
        } else {
            cout << "El indice del elemento a copiar esta fuera de los limites de las columnas." << endl;
        }
    } else {
        cout << "Las posiciones de origen y destino estan fuera de los limites de la matriz." << endl;
    }
}


