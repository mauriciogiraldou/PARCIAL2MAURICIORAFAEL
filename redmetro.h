#ifndef REDMETRO_H
#define REDMETRO_H
#include "linea.h"
class RedMetro {
private:
    Linea*** datos;
    int filas;
    int columnas;

public:
    RedMetro(int filas, int columnas);
    ~RedMetro();
    void setValue(int fila, int columna, const string* valores, int tamano, const string& nombre = "");
    string getValue(int fila, int columna, int indice);
    string getNombre(int fila, int columna);
    int numRows();
    int numCols();
};

#endif // REDMETRO_H
