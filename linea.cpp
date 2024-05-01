#include "linea.h"
Linea::Linea(const string* valores, int tamano, const string& nombre): tamano(tamano), nombre(nombre) {
    data = new string[tamano];
    for (int i = 0; i < tamano; ++i) {
        data[i] = valores[i];
    }
}
Linea::~Linea() {
    delete[] data;
}

string Linea::getValue(int indice) {
    if (indice >= 0 && indice < tamano) {
        return data[indice];
    }
    return "";
}

string Linea::getNombre() const {
    return nombre;
}
