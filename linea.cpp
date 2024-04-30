#include "linea.h"
Linea::Linea(const string* values, int tamano, const string& nombre)
    : tamano(tamano), nombre(nombre) {
    data = new string[tamano];
    for (int i = 0; i < tamano; ++i) {
        data[i] = values[i];
    }
}
Linea::~Linea() {
    delete[] data;
}

string Linea::getValue(int index) {
    if (index >= 0 && index < tamano) {
        return data[index];
    }
    return "";
}

string Linea::getNombre() const {
    return nombre;
}
