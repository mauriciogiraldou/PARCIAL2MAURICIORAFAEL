#ifndef LINEA_H
#define LINEA_H
#include <string>
#include <iostream>
using namespace std;
/*
La clase linea será un arreglo dinamico de strings, en el cual cada string dentro de ese arreglo dinamico será una estacion.
*/
class Linea{
private:
    string nombre;
    int tamano;
    string *data;

public:
    Linea(const string* valores,int size,const string&nombre="");
    ~Linea();
    string getValue(int indice);
    string getNombre() const;
};

#endif // LINEA_H
