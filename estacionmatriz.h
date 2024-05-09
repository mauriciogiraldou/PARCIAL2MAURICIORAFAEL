#ifndef ESTACIONMATRIZ_H
#define ESTACIONMATRIZ_H
#include "Estacion.h"
class EstacionMatriz {
private:
    Estacion*** matriz;
    int filas;
    int columnas;

public:
    EstacionMatriz(int filas, int columnas);
    ~EstacionMatriz();
    int cantidadLineas() const;
    Estacion* getEstacion(int fila, int columna) const;
    void setEstacion(int fila, int columna, Estacion* estacion);
    void redimensionar(int nuevaFilas, int columnas);
    void borrarEstacion(int fila, int columna);
    int obtenerFilas() const { return filas; }
    void mostrarMatriz() const;
    int obtenerColumnas() const { return columnas; }
    void copiarElemento(int origen, int destino, int indiceElemento);
    int cantidadColumnasEnFila(int fila) const;
    bool estacionPerteneceALinea(const string& nombreEstacion, int linea) const;
    int cantidadEstacionesSinTransferencia() const;
};

#endif // ESTACIONMATRIZ_H
