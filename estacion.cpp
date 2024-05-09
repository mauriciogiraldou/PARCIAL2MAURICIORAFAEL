#include "Estacion.h"
Estacion::Estacion(const string& _nombre) : nombre(new string(_nombre)) {}
Estacion::~Estacion() {
    delete nombre;
}

string Estacion::getNombre() const {
    return *nombre;
}

void Estacion::getEstacion() const {
    if (nombre != nullptr) {
        cout << *nombre;
    } else {
        cout << "El nombre de la estacion no esta inicializado";
    }
}
void Estacion::setNombre(const string& nuevoNombre) {
    *nombre = nuevoNombre;
}

bool Estacion::operator==(const Estacion& otraEstacion) const {
    return *nombre == *(otraEstacion.nombre);
}

Estacion& Estacion::operator=(const Estacion& otraEstacion) {
    if (this != &otraEstacion) {
        *nombre = *(otraEstacion.nombre);
        tiempo = otraEstacion.tiempo;
    }
    return *this;
}
