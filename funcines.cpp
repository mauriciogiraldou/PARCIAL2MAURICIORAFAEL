#include "funcion.h"
EstacionMatriz inicializarmatriz(int n) {
    EstacionMatriz sistemametro(n, n);
    return sistemametro;
}
void crearestacion(EstacionMatriz& sistemametro, int fila, int columna) {
    int filas = sistemametro.obtenerFilas();
    int columnas = sistemametro.obtenerColumnas();
    string nombrenuevaestacion;
    cout << "Ingrese el nombre de la Estacion: ";
    getline(cin, nombrenuevaestacion);
    cin.ignore();
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        Estacion* nuevaEstacion = new Estacion(nombrenuevaestacion);
        sistemametro.setEstacion(fila, columna, nuevaEstacion);
    } else {
        int nuevaFilas = max(fila + 1, filas);
        int nuevasColumnas = max(columna + 1, columnas);
        sistemametro.redimensionar(nuevaFilas, nuevasColumnas);
        Estacion* nuevaEstacion = new Estacion(nombrenuevaestacion);
        sistemametro.setEstacion(fila, columna, nuevaEstacion);
    }
}
