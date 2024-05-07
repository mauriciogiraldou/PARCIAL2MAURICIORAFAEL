#include "Estacion.h"

// Constructor
Estacion::Estacion(const string& _nombre) : nombre(new string(_nombre)) {}

// Destructor
Estacion::~Estacion() {
    delete nombre;
}

// Método para establecer el nombre de la estación

// Método para obtener el nombre de la estación
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

// Sobrecarga del operador de igualdad
bool Estacion::operator==(const Estacion& otraEstacion) const {
    // Comparar los nombres de las estaciones
    return *nombre == *(otraEstacion.nombre);
}

// Sobrecarga del operador de asignación
Estacion& Estacion::operator=(const Estacion& otraEstacion) {
    if (this != &otraEstacion) { // Evitar la auto-asignación
        // Asignar el nombre y el tiempo de otraEstacion a esta estación
        *nombre = *(otraEstacion.nombre);
        tiempo = otraEstacion.tiempo;
    }
    return *this;
}
