#ifndef ESTACION_H
#define ESTACION_H
#include <iostream>
#include <string>
using namespace std;
class Estacion {
private:
    string* nombre;
    int tiempo;
public:
    Estacion(const string&);
    ~Estacion();
    string getNombre() const;
    void setNombre(const string& nuevoNombre);
    void getEstacion() const;
    bool operator==(const Estacion& otraEstacion) const;
    Estacion& operator=(const Estacion& otraEstacion);
};

#endif // ESTACION_H

