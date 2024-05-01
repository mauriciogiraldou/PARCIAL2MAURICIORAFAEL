#include "redmetro.h"
RedMetro::RedMetro(int filas, int columnas) : filas(filas), columnas(columnas) {
    datos = new Linea**[filas];
    for (int i = 0; i < filas; ++i) {
        datos[i] = new Linea*[columnas];
        for (int j = 0; j < columnas; ++j) {
            datos[i][j] = nullptr;
        }
    }
}

RedMetro::~RedMetro() {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            delete datos[i][j];
        }
        delete[] datos[i];
    }
    delete[] datos;
}

void RedMetro::setValue(int fila, int columna, const string* valores, int tamano, const string& nombre) {
    if (datos[fila][columna] != nullptr) {
        delete datos[fila][columna];
    }
    datos[fila][columna] = new Linea(valores, tamano, nombre);
}

string RedMetro::getValue(int fila, int columna, int indice) {
    if (datos[fila][columna] != nullptr) {
        return datos[fila][columna]->getValue(indice);
    }
    return "";
}

string RedMetro::getNombre(int fila, int columna) {
    if (datos[fila][columna] != nullptr) {
        return datos[fila][columna]->getNombre();
    }
    return "";
}

int RedMetro::numRows() {
    return filas;
}

int RedMetro::numCols() {
    return columnas;
}
